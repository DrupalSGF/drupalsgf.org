<?php
/**
 * @file
 * single_user_blog.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function single_user_blog_user_default_roles() {
  $roles = array();

  // Exported role: blogger.
  $roles['blogger'] = array(
    'name' => 'blogger',
    'weight' => '3',
  );

  return $roles;
}
