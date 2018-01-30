<?php

/**
 * @file
 * Provides common routines and declarations for Fasttoggle.
 */

/**
 * Displays the current state of a setting (e.g. "published", "active").
 */
define('FASTTOGGLE_LABEL_STATUS', 0x0000);

/**
 * Displays the action that will be performed (e.g. "unpublish", "block").
 */
define('FASTTOGGLE_LABEL_ACTION', 0x0001);

/**
 * Read custom strings from settings.php
 */
define('FASTTOGGLE_LABEL_CUSTOM', 0x0002);

/**
 * Return a link in the resulting HTML format.
 */
define('FASTTOGGLE_FORMAT_HTML', 0x0000);

/**
 * Return a link as the structure passed to l().
 */
define('FASTTOGGLE_FORMAT_LINK_ARRAY', 0x0001);

/**
 * Return a link as the structure for a form build.
 */
define('FASTTOGGLE_FORMAT_FORM', 0x0002);
