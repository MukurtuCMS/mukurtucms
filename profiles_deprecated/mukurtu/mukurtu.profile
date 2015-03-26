<?php

/**
 * Implementation of hook_form().
 */
 
function mukurtu_install_tasks($install_state) {
  $tasks = array (
    'mukurtu_configure' => array(),
  );
  return $tasks;
}

/**
 * Set up base config (adapted from Pantheon installer)
 */
function mukurtu_configure() {
  // Set default Mukurtu / Pantheon variables
  variable_set('cache', 1);
  variable_set('block_cache', 1);
  variable_set('cache_lifetime', '0');
  variable_set('page_cache_maximum_age', '900');
  variable_set('page_compression', 0);
  variable_set('preprocess_css', 1);
  variable_set('preprocess_js', 1);
  $search_active_modules = array(
    'apachesolr_search' => 'apachesolr_search',
    'user' => 'user',
    'node' => 0
  );
  variable_set('search_active_modules', $search_active_modules);
  variable_set('search_default_module', 'apachesolr_search');
  drupal_set_message(t('Mukurtu defaults configured.'));
}

/**
 * Implements hook_form_FORM_ID_alter().
 *
 * Allows the profile to alter the site configuration form.
 */
function mukurtu_form_install_configure_form_alter(&$form, $form_state) {
  // Pre-populate the site name with the server name.
  $form['site_information']['site_name']['#default_value'] = $_SERVER['SERVER_NAME'];
  $form['site_information']['site_email']['#default_value'] = 'chachasikes@gmail.com';
}

 
function mukurtu_profile_form($form, &$form_state, &$install_state) {
  drupal_set_title(st('Configure and Install Mukurtu'));
  
  // Warn about settings.php permissions risk
  $settings_dir = conf_path();
  $settings_file = $settings_dir . '/settings.php';
  // Check that $_POST is empty so we only show this message when the form is
  // first displayed, not on the next page after it is submitted. (We do not
  // want to repeat it multiple times because it is a general warning that is
  // not related to the rest of the installation process; it would also be
  // especially out of place on the last page of the installer, where it would
  // distract from the message that the Drupal installation has completed
  // successfully.)
  if (empty($_POST) && (!drupal_verify_install_file(DRUPAL_ROOT . '/' . $settings_file, FILE_EXIST|FILE_READABLE|FILE_NOT_WRITABLE) || !drupal_verify_install_file(DRUPAL_ROOT . '/' . $settings_dir, FILE_NOT_WRITABLE, 'dir'))) {
    drupal_set_message(st('All necessary changes to %dir and %file have been made, so you should remove write permissions to them now in order to avoid security risks. If you are unsure how to do so, consult the <a href="@handbook_url">online handbook</a>.', array('%dir' => $settings_dir, '%file' => $settings_file, '@handbook_url' => 'http://drupal.org/server-permissions')), 'warning');
  }

  drupal_add_js(drupal_get_path('module', 'system') . '/system.js');
  // We add these strings as settings because JavaScript translation does not
  // work on install time.
  drupal_add_js(array('copyFieldValue' => array('edit-site-mail' => array('edit-account-mail'))), 'setting');
  // Add JS to show / hide the 'Email administrator about site updates' elements
  drupal_add_js('jQuery(function () { Drupal.hideEmailAdministratorCheckbox() });', 'inline');

  // Return the form.
  $form += _install_configure_form($form, $form_state, $install_state);

  $form['server_settings']['clean_url'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable Clean URLs'),
    '#default_value' => 1,
    '#description' => t('If clean URLs are configured on this server, you can check this box. Details on <a href="http://drupal.org/getting-started/clean-urls">setting up clean URLs</a> are available.'),
    '#weight' => 20,
  );

  $form['actions']['submit'] = array('#type' => 'submit', '#value' => t('Install Mukurtu'));
  return $form;
}

/**
 * Validate handler for the "install_configure" form.
 */
function mukurtu_profile_form_validate($form, &$form_state) {
  install_configure_form_validate($form, $form_state);
}
