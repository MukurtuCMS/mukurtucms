<?php

/**
 * @file
 * community_tags.admin.inc
 *
 * Admin forms and supporting functions.
 */

/**
 * Form builder; Builds the settings form.
 *
 * @ingroup forms
 */
function community_tags_settings($form, &$form_state) {
  $form = array();

  // community_tags_rehash();
  if ($broken = _community_tags_get_count_of_broken_tags()) {
    drupal_set_message(t('There are @count broken community tags that reference missing terms, nodes, or users. Click <a href="@url">here</a> to delete them.', array('@count' => $broken, '@url' => url('admin/config/content/community-tags/ops/broken'))), 'warning');
  }

  // Build list of available free-tagging vocabularies
  $vocabularies = _community_tags_get_settings();

  // stat query for all ctags even for invalid combos - e.g. unassigned content type
  $counts = _community_tags_get_tag_counts_by_type_and_vocabulary();

  // put tag counts into vocabularies array. If a new type is found for a vocabulary
  // then tags are left over from a previous configuration - i.e. content type was assigned for tagging but now is not.
  foreach ($counts as $vid => $counts_by_type) {
    foreach ($counts_by_type as $type => $count) {
      if (!isset($vocabularies[$vid]['types'][$type])) {
        $content_type = node_type_get_type($type);
        $vocabularies[$vid]['types'][$type] = array(
          'type_name' => $content_type->name,
          'tag_count' => $count->tag_count,
          'assigned' => FALSE,
        );
      }
      else {
        $vocabularies[$vid]['types'][$type]['tag_count'] = $count->tag_count;
      }
    }
  }

  $missing_tag_counts = _community_tags_get_all_out_of_sync_missing_tag_counts();
  $missing_termnode_counts = _community_tags_get_all_out_of_sync_missing_node_terms_counts();

  foreach ($vocabularies as $vid => $vocabulary) {
    foreach ($vocabulary['types'] as $type => $type_settings) {
      $vocabularies[$vid]['types'][$type]['missing_tag_count'] = !empty($missing_tag_counts[$vid][$type]) ? $missing_tag_counts[$vid][$type] : 0;
      $vocabularies[$vid]['types'][$type]['missing_termnode_count'] = !empty($missing_termnode_counts[$vid][$type]) ? $missing_termnode_counts[$vid][$type] : 0;
    }
  }

  $form['#theme'] = 'community_tags_settings';

  $form['community_tags_settings'] = array(
    '#title' => t('Community tags vocabulary settings'),
    '#tree' => TRUE,
    '#type' => 'fieldset',
  );

  $display_handler_options = _community_tags_get_display_handler_options();

  foreach ($vocabularies as $vid => $vocabulary) {
    $form['community_tags_settings'][$vid] = array(
      '#title' => l($vocabulary['name'], 'admin/structure/taxonomy/' . $vocabulary['machine_name'], array('query' => drupal_get_destination())),
      '#type' => 'fieldset',
      '#tree' => TRUE,
    );
    // $form['community_tags_settings'][$vid]['tagging'] = array(
    //   '#title' => t('Free-tagging'),
    //   '#type' => 'item',
    //   '#value' => $vocabulary['tagging'] ? t('yes') : t('no'),
    // );
    $form['community_tags_settings'][$vid]['is_enabled'] = array(
      '#title' => t('Enable community tagging'),
      '#type' => 'checkbox',
      '#default_value' => $vocabulary['CT_enabled'],
    );
    $form['community_tags_settings'][$vid]['types'] = array(
      '#title' => t('Content type settings'),
      // '#tree' => count($vocabulary['types']) > 0 ? TRUE : FALSE,
      '#tree' => TRUE,
      '#type' => 'item',
    );
    foreach ($vocabulary['types'] as $type_id => $type) {
      $is_valid_CT_vocabulary_and_type = $type['assigned'] && $vocabulary['tagging'] && $vocabulary['CT_enabled'];

      $type_title = l($type['type_name'], 'admin/structure/types/manage/' . $type_id, array('query' => drupal_get_destination()));
      $type_description = t('Content types marked with an asterisk (*) indicate that the type is not enabled for the vocabulary but community tags exist from a previous configuration.');

      if (!$type['assigned']) {
        $type_title .= '*';
      }

      $form['community_tags_settings'][$vid]['types'][$type_id] = array(
        '#title' => $type_title,
        '#type' => 'fieldset',
        '#tree' => TRUE,
        '#description' => $type_description,
      );
      $form['community_tags_settings'][$vid]['types'][$type_id]['is_valid'] = array(
        '#type' => 'value',
        '#value' => $is_valid_CT_vocabulary_and_type,
      );
      // $form['community_tags_settings'][$vid]['types'][$type_id]['assigned'] = array(
      //   '#title' => t('Assigned'),
      //   '#type' => 'checkbox',
      //   '#disabled' => TRUE,
      //   '#default_value' => $type['assigned'],
      // );
      $form['community_tags_settings'][$vid]['types'][$type_id]['display_handler'] = array(
        '#title' => t('Display'),
        '#type' => $is_valid_CT_vocabulary_and_type ? 'select' : 'hidden',
        '#default_value' => isset($display_handler_options[$type['display_handler']]) ? $type['display_handler'] : 'links',
        '#options' => $display_handler_options,
      );
      $form['community_tags_settings'][$vid]['types'][$type_id]['synchronised'] = array(
        '#title' => t('Sync Nodes'),
        '#type' => $is_valid_CT_vocabulary_and_type ? 'checkbox' : 'hidden',
        '#default_value' => $type['opmode'] & COMMUNITY_TAGS_OPMODE_SYNC,
        '#description' => t('Sync Nodes: When a community tag is added or removed, the term will be added to or removed from the node respectively if this option is set.'),
      );
      $form['community_tags_settings'][$vid]['types'][$type_id]['redundant_terms'] = array(
        '#title' => t('Sync Terms'),
        '#type' => $is_valid_CT_vocabulary_and_type ? 'checkbox' : 'hidden',
        '#default_value' => ($type['opmode'] & COMMUNITY_TAGS_OPMODE_DELETE_ORPHAN_TERMS) > 0 ? TRUE : FALSE,
        '#description' => t('Sync Terms: When a community tag is removed and the term referenced by it is no longer used, then the term is deleted if this option is set.'),
      );
      $form['community_tags_settings'][$vid]['types'][$type_id]['tag_count'] = array(
        '#title' => t('Tag count'),
        '#type' => 'item',
        '#markup' => isset($type['tag_count']) ? $type['tag_count'] : 0,
      );

      $operations = array();
      if ($is_valid_CT_vocabulary_and_type) {
        // operations for valid enabled CT vocabulary content type combinations
        // add in deleted orphaned terms - need to encapsulate all this
        if (is_object($type['missing_tag_count']) && $type['missing_tag_count']->missing_ctag_count > 0
           || ($type['opmode'] & COMMUNITY_TAGS_OPMODE_SYNC && is_object($type['missing_termnode_count']) && $type['missing_termnode_count']->missing_termnode_count > 0)
           || FALSE) {
          $operations[] = array(
            'title' => t('rebuild'),
            'href' => "admin/config/content/community-tags/ops/rebuild/$vid/$type_id",
            'query' => drupal_get_destination(),
          );
        }
      }
      if (isset($type['tag_count']) && $type['tag_count'] > 0) {
        // operations for any CT vocabulary that has tags
        $operations[] = array(
          'title' => t('purge'),
          'href' => "admin/config/content/community-tags/ops/purge/$vid/$type_id",
          'query' => drupal_get_destination(),
        );
      }

      $form['community_tags_settings'][$vid]['types'][$type_id]['ops'] = array(
        '#title' => t('Operations'),
        '#markup' => !empty($operations) ? theme('links', array('links' => $operations, 'attributes' => array('class' => 'links inline'))) : '',
        '#type' => 'item',
      );
    }
  }

  $form['buttons']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save configuration'),
  );

  return $form;
}

