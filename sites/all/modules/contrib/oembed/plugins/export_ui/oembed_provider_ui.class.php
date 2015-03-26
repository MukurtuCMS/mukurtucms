<?php

class oembed_provider_ui extends ctools_export_ui {

  /**
   * Provide the actual editing form.
   */
  function edit_form(&$form, &$form_state) {
    parent::edit_form($form, $form_state);
    $form['title'] = array(
      '#type'          => 'textfield',
      '#title'         => t('Title'),
      '#description'   => t('A human-readable title for the provider.'),
      '#size'          => 32,
      '#maxlength'     => 255,
      '#required'      => TRUE,
      '#default_value' => $form_state['item']->title,
    );

    $form['endpoint'] = array(
      '#type'          => 'textfield',
      '#title'         => t('Endpoint'),
      '#description'   => t('The endpoint where oEmbed requests are going to be sent.'),
      '#size'          => 32,
      '#maxlength'     => 255,
      '#required'      => TRUE,
      '#default_value' => $form_state['item']->endpoint,
    );

    $form['scheme'] = array(
      '#type'          => 'textarea',
      '#title'         => t('Schemes'),
      '#description'   => t('Newline separated list of schemes like !example', array('!example' => 'http://*.revision3.com/*')),
      '#required'      => TRUE,
      '#default_value' => $form_state['item']->scheme,
    );
  }

  /**
   * Overrides ctools_export_ui::edit_form_submit().
   */
  function edit_form_submit(&$form, &$form_state) {
    // Clear the oEmbed provider cache.
    oembed_providers_reset();
    parent::edit_form_submit($form, $form_state);
  }

  /**
   * Overrides ctools_export_ui::edit_form_import_submit().
   */
  function edit_form_import_submit($form, &$form_state) {
    // Clear the oEmbed provider cache.
    oembed_providers_reset();
    parent::edit_form_import_submit($form, $form_state);
  }

  /**
   * Overrides ctools_export_ui::delete_form_submit().
   */
  function delete_form_submit(&$form_state) {
    // Clear the oEmbed provider cache.
    oembed_providers_reset();
    parent::delete_form_submit($form_state);
  }

  /**
   * Overrides ctools_export_ui::set_item_state().
   */
  function set_item_state($state, $js, $input, $item) {
    // Clear the oEmbed provider cache.
    oembed_providers_reset();
    return parent::set_item_state($state, $js, $input, $item);
  }
}
