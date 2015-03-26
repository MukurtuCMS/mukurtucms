<?php

/**
 * @file
 * Scald Constants
 *
 * Rarely-configured constants used for defining various elements of Scald.
 *
 * @ingroup scald
 */


define('SCALD_SLUG_MAX_LENGTH', 128);
define('SCALD_SLUG_MATCH_PATTERN', '/^[\w-]+$/');

/**
 * Defines the maximum power assignable to an action.
 *
 * There are dozens of issues with integer values and variables in PHP.  All
 * integer values are unsigned and so the highest bit which is truly safe to
 * use in the way that Scald does is the 31st bit.
 *
 * This is the max power which can live in the db.
 *
 * This constants limits the number of actions that can be defined at the
 * same time in any given site.
 */
define('SCALD_ACTIONS_MAX_POWER', 30);

/**
 * Defines the regexp pattern for SAS format.
 *
 * The full SAS format is literally:
 *
 *   [scald=ATOM_ID:context options]
 *
 * where 'context' is the context name and 'options' is JSON representation of
 * options used to render the atom.
 *
 * Examples of SAS formats:
 *
 * [scald=23]
 *   atom with ID=23 in the 'title' (default) context
 * [scald=23:full]
 *   atom with ID=23 in the 'full' context
 * [scald=23:full {"link":"http://www.google.com"}]
 */
define('SCALD_SAS_MATCH_PATTERN', '/\[\s*scald=(\d+)(?(?=:):([\w-]+))(?(?=\s+)\s+([^\]]*))\s*\]/');

define('SCALD_RENDERED_MATCH_PATTERN', '/<!--\s*scald=(\d+)(?(?=:):([\w-]+))(?(?=\s+)\s+([^\]]*))\s*-->.*<!--\s*END scald=\1\s*-->/sU');

// How many users to load and save at a time in order to rebuild Actions
// bitstrings.
define('SCALD_ADMIN_ACTIONS_BATCH_LIMIT', 1);

// How many users to register as Authors at a time during hook_enable().
define('SCALD_ENABLE_BATCH_LIMIT', 100);

/**
 * Modules should return this value from hook_scald_atom_access() to allow
 * access to an atom.
 */
define('SCALD_ATOM_ACCESS_ALLOW', TRUE);

/**
 * Modules should return this value from hook_scald_atom_access() to deny access
 * to an atom.
 */
define('SCALD_ATOM_ACCESS_DENY', FALSE);

/**
 * Modules should return this value from hook_scald_atom_access() to not affect
 * atom access.
 */
define('SCALD_ATOM_ACCESS_IGNORE', NULL);