/**
 * Submit handler for community tags settings form.
 * @todo add configuration settings
 */
function community_tags_settings_submit($form, &$form_state) {
  // reconstruct settings variable from nested form
  if (!empty($form_state['values']['community_tags_settings'])) {
    $vocabularies = taxonomy_get_vocabularies();
    $ct_enabled_vocabularies = array();
    foreach ($form_state['values']['community_tags_settings'] as $vid => $settings) {
      if ($settings['is_enabled']) {
        foreach ($settings['types'] as &$type_settings) {
          $type_settings['opmode'] = 0x00;
          $type_settings['opmode'] |= $type_settings['synchronised'] ? COMMUNITY_TAGS_OPMODE_SYNC : 0x00;
          $type_settings['opmode'] |= $type_settings['redundant_terms'] ? COMMUNITY_TAGS_OPMODE_DELETE_ORPHAN_TERMS : 0x00;
          unset($type_settings['synchronised']);
          unset($type_settings['redundant_terms']);
        }
        // store by machine name
        $vname = $vocabularies[$vid]->machine_name;
        $ct_enabled_vocabularies[$vname] = $settings;

      }
    }
    variable_set('community_tags_vocabularies', $ct_enabled_vocabularies);
  }
}


/**
 * Theme function for presets form element - display in table.
 */
