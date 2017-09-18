<?php

function mukurtu_starter_form_system_theme_settings_alter(&$form, $form_state) {
    $form['mukurtu'] = array(
        '#type' => 'vertical_tabs',
        '#attached' => array(
            'js'  => array(drupal_get_path('theme', 'bootstrap') . '/js/bootstrap.admin.js'),
        ),
        '#prefix' => '<h2><small>' . t('Mukurtu Settings') . '</small></h2>',
        '#weight' => -5,
    );

    $form['mukurtu_search'] = array(
        '#type' => 'fieldset',
        '#title' => t('Search'),
        '#group' => 'mukurtu',
    );

    $form['mukurtu_search']['display_record_label'] = array(
        '#type'          => 'checkbox',
        '#title'         => t('Display record count label'),
        '#default_value' => theme_get_setting('display_record_label'),
        '#description'   => t("Check here to add a label summarizing the number of community records to an item's search result display"),
    );

    $form['mukurtu_search']['display_book_page_label'] = array(
        '#type'          => 'checkbox',
        '#title'         => t('Display pages label'),
        '#default_value' => theme_get_setting('display_book_page_label'),
        '#description'   => t("Check here to add a label summarizing the number of pages to a multi-page item's search result display"),
    );
}