<?php

/**
 * @file
 * Contains Drupal_SearchApi_Facetapi_QueryType_DateRangeQueryType.
 */

/**
 * Date range query type plugin for the Apache Solr Search Integration adapter.
 */
class Drupal_SearchApi_Facetapi_QueryType_DateRangeQueryType extends SearchApiFacetapiDate implements FacetapiQueryTypeInterface {

  /**
   * Implements FacetapiQueryTypeInterface::getType().
   */
  static public function getType() {
    return DATE_FACETS_DATE_RANGE_QUERY_TYPE;
  }

  /**
   * Implements FacetapiQueryTypeInterface::execute().
   */
  public function execute($query) {
    $this->adapter->addFacet($this->facet, $query);
    if ($active = $this->adapter->getActiveItems($this->facet)) {
      // Check the first value since only one is allowed.
      $filter = self::mapFacetItemToFilter(key($active), $this->facet);
      if ($filter) {
        $this->addFacetFilter($query, $this->facet['field'], $filter);
      }
    }
  }

  /**
   * Generate valid date ranges (timestamps) to be used in a SQL query.
   */
  protected function generateRange($range = array()) {
    if (empty($range)) {
      $start = REQUEST_TIME;
      $end = REQUEST_TIME + DATE_RANGE_UNIT_DAY;
    }
    else {
      $start = self::rangeToString($range, 'start');
      $end = self::rangeToString($range, 'end');
    }
    return array($start, $end);
  }

  /**
   * Implements FacetapiQueryTypeInterface::build().
   *
   * Unlike normal facets, we provide a static list of options.
   */
  public function build() {
    $facet = $this->adapter->getFacet($this->facet);
    $search_ids = drupal_static('search_api_facetapi_active_facets', array());

    $facet_key = $facet['name'] . '@' . $this->adapter->getSearcher();
    if (empty($search_ids[$facet_key]) || !search_api_current_search($search_ids[$facet_key])) {
      return array();
    }
    $search_id = $search_ids[$facet_key];

    $build = array();
    $search = search_api_current_search($search_id);

    $results = $search[1];
    if (!$results['result count']) {
      return array();
    }

    // Executes query, iterates over results.
    if (isset($results['search_api_facets']) && isset($results['search_api_facets'][$this->facet['field']])) {
      $values = $results['search_api_facets'][$this->facet['field']];

      $realm = facetapi_realm_load('block');
      $settings = $this->adapter->getFacetSettings($this->facet, $realm);
      $ranges = (isset($settings->settings['ranges']) && !empty($settings->settings['ranges']) ? $settings->settings['ranges'] : date_facets_default_ranges());
      // Build the markup for the facet's date ranges.
      $build = date_facets_get_ranges_render_arrays($ranges);

      $ranges_timestamps = array();
      foreach ($ranges as $key => $item) {
        list($start, $end) = $this->generateRange($item);
        $ranges_timestamps[$key] = array('start' => $start, 'end' => $end);
      }

      // Calculate values by facet.
      foreach ($values as $value) {
        $value['filter'] = str_replace('"', '', $value['filter']);

        foreach ($ranges_timestamps as $key => $interval) {
          $future_interval = ($item['date_range_end_op'] == '+' && $interval['start'] <= $value['filter'] && $value['filter'] <= $interval['end']);
          $past_interval = $item['date_range_start_op'] == '-' && $interval['start'] <= $value['filter'] && $value['filter'] <= $interval['end'];
          if ($future_interval || $past_interval) {
            $build[$key]['#count'] += $value['count'];
          }
        }
      }
    }

    // Unset empty items.
    foreach ($build as $key => $item) {
      if ($item['#count'] === NULL) {
        unset($build[$key]);
      }
    }

    // Gets total number of documents matched in search.
    $total = $results['result count'];
    $keys_of_active_facets = array();
    // Gets active facets, starts building hierarchy.
    foreach ($this->adapter->getActiveItems($this->facet) as $key => $item) {
      // If the item is active, the count is the result set count.
      $build[$key]['#count'] = $total;
      $keys_of_active_facets[] = $key;
    }

    // If we have active item, unset other items.
    $settings = $facet->getSettings()->settings;
    if ((isset($settings['operator'])) && ($settings['operator'] !== FACETAPI_OPERATOR_OR)) {
      if (!empty($keys_of_active_facets)) {
        foreach ($build as $key => $item) {
          if (!in_array($key, $keys_of_active_facets)) {
            unset($build[$key]);
          }
        }
      }
    }

    return $build;
  }

  /**
   * Maps a facet item to a filter.
   *
   * @param string $range_machine_name
   *   For example 'past_hour'.
   *
   * @return string|false
   *   A string that can be used as a filter, false if no filter was found.
   */
  public static function mapFacetItemToFilter($range_machine_name, $facet) {
    $ranges = date_facets_get_ranges($facet['name'], $facet['map options']['index id']);

    $filter_str = FALSE;
    if (isset($ranges[$range_machine_name])) {
      $start = self::rangeToString($ranges[$range_machine_name], 'start');
      $end = self::rangeToString($ranges[$range_machine_name], 'end');
      // Future.
      if ($ranges[$range_machine_name]['date_range_end_op'] == '+') {
        $filter_str = "[$start TO $end]";
      }
      // Past. We should reverse intervals.
      elseif ($ranges[$range_machine_name]['date_range_start_op'] == '-') {
        $filter_str = "[$start TO $end]";
      }
    }

    return $filter_str;
  }

  /**
   * Convert a range setting to a timestamp.
   *
   * @param array $range_config
   *   Settings array from a range
   *
   * @param string $part
   *   Whether it's the start or end part of the range config you want to convert
   *
   * @return number
   */
  public static function rangeToString($range_config, $part) {
    if ($range_config["date_range_{$part}_op"] == 'NOW') {
      return REQUEST_TIME;
    }
    else {
      return strtotime(
        "{$range_config["date_range_{$part}_op"]} "
          . "{$range_config["date_range_{$part}_amount"]} "
          . "{$range_config["date_range_{$part}_unit"]}"
      );
    }
  }
}
