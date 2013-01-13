<?php
/**
 * @file
 * dsgf_users.features.field.inc
 */

/**
 * Implements hook_field_default_fields().
 */
function dsgf_users_field_default_fields() {
  $fields = array();

  // Exported field: 'profile2-member_profile-field_bitbucket'.
  $fields['profile2-member_profile-field_bitbucket'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_bitbucket',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(
        'max_length' => '30',
        'profile2_private' => 0,
      ),
      'translatable' => '0',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'member_profile',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 8,
        ),
      ),
      'entity_type' => 'profile2',
      'field_name' => 'field_bitbucket',
      'label' => 'Bitbucket',
      'required' => 0,
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'size' => '60',
        ),
        'type' => 'text_textfield',
        'weight' => '9',
      ),
    ),
  );

  // Exported field: 'profile2-member_profile-field_drupal_uid'.
  $fields['profile2-member_profile-field_drupal_uid'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_drupal_uid',
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'number',
      'settings' => array(
        'profile2_private' => 0,
      ),
      'translatable' => '0',
      'type' => 'number_integer',
    ),
    'field_instance' => array(
      'bundle' => 'member_profile',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Your Drupal UID can be found at the end of your profile\'s URL: <em>http://drupal.org/user/487058</em>',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'number',
          'settings' => array(
            'decimal_separator' => '.',
            'prefix_suffix' => 0,
            'scale' => 0,
            'thousand_separator' => '',
          ),
          'type' => 'number_integer',
          'weight' => '2',
        ),
      ),
      'entity_type' => 'profile2',
      'field_name' => 'field_drupal_uid',
      'label' => 'Drupal UID',
      'required' => 0,
      'settings' => array(
        'max' => '',
        'min' => '',
        'prefix' => '',
        'suffix' => '',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'number',
        'settings' => array(),
        'type' => 'number',
        'weight' => '3',
      ),
    ),
  );

  // Exported field: 'profile2-member_profile-field_facebook_url'.
  $fields['profile2-member_profile-field_facebook_url'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_facebook_url',
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'url',
      'settings' => array(
        'profile2_private' => 0,
      ),
      'translatable' => '0',
      'type' => 'url',
    ),
    'field_instance' => array(
      'bundle' => 'member_profile',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'url',
          'settings' => array(
            'nofollow' => FALSE,
            'trim_length' => 80,
          ),
          'type' => 'url_default',
          'weight' => 5,
        ),
      ),
      'entity_type' => 'profile2',
      'field_name' => 'field_facebook_url',
      'label' => 'Facebook URL',
      'required' => 0,
      'settings' => array(
        'title_fetch' => 0,
        'title_field' => 0,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'url',
        'settings' => array(
          'size' => '60',
        ),
        'type' => 'url_external',
        'weight' => '6',
      ),
    ),
  );

  // Exported field: 'profile2-member_profile-field_first_name'.
  $fields['profile2-member_profile-field_first_name'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_first_name',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(
        'max_length' => '35',
        'profile2_private' => 0,
      ),
      'translatable' => '0',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'member_profile',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_plain',
          'weight' => '0',
        ),
      ),
      'entity_type' => 'profile2',
      'field_name' => 'field_first_name',
      'label' => 'First Name',
      'required' => 0,
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'size' => '60',
        ),
        'type' => 'text_textfield',
        'weight' => '1',
      ),
    ),
  );

  // Exported field: 'profile2-member_profile-field_github'.
  $fields['profile2-member_profile-field_github'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_github',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(
        'max_length' => '30',
        'profile2_private' => 0,
      ),
      'translatable' => '0',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'member_profile',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 7,
        ),
      ),
      'entity_type' => 'profile2',
      'field_name' => 'field_github',
      'label' => 'GitHub',
      'required' => 0,
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'size' => '60',
        ),
        'type' => 'text_textfield',
        'weight' => '8',
      ),
    ),
  );

  // Exported field: 'profile2-member_profile-field_googleplus_url'.
  $fields['profile2-member_profile-field_googleplus_url'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_googleplus_url',
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'url',
      'settings' => array(
        'profile2_private' => 0,
      ),
      'translatable' => '0',
      'type' => 'url',
    ),
    'field_instance' => array(
      'bundle' => 'member_profile',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'url',
          'settings' => array(
            'nofollow' => FALSE,
            'trim_length' => 80,
          ),
          'type' => 'url_default',
          'weight' => 6,
        ),
      ),
      'entity_type' => 'profile2',
      'field_name' => 'field_googleplus_url',
      'label' => 'Google+ URL',
      'required' => 0,
      'settings' => array(
        'title_fetch' => 0,
        'title_field' => 0,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'url',
        'settings' => array(
          'size' => '60',
        ),
        'type' => 'url_external',
        'weight' => '7',
      ),
    ),
  );

  // Exported field: 'profile2-member_profile-field_irc_nick'.
  $fields['profile2-member_profile-field_irc_nick'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_irc_nick',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(
        'max_length' => '30',
        'profile2_private' => 0,
      ),
      'translatable' => '0',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'member_profile',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'The nick you plan to use in #drupal-sgf',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 3,
        ),
      ),
      'entity_type' => 'profile2',
      'field_name' => 'field_irc_nick',
      'label' => 'IRC nick',
      'required' => 0,
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'size' => '60',
        ),
        'type' => 'text_textfield',
        'weight' => '4',
      ),
    ),
  );

  // Exported field: 'profile2-member_profile-field_last_name'.
  $fields['profile2-member_profile-field_last_name'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_last_name',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(
        'max_length' => '35',
        'profile2_private' => 0,
      ),
      'translatable' => '0',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'member_profile',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_plain',
          'weight' => '1',
        ),
      ),
      'entity_type' => 'profile2',
      'field_name' => 'field_last_name',
      'label' => 'Last Name',
      'required' => 0,
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'size' => '60',
        ),
        'type' => 'text_textfield',
        'weight' => '2',
      ),
    ),
  );

  // Exported field: 'profile2-member_profile-field_phone'.
  $fields['profile2-member_profile-field_phone'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_phone',
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'phone',
      'settings' => array(
        'country' => 'ca',
        'profile2_private' => 1,
      ),
      'translatable' => '0',
      'type' => 'phone',
    ),
    'field_instance' => array(
      'bundle' => 'member_profile',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'This field will <em>only</em> be visible to site Administrators, regardless of privacy settings.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'phone',
          'settings' => array(),
          'type' => 'phone',
          'weight' => 9,
        ),
      ),
      'entity_type' => 'profile2',
      'field_name' => 'field_phone',
      'label' => 'Phone',
      'required' => 0,
      'settings' => array(
        'ca_phone_parentheses' => 1,
        'ca_phone_separator' => '-',
        'phone_country_code' => 0,
        'phone_default_country_code' => '1',
        'phone_int_max_length' => 15,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'phone',
        'settings' => array(),
        'type' => 'phone_textfield',
        'weight' => '10',
      ),
    ),
  );

  // Exported field: 'profile2-member_profile-field_privacy_settings'.
  $fields['profile2-member_profile-field_privacy_settings'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_privacy_settings',
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'profile2_privacy',
      'settings' => array(
        'profile2_private' => 1,
      ),
      'translatable' => '0',
      'type' => 'profile2_privacy',
    ),
    'field_instance' => array(
      'bundle' => 'member_profile',
      'default_value' => array(
        0 => '3',
      ),
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'profile2_privacy',
          'settings' => array(),
          'type' => 'profile2_privacy_formatter',
          'weight' => 10,
        ),
      ),
      'entity_type' => 'profile2',
      'field_name' => 'field_privacy_settings',
      'label' => 'Privacy Settings',
      'required' => 1,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'profile2_privacy',
        'settings' => array(),
        'type' => 'profile2_privacy_widget',
        'weight' => 0,
      ),
    ),
  );

  // Exported field: 'profile2-member_profile-field_twitter'.
  $fields['profile2-member_profile-field_twitter'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_twitter',
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'twitter_username',
      'settings' => array(
        'max_length' => 16,
        'profile2_private' => 0,
      ),
      'translatable' => '0',
      'type' => 'twitter_username',
    ),
    'field_instance' => array(
      'bundle' => 'member_profile',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'twitter_username',
          'settings' => array(),
          'type' => 'default',
          'weight' => 4,
        ),
      ),
      'entity_type' => 'profile2',
      'field_name' => 'field_twitter',
      'label' => 'Twitter',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
        'validate_existance' => 0,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'twitter_username',
        'settings' => array(),
        'type' => 'twitter_username',
        'weight' => '5',
      ),
    ),
  );

  // Exported field: 'profile2-server_access-field_ssh_public_key'.
  $fields['profile2-server_access-field_ssh_public_key'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_ssh_public_key',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(
        'profile2_private' => 1,
      ),
      'translatable' => '0',
      'type' => 'text_long',
    ),
    'field_instance' => array(
      'bundle' => 'server_access',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Paste your pubkey in this field. ',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'profile2',
      'field_name' => 'field_ssh_public_key',
      'label' => 'SSH Public Key',
      'required' => 0,
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'rows' => '5',
        ),
        'type' => 'text_textarea',
        'weight' => '1',
      ),
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Bitbucket');
  t('Drupal UID');
  t('Facebook URL');
  t('First Name');
  t('GitHub');
  t('Google+ URL');
  t('IRC nick');
  t('Last Name');
  t('Paste your pubkey in this field. ');
  t('Phone');
  t('Privacy Settings');
  t('SSH Public Key');
  t('The nick you plan to use in #drupal-sgf');
  t('This field will <em>only</em> be visible to site Administrators, regardless of privacy settings.');
  t('Twitter');
  t('Your Drupal UID can be found at the end of your profile\'s URL: <em>http://drupal.org/user/487058</em>');

  return $fields;
}
