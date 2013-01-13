<?php

/**
 * @file
 * User page callbacks for the github_connect module.
 */

/**
 * Menu callback; Process an Github authentication
 */
function github_connect_get_access_token() {
  global $user;

  module_load_include('inc', 'github_connect');

  $client_id = variable_get('github_connect_client_id');
  $client_secret = variable_get('github_connect_client_secret');

  // The response code after first call to GitHub.
  $code = $_GET['code'];

  $url = 'https://github.com/login/oauth/access_token?';
  $options = array(
    'data' => 'client_id=' . $client_id . '&client_secret=' . $client_secret . '&code=' . $code,
    'method' => 'POST',
  );
  $response = drupal_http_request($url, $options);
  $token = $response->data;

  if ($token) {
    // Check if a user exists for the token.
    $account = github_connect_get_token_user($token);

    if ($user->uid == 0) { // First the case where an anonymous user attempts a login
      watchdog('github_connect', 'An anonymous user attempts login', array(), WATCHDOG_DEBUG);
      if ($account) { // If there is a user with the token log that user in.
        watchdog('github_connect', 'There is a token, attempting login for uid !uid', array('!uid' => $account->uid), WATCHDOG_DEBUG);
        _github_connect_user_login($account);
        drupal_goto();
      }
      else { // Otherwise register the user and log in
        $github_user = _github_connect_get_github_user_info($token);
        watchdog('github_connect', 'Registering a user', array(), WATCHDOG_DEBUG);

        if ($existing_user_by_mail = user_load_by_mail($github_user['email'])) {
          // If a user with this email address exists, let him connect the github account to his already created account.
          watchdog('github_connect', 'User with email !email already exists, redirecting', array('!email' => $github_user['email']), WATCHDOG_DEBUG);
          drupal_goto('github/verify/email/' . $existing_user_by_mail->uid . '/' . $token);
        }
        else {
          // Otherwise make sure there is no account with the same username
          if ($existing_user_by_name = user_load_by_name($github_user['login'])) {
            watchdog('github_connect', 'User with login !login already exists, redirecting', array('!login' => $github_user['login']), WATCHDOG_DEBUG);
            drupal_goto('github/username/' . $existing_user_by_name->uid . '/' . $token);
          } else {
            watchdog('github_connect', 'Registering new user', array(), WATCHDOG_DEBUG);
            _github_connect_register($github_user, $token);
            drupal_goto();
          }
        }
      }
    }
    else { // Second the case where an logged in user attempts to attach his github account
      if ($account) {
        // If there is a user with the token, throw an error.
        drupal_set_message(t('Your GitHub account could not be connected, it is already coupled with another user.'), 'error');
        drupal_goto('user/' . $user->uid . '/github');
      }
      else {
        $github_user = _github_connect_get_github_user_info($token);

        if ($github_user['html_url']) {
          _github_connect_save_github_user($user, $token);

          module_invoke_all('github_added', $user, $github_user['login']);

          drupal_set_message(t('Your GitHub account is now connected.'));
          drupal_goto('user/' . $user->uid . '/github');
        }
      }
    }
  }
  else {
    // If we didn't get a token, connection to Github failed
    drupal_set_message(t('Failed connecting to GitHub.'), 'error');
    drupal_goto();
  }
}

/**
 * Menu callback; Manage Github account for the specified user.
 */
function github_user_account($account) {
  drupal_set_title(format_username($account));

  $header = array(t('GitHub account'), t('Operations'));
  $rows = array();

  $result = db_query("SELECT * FROM {authmap} WHERE module='github_connect' AND uid=:uid", array(':uid' => $account->uid));
  foreach ($result as $identity) {
    $rows[] = array(check_plain($identity->authname), l(t('Delete'), 'user/' . $account->uid . '/github/delete/' . $identity->aid));
  }

  $build['github_table'] = array(
    '#theme' => 'table',
    '#header' => $header,
    '#rows' => $rows,
  );
  if (!$result->rowCount()) {
    $build['github_user_connect'] = drupal_get_form('github_user_connect');
  }
  return $build;
}

/**
 * Form builder; Connect a Github account.
 *
 * @ingroup forms
 * @see github_user_connect_submit()
 */
function github_user_connect() {
  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array('#type' => 'submit', '#value' => t('Connect your GitHub account'));

  return $form;
}

function github_user_connect_submit($form, &$form_state) {
  global $base_url;

  $return_to = url('user/' . arg(1) . '/github', array('absolute' => TRUE));

  $client_id = variable_get('github_connect_client_id');
  $link = 'https://github.com/login/oauth/authorize?client_id=' . $client_id . '&scope=user,public&redirect_uri=' . urlencode($base_url . '/github/register/create');

  $form_state['redirect'] = $link;
}

/**
 * Menu callback; Disconnect the specified Github account from the system.
 */
