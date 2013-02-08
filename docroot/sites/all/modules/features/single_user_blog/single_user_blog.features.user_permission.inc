<?php
/**
 * @file
 * single_user_blog.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function single_user_blog_user_default_permissions() {
  $permissions = array();

  // Exported permission: access comments.
  $permissions['access comments'] = array(
    'name' => 'access comments',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'comment',
  );

  // Exported permission: change own username.
  $permissions['change own username'] = array(
    'name' => 'change own username',
    'roles' => array(
      0 => 'administrator',
      1 => 'blogger',
    ),
    'module' => 'user',
  );

  // Exported permission: create blog_post content.
  $permissions['create blog_post content'] = array(
    'name' => 'create blog_post content',
    'roles' => array(
      0 => 'blogger',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any blog_post content.
  $permissions['delete any blog_post content'] = array(
    'name' => 'delete any blog_post content',
    'roles' => array(
      0 => 'blogger',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own blog_post content.
  $permissions['delete own blog_post content'] = array(
    'name' => 'delete own blog_post content',
    'roles' => array(
      0 => 'blogger',
    ),
    'module' => 'node',
  );

  // Exported permission: delete terms in 1.
  $permissions['delete terms in 1'] = array(
    'name' => 'delete terms in 1',
    'roles' => array(
      0 => 'administrator',
      1 => 'blogger',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit any blog_post content.
  $permissions['edit any blog_post content'] = array(
    'name' => 'edit any blog_post content',
    'roles' => array(
      0 => 'blogger',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own blog_post content.
  $permissions['edit own blog_post content'] = array(
    'name' => 'edit own blog_post content',
    'roles' => array(
      0 => 'blogger',
    ),
    'module' => 'node',
  );

  // Exported permission: edit terms in 1.
  $permissions['edit terms in 1'] = array(
    'name' => 'edit terms in 1',
    'roles' => array(
      0 => 'administrator',
      1 => 'blogger',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: view disqus comments.
  $permissions['view disqus comments'] = array(
    'name' => 'view disqus comments',
    'roles' => array(
      0 => 'administrator',
      1 => 'anonymous user',
      2 => 'authenticated user',
    ),
    'module' => 'disqus',
  );

  return $permissions;
}
