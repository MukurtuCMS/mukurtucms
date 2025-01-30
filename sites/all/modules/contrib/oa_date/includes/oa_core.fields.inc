<?php
/**
 * @file
 * Code for custom Form API fields in Open Atrium
 */

/**
 * Implements hook_element_info().
 */
function oa_core_element_info() {
  return array(
    'og_group_ref' => array(
      '#input' => TRUE,
      '#process' => array('oa_core_og_group_ref_process', 'ajax_process_form'),
    ),
    'oa_section_ref' => array(
      '#input' => TRUE,
      '#process' => array('oa_core_oa_section_ref_process', 'ajax_process_form'),
    ),
  );
}

/**
 * Process function of the og_group_ref field.
 */
function oa_core_og_group_ref_process($element, &$form_state, &$complete_form) {
  global $user;
  $element += array(
    '#title' => t('Space'),
    '#description' => t('Select a space'),
  );
  if (empty($element['#use_select'])) {
    // Below is mocking what og/select2widget does so it thinks this is a
    // select2 element.
    $field = field_info_field('og_group_ref');
    $type = 'select2widgetajax';
    $required = !empty($element['#required']);
    $has_value = !empty($element['#default_value']);
    $instance = _oa_core_get_og_group_ref_mocked_field_instance();
    $settings = $instance['widget']['settings'];
    $id = 'NULL';
    $entity_labels = _oa_core_select2widget_process_entity_labels($element['#default_value']);
    $autocomplete_path = (!empty($element['#allow_current']) ? 'oacoreselect2widgetpanes' : 'oacoreselect2widget') . '/ajax/' . $field['field_name'] . '/' . $instance['entity_type'] . '/' . $instance['bundle'] . '/' . $id . '?field_mode=all';
    $element = array(
      '#type' => 'textfield',
      '#default_value' => implode(',', $entity_labels),
      '#autocomplete_path' => $autocomplete_path,
      '#element_validate' => array('oa_core_select2widget_entity_validate_field'),
      '#settings' => $instance['widget']['settings'],
      '#maxlength' => 1024,
      '#init' => $entity_labels,
      '#field_name' => 'og_group_ref',
      '#language' => LANGUAGE_NONE,
      '#bundle' => $instance['bundle'],
      '#entity_type' => 'node',
      '#field' => $field,
      '#field_parents' => array(),
    ) + $element;
    if (!empty($element['#multiple'])) {
      $element['#field']['cardinality'] = FIELD_CARDINALITY_UNLIMITED;
    }
    $element['#settings']['select2widgetajax']['width'] = '300px';
    $element['#settings']['select2widgetajax']['min_char'] = 0;
    $form_state['field'][$element['#field_name']][$element['#language']]['field'] = $field;
    $element = oa_core_exposed_og_group_ref_fix_cardinality($element, $form_state, $complete_form);
    $element = select2widget_entity_process_callback($element, $form_state, $complete_form);
  }
  else {
    $element['#type'] = 'select';
    $element['#options'][-1] = t(' - Current Space - ');
    if (empty($element['#required'])) {
      $element['#options'][0] = t(' - Any - ');
    }
    if (($groups = oa_core_get_groups_by_user($user, 'node')) && ($titles = oa_core_get_titles($groups, '', 'title', array('title'), TRUE, 100))) {
      $element['#options'] += $titles['titles'];
    }
  }
  $element += element_info($element['#type']);
  return $element;
}

/**
 * Set the field settings for select2widget_entity_process_callback.
 *
 * Due to how panes work, the form_state isn't preserved so we add this in here.
 */
function oa_core_exposed_og_group_ref_fix_cardinality($element, &$form_state, $form) {
  $form_state['field'][$element['#field_name']][$element['#language']]['field'] = $element['#field'];
  return $element;
}

/**
 * Validate the entities as real, including custom all/current.
 */
