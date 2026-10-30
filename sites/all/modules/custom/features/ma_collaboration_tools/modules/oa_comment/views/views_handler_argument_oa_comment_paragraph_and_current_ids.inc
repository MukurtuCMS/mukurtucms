<?php

/**
 * @file
 * Definition of views_handler_argument_numeric.
 */

/**
 * Contextural filter for Open Atrium Parent ID
 */
class views_handler_argument_oa_comment_paragraph_and_current_ids extends views_handler_argument_numeric {
  var $no_operator = TRUE;

  function query($group_by = FALSE) {
    $table = $this->ensure_my_table();
    // Determine parent of the node argument if any
    $this->query->set_where_group('OR', 'paragraph_and_current_ids');
    $this->query->add_where_expression('paragraph_and_current_ids', "$table.type = 'node' AND id = {$this->argument}");
    if ($ids = oa_comment_find_paragraph_ids($this->argument)) {
      foreach ($ids as $key => $pids) {
        foreach ($pids as $id) {
          $this->query->add_where_expression('paragraph_and_current_ids', "$table.type = 'paragraphs_item' AND id = $id");
        }
      }
    }
  }
}
