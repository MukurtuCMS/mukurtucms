<?php

/**
 * @file
 * Code to override field to add in auto option.
 */

class oa_core_og_group_ref_views_handler_filter_entityreference_autocomplete extends views_handler_filter_entityreference_autocomplete {

  private $fail_build = FALSE;

  function init(&$view, &$options) {
    parent::init($view, $options);
    $this->fail_build = !oa_core_process_exposed_group_input($this);
  }

  function query() {
    parent::query();
    if (!empty($this->fail_build)) {
      $this->view->build_info['fail'] = TRUE;
    }
  }

  function value_form(&$form, &$form_state) {
    $saved_value = $this->value;
    $this->value = array();
    parent::value_form($form, $form_state);
    $field = field_info_field('og_group_ref');
    $value_key = key($field['columns']);

    // Below is mocking what og/select2widget does so it thinks this is a
    // select2 element.
    $type = 'select2widgetajax';
    $required = !empty($form['value']['#required']);
    $instance = _oa_core_get_og_group_ref_mocked_field_instance();
    $settings = $instance['widget']['settings'];
    $id = 'NULL';
    $admin_form = !empty($form_state['form_id']) && $form_state['form_id'] == 'views_ui_config_item_form';
    $autocomplete_path = ($admin_form ? 'oacoreselect2widgetpanes' : 'oacoreselect2widget') .'/ajax/' . $field['field_name'] . '/' . $instance['entity_type'] . '/' . $instance['bundle'] . '/' . $id . '?field_mode=all';

    if (variable_get('oa_core_group_reference_default_current', TRUE)) {
      $entity_labels = is_string($saved_value) ? _oa_core_select2widget_process_entity_labels($saved_value) : array();
      $default_value = $saved_value == OA_SPACE_CURRENT ? OA_SPACE_CURRENT : implode(', ', $entity_labels);
    }
    else {
      $default_value = _oa_core_select2widget_all_label();
    }

    $form['value'] = array(
      '#type' => 'textfield',
      '#default_value' => $default_value,
      '#autocomplete_path' => $autocomplete_path,
      '#element_validate' => array('oa_core_select2widget_entity_validate_field'),
      '#settings' => $instance['widget']['settings'],
      '#process' => array('oa_core_exposed_og_group_ref_fix_cardinality', 'select2widget_entity_process_callback', 'ajax_process_form'),
      '#maxlength' => 1024,
      '#init' => $entity_labels,
      '#field_name' => 'og_group_ref',
      '#language' => LANGUAGE_NONE,
      '#bundle' => $instance['bundle'],
      '#entity_type' => 'node',
      '#field' => $field,
      '#field_parents' => array(),
      '#convert_empty_to_current' => variable_get('oa_core_group_reference_default_current', TRUE),
      '#oa_core_select2_set_value' => TRUE,
    ) + $form['value'];
    $form['value']['#settings']['select2widgetajax']['min_char'] = 0;
    $form_state['field'][$form['value']['#field_name']][$form['value']['#language']]['field'] = $field;
  }

  function exposed_form(&$form, &$form_state) {
    parent::exposed_form($form, $form_state);
    global $user;
    $exposed = $this->view->get_exposed_input();
    // just call OG for spaces, we don't care about subspaces
    // really we just need a count, but at least this doesn't load every space
    $full_user = user_load($user->uid);
    $groups = field_get_items('user', $full_user, 'og_user_node');
    // check is to check if part of any spaces.
    if (($id = $this->options['expose']['identifier']) && $groups) {
      $form[$id . '_mine'] = array(
        '#title' => t('My Spaces'),
        '#default_value' => 0,
        '#type' => 'checkbox',
      );
      if (!empty($exposed[$id . '_mine'])) {
        $form[$id]['#access'] = FALSE;
        // Need to set it here else the value is ignored when access is FALSE.
        if (!empty($exposed[$id])) {
          $form[$id] = array(
            '#type' => 'value',
            '#value' =>  $exposed[$id],
          );
        }
      }
    }
  }

  function exposed_validate(&$form, &$form_state) {
    if (empty($this->options['exposed'])) {
      return;
    }

    if (empty($this->options['expose']['identifier'])) {
      return;
    }

    $identifier = $this->options['expose']['identifier'];
    if (!empty($form_state['values'][$identifier])) {
      $this->validated_exposed_input = $form_state['values'][$identifier];
    }
  }
}
