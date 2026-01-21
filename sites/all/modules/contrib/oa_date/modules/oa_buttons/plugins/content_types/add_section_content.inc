<?php
/**
 * @file oa_notifications_pane.inc
 */

$plugin = array(
  'title' => t('Add Section Content'),
  'description' => t('Create section content according to allowed content options'),
  'single' => TRUE,
  'category' => array(t('OA Admin'), -9),
  'edit form' => 'oa_buttons_add_section_content_settings_form',
  'render callback' => 'oa_buttons_add_section_content_render',
  'required context' => new ctools_context_required(t('Node'), 'node'),
);


/**
 * Provides the form for the widget.
 */
function oa_buttons_add_section_content_settings_form($form, &$form_state) {
  return $form;
}


/**
 * Renders the widget.
 */
function oa_buttons_add_section_content_render($subtype, $conf, $args, $context) {
  $block = NULL;
  $node = $context->data;
  if ($node) {
    $buttons_for_node = oa_buttons_get_command_buttons($node);
    if (!empty($buttons_for_node)) {
      $machine_names = array();
      foreach ($buttons_for_node as $button) {
        $machine_names[$button['value']] = $button['value'];
      }
      $buttons = command_buttons_machine_name_load($machine_names);

      $item_list = array();
      $classes = array(
        'item_class' => array(
          'btn btn-primary',
          'oa-button',
         ),
        'wrapper_class' => array(
          'oa-buttons',
        ),
        'use_dropdowns' => FALSE,
        'dropdown_label' => NULL,
      );
      $block = new stdClass();
      $block->title = t('Create Content');
      $block->content = command_buttons_render_buttons($buttons, $classes, $buttons_for_node);
    }
  }
  return $block;
}


