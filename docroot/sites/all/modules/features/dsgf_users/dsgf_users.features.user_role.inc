<?php
/**
 * @file
 * dsgf_users.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function dsgf_users_user_default_roles() {
  $roles = array();

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => '2',
  );

  // Exported role: content manager.
  $roles['content manager'] = array(
    'name' => 'content manager',
    'weight' => '3',
  );

  // Exported role: member.
  $roles['member'] = array(
    'name' => 'member',
    'weight' => '4',
  );

  return $roles;
}