function oa_core_select2widget_entity_validate_field(&$element, &$form_state, $form) {
  // Legacy support, empty means current.
  if (!empty($element['#convert_empty_to_current']) && empty($element['#value'])) {
    // If filter is on an admin view or user view, default to show All spaces
    if ((isset($form_state['view']->tag) && ($form_state['view']->tag == 'admin')) ||
      isset($form_state['view']->argument['user'])) {
      $element['#value'] = _oa_core_select2widget_all_label();
    }
    else {
      $element['#value'] = OA_SPACE_CURRENT;
    }
  }
  if (empty($element['#oa_core_in_pane_config'])) {
    $element['#value'] = str_replace(OA_SPACE_CURRENT, oa_core_get_space_context(), $element['#value']);
    $element['#value'] = str_replace(_oa_core_select2widget_current_label(), oa_core_get_space_context(), $element['#value']);
  }
  $element['#value'] = str_replace(_oa_core_select2widget_all_label(), 'All', $element['#value']);
  $entity_labels = _oa_core_select2widget_process_entity_labels($element['#value']);
  $element['#attached']['js'][0]['data']['select2widgetajax']['elements'][$element['#id']]['init'] = $entity_labels;
  if (!empty($element['#oa_core_select2_set_value']) && $entity_labels && isset($form_state['values'])) {
    $value = array_keys($entity_labels);
    form_set_value($element, current($value), $form_state);
  }
}

/**
 * Turn the current values to labels for select2 init/default value.
 */
function _oa_core_select2widget_process_entity_labels($value) {
  $target_entities = is_array($value) ? $value : explode(',', $value);
  $entity_labels = array();
  foreach ($target_entities as &$target_entity) {
    if (is_numeric($target_entity)) {
      $entity = entity_load_single('node', $target_entity);
      if (entity_load_single('node', $target_entity)) {
        $label = entity_label('node', $entity);
        $key = "$label - $target_entity";
        // Labels containing commas or quotes must be wrapped in quotes.
        if (strpos($key, ',') !== FALSE || strpos($key, '"') !== FALSE) {
          $key = '"' . str_replace('"', '""', $key) . '"';
        }
        $entity_labels[$target_entity] = $key;
      }
    }
    elseif (preg_match("/.+\((\d+)\)/", $target_entity, $matches)) {
      $entity_labels[$matches[1]] = check_plain($target_entity);
    }
    elseif ($target_entity == 'All') {
      $entity_labels['All'] = _oa_core_select2widget_all_label();
    }
    elseif ($target_entity == OA_SPACE_CURRENT || $target_entity = _oa_core_select2widget_current_label()) {
      $entity_labels[OA_SPACE_CURRENT] = _oa_core_select2widget_current_label();
    }
  }
  return $entity_labels;
}

/**
 * Process function of the oa_section_ref field.
 */
function oa_core_oa_section_ref_process($element, &$form_state, &$complete_form) {
  global $user;
  $element['#type'] = 'select';
  $element += array(
    '#title' => t('Section'),
    '#description' => t('Select a Section'),
  );
  $element['#options'][-1] = t(' - Current Section - ');
  if (empty($element['#required'])) {
    $element['#options'][0] = t(' - Any - ');
  }
  if (!isset($element['#default_value'])) {
    $element['#default_value'] = !empty($element['#multiple']) ? array(-1) : -1;
  }
  $element += element_info('select');

  $group_ref_key = NULL;
  if (isset($element['#og_group_ref'])) {
    if (!empty($element['#og_group_ref'])) {
      $group_ref = !is_array($element['#og_group_ref']) ? array($element['#og_group_ref']) : $element['#og_group_ref'];
      $group_ref_key = implode('--', $group_ref);
      $value = drupal_array_get_nested_value($form_state['input'], $group_ref);
      if (is_null($value)) {
        $value = drupal_array_get_nested_value($form_state['values'], $group_ref);
      }
    }
    else {
      $value = -1;
    }
    // Gid == 0 is no group.
    $gid = isset($value) && ($value === 0 || $value != -1) ? $value : oa_core_get_space_context();
    // Add options based on current selected group.
    if ($gid && $sections = oa_core_space_sections($gid, NODE_PUBLISHED, NULL, array(), TRUE)) {
      foreach($sections as $nid => $title) {
        $element['#options'][$nid] = check_plain($title);
      }
    }

    // Since IDs change with ajax (to be unique), need a static id for wrappers.
    $element['#ajax_id'] = isset($form_state['oa_section_ref_replace'][$group_ref_key]['id']) ?
      $form_state['oa_section_ref_replace'][$group_ref_key]['id'] : $element['#id'];
    $element['#prefix'] = '<div id="' . $element['#ajax_id'] . '-replace">';
    $element['#suffix'] = '</div>';

    if (!empty($group_ref_key)) {
      // Add wrapper to replace via ajax.
      // Find the group element and add ajax processing to it.
      $group_element = &_oa_core_oa_section_ref_process_find_element($complete_form, $group_ref);
      $group_element['#ajax'] = array(
        'callback' => 'oa_core_oa_section_ref_replace',
        'wrapper' => $element['#ajax_id'] . '-replace',
        'method' => 'replace',
        'effect' => 'fade',
        'event' => 'change',
      );
    }
    if (arg(0) == 'panels' && strpos($_GET['q'], 'ajax')) {
      $group_element['#ajax']['path'] = 'system/panopoly-magic';
    }
    // Add a message area to see messages.
    $group_element['messages'] = array(
      '#tag' => 'div',
      '#value' => '',
      '#attributes' => array(
        'id' => $element['#ajax_id'] . '-messages',
      ),
      '#type' => 'html_tag',
      '#weight' => -100,
    );
    // Store information about this replacement for the ajax callback.
    if (!isset($form_state['oa_section_ref_replace'][$group_ref_key])) {
      $form_state['oa_section_ref_replace'][$group_ref_key]['parents'] = $element['#parents'];
      $form_state['oa_section_ref_replace'][$group_ref_key]['id'] = $element['#ajax_id'];
    }
    // Because we are altering an already processed form element, need to redo.
    unset($group_element['#ajax_processed']);
    $group_element = ajax_process_form($group_element, $form_state);
    if (!empty($form_state['triggering_element']) && $form_state['triggering_element']['#parents'] == $group_ref) {
      $form_state['triggering_element'] = $group_element;
    }
  }

  // Make sure if ajax with change group, invalid sections are forgotten.
  $values = is_array($element['#value']) ? $element['#value'] : array($element['#value']);
  foreach ($values as $key => $value) {
    if (empty($element['#options'][$value])) {
      unset($values[$key]);
    }
  }
  if (empty($values)) {
    $element['#value'] = !empty($element['#multiple']) ? array(-1) : -1;
  }
  else {
    $element['#value'] = !empty($element['#multiple']) ? $values : reset($values);
  }

  // Allow standard select processing (allows use of #multiple)
  $element = form_process_select($element);

  return $element;
}

