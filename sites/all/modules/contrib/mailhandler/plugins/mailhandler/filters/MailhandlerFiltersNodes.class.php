<?php
/**
 * @file
 * MailhandlerFiltersNodes class.
 */

/**
 * Filter to return nodes.
 */
class MailhandlerFiltersNodes extends MailhandlerFilters {
  /**
   * Whether or not to fetch message, based on headers.
   *
   * @param array $header
   *   Message headers
   *
   * @return bool
   *   TRUE if node, FALSE otherwise
   */
  public function fetch($header) {
    return !isset($header->in_reply_to);
  }
}
