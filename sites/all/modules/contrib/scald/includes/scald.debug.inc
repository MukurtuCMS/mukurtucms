<?php

/**
 * @file
 * Scald Debugging
 *
 * The Scald Core "Debugging Console" and other debugging functionality
 *
 * @ingroup scald
 */

require_once 'scald.constants.inc';

/**
 * Callback for Scald Debugging Console.
 *
 * @param int $sid
 *   The Scald ID of the Atom to load into the debugging console
 *
 * @return string
 *   XHTML for the Console page
 */
function scald_debug_console($sid) {
  return scald_render($sid, 'debug', NULL, TRUE);
}
