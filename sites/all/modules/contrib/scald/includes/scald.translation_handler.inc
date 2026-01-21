<?php

/**
 * @file
 * Translation handler for the Scald Atom entity.
 */

/**
 * Class implementing the entity translation behaviours for Scald Atom.
 */
class EntityTranslationScaldHandler extends EntityTranslationDefaultHandler {

  public function __construct($entity_type, $entity_info, $entity) {
    parent::__construct('scald_atom', $entity_info, $entity);
  }

  /**
   * Checks whether the current user has access to this product.
   */
  public function getAccess($op) {
    return scald_action_permitted($this->entity, array('fetch', 'view'));
  }

  /**
   * Changes the editPath when necessary.
   */
  public function getEditPath($langcode = NULL) {
    $edit_path = parent::getEditPath($langcode);
    return str_replace('/%ctools_js', '/nojs', $edit_path);
  }

  /**
   * Tweaks the product form to support multilingual elements.
   */
  public function entityForm(&$form, &$form_state) {
    parent::entityForm($form, $form_state);
    $translations = $this->getTranslations();
    $is_translation = $this->isTranslationForm();
    $form_langcode = $this->getFormLanguage();
    $new_translation = !isset($translations->data[$form_langcode]);
    if ($is_translation && !$new_translation) {
      $form['actions']['delete_translation'] = array(
        '#type' => 'submit',
        '#value' => t('Delete translation'),
        '#weight' => 50,
        '#submit' => array('entity_translation_entity_form_delete_translation_submit'),
      );
    }
  }
}
