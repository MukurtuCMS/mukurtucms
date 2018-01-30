<?php
/**
 * @file
 * Views data definitions for Fasttoggle.
 *
 * This file defines how Views should get Fasttoggle data.
 */

/**
 * Implementation of hook_views_data_alter()
 */

function fasttoggle_user_views_data_alter(&$data) {

  $data['users']['fasttoggle_block_user'] = array(
      'field' => array(
        'title' => t('Block Link (Fasttoggle)'),
        'help' => t('Provide a simple link to block/unblock the user.'),
        'handler' => 'fasttoggle_user_views_handler_field_user_link',
        ),
      );
}

/**
 * Field handler to present a link toggle status.
 */
function fasttoggle_user_views_handlers() {
  return array(
      'info' => array(
        'path' => drupal_get_path('module', 'fasttoggle_user') . '/views',
        ),
      'handlers' => array(
        'fasttoggle_user_views_handler_field_user_link' => array(
          'parent' => 'views_handler_field_user_link',
          ),
        ),
      );
}
