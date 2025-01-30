<?php
/**
 * @file
 * MailhandlerCommandsExtendedHeaders class.
 */

/**
 * Provides extended headers from messages.
 */
class MailhandlerCommandsExtendedHeaders extends MailhandlerCommandsHeaders {

  /**
   * Build configuration form.
   */
  public function configForm(&$form, &$form_state, $config) {
    $form['extended_headers'] = array(
      '#type' => 'textarea',
      '#title' => t('Extended headers'),
      '#description' => t('Additional headers that can be mapped to Feeds processor targets.'),
      '#default_value' => $config['extended_headers'],
    );
  }

  /**
   * Implements getMappingSources().
   */
  public function getMappingSources($config) {
    $sources = array();
    $extended_headers = explode("\n", $config['extended_headers']);
    foreach ($extended_headers as $header) {
      $header = trim($header);
      $sources[$header] = array(
        'name' => $header,
        'description' => $header . ' (extended header)',
      );
    }
    return $sources;
  }

}
