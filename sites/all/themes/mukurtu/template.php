<?php

/**
 * @file
 * The primary PHP file for this theme.
 */


function mukurtu_preprocess_page(&$vars, $hook = null){
    if (isset($vars['node'])) {
        switch ($vars['node']->type) {
            case 'collection':
                drupal_add_js(drupal_get_path('theme', 'mukurtu') . '/js/collection-grid.js');
                break;
        }
    }
}