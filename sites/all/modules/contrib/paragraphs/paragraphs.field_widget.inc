<?php

/**
 * @file
 * Holds functions for the paragraphs widgets.
 */

/**
 * Implements hook_field_widget_info().
 */
function paragraphs_field_widget_info() {
  return array(
    'paragraphs_hidden' => array(
      'label' => t('Hidden'),
      'field types' => array('paragraphs'),
      'behaviors' => array(
        'multiple values' => FIELD_BEHAVIOR_CUSTOM,
        'default value' => FIELD_BEHAVIOR_NONE,
      ),
    ),
    'paragraphs_embed' => array(
      'label' => t('Embedded'),
      'field types' => array('paragraphs'),
      'behaviors' => array(
        'multiple values' => FIELD_BEHAVIOR_CUSTOM,
        'default value' => FIELD_BEHAVIOR_NONE,
      ),
    ),
  );
}

/**
 * Implements hook_field_widget_form().
 */
function paragraphs_field_widget_form(&$form, &$form_state, $field, $instance, $langcode, $items, $delta, $element) {
  switch ($instance['widget']['type']) {
    case 'paragraphs_hidden':
      return $element;

    case 'paragraphs_embed':
      return paragraphs_field_multiple_value_form($field, $instance, $langcode, $items, $form, $form_state, $delta, $element);

  }
}

/**
 * Special handling to create form elements for multiple values.
 *
 * Handles generic features for multiple fields:
 * - number of widgets
 * - AHAH-'add more' button
 * - drag-n-drop value reordering.
 */
