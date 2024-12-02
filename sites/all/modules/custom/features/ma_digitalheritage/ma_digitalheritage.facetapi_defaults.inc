<?php

/**
 * @file
 * ma_digitalheritage.facetapi_defaults.inc
 */

/**
 * Implements hook_facetapi_default_facet_settings().
 */
function ma_digitalheritage_facetapi_default_facet_settings() {
  $export = array();

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_node_index::field_category';
  $facet->searcher = 'search_api@default_node_index';
  $facet->realm = '';
  $facet->facet = 'field_category';
  $facet->enabled = FALSE;
  $facet->hash = '0';
  $facet->settings = array(
    'default_true' => '1',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
      'roles' => array(),
    ),
    'exclude' => 0,
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'facet_search_ids' => array(),
    'flatten' => '0',
    'hard_limit' => '-1',
    'individual_parent' => '0',
    'limit_active_items' => 0,
    'operator' => 'and',
    'pretty_paths_alias' => 'category',
    'pretty_paths_taxonomy_pathauto' => 1,
    'pretty_paths_taxonomy_pathauto_vocabulary' => 'category',
    'query_type' => 'term',
  );
  $export['search_api@default_node_index::field_category'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_node_index::field_collection';
  $facet->searcher = 'search_api@default_node_index';
  $facet->realm = '';
  $facet->facet = 'field_collection';
  $facet->enabled = FALSE;
  $facet->hash = '0';
  $facet->settings = array(
    'default_true' => '1',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
      'roles' => array(),
    ),
    'exclude' => 0,
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'facet_search_ids' => array(),
    'flatten' => 0,
    'hard_limit' => '-1',
    'individual_parent' => 0,
    'limit_active_items' => 0,
    'operator' => 'and',
    'pretty_paths_alias' => 'field_collection',
    'query_type' => 'term',
  );
  $export['search_api@default_node_index::field_collection'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_node_index::field_community_ref';
  $facet->searcher = 'search_api@default_node_index';
  $facet->realm = '';
  $facet->facet = 'field_community_ref';
  $facet->enabled = FALSE;
  $facet->hash = '0';
  $facet->settings = array(
    'default_true' => '1',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
      'roles' => array(),
    ),
    'exclude' => 0,
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'facet_search_ids' => array(),
    'flatten' => 0,
    'hard_limit' => '-1',
    'individual_parent' => 0,
    'limit_active_items' => 0,
    'operator' => 'and',
    'pretty_paths_alias' => 'community',
    'query_type' => 'term',
  );
  $export['search_api@default_node_index::field_community_ref'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_node_index::field_media_asset:type';
  $facet->searcher = 'search_api@default_node_index';
  $facet->realm = '';
  $facet->facet = 'field_media_asset:type';
  $facet->enabled = FALSE;
  $facet->hash = '0';
  $facet->settings = array(
    'default_true' => '1',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
      'roles' => array(),
    ),
    'exclude' => 0,
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'facet_search_ids' => array(),
    'flatten' => 0,
    'hard_limit' => '-1',
    'individual_parent' => 0,
    'limit_active_items' => 0,
    'operator' => 'and',
    'pretty_paths_alias' => 'media-type',
    'query_type' => 'term',
  );
  $export['search_api@default_node_index::field_media_asset:type'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_node_index::field_tags';
  $facet->searcher = 'search_api@default_node_index';
  $facet->realm = '';
  $facet->facet = 'field_tags';
  $facet->enabled = FALSE;
  $facet->hash = '0';
  $facet->settings = array(
    'default_true' => '1',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
      'roles' => array(),
    ),
    'exclude' => 0,
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'facet_search_ids' => array(),
    'flatten' => '0',
    'hard_limit' => '-1',
    'individual_parent' => '0',
    'limit_active_items' => 0,
    'operator' => 'and',
    'pretty_paths_alias' => 'keywords',
    'pretty_paths_taxonomy_pathauto' => 1,
    'pretty_paths_taxonomy_pathauto_vocabulary' => 'tags',
    'query_type' => 'term',
  );
  $export['search_api@default_node_index::field_tags'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_node_index:block:field_category';
  $facet->searcher = 'search_api@default_node_index';
  $facet->realm = 'block';
  $facet->facet = 'field_category';
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
    'soft_limit' => '20',
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'weight' => 0,
    'widget' => 'facetapi_checkbox_links',
  );
  $export['search_api@default_node_index:block:field_category'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_node_index:block:field_collection';
  $facet->searcher = 'search_api@default_node_index';
  $facet->realm = 'block';
  $facet->facet = 'field_collection';
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
    'soft_limit' => '20',
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'weight' => 0,
    'widget' => 'facetapi_checkbox_links',
  );
  $export['search_api@default_node_index:block:field_collection'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_node_index:block:field_community_ref';
  $facet->searcher = 'search_api@default_node_index';
  $facet->realm = 'block';
  $facet->facet = 'field_community_ref';
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
    'soft_limit' => '20',
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'weight' => 0,
    'widget' => 'facetapi_checkbox_links',
  );
  $export['search_api@default_node_index:block:field_community_ref'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_node_index:block:field_media_asset:type';
  $facet->searcher = 'search_api@default_node_index';
  $facet->realm = 'block';
  $facet->facet = 'field_media_asset:type';
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
    'soft_limit' => '20',
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'weight' => 0,
    'widget' => 'facetapi_checkbox_links',
  );
  $export['search_api@default_node_index:block:field_media_asset:type'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_node_index:block:field_tags';
  $facet->searcher = 'search_api@default_node_index';
  $facet->realm = 'block';
  $facet->facet = 'field_tags';
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
    'soft_limit' => '20',
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'weight' => 0,
    'widget' => 'facetapi_checkbox_links',
  );
  $export['search_api@default_node_index:block:field_tags'] = $facet;

  return $export;
}
