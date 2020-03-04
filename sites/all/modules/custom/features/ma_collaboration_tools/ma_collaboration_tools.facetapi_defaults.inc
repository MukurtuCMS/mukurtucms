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
  $facet->name = 'search_api@document_pages::changed';
  $facet->searcher = 'search_api@document_pages';
  $facet->realm = '';
  $facet->facet = 'changed';
  $facet->enabled = TRUE;
  $facet->hash = 'TqDHVYk1sB6Kb3xC6o0y9qcMQivNxut9';
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
    'pretty_paths_alias' => 'changed',
  );
  $export['search_api@document_pages::changed'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@document_pages::created';
  $facet->searcher = 'search_api@document_pages';
  $facet->realm = '';
  $facet->facet = 'created';
  $facet->enabled = TRUE;
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
    'pretty_paths_alias' => 'added',
  );
  $export['search_api@document_pages::created'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@document_pages:block:changed';
  $facet->searcher = 'search_api@document_pages';
  $facet->realm = 'block';
  $facet->facet = 'changed';
  $facet->enabled = TRUE;
  $facet->hash = 'ltOeomJN7uPfANVEHAarPnnGf9qhgx65';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_links',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
    ),
    'sort_weight' => array(
      'active' => -50,
      'count' => -49,
      'display' => -48,
    ),
    'sort_order' => array(
      'active' => 3,
      'count' => 3,
      'display' => 4,
    ),
    'empty_behavior' => 'none',
    'display_count' => TRUE,
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'title_override' => 0,
    'title' => 'Date changed',
    'soft_limit' => 20,
    'nofollow' => 1,
    'show_expanded' => 0,
  );
  $export['search_api@document_pages:block:changed'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@document_pages:block:created';
  $facet->searcher = 'search_api@document_pages';
  $facet->realm = 'block';
  $facet->facet = 'created';
  $facet->enabled = TRUE;
  $facet->hash = '1RaG9JiXm2VBg0KxlVPk1lptvT4ZbXCY';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_links',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
    ),
    'sort_weight' => array(
      'active' => -50,
      'count' => -49,
      'display' => -48,
    ),
    'sort_order' => array(
      'active' => 3,
      'count' => 3,
      'display' => 4,
    ),
    'empty_behavior' => 'none',
    'display_count' => TRUE,
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'title_override' => 0,
    'title' => 'Date created',
    'soft_limit' => 20,
    'nofollow' => 1,
    'show_expanded' => 0,
  );
  $export['search_api@document_pages:block:created'] = $facet;

  return $export;
}