function paragraphs_field_multiple_value_form($field, $instance, $langcode, $items, &$form, &$form_state, $delta, $original_element) {
  $field_name = $field['field_name'];
  $parents = $form['#parents'];

  $field_state = field_form_get_state($parents, $field_name, $langcode, $form_state);
  $max = $field_state['items_count'] - 1;

  $title = check_plain($instance['label']);
  $description = field_filter_xss($instance['description']);

  $id_prefix = implode('-', array_merge($parents, array($field_name)));
  $wrapper_id = drupal_html_id($id_prefix . '-add-more-wrapper');

  $field_elements = array();

  $function = $instance['widget']['module'] . '_field_widget_form_build';
  $had_first = FALSE;
  $actual_item_count = 0;

  if (function_exists($function)) {
    for ($delta = 0; $delta <= $max; $delta++) {
      $multiple = TRUE;
      $element = array(
        '#entity_type' => $original_element['#entity_type'],
        '#entity' => $original_element['#entity'],
        '#bundle' => $original_element['#bundle'],
        '#field_name' => $field_name,
        '#language' => $langcode,
        '#field_parents' => $parents,
        '#columns' => array_keys($field['columns']),
        // For multiple fields, title and description are handled by the
        // wrapping table.
        '#title' => $multiple ? '' : $title,
        '#description' => $multiple ? '' : $description,
        '#delta' => $delta,
        '#weight' => $delta,
        '#wrapper_id' => $wrapper_id,
      );
      if ($element = $function($form, $form_state, $field, $instance, $langcode, $items, $delta, $element)) {
        // Input field for the delta (drag-n-drop reordering).
        if ($multiple) {
          // We name the element '_weight' to avoid clashing with elements
          // defined by widget.
          $element['_weight'] = array(
            '#type' => 'weight',
            '#title' => t('Weight for row @number', array('@number' => $delta + 1)),
            '#title_display' => 'invisible',
            // Note: this 'delta' is the FAPI 'weight' element's property.
            '#delta' => $max,
            '#default_value' => isset($items[$delta]['_weight']) ? $items[$delta]['_weight'] : $delta,
            '#weight' => 100,
          );
        }

        // Because our deleted elements are still in the form, only the first
        // shown element is required.
        if (!$had_first && (!isset($element['#access']) || $element['#access'])) {
          $had_first = TRUE;
          $element['#required'] = $instance['required'];
        }

        if (!isset($element['#access']) || $element['#access']) {
          $actual_item_count++;
        }

        // Allow modules to alter the field widget form element.
        $context = array(
          'form' => $form,
          'field' => $field,
          'instance' => $instance,
          'langcode' => $langcode,
          'items' => $items,
          'delta' => $delta,
        );
        drupal_alter(array('paragraphs_field_widget_form', 'paragraphs_field_widget_' . $instance['widget']['type'] . '_form'), $element, $form_state, $context);

        $field_elements[$delta] = $element;
      }
    }

    $field_state = field_form_get_state($parents, $field_name, $langcode, $form_state);
    $field_state['real_items_count'] = $actual_item_count;
    field_form_set_state($parents, $field_name, $langcode, $form_state, $field_state);

    $field_elements += array(
      '#theme' => 'paragraphs_field_multiple_value_form',
      '#field_name' => $field['field_name'],
      '#cardinality' => $field['cardinality'],
      '#title' => $title,
      '#required' => $instance['required'],
      '#description' => $description,
      '#prefix' => '<div id="' . $wrapper_id . '">',
      '#suffix' => '</div>',
      '#max_delta' => $max,
      '#instance' => $instance,
      '#element_validate' => array('_paragraphs_multiple_field_validate'),
    );

    // Add 'add more' button, if not working with a programmed form.
    if (empty($form_state['programmed'])) {
      $available_bundles = paragraphs_bundle_load();
      $select_bundles = array();
      $select_bundles_weighted = array();

      // By default, consider that no bundle has been explicitly picked.
      $explicitly_enabled = FALSE;
      foreach ($instance['settings']['allowed_bundles'] as $allowed_bundle_key => $allowed_bundle_value) {
        if ($allowed_bundle_key === $allowed_bundle_value && isset($available_bundles[$allowed_bundle_key])) {
          $select_bundles[$available_bundles[$allowed_bundle_key]->bundle] = $available_bundles[$allowed_bundle_key]->label;

          // If an item has been explicitly selected, raise our flag.
          $explicitly_enabled = TRUE;
        }
        elseif (isset($available_bundles[$allowed_bundle_key]->bundle)) {
          $select_bundles_weighted[$available_bundles[$allowed_bundle_key]->bundle] = $available_bundles[$allowed_bundle_key]->label;
        }
      }

      // If no bundle has been explicitly selected, give access to all of them.
      if (!$explicitly_enabled) {
        $select_bundles = $select_bundles_weighted;
        foreach ($available_bundles as $bundle) {
          if (!isset($select_bundles[$bundle->bundle])) {
            $select_bundles[$bundle->bundle] = $bundle->label;
          }
        }
      }

      $removed_a_bundle = FALSE;

      $weight = 0;

      foreach ($select_bundles as $machine_name => $bundle) {
        $select_bundles[$machine_name] = array(
          'name' => $bundle,
          'weight' => $weight,
        );

        /* @var $entity_shell ParagraphsItemEntity */
        $entity_shell = entity_create('paragraphs_item', array('bundle' => $machine_name, 'field_name' => $field_name));
        $entity_shell->setHostEntity($original_element['#entity_type'], $original_element['#entity'], $langcode, FALSE);

        if (!entity_access('create', 'paragraphs_item', $entity_shell)) {
          unset($select_bundles[$machine_name]);
          $removed_a_bundle = TRUE;
        }
        elseif (isset($instance['settings']['bundle_weights'][$machine_name])) {
          $select_bundles[$machine_name]['weight'] = $instance['settings']['bundle_weights'][$machine_name];
        }
        $weight++;
      }

      $field_elements['#select_bundles'] = $select_bundles;
      if ($removed_a_bundle && count($select_bundles) === 0) {
        $field_elements['add_more'] = array(
          '#type' => 'container',
          '#tree' => TRUE,
        );
        $field_elements['add_more']['add_more'] = array(
          '#type' => 'markup',
          '#markup' => '<em>' . t('You are not allowed to add any of the bundles.') . '</em>',
        );
      }
      elseif (count($select_bundles)) {
        uasort($select_bundles, 'drupal_sort_weight');
        $field = $field_state['field'];

        if ($field['cardinality'] == FIELD_CARDINALITY_UNLIMITED || $field_state['real_items_count'] < $field['cardinality']) {
          if (!isset($instance['settings']['title'])) {
            $instance['settings']['title'] = PARAGRAPHS_DEFAULT_TITLE;
          }
          $instance_title = t($instance['settings']['title']);

          $field_elements['add_more'] = array(
            '#type' => 'container',
            '#tree' => TRUE,
          );

          $add_mode = (isset($instance['settings']['add_mode']) ? $instance['settings']['add_mode'] : PARAGRAPHS_DEFAULT_ADD_MODE);

          if ($add_mode == 'button') {
            foreach ($select_bundles as $machine_name => $bundle) {

              /* @var $entity_shell ParagraphsItemEntity */
              $entity_shell = entity_create('paragraphs_item', array('bundle' => $machine_name, 'field_name' => $field_name));
              $entity_shell->setHostEntity($original_element['#entity_type'], $original_element['#entity'], $langcode, FALSE);

              $field_elements['add_more']['add_more_bundle_' . $machine_name] = array(
                '#type' => 'submit',
                '#name' => strtr($id_prefix, '-', '_') . '_add_more_add_more_bundle_' . $machine_name,
                '#value' => t('Add !title', array('!title' => $bundle['name'])),
                '#access' => entity_access('create', 'paragraphs_item', $entity_shell),
                '#attributes' => array('class' => array('field-add-more-submit', 'paragraphs-add-more-submit')),
                '#limit_validation_errors' => array(),
                '#submit' => array('paragraphs_add_more_submit'),
                '#ajax' => array(
                  'callback' => 'paragraphs_add_more_js',
                  'wrapper' => $wrapper_id,
                  'effect' => 'fade',
                ),
              );
            }
          }
          else {
            uasort($select_bundles, 'drupal_sort_weight');

            $select_list = array();
            foreach ($select_bundles as $machine_name => $bundle) {
              $select_list[$machine_name] = $bundle['name'];
            }

            $field_elements['add_more']['type'] = array(
              '#type' => 'select',
              '#name' => strtr($id_prefix, '-', '_') . '_add_more_type',
              '#title' => t('!title type', array('!title' => $instance_title)),
              '#options' => $select_list,
              '#attributes' => array('class' => array('field-add-more-type')),
              '#limit_validation_errors' => array(array_merge($parents, array($field_name, $langcode))),
            );

            // Hide the bundle selection if only one bundle is allowed.
            if (count($select_list) == 1) {
              $field_elements['add_more']['type']['#type'] = 'hidden';
              $keys = array_keys($select_list);
              $field_elements['add_more']['type']['#value'] = $keys[0];
            }

            if (isset($form_state['input'][strtr($id_prefix, '-', '_') . '_add_more_type'])) {
              $field_elements['add_more']['type']['#default_value'] = $form_state['input'][strtr($id_prefix, '-', '_') . '_add_more_type'];
            }

            $text = t('Add new !title', array('!title' => $instance_title));
            if ($max >= 0) {
              $text = t('Add another !title', array('!title' => $instance_title));
            }

            $field_elements['add_more']['add_more'] = array(
              '#type' => 'submit',
              '#name' => strtr($id_prefix, '-', '_') . '_add_more_add_more',
              '#value' => $text,
              '#attributes' => array('class' => array('field-add-more-submit', 'paragraphs-add-more-submit')),
              '#limit_validation_errors' => array(),
              '#submit' => array('paragraphs_add_more_submit'),
              '#ajax' => array(
                'callback' => 'paragraphs_add_more_js',
                'wrapper' => $wrapper_id,
                'effect' => 'fade',
              ),
            );
          }
        }
      }
      else {
        $field_elements['add_more']['add_more'] = array(
          '#type' => 'markup',
          '#markup' => '<em>' . t('No bundles available, edit field settings') . '</em>',
        );
      }
    }
  }

  if (module_exists('file')) {
    // file.js triggers uploads when the main Submit button is clicked.
    $field_elements['#attached']['js'] = array(
      drupal_get_path('module', 'file') . '/file.js',
      array(
        'data' => drupal_get_path('module', 'paragraphs') . '/paragraphs.js',
        'type' => 'file',
        'weight' => 9999,
      ),
    );
    $form_state['has_file_element'] = TRUE;
  }

  return $field_elements;
}

