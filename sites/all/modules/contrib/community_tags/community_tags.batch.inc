<?php

/**
 * @file
 * community_tags.batch.inc
 *
 * Batch process functions.
 */

/**
 * Batch process for rebuilding missing tags from node terms.
 */
function community_tags_rebuild_tags_batch_process($vid, $content_type, $count, &$context) {
  if (!isset($context['sandbox']['progress'])) {
    $context['sandbox']['progress'] = 0;
    $context['sandbox']['current_node'] = 0;
    $context['sandbox']['max'] = $count;
  }

  // get all the next lot of nodes to update. Note the range starts at 0 because the processed ones don't get returned by the query. duh.
  // TODO Please convert this statement to the D7 database API syntax.
  $result = db_query_range("SELECT n.nid, n.uid, count(distinct tn.tid) missing_ctag_count, group_concat(tn.tid) tids
     FROM {taxonomy_index} tn
     INNER JOIN {taxonomy_term_data} td ON td.tid = tn.tid AND td.vid = :vid
     INNER JOIN {node} n ON n.nid = tn.nid AND n.type = :type
     LEFT JOIN {community_tags} ct ON ct.nid = tn.nid AND ct.tid = tn.tid
     WHERE ct.nid IS NULL
     GROUP BY n.nid", 0, 100, array(':vid' => $vid, ':type' => $content_type));

  $initial_progress = $context['sandbox']['progress'];

  foreach ($result as $row) {
    // get the tids from the query results
    $tids = explode(',', $row->tids);

    // add - uid is node author
    foreach ($tids as $tid) {
      _community_tags_add_tag($row->nid, $tid, $row->uid);
    }

    $context['sandbox']['progress'] += 1;
    $context['sandbox']['tag_count'] += $row->missing_ctag_count;
  }

  // Inform the batch engine that we are not finished,
  // and provide an estimation of the completion level we reached.
  // guard against not reaching the max!
  // nothing added - something changed whilst processing - finish early
  if ($context['sandbox']['progress'] != $context['sandbox']['max'] && $initial_progress != $context['sandbox']['progress']) {
    $context['finished'] = $context['sandbox']['progress'] / $context['sandbox']['max'];
  }
  else {
    $context['sandbox']['progress'] = $context['sandbox']['max'];
    $context['results'][] = t('Added %tag_count community tags to %node_count nodes.', array('%tag_count' => $context['sandbox']['tag_count'], '%node_count' => $context['sandbox']['progress']));
  }
}

/**
 * Batch process for rebuilding missing term nodes from community tags.
 */
function community_tags_rebuild_nodeterms_batch_process($vid, $content_type, $count, $mode, &$context) {
  if (!isset($context['sandbox']['progress'])) {
    $context['sandbox']['progress'] = 0;
    $context['sandbox']['current_node'] = 0;
    $context['sandbox']['max'] = $count;
  }

  // number of modes to process in single operation step depends on the mode. Term adding
  // takes much longer - so lower limit
  $limit = $mode == 1 ? 20 : 100;

  // get all the next lot of nodes to update. Note the range starts at 0 because the processed ones don't get returned by the query. duh.
  // TODO Please convert this statement to the D7 database API syntax.
  $result = db_query_range("SELECT n.nid, count(distinct ct.tid) missing_nodeterm_count, group_concat(distinct ct.tid) tids
     FROM {community_tags} ct
     INNER JOIN {taxonomy_term_data} td ON td.tid = ct.tid AND td.vid = :vid
     INNER JOIN {node} n ON n.nid = ct.nid AND n.type = :type
     LEFT JOIN {taxonomy_index} tn ON tn.nid = ct.nid AND tn.tid = ct.tid
     WHERE tn.nid IS NULL
     GROUP BY n.nid", 0, $limit, array(':vid' => $vid, ':type' => $content_type));

  $initial_progress = $context['sandbox']['progress'];

  foreach ($result as $row) {
    // get the tids from the query results
    $tids = explode(',', $row->tids);

    if ($mode == 1) {
      // load node but instruct not to put in static array
      $node = node_load($row->nid, NULL, TRUE);

      // add all these to the node
      foreach ($tids as $tid) {
        _community_tags_add_term_to_node($node, $tid, $vid);
      }

      // add save the node
      // prevent node update CT processing
      $node->ct_user_tags = array();
      node_save($node);
    }
    else {
      // delete community tags
      foreach ($tids as $tid) {
        _community_tags_delete_tags($row->nid, $tid);
        // this may create redundant terms
      }
    }

    $context['sandbox']['progress'] += 1;
    $context['sandbox']['nt_count'] += $row->missing_nodeterm_count;
  }

  // Inform the batch engine that we are not finished,
  // and provide an estimation of the completion level we reached.
  // guard against not reaching the max!
  // nothing added - something changed whilst processing - finish early
  if ($context['sandbox']['progress'] != $context['sandbox']['max'] && $initial_progress != $context['sandbox']['progress']) {
    $context['finished'] = $context['sandbox']['progress'] / $context['sandbox']['max'];
  }
  else {
    $context['sandbox']['progress'] = $context['sandbox']['max'];
    if ($mode == 1) {
      $context['results'][] = t('Added %nt_count terms to %node_count nodes.', array('%nt_count' => $context['sandbox']['nt_count'], '%node_count' => $context['sandbox']['progress']));
    }
    else {
      $context['results'][] = t('Deleted %nt_count community tags from %node_count nodes.', array('%nt_count' => $context['sandbox']['nt_count'], '%node_count' => $context['sandbox']['progress']));
    }
  }
}

/**
 * Batch process for deleting tags and optionally their corresponding node terms.
 */
function community_tags_delete_tags_batch_process($vid, $content_type, $counts, $mode, &$context) {
  if (!isset($context['sandbox']['progress'])) {
    $context['sandbox']['progress'] = 0;
    $context['sandbox']['current_node'] = 0;
    $context['sandbox']['max'] = $counts->node_count;
  }

  // get all the next lot of nodes to update. Note the range starts at 0 because the processed ones don't get returned by the query. duh.
  $result = db_query_range(
    "SELECT n.nid, n.uid, count(distinct ct.tid) term_count, group_concat(ct.tid) tids, count(*) tag_count
     FROM {community_tags} ct
     INNER JOIN {taxonomy_term_data} td ON td.tid = ct.tid AND td.vid = :vid
     INNER JOIN {node} n ON n.nid = ct.nid AND n.type = :type
     LEFT JOIN {taxonomy_index} tn ON tn.nid = ct.nid AND tn.tid = ct.tid
     GROUP BY n.nid", 0, 100, array(':vid' => $vid, ':type' => $content_type));

  $initial_progress = $context['sandbox']['progress'];


  foreach ($result as $row) {
    // get the tids from the query results
    $tids = explode(',', $row->tids);

    foreach ($tids as $tid) {
      // delete all user tags...
      // @todo - keep author tags - or tags by specfied roles?
      _community_tags_delete_tags($row->nid, $tid);
    }

    // if required remove terms from the node
    if ($mode & COMMUNITY_TAGS_OPMODE_SYNC) {
      $node = node_load($row->nid);

      if($nodeterm_count = _community_tags_remove_terms_from_node($node, $tids, $vid) > 0) {
        // node save required
        $node->ct_user_tags = array();
        node_save($node);
        $context['sandbox']['nodeterm_count'] += $nodeterm_count;
      }
      $node = node_load($row->nid, NULL, TRUE);
    }

    if ($mode & COMMUNITY_TAGS_OPMODE_DELETE_ORPHAN_TERMS) {
      $context['sandbox']['redundant_term_count'] += _community_tags_cleanup_orphaned_tags_by_tids($tids);
    }

    $context['sandbox']['progress'] += 1;
    $context['sandbox']['tag_count'] += $row->tag_count;
  }

  // Inform the batch engine that we are not finished,
  // and provide an estimation of the completion level we reached.
  // guard against not reaching the max!
  // nothing added - something changed whilst processing - finish early
  if ($context['sandbox']['progress'] != $context['sandbox']['max'] && $initial_progress != $context['sandbox']['progress']) {
    $context['finished'] = $context['sandbox']['progress'] / $context['sandbox']['max'];
  }
  else {
    $context['sandbox']['progress'] = $context['sandbox']['max'];
    $context['results'][] = t('Deleted %tag_count community tags from %node_count nodes.', array('%tag_count' => $context['sandbox']['tag_count'], '%node_count' => $context['sandbox']['progress']));
    if ($mode & COMMUNITY_TAGS_OPMODE_SYNC) {
      $context['results'][] = t('Deleted %nodeterm_count terms.', array('%nodeterm_count' => $context['sandbox']['nodeterm_count']));
    }
    if ($mode & COMMUNITY_TAGS_OPMODE_DELETE_ORPHAN_TERMS) {
      $context['results'][] = t('Deleted %term_count redundant terms.', array('%term_count' => $context['sandbox']['redundant_term_count']));
    }
  }
}

/**
 * Batch 'finished' callback
 */
function community_tags_batch_finished($success, $results, $operations) {
  if ($success) {
    // Here we do something meaningful with the results.
    $message = count($results) . ' processed.';
    $message .= theme('item_list', array('items' => $results));
  }
  else {
    // An error occurred.
    // $operations contains the operations that remained unprocessed.
    $error_operation = reset($operations);
    $message = t('An error occurred while processing %error_operation with arguments: @arguments', array('%error_operation' => $error_operation[0], '@arguments' => print_r($error_operation[1], TRUE)));
  }
  drupal_set_message($message);
}

