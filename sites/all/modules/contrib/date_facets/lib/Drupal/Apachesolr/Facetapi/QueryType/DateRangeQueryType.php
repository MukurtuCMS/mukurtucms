<?php

/**
 * @file
 * Contains Drupal_Apachesolr_Facetapi_QueryType_DateRangeQueryType.
 */

/**
 * Date range query type plugin for the Apache Solr Search Integration adapter.
 */
class Drupal_Apachesolr_Facetapi_QueryType_DateRangeQueryType extends FacetapiQueryType implements FacetapiQueryTypeInterface {

  /**
   * Implements FacetapiQueryTypeInterface::getType().
   */
  static public function getType() {
    return DATE_FACETS_DATE_RANGE_QUERY_TYPE;
  }

  /**
   * Implements FacetapiQueryTypeInterface::execute().
   *
   * @see http://searchhub.org/dev/2012/02/23/date-math-now-and-filter-queries/
   */
  public function execute($query) {
    $active = $this->getActiveItems();

    $settings = $this->adapter->getFacetSettings($this->facet, facetapi_realm_load('block'));
    // Get the configured date ranges, or the default ranges if none have been
    // set up already.
    $ranges = (isset($settings->settings['ranges']) ? $settings->settings['ranges'] : date_facets_default_ranges());

    // We generate the ranges and add them to the facet query to get facet counts.
    foreach (array_merge($ranges, date_facets_default_ranges()) as $range) {
      list($start, $end) = $this->generateRange($range, $this->facet['field']);
      $query->addParam('facet.query', $this->facet['field'] . ":[$start TO $end]");
    }

    // Generate the date range and add it as a filter.
    if (!empty($active)) {
      $range = $ranges[key($active)];
      list($start, $end) = $this->generateRange($range, $this->facet['field']);
      $query->addParam('fq', $this->facet['field'] . ":[$start TO $end]");
    }
  }

  /**
   * Return the divisor for the given unit.
   */
  protected function unitDivisor($unit) {
    switch ($unit) {
      case "HOUR":
        return "HOUR";
      case "DAY":
        return "DAY";
      case "MONTH":
      case "YEAR":
        return "MONTH";
    }
  }

  /**
   * Generate a Solr version of a lower and upper date range.
   */
  protected function generateRange($range, $field = NULL) {
    if ($range['date_range_start_op'] == 'NOW') {
      $lower = "NOW/DAY";
    }
    else {
      $s = (((int) abs($range['date_range_start_amount']) > 1) ? 'S' : '');
      $lower = "NOW/" . $this->unitDivisor($range['date_range_start_unit']) . $range['date_range_start_op'] . $range['date_range_start_amount'] . $range['date_range_start_unit'] . $s;
    }
    if ($range['date_range_end_op'] == 'NOW') {
      $upper = "NOW/DAY+1DAY";
    }
    else {
      $s = (((int) abs($range['date_range_end_amount']) > 1) ? 'S' : '');
      $upper = "NOW/" . $this->unitDivisor($range['date_range_end_unit']) . $range['date_range_end_op'] . $range['date_range_end_amount'] . $range['date_range_end_unit'] . $s;
    }

    if (!empty($field) && !SolrBaseQuery::validFilterValue($field . ":[$lower TO $upper]")) {
      $lower = "NOW/DAY";
      $upper = "NOW/DAY+1DAY";
    }

    return array($lower, $upper);
  }

  /**
   * Implements FacetapiQueryTypeInterface::build().
   *
   * Unlike normal facets, we provide a static list of options.
   */
  public function build() {
    // Get facet's configured date ranges, or defaults if none have been set up.
    $settings = $this->adapter->getFacetSettings($this->facet, facetapi_realm_load('block'));
    $ranges = (isset($settings->settings['ranges']) && !empty($settings->settings['ranges']) ? $settings->settings['ranges'] : date_facets_default_ranges());
    // Build the markup for the date ranges.
    $build = date_facets_get_ranges_render_arrays($ranges);

    if ($response = apachesolr_static_response_cache($this->adapter->getSearcher())) {
      $facet_global_settings = $this->adapter->getFacet($this->facet)->getSettings();
      $values = (array) $response->facet_counts->facet_queries;
      // Add result counts from the facet queries added in execute().
      foreach ($ranges as $range) {
        list($start, $end) = $this->generateRange($range);
        $build[$range['machine_name']]['#count'] = $values[($this->facet['field'] . ":[$start TO $end]")];
      }
      // Unset options with fewer results than the minimum count setting.
      foreach ($build as $name => $item) {
        if ($item['#count'] < $facet_global_settings->settings['facet_mincount']) {
          unset($build[$name]);
        }
      }
    }
    return $build;
  }
}
