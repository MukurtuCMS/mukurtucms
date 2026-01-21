<?php
/**
 * @file
 * Definition of MailhandlerCommands class.
 */

/**
 * Allows additional Feeds Processor sources to be mapped.
 *
 * When selected from the Mailhandler Parser, uses properties of a message to
 * set Feeds Processor sources. These sources can come from standard IMAP
 * headers / MIME parts, be "commanded" by key: value pairs in message bodies,
 * etc...
 */
abstract class MailhandlerCommands {

  protected $commands = NULL;

  /**
   * Parse commands from email body.
   *
   * @param array $message
   *   Array of message info including headers.
   */
  public function parse(&$message, $source, $client) {
  }

  /**
   * Process parsed commands by applying / manipulating the node object.
   *
   * @param object $message
   *   Array of message info including headers.
   */
  abstract public function process(&$message, $source);

  /**
   * Return mapping sources in the same manner as a Feeds Parser.
   *
   * @return array
   *   Array containing mapping sources in standard Feeds Parser format.
   */
  public function getMappingSources($config) {
    return array();
  }

  /**
   * Build configuration form.
   */
  public function configForm(&$form, &$form_state, $config) {
  }

  /**
   * Build source form.
   */
  public function sourceForm(&$form, $source_config) {
  }
}