function theme_community_tags_settings($variables) {
  $form = $variables['element'];
  $rows = array();
  $elements = element_children($form['community_tags_settings']);
  // $first = $form[reset($form)];

  $notes = array();
  $header_rows = array();
  $rows = array();


  $first_row = TRUE;
  $first_type_row = TRUE;
  $vocab_index = 0;
  $type_column_count = 1;
  foreach ($elements as $key) {

    // content types enabled for this vocabulary - may not be any
    $type_elements = element_children($form['community_tags_settings'][$key]['types']);
    $content_type_count = count($type_elements);
    $rowspan = $content_type_count == 0 ? 1 : $content_type_count;

    // First column 'taxonomy_vocabulary' - if first pass rocess header - get description if any
    $row_data = array();
    $row_data[] = array(
      'data' => $form['community_tags_settings'][$key]['#title'],
      'rowspan' => $rowspan,
    );
    if ($first_row) {
      $header_rows[0][] = array('data' => t('Vocabulary'));
      if (!empty($form['community_tags_settings'][$key]['#description'])) {
        $notes[] = $form['community_tags_settings'][$key]['#description'];
      }
    }

    // Vocabulary level columns - if first pass process header - get descriptions if any
    $vocab_elements = element_children($form['community_tags_settings'][$key]);
    foreach ($vocab_elements as $vocab_key) {
      if ($vocab_key != 'types') {

        if ($first_row) {
          $header_rows[0][] = array('data' => $form['community_tags_settings'][$key][$vocab_key]['#title']);

          if (!empty($form['community_tags_settings'][$key][$vocab_key]['#description'])) {
            $notes[] = $form['community_tags_settings'][$key][$vocab_key]['#description'];
          }
        }

        unset($form['community_tags_settings'][$key][$vocab_key]['#description']);
        unset($form['community_tags_settings'][$key][$vocab_key]['#title']);
        $row_data[] = array(
          'data' => drupal_render($form['community_tags_settings'][$key][$vocab_key]),
          'rowspan' => $rowspan,
        );
      }
    }

    // stripe per vocabulary
    $row_class = ($vocab_index % 2) == 0 ? 'odd' : 'even';

    if ($content_type_count > 0) {
      // get first and move pointer on
      $first_type = TRUE;
      foreach ($type_elements as $type_key) {
        $type_element = $form['community_tags_settings'][$key]['types'][$type_key];
        $type_sub_elements = element_children($form['community_tags_settings'][$key]['types'][$type_key]);


        // content type link cell
        $row_data['type'] = array('data' => $type_element['#title']);
        if ($first_type_row) {
          $type_column_count = count($type_sub_elements);

          // need type headings - increase rowspan of vocab headings
          foreach ($header_rows[0] as $header_index => $header_cell) {
            $header_rows[0][$header_index]['rowspan'] = 2;
          }
          // previous data rows may need expanding
          foreach ($rows as $row_key => $row) {
            $rows[$row_key]['data']['type']['colspan'] = $type_column_count;
          }

          // types heading - will have nested type-specific headings
          $header_rows[0]['type'] = array(
            'data' => $form['community_tags_settings'][$key]['types']['#title'],
            'colspan' => $type_column_count,
          );

          // start second header row
          $header_rows[1][] = array('data' => t('Type'));
          if ($type_element['#description']) {
            $notes[] = $type_element['#description'];
          }
        }

        foreach ($type_sub_elements as $sub_element_key) {
          if($type_element[$sub_element_key]['#type'] <> 'value') {
            if ($first_type_row) {
              $header_rows[1][] = array('data' => $type_element[$sub_element_key]['#title']);
              if (!empty($type_element[$sub_element_key]['#description'])) {
                $notes[] = $type_element[$sub_element_key]['#description'];
              }
            }
            unset($type_element[$sub_element_key]['#description']);
            unset($type_element[$sub_element_key]['#title']);
            $data = array('data' => drupal_render($type_element[$sub_element_key]));
            $row_data[] = $data;
          }
        }

        $rows[] = array(
          'data' => $row_data,
          'class' => $row_class,
        );

        // reset row data - don't need it row subsequent content type rows
        $row_data = array();
        $first_type_row = FALSE;
      }
    }
    else {
      // No types assigned
      $row_data['type'] = array(
        'data' => t('No assigned content types.'),
        'colspan' => $type_column_count,
      );
      if ($first_row) {
        // types heading - first row - don't know that we have type settings yet
        $header_rows[0]['type'] = array('data' => $form['community_tags_settings'][$key]['types']['#title']);
      }
      $rows[] = array(
        'data' => $row_data,
        'class' => $row_class,
      );
    }

    $vocab_index += 1;
    $first_row = FALSE;
  }

  $output = '<div class="form-item"><label>' . $form['community_tags_settings']['#title'] . ':</label>';

  // output the table - don't use standard theme because want bespoke striping
  $xoutput = '';
  $xoutput .= '<table><thead>';
  foreach ($header_rows as $header_row) {
    $xoutput .= '<tr>';
    foreach ($header_row as $header_cell) {
      $xoutput .= _theme_table_cell($header_cell, TRUE);
    }
    $xoutput .= '</tr>';
  }
  $xoutput .= '</thead><tbody>';
  foreach ($rows as $row) {
    $xoutput .= '<tr class="' . $row['class'] . '">';
    foreach ($row['data'] as $data_cell) {
      $xoutput .= _theme_table_cell($data_cell);
    }
    $xoutput .= '</tr>';
  }
  $xoutput .= '</tbody></table>';

  $output .= $xoutput;

  // add notes pulled from form elements to the end of the table
  if (!empty($notes)) {
    $output .= theme('item_list', array('items' => $notes, 'title' => NULL, 'type' => 'ul', 'attributes' => array('class' => 'description')));
  }

  // end of form-item div.
  $output .= '</div>';

  // clear all this
  drupal_render($form['community_tags_settings']);

  $output .= drupal_render_children($form);

  return $output;
}

