<?php

/**
 * @file
 * ma_dictionary.facetapi_defaults.inc
 */

/**
 * Implements hook_facetapi_default_facet_settings().
 */
function ma_dictionary_facetapi_default_facet_settings() {
  $export = array();

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_node_index::field_dictionary_word_language';
  $facet->searcher = 'search_api@default_node_index';
  $facet->realm = '';
  $facet->facet = 'field_dictionary_word_language';
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
    'pretty_paths_alias' => 'language',
    'pretty_paths_taxonomy_pathauto' => 1,
    'pretty_paths_taxonomy_pathauto_vocabulary' => 'language',
    'query_type' => 'term',
  );
  $export['search_api@default_node_index::field_dictionary_word_language'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_node_index::field_dictionary_word_related_dh';
  $facet->searcher = 'search_api@default_node_index';
  $facet->realm = '';
  $facet->facet = 'field_dictionary_word_related_dh';
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
    'pretty_paths_alias' => 'related-dh',
    'query_type' => 'term',
  );
  $export['search_api@default_node_index::field_dictionary_word_related_dh'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_node_index::field_related_dictionary_words';
  $facet->searcher = 'search_api@default_node_index';
  $facet->realm = '';
  $facet->facet = 'field_related_dictionary_words';
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
    'pretty_paths_alias' => 'related-words',
    'query_type' => 'term',
  );
  $export['search_api@default_node_index::field_related_dictionary_words'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_node_index::field_translation';
  $facet->searcher = 'search_api@default_node_index';
  $facet->realm = '';
  $facet->facet = 'field_translation';
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
    'pretty_paths_alias' => 'translation',
    'query_type' => 'term',
  );
  $export['search_api@default_node_index::field_translation'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_node_index::field_word_list';
  $facet->searcher = 'search_api@default_node_index';
  $facet->realm = '';
  $facet->facet = 'field_word_list';
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
    'pretty_paths_alias' => 'field_word_list',
    'query_type' => 'term',
  );
  $export['search_api@default_node_index::field_word_list'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_node_index::field_words';
  $facet->searcher = 'search_api@default_node_index';
  $facet->realm = '';
  $facet->facet = 'field_words';
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
    'pretty_paths_alias' => 'field_words',
    'query_type' => 'term',
  );
  $export['search_api@default_node_index::field_words'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_node_index::title_az_glossary';
  $facet->searcher = 'search_api@default_node_index';
  $facet->realm = '';
  $facet->facet = 'title_az_glossary';
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
        'glossary' => 0,
        'glossary_term' => 0,
        'page' => 0,
        'panel' => 0,
      ),
      'roles' => array(
        1 => 0,
        2 => 0,
        3 => 0,
        4 => 0,
        5 => 0,
        6 => 0,
      ),
    ),
    'exclude' => 0,
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'facet_search_ids' => array(),
    'flatten' => 0,
    'hard_limit' => '-1',
    'individual_parent' => 0,
    'limit_active_items' => 0,
    'operator' => 'or',
    'pretty_paths_alias' => 'title',
    'query_type' => 'term',
    'title_az_glossary_field' => '',
  );
  $export['search_api@default_node_index::title_az_glossary'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_node_index:block:field_dictionary_word_language';
  $facet->searcher = 'search_api@default_node_index';
  $facet->realm = 'block';
  $facet->facet = 'field_dictionary_word_language';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'glossary_az' => 0,
      'indexed' => 0,
    ),
    'empty_behavior' => 'none',
    'empty_text' => array(
      'format' => 'filtered_html',
      'value' => '',
    ),
    'facet_fewer_text' => 'Show fewer',
    'facet_more_text' => 'Show more',
    'filters' => array(),
    'nofollow' => 1,
    'show_all' => 1,
    'show_count' => 1,
    'show_expanded' => 0,
    'soft_limit' => '50',
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'glossary_az' => '4',
      'indexed' => '4',
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'glossary_az' => '0',
      'indexed' => '0',
    ),
    'weight' => 0,
    'widget' => 'facetapi_checkbox_links',
  );
  $export['search_api@default_node_index:block:field_dictionary_word_language'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_node_index:block:field_dictionary_word_related_dh';
  $facet->searcher = 'search_api@default_node_index';
  $facet->realm = 'block';
  $facet->facet = 'field_dictionary_word_related_dh';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'glossary_az' => 0,
      'indexed' => 0,
    ),
    'empty_behavior' => 'none',
    'empty_text' => array(
      'format' => 'filtered_html',
      'value' => '',
    ),
    'facet_fewer_text' => 'Show fewer',
    'facet_more_text' => 'Show more',
    'filters' => array(),
    'nofollow' => 1,
    'show_all' => 1,
    'show_count' => 1,
    'show_expanded' => 0,
    'soft_limit' => '50',
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'glossary_az' => '4',
      'indexed' => '4',
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'glossary_az' => '0',
      'indexed' => '0',
    ),
    'weight' => 0,
    'widget' => 'facetapi_checkbox_links',
  );
  $export['search_api@default_node_index:block:field_dictionary_word_related_dh'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_node_index:block:field_related_dictionary_words';
  $facet->searcher = 'search_api@default_node_index';
  $facet->realm = 'block';
  $facet->facet = 'field_related_dictionary_words';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'glossary_az' => 0,
      'indexed' => 0,
    ),
    'empty_behavior' => 'none',
    'empty_text' => array(
      'format' => 'filtered_html',
      'value' => '',
    ),
    'facet_fewer_text' => 'Show fewer',
    'facet_more_text' => 'Show more',
    'filters' => array(),
    'nofollow' => 1,
    'show_all' => 1,
    'show_count' => 1,
    'show_expanded' => 0,
    'soft_limit' => '50',
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'glossary_az' => '4',
      'indexed' => '4',
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'glossary_az' => '0',
      'indexed' => '0',
    ),
    'weight' => 0,
    'widget' => 'facetapi_checkbox_links',
  );
  $export['search_api@default_node_index:block:field_related_dictionary_words'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_node_index:block:field_translation';
  $facet->searcher = 'search_api@default_node_index';
  $facet->realm = 'block';
  $facet->facet = 'field_translation';
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
      'format' => 'filtered_html',
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
  $export['search_api@default_node_index:block:field_translation'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_node_index:block:field_word_entry:field_part_of_speech';
  $facet->searcher = 'search_api@default_node_index';
  $facet->realm = 'block';
  $facet->facet = 'field_word_entry:field_part_of_speech';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'glossary_az' => 0,
      'indexed' => 0,
    ),
    'empty_behavior' => 'none',
    'empty_text' => array(
      'format' => 'filtered_html',
      'value' => '',
    ),
    'facet_fewer_text' => 'Show fewer',
    'facet_more_text' => 'Show more',
    'filters' => array(),
    'nofollow' => 1,
    'show_all' => 1,
    'show_count' => 1,
    'show_expanded' => 0,
    'soft_limit' => '20',
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'glossary_az' => '4',
      'indexed' => '4',
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'glossary_az' => '0',
      'indexed' => '0',
    ),
    'weight' => 0,
    'widget' => 'facetapi_checkbox_links',
  );
  $export['search_api@default_node_index:block:field_word_entry:field_part_of_speech'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_node_index:block:field_word_list';
  $facet->searcher = 'search_api@default_node_index';
  $facet->realm = 'block';
  $facet->facet = 'field_word_list';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'glossary_az' => 0,
      'indexed' => 0,
    ),
    'empty_behavior' => 'none',
    'empty_text' => array(
      'format' => 'filtered_html',
      'value' => '',
    ),
    'facet_fewer_text' => 'Show fewer',
    'facet_more_text' => 'Show more',
    'filters' => array(),
    'nofollow' => 1,
    'show_all' => 1,
    'show_count' => 1,
    'show_expanded' => 0,
    'soft_limit' => '20',
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'glossary_az' => '4',
      'indexed' => '4',
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'glossary_az' => '0',
      'indexed' => '0',
    ),
    'weight' => 0,
    'widget' => 'facetapi_checkbox_links',
  );
  $export['search_api@default_node_index:block:field_word_list'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_node_index:block:field_words';
  $facet->searcher = 'search_api@default_node_index';
  $facet->realm = 'block';
  $facet->facet = 'field_words';
  $facet->enabled = FALSE;
  $facet->hash = '0';
  $facet->settings = array(
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'glossary_az' => 0,
      'indexed' => 0,
    ),
    'empty_behavior' => 'none',
    'empty_text' => array(
      'format' => 'filtered_html',
      'value' => '',
    ),
    'facet_fewer_text' => 'Show fewer',
    'facet_more_text' => 'Show more',
    'filters' => array(),
    'nofollow' => 1,
    'show_all' => 1,
    'show_count' => 1,
    'show_expanded' => 0,
    'soft_limit' => '20',
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'glossary_az' => '4',
      'indexed' => '4',
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'glossary_az' => '0',
      'indexed' => '0',
    ),
    'weight' => 0,
    'widget' => 'facetapi_checkbox_links',
  );
  $export['search_api@default_node_index:block:field_words'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_node_index:block:title_az_glossary';
  $facet->searcher = 'search_api@default_node_index';
  $facet->realm = 'block';
  $facet->facet = 'title_az_glossary';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'active_sorts' => array(
      'active' => 'active',
      'count' => 0,
      'display' => 0,
      'glossary_az' => 'glossary_az',
      'indexed' => 0,
    ),
    'empty_behavior' => 'none',
    'empty_text' => array(
      'format' => 'filtered_html',
      'value' => '',
    ),
    'facet_fewer_text' => 'Show fewer',
    'facet_more_text' => 'Show more',
    'filters' => array(
      'active_items' => array(
        'status' => 0,
        'weight' => '-50',
      ),
      'glossary_rewrite_items' => array(
        'status' => 1,
        'weight' => '-49',
      ),
    ),
    'nofollow' => 1,
    'show_all' => 0,
    'show_count' => 0,
    'show_expanded' => 0,
    'soft_limit' => '50',
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'glossary_az' => '4',
      'indexed' => '4',
    ),
    'sort_weight' => array(
      'active' => '-49',
      'count' => '-48',
      'display' => '-47',
      'glossary_az' => '-50',
      'indexed' => '-46',
    ),
    'weight' => 0,
    'widget' => 'search_api_glossary',
  );
  $export['search_api@default_node_index:block:title_az_glossary'] = $facet;

  return $export;
}
