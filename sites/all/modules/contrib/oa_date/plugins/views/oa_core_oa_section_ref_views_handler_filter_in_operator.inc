<?php

/**
 * @file
 * Code to override field to add in auto option.
 */

class oa_core_oa_section_ref_views_handler_filter_in_operator extends views_handler_filter_in_operator {
  function init(&$view, &$options) {
    parent::init($view, $options);
    if ($this->options['exposed']) {
      $exposed_options = array_filter($this->options['expose']);
      $id = !empty($exposed_options['identifier']) ?  $exposed_options['identifier'] : 'oa_section_ref';
      if (empty($exposed_options['oa_core_no_auto'])) {
        $exposed = $this->view->get_exposed_input();
        if (isset($exposed[$id]) && empty($exposed[$id])) {
          $section = oa_core_get_section_context();
          if (($node = menu_get_object()) && $node->type == 'oa_space') {
            $section = NULL;
          }
          if ($section) {
            $exposed[$id] = $section;
          }
          else {
            unset($exposed[$id]);
          }
          $this->view->set_exposed_input($exposed);
        }
      }
      $exposed = $this->view->get_exposed_input();
      // Remove section value if section not in group.
      if (!empty($id) && !empty($exposed[$id]) && is_numeric($exposed[$id]) &&
        !empty($exposed['og_group_ref_target_id']) &&
        ($section = node_load($exposed[$id])) && isset($section->{OA_SPACE_FIELD}[LANGUAGE_NONE][0]['target_id']) &&
        $section->{OA_SPACE_FIELD}[LANGUAGE_NONE][0]['target_id'] != $exposed['og_group_ref_target_id']) {
        // See if section of same name exists in current space
        if (module_exists('oa_subspaces')) {
          $extra_sections = oa_subspaces_matching_sections($exposed[$id], array($exposed['og_group_ref_target_id']), array());
          if (!empty($extra_sections)) {
            $exposed[$id] = current($extra_sections);
            $this->view->set_exposed_input($exposed);
            return;
          }
        }
        unset($exposed[$id]);
        $this->view->set_exposed_input($exposed);
      }
    }
  }
}
