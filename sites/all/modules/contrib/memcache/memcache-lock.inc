<?php

/**
 * @file
 * A memcache based implementation of a locking mechanism.
 * See includes/lock.inc for documenation
 */

require_once dirname(__FILE__) . '/dmemcache.inc';

// Check if memcached is available - if not include default lock handler.
// @todo get rid of this conditional include as soon as this is done:
// http://drupal.org/node/1225404
$lock_file = dirname(__FILE__) . '/memcache-lock-code.inc';
$mc = dmemcache_object('semaphore');
// dmemcache_object may return FALSE, we don't need these stats but it forces
// us to try and connect to memcache. If this fails, we can't store locks in
// memcache.
$connection_okay = $mc && !empty($mc->getStats());

// Reset the server list and try the getStats() call again.
if (!$connection_okay && $mc && _dmemcache_reset_ascii_auth($mc)) {
  $connection_okay = !empty($mc->getStats());
}

if (!$connection_okay) {
  $lock_file = DRUPAL_ROOT . '/includes/lock.inc';
}
require_once $lock_file;
