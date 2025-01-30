<?php

/**
 * @file
 * Callbacks for services module resource hooks.
 */

/**
 * Callback for retrieving views resources.
 *
 * @param string $view_name
 *   The views name.
 * @param string $display_id
 *   (optional) The views display name.
 * @param array $args
 *   (optional) A list of arguments to pass to the view.
 * @param int $offset
 *   (optional) An offset integer for paging.
 * @param int $limit
 *   (optional) A limit integer for paging.
 * @param string $return_type
 *   (optional) Whether to return the raw data results (FALSE), the entire
 *   views object ('view') or themed results ('theme').
 * @param array $filters
 *   (optional) A list of exposed filters to pass to the view.
 *
 * @return array
 *   The views return.
 */
function services_views_retrieve($view_name, $display_id = 'default', array $args = array(), $offset = 0, $limit = -1, $return_type = FALSE, array $filters = array()) {
  $result = array();
  $view = views_get_view($view_name);
  // Make sure we aren't working with a backwards compatible display_id.
  if (empty($view->display[$display_id]) || $view->display[$display_id]->display_plugin != 'services') {
    $display_id = 'services_clone_' . $display_id;
  }

  // Put all arguments and filters and then execute.
  $view->set_arguments($args, FALSE);
  $view->set_exposed_input($filters);
  $view->set_offset($offset);

  // Support for Views 2.
  if (method_exists($view, 'set_use_pager')) {
    // If offset is set we can't have a user pager.
    if (empty($offset)) {
      $view->set_use_pager(TRUE);
      if ($limit >= 0) {
        $view->set_items_per_page($limit);
      }
    }
    else {
      // Disable the user pager.
      $view->set_use_pager(FALSE);
    }
  }
  elseif ($limit >= 0) {
    $view->set_items_per_page($limit);
  }

  // If we display values and not themed view output.
  if (empty($return_type)) {
    $view->set_display($display_id);
    $view->pre_execute();
    $view->execute();
    $result = $view->result;

    $row_plugin = $view->display_handler->get_option('row_plugin');
    // If row plugin is node, then we should load each node.
    if ($row_plugin == 'node') {
      $nodes = array();
      foreach ($view->result as $row) {
        $nodes[] = node_load($row->nid);
      }
      $result = $nodes;
    }
    elseif ($row_plugin == 'fields') {
      $items = array();

      // Pre-render and field values.
      foreach ($view->field as $field) {
        $field->pre_render($view->result);
      }

      foreach ($view->result as $row_index => $row) {
        $item = new stdClass();
        $excluded_fields = array();
        foreach ($view->field as $field_id => $field) {
          if (!empty($field->options['label'])) {
            $field_label = strtolower($field->options['label']);
          }
          elseif ($field->field_alias) {
            $field_label = $field->field_alias;
          }
          else {
            $field_label = $field_id;
          }
          $field->view->row_index = $row_index;
          $item->$field_label = $field->theme($row);
          if (!empty($field->options['exclude'])) {
            $excluded_fields[] = $field_label;
          }
        }
        foreach ($excluded_fields as $excluded_field) {
          unset($item->{$excluded_field});
        }
        $items[] = $item;
      }
      if ($items) {
        $result = $items;
      }
    }
  }
  elseif ($return_type == 'view') {
    $view->set_display($display_id);
    $view->execute();
    return $view;
  }
  else {
    // We want to keep the result an array.
    $result[] = $view->preview($display_id);
  }
  return $result;
}

/**
 * Execute a view and return results.
 */
