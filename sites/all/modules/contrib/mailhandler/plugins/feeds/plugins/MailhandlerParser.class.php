<?php
/**
 * @file
 * MailhandlerParser class.
 */

/**
 * Parses an IMAP stream.
 */
class MailhandlerParser extends FeedsParser {

  /**
   * Override parent::configDefaults().
   */
  public function configDefaults() {
    return array(
      'available_commands' => 'status',
      'authenticate_plugin' => 'MailhandlerAuthenticateDefault',
      'extended_headers' => NULL,
    );
  }

  /**
   * Define defaults.
   */
  public function sourceDefaults() {
    return array(
      'auth_required' => TRUE,
      'default_commands' => 'status: 1',
      'commands_failed_auth' => 'status: 0',
    );
  }

  /**
   * Implements sourceForm().
   */
  public function sourceForm($source_config) {
    $form['auth_required'] = array(
      '#type' => 'checkbox',
      '#title' => t('Skip messages that fail authentication'),
      '#default_value' => isset($source_config['auth_required']) ? $source_config['auth_required'] : '',
      '#description' => t('If checked, only messages that belong to an authenticated user will be imported.'),
    );
    $plugins = mailhandler_get_plugins('mailhandler', 'commands');
    foreach ($plugins as $plugin_name => $plugin) {
      if ($class = mailhandler_plugin_load_class('mailhandler', $plugin_name, 'commands', 'handler')) {
        $class->sourceForm($form, $source_config);
      }
    }
    return $form;
  }

  /**
   * Build configuration form.
   */
  public function configForm(&$form_state) {
    $form = array();
    ctools_include('plugins');
    $form['authenticate_plugin'] = array(
      '#type' => 'select',
      '#title' => t('Authentication plugin'),
      '#description' => t('Choose an authentication plugin'),
      '#options' => _mailhandler_build_options(mailhandler_get_plugins('mailhandler', 'authenticate')),
      '#default_value' => $this->config['authenticate_plugin'],
      '#required' => FALSE,
    );
    $plugins = mailhandler_get_plugins('mailhandler', 'commands');
    foreach ($plugins as $plugin_name => $plugin) {
      if ($class = mailhandler_plugin_load_class('mailhandler', $plugin_name, 'commands', 'handler')) {
        $class->configForm($form, $form_state, $this->config);
      }
    }
    return $form;
  }

  /**
   * Implementation of FeedsParser::parse().
   */
  public function parse(FeedsSource $source, FeedsFetcherResult $fetcher_result) {
    $fetched = $fetcher_result->getRaw();
    $mailbox = $fetched['mailbox'];
    $result = new FeedsParserResult();
    if (!empty($fetched['messages'])) {
      foreach ($fetched['messages'] as &$message) {
        $this->authenticate($message, $mailbox);
        if ($class = mailhandler_plugin_load_class('mailhandler', $mailbox->settings['retrieve'], 'retrieve', 'handler')) {
          $class->purge_message($mailbox, $message);
        }
        if ($message['authenticated_uid'] == 0) {
          // User was not authenticated.
          module_invoke_all('mailhandler_auth_failed', $message);
          $source_config = $source->getConfigFor($this);
          if ($source_config['auth_required']) {
            mailhandler_report('warning', 'User could not be authenticated. Please check your Mailhandler authentication plugin settings.');
            continue;
          }
        }
        $this->commands($message, $source);
        $result->items[] = $message;
      }
    }
    return $result;
  }

  /**
   * This defines sources which user's can select to map values to.
   */
  public function getMappingSources() {
    $sources = parent::getMappingSources();
    $sources['authenticated_uid'] = array(
      'name' => t('User ID'),
      'description' => t('The authenticated Drupal user ID'),
    );
    $plugins = mailhandler_get_plugins('mailhandler', 'commands');
    foreach ($plugins as $plugin_name => $plugin) {
      $plugin = mailhandler_plugin_load_class('mailhandler', $plugin_name, 'commands', 'handler');
      $sources = array_merge($sources, $plugin->getMappingSources($this->config));
    }
    return $sources;
  }

  /**
   * Parse and apply commands.
   */
  public function commands(&$message, $source) {
    $plugins = mailhandler_get_plugins('mailhandler', 'commands');
    foreach ($plugins as $plugin_name => $plugin) {
      if ($class = mailhandler_plugin_load_class('mailhandler', $plugin_name, 'commands', 'handler')) {
        $class->parse($message, $source, $this);
        $class->process($message, $source);
      }
    }
  }

  /**
   * Authenticate the message and set $message['authenticated_uid'].
   */
  public function authenticate(&$message, $mailbox) {
    if ($plugin = $this->config['authenticate_plugin']) {
      if ($class = mailhandler_plugin_load_class('mailhandler', $plugin, 'authenticate', 'handler')) {
        $message['authenticated_uid'] = $class->authenticate($message, $mailbox);
      }
    }
  }
}
