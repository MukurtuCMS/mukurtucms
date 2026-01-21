<?php

/**
 * @file
 * Views hook implementations.
 */

/**
 * Implements hook_views_data_alter().
 */
function views_base_url_views_data_alter(&$data) {
  $data['views']['base_url'] = array(
    'title' => t('Base url'),
    'help' => t("Site's base url"),
    'field' => array(
      'handler' => 'ViewsBaseUrlHandlerBaseUrl',
    ),
  );
}
