<?php
/**
 * @file
 * mukurtu_importer_generator.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function mukurtu_importer_generator_feeds_importer_default() {
  $export = array();


  foreach(array_keys(entity_get_info()) as $entity_type) {
      // Only generate importers for the following entity types
      if(!in_array($entity_type, array('paragraphs_item', 'node', 'scald_atom', 'taxonomy_term'))) {
          continue;
      }
      $entity_info = entity_get_info($entity_type);

      foreach($entity_info['bundles'] as $bundle_name => $ids) {
          $fields_info = field_info_instances($entity_type, $bundle_name);

          // Define importer for bundle
          $id = "mukurtu_import_{$entity_type}_{$bundle_name}";
          $importer_name = "Mukurtu Import: {$entity_info['label']} - {$ids['label']}";
          $importer_desc = "Mukurtu roundtrip importer for {$entity_info['label']} - {$ids['label']}";

          $mappings = array(
              0 => array(
                  'source' => 'guid',
                  'target' => 'guid',
                  'unique' => 1,
                  'language' => 'und',
              ),
              1 => array(
                  'source' => 'nid',
                  'target' => 'nid',
                  'unique' => 1,
                  'language' => 'und',
              ),
              2 => array(
                  'source' => 'Title',
                  'target' => 'title',
                  'unique' => 1,
                  'language' => 'und',
              ),
          );

          $mapping_i = 3;

          foreach($fields_info as $field_name => $field_value) {
              $field = field_info_field($field_name);
              //              dpm("Add $entity_type - $bundle_name: $field_name/{$field['type']}");

              $mappings[$mapping_i] = array(
                  'source' => $field_value['label'],
                  'target' => $field_name,
                  'unique' => 1,
                  'language' => 'und',
              );

              switch($field['type']) {
              // Taxonomy Terms
              case 'atom_reference':
              case 'node_reference':
              case 'entityreference':
                  $target_id = array_keys($field['columns'])[0];
                  $mappings[$mapping_i]['target'] = "{$field_name}:guid_or_{$target_id}";
                  break;
              case 'taxonomy_term_reference':
                  $mappings[$mapping_i]['term_search'] = 0;
                  $mappings[$mapping_i]['autocreate'] = 1;
                  break;
              }

              $mapping_i++;

              // Create feed importer
              $feeds_importer = new stdClass();
              $feeds_importer->disabled = FALSE;
              $feeds_importer->api_version = 1;
              $feeds_importer->id = $id;
              $feeds_importer->config = array(
                  'name' => $importer_name,
                  'description' => $importer_desc,
                  'fetcher' => array(
                      'plugin_key' => 'FeedsFileFetcher',
                      'config' => array(
                          'direct' => 0,
                          'allowed_extensions' => 'csv',
                          'directory' => 'private://feeds',
                          'allowed_schemes' => array(
                              0 => 'public',
                              1 => 'private',
                          ),
                          'delete_uploaded_file' => TRUE,
                      ),
                  ),
                  'parser' => array(
                      'plugin_key' => 'FeedsCSVParser',
                      'config' => array(
                          'delimiter' => ',',
                          'no_headers' => 0,
                          'encoding' => 'UTF-8',
                      ),
                  ),
                  'processor' => array(
                      'plugin_key' => 'FeedsNodeProcessor',
                      'config' => array(
                          'update_existing' => '2',
                          'expire' => '-1',
                          'mappings' => $mappings,
                          'input_format' => 'filtered_html',
                          'author' => '1',
                          'authorize' => 1,
                          'skip_hash_check' => 0,
                          'bundle' => $bundle_name,
                          'update_non_existent' => 'skip',
                          'insert_new' => 1,
                          'language' => 'und',
                      ),
                  ),
                  'content_type' => '',
                  'update' => 0,
                  'import_period' => '-1',
                  'expire_period' => 3600,
                  'import_on_create' => 1,
                  'process_in_background' => 0,
              );
              $export[$id] = $feeds_importer;
          }
      }
  }

  return $export;
}
