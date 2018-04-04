<?php
/**
 * @file
 * Code for the views integration of OpenAtrium comments.
 */

/**
 * Implements hook_views_data().
 *
 * Define a custom views contextual filter for Parent node.
 */
function oa_comment_views_data() {
  $data = array();

  $data['comment']['last_date'] = array(
    'title' => t('Last updated date'),
    'help' => t('Child updated date, or parent updated date'),
    'real field' => 'changed',
    'field' => array(
      'handler' => 'views_handler_field_oa_comment_last_date',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_oa_comment_last_date',
    ),
  );

  $data['history']['timestamp_new_comments'] = array(
    'title' => t('New Comments'),
    'real field' => 'timestamp',
    'field' => array(
      'help' => t('Is this comment new? (0/1)'),
      'handler' => 'views_handler_field_oa_comment_timestamp_new_comments',
    ),
  );

  $data['history']['timestamp_updated_comments'] = array(
    'title' => t('Updated Comments'),
    'real field' => 'timestamp',
    'field' => array(
      'help' => t('Is this comment updated? (0/1)'),
      'handler' => 'views_handler_field_oa_comment_timestamp_updated_comments',
    ),
  );

  $data['file_usage']['paragraph_and_current_ids'] = array(
    'title' => t('All IDs in usage with this content'),
    'help' => t('Takes an an argument node ID and changes it tll all IDs (node nid, paragraph IDs, etc.) in usage.'),
    'real field' => 'id',
    'argument' => array(
      'handler' => 'views_handler_argument_oa_comment_paragraph_and_current_ids',
    ),
  );


  return $data;
}
