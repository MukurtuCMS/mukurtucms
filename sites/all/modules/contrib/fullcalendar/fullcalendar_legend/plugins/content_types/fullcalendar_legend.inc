<?php

/**
 * @file
 * Defines a CTools content type for FullCalendar Legends.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('FullCalendar Legend'),
  'description' => t('A legend, generally for use with FullCalendar Colors.'),
  'category' => t('FullCalendar'),
  'render callback' => 'fullcalendar_legend_content_type_render',
  'edit form' => 'fullcalendar_legend_content_type_edit_form',
);

/**
 * Implements MODULE_PLUGIN_content_type_render().
 */
function fullcalendar_legend_content_type_render($subtype, $conf, $panel_args, $context) {
  if (empty($conf['view']) || empty($conf['legend_type'])) {
    return;
  }
  list($name, $display) = explode('-', $conf['view']);
  $view = views_get_view($name);
  if (empty($view)) {
    return;
  }
  $view->set_display($display);

  return (object) array(
    'module' => 'fullcalendar_legend',
    'delta' => 'fullcalendar_legend',
    'content' => fullcalendar_legend_build_legend($view, $conf['legend_type']),
  );
}

/**
 * Implements MODULE_PLUGIN_content_type_edit_form().
 */
function fullcalendar_legend_content_type_edit_form($form, &$form_state) {
  if (empty($form_state['display'])) {
    return $form;
  }

  $conf = $form_state['conf'];
  $form['legend_type'] = array(
    '#type' => 'select',
    '#title' => t('Legend type'),
    '#options' => array(
      'bundle' => t('Bundle'),
      'taxonomy' => t('Taxonomy'),
    ),
    '#default_value' => isset($conf['legend_type']) ? $conf['legend_type'] : '',
    '#description' => t('Select the type of legend to display.'),
  );
  $form['view'] = array(
    '#type' => 'select',
    '#title' => t('FullCalendar view'),
    '#description' => t('Select the associated calendar'),
    '#options' => _fullcalendar_legend_get_views_panes($form_state['display']),
    '#default_value' => isset($conf['view']) ? $conf['view'] : '',
  );
  return $form;
}

/**
 * Form submission handler for fullcalendar_legend_content_type_edit_form().
 */
function fullcalendar_legend_content_type_edit_form_submit($form, &$form_state) {
  foreach (array('view', 'legend_type') as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}

/**
 * Gets the available View names.
 *
 * @param object $panel
 *   The current panel object.
 *
 * @return array
 *   An asssociative array of View names, keyed by machine name.
 */
function _fullcalendar_legend_get_views_panes($panel) {
  $views = array();
  foreach ($panel->content as $pid => $pane) {
    if ($pane->type != 'views_panes') {
      continue;
    }
    list($name, $display) = explode('-', $pane->subtype);
    $view = views_get_view($name);
    if (empty($view)) {
      continue;
    }

    $view->set_display($display);
    if ($view->display_handler->get_option('style_plugin') != 'fullcalendar') {
      continue;
    }
    $views[$pane->subtype] = $view->human_name;
  }
  return $views;
}
