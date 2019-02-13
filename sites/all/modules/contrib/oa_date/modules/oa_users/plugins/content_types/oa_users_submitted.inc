<?php

/**
 * @file
 * Provides a panel pane that displays add node submitted-by ribbon.
 */

$plugin = array(
  'title' => t('Submitted by'),
  'description' => t('Display the submission info for the node.'),
  'single' => TRUE,
  'category' => array(t('Open Atrium'), -9),
  'edit form' => 'oa_user_submitted_form',
  'render callback' => 'oa_user_submitted_render',
  'required context' => new ctools_context_required(t('Node'), 'node'),
  'defaults' => array(
    'align' => 0,
    'label' => TRUE,
    'date' => 0,
    'picture' => FALSE,
    'image_style' => 'oa_medium_thumbnail',
    'node_title' => FALSE,
    'hide_author' => FALSE,
  ),
);

/**
 * Run-time rendering of the body of the block (content type)
 * See ctools_plugin_examples for more advanced info
 */
function oa_user_submitted_render($subtype, $conf, $args, $context = NULL) {
  if (!isset($context->data)) {
    return;
  }
  $block = new stdClass();
  $block->title = '';

  $node = $context->data;

  $user = user_load($node->uid);

  $vars['show_title'] = !empty($conf['node_title']) ? $conf['node_title'] : FALSE;
  $vars['title'] = $vars['show_title'] ? theme('head_title') : '';
  if (!empty($vars['title'])) {
    // Used in the oa_pane_title to supress the page title
    $GLOBALS['oa_hide_page_title'] = TRUE;
  }
  else {
    $vars['show_title'] = FALSE;
  }

  $image_style = !empty($conf['image_style']) ? $conf['image_style'] : 'oa_medium_thumbnail';
  $vars['userlink'] = l(format_username($user), 'user/' . $user->uid);
  $vars['picture'] = empty($conf['picture']) ? oa_users_picture($user, $image_style) : '';
  $vars['align'] = !empty($conf['align']) ? 'right' : 'left';
  $vars['show_author'] = !empty($conf['hide_author']) ? FALSE : TRUE;
  $date = !empty($conf['date']) ? $node->changed : $node->created;
  $vars['label'] = !empty($conf['label']) ? (!empty($conf['date']) ? t('Updated') : t('Posted')) : '';
  $vars['bylabel'] = !empty($conf['label']) ? ' ' . t('by') . ' ' : '';
  $vars['date'] = oa_date_format_date($date) . ' - ' . format_date($date, 'custom', 'G:ia');

  $block->content = theme('oa_users_submitted', $vars);
  return $block;
}

/**
 * Widget config form
 */
function oa_user_submitted_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['node_title'] = array(
    '#title' => t('Show node title'),
    '#type' => 'checkbox',
    '#default_value' => !empty($conf['node_title']) ? $conf['node_title'] : FALSE,
  );

  $form['hide_author'] = array(
    '#title' => t('Hide post author and date'),
    '#type' => 'checkbox',
    '#default_value' => !empty($conf['hide_author']) ? $conf['hide_author'] : FALSE,
  );

  $form['align'] = array(
    '#type' => 'select',
    '#options' => array(
      0 => 'Left',
      1 => 'Right',
    ),
    '#title' => 'Alignment',
    '#default_value' => $conf['align'],
  );

  $form['date'] = array(
    '#type' => 'select',
    '#options' => array(
      0 => 'Created',
      1 => 'Modified',
    ),
    '#title' => 'Date',
    '#default_value' => $conf['date'],
  );

  $form['label'] = array(
    '#title' => t('Show text labels'),
    '#type' => 'checkbox',
    '#default_value' => $conf['label'],
  );

  $form['picture'] = array(
    '#title' => t('Hide user picture'),
    '#type' => 'checkbox',
    '#default_value' => $conf['picture'],
  );

  $form['image_style'] = array(
    '#title' => t('Picture image style'),
    '#type' => 'textfield',
    '#default_value' => !empty($conf['image_style']) ? $conf['image_style'] : 'oa_medium_thumbnail',
  );

  return $form;
}


/**
 * Saves changes to the widget.
 */
function oa_user_submitted_form_submit($form, &$form_state) {
  foreach (array_keys($form_state['values']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