/**
 * Ajax callback to return the section field.
 */
function oa_core_oa_section_ref_replace($form, $form_state) {
  $field_name_triggering = implode('--', $form_state['triggering_element']['#parents']);

  $return = array(
    '#type' => 'ajax',
    '#commands' => array(),
  );
  $group_element = &_oa_core_oa_section_ref_process_find_element($form, $form_state['triggering_element']['#parents']);

  if ($messages = theme('status_messages')) {
    $selector = '#' . $group_element['messages']['#attributes']['id'];
    $html = '<div class="views-messages">' . $messages . '</div>';
    $return['#commands'][] = ajax_command_replace($selector, $html);
  }
  if (!isset($form_state['oa_section_ref_replace'][$field_name_triggering])) {
    return $return;
  }
  // Replace the section element.
  $section_element = &_oa_core_oa_section_ref_process_find_element($form, $form_state['oa_section_ref_replace'][$field_name_triggering]['parents']);
  $return['#commands'][] = ajax_command_replace('#' . $section_element['#ajax_id'] . '-replace', render($section_element));
  return $return;
}

/**
 * Find the element based on tree parents.
 */
function &_oa_core_oa_section_ref_process_find_element(&$form, $parents) {
  foreach (element_children($form) as $key) {
    if (isset($form[$key]['#parents']) && $form[$key]['#parents'] === $parents) {
      $element = &$form[$key];
      return $element;
    }
    if ($element = &_oa_core_oa_section_ref_process_find_element($form[$key], $parents)) {
      return $element;
    }
  }
  $element = NULL;
  return $element;
}

/**
 * Menu callback for testing th oa_core system fields.
 */
function oa_core_element_test_page() {
  return drupal_get_form('oa_core_test_form');
}

/**
 * Form callback for testing th oa_core system fields.
 */
function oa_core_test_form() {
  $form = array();

  $form['test_element'] = array(
    '#type' => 'og_group_ref',
  );
  $form['test_element_2'] = array(
    '#og_group_ref' => 'test_element',
    '#type' => 'oa_section_ref',
  );

  return $form;
}

/**
 * Return an instance to be used to mock the field.
 */
function _oa_core_get_og_group_ref_mocked_field_instance() {
  $instances = field_read_instances(array('field_name' => 'og_group_ref'));
  $field_mode = 'default';
  foreach ($instances as $instance) {
    if (isset($instance['settings']['behaviors']['og_widget'][$field_mode]['widget_settings']['select2widgetajax'])) {
      break;
    }
  }
  return og_get_mocked_instance($instance, 'default');
}
