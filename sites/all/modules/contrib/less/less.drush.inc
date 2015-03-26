<?php

function less_drush_cache_clear(&$types) {
  $types['less'] = '_less_drush_cache_clear';
}

function _less_drush_cache_clear() {
  _less_new_dir();
  less_cron();
}
