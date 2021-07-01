<?php

/**
 * @file
 * Definition of views_handler_field_oa_comment_last_date.
 */

/**
 * Returns the last date either of node changed or comment changed.
 */
class views_handler_field_oa_comment_last_date extends oa_date_handler_field_date {

  function query() {
    $this->ensure_my_table();
    $field = "$this->table_alias.$this->real_field";
    $node = $this->query->ensure_table('node');

    $params = $this->options['group_type'] != 'group' ? array('function' => $this->options['group_type']) : array();
    $this->field_alias = $this->query->add_field(NULL, "COALESCE($field, $node.changed)", $this->table . '_' . $this->field, $params);
  }
}
