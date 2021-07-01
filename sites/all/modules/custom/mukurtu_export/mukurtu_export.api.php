<?php

/**
 * @file
 * Documents Mukurtu export's hooks for api reference.
 */


function hook_mukurtu_export_field_handlers() {
    return array(
        'taxonomy_term_reference' => array(
            '#module' => 'mukurtu_export',
            '#file' => drupal_get_path('module', 'mukurtu_export') . DIRECTORY_SEPARATOR . 'mukurtu_export.field_handlers.inc',
            '#callback' => 'mukurtu_export_field_handler_taxonomy_term_reference'
        )
    );
}