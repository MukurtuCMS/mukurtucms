<?php

// Stock Mukurtu Export Field Handlers
function mukurtu_export_mukurtu_export_field_handlers() {
    return array(
        'image' => array(
            '#module' => 'mukurtu_export',
            '#file' => drupal_get_path('module', 'mukurtu_export') . DIRECTORY_SEPARATOR . 'mukurtu_export.field_handlers.inc',
            '#callback' => 'mukurtu_export_field_handler_image'
        ),
        'taxonomy_term_reference' => array(
            '#module' => 'mukurtu_export',
            '#file' => drupal_get_path('module', 'mukurtu_export') . DIRECTORY_SEPARATOR . 'mukurtu_export.field_handlers.inc',
            '#callback' => 'mukurtu_export_field_handler_taxonomy_term_reference'
        ),
        'atom_reference' => array(
            '#module' => 'mukurtu_export',
            '#file' => drupal_get_path('module', 'mukurtu_export') . DIRECTORY_SEPARATOR . 'mukurtu_export.field_handlers.inc',
            '#callback' => 'mukurtu_export_field_handler_atom_reference'
        ),
        'node_reference' => array(
            '#module' => 'mukurtu_export',
            '#file' => drupal_get_path('module', 'mukurtu_export') . DIRECTORY_SEPARATOR . 'mukurtu_export.field_handlers.inc',
            '#callback' => 'mukurtu_export_field_handler_node_reference'
        ),
        'entityreference' => array(
            '#module' => 'mukurtu_export',
            '#file' => drupal_get_path('module', 'mukurtu_export') . DIRECTORY_SEPARATOR . 'mukurtu_export.field_handlers.inc',
            '#callback' => 'mukurtu_export_field_handler_entity_reference'
        ),
        'partial_date_range' => array(
            '#module' => 'mukurtu_export',
            '#file' => drupal_get_path('module', 'mukurtu_export') . DIRECTORY_SEPARATOR . 'mukurtu_export.field_handlers.inc',
            '#callback' => 'mukurtu_export_field_handler_partial_date_range'
        )
    );
}

// Handle Taxonomy Term References
function mukurtu_export_field_handler_taxonomy_term_reference($value, $field_info) {
    $referenced_entities = array();
    if(isset($value['tid'])) {
        $term = taxonomy_term_load($value['tid']);
        if(isset($term->name)) {
            return array($term->name, $referenced_entities);
        }
    }
    return array(NULL, $referenced_entities);
}

// Handle Images files (not Scald Atoms)
function mukurtu_export_field_handler_image($value, $field_info) {
    return isset($value['fid']) ? $value['fid'] : NULL;
}

// Handle entityreference fields
function mukurtu_export_field_handler_entity_reference($value, $field_info) {
    $referenced_entities = array();
    if(isset($value['target_id'])) {
        if(isset($field_info['settings']['target_type'])) {
            $referenced_entities[$field_info['settings']['target_type']][$value['target_id']] = $value['target_id'];
        }
        return array($value['target_id'], $referenced_entities);
    }
    return array(NULL, $referenced_entities);
}

function mukurtu_export_field_handler_node_reference($value, $field_info) {
    $referenced_entities = array();
    if(isset($value['nid'])) {
        $referenced_entities['node'][$value['nid']] = $value['nid'];
        return array($value['nid'], $referenced_entities);
    }
    return array(NULL, $referenced_entities);
}

function mukurtu_export_field_handler_atom_reference($value, $field_info) {
    $referenced_entities = array();
    if(isset($value['sid'])) {
        $referenced_entities['scald_atom'][$value['sid']] = $value['sid'];
        return array($value['sid'], $referenced_entities);
    }
    return array(NULL, $referenced_entities);
}

function mukurtu_export_field_handler_partial_date_range($value, $field_info) {
    $referenced_entities = array();
    if(isset($value['timestamp'])) {
        return array($value['timestamp'], $referenced_entities);
    }
    return array(NULL, $referenced_entities);
}

