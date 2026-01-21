<?php

/**
 * Implements hook_install_tasks().
 */

function mukurtu_install_tasks($install_state) {
  $tasks = array (
    'mukurtu_set_misc_vars' => array(),
    'mukurtu_set_theme' => array(),
    'mukurtu_create_default_boxes' => array(),
    'mukurtu_resolve_dependencies' => array(),
    'mukurtu_revert_features' => array(
      'display_name' => st('Finalize configuration'),
    ),
    'mukurtu_rebuild_permissions' => array(),
    'mukurtu_default_tax_terms' => array(),
    'mukurtu_default_menu_links' => array(),
    'mukurtu_create_default_pages' => array(),
    //    'mukurtu_create_default_contexts' => array(),
    'mukurtu_set_permissions' => array(),
    'mukurtu_set_scald_drawer_thumbnails' => array(),
    'mukurtu_delete_og_roles' => array(),
    'mukurtu_cycle_search_api' => array(),
    'mukurtu_revert_features' => array(),
    'mukurtu_create_default_content' => array(),
    'mukurtu_revert_features' => array(),
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

function mukurtu_set_misc_vars () {
  variable_set ('error_level', ERROR_REPORTING_HIDE);
  variable_set ('file_private_path', 'sites/default/files/private');
  variable_set ('clean_url', 1);
  variable_set ('cron_safe_threshold', 0);
}

function mukurtu_set_theme () {
  theme_enable(array('bootstrap', 'mukurtu', 'mukurtu_starter'));
  variable_set ('theme_default', 'mukurtu');
  theme_disable (array('bartik', 'seven'));
}

function mukurtu_create_default_boxes() {
  // Footer
  $box = boxes_factory('simple', array(
    'delta' => 'ma_site_footer',
    'title' => '',
    'description' => 'Custom Site Footer',
    'options' => array(
      'body' => array(
        'value' => '<p>Edit Site Footer here.</p>',
        'format' => 'full_html',
      ),
    ),
  ));
  $box->save();

  // Header (for frontpage)
  $box = boxes_factory('simple', array(
    'delta' => 'ma_site_header',
    'title' => '',
    'description' => 'Custom Site Header',
    'options' => array(
      'body' => array(
        'value' => '<p><img src="sites/all/themes/mukurtu_starter/mukurtu_default_banner.jpg" alt="" width="1140" /></p>

<h1> Welcome to Mukurtu CMS </h1>
<p> Mukurtu (MOOK-oo-too) is a grassroots project aiming to empower communities to manage, share and exchange their digital heritage in culturally relevant and ethically-minded ways. We are committed to maintaining an open, community-driven approach to Mukurtu’s continued development. Our first priority is to help build a platform that fosters relationships of respect and trust. <a href="about"> Learn More >> </a></p>',
        'format' => 'ds_code',
      ),
    ),
  ));
  $box->save();

}

function mukurtu_resolve_dependencies() {
    // Long term the community_tags module will probably be removed.
    // We have removed it as a dependency from the Mukurtu features now, which
    // allows sites to disable the module if they prefer. Here we enable the
    // module as part of new installs for the sake of consistency.
    module_enable(array('ma_dictionary'));
}

function mukurtu_revert_features () {
  features_revert_module('ma_search_api'); // First revert search_api to get the node index
  features_revert(); // Revert all features
  drupal_get_messages();
  features_revert(); // Revert all features a second time, for any straggling components
  drupal_get_messages();
}

function mukurtu_rebuild_permissions () {
  node_access_rebuild();
}

function mukurtu_default_tax_terms () {
  $taxonomy = array(
    'category' => array(
      'Default',
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
    'weight' => -45,
    'expanded' => 0,
  );
  menu_link_save($item);

  $item = array(
    'link_path' => 'browse',
    'link_title' => 'Browse',
    'menu_name' => 'menu-browse-menu',
    'weight' => -43,
    'expanded' => 0,
    'customized' => 1,
  );
  menu_link_save($item);

  $item = array(
    'link_path' => 'dictionary',
    'link_title' => 'Browse Dictionary',
    'menu_name' => 'menu-browse-menu',
    'weight' => -40,
    'expanded' => 0,
    'customized' => 1,
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
  $node = new stdClass();
  $node->type = 'page';
  $node->uid = 1;
  $node->language = LANGUAGE_NONE;
  $node->title = 'About';
  $node->body[LANGUAGE_NONE][0] = array (
    'value' => file_get_contents(DRUPAL_ROOT . '/' . drupal_get_path('profile', 'mukurtu') . '/pages/about'),
    'format' => 'full_html',
  );
  $node->menu = array(
    'link_title' => 'About',
    'menu_name' => 'menu-browse-menu',
    'weight' => -55,
    'plid' => 0,
    'enabled' => 1,
  );
  node_save($node);
}

function mukurtu_create_default_contexts () {

  // frontpage context
  $context = new stdClass();
  $context->disabled = TRUE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'front_page';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'boxes-ma_site_header' => array(
          'module' => 'boxes',
          'delta' => 'ma_site_header',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-communities_content-block_1' => array(
          'module' => 'views',
          'delta' => 'communities_content-block_1',
          'region' => 'content',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  context_save ($context);
}

function mukurtu_cycle_search_api() {
    // Disable Search API then revert the ma_search_api feature
    if(module_exists('search_api')) {
        $result = search_api_server_disable('search_api_db_server');
        if($result) {
            $feature = features_get_features('ma_search_api');
            if(isset($feature->info)) {
                $components = array_keys($feature->info['features']);
                features_revert(array('ma_search_api' => $components));
            }
        }
    }
}

function mukurtu_create_default_content() {
  // Cycle the theme feature.
  features_revert_module('ma_base_theme');

  // Create frontpage beans.
  _ma_base_theme_create_default_beans();

  // Cycle the theme feature.
  features_revert_module('ma_base_theme');

  // Set default browse mode.
  _ma_base_theme_set_default_browse('digital-heritage');

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

