<?php
/**
 * @file
 * mukurtu_importer_generator.feeds_tamper_default.inc
 */

function _mukurtu_importer_generator_add_explode_tamper(&$tampers, $importer_id, $field_name, $source, $weight = 0) {
    $tamper_field_name = str_replace('field_', '', $field_name);
    $tamper_id = "{$importer_id}-{$tamper_field_name}-explode";

    $feeds_tamper = new stdClass();
    $feeds_tamper->disabled = FALSE;
    $feeds_tamper->api_version = 2;
    $feeds_tamper->id = $tamper_id;
    $feeds_tamper->importer = $importer_id;
    $feeds_tamper->source = $source;
    $feeds_tamper->plugin_id = 'explode';
    $feeds_tamper->settings = array(
        'separator' => ';',
        'limit' => '',
        'real_separator' => ';',
    );
    $feeds_tamper->weight = $weight;
    $feeds_tamper->description = 'Explode';
    $tampers[$tamper_id] = $feeds_tamper;
}

function _mukurtu_importer_generator_add_trim_tamper(&$tampers, $importer_id, $field_name, $source, $weight = 0) {
    $tamper_field_name = str_replace('field_', '', $field_name);
    $tamper_id = "{$importer_id}-{$tamper_field_name}-trim";

    $feeds_tamper = new stdClass();
    $feeds_tamper->disabled = FALSE;
    $feeds_tamper->api_version = 2;
    $feeds_tamper->id = $tamper_id;
    $feeds_tamper->importer = $importer_id;
    $feeds_tamper->source = $source;
    $feeds_tamper->plugin_id = 'trim';
    $feeds_tamper->settings = array(
        'mask' => '',
        'side' => 'trim',
    );
    $feeds_tamper->weight = $weight;
    $feeds_tamper->description = 'Trim';
    $tampers[$tamper_id] = $feeds_tamper;
}

function _mukurtu_importer_generator_add_required_tamper(&$tampers, $importer_id, $field_name, $source, $weight = 0) {
    $tamper_field_name = str_replace('field_', '', $field_name);
    $tamper_id = "{$importer_id}-{$tamper_field_name}-required";

    $feeds_tamper = new stdClass();
    $feeds_tamper->disabled = FALSE;
    $feeds_tamper->api_version = 2;
    $feeds_tamper->id = $tamper_id;
    $feeds_tamper->importer = $importer_id;
    $feeds_tamper->source = $source;
    $feeds_tamper->plugin_id = 'required';
    $feeds_tamper->settings = array(
        'invert' => 0,
        'log' => 1,
    );
    $feeds_tamper->weight = $weight;
    $feeds_tamper->description = 'Required field';
    $tampers[$tamper_id] = $feeds_tamper;
}

function _mukurtu_importer_generator_add_require_valid_node_tamper(&$tampers, $importer_id, $field_name, $source, $node_type, $weight = 0) {
    if(!is_array($node_type)) {
        $node_type = array($node_type);
    }
    $tamper_field_name = str_replace('field_', '', $field_name);
    $tamper_id = "{$importer_id}-{$tamper_field_name}-required_valid_node";

    $feeds_tamper = new stdClass();
    $feeds_tamper->disabled = FALSE;
    $feeds_tamper->api_version = 2;
    $feeds_tamper->id = $tamper_id;
    $feeds_tamper->importer = $importer_id;
    $feeds_tamper->source = $source;
    $feeds_tamper->plugin_id = 'require_valid_node';
    $feeds_tamper->settings = array(
        'allow_empty' => 1,
        'node_type' => $node_type,
    );
    $feeds_tamper->weight = $weight;
    $node_type_string = implode("|", $node_type);
    $feeds_tamper->description = "Require valid $node_type_string";
    $tampers[$tamper_id] = $feeds_tamper;
}

/**
 * Implements hook_feeds_tamper_default().
 */
function mukurtu_importer_generator_feeds_tamper_default() {
  $export = array();

  foreach(array_keys(entity_get_info()) as $entity_type) {
      // Only generate import tampers for the following entity types
      if(!in_array($entity_type, array('paragraphs_item', 'node', 'scald_atom', 'taxonomy_term'))) {
          continue;
      }
      $entity_info = entity_get_info($entity_type);

      foreach($entity_info['bundles'] as $bundle_name => $ids) {
          $fields_info = field_info_instances($entity_type, $bundle_name);

          // Define importer for bundle
          $importer_id = "mukurtu_import_{$entity_type}_{$bundle_name}";

          // Add trim tamper to all fields.
          $feed = feeds_source($importer_id);
          if (isset($feed)) {
              // We are getting the mappings from the importer rather than field_info_field because
              // need to add trim tampers to extra fields like guid, nid, etc.
              $mappings = $feed->importer->config['processor']['config']['mappings'];
              foreach ($mappings as $mapping) {
                $field_name = strpos($mapping['target'], ':') ? rtrim(strstr($mapping['target'], ':', TRUE), ':') : $mapping['target'];
                _mukurtu_importer_generator_add_trim_tamper($export, $importer_id, $field_name, $mapping['source'], -5);
              }
          }

          // Check each field
          foreach($fields_info as $field_name => $field_value) {
              $field = field_info_field($field_name);
              $source = $field_value['label'];

              // Required field
              if(!empty($field['required']) && $field['required'] == TRUE) {
                  _mukurtu_importer_generator_add_required_tamper($export, $importer_id, $field_name, $source);
              }

              // Explode for multiple values
              if(!empty($field['cardinality'])
                 && (($field['cardinality'] > 1) || $field['cardinality'] == '-1')) {
                  _mukurtu_importer_generator_add_explode_tamper($export, $importer_id, $field_name, $source, -10);
              }

              // Require valid node
              if($field['type'] == 'entityreference') {
                  if($field['settings']['target_type'] == 'node') {
                      // Requires specific type of node
                      if($field['settings']['handler'] == 'base') {
                          $node_type = array_keys($field['settings']['handler_settings']['target_bundles']);
                          _mukurtu_importer_generator_add_require_valid_node_tamper($export, $importer_id, $field_name, $source, $node_type);
                      }

                      // Can be any node
                      if($field['settings']['handler'] == 'views') {
                          _mukurtu_importer_generator_add_require_valid_node_tamper($export, $importer_id, $field_name, $source, 'any');
                      }
                  }
              }
          }
      }
  }

  return $export;
}
