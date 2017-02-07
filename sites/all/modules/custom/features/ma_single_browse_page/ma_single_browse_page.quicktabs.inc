<?php
/**
 * @file
 * ma_single_browse_page.quicktabs.inc
 */

/**
 * Implements hook_quicktabs_default_quicktabs().
 */
function ma_single_browse_page_quicktabs_default_quicktabs() {
  $export = array();

  $quicktabs = new stdClass();
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'single_browse_page_right_column';
  $quicktabs->ajax = 0;
  $quicktabs->hide_empty_tabs = FALSE;
  $quicktabs->default_tab = 0;
  $quicktabs->title = 'Single Browse Page Right Column';
  $quicktabs->tabs = array(
    0 => array(
      'bid' => 'ma_single_browse_page_delta_single_browse_page_list_and_sort',
      'hide_title' => 1,
      'title' => 'Items',
      'weight' => '-100',
      'type' => 'block',
    ),
    1 => array(
      'bid' => 'ma_single_browse_page_delta_single_browse_page_filters',
      'hide_title' => 1,
      'title' => 'Filters',
      'weight' => '-99',
      'type' => 'block',
    ),
    2 => array(
      'bid' => 'ma_single_browse_page_delta_single_browse_page_legend',
      'hide_title' => 1,
      'title' => 'Legend',
      'weight' => '-98',
      'type' => 'block',
    ),
    3 => array(
      'bid' => 'ma_single_browse_page_delta_single_browse_page_content_tab',
      'hide_title' => 1,
      'title' => 'Content',
      'weight' => '-97',
      'type' => 'block',
    ),
  );
  $quicktabs->renderer = 'quicktabs';
  $quicktabs->style = 'default';
  $quicktabs->options = array();

  // Translatables
  // Included for use with string extractors like potx.
  t('Content');
  t('Filters');
  t('Items');
  t('Legend');
  t('Single Browse Page Right Column');

  $export['single_browse_page_right_column'] = $quicktabs;

  return $export;
}
