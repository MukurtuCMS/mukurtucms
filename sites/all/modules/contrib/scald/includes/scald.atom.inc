<?php
/**
 * @file
 * Functions related to the Scald atom entity rendering.
 */

/**
 * Handles the view of an atom within a context.
 *
 * Contrary to scald_render(), which displays basically a "player", this
 * function displays the player and all atom fields. Fields are reorderable and
 * customisable in the Field UI as usual.
 *
 * @param ScaldAtom $atom
 *   Atom to be rendered
 * @param string $context
 *   (optional) Name of the context (view mode). Defaults to 'full'.
 * @param string $langcode
 *   (optional) A langcode to use for rendering.
 *
 * @return array
 *   An array as expected by drupal_render().
 */
function scald_atom_view($atom, $context = 'full', $langcode = NULL) {
  if (!isset($langcode)) {
    $langcode = $GLOBALS['language_content']->language;
  }

  // Populate $atom->content with a render() array.
  scald_atom_build_content($atom, $context, $langcode);

  $build = $atom->content;
  // We don't need duplicate rendering info in atom->content.
  unset($atom->content);

  $build += array(
    '#theme' => 'scald_atom',
  );

  // Allow modules to modify the structured atom.
  $type = 'scald_atom';
  drupal_alter(array('scald_atom_view', 'entity_view'), $build, $type);

  return $build;
}

/**
 * Builds a structured array representing the atom's content.
 *
 * @param ScaldAtom $atom
 *   Atom to build content.
 * @param string $view_mode
 *   View mode.
 * @param string $langcode
 *   (optional) A langcode to use for rendering.
 */
function scald_atom_build_content($atom, $view_mode = 'full', $langcode = NULL) {
  if (!isset($langcode)) {
    $langcode = $GLOBALS['language_content']->language;
  }

  // Remove previously built content, if exists.
  $atom->content = array();

  // Allow modules to change the view mode.
  $atom_by_view_mode = entity_view_mode_prepare('scald_atom', array($atom->sid => $atom), $view_mode, $langcode);
  $view_mode = key($atom_by_view_mode);

  // Building content of atom.
  field_attach_prepare_view('scald_atom', array($atom->sid => $atom), $view_mode, $langcode);
  entity_prepare_view('scald_atom', array($atom->sid => $atom), $langcode);
  $atom->content += field_attach_view('scald_atom', $atom, $view_mode, $langcode);

  // If the transcoder provider prepared a 'player', use it. Otherwise, build
  // a default representation of the atom.
  if (!empty($atom->rendered->player)) {
    $atom->content['atom'] = is_array($atom->rendered->player) ? $atom->rendered->player : array('#markup' => $atom->rendered->player);
  }
  else {
    $atom->content['atom'] = array(
      '#type' => 'link',
      '#href' => 'atom/' . $atom->sid,
      '#title' => '<img src="' . $atom->rendered->thumbnail_source_url . '" />',
      '#options' => array('html' => TRUE),
    );
  }

  // Allow modules to make their own additions to the atom.
  module_invoke_all('scald_atom_view', $atom, $view_mode, $langcode);
  module_invoke_all('entity_view', $atom, 'scald_atom', $view_mode, $langcode);

  $atom->content += array(
    '#entity_type' => 'scald_atom',
    '#entity' => $atom,
    '#view_mode' => $view_mode,
    '#language' => $langcode,
  );
}
