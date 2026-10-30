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
  $facet->hash = '0';
  $facet->settings = array(
    'default_true' => '1',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(
        'article' => 0,
        'collection' => 0,
        'community' => 0,
        'cultural_protocol_group' => 0,
        'digital_heritage' => 0,
        'page' => 0,
        'panel' => 0,
      ),
      'roles' => array(
        1 => 0,
        2 => 0,
        3 => 0,
        4 => '4',
        5 => 0,
        6 => '6',
      ),
    ),
    'exclude' => 0,
    'facet_mincount' => '0',
    'facet_missing' => '0',
    'facet_search_ids' => array(),
    'flatten' => 0,
    'hard_limit' => '-1',
    'individual_parent' => 0,
    'limit_active_items' => 0,
    'operator' => 'and',
    'pretty_paths_alias' => 'field_digital_heritage_count',
    'query_type' => 'term',
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
  $facet->hash = '0';
  $facet->settings = array(
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'empty_behavior' => 'none',
    'empty_text' => array(
      'format' => 'full_html',
      'value' => '',
    ),
    'facet_fewer_text' => 'Show fewer',
    'facet_more_text' => 'Show more',
    'filters' => array(),
    'nofollow' => 1,
    'show_expanded' => 0,
    'soft_limit' => '10',
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '3',
      'indexed' => '4',
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-48',
      'display' => '-49',
      'indexed' => '-47',
    ),
    'weight' => 0,
    'widget' => 'facetapi_checkbox_links',
  );
  $export['search_api@default_node_index:block:field_digital_heritage_count'] = $facet;

  return $export;
}
