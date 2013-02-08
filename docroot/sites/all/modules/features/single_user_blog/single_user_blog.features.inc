<?php
/**
 * @file
 * single_user_blog.features.inc
 */

/**
 * Implements hook_views_api().
 */
function single_user_blog_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function single_user_blog_node_info() {
  $items = array(
    'blog_post' => array(
      'name' => t('Blog Post'),
      'base' => 'node_content',
      'description' => t('Use this content type to add a post to a blog.<br />
The user who creates the Blog Post will be attributed the "author" status.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
