<?php
/**
 * @file
 * dsgf_users.features.inc
 */

/**
 * Implements hook_default_profile2_type().
 */
function dsgf_users_default_profile2_type() {
  $items = array();
  $items['member_profile'] = entity_import('profile2_type', '{
    "userCategory" : true,
    "userView" : true,
    "type" : "member_profile",
    "label" : "Member Profile",
    "weight" : "0",
    "data" : { "registration" : 1, "use_page" : 0 }
  }');
  $items['server_access'] = entity_import('profile2_type', '{
    "userCategory" : true,
    "userView" : true,
    "type" : "server_access",
    "label" : "Server Access",
    "weight" : "1",
    "data" : { "registration" : 0, "use_page" : 0 }
  }');
  return $items;
}
