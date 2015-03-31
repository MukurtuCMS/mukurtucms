<?php

/**
 * Implements hook_install_tasks().
 */

function mukurtu_install_tasks($install_state) {
  $tasks = array (
    'mukurtu_set_error_level' => array(),
    'mukurtu_set_theme' => array(),
    'mukurtu_set_clean_urls' => array(),
    'mukurtu_revert_features' => array(
      'display_name' => st('Finalize configuration'),
    ),
    'mukurtu_rebuild_permissions' => array(),
    'mukurtu_default_tax_terms' => array(),
    'mukurtu_default_menu_links' => array(),
    'mukurtu_create_default_pages' => array(),
    'mukurtu_set_permissions' => array(),
    'mukurtu_set_scald_drawer_thumbnails' => array(),
    'mukurtu_delete_og_roles' => array(),
//    'mukurtu_client_form' => array(
//      'display_name' => st('Setup Client'),
//      'type' => 'form',
//    ),
  );
  return $tasks;
}

/**
 * hook_install_tasks callbacks
 */

function mukurtu_set_error_level () {
  variable_set ('error_level', ERROR_REPORTING_HIDE);
}

function mukurtu_set_theme () {
  theme_enable (array('mukurtu_starter'));
  variable_set ('theme_default', 'mukurtu_starter');
  theme_disable (array('bartik', 'seven'));
}

function mukurtu_set_clean_urls () {
  variable_set ('clean_url', 1);
}

function mukurtu_revert_features () {
  features_revert_module('ma_search_api'); // First revert search_api to get the node index
  features_revert(); // Revert all features
  features_revert(); // Revert all features a second time, for any straggling components
}
function mukurtu_rebuild_permissions () {
  node_access_rebuild();
}

function mukurtu_default_tax_terms () {
  $taxonomy = array(
    'category' => array(
      'General',
    ),
  );
  foreach ($taxonomy as $vocabulary_name => $terms) {
    // Add a default term to the vocabulary.
    $vocabulary = taxonomy_vocabulary_machine_name_load($vocabulary_name);
    foreach ($terms as $term) {
      taxonomy_term_save((object) array(
        'name' => $term,
        'vid' => $vocabulary->vid,
      ));
    }
  }
}

function mukurtu_default_menu_links () {

  $item = array(
    'link_path' => 'about',
    'link_title' => 'About',
    'menu_name' => 'menu-browse-menu',
    'weight' => -51,
    'expanded' => 0,
  );
  menu_link_save($item);

  $item = array(
    'link_path' => 'collections',
    'link_title' => 'Browse Collections',
    'menu_name' => 'menu-browse-menu',
    'weight' => -50,
    'expanded' => 0,
  );
  menu_link_save($item);

  $item = array(
    'link_path' => 'digital-heritage',
    'link_title' => 'Browse Digital Heritage',
    'menu_name' => 'menu-browse-menu',
    'weight' => -49,
    'expanded' => 0,
  );
  menu_link_save($item);

}

function mukurtu_set_permissions () {

  // These are permissions we do not want featurized because clients may want to change them
  $permissions_to_grant = array (
    'post comments' => array (
      'administrator',
      'Site Administrator',
      'authenticated user',
    ),
  );
  foreach ($permissions_to_grant as $permission_to_grant => $rolenames_to_grant_to) {
    foreach ($rolenames_to_grant_to as $role_name) {
      if ($role = user_role_load_by_name($role_name)) {
        user_role_grant_permissions($role->rid, array ($permission_to_grant));
      }
    }
  }
}

function mukurtu_set_scald_drawer_thumbnails() {

  // This is for the scald drawer thumbnails, not the thumbnails within the nodes, which we are handling separately
  $thumbnails = array(
    'thumbnail_default.png',
    'image.png',
    'audio.png',
    'video.png'
  );
  foreach ($thumbnails as $thumbnail) {
    $thumbnail_target = 'public://atoms/' . $thumbnail;

    if (!file_exists($thumbnail_target)) {
      $directory = dirname($thumbnail_target);
      file_prepare_directory($directory, FILE_CREATE_DIRECTORY);
      file_unmanaged_copy(drupal_get_path('module', 'scald') . '/assets/' . $thumbnail, $thumbnail_target);
    }
  }
}

function mukurtu_delete_og_roles() {
  // The Administrator Member role is created by default by OG, then inherited when our group types are created. Delete it.
  $group_types = array (
    'cultural_protocol_group',
    'community',
  );
  foreach ($group_types as $group_type) {
    $rid = array_search('administrator member', og_roles('node', $group_type));
    og_role_delete($rid);
  }
}

function mukurtu_create_default_pages () {
  $values = array(
    'type' => 'page',
    'uid' => 1,
    'status' => 1,
    'comment' => 0,
    'promote' => 0,
  );
  $entity = entity_create('node', $values);
  $ewrapper = entity_metadata_wrapper('node', $entity);
  $ewrapper->title->set('About');
  $body = file_get_contents(DRUPAL_ROOT . '/' . drupal_get_path('profile', 'mukurtu') . '/pages/about');
  $ewrapper->body->set(array('value' => $body, 'format' => 'full_html'));
  $ewrapper->save();
}

//function mukurtu_client_form() {
//  $form = array();
//  $form['intro'] = array(
//    '#markup' => '<p>' . st('Setup your default client account below.') . '</p>',
//  );
//  $form['client_name'] = array(
//    '#type' => 'textfield',
//    '#title' => st('Client Username'),
//    '#required' => TRUE,
//  );
//  $form['client_mail'] = array(
//    '#type' => 'textfield',
//    '#title' => st('Client E-mail Address'),
//    '#required' => TRUE,
//  );
//  $form['client_pass'] = array(
//    '#type' => 'password',
//    '#title' => st('Client Password'),
//  );
//  $form['submit'] = array(
//    '#type' => 'submit',
//    '#value' => st('Continue'),
//  );
//  return $form;
//}
//
//function mukurtu_client_form_validate($form, &$form_state) {
//  if (!valid_email_address($form_state['values']['client_mail'])) {
//    form_set_error('client_mail', st('Please enter a valid email address'));
//  }
//}
//
//function mukurtu_client_form_submit($form, &$form_state) {
//  $values = $form_state['values'];
//
//  // Setup the user account array to programatically create a new user.
//  $account = array(
//    'name' => $values['client_name'],
//    'pass' => !empty($values['client_pass']) ? $values['client_pass'] : user_password(),
//    'mail' => $values['client_mail'],
//    'status' => 1,
//    'init' => $values['client_mail'],
//  );
//  $account = user_save(null, $account);
//
//  // Assign the client to the "administrator" role.
//  $role = user_role_load_by_name('administrator');
//  db_insert('users_roles')
//    ->fields(array('uid' => $account->uid, 'rid' => $role->rid))
//    ->execute();
//}



/**
 * Implements hook_form_FORM_ID_alter().
 */
function mukurtu_form_install_configure_form_alter(&$form, &$form_state) {

  // Do not email Drupal update notifications (we should be handling it on our end, not the client)
  $form['update_notifications']['update_status_module']['#default_value'] = array (0,0);
  $form['update_notifications']['#access'] = FALSE;

  // Set default country and timezone to Australia
  $form['server_settings']['site_default_country']['#default_value'] = 'AU';
  # $form['server_settings']['date_default_timezone']['#default_value'] = "Australia/Perth"; # this isn't working. Probably form alter is populating this with browser or server timezone.

}