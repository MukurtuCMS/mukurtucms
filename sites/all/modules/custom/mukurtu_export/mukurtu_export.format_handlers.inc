<?php

function mukurtu_export_mukurtu_export_format_handlers() {
    return array(
        'csv' => array(
            '#title' => t('CSV (Mukurtu Format)'),
            '#module' => 'mukurtu_export',
            '#file' => drupal_get_path('module', 'mukurtu_export') . '/formats/csv.inc',
            '#description' => t(
              'Comma separated values, formatted for importing into Mukurtu.'
            ),
            '#settings_callback' => 'mukurtu_export_csv_settings',
            '#export_callback' => 'mukurtu_export_csv_export',
          ),
    );
}