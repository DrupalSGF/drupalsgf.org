<?php
/**
 * @file
 * single_user_blog.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function single_user_blog_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: navigation:node/add/blog-post
  $menu_links['navigation:node/add/blog-post'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add/blog-post',
    'router_path' => 'node/add/blog-post',
    'link_title' => 'Blog Post',
    'options' => array(
      'attributes' => array(
        'title' => 'Use this content type to add a post to a blog.<br />
The user who creates the Blog Post will be attributed the "author" status.',
      ),
    ),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
    'parent_path' => 'node/add',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Blog Post');


  return $menu_links;
}