/**
 * Get tag counts by vocabulary and type.
 */
function _community_tags_get_tag_counts_by_type_and_vocabulary() {
  $counts = array();

  // stat query for all ctags even for invalid combos - e.g. unassigned content type
  $tag_count_result = db_query(
    'SELECT td.vid, n.type, count(*) tag_count, count(distinct ct.nid) node_count, count(distinct ct.tid) term_count, count(distinct ct.uid) user_count
     FROM {community_tags} ct
     INNER JOIN {taxonomy_term_data} td ON td.tid = ct.tid
     INNER JOIN {node} n ON n.nid = ct.nid
     GROUP BY td.vid, n.type');

  // put tag counts into vocabularies array. If a new type is found for a vocabulary
  // then tags are left over from a previous configuration - i.e. content type was assigned for tagging but now is not.
  foreach ($tag_count_result as $row) {
    $counts[$row->vid][$row->type] = $row;
  }

  return $counts;
}

/**
 * Get number of missing community tags i.e. node terms that don't have community tags. Also return the number of nodes that have missing ctags.
 *  - number of missing term nodes i.e. community tags that don't have a matching node term (sync mode only).
 * D7 - AAaaaarrrgggghhhh. Need to hook into the field data tables. Could use taxonomy_index
 * but it only works for published nodes and can be disabled. But it's an awful lot easier and probably
 * faster - discussion of it's inception here: http://drupal.org/node/412518.
 *
 * @return
 *  Object with properties: {node_count, missing_ctag_count}.
 */
function _community_tags_get_out_of_sync_missing_tag_counts($vid, $content_type) {
  // have vocabulary and content type so we can narrow it down to one field data table
  // NOPE could have more than 1 term reference field on a content type referencing the same vocabulary
  // both having their own tables.
  $result = db_query("SELECT count(distinct n.nid) node_count, count(distinct n.nid, td.tid) missing_ctag_count
     FROM {taxonomy_index} tn
     INNER JOIN {taxonomy_term_data} td ON td.tid = tn.tid AND td.vid = :vid
     INNER JOIN {node} n ON n.nid = tn.nid AND n.type = :type
     LEFT JOIN {community_tags} ct ON ct.nid = tn.nid AND ct.tid = tn.tid
     WHERE ct.nid IS NULL", array(':vid' => $vid, ':type' => $content_type));

  $counts = $result->fetchObject();
  return $counts;
}

/**
 * Get out_of_sync_missing_tag_counts counts for all vocabulary and node type combinations.
 */
function _community_tags_get_all_out_of_sync_missing_tag_counts() {
  $counts = array();
  // TODO Please convert this statement to the D7 database API syntax.
  $result = db_query("SELECT td.vid, n.type, count(distinct tn.nid) node_count, count(distinct tn.nid) term_count, count(distinct tn.nid, tn.tid) missing_ctag_count
     FROM {taxonomy_index} tn
     INNER JOIN {taxonomy_term_data} td ON td.tid = tn.tid
     INNER JOIN {node} n ON n.nid = tn.nid
     LEFT JOIN {community_tags} ct ON ct.nid = tn.nid AND ct.tid = tn.tid
     WHERE ct.nid IS NULL
     GROUP BY td.vid, n.type");

  foreach ($result as $row) {
    $counts[$row->vid][$row->type] = $row;
  }
  return $counts;
}

/**
 * Get out_of_sync_missing_node_terms counts for all vocabulary and node type combinations.
 */
function _community_tags_get_all_out_of_sync_missing_node_terms_counts() {
  $counts = array();
  // TODO Please convert this statement to the D7 database API syntax.
  $result = db_query("SELECT td.vid, n.type, count(distinct ct.nid) node_count, count(distinct ct.nid) term_count, count(distinct ct.nid, ct.tid) missing_termnode_count
     FROM {community_tags} ct
     INNER JOIN {taxonomy_term_data} td ON td.tid = ct.tid
     INNER JOIN {node} n ON n.nid = ct.nid
     LEFT JOIN {taxonomy_index} tn ON tn.nid = ct.nid AND tn.tid = ct.tid
     WHERE tn.nid IS NULL
     GROUP BY td.vid, n.type");

  foreach ($result as $row) {
    $counts[$row->vid][$row->type] = $row;
  }
  return $counts;
}

/**
 * Get the number of missing term nodes i.e. community tags that don't have a matching node term (sync mode only). Also return the number of nodes that have missing node terms.
 *
 * @return
 *  Object with properties: {node_count, missing_nodeterm_count}.
 */
function _community_tags_get_out_of_sync_missing_nodeterm_counts($vid, $content_type) {
  // TODO Please convert this statement to the D7 database API syntax.
  $result = db_query("SELECT count(distinct n.nid) node_count, count(*) missing_nodeterm_count
     FROM {community_tags} ct
     INNER JOIN {taxonomy_term_data} td ON td.tid = ct.tid AND td.vid = :vid
     INNER JOIN {node} n ON n.nid = ct.nid AND n.type = :type
     LEFT JOIN {taxonomy_index} tn ON tn.nid = ct.nid AND tn.tid = ct.tid
     WHERE tn.nid IS NULL", array(':vid' => $vid, ':type' => $content_type));

  $counts = $result->fetchObject();
  return $counts;
}

/**
 * Confirmation form for tag rebuild.
 */
function community_tags_rebuild_form($form, &$form_state, $vocabulary, $content_type) {
  $form = array();
  $type_obj = node_type_get_type($content_type);

  $settings = _community_tags_get_settings($vocabulary->vid, $content_type, TRUE);

  $missing_tag_counts = _community_tags_get_out_of_sync_missing_tag_counts($vocabulary->vid, $content_type);
  $missing_nodeterm_counts = _community_tags_get_out_of_sync_missing_nodeterm_counts($vocabulary->vid, $content_type);

  $form['#rebuild_ops'] = array();
  $form['#ct_settings'] = $settings;
  $form['#vocabulary'] = $vocabulary;
  $form['#content_type_obj'] = $type_obj;

  $description = '';

  if ($settings) {
    if ($missing_tag_counts->missing_ctag_count > 0 || (($settings['opmode'] & COMMUNITY_TAGS_OPMODE_SYNC) && $missing_nodeterm_counts->missing_nodeterm_count > 0)) {
      $question = t('Rebuild community tags for %vocabulary terms on %type nodes?', array('%vocabulary' => $vocabulary->name, '%type' => $type_obj->name));

      if ($missing_tag_counts->missing_ctag_count > 0) {
        $description = '<p>' . t('This operation will rebuild %count missing community tags on %node_count nodes.', array('%count' => $missing_tag_counts->missing_ctag_count, '%node_count' => $missing_tag_counts->node_count)) . '</p>';

        $form['#rebuild_ops']['tags'] = $missing_tag_counts;
      }

      if (($settings['opmode'] & COMMUNITY_TAGS_OPMODE_SYNC) && $missing_nodeterm_counts->missing_nodeterm_count > 0) {
        $description .= '<p>' . t('Sync mode is <em>ON</em>. There are %count community tags that have no corresponding node terms. Select a syncronistion mode: ', array('%count' => $missing_nodeterm_counts->missing_nodeterm_count)) . '</p>';

        // offer option to bring ct's into line with nt or vice versa
        $form['sync_policy'] = array(
          '#type' => 'radios',
          '#title' => t('Synchronisation mode'),
          '#options' => array(
            t('<em>Delete community tags</em> that have no corresponding node term.'),
            t('<em>Add node terms</em> for all community tags that have no corresponding node term.'),
          ),
          '#weight' => 1,
          '#default_value' => 0,
        );
        $form['#rebuild_ops']['nodeterms'] = $missing_nodeterm_counts;
      }

      // don't do orphaned term removal - needs work.
    }
    else {
      drupal_set_message(t('Community tags for @vocabulary terms on @type nodes are up to date. Nothing to rebuild. ', array('@vocabulary' => $vocabulary->name, '@type' => $type_obj->name)));
      return;
    }
  }
  else {
    drupal_set_message(t('Community tagging is not active for @vocabulary terms on @type nodes. Will not rebuild. ', array('@vocabulary' => $vocabulary->name, '@type' => $type_obj->name)));
    return;
  }

  $path = 'admin/config/content/community-tags';

  $confirm_form = confirm_form($form, $question, $path, $description);
  $confirm_form['actions']['#weight'] = 2;
  return $confirm_form;
}

/**
 * Submit handler for rebuild confirmation form.
 */
function community_tags_rebuild_form_submit($form, &$form_state) {
  $vid = $form['#vocabulary']->vid;
  $content_type = $form['#content_type_obj']->type;

  $operations = array();

  // set up the tag rebuild operations
  if (isset($form['#rebuild_ops']['tags'])) {
    $operations[] = array('community_tags_rebuild_tags_batch_process', array($vid, $content_type, $form['#rebuild_ops']['tags']->node_count));
  }

  if (isset($form['#rebuild_ops']['nodeterms'])) {
    $mode = $form_state['values']['sync_policy'];
    $operations[] = array('community_tags_rebuild_nodeterms_batch_process', array($vid, $content_type, $form['#rebuild_ops']['nodeterms']->node_count, $mode));
  }

  $batch = array(
    'operations' => $operations,
    'finished' => 'community_tags_batch_finished',
    'title' => t('Processing Community Tags Rebuild Batch'),
    'init_message' => t('Community Tags Rebuild Batch is starting.'),
    // 'progress_message' => t('Processed @current out of @total.'),
    'error_message' => t('Community Tags Rebuild Batch has encountered an error.'),
    'file' => drupal_get_path('module', 'community_tags') . '/community_tags.batch.inc',
  );
  batch_set($batch);
}

/**
 * Get the number of broken tags.
 *
 * @return
 *  The number of broken tags.
 */
function _community_tags_get_count_of_broken_tags() {
  // TODO Please convert this statement to the D7 database API syntax.
  $result = db_query('SELECT count(*) FROM {community_tags} ct
     LEFT JOIN {taxonomy_term_data} td ON td.tid = ct.tid
     LEFT JOIN {users} u ON u.uid = ct.uid
     LEFT JOIN {node} n ON n.nid = ct.nid
     WHERE td.tid IS NULL
     OR u.uid IS NULL
     OR n.nid IS NULL');

  return $result->fetchField();
}

/**
 * Confirmation for deleting broken tags.
 */
function community_tags_delete_broken_tags_form($form, &$form_state) {
  $form = array();
  $question = t('Delete %count broken community tags?', array('%count' => $broken_ctag_count));
  $path = 'admin/config/content/community-tags';
  $confirm_form = confirm_form($form, $question, $path);
  return $confirm_form;
}

/**
 * Submit handler for broken tag deletion form.
 */
function community_tags_delete_broken_tags_form_submit($form, &$form_state) {
  // TODO Please convert this statement to the D7 database API syntax.
   db_query(
     'DELETE FROM ct
     USING {community_tags} ct
     LEFT JOIN {taxonomy_term_data} td ON td.tid = ct.tid
     LEFT JOIN {users} u ON u.uid = ct.uid
     LEFT JOIN {node} n ON n.nid = ct.nid
     WHERE td.tid IS NULL
     OR u.uid IS NULL
     OR n.nid IS NULL'
   );

  $deleted = db_affected_rows();

  drupal_set_message(t('@count broken community tags deleted.', array('@count' => $deleted)));
  $form_state['redirect'] = "admin/config/content/community-tags";
}

/**
 * Confirmation form for tag purge. Assumes defaults.
 */
function community_tags_delete_all_form($form, &$form_state, $vocabulary, $content_type) {
  $form = array();

  $type_obj = node_type_get_type($content_type);
  // get the number of tags that will be deleted
  $counts = _community_tags_get_tag_counts_by_type_and_vocabulary();
  if (empty($counts[$vocabulary->vid][$content_type])) {
    drupal_set_message(t('There are no community tags to delete.'));
  }
  else {
    $counts = $counts[$vocabulary->vid][$content_type];
  }


  // get settings if valid
  $settings = _community_tags_get_settings($vocabulary->vid, $content_type, TRUE);

  $form['#delete_ops'] = array();
  $form['#ct_settings'] = $settings;
  $form['#vocabulary'] = $vocabulary;
  $form['#content_type_obj'] = $type_obj;
  $form['#counts'] = $counts;

  $question = t('Delete %count community tags from the %vocabulary vocabulary on nodes of type %type?.', array('%count' => $counts->tag_count, '%vocabulary' => $vocabulary->name, '%type' => $type_obj->name));

  // @todo 2.x get the number of node terms that will be deleted
  // @todo 2.x get the number of orphaned terms that will be deleted

  $description = '';
  if ($settings) {
    $form['#delete_ops']['delete_tags'] = TRUE;
    $description .= '<p>' . t('WARNING: Community tagging is currently enabled for this combination of content type and vocabulary. ') . '</p>';

    if ($settings['opmode'] & COMMUNITY_TAGS_OPMODE_SYNC || $settings['opmode'] & COMMUNITY_TAGS_OPMODE_DELETE_ORPHAN_TERMS) {
      // offer option to bring ct's into line with nt or vice versa
      $form['delete_policy'] = array(
        '#type' => 'checkboxes',
        '#title' => t('Purge options'),
        '#options' => array(),
        '#multiple' => TRUE,
        '#weight' => 1,
        '#default_value' => array(),
      );

      if ($settings['opmode'] & COMMUNITY_TAGS_OPMODE_SYNC) {
        $description .= '<p>' . t('Community tags are synchronised with node terms: all corresponding node terms will be removed. ') . '</p>';
        $description .= '<p>' . t('If you do not want to delete corresponding node terms as part of this purge operation, un-check the option below. ') . '</p>';
        $form['delete_policy']['#options'][COMMUNITY_TAGS_OPMODE_SYNC] = t('<em>Delete node terms</em>');
        $form['delete_policy']['#default_value'][] = COMMUNITY_TAGS_OPMODE_SYNC;
      }
      else {
        $description = '<p>' . t('Community tags will be deleted from the community tags database table.') . '</p>';
      }
      if ($settings['opmode'] & COMMUNITY_TAGS_OPMODE_DELETE_ORPHAN_TERMS) {
        $description .= '<p>' . t('"Delete orphaned term" mode is set. All orphaned terms will be deleted i.e. all terms matching deleted tags that are no longer used. ') . '</p>';
        $description .= '<p>' . t('If you do not want to delete redundant terms as part of this purge operation, un-check the option below. ') . '</p>';
        $form['delete_policy']['#options'][COMMUNITY_TAGS_OPMODE_DELETE_ORPHAN_TERMS] = t('<em>Delete redundant terms</em>');
        $form['delete_policy']['#default_value'][] = COMMUNITY_TAGS_OPMODE_DELETE_ORPHAN_TERMS;
      }
    }

  }
  else {
    $form['#delete_ops']['#quick_delete'] = TRUE;
    $description = '<p>' . t('Community tagging is currently disabled for this combination of content type and vocabulary. ') . '</p>';
    $description = '<p>' . t('Community tags will be deleted from the community tags database table and nothing else. ') . '</p>';
  }

  $path = 'admin/config/content/community-tags';

  $confirm_form = confirm_form($form, $question, $path, $description);
  $confirm_form['actions']['#weight'] = 2;
  return $confirm_form;
}

/**
 * Submit handler for community_tags_delete_all_form().
 */
function community_tags_delete_all_form_submit($form, &$form_state) {
  $vid = $form['#vocabulary']->vid;
  $content_type = $form['#content_type_obj']->type;

  if (isset($form['#delete_ops']['#quick_delete'])) {
    // TODO Please convert this statement to the D7 database API syntax.
     db_query(
     "DELETE FROM ct
     USING {community_tags} ct, {taxonomy_term_data} AS td, {node} AS n
     WHERE ct.tid = td.tid
     AND td.vid = :vid
     AND ct.nid = n.nid
     AND n.type = :type", array(':vid' => $vid, ':type' => $content_type));

    drupal_set_message(t('@delete_count community tags deleted.', array('@delete_count' => db_affected_rows())));
  }
  else {
    // do batched delete
    $operations = array();

    $mode = $form['#ct_settings']['opmode'];

    // set up the tag delete operations
    // remove mode flags for unchecked mode options
    if (!empty($form_state['values']['delete_policy'])) {
      foreach ($form_state['values']['delete_policy'] as $mask => $set) {
        $mode = $set == 0 ? $mode &= ~$mask : $mode;
      }
    }
    $operations[] = array('community_tags_delete_tags_batch_process', array($vid, $content_type, $form['#counts'], $mode));
    $batch = array(
      'operations' => $operations,
      'finished' => 'community_tags_batch_finished',
      'title' => t('Processing Community Tags Delete Batch'),
      'init_message' => t('Community Tags Delete Batch is starting.'),
      // 'progress_message' => t('Processed @current out of @total.'),
      'error_message' => t('Community Tags Delete Batch has encountered an error.'),
      'file' => drupal_get_path('module', 'community_tags') . '/community_tags.batch.inc',
    );
    batch_set($batch);
  }

}
