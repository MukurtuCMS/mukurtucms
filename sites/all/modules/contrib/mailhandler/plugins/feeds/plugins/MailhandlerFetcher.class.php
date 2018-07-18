<?php

/**
 * @file
 * Checks for new messages in a mailbox (IMAP, POP3, etc...).
 */

/**
 * Definition of the import batch object needed by MailhandlerFetcher.
 */
class MailhandlerFetcherResult extends FeedsFetcherResult {
  protected $mailbox_name;
  protected $filter;

  /**
   * Constructor.
   */
  public function __construct($mailbox_name, $filter) {
    parent::__construct('');
    $this->mailbox_name = $mailbox_name;
    $this->filter = $filter;
  }

  /**
   * Implementation of FeedsImportBatch::getRaw();
   */
  public function getRaw() {
    $mailbox = mailhandler_mailbox_load($this->mailbox_name);
    if ($class = mailhandler_plugin_load_class('mailhandler', $mailbox->settings['retrieve'], 'retrieve', 'handler')) {
      if ($messages = $class->retrieve($mailbox, $this->filter)) {
        return array('messages' => $messages, 'mailbox' => $mailbox);
      }
    }
  }
}

/**
 * Implementation of FeedsFetcher.
 */
class MailhandlerFetcher extends FeedsFetcher {

  /**
   * Implementation of FeedsFetcher::fetch().
   */
  public function fetch(FeedsSource $source) {
    $source_config = $source->getConfigFor($this);
    return new MailhandlerFetcherResult($source_config['source'], $this->config['filter']);
  }

  /**
   * Source form.
   */
  public function sourceForm($source_config) {
    $form = array();
    $form['source'] = array(
      '#type' => 'select',
      '#title' => t('Mailbox'),
      '#description' => t('Select a mailbox to use'),
      '#default_value' => isset($source_config['source']) ? $source_config['source'] : '',
      '#options' => _mailhandler_build_options(mailhandler_mailbox_load_all(FALSE), 'admin_title'),
    );
    return $form;
  }

  /**
   * Define defaults.
   */
  public function sourceDefaults() {
    return array(
      'source' => '',
    );
  }

  /**
   * Override parent::configDefaults().
   */
  public function configDefaults() {
    return array(
      'filter' => 'MailhandlerFilters',
    );
  }

  /**
   * Config form.
   */
  public function configForm(&$form_state) {
    $form = array();
    // Select message filter (to differentiate nodes/comments/etc)
    $form['filter'] = array(
      '#type' => 'select',
      '#title' => t('Message filter'),
      '#description' => t('Select which types of messages to import. This is a heuristic filter, and may fail in some scenarios. For instance, messages from a mailing list will almost always look like comments. Thus, the safest setting is <em>all</em>.'),
      '#default_value' => $this->config['filter'],
      '#options' => _mailhandler_build_options(mailhandler_get_plugins('mailhandler', 'filters')),
    );
    return $form;
  }

}
