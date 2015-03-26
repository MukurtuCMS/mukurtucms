<?php

/**
 * Implements hook_views_data().
 */
function entity_delete_log_views_data() {
  $table = array(
    'entity_delete_log' => array(
      'table' => array(
        'group' => 'Entity Delete Log',
        'base' => array(
          'field' => 'entity_delete_log_id',
          'title' => t('Entity Delete Log'),
          'help' => t('The Entity Delete Log Table'),
        ),
      ),
      'entity_delete_log_id' => array(
        'title' => t('Entity Delete Log ID'),
        'help' => t('The Entity Delete Log ID'),
        'field' => array(
          'handler' => 'views_handler_field_numeric',
          'click sortable' => TRUE,
        ),
      ),
      'entity_id' => array(
        'title' => t('Entity ID'),
        'help' => t('The Entity ID'),
        'field' => array(
          'handler' => 'views_handler_field_numeric',
          'click sortable' => TRUE,
        ),
      ),
      'entity_type' => array(
        'title' => t('Entity Type'),
        'help' => t('The Entity Type'),
        'field' => array(
          'handler' => 'views_handler_field',
          'click sortable' => TRUE,
        ),
        'filter' => array(
          'handler' => 'views_handler_filter_string',
        ),
        'sort' => array(
          'handler' => 'views_handler_sort',
        ),
      ),
      'entity_bundle' => array(
        'title' => t('Entity Bundle'),
        'help' => t('The Entity Bundle'),
        'field' => array(
          'handler' => 'views_handler_field',
          'click sortable' => TRUE,
        ),
        'filter' => array(
          'handler' => 'views_handler_filter_string',
        ),
        'sort' => array(
          'handler' => 'views_handler_sort',
        ),
      ),
      'entity_title' => array(
        'title' => t('Entity Title'),
        'help' => t('The Entity Title'),
        'field' => array(
          'handler' => 'views_handler_field',
          'click sortable' => TRUE,
        ),
        'filter' => array(
          'handler' => 'views_handler_filter_string',
        ),
        'sort' => array(
          'handler' => 'views_handler_sort',
        ),
      ),
      'author' => array(
        'title' => t('Author'),
        'help' => t("The User ID of the entity's author"),
        'field' => array(
          'handler' => 'views_handler_field_user',
          'click sortable' => TRUE,
        ),
        'relationship' => array(
          'title' => t('Author User Account'),
          'help' => t('The user account for the entity author'),
          'base' => 'users',
          'base_field' => 'uid',
          'handler' => 'views_handler_relationship',
          'label' => t('Author User Account'),
        ),
        'filter' => array(
          'handler' => 'views_handler_filter_user',
        ),
        'sort' => array(
          'handler' => 'views_handler_sort',
        ),
      ),
      'revisions' => array(
        'title' => t('Revisions'),
        'help' => t('The number of revisions for the entity'),
        'field' => array(
          'handler' => 'views_handler_field_numeric',
          'click sortable' => TRUE,
        ),
        'filter' => array(
          'handler' => 'views_handler_filter_numeric',
        ),
        'sort' => array(
          'handler' => 'views_handler_sort',
        ),
      ),
      'created' => array(
        'title' => t('Created'),
        'help' => t('The entity creation date'),
        'field' => array(
          'handler' => 'views_handler_field_date',
          'click sortable' => TRUE,
        ),
        'filter' => array(
          'handler' => 'views_handler_filter_date',
        ),
        'sort' => array(
          'handler' => 'views_handler_sort',
        ),
      ),
      'deleted' => array(
        'title' => t('Deleted'),
        'help' => t('The entity deletion date'),
        'field' => array(
          'handler' => 'views_handler_field_date',
          'click sortable' => TRUE,
        ),
        'filter' => array(
          'handler' => 'views_handler_filter_date',
        ),
        'sort' => array(
          'handler' => 'views_handler_sort',
        ),
      ),
      'uid' => array(
        'title' => t('User ID'),
        'help' => t('The user ID of the account that deleted the entity'),
        'field' => array(
          'handler' => 'views_handler_field_user',
          'click sortable' => TRUE,
        ),
        'relationship' => array(
          'title' => t('Acting User Account'),
          'help' => t('The user account who deleted the entity'),
          'base' => 'users',
          'base_field' => 'uid',
          'handler' => 'views_handler_relationship',
          'label' => t('Acting User Account'),
        ),
        'filter' => array(
          'handler' => 'views_handler_filter_user',
        ),
        'sort' => array(
          'handler' => 'views_handler_sort',
        ),
      ),
    ),
  );
  return $table;
}

