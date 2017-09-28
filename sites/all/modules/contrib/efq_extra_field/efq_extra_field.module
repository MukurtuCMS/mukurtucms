<?php

class EntityFieldQueryExtraFields extends EntityFieldQuery {
 /**
  * Finishes the query.
  *
  * Adds tags, metaData, range and returns the requested list or count.
  *
  * @param SelectQuery $select_query
  *   A SelectQuery which has entity_type, entity_id, revision_id and bundle
  *   fields added.
  * @param $id_key
  *   Which field's values to use as the returned array keys.
  *
  * @return
  *   See EntityFieldQuery::execute().
  */
  private $addedFields = array();

  function finishQuery($select_query, $id_key = 'entity_id') {
    // http://drupal.org/node/1226622#comment-6809826 - adds support for IS NULL
    // Iterate through all fields.  If the query is trying to fetch results
    // where a field is null, then alter the query to use a LEFT OUTER join.
    // Otherwise the query will always return 0 results.
    $tables =& $select_query->getTables();
    foreach ($this->fieldConditions as $key => $fieldCondition) {
      if ($fieldCondition['operator'] == 'IS NULL' && isset($this->fields[$key]['storage']['details']['sql'][FIELD_LOAD_CURRENT])) {
        $keys = array_keys($this->fields[$key]['storage']['details']['sql'][FIELD_LOAD_CURRENT]);
        $sql_table = reset($keys);
        foreach ($tables as $table_id => $table) {
          if ($table['table'] == $sql_table) {
            $tables[$table_id]['join type'] = 'LEFT OUTER';
          }
        }
      }
    }

    foreach ($this->tags as $tag) {
      $select_query->addTag($tag);
    }
    foreach ($this->metaData as $key => $object) {
      $select_query->addMetaData($key, $object);
    }
    $select_query->addMetaData('entity_field_query', $this);
    if ($this->range) {
      $select_query->range($this->range['start'], $this->range['length']);
    }
    if ($this->count) {
      return $select_query->countQuery()->execute()->fetchField();
    }
    $return = array();

    foreach($this->addedFields as $addedField) {
      $fields = $select_query->getFields();

      if (!empty($addedField['field_name'])) {
        $tables = $select_query->getTables();
        $clean_tables = $this->cleanTables($tables);
        // hardcoded as it is also hardcoded in the fields module
        $table = 'field_data_' . $addedField['field_name'];

        // Get our alias for the selected field
        if (isset($clean_tables[$table])) {
          $addedField['table'] = $clean_tables[$table]['alias'];
        }

        // Set our name and alias
        $column = $addedField['field_name'] . '_' . $addedField['column'];
        $column_alias = $addedField['field_name'] . '_' . $addedField['column_alias'];
      }
      else {
        // Not from a field, so probably a direct entity property
        $column = $addedField['column'];
        $column_alias = $addedField['column_alias'];
      }
      if (!empty($addedField['table'])) {
        // if we know the exact table, set it
        $select_query->addField($addedField['table'], $column, $column_alias);
      }
      else {
        // If not, use the main selected table to fetch the extra field from
        $select_query->addField($fields['entity_id']['table'], $column, $column_alias);
      }
    }

    foreach ($select_query->execute() as $partial_entity) {
      $bundle = isset($partial_entity->bundle) ? $partial_entity->bundle : NULL;
      $entity = entity_create_stub_entity($partial_entity->entity_type, array($partial_entity->entity_id, $partial_entity->revision_id, $bundle));
      $entity->extraFields = $partial_entity;

      // If the id already exists, merge the data in a smart way. This
      // is completely based on the assumption that we expect a similar entity.
      if (isset($return[$partial_entity->entity_type][$partial_entity->$id_key])) {
        $previous_entity = $return[$partial_entity->entity_type][$partial_entity->$id_key];
        foreach ($previous_entity->extraFields as $id => $child) {
          // Found a distinct value, make it into an array.
          if (!is_array($previous_entity->extraFields->{$id})) {
            if ($entity->extraFields->{$id} != $previous_entity->extraFields->{$id}) {
              $entity->extraFields->{$id} = array($previous_entity->extraFields->{$id}, $entity->extraFields->{$id});
            }
          }
          // Found more distinct values. Append to the array. Avoid duplicates.
          else {
            if (!in_array($entity->extraFields->{$id}, $previous_entity->extraFields->{$id})) {
              $previous_entity->extraFields->{$id}[] = $entity->extraFields->{$id};
              $entity->extraFields->{$id} = $previous_entity->extraFields->{$id};
            }
          }
        }
      }

      // Add the entity to the result set to return.
      $return[$partial_entity->entity_type][$partial_entity->$id_key] = $entity;
      $this->ordered_results[] = $partial_entity;
    }
    return $return;
  }

  /**
   * Add the given field with an INNER JOIN and add a select statement
   * for the requested field
   * @param type $field_name
   * @param type $column
   * @param type $column_alias
   * @param type $table
   * @return \EntityFieldQueryExtraFields
   */
  public function addExtraField($field_name, $column, $column_alias = NULL, $table = NULL) {
    if (!empty($field_name) && !$this->checkFieldExists($field_name)) {
      // Add the field as a condition, so we generate the join
      $this->fieldCondition($field_name);
    }

    $this->addedFields[] = array(
      'field_name' => $field_name,
      'column' => $column,
      'column_alias' => $column_alias,
      'table' => $table,
    );
    return $this;
  }

  /**
   * Give the values in the array the name of the real table instead of the
   * alias, so we can look up the alias quicker
   * @param type $tables
   * @return type
   */
  private function cleanTables($tables) {
    if (!is_array($tables)) {
      return array();
    }
    foreach ($tables as $table_id => $table) {
      if ($table['join type'] == 'INNER') {
        $tables[$table['table']] = $table;
        unset($tables[$table_id]);
      }
    }
    return $tables;
  }

  /**
   * Check if the field already has a table that does a join.
   * @param type $field_name
   * @return boolean
   */
  private function checkFieldExists($field_name) {
    $fields = $this->fields;
    foreach($fields as $field) {
      if (isset($field['field_name']) && $field['field_name'] == $field_name) {
        return TRUE;
      }
    }
    return FALSE;
  }
}