/**
 * Widget form implementation for paragraphs.
 *
 * @param array $form
 *   The form structure where widgets are being attached to. This might be a
 *   full form structure, or a sub-element of a larger form.
 * @param array $form_state
 *   An associative array containing the current state of the form.
 * @param array $field
 *   The field structure.
 * @param array $instance
 *   The field instance.
 * @param string $langcode
 *   The language associated with $items.
 * @param array $items
 *   Array of default values for this field.
 * @param int $delta
 *   The order of this item in the array of subelements (0, 1, 2, etc).
 * @param array $element
 *   A form element array containing basic properties for the widget.
 *
 * @return array
 *   The form elements for a single widget for this field.
 */
function paragraphs_field_widget_form_build(array &$form, array &$form_state, array $field, array $instance, $langcode, array $items, $delta, array $element) {
  static $recursion = 0;

  if (!isset($instance['settings']['title'])) {
    $instance['settings']['title'] = PARAGRAPHS_DEFAULT_TITLE;
  }
  $instance_title = t($instance['settings']['title']);

  if (!isset($instance['settings']['title_multiple'])) {
    $instance['settings']['title_multiple'] = PARAGRAPHS_DEFAULT_TITLE_MULTIPLE;
  }

  // If the paragraphs item form contains another paragraph,
  // we might ran into a recursive loop. Prevent that.
  if ($recursion++ > PARAGRAPHS_RECURSION_LIMIT) {
    drupal_set_message(t('The paragraphs item form has not been embedded to avoid recursive loops.'), 'error');
    return $element;
  }

  $field_parents = $element['#field_parents'];
  $field_name = $element['#field_name'];
  $language = $element['#language'];

  // Set host entity data since field_attach_form() overrides the $element
  // values with the values for the paragraphs item.
  $element['#host_entity_type'] = $element['#entity_type'];
  $element['#host_entity'] = $element['#entity'];
  $element['#host_bundle'] = $element['#bundle'];

  $bundle = FALSE;
  $id_prefix = implode('-', array_merge($field_parents, array($field_name)));

  if (isset($form_state['input'][strtr($id_prefix, '-', '_') . '_add_more_type'])) {
    $bundle = $form_state['input'][strtr($id_prefix, '-', '_') . '_add_more_type'];
  }
  elseif (isset($form_state['input']['_triggering_element_name'])) {
    if (strpos($form_state['input']['_triggering_element_name'], strtr($id_prefix, '-', '_') . '_add_more_add_more_bundle_') === 0) {
      $bundle = substr($form_state['input']['_triggering_element_name'], drupal_strlen(strtr($id_prefix, '-', '_') . '_add_more_add_more_bundle_'));
    }
  }

  // Nest the paragraphs item entity form in a dedicated parent space,
  // by appending [field_name, langcode, delta] to the current parent space.
  // That way the form values of the paragraphs item are separated.
  $parents = array_merge($field_parents, array($field_name, $language, $delta));

  $element += array(
    '#element_validate' => array('paragraphs_field_widget_embed_validate'),
    '#parents' => $parents,
  );

  $field_state = field_form_get_state($field_parents, $field_name, $language, $form_state);

  $deleted_paragraph = FALSE;
  $confirmed_deleted_paragraph = FALSE;
  $is_new_paragraph = FALSE;

  $default_edit_mode = isset($instance['settings']['default_edit_mode']) ? $instance['settings']['default_edit_mode'] : PARAGRAPHS_DEFAULT_EDIT_MODE;
  $default_edit_mode_override = isset($instance['settings']['default_edit_mode_override']) ? $instance['settings']['default_edit_mode_override'] : PARAGRAPHS_DEFAULT_EDIT_MODE_OVERRIDE;
  $force_open = (!empty($instance['widget']['paragraphs_edit_mode_open']) || count($items) < $default_edit_mode_override);

  $being_edited_paragraph = ($default_edit_mode === 'open');

  if (isset($field_state['entity'][$delta])) {
    if (isset($field_state['entity'][$delta]->removed) && $field_state['entity'][$delta]->removed) {
      $deleted_paragraph = TRUE;
    }
    if (isset($field_state['entity'][$delta]->confirmed_removed) && $field_state['entity'][$delta]->confirmed_removed) {
      $confirmed_deleted_paragraph = TRUE;
    }
    if ($being_edited_paragraph || (isset($field_state['entity'][$delta]->being_edited) && $field_state['entity'][$delta]->being_edited)) {
      $being_edited_paragraph = TRUE;
    }
    else {
      $being_edited_paragraph = FALSE;
    }

    /* @var $paragraph_item ParagraphsItemEntity */
    $paragraph_item = $field_state['entity'][$delta];
    $paragraph_item->setHostEntity($element['#host_entity_type'], $element['#host_entity'], $langcode, FALSE);
  }
  else {
    if (isset($items[$delta])) {
      $paragraph_item = paragraphs_field_get_entity($items[$delta]);
    }

    // Show an empty collection if we have no existing one or it does not
    // load.
    if (empty($paragraph_item) && $bundle) {
      /* @var $paragraph_item ParagraphsItemEntity */
      $paragraph_item = entity_create('paragraphs_item', array('bundle' => $bundle, 'field_name' => $field_name));
      $paragraph_item->being_edited = TRUE;
      $being_edited_paragraph = TRUE;
      $is_new_paragraph = TRUE;
    }

    if (!empty($paragraph_item)) {
      /* @var $paragraph_item ParagraphsItemEntity */
      $paragraph_item->setHostEntity($element['#host_entity_type'], $element['#host_entity'], $langcode, FALSE);

      if ($force_open) {
        $paragraph_item->being_edited = TRUE;
        $being_edited_paragraph = TRUE;
      }

      // Put our entity in the form state, so FAPI callbacks can access it.
      $field_state['entity'][$delta] = $paragraph_item;
    }
  }
  field_form_set_state($field_parents, $field_name, $language, $form_state, $field_state);
  if (!empty($paragraph_item)) {

    $bundle_info = paragraphs_bundle_load($paragraph_item->bundle);

    if ($bundle_info) {
      $element['paragraph_bundle_title'] = array(
        '#type' => 'container',
        '#weight' => -100,
      );
      $element['paragraph_bundle_title']['info'] = array(
        '#markup' => t('@title type: %bundle', array('@title' => $instance_title, '%bundle' => $bundle_info->label)),
      );
    }

    if (!$deleted_paragraph) {
      $element['actions'] = array(
        '#type' => 'actions',
        '#weight' => 9999,
      );

      field_attach_form('paragraphs_item', $paragraph_item, $element, $form_state, $language);
      if ($being_edited_paragraph) {
        if (!$is_new_paragraph && !entity_access('update', 'paragraphs_item', $paragraph_item)) {
          foreach (element_children($element) as $key) {
            if ($key != 'paragraph_bundle_title' && $key != 'actions' && $key != 'paragraph_bundle_preview' && $key != 'access_info') {
              $element[$key]['#access'] = FALSE;
            }
          }

          $element['access_info'] = array(
            '#type' => 'container',
            '#weight' => 9998,
          );
          $element['access_info']['info'] = array(
            '#type' => 'markup',
            '#markup' => '<em>' . t('You are not allowed to edit this @title item.', array('@title' => $instance_title)) . '</em>',
          );
        }
        else {
          if (empty($element['#required'])) {
            $element['#after_build'][] = 'paragraphs_field_widget_embed_delay_required_validation';
          }
        }

        if ($default_edit_mode != 'open') {
          $element['actions']['collapse_button'] = array(
            '#delta' => $delta,
            '#name' => implode('_', $parents) . '_collapse_button',
            '#type' => 'submit',
            '#value' => t('Collapse'),
            '#validate' => array(),
            '#submit' => array('paragraphs_collapse_submit'),
            '#limit_validation_errors' => array($parents),
            '#ajax' => array(
              'callback' => '_paragraphs_ajax_update_callback',
              'effect' => 'fade',
              'wrapper' => $element['#wrapper_id'],
            ),
            '#access' => entity_access('update', 'paragraphs_item', $paragraph_item),
            '#weight' => 999,
          );
        }
      }
      else {
        if ($default_edit_mode === 'preview' && entity_access('view', 'paragraphs_item', $paragraph_item)) {
          $element['paragraph_bundle_preview'] = array(
            '#type' => 'container',
          );
          $preview = $paragraph_item->view('paragraphs_editor_preview', $langcode);
          $element['paragraph_bundle_preview']['preview'] = $preview;
        }

        foreach (element_children($element) as $key) {
          if ($key != 'paragraph_bundle_title' && $key != 'actions' && $key != 'paragraph_bundle_preview' && $key != 'access_info') {
            $element[$key]['#access'] = FALSE;
          }
        }
        $element['actions'] = array(
          '#type' => 'actions',
          '#weight' => 9999,
        );

        if (isset($field_state['entity'][$delta]->must_be_saved) && $field_state['entity'][$delta]->must_be_saved) {
          $element['actions']['must_be_saved'] = array(
            '#markup' => '<p><em>' . t('Warning: this content must be saved to reflect changes on this paragraphs item.') . '</em></p>',
            '#weight' => 998,
          );
        }

        $element['actions']['edit_button'] = array(
          '#delta' => $delta,
          '#name' => implode('_', $parents) . '_edit_button',
          '#type' => 'submit',
          '#value' => t('Edit'),
          '#validate' => array(),
          '#submit' => array('paragraphs_edit_submit'),
          '#limit_validation_errors' => array(),
          '#ajax' => array(
            'callback' => '_paragraphs_ajax_update_callback',
            'effect' => 'fade',
            'wrapper' => $element['#wrapper_id'],
          ),
          '#access' => entity_access('update', 'paragraphs_item', $paragraph_item),
          '#weight' => 999,
        );
      }

      if (isset($paragraph_item)) {
        $element['actions']['remove_button'] = array(
          '#delta' => $delta,
          '#name' => implode('_', $parents) . '_remove_button',
          '#type' => 'submit',
          '#value' => t('Remove'),
          '#validate' => array(),
          '#submit' => array('paragraphs_remove_submit'),
          '#limit_validation_errors' => array(),
          '#ajax' => array(
            'callback' => '_paragraphs_ajax_update_callback',
            'effect' => 'fade',
            'wrapper' => $element['#wrapper_id'],
          ),
          '#access' => entity_access('delete', 'paragraphs_item', $paragraph_item),
          '#weight' => 1000,
        );
      }

      if (isset($element['actions']['edit_button']) && !$element['actions']['edit_button']['#access']
          && isset($element['actions']['remove_button']) && !$element['actions']['remove_button']['#access']) {
        $element['access_info'] = array(
          '#type' => 'container',
          '#weight' => 9998,
        );
        $element['access_info']['info'] = array(
          '#type' => 'markup',
          '#markup' => '<em>' . t('You are not allowed to edit or remove this @title item.', array('@title' => $instance_title)) . '</em>',
        );
      }
      elseif (isset($element['actions']['edit_button']) && !$element['actions']['edit_button']['#access']) {
        $element['access_info'] = array(
          '#type' => 'container',
          '#weight' => 9998,
        );
        $element['access_info']['info'] = array(
          '#type' => 'markup',
          '#markup' => '<em>' . t('You are not allowed to edit this @title item.', array('@title' => $instance_title)) . '</em>',
        );
      }
      elseif (isset($element['actions']['remove_button']) && !$element['actions']['remove_button']['#access']) {
        $element['access_info'] = array(
          '#type' => 'container',
          '#weight' => 9998,
        );
        $element['access_info']['info'] = array(
          '#type' => 'markup',
          '#markup' => '<em>' . t('You are not allowed to remove this @title item.', array('@title' => $instance_title)) . '</em>',
        );
      }
    }
    else {
      $element['actions'] = array(
        '#type' => 'actions',
        '#weight' => 9999,
      );
      $element['actions']['remove_button'] = array(
        '#markup' => '<p>' . t('This @title has been removed, press the button below to restore.', array('@title' => $instance_title)) . ' </p><p><em>' . t('Warning: this @title will actually be deleted when you press "!confirm" or "!save"!', array('@title' => $instance_title, '!confirm' => t('Confirm Deletion'), '!save' => t('Save'))) . '</em></p>',
      );
      $element['actions']['restore_button'] = array(
        '#delta' => $delta,
        '#name' => implode('_', $parents) . '_restore_button',
        '#type' => 'submit',
        '#value' => t('Restore'),
        '#validate' => array(),
        '#submit' => array('paragraphs_restore_submit'),
        '#limit_validation_errors' => array(),
        '#ajax' => array(
          'callback' => '_paragraphs_ajax_update_callback',
          'effect' => 'fade',
          'wrapper' => $element['#wrapper_id'],
        ),
        '#weight' => 1000,
      );
      $element['actions']['confirm_delete_button'] = array(
        '#delta' => $delta,
        '#name' => implode('_', $parents) . '_deleteconfirm_button',
        '#type' => 'submit',
        '#value' => t('Confirm Deletion'),
        '#validate' => array(),
        '#submit' => array('paragraphs_deleteconfirm_submit'),
        '#limit_validation_errors' => array(),
        '#ajax' => array(
          'callback' => '_paragraphs_ajax_update_callback',
          'effect' => 'fade',
          'wrapper' => $element['#wrapper_id'],
        ),
        '#weight' => 1001,
      );
    }
  }

  // Hide full item when we are confirmed delete.
  if ($confirmed_deleted_paragraph) {
    $element['#access'] = FALSE;
  }

  $recursion--;
  return $element;
}