function services_views_execute_view($view_info, $view = NULL, $display_id = NULL) {
  if (!empty($view_info)) {
    $view_name = $view_info['view_name'];
    $display_id = $view_info['display_id'];
    $args = $view_info['args'];

    $view = views_get_view($view_name);
    $view->set_arguments($args);
    $view->execute_display($display_id, $args);
  }

  // Avoid translation of the field labels.
  $view->localization_plugin = views_get_plugin('localization', 'none');

  // Execute a view.
  $output = $view->render($display_id);

  // Add support for Services Raw formatter.
  foreach ($view->result as $index => $row) {
    foreach ($view->field as $field_key => $field) {
      $f_key = 'field_' . $field_key;
      $entity_property = FALSE;
      if (!isset($row->$f_key)) {
        $f_key = $field->field_alias;
        $entity_property = TRUE;
      }
      if (isset($row->$f_key)) {
        $target_key = $field_key;

        // Skip this field?
        if (isset($field->options['exclude']) && $field->options['exclude'] == TRUE) {
          continue;
        }

        if (isset($field->options['label']) && !empty($field->options['label'])) {
          $target_key = $field->options['label'];
        }

        // Move key if we have an entity property and the target_key was changed
        // via label.
        if ($entity_property) {
          unset($output[$index]->$f_key);
          $field->view->row_index = $index;
          // @todo: Do not render twice; use view->execute_display and
          // consolidate functions.
          $output[$index]->$target_key = $field->theme($row);
          continue;
        }

        // Create helper variables.
        $output[$index]->$target_key = array();
        if ($field->field_info['cardinality'] == 1) {
          $output[$index]->$target_key = array('');
        }
        $obj = &$output[$index]->$target_key;
        $format = ($field->options['type'] == 'services') ? 'raw' : 'rendered';

        foreach ($row->$f_key as $idx => $res) {

          if (isset($res[$format])) {
            $data = $res[$format];

            // If this is raw formatter.
            if ($format == 'raw') {
              if (is_array($data)) {
                foreach ($data as $key => $val) {
                  if ($field->options['settings']['skip_safe'] && strpos($key, 'safe_') === 0) {
                    unset($data[$key]);
                  }
                  if ($field->options['settings']['skip_empty_values'] && empty($val)) {
                    unset($data[$key]);
                  }
                }
              }
              $obj[$idx] = $data;
            }
            // Rendered output.
            elseif (isset($data['#access']) && $data['#access'] == TRUE) {
              // Check for a field collection.
              if (isset($data['entity']['field_collection_item'])) {
                foreach ($data['entity']['field_collection_item'] as $fcid => $entity) {
                  // If the field collection is using the services view mode,
                  // add each child separately.
                  if ($entity['#view_mode'] == 'services') {
                    $instances = field_info_instances($entity['#entity_type'], $entity['#bundle']);
                    foreach (element_children($entity, TRUE) as $child) {
                      $instance = $instances[$child];
                      $element_key = $instance['display']['services']['settings']['data_element_key'];
                      $element_key = ($element_key ? $element_key : $instance['label']);

                      // Get the formatted values for the field and add them to
                      // the data array, using any preset element keys.
                      foreach (element_children($entity[$child]) as $field_item) {
                        $fi = &$entity[$child][$field_item];
                        if (is_array($fi) && count($fi) == 1 && isset($fi['value'])) {
                          $obj[$idx][$element_key] = $fi['value'];
                        }
                        else {
                          $obj[$idx][$element_key] = $fi;
                        }
                      }
                    }

                    // Allow modules to alter the data before it is sent.
                    drupal_alter('services_field_collection_data', $obj[$idx], $entity, $f_key);
                  }
                  else {
                    $obj[$idx] = render($data);
                  }
                }
              }
              else {
                $obj[$idx] = render($data);
              }
            }
            else {
              $obj[$idx] = array('error' => t('Access denied or format unknown on field.'));
            }
          }

          // Check html_strip property.
          if ($field->options['alter']['strip_tags'] == 1) {
            // Strip the tags which aren't allowed.
            $obj[$idx] = strip_tags($obj[$idx], $field->options['alter']['preserve_tags']);
          }

          // Check cardinality of the field.
          if ($field->field_info['cardinality'] == 1 && is_array($obj) && count($obj) == 1) {
            $obj = $obj[$idx];
          }
        }
      }
    }
  }

  drupal_alter('services_views_execute_view', $output, $view);

  $view->destroy();
  return $output;
}
