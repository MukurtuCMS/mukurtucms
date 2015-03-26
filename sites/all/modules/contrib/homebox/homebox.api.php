<?php

/**
 * @file
 * Homebox API: Blocks are rendered through hook_block(). The $edit parameter is overloaded
 * with the homebox block object, which included properties for any customized
 * fields.
 */

/**
 * List form values to be stored.
 *
 * Used to make sure configuarble blocks only save what is necessary.
 *
 * @param $block
 *   A block oject with at least module and delta properties. module will
 *   always match your module name. Use delta if you have different types of
 *   configurable blocks.
 *
 * @return
 *   An array of strings matching the hook_homebox_block_edit_form() elements
 *   that should be saved.
 */
function hook_homebox_block_keys($block) {
  return array('title', 'content');
}

/**
 * Provide a custom block configuration form for a block.
 *
 * The form will display above the block; keep it concise. Allows users to
 * customize what is shown on their homebox page. For example, number of items
 * shown, switch to a different item, or cutomize details.
 *
 * For extra validation and processing, use Form API's #validate, #submit and
 * other features.
 *
 * @param $block
 *   A block oject with at least module and delta properties. module will
 *   always match your module name. Use delta if you have different types of
 *   configurable blocks.
 *
 * @return
 *   A Form API array. Submit buttons, working with AHAH, and saving are
 *   handled by homebox.
 *
 * @see form.inc
 */
function hook_homebox_block_edit_form($block) {
  $form = array();

  $form['title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#size' => 25,
    '#default_value' => $block->title,
    '#required' => TRUE,
  );
  $form['content'] = array(
    '#type' => 'textarea',
    '#title' => t('Content'),
    '#default_value' => $block->content,
    '#required' => TRUE,
  );
  $form['#validate'][] = 'project_issue_homebox_block_edit_form_validate';

  return $form;
}
