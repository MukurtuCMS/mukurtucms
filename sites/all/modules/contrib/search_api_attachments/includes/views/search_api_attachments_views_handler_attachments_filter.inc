<?php

/**
 * @file
 * Contains SearchApiAttachmentsViewsHandlerAttachmentsFilter.
 */

/**
 * Views filter handler class to filter attachments results.
 */
class SearchApiAttachmentsViewsHandlerAttachmentsFilter extends views_handler_filter {

  /**
   * {@inheritdoc}
   */
  public function option_definition() {
    $options = parent::option_definition();
    $options['saa_exclude_attachments'] = array('default' => 0);
    return $options;
  }

  /**
   * {@inheritdoc}
   */
  public function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['saa_exclude_attachments'] = array(
      '#type' => 'checkbox',
      '#title' => t('Exclude search in attachments'),
      '#default_value' => $this->options['saa_exclude_attachments'],
    );
  }

  /**
   * {@inheritdoc}
   */
  public function admin_summary() {
    if (!empty($this->options['exposed'])) {
      return t('exposed');
    }

    if ($this->value == 0) {
      return t('Include attachments');
    }

    if ($this->value == 1) {
      return t('Exclude attachments');
    }

    return check_plain((string) $this->value);
  }

  /**
   * {@inheritdoc}
   */
  public function exposed_form(&$form, &$form_state) {
    if (empty($this->options['exposed'])) {
      return;
    }
    $form['saa_exclude_attachments'] = array(
      '#type' => 'checkbox',
      '#title' => t('Exclude search in attachments'),
      '#default_value' => $this->options['saa_exclude_attachments'],
    );
  }

  /**
   * {@inheritdoc}
   */
  public function query() {
    if (empty($this->value[0])) {
      return;
    }

    // Loop through all defined fields and remove those starting by
    // 'attachments_' prefix.
    $fields = $this->query->getFields();
    if (!empty($fields)) {
      foreach ($fields as $key => $field_name) {
        $prefix = 'attachments_';
        if (strpos($field_name, $prefix) === 0) {
          unset($fields[$key]);
        }
      }
      $this->query->fields($fields);
    }
  }

}
