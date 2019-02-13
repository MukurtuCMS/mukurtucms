<?php

/**
 * @file
 * ma_collection.facetapi_defaults.inc
 */

/**
 * Implements hook_facetapi_default_facet_settings().
 */
function ma_collection_facetapi_default_facet_settings() {
  $export = array();

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_node_index::field_digital_heritage_count';
  $facet->searcher = 'search_api@default_node_index';
  $facet->realm = '';
  $facet->facet = 'field_digital_heritage_count';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'and',
    'hard_limit' => '-1',
    'dependencies' => array(
      'roles' => array(
        6 => '6',
        4 => '4',
        1 => 0,
        2 => 0,
        3 => 0,
        5 => 0,
      ),
      'bundle' => 'none',
      'bundle_selected' => array(
        'article' => 0,
        'page' => 0,
        'collection' => 0,
        'community' => 0,
        'cultural_protocol_group' => 0,
        'digital_heritage' => 0,
        'panel' => 0,
      ),
    ),
    'facet_mincount' => '0',
    'facet_missing' => '0',
    'flatten' => 0,
    'individual_parent' => 0,
    'query_type' => 'term',
    'limit_active_items' => 0,
    'default_true' => '1',
    'facet_search_ids' => array(),
    'exclude' => 0,
    'pretty_paths_alias' => 'field_digital_heritage_count',
  );
  $export['search_api@default_node_index::field_digital_heritage_count'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_node_index:block:field_digital_heritage_count';
  $facet->searcher = 'search_api@default_node_index';
  $facet->realm = 'block';
  $facet->facet = 'field_digital_heritage_count';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_checkbox_links',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'display' => 'display',
      'count' => 'count',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'display' => '-49',
      'count' => '-48',
      'indexed' => '-47',
    ),
    'sort_order' => array(
      'active' => '3',
      'display' => '3',
      'count' => '3',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '10',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'full_html',
    ),
  );
  $export['search_api@default_node_index:block:field_digital_heritage_count'] = $facet;

  return $export;
}