function github_connect_user_delete_form($form, $form_state, $account, $aid = 0) {
  module_load_include('inc', 'github_connect');

  $github_username = _github_connect_get_github_username($account);
  $form['account'] = array(
    '#type' => 'value',
    '#value' => $account,
  );
  $form['github_username'] = array(
    '#type' => 'value',
    '#value' => $github_username,
  );
  return confirm_form($form, t('Are you sure you want to disconnect the Github account %authname for %user?', array('%authname' => $github_username, '%user' => $account->name)), 'user/' . $account->uid . '/github');
}

function github_connect_user_delete_form_submit($form, &$form_state) {
  module_load_include('inc', 'github_connect');

  $query1 = db_delete('authmap')
    ->condition('uid', $form_state['values']['account']->uid)
    ->condition('aid', $form_state['build_info']['args'][1])
    ->condition('module', 'github_connect')
    ->execute();

  // Delete the user from github_connect_users table.
  $query2 = db_delete('github_connect_users')
    ->condition('uid', $form_state['values']['account']->uid)
    ->execute();
  if ($query1 && $query2) {
    module_invoke_all('github_removed', $form_state['values']['account'], $form_state['values']['github_username']);
    drupal_set_message(t('Github account disconnected.'));
  }

  $form_state['redirect'] = 'user/' . $form_state['build_info']['args'][0]->uid . '/github';
}

/**
 * Require user to verify email address when merging accounts.
 */
function github_connect_verify_email_form($form, &$form_state, $account, $token) {
  $form['message'] = array(
    '#type' => 'item',
    '#title' => t('Email address in use'),
    '#markup' => t('There is already an account associated with your GitHub email address. Type your !site account password to merge accounts.', array('!site' => variable_get('site_name'))),
  );
  $form['name'] = array('#type' => 'hidden', '#value' => $account->name);
  $form['pass'] = array('#type' => 'password',
    '#title' => t('Password'),
    '#description' => t('Enter your password.'),
    '#required' => TRUE,
  );
  $form['token'] = array('#type' => 'hidden', '#value' => $token);
  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array('#type' => 'submit', '#value' => t('Merge accounts'));

  return $form;
}

/**
 * Validation to check correct password when merging.
 */
function github_connect_verify_email_form_validate($form, &$form_state) {
  $name = $form_state['values']['name'];
  $password = $form_state['values']['pass'];

  if (user_authenticate($name, $password) == FALSE) {
    form_set_error('pass', t('Incorrect password.'));
  }
}

/**
 * Custom submit function to save user when merging.
 */
function github_connect_verify_email_form_submit($form, &$form_state) {
  module_load_include('inc', 'github_connect');

  $account = user_load_by_name($form_state['values']['name']);
  $token = $form_state['values']['token'];

  _github_connect_save_github_user($account, $token);

  // Log in the connected user.
  _github_connect_user_login($account);
  drupal_set_message(t('You are now connected with your GitHub account.'));

  module_invoke_all('github_added', $account, _github_connect_get_github_username($account));

  drupal_goto();
}

/**
 * Allow a user to choose their username when their github username is already taken.
 */
function github_connect_username_choose_form($form, &$form_state, $account, $token) {

  $form['message'] = array(
    '#type' => 'item',
    '#title' => t('Username in use'),
    '#markup' => t('There is already an account associated with your GitHub account name !account_name. Please choose a
        different username for use on !site. This will not change your github username and you will continue to be able
        to log in with your github account.',
      array(
        '!site' => variable_get('site_name'),
        '!account_name' => $account->name,
      )),
  );
  $form['name'] = array('#type' => 'hidden', '#value' => $account->name);
  $form['name_new'] = array('#type' => 'textfield',
    '#title' => t('New username'),
    '#description' => t('Enter another username.'),
    '#required' => TRUE,
  );
  $form['token'] = array('#type' => 'hidden', '#value' => $token);

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array('#type' => 'submit', '#value' => t('Submit username'));

  return $form;
}


/**
 * Validation to check if the newly chosen username doesn't exist
 */
function github_connect_username_choose_form_validate($form, &$form_state) {
  module_load_include('inc', 'github_connect');

  $name_new = $form_state['values']['name_new'];

  if (user_load_by_name($name_new)) {
    form_set_error('name_new', t('This username already exists, please choose another one.'));
  }
}

/**
 * Custom submit function to save user when choosing custom username
 */
function github_connect_username_choose_form_submit($form, &$form_state) {
  module_load_include('inc', 'github_connect');

  $token = $form_state['values']['token'];
  $github_user = _github_connect_get_github_user_info($token);
  // Change the login name to the newly selected name
  $github_user['login'] = $form_state['values']['name_new'];

  _github_connect_register($github_user, $token);

  drupal_goto();
}
