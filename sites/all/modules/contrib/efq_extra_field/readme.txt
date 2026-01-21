// Example on how to use this module

$results = array();
$fields = field_info_field_by_ids();
foreach ($fields as $field_id => $field_info) {
  if ($field_info['type'] == 'file') {
    foreach ($field_info['bundles'] as $entity_type => $bundles) {
      $entity_info = entity_get_info($entity_type);
      // If this entity type is not indexable, ignore this and move on to the
      // next one
      if (empty($entity_info['apachesolr']['indexable'])) {
        continue;
      }

      $query = new EntityFieldQueryExtraFields();
      $results_query = $query
        ->entityCondition('entity_type', $entity_type)
        ->fieldCondition($field_info['field_name'])
        // Fetch all file ids related to the entities
        ->addExtraField($field_info['field_name], 'fid', 'fid')
        ->execute();
      $results = array_merge_recursive($results, $results_query);
    }
  }
}
dsm($results);