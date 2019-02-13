<?php
/**
 * @file
 * Feature provides a default Mail Comment importer to produce comments from emails.
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function mailcomment_default_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => 1);
  }
}
