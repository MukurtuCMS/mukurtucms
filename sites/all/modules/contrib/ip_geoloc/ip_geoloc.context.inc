<?php

/**
 * Implements hook_context_plugins().
 */
function ip_geoloc_context_plugins() {
  $plugins = array();
  $plugins['ip_geoloc_context_reaction_locate_visitor'] = array(
    'handler' => array(
      'path' => drupal_get_path('module', 'ip_geoloc') . '/plugins',
      'file'  => 'ip_geoloc_context_reaction_locate_visitor.inc',
      'class' => 'ip_geoloc_context_reaction_locate_visitor',
      'parent' => 'context_reaction',
    ),
  );
  return $plugins;
}

/**
 * Implements hook_context_registry().
 */
function ip_geoloc_context_registry() {
  return array(
    'reactions' => array(
      'locate_visitor' => array(
        'title' => t('Locate visitor using GPS/Wifi (if page changed)'),
        'plugin' => 'ip_geoloc_context_reaction_locate_visitor',
      ),
    ),
  );
}

/**
 * Implements hook_context_page_reaction().
 */
function ip_geoloc_context_page_reaction() {
  if ($plugin = context_get_plugin('reaction', 'locate_visitor')) {
    $plugin->execute();
  }
}
