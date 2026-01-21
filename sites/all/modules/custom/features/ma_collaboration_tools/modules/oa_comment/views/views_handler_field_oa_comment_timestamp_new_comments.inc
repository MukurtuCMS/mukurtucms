<?php

/**
 * @file
 * Definition of views_handler_field_oa_comment_timestamp_new_comments.
 */

/**
 * Filter to show how many new comments on a post since user last visited it.
 */
class views_handler_field_oa_comment_timestamp_new_comments extends views_handler_field_numeric {

  function query() {
    $limit = time() - (REQUEST_TIME - NODE_NEW_LIMIT);

    $this->ensure_my_table();
    $field = "$this->table_alias.$this->real_field";
    $node = $this->query->ensure_table('node', $this->relationship);
    $comment = $this->query->ensure_table('comment', 'comment_node');

    $params = $this->options['group_type'] != 'group' ? array('function' => $this->options['group_type']) : array();
    $this->field_alias = $this->query->add_field(NULL, "CASE WHEN (($field IS NULL or $comment.created > $field) AND $comment.status = 1)  THEN 1 ELSE 0 END", $this->table . '_' . $this->field, $params);
  }
}
