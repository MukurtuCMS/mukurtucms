<?php

/**
 * @file
 * Definition of views_handler_argument_numeric.
 */

/**
 * Basic argument handler for arguments that are numeric. Incorporates
 * break_phrase.
 *
 * @ingroup views_argument_handlers
 */
class oa_core_views_handler_argument_numeric_og_membership_gid extends views_handler_argument_numeric {

  function option_definition() {
    $options = parent::option_definition();

    $options['oa_subspaces_expand'] = array('default' => FALSE, 'bool' => TRUE);

    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['oa_subspaces_expand'] = array(
      '#type' => 'checkbox',
      '#title' => t('Expand'),
      '#description' => t('If selected, the argument will be expanded to include inheriting parent GIDs, with assumption that this is a node GID'),
      '#default_value' => !empty($this->options['oa_subspaces_expand']),
      '#fieldset' => 'more',
    );

  }

  function query($group_by = FALSE) {
    if (empty($this->options['oa_subspaces_expand'])) {
      return parent::query($group_by);
    }

    if (!empty($this->options['break_phrase'])) {
      views_break_phrase($this->argument, $this);
    }
    else {
      $this->value = array($this->argument);
    }
    // Add parents.
    $original_breakphrase = $this->options['break_phrase'];
    $parents = count($this->value) == 1 ? og_subgroups_parents_load('node', current($this->value)) : og_subgroups_parents_load_multiple(array('node' => $this->value));
    if (!empty($parents['node'])) {
      $this->options['break_phrase'] = TRUE;
      $seperator = isset($this->operator) && $this->operator == 'and' ? '-' : '+';
      $this->value = array_unique(array_merge($this->value, $parents['node']));
      $this->argument = implode($seperator, $this->value);
    }

    parent::query($group_by);
    $this->options['break_phrase'] = $original_breakphrase;
  }
}
