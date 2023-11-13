<?php

/**
 * @file
 * Provides a panel pane that displays add content links.
 */

$plugin = array(
  'title' => t('Add content types'),
  'description' => t('List of content types in a widget.'),
  'single' => TRUE,
  'category' => array(t('OA Admin'), -9),
  'edit form' => 'oa_widgets_add_content_edit_form',
  'render callback' => 'oa_widgets_add_content_render',
  'defaults' => array(
    'oa_widgets_types' => array(),
    'oa_widgets_use_all' => TRUE,
    'button_class' => '',
    'title_prefix' => '',
  ),
);


/**
 * Run-time rendering of the body of the block (content type)
 * See ctools_plugin_examples for more advanced info
 */
function oa_widgets_add_content_render($subtype, $conf, $args, $context = NULL) {

  $nodes = $conf['oa_widgets_types'];

  $class = !empty($conf['button_class']) ? $conf['button_class'] : '';
  if (strpos($class, 'btn') !== FALSE) {
    if (strpos($class, 'btn-') === FALSE) {
      // handle default buttons in bootstrap 3
      $class .= ' btn-default';
    }
  }  $prefix = !empty($conf['title_prefix']) ? $conf['title_prefix'] : '';
  $links = array();
  foreach ($nodes as $node_type) {
    $node = node_type_load($node_type);
    if (is_object($node) && node_access('create', $node_type)) {
      $links[] = '<li>' .
        l($prefix . $node->name, 'node/add/' . str_replace('_', '-', $node_type) ,
          array('attributes' => array(
            'class' => $class)))
        . '</li>';
    }
  }
  $output = '<ul>' . implode($links) . '</ul>';

  $block = new stdClass();
  $block->title = t('Create content');
  $block->content = $output;

  if (!empty($links)) {
    return $block;
  }
  return FALSE;
}

/**
 * Custom edit form to allow users to enable/disable selectable content types
 */
function oa_widgets_add_content_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $nodes = oa_core_list_content_types();

  $options = array();
  foreach ($nodes as $node) {
    $options[$node->type] = check_plain($node->name);
  }
  $form['settings']['oa_widgets_types'] = array(
    '#title' => t('Enable content types'),
    '#type' => 'checkboxes',
    '#options' => $options,
    '#default_value' => isset($conf['oa_widgets_types']) ? $conf['oa_widgets_types'] : array_values($options),
    '#description' => t('Select which content types you would like to enable for this widget.'),
  );
  $form['button_class'] = array(
    '#title' => t('CSS class for links'),
    '#type' => 'textfield',
    '#default_value' => $conf['button_class'],
    '#description' => 'Enter CSS class for links, such as btn.'
  );
  $form['title_prefix'] = array(
    '#title' => t('Title Prefix'),
    '#type' => 'textfield',
    '#default_value' => $conf['title_prefix'],
    '#description' => 'Enter prefix text for link titles.'
  );

  return $form;
}


/**
 * Saves changes to the widget.
 */
function oa_widgets_add_content_edit_form_submit($form, &$form_state) {
  foreach (array_keys($form_state['values']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

