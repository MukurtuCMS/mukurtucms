<?php

/**
 * @file
 * Definition of TaxonomyTermReferenceTermMergeSynonymsBehavior class.
 */

/**
 * Synonyms "term_merge" behavior for 'taxonomy term reference' field type.
 */
class TaxonomyTermReferenceTermMergeSynonymsBehavior extends TaxonomySynonymsBehavior implements TermMergeSynonymsBehavior {

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
    // Taxonomy term reference supports only referencing of entity types
    // 'taxonomy_term'.. duh.
    if ($synonym_entity_type != 'taxonomy_term') {
      return;
    }

    $items = $this->entityItems($trunk_entity);

    // Checking that $field is configured to reference the vocabulary of
    // $synonym_entity term.
    $is_allowed = FALSE;
    foreach ($this->field['settings']['allowed_values'] as $setting) {
      if ($synonym_entity->vocabulary_machine_name == $setting['vocabulary']) {
        if ($setting['parent'] == 0) {
          // No need to check parent property as there is no limitation on it.
          $is_allowed = TRUE;
          break;
        }
        else {
          foreach (taxonomy_get_parents_all($synonym_entity->tid) as $parent) {
            if ($parent->tid == $setting['parent']) {
              $is_allowed = TRUE;
              break(2);
            }
          }
        }
      }
    }
    if (!$is_allowed) {
      // Synonym term is from a vocabulary that is not expected by this field,
      // or under unexpected parent.
      return;
    }
    $items[] = array(
      'tid' => $synonym_entity->tid,
    );
    $trunk_entity->{$this->field['field_name']}[LANGUAGE_NONE] = $this->uniqueItems($items, array('tid'));
  }
}
