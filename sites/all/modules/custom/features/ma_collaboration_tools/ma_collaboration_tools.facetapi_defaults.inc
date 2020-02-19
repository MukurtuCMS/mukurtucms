<?php

/**
 * @file
 * ma_collaboration_tools.facetapi_defaults.inc
 */

/**
 * Implements hook_facetapi_default_facet_settings().
 */
function ma_collaboration_tools_facetapi_default_facet_settings() {
  $export = array();

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@document_pages::created';
  $facet->searcher = 'search_api@document_pages';
  $facet->realm = '';
  $facet->facet = 'created';
  $facet->enabled = FALSE;
  $facet->hash = 'vithFmMOTUF1HKBdW0RjfGr3rzWGMVcG';
  $facet->settings = array(
    'operator' => 'and',
    'hard_limit' => '-1',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
      'roles' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => 0,
    'individual_parent' => 0,
    'query_type' => 'date_range',
    'limit_active_items' => 0,
    'default_true' => TRUE,
    'facet_search_ids' => array(),
    'date_granularity' => 'DAY',
    'date_granularity_min' => 'YEAR',
    'pretty_paths_alias' => 'created',
  );
  $export['search_api@document_pages::created'] = $facet;

  return $export;
}
