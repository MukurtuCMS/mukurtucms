<?php
/**
 * @file
 * oa_panopoly_users.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function oa_panopoly_users_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_default_page_manager_handlers_alter().
 */
function oa_panopoly_users_default_page_manager_handlers_alter(&$data) {
  if (isset($data['pm_existing_pages_user_login_panel_context'])) {
    $data['pm_existing_pages_user_login_panel_context']->conf['body_classes_to_add'] = 'oa-login'; /* WAS: '' */
    $data['pm_existing_pages_user_login_panel_context']->conf['display']->content['new-36405db8-54c5-495c-ba8a-0a5f7ade185a']->configuration['override_title_text'] = 'Log In'; /* WAS: '' */
    $data['pm_existing_pages_user_login_panel_context']->conf['display']->hide_title = 1; /* WAS: 0 */
    $data['pm_existing_pages_user_login_panel_context']->conf['display']->layout = 'radix_boxton'; /* WAS: 'radix_burr_flipped' */
    $data['pm_existing_pages_user_login_panel_context']->conf['display']->panel_settings['contentmain'] = array(
      'style' => 'oa_styles_oa_pane',
    ); /* WAS: '' */
  }
}

