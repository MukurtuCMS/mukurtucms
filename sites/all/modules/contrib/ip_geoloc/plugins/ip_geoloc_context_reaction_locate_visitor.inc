<?php

/**
 * @file
 * Output javascript to locate visitor using GPS/Wifi.
 */
class ip_geoloc_context_reaction_locate_visitor extends context_reaction {

  function options_form($context) {
    return array('locate_visitor' => array(
      '#type' => 'value',
      '#value' => TRUE)
    );
  }

  function options_form_submit($values) {
    return array('locate_visitor' => TRUE);
  }

  /**
   *
   */
  function execute() {
    foreach (context_active_contexts() as $context) {
      if (!empty($context->reactions['locate_visitor'])) {
        /* drupal_set_message(t("Referer, %referer, path: %path, context: %context, reacting with %reaction", array(
          '%referer' => $_SERVER['HTTP_REFERER'],
          '%path' => drupal_get_path_alias(),
          '%context' => $context->name,
          '%reaction' => t('Locate visitor using GPS/Wifi'),
        ))); */
        if (!ip_geoloc_same_path()) {
          ip_geoloc_get_current_location();
        }
      }
    }
  }
}
