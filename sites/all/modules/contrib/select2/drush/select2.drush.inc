<?php
/**
 * @file
 * drush integration for select2.
 */

/**
 * The Select2 plugin URI.
 */
define('SELECT2_DOWNLOAD_URI_PREFIX', 'https://github.com/ivaynberg/select2/archive/');
define('SELECT2_DOWNLOAD_PREFIX', 'select2-');
define('SELECT2_DEFAULT_TAG', '3.5.4');

/**
 * Implements hook_drush_command().
 *
 * For a list of recognized keys
 * @See drush_parse_command()
 */
function select2_drush_command() {

  $items = array();

  $items['select2-download'] = array(
    'callback'    => '_select2_drush_download_select2',
    'description' => dt('Downloads the Select2 from authors github.com repository.'),
    'options' => array(
      'path' => dt('Optional. The path to the download folder. If omitted, Drush will use the default location (sites/all/libraries/select2).'),
      'tag'  => dt('Optional. The Select2 repository tag for download. If ommited @tag tag will be used. You can use "master" tag for download last Select2 version.'),
    ),
    'aliases'     => array('sel2dl'),
  );

  return $items;

}

/**
 * Implements hook_drush_help().
 */
function select2_drush_help($section) {
  switch ($section) {
    case 'drush:select2-download':
      return dt("Downloads the Select2 from authors github.com repository. Accepts an optional destination argument.");
  }
}

/**
 * Helper function downloads Select2 plugin.
 */
function _select2_drush_download_select2() {

  // Get the path from the argument, if site, or use the default.
  $drush_context = drush_get_context('DRUSH_DRUPAL_ROOT');

  // Can we use Libraries API?
  if (module_exists('libraries') && function_exists('libraries_get_path')) {
    $libraries_dir = libraries_get_path('select2');
  }

  // Load the path.
  $path = $libraries_dir ? $drush_context . '/' . $libraries_dir : $drush_context . '/sites/all/libraries/select2';

  $path = drush_get_option('path', $path);

  $tag = drush_get_option('tag', SELECT2_DEFAULT_TAG);

  drush_log(dt('Download destination path: "@path"', array('@path' => $path)), 'notice');

  // Set the directory to the download location.
  $olddir = getcwd();

  $download_path = str_replace('/select2', '', $path);

  chdir($download_path);

  $download_uri = SELECT2_DOWNLOAD_URI_PREFIX . $tag . '.zip';

  // Download the zip archive.
  if ($filepath = drush_download_file($download_uri, $download_path . '/' . $tag . '.zip')) {
    $filename = basename($filepath);
    $dirname = SELECT2_DOWNLOAD_PREFIX . basename($filepath, '.zip');

    // Remove any existing Select2 plugin directory.
    if (is_dir($dirname) || is_dir('select2')) {
      drush_delete_dir($dirname, TRUE);
      drush_delete_dir('select2', TRUE);
      drush_log(dt('A existing Select2 plugin was deleted from @path', array('@path' => $path)), 'notice');
    }

    // Decompress the zip archive.
    drush_tarball_extract($filename);

    // Change the directory name to "select2" if needed.
    if ($dirname != 'select2') {
      drush_move_dir($dirname, 'select2', TRUE);
      $dirname = 'select2';
    }
  }

  if (is_dir($dirname)) {
    drush_log(dt('Select2 plugin has been installed in @path', array('@path' => $path)), 'success');
  }
  else {
    drush_log(dt('Drush was unable to install the Select2 plugin to @path', array('@path' => $path)), 'error');
  }

  // Set working directory back to the previous working directory.
  chdir($olddir);

}
