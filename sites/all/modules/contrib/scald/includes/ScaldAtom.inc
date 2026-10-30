<?php
/**
 * @file
 * Defines a class for Scald Atoms.
 */

class ScaldAtom {
  /**
   * Constructs a ScaldAtom object.
   */
  public function __construct($type, $provider = 'scald', array $values = array()) {
    // Add default values.
    $values += array(
      'title' => '',
      'type' => $type,
      'language' => LANGUAGE_NONE,
      'provider' => $provider,
      'publisher' => $GLOBALS['user']->uid,
      'actions' => scald_atom_defaults($type)->actions,
      'data' => array(),
    );

    if (module_exists('entity_translation')) {
      unset($values['language']);
      $handler = entity_translation_get_handler('scald_atom',(object) $values);
      $langcode = $handler->getLanguage();
      $values['language'] = $langcode;
    }

    foreach ($values as $key => $value) {
      $this->$key = $value;
    }
  }

  public function save() {
    return ScaldAtomController::save($this);
  }
}
