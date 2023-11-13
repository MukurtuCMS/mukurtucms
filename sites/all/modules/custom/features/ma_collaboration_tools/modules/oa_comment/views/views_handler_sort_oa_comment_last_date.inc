<?php

/**
 * @file
 * Definition of views_handler_sort_oa_comment_last_date.
 */

/**
 * Sort handler to sort by last commented date or post
 *
 * @ingroup views_sort_handlers
 */
class views_handler_sort_oa_comment_last_date extends views_handler_sort {

  /**
   * Called to add the sort to a query.
   */
  function query() {
    $this->ensure_my_table();
    $field = "$this->table_alias.$this->real_field";
    $node = $this->query->ensure_table('node');
    // Add the field.
    $params = $this->options['group_type'] != 'group' ? array('function' => $this->options['group_type']) : array();
    $this->query->add_orderby(NULL, "COALESCE($field, $node.changed)", $this->options['order'], $this->table_alias . '_' . $this->field, $params);
  }
}
