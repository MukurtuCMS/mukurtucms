<?php

/**
 * @file
 * Definition of EntityReferenceTermMergeSynonymsBehavior class.
 */

/**
 * Synonyms "term_merge" behavior for 'entityreference' field type.
 */
class EntityReferenceTermMergeSynonymsBehavior extends EntityReferenceSynonymsBehavior implements TermMergeSynonymsBehavior {

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
    // Firstly validating that this entity reference is able to reference that
    // type of entity.
    $expected_synonym_entity_type = $this->field['settings']['target_type'];

    $items = $this->entityItems($trunk_entity);

    if ($expected_synonym_entity_type != $synonym_entity_type) {
      return;
    }
    $synonym_entity_id = entity_extract_ids($synonym_entity_type, $synonym_entity);
    $synonym_entity_id = $synonym_entity_id[0];
    $items[] = array(
      'target_id' => $synonym_entity_id,
    );
    $trunk_entity->{$this->field['field_name']}[LANGUAGE_NONE] = $this->uniqueItems($items, array('target_id'));
  }
}