/**
 * FAPI #ajax callback to update a paragraphs item.
 */
function _paragraphs_ajax_update_callback($form, $form_state) {
  // Get the information on what we're updating.
  $button = $form_state['triggering_element'];

  // Go three levels up in the form, to the whole widget.
  $element = drupal_array_get_nested_value($form, array_slice($button['#array_parents'], 0, -3));

  // Send back the rendered element and let Drupal wrap it in an AJAX command.
  return drupal_render($element);
}

/**
 * After-build callback to validate an individual paragraphs element.
 *
 * @param array $element
 *   A form element array containing basic properties of the paragraphs element.
 * @param array $form_state
 *   An associative array containing the current state of the form.
 */
function paragraphs_field_widget_embed_delay_required_validation(array &$element, array &$form_state) {
  // If the process_input flag is set, the form and its input is going to be
  // validated. Prevent #required (sub)fields from throwing errors while
  // their non-#required paragraphs item is empty.
  if ($form_state['process_input']) {
    _paragraphs_collect_required_elements($element, $element['#paragraphs_required_elements']);
  }
  return $element;
}

/**
 * Collects all embedded required fields.
 *
 * @param array $element
 *   A form element array containing basic properties of the paragraphs element.
 * @param array|null $required_elements
 *   An array containing required paragraphs elements.
 */
