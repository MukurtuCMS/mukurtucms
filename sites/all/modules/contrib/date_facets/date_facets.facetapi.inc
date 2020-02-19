<?php

/**
 * @file
 * Facet API hook implementations.
 */

/**
 * Implements hook_facetapi_widgets().
 */
function date_facets_facetapi_widgets() {
  return array(
    'date_range' => array(
      'handler' => array(
        'label' => t('Date range'),
        'class' => 'Drupal_Apachesolr_Facetapi_Widget_DateRangeWidget',
        'query types' => array(DATE_FACETS_DATE_RANGE_QUERY_TYPE),
      ),
    ),
    'date_range_checkboxes' => array(
      'handler' => array(
        'label' => t('Date range with checkboxes'),
        'class' => 'Drupal_Apachesolr_Facetapi_Widget_DateRangeCheckBoxesWidget',
        'query types' => array(DATE_FACETS_DATE_RANGE_QUERY_TYPE),
      ),
    ),
  );
}

/**
 * Implements hook_facetapi_query_types().
 */
function date_facets_facetapi_query_types() {
  return array(
    'apachesolr_date_range' => array(
      'handler' => array(
        'class' => 'Drupal_Apachesolr_Facetapi_QueryType_DateRangeQueryType',
        'adapter' => 'apachesolr',
      ),
    ),
    'search_date_range' => array(
      'handler' => array(
        'class' => 'Drupal_Search_Facetapi_QueryType_DateRangeQueryType',
        'adapter' => 'search',
      ),
    ),
    'search_api_date_range' => array(
      'handler' => array(
        'class' => 'Drupal_SearchApi_Facetapi_QueryType_DateRangeQueryType',
        'adapter' => 'search_api',
      ),
    )
  );
}
