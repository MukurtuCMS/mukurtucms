<?php
/**
 * @file
 * Provides a field containing the actions allowed for the current user on an atom
 */
class scald_views_handler_field_actions extends views_handler_field {
  /**
   * Renders the atom according in the context specified in the option form.
   */
  function render($values) {
    $atom = scald_fetch($values->sid);
    $links = scald_atom_user_build_actions_links($atom, drupal_get_destination());
    $content = array(
      '#theme' => 'links',
      '#links' => $links,
      '#attributes' => array('class' => array('links', 'inline')),
    );
    return $content;
  }
}
