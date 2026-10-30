<?php
/**
 * @file
 * mukurtu_importer_generator.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function mukurtu_importer_generator_user_default_permissions() {
  $permissions = array();

  foreach(array_keys(entity_get_info()) as $entity_type) {
    // Only generate importers for the following entity types.
    if (!in_array($entity_type, array('paragraphs_item', 'node', 'scald_atom', 'taxonomy_term'))) {
      continue;
    }

    $entity_info = entity_get_info($entity_type);

    // Entity ID name.
    $entity_id_name = $entity_info['entity keys']['id'];

    foreach ($entity_info['bundles'] as $bundle_name => $ids) {
      // Define importer ID for bundle.
      $importer_id = "mukurtu_import_{$entity_type}_{$bundle_name}";

      // Exported permission: 'clear $importer_id feeds'.
      $permissions["clear $importer_id feeds"] = array(
        'name' => "clear $importer_id feeds",
        'roles' => array(
          'Mukurtu Administrator' => 'Mukurtu Administrator',
          'administrator' => 'administrator',
        ),
        'module' => 'feeds',
      );

      // Exported permission: 'import $importer_id feeds'.
      $permissions["import $importer_id feeds"] = array(
        'name' => "import $importer_id feeds",
        'roles' => array(
          'Mukurtu Administrator' => 'Mukurtu Administrator',
          'administrator' => 'administrator',
        ),
        'module' => 'feeds',
      );

      // Exported permission: 'tamper $importer_id'.
      $permissions["tamper $importer_id"] = array(
        'name' => "tamper $importer_id",
        'roles' => array(
          'administrator' => 'administrator',
        ),
        'module' => 'feeds_tamper',
      );

      // Exported permission: 'unlock $importer_id feeds'.
      $permissions["unlock $importer_id feeds"] = array(
        'name' => "unlock $importer_id feeds",
        'roles' => array(
          'Mukurtu Administrator' => 'Mukurtu Administrator',
          'administrator' => 'administrator',
        ),
        'module' => 'feeds',
      );
    }
  }

  return $permissions;
}
