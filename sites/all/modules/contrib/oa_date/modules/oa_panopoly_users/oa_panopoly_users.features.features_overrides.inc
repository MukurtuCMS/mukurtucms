<?php
/**
 * @file
 * oa_panopoly_users.features.features_overrides.inc
 */

/**
 * Implements hook_features_override_default_overrides().
 */
function oa_panopoly_users_features_override_default_overrides() {
  // This code is only used for UI in features. Exported alters hooks do the magic.
  $overrides = array();

  // Exported overrides for: page_manager_handlers
  $overrides["page_manager_handlers.pm_existing_pages_user_login_panel_context.conf|body_classes_to_add"] = 'oa-login';
  $overrides["page_manager_handlers.pm_existing_pages_user_login_panel_context.conf|display|content|new-36405db8-54c5-495c-ba8a-0a5f7ade185a|configuration|override_title_text"] = 'Log In';
  $overrides["page_manager_handlers.pm_existing_pages_user_login_panel_context.conf|display|hide_title"] = 1;
  $overrides["page_manager_handlers.pm_existing_pages_user_login_panel_context.conf|display|layout"] = 'radix_boxton';
  $overrides["page_manager_handlers.pm_existing_pages_user_login_panel_context.conf|display|panel_settings|contentmain"] = array(
    'style' => 'oa_styles_oa_pane',
  );

 return $overrides;
}
