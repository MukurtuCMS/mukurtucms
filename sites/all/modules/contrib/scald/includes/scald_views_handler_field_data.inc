<?php
/**
 * @file
 * Provides a field showing a part of the data-bag on an atom
 */
class scald_views_handler_field_data extends views_handler_field {
  /**
   * Overrides views_handler_field::option_definition().
   */
  public function option_definition() {
    $options = parent::option_definition();

    $options['data_key'] = array('default' => '');
    $options['plain'] = array('default' => TRUE);

    return $options;
  }

  /**
   * Overrides views_handler_field::options_form().
   */
  public function options_form(&$form, &$form_state) {
    $form['data_key'] = array(
      '#type' => 'textfield',
      '#title' => t('Data key'),
      '#default_value' => $this->options['data_key'],
      '#description' => t('Specify the key of the data that should be displayed. This is atom type and provider specific.'),
    );

    $form['plain'] = array(
      '#type' => 'checkbox',
      '#title' => t('Sanitize output'),
      '#default_value' => $this->options['plain'],
      '#description' => t('Specify if the output should be sanitized to prevent injection.'),
    );

    parent::options_form($form, $form_state);
  }

  /**
   * Overrides views_handler_field::render().
   */
  function render($values) {
    $data = unserialize($values->{$this->field_alias});
    $content = NULL;
    if (!empty($data[$this->options['data_key']])) {
      $output = (string) $data[$this->options['data_key']];
      $content = array(
        '#markup' => $this->options['plain'] ? check_plain($output) : $output,
      );
    }
    return $content;
  }
}
