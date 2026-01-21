<?php
/**
 * @file
 * MailhandlerFiltersComments class.
 */

/**
 * Filter to return comments.
 */
class MailhandlerFiltersComments extends MailhandlerFilters {
  /**
   * Whether or not to fetch message, based on headers.
   *
   * @param array $header
   *   Message headers
   *
   * @return bool
   *   TRUE if comment, FALSE otherwise
   */
  public function fetch($header) {
    return isset($header->in_reply_to);
  }
}
