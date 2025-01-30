<?php
/**
 * @file
 * Provides a field containing the actions allowed for the current user on an atom
 */
class scald_views_handler_field_actions extends views_handler_field {
  function option_definition() {
    $options = parent::option_definition();
    $options['end_user_links'] = array('default' => TRUE);
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['end_user_links'] = array(
      '#type' => 'checkbox',
      '#title' => t('Display links for end users'),
      '#description' => t('If this is checked, a list of action links targeted towards end users is shown. If this is unchecked, then the raw labels of the actions checked on the atom will be displayed instead.'),
      '#default_value' => $this->options['end_user_links'],
    );
  }

  /**
   * Renders the atom according in the context specified in the option form.
   */
  function render($values) {
    $atom = scald_fetch($values->sid);
    if ($this->options['end_user_links']) {
      $links = scald_atom_user_build_actions_links($atom, drupal_get_destination());
    }
    else {
      $links = array();
      foreach (scald_actions() as $action) {
        if ($atom->actions & $action['bitmask']) {
          $links[] = array('title' => $action['title']);
        }
      }
    }
    $content = array(
      '#theme' => 'links',
      '#links' => $links,
      '#attributes' => array('class' => array('links', 'inline')),
    );
    return $content;
  }
}
