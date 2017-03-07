<?php

/**
 * Define homebox pages in code.
 *
 * The menu might need to be rebuilt / cache cleared in order for pages in code
 * to show on the Homebox admin page and become accessible via the specified
 * path.
 *
 * Once an admin saves settings for a page in code, it resides in the database,
 * and the code is no longer read, until it's reverted/deleted.
 *
 * @return
 *   An array of homebox page settings arrays. The machine name is specified in
 *   the array key. The machine name and path MUST not be in use. Both name and
 *   path registered by first-come
 */
function hook_homebox() {
  $pages = array();

  $pages['testbox'] = array(// Keyed with the unique machine-name
    'title' => 'Test Homebox', // The title of the Homebox page
    'path' => 'testbox', // The path of the Homebox (URL)
    'menu' => 1, // Add a menu entry for this page (Navigation)
    'enabled' => 1, // Enable or disable the page. Only admins can view disabled
    'regions' => 3, // How many regions to create (1-9)
    'cache' => 0, // Use the block cache, when available
    'full' => 0, // Disable theme regions so page can go full-width
    'custom' => 1, // Allow users to add custom items to the page
    'roles' => array(// Which roles can view the page. If none specified, no one can view
      0 => 'authenticated user',
    ),
    'color' => 1, // Allow users to change the color of blocks
    'colors' => array(// Which colors are available (Must be 6 options)
      0 => '#e4f0f8',
      1 => '#c4d5b4',
      2 => '#ecc189',
      3 => '#ec8989',
      4 => '#6b6b70',
      5 => '#4b97e5',
    ),
    'widths' => array(// (Optional) The width percentage of each region
      1 => 25,
      2 => 50,
      3 => 25,
    ),
    'blocks' => array(// The available blocks on the page
      'node_recent' => array(// The block key; Format = module_delta
        'module' => 'node', // The module this block belongs to
        'delta' => 'recent', // The block delta
        'region' => 2, // Which region to place this block in
        'movable' => 1, // Can this block be dragged?
        'status' => 1, // Is this block visible by default (if not, it can be toggled)?
        'open' => 1, // Is this block expanded by default?
        'closable' => 1, // Can users close this block?
        'title' => '', // Blank if default block title should be used, if not, use a custom one
        'weight' => -8, // The weight of the block (lower numbers raise to the top)
      ),
      'user_new' => array(
        'module' => 'user',
        'delta' => 'new', // Who's New block.
        'region' => 1,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 1,
        'title' => '',
        'weight' => -7,
      ),
      'user_online' => array(
        'module' => 'user',
        'delta' => 'online', // Who's Online block.
        'region' => 3,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 1,
        'title' => '',
        'weight' => -7,
      ),
      'system_powered_by' => array(
        'module' => 'system',
        'delta' => 'powered-by', // Powered By block.
        'region' => 2,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 1,
        'title' => '',
        'weight' => -7,
      ),
    ),
  );

  return $pages;
}