function _paragraphs_collect_required_elements(array &$element, &$required_elements = array()) {
  // Recurse through all children.
  foreach (element_children($element) as $key) {
    if (isset($element[$key]) && $element[$key]) {
      _paragraphs_collect_required_elements($element[$key], $required_elements);
    }
  }
  if (!empty($element['#required'])) {
    $required_elements[] = &$element;
    $element += array('#pre_render' => array());
    array_unshift($element['#pre_render'], 'paragraphs_field_widget_render_required');
  }
}

/**
 * Pre-render callback that ensures the element is rendered as being required.
 */
function paragraphs_field_widget_render_required($element) {
  $element['#required'] = TRUE;
  return $element;
}

/**
 * FAPI validation of an individual paragraphs element.
 *
 * @param array $element
 *   A form element array containing basic properties of the paragraphs element.
 * @param array $form_state
 *   An associative array containing the current state of the form.
 * @param array $complete_form
 *   The form structure array.
 */
function paragraphs_field_widget_embed_validate(array $element, array &$form_state, array $complete_form) {
  $field_parents = $element['#field_parents'];
  $field_name = $element['#field_name'];
  $language = $element['#language'];

  $field_state = field_form_get_state($field_parents, $field_name, $language, $form_state);
  if (isset($field_state['entity'][$element['#delta']])) {
    $paragraph_item = $field_state['entity'][$element['#delta']];

    // Now validate elements if the entity is not empty.
    if (((!isset($paragraph_item->removed) || !$paragraph_item->removed) && (!isset($paragraph_item->confirmed_removed) || !$paragraph_item->confirmed_removed))) {

      // Attach field API validation of the embedded form.
      field_attach_form_validate('paragraphs_item', $paragraph_item, $element, $form_state);

      if (!empty($element['#paragraphs_required_elements'])) {
        foreach ($element['#paragraphs_required_elements'] as &$elements) {

          // Copied from _form_validate().
          if (isset($elements['#needs_validation'])) {
            $is_countable = is_array($elements['#value']) || $elements['#value'] instanceof Countable;
            $is_empty_multiple = $is_countable && (!count($elements['#value']));
            $is_empty_string = (is_string($elements['#value']) && drupal_strlen(trim($elements['#value'])) == 0);
            $is_empty_value = ($elements['#value'] === 0);
            if ($is_empty_multiple || $is_empty_string || $is_empty_value) {
              if (isset($elements['#title'])) {
                $error_text = t('!name field is required.', array('!name' => $elements['#title']));
                form_error($elements, filter_xss_admin($error_text));
              }
              else {
                form_error($elements);
              }
            }
          }
        }
      }
    }

    // Only if the form is being submitted, finish the collection entity and
    // prepare it for saving.
    if ($form_state['submitted']) {
      $errors = form_get_errors();
      if (module_exists('conditional_fields') && isset($form_state['conditional_fields_untriggered_dependents'])) {
        // Conditional_fields will remove errors which occurred on "untriggered
        // fields" and only remove them via the form-level validation handlers.
        foreach ($form_state['conditional_fields_untriggered_dependents'] as $conditional_error) {
          if (isset($conditional_error['errors'])) {
            foreach ($conditional_error['errors'] as $key => $error) {
              unset($errors[$key]);
            }
          }
        }
      }

      if (!$errors) {
        field_attach_submit('paragraphs_item', $paragraph_item, $element, $form_state);

        // Load initial form values into $item, so any other form values below
        // the same parents are kept.
        $item = drupal_array_get_nested_value($form_state['values'], $element['#parents']);

        // Set the _weight if it is a multiple field.
        if (isset($element['_weight'])) {
          $item['_weight'] = $element['_weight']['#value'];
        }

        // Put the paragraphs item in $item['entity'], so it is saved with
        // the host entity via hook_field_presave() if it is not empty.
        // @see paragraph_field_presave()
        $item['entity'] = $paragraph_item;
        form_set_value($element, $item, $form_state);
      }

    }
  }
}

