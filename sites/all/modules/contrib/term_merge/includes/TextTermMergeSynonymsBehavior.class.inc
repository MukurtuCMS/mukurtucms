<?php

/**
 * @file
 * Definition of TextTermMergeSynonymsBehavior class.
 */

/**
 * Synonyms "term_merge" behavior for 'text' field type.
 */
class TextTermMergeSynonymsBehavior extends TextSynonymsBehavior implements TermMergeSynonymsBehavior {

  /**
   * Add an entity as a synonym into another entity.
   *
   * Basically this method should be called when you want to add some entity as
   * a synonym to another entity (for example when you merge one entity into
   * another and besides merging want to add synonym of the merged entity into
   * the trunk entity). You should update $trunk_entity in such a way that it
   * holds $synonym_entity as a synonym (it all depends on how data is stored in
   * your behavior implementation, but probably you will store entity label or
   * its ID as you cannot literally store an entity inside of another entity).
   * If entity of type $synonym_entity_type cannot be converted into a format
   * expected by your behavior implementation, just do nothing.
   *
   * @param object $trunk_entity
   *   Entity into which another one should be added as synonym
   * @param object $synonym_entity
   *   Fully loaded entity object which has to be added as synonym
   * @param string $synonym_entity_type
   *   Entity type of $synonym_entity
   */
  public function mergeTerm($trunk_entity, $synonym_entity, $synonym_entity_type) {
    $synonym = entity_label($synonym_entity_type, $synonym_entity);

    switch ($this->field['type']) {
      case 'text':
        break;

      // We add synonyms for numbers only if $synonym is a number.
      case 'number_integer':
      case 'number_float':
      case 'number_decimal':
        if (!is_numeric($synonym)) {
          return;
        }
        break;

    }
    $items = $this->entityItems($trunk_entity);
    $items[] = array(
      'value' => $synonym,
    );
    $trunk_entity->{$this->field['field_name']}[LANGUAGE_NONE] = $this->uniqueItems($items, array('value'));
  }
}
