
<?php
/**
 * @file
 * Views include file with views hooks.
 */


/**
 * Implementation of hook_views_plugins().
 */
function views_autocomplete_views_plugins() {
  $path = drupal_get_path('module', 'views_autocomplete');
  return array(
    'module' => 'views_autocomplete',
    'style' => array(
      'views_autocomplete' => array(
        'title'           => t('Autocomplete JSON data document'),
        'path'            => $path . '/plugins',
        'help'            => t('Displays nodes in autocomplete JSON data format.'),
        'handler'         => 'views_plugin_style_autocomplete',
        'theme'           => 'views_views_autocomplete',
        'theme file'      => 'views_views_autocomplete.theme.inc',
        'theme path'      => $path . '/theme',
        'uses row plugin' => FALSE,
        'uses fields'     => TRUE,
        'uses options'    => TRUE,
        'type'            => 'normal',
        'help_topic'      => 'autocomplete',
        'even empty'      => TRUE,
      ),
    ),
  );
}

/**
 * Implementation of hook_views_handlers().
 */
function views_autocomplete_views_handlers() {
  return array(
    'handlers' => array(
      'views_handler_filter_string_autocomplete' => array(
        'parent' => 'views_handler_filter_string',
      ),
    ),
  );
}

/**
 * Implementation of hook_views_data_alter().
 */
function views_autocomplete_views_data_alter(&$data) {
  // TODO: There has to be a less heavy handed way of doing this.
  foreach ($data as $table => $field) {
    foreach ($field as $field_name => $info) {
      if (isset($info['filter']['handler']) && $info['filter']['handler'] == 'views_handler_filter_string') {
        $data[$table][$field_name]['filter']['handler'] = 'views_handler_filter_string_autocomplete';
      }
    }
  }
}