/**
 * Submit function to add another paragraph.
 *
 * @param array $form
 *   The form structure array.
 * @param array $form_state
 *   An associative array containing the current state of the form.
 */
function paragraphs_add_more_submit(array $form, array &$form_state) {
  $button = $form_state['triggering_element'];

  // Go one level up in the form, to the widgets container.
  $element = drupal_array_get_nested_value($form, array_slice($button['#array_parents'], 0, -2));
  $field_name = $element['#field_name'];
  $langcode = $element['#language'];
  $parents = $element['#field_parents'];

  // Increment the items count.
  $field_state = field_form_get_state($parents, $field_name, $langcode, $form_state);

  $field = $field_state['field'];

  if ($field['cardinality'] == FIELD_CARDINALITY_UNLIMITED || $field_state['real_items_count'] < $field['cardinality']) {
    $field_state['items_count']++;
  }

  field_form_set_state($parents, $field_name, $langcode, $form_state, $field_state);

  $form_state['rebuild'] = TRUE;
}

/**
 * Form Validation for submitting a node with required paragraphs fields.
 */
function _paragraphs_multiple_field_validate($elements, &$form_state) {
  // Check child fields of required paragraphs.
  if (!empty($elements['#required'])) {
    $field_values = array();
    $field_state = field_form_get_state($elements['#field_parents'], $elements['#field_name'], $elements['#language'], $form_state);
    $field_info = field_info_field($elements['#field_name']);

    if (empty($elements['#parents'])) {
      // Try top level structure if there are no parents.
      if (!empty($form_state['values'][$elements['#field_name']][LANGUAGE_NONE])) {
        $field_values = $form_state['values'][$elements['#field_name']][LANGUAGE_NONE];
      }
    }
    else {
      // Extract field values.
      $key_exists = NULL;
      $field_values_found = drupal_array_get_nested_value($form_state['values'], $elements['#parents'], $key_exists);
      if ($key_exists) {
        $field_values = $field_values_found;
      }
    }

    if ($field_values) {
      foreach (array_keys($field_values) as $item_key) {
        if (!is_numeric($item_key)) {
          // Remove non field item deltas.
          unset($field_values[$item_key]);
        }
        elseif (isset($field_state['entity'][$item_key])) {
          // Handle field item entity forms that build new objects in the field
          // state. Examples: field_collection_item, paragraphs_item.
          // If this is not set, then the field_is_empty check in
          // _field_filter_items() fails.
          $field_values[$item_key] = array(
            'entity' => $field_state['entity'][$item_key],
          );
        }
      }

      // Get non-empty items.
      $field_values = _field_filter_items($field_info, $field_values);
    }

    if (count($field_values) < 1) {
      form_error($elements, t('The "!name" field is required', array(
        '!name' => $elements['#title'],
      )));
    }
  }
}

/**
 * Ajax callback in response to a new empty widget being added to the form.
 *
 * This returns the new page content to replace the page content made obsolete
 * by the form submission.
 *
 * @param array $form
 *   The form structure array.
 * @param array $form_state
 *   An associative array containing the current state of the form.
 *
 * @see field_add_more_submit()
 */
function paragraphs_add_more_js(array $form, array $form_state) {
  $button = $form_state['triggering_element'];

  // Go one level up in the form, to the widgets container.
  $element = drupal_array_get_nested_value($form, array_slice($button['#array_parents'], 0, -2));

  // Add a DIV around the delta receiving the Ajax effect.
  $delta = $element['#max_delta'];
  $element[$delta]['#prefix'] = '<div class="ajax-new-content">' . (isset($element[$delta]['#prefix']) ? $element[$delta]['#prefix'] : '');
  $element[$delta]['#suffix'] = (isset($element[$delta]['#suffix']) ? $element[$delta]['#suffix'] : '') . '</div>';

  return $element;
}

/**
 * Submit callback to remove an item from the field UI multiple wrapper.
 *
 * When a remove button is submitted, we need to find the item that it
 * referenced and delete it. Since field UI has the deltas as a straight
 * unbroken array key, we have to renumber everything down. Since we do this
 * we *also* need to move all the deltas around in the $form_state['values']
 * and $form_state['input'] so that user changed values follow. This is a bit
 * of a complicated process.
 *
 * @param array $form
 *   The form structure array.
 * @param array $form_state
 *   An associative array containing the current state of the form.
 */
function paragraphs_remove_submit(array $form, array &$form_state) {
  $button = $form_state['triggering_element'];
  $delta = $button['#delta'];

  // Where in the form we'll find the parent element.
  $address = array_slice($button['#array_parents'], 0, -3);

  // Go one level up in the form, to the widgets container.
  $parent_element = drupal_array_get_nested_value($form, $address);
  $field_name = $parent_element['#field_name'];
  $langcode = $parent_element['#language'];
  $parents = $parent_element['#field_parents'];

  $field_state = field_form_get_state($parents, $field_name, $langcode, $form_state);

  if (isset($field_state['entity'][$delta])) {
    $field_state['entity'][$delta]->removed = 1;
  }

  // Fix the weights. Field UI lets the weights be in a range of
  // (-1 * item_count) to (item_count). This means that when we remove one,
  // the range shrinks; weights outside of that range then get set to
  // the first item in the select by the browser, floating them to the top.
  // We use a brute force method because we lost weights on both ends
  // and if the user has moved things around, we have to cascade because
  // if I have items weight weights 3 and 4, and I change 4 to 3 but leave
  // the 3, the order of the two 3s now is undefined and may not match what
  // the user had selected.
  $input = drupal_array_get_nested_value($form_state['input'], $address);
  // Sort by weight,
  // but first remove garbage values to ensure proper '_weight' sorting.
  unset($input['add_more']);
  uasort($input, '_field_sort_items_helper');

  // Reweight everything in the correct order.
  $weight = -1 * $field_state['items_count'] + 1;
  foreach ($input as $key => $item) {
    if ($item) {
      $input[$key]['_weight'] = $weight++;
    }
  }

  drupal_array_set_nested_value($form_state['input'], $address, $input);
  field_form_set_state($parents, $field_name, $langcode, $form_state, $field_state);

  $form_state['rebuild'] = TRUE;
}

/**
 * Submit callback to editing an item from the field UI multiple wrapper.
 *
 * When a edited button is submitted, we need to find the item that it
 * referenced and delete it. Since field UI has the deltas as a straight
 * unbroken array key, we have to renumber everything down. Since we do this
 * we *also* need to move all the deltas around in the $form_state['values']
 * and $form_state['input'] so that user changed values follow. This is a bit
 * of a complicated process.
 *
 * @param array $form
 *   The form structure array.
 * @param array $form_state
 *   An associative array containing the current state of the form.
 */
function paragraphs_edit_submit(array $form, array &$form_state) {
  $button = $form_state['triggering_element'];
  $delta = $button['#delta'];

  // Where in the form we'll find the parent element.
  $address = array_slice($button['#array_parents'], 0, -3);

  // Go one level up in the form, to the widgets container.
  $parent_element = drupal_array_get_nested_value($form, $address);
  $field_name = $parent_element['#field_name'];
  $langcode = $parent_element['#language'];
  $parents = $parent_element['#field_parents'];

  $field_state = field_form_get_state($parents, $field_name, $langcode, $form_state);

  if (isset($field_state['entity'][$delta])) {
    $field_state['entity'][$delta]->being_edited = 1;
  }

  // Fix the weights. Field UI lets the weights be in a range of
  // (-1 * item_count) to (item_count). This means that when we remove one,
  // the range shrinks; weights outside of that range then get set to
  // the first item in the select by the browser, floating them to the top.
  // We use a brute force method because we lost weights on both ends
  // and if the user has moved things around, we have to cascade because
  // if I have items weight weights 3 and 4, and I change 4 to 3 but leave
  // the 3, the order of the two 3s now is undefined and may not match what
  // the user had selected.
  $input = drupal_array_get_nested_value($form_state['input'], $address);
  // Sort by weight,
  // but first remove garbage values to ensure proper '_weight' sorting.
  unset($input['add_more']);
  uasort($input, '_field_sort_items_helper');

  // Reweight everything in the correct order.
  $weight = -1 * $field_state['items_count'] + 1;
  foreach ($input as $key => $item) {
    if ($item) {
      $input[$key]['_weight'] = $weight++;
    }
  }

  drupal_array_set_nested_value($form_state['input'], $address, $input);
  field_form_set_state($parents, $field_name, $langcode, $form_state, $field_state);

  $form_state['rebuild'] = TRUE;
}

/**
 * Submit callback to collapse an item from the field UI multiple wrapper.
 *
 * When a collapse button is submitted, we need to find the item that it
 * referenced and delete it. Since field UI has the deltas as a straight
 * unbroken array key, we have to renumber everything down. Since we do this
 * we *also* need to move all the deltas around in the $form_state['values']
 * and $form_state['input'] so that user changed values follow. This is a bit
 * of a complicated process.
 *
 * @param array $form
 *   The form structure array.
 * @param array $form_state
 *   An associative array containing the current state of the form.
 */
