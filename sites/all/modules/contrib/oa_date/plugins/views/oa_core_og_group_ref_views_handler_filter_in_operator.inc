<?php

/**
 * @file
 * Code to override field to add in auto option.
 */

class oa_core_og_group_ref_views_handler_filter_in_operator extends views_handler_filter_in_operator {

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

  function exposed_form(&$form, &$form_state) {
    parent::exposed_form($form, $form_state);
    global $user;
    $exposed = $this->view->get_exposed_input();
    // just call OG for spaces, we don't care about subspaces
    // really we just need a count, but at least this doesn't load every space
    $groups = og_get_groups_by_user($user, 'node');
    if (($id = $this->options['expose']['identifier']) && $groups && !empty($form[$id]['#options']) && array_intersect_key($groups, $form[$id]['#options'])) {
      $form[$id . '_mine'] = array(
        '#title' => t('My Spaces'),
        '#default_value' => 0,
        '#type' => 'checkbox',
      );
      if (!empty($exposed[$id . '_mine'])) {
        $form[$id]['#access'] = FALSE;
        // Need to set it here else the value is ignored when access is FALSE.
        if (!empty($exposed[$id])) {
          $form[$id]['#value'] = $exposed[$id];
        }
      }
    }
  }

}
