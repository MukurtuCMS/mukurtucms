<?php

/**
 * @file
 * owlcarousel_views_plugin_style_owlcarousel.inc
 */

/**
 * Implements a style type plugin for the Views module.
 */
class owlcarousel_views_plugin_style_owlcarousel extends views_plugin_style {

  /**
   * Set default options.
   */
  function option_definition() {
    $options = parent::option_definition();
    $options['instance'] = array('default' => 'owlcarousel_settings_default');

    return $options;
  }

  /**
   * Show a form to edit the style options.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    // Carousel instance settings.
    $options = array();
    $keys = owlcarousel_instance_callback_list();
    foreach ($keys as $key) {
      if (!is_numeric(substr($key, -1, 1))) {
        $options[$key] = $key;
      }
    }

    $form['settings'] = array(
      '#type' => 'fieldset',
      '#title' => t('Owl Carousel'),
    );
    $form['settings']['instance'] = array(
      '#title' => t('Options Set'),
      '#type' => 'select',
      '#description' => t('Settings to apply to this carousel instance.'),
      '#options' => $options,
      '#default_value' => $this->options['instance'],
    );
  }

  /**
   * Additionally format saved instance.
   */
  function options_submit(&$form, &$form_state) {
    $settings = $form_state['values']['style_options'];
    $config = array_merge($settings['settings']);

    // Keep default value structure.
    $form_state['values']['style_options'] = $config;
  }

  /**
   * Render display.
   */
  function render() {
    $id = drupal_html_id('owl-carousel-' . $this->view->current_display . $this->view->vid);
    $this->options['id']['default'] = $id;

    // Group results.
    $rows = $this->render_grouping($this->view->result, $this->options['grouping']);

    $output = '';
    foreach ($rows as $title => $row) {
      $output .= theme($this->theme_functions(),
        array(
          'view' => $this->view,
          'options' => $this->options,
          'rows' => $row,
          'title' => $title
        )
      );
    }

    return $output;
  }
}