function paragraphs_collapse_submit(array $form, array &$form_state) {
  $button = $form_state['triggering_element'];
  $delta = $button['#delta'];

  // Where in the form we'll find the parent element.
  $address = array_slice($button['#array_parents'], 0, -3);

  // Go one level up in the form, to the widgets container.
  $parent_element = drupal_array_get_nested_value($form, $address);
  $field_name = $parent_element['#field_name'];
  $langcode = $parent_element['#language'];
  $parents = $parent_element['#field_parents'];

  $field_state = field_form_get_state($parents, $field_name, $langcode, $form_state);

  if (isset($field_state['entity'][$delta])) {
    $field_state['entity'][$delta]->being_edited = 0;
    $field_state['entity'][$delta]->must_be_saved = 1;
  }

  // Fix the weights. Field UI lets the weights be in a range of
  // (-1 * item_count) to (item_count). This means that when we remove one,
  // the range shrinks; weights outside of that range then get set to
  // the first item in the select by the browser, floating them to the top.
  // We use a brute force method because we lost weights on both ends
  // and if the user has moved things around, we have to cascade because
  // if I have items weight weights 3 and 4, and I change 4 to 3 but leave
  // the 3, the order of the two 3s now is undefined and may not match what
  // the user had selected.
  $input = drupal_array_get_nested_value($form_state['input'], $address);
  // Sort by weight,
  // but first remove garbage values to ensure proper '_weight' sorting.
  unset($input['add_more']);
  uasort($input, '_field_sort_items_helper');

  // Reweight everything in the correct order.
  $weight = -1 * $field_state['items_count'] + 1;
  foreach ($input as $key => $item) {
    if ($item) {
      $input[$key]['_weight'] = $weight++;
    }
  }

  drupal_array_set_nested_value($form_state['input'], $address, $input);
  field_form_set_state($parents, $field_name, $langcode, $form_state, $field_state);

  $form_state['rebuild'] = TRUE;
}

/**
 * Submit callback to remove an item from the field UI multiple wrapper.
 *
 * When a remove button is submitted, we need to find the item that it
 * referenced and delete it. Since field UI has the deltas as a straight
 * unbroken array key, we have to renumber everything down. Since we do this
 * we *also* need to move all the deltas around in the $form_state['values']
 * and $form_state['input'] so that user changed values follow. This is a bit
 * of a complicated process.
 *
 * @param array $form
 *   The form structure array.
 * @param array $form_state
 *   An associative array containing the current state of the form.
 */
function paragraphs_deleteconfirm_submit(array $form, array &$form_state) {
  $button = $form_state['triggering_element'];
  $delta = $button['#delta'];

  // Where in the form we'll find the parent element.
  $address = array_slice($button['#array_parents'], 0, -3);

  // Go one level up in the form, to the widgets container.
  $parent_element = drupal_array_get_nested_value($form, $address);
  $field_name = $parent_element['#field_name'];
  $langcode = $parent_element['#language'];
  $parents = $parent_element['#field_parents'];

  $field_state = field_form_get_state($parents, $field_name, $langcode, $form_state);

  if (isset($field_state['entity'][$delta])) {
    $field_state['entity'][$delta]->removed = 1;
    $field_state['entity'][$delta]->confirmed_removed = 1;
  }

  // Fix the weights. Field UI lets the weights be in a range of
  // (-1 * item_count) to (item_count). This means that when we remove one,
  // the range shrinks; weights outside of that range then get set to
  // the first item in the select by the browser, floating them to the top.
  // We use a brute force method because we lost weights on both ends
  // and if the user has moved things around, we have to cascade because
  // if I have items weight weights 3 and 4, and I change 4 to 3 but leave
  // the 3, the order of the two 3s now is undefined and may not match what
  // the user had selected.
  $input = drupal_array_get_nested_value($form_state['input'], $address);
  // Sort by weight,
  // but first remove garbage values to ensure proper '_weight' sorting.
  unset($input['add_more']);
  uasort($input, '_field_sort_items_helper');

  // Reweight everything in the correct order.
  $weight = -1 * $field_state['items_count'] + 1;
  foreach ($input as $key => $item) {
    if ($item) {
      $input[$key]['_weight'] = $weight++;
    }
  }

  drupal_array_set_nested_value($form_state['input'], $address, $input);
  field_form_set_state($parents, $field_name, $langcode, $form_state, $field_state);

  $form_state['rebuild'] = TRUE;
}

/**
 * Submit function to restore a paragraphs item that was deleted.
 *
 * @param array $form
 *   The form structure array.
 * @param array $form_state
 *   An associative array containing the current state of the form.
 */
function paragraphs_restore_submit(array $form, array &$form_state) {
  $button = $form_state['triggering_element'];
  $delta = $button['#delta'];

  // Where in the form we'll find the parent element.
  $address = array_slice($button['#array_parents'], 0, -3);

  // Go one level up in the form, to the widgets container.
  $parent_element = drupal_array_get_nested_value($form, $address);
  $field_name = $parent_element['#field_name'];
  $langcode = $parent_element['#language'];
  $parents = $parent_element['#field_parents'];

  $field_state = field_form_get_state($parents, $field_name, $langcode, $form_state);

  if (isset($field_state['entity'][$delta])) {
    $field_state['entity'][$delta]->removed = 0;
  }

  // Fix the weights. Field UI lets the weights be in a range of
  // (-1 * item_count) to (item_count). This means that when we remove one,
  // the range shrinks; weights outside of that range then get set to
  // the first item in the select by the browser, floating them to the top.
  // We use a brute force method because we lost weights on both ends
  // and if the user has moved things around, we have to cascade because
  // if I have items weight weights 3 and 4, and I change 4 to 3 but leave
  // the 3, the order of the two 3s now is undefined and may not match what
  // the user had selected.
  $input = drupal_array_get_nested_value($form_state['input'], $address);
  // Sort by weight,
  // but first remove garbage values to ensure proper '_weight' sorting.
  unset($input['add_more']);
  uasort($input, '_field_sort_items_helper');

  // Reweight everything in the correct order.
  $weight = -1 * $field_state['items_count'] + 1;
  foreach ($input as $key => $item) {
    if ($item) {
      $input[$key]['_weight'] = $weight++;
    }
  }

  drupal_array_set_nested_value($form_state['input'], $address, $input);
  field_form_set_state($parents, $field_name, $langcode, $form_state, $field_state);

  $form_state['rebuild'] = TRUE;
}
