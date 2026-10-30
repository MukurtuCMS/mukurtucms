<?php

/**
 * @file
 * Defines the Node Token widget.
 */

$plugin = array(
  'title' => t('Node Tokens'),
  'description' => t('Display custom HTML including node tokens.'),
  'single' => TRUE,
  'category' => t('Open Atrium'),
  'edit form' => 'oa_core_node_token_edit_form',
  'render callback' => 'oa_core_node_token_render',
  'required context' => new ctools_context_required(t('Node'), 'node'),
  'defaults' => array(
    'token_title' => '',
    'token_body' => '',
  ),
);


/**
 * Render callback for the node token pane.
 */
function oa_core_node_token_render($subtype, $conf, $args, $context = NULL) {
  if (empty($context->data->nid) || !node_access('view', $context->data)) {
    return;
  }

  $node = $context->data;

  $block = new stdClass();
  $block->title = token_replace($conf['token_title'], array('node' => $node));
  $body = isset($conf['token_body']['value']) ? $conf['token_body']['value'] : '';
  $vars['body'] = token_replace($body, array('node' => $node));
  $block->content = theme('oa_core_node_token', $vars);

  return $block;
}

/**
 * Edit form for the panel.
 */
function oa_core_node_token_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $form['override_title']['#access'] = FALSE;
  $form['override_title_text']['#access'] = FALSE;
  $form['token_title'] = array(
    '#title' => t('Displayed Title'),
    '#description' => t('Enter the title to be displayed, including any token references.'),
    '#type' => 'textfield',
    '#default_value' => $conf['token_title'],
  );
  $form['token_body'] = array(
    '#title' => t('Displayed Text'),
    '#description' => t('Enter the full text to be displayed, including any token references.'),
    '#type' => 'text_format',
    '#format' => isset($conf['token_body']['format']) ? $conf['token_body']['format'] : 'panopoly_wysiwyg_text',
    '#default_value' => isset($conf['token_body']['value']) ? $conf['token_body']['value'] : '',
  );
  $form['tokens'] = array(
    '#theme' => 'token_tree',
    '#token_types' => array('node'),
    '#recursion_limit' => 2,
  );

  return $form;
}

/**
 * Submit handler for edit form. Save the custom form fields we added.
 */
function oa_core_node_token_edit_form_submit($form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

