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

  // Fields to not generate import fields for.
  $field_blacklist = array(
    'all' => array(
        'field_pre_actions',
        'field_digital_heritage_count',
        'field_media_aggregate',
        'field_node_aggregate',
    ),
    'node' => array(
        'dictionary_word' => array('field_media_asset'),
    ),
  );

  foreach(array_keys(entity_get_info()) as $entity_type) {
      // Only generate importers for the following entity types
      if(!in_array($entity_type, array('paragraphs_item', 'node', 'scald_atom', 'taxonomy_term'))) {
          continue;
      }
      $processor_name = $entity_type == 'node' ? 'FeedsNodeProcessor' : 'FeedsEntityProcessor' . ucfirst($entity_type);
      $entity_info = entity_get_info($entity_type);

      // ID name
      $entity_id_name = $entity_info['entity keys']['id'];

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
                  'source' => $entity_id_name,
                  'target' => $entity_id_name,
                  'unique' => 1,
                  'language' => 'und',
              ),
          );

          $mapping_i = 2;

          if($entity_type == 'scald_atom') {
            $mappings[$mapping_i++] = array(
                'source' => 'Provider',
                'target' => 'provider',
                'unique' => 0,
                'language' => 'und',
            );
            $mappings[$mapping_i++] = array(
                'source' => 'Media Source',
                'target' => 'file_source',
                'unique' => 0,
                'language' => 'und',
            );
          }

          if ($entity_type == 'paragraphs_item') {
            switch($bundle_name) {
            case 'dictionary_word_bundle':
                $source = 'Dictionary Word';
                break;
            default:
                $source = "Host Entity";
            }
            $mappings[$mapping_i++] = array(
                'source' => $source,
                'target' => 'host_entity',
                'unique' => 0,
                'language' => 'und',
            );
          }

          // Extra fields (title, etc)
          $extra_fields = field_info_extra_fields($entity_type, $bundle_name, 'form');
          if(!empty($extra_fields)) {
              foreach($extra_fields as $extra_field_name => $extra_field) {
                  // Skip path/redirect fields
                  if(in_array($extra_field_name, array('path', 'redirect'))) {
                      continue;
                  }
                  $mappings[$mapping_i++] = array(
                      'source' => $extra_field['label'],
                      'target' => $extra_field_name,
                      'unique' => 0,
                      'language' => 'und',
                  );
              }
          }

          foreach($fields_info as $field_name => $field_value) {
            // Check global blacklist.
            if (in_array($field_name, $field_blacklist['all'])) {
                continue;
            }

            // Check specific blacklist.
            if (!empty($field_blacklist[$entity_type][$bundle_name]) && in_array($field_name, $field_blacklist[$entity_type][$bundle_name])) {
                continue;
            }

              $field = field_info_field($field_name);
              //              dpm("Add $entity_type - $bundle_name: $field_name/{$field['type']}");

              $mappings[$mapping_i] = array(
                  'source' => $field_value['label'],
                  'target' => $field_name,
                  'unique' => 0,
                  'language' => 'und',
              );

              switch($field['type']) {
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
              case 'paragraphs':
                  $target_id = array_keys($field['columns'])[0];
                  $mappings[$mapping_i]['target'] = "{$field_name}:guid_or_{$target_id}";
                  break;
              case 'geofield':
                  $mappings[$mapping_i]['target'] = "{$field_name}:wkt";
                  break;
              case 'partial_date_range':
                  break;
              case 'datetime':
                  $mappings[$mapping_i]['target'] = "{$field_name}:start";
                  break;
              default:
                                //watchdog(WATCHDOG_NOTICE, "unhandled {$field['type']}");
              }

              $mapping_i++;
          }

          // Add username for node imports.
          if ($entity_type == 'node') {
            $mappings[$mapping_i++] = array(
                'source' => 'Username',
                'target' => 'user_name',
                'unique' => 0,
                'language' => 'und',
            );
          }

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
                  'plugin_key' => $processor_name,
                  'config' => array(
                      'update_existing' => '2',
                      'expire' => '-1',
                      'mappings' => $mappings,
                      'input_format' => 'filtered_html',
                      'author' => '1',
                      'authorize' => 1,
                      'skip_hash_check' => 1,
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

          // Create/update documentation.
          mukurtu_importer_generator_set_mapping_documentation($mappings, $entity_type, $bundle_name);
      }
  }

  return $export;
}
