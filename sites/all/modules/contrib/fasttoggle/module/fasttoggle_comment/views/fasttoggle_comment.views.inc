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

function fasttoggle_comment_views_data_alter(&$data) {

  $data['comment']['fasttoggle_status'] = array(
      'field' => array(
        'title' => t('Approve link (Fasttoggle)'),
        'help' => t('Provide a simple link to toggle approval of a comment.'),
        'handler' => 'fasttoggle_comment_views_handler_field_comment_link',
        ),
      );
}

/**
 * Field handler to present a link toggle status.
 */
function fasttoggle_comment_views_handlers() {
  return array(
      'info' => array(
        'path' => drupal_get_path('module', 'fasttoggle_comment') . '/views',
        ),
      'handlers' => array(
        'fasttoggle_comment_views_handler_field_comment_link' => array(
          'parent' => 'views_handler_field_comment_link',
          ),
        ),
      );
}
