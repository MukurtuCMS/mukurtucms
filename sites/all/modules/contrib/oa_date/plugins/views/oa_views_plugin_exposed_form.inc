<?php

/**
 * @file
 * Defines an exposed form plugin that contains some OA goodies.
 */

class oa_views_plugin_exposed_form extends views_plugin_exposed_form {

  /**
   * Provide options and defaults.
   */
  function option_definition() {
    $options = parent::option_definition();
    $options['collapsed_filter'] = array('default' => TRUE, 'translatable' => TRUE);
    return $options;
  }
  
  /**
   * Provide options form.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    
    $form['collapsed_filter'] = array(
      '#type' => 'checkbox',
      '#title' => t('Collapsed filter'),
      '#description' => t('Adds a button that will show the exposed filter. Collapsed by default.'),
      '#default_value' => $this->options['collapsed_filter'],
    );
  }
  
  /**
   * Alter the exposed form based on our settings.
   */
  function exposed_form_alter(&$form, &$form_state) {
    parent::exposed_form_alter($form, $form_state);
    
    $form['#collapsed_filter'] = $this->options['collapsed_filter'];
  }
}
