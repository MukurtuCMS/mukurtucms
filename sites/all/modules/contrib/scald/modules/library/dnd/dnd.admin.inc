<?php
/**
 * @file
 * Provides the administration related parts of the DnD module.
 */

/**
 * Provides the main DnD settings form.
 */
function dnd_admin_form() {
  $libraries = dnd_get_libraries();
  $form['dnd_callback_url'] = array(
    '#type' => 'select',
    '#title' => t('Library'),
    '#default_value' => dnd_get_library(),
    '#description' => t('The library that will available on node edit forms if they contains fields referencing rich media content, such as Multimedia Editorial Element or Resource reference fields.'),
    '#options' => $libraries,
  );
  $form['dnd_modal_width'] = array(
    '#type' => 'textfield',
    '#title' => t('Modal width'),
    '#size' => 5,
    '#maxlength' => 5,
    '#default_value' => variable_get('dnd_modal_width', 500),
    '#description' => t('The width of the modal window opened from the library in pixels or percentage. Example: 100 for 100 pixels, 0.5 for 50%.'),
  );
  $form['dnd_modal_height'] = array(
    '#type' => 'textfield',
    '#title' => t('Modal height'),
    '#size' => 5,
    '#maxlength' => 5,
    '#default_value' => variable_get('dnd_modal_height', 300),
    '#description' => t('The height of the modal window opened from the library in pixels or percentage. Example: 100 for 100 pixels, 0.5 for 50%.'),
  );
  $form['dnd_modal_admin'] = array(
    '#type' => 'checkbox',
    '#title' => t('Use the admin theme'),
    '#default_value' => variable_get('dnd_modal_admin', FALSE),
    '#description' => t('If enabled, the library will be considered to be administrative.'),
  );
  if (function_exists('qtip_fetch_instances_field')) {
    $form['dnd_qtip_instance'] = qtip_fetch_instances_field(variable_get('dnd_qtip_instance', ''));
  }
  $mee_store_format = (module_exists('mee')) ? mee_store_format() : '';
  if (!empty($mee_store_format)) {
    if ($mee_store_format === 'embed_div') {
      $form['dnd_uses_caption_default'] = array(
        '#type' => 'checkbox',
        '#title' => t('Enable captions by default'),
        '#default_value' => variable_get('dnd_uses_caption_default', TRUE),
        '#description' => t('If enabled, captions in CKEditor will show up under Atoms by default.'),
      );
    }
    $form['mee_store_format'] = array(
      '#type' => 'select',
      '#options' => array(
        'sas' => t('Scald Atom Shorthand'),
        'embed_div' => t('Div attributes'),
      ),
      '#title' => t('Wysiwyg store format'),
      '#default_value' => $mee_store_format,
      '#description' => t('The store method used in Wysiwyg editors to embed atoms. The default value is "Scald Atom Shorthand", however to use the CKEditor widget plugin, the "Div attributes" value should be used.')
    );
  }
  return system_settings_form($form);
}

/**
 * Validate callback for dnd_admin_form().
 *
 * Ensure that width and height are numeric values.
 */
function dnd_admin_form_validate($form, &$form_state) {
  if (!is_numeric($form_state['values']['dnd_modal_width'])) {
    form_set_error('dnd_modal_width', t('Width value must be numeric.'));
  }
  if (!is_numeric($form_state['values']['dnd_modal_height'])) {
    form_set_error('dnd_modal_height', t('Height value must be numeric.'));
  }
  $width = (float) $form_state['values']['dnd_modal_width'];
  $height = (float) $form_state['values']['dnd_modal_height'];
  if ($width < 0) {
    form_set_error('dnd_modal_width', t('Width value must be bigger than zero.'));
  }
  if ($height < 0) {
    form_set_error('dnd_modal_height', t('Height value must be bigger than zero.'));
  }
  if (($width <= 1 && $height > 1) || ($width > 1 && $height <= 1)) {
    form_set_error('dnd_modal_width', t('Width and height values must both be in the same metric.'));
  }
}

