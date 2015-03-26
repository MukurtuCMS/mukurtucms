<?php

/**
 * Implements hook_views_data().
 */
function entity_delete_log_og_views_data() {
  $table = array(
    'entity_delete_log_og' => array(
      'table' => array(
        'group' => 'Entity Delete Log Organic Groups',
        'base' => array(
          'field' => 'entity_delete_log_og_id',
          'title' => t('Entity Delete Log Organic Groups'),
          'help' => t('The Entity Delete Log Organic Groups Table'),
        ),
      ),
      'entity_delete_log_og_id' => array(
        'title' => t('Entity Delete Log OG ID'),
        'help' => t('The Entity Delete Log OG ID'),
        'field' => array(
          'handler' => 'views_handler_field_numeric',
          'click sortable' => TRUE,
        ),
      ),
      'entity_delete_log_id' => array(
        'title' => t('Entity Delete Log ID'),
        'help' => t('The Entity Delete Log ID'),
        'field' => array(
          'handler' => 'views_handler_field_numeric',
          'click sortable' => TRUE,
        ),
        'relationship' => array(
          'title' => t('Entity Delete Log'),
          'help' => t('The Entity Delete Log related to this OG log'),
          'base' => 'entity_delete_log',
          'base_field' => 'entity_delete_log_id',
          'handler' => 'views_handler_relationship',
          'label' => t('Entity Delete Log'),
        ),
      ),
      'gid' => array(
        'title' => t('OG Group ID'),
        'help' => t('The OG Group ID'),
        'field' => array(
          'handler' => 'views_handler_field_numeric',
          'click sortable' => TRUE,
        ),
        'relationship' => array(
          'title' => t('Organic Group'),
          'help' => t('The Organic Group related to the entity delete log'),
          'base' => 'og',
          'base_field' => 'gid',
          'handler' => 'views_handler_relationship',
          'label' => t('Organic Group'),
        ),
      ),
    ),
  );
  return $table;
}

