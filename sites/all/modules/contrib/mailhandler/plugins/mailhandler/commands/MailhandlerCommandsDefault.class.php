<?php
/**
 * @file
 * MailhandlerCommandsDefault class.
 */

/**
 * Provides default commands.
 */
class MailhandlerCommandsDefault extends MailhandlerCommands {

  /**
   * Parse commands from email body.
   *
   * @param array $message
   *   Message including body fields.
   * @param object $source
   *   Source config.
   */
  public function parse(&$message, $source, $client) {
    // Prepend the default commands.
    // User-added commands will override the default commands.
    $source_config = $source->getConfigFor($client);
    $authid = $message['authenticated_uid'];
    if ($source_config['default_commands']) {
      $message['body_text'] = trim($source_config['default_commands']) . "\n" . $message['body_text'];
    }
    $commands = $this->getCommands($message['body_text'], $client, $source, $authid);
    $this->commands = $commands;
    foreach ($commands as $key => $value) {
      $message['body_html'] = str_replace($key . ': ' . $value, '', $message['body_html']);
      $message['body_html'] = preg_replace('/<br[^>\r\n]*>/', '', $message['body_html'], 1);
    }
    if ($message['authenticated_uid'] == 0) {
      $commands = $this->getCommands($source_config['commands_failed_auth'], $client, $source, $authid);
      foreach ($commands as $key => $value) {
        if (isset($this->commands[$key])) {
          $this->commands[$key] = $value;
        }
      }
    }
  }

  /**
   * Parse and process commands.
   */
  public function process(&$message, $source) {
    if (!empty($this->commands)) {
      foreach ($this->commands as $key => $value) {
        if (drupal_substr($value, 0, 1) == '[' && drupal_substr($value, -1, 1) == ']') {
          // Strip brackets.
          $value = rtrim(ltrim($value, '['), ']');
          $value = explode(',', $value);
        }
        $key = str_replace(' ', '_', $key);
        if (!empty($key) && empty($message[$key])) {
          $message[$key] = $value;
        }
      }
    }
  }

  /**
   * Build configuration form.
   */
  public function configForm(&$form, &$form_state, $config) {
    $form['available_commands'] = array(
      '#type' => 'textarea',
      '#title' => t('Available commands'),
      '#description' => t('A set of commands that can be mapped to Feeds processor targets.'),
      '#default_value' => $config['available_commands'],
    );
  }

  /**
   * Build source form.
   */
  public function sourceForm(&$form, $source_config) {
    $form['default_commands'] = array(
      '#type' => 'textarea',
      '#title' => t('Default commands (authenticated users)'),
      '#description' => t('A set of commands that are added to each message by default, if the user is authenticated. Should be in the form "key: value".'),
      '#default_value' => isset($source_config['default_commands']) ? $source_config['default_commands'] : '',
    );
    $form['commands_failed_auth'] = array(
      '#type' => 'textarea',
      '#title' => t('Default commands (anonymous users)'),
      '#description' => t('A set of commands that are added to each message by default, if the user is not authenticated. Should be in the form "key: value".'),
      '#default_value' => isset($source_config['commands_failed_auth']) ? $source_config['commands_failed_auth'] : '',
    );
  }

  /**
   * Implements getMappingSources().
   */
  public function getMappingSources($config) {
    $sources = array();
    $sources['body_text'] = array(
      'name' => t('Body (Text)'),
      'description' => t('Plain-text message body. Will fall back to HTML body if necessary.'),
    );
    $sources['body_html'] = array(
      'name' => t('Body (HTML)'),
      'description' => t('HTML message body. Will fall back to text body if necessary.'),
    );
    $available_commands = explode("\n", $config['available_commands']);
    foreach ($available_commands as $command) {
      $command = trim($command);
      $sources[$command] = array(
        'name' => $command,
        'description' => $command . ' (commanded)',
      );
    }
    return $sources;
  }

  /**
   * Implements getCommands().
   */
  public function getCommands(&$string, $client = NULL, $source = NULL, $authid = NULL) {
    if ($source) {
      $config = $source->importer->getConfig();
    }
    if ($client) {
      $source_config = $source->getConfigFor($client);
    }
    $commands = array();
    $endcommands = NULL;
    // Collect the commands and locate signature.
    $lines = explode("\n", $string);
    foreach ($lines as $i => $line) {
      preg_match('/^([a-zA-Z0-9_-\s\.]+):{1}\s+(.+)$/', $line, $matches);
      if (count($matches) == 3) {
        $key = trim($matches[1]);
        $value = trim($matches[2]);
        if (isset($config)) {
          if (!(strpos($config['parser']['config']['available_commands'], $key) === FALSE)) {
            $commands[$key] = $value;
          }
        }
        elseif (isset($source_config)) {
          if (!(strpos($config['parser']['source_config']['commands_failed_auth'], $key) === FALSE)) {
            $commands[$key] = $value;
          }
        }
      }
      elseif (!empty($commands)) {
        $endcommands = count($commands);
        break;
      }
      elseif ($i == 0) {
        $endcommands = 0;
        break;
      }
    }
    $string = implode("\n", array_slice($lines, $endcommands));
    return $commands;
  }

}
