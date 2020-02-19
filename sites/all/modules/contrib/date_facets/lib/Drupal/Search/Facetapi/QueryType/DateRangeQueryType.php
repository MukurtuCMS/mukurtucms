<?php

/**
 * @file
 * Contains Drupal_Search_Facetapi_QueryType_DateRangeQueryType.
 */

/**
 * Date range query type plugin for the core Search adapter.
 */
class Drupal_Search_Facetapi_QueryType_DateRangeQueryType extends FacetapiQueryType implements FacetapiQueryTypeInterface {

  /**
   * Implements FacetapiQueryTypeInterface::getType().
   */
  static public function getType() {
    return DATE_FACETS_DATE_RANGE_QUERY_TYPE;
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
      // Generate the timestamp for both start and end date ranges.
      foreach (array('start', 'end') as $item) {
        // Start by initializing it to the current time.
        $$item = REQUEST_TIME;
        $unit = $range['date_range_' . $item . '_unit'];
        $amount = (int) $range['date_range_' . $item . '_amount'];
        switch ($unit) {
          case 'HOUR':
            $unit = (int) DATE_RANGE_UNIT_HOUR;
            break;
          case 'DAY':
            $unit = (int) DATE_RANGE_UNIT_DAY;
            break;
          case 'MONTH':
            $unit = (int) DATE_RANGE_UNIT_MONTH;
            break;
          case 'YEAR':
            $unit = (int) DATE_RANGE_UNIT_YEAR;
            break;
        }
        // Based on which operation, either add or subtract the appropriate
        // amount from the time.
        // In each case, the amount we subtract is the amount of the unit, times
        // the value of the unit.
        switch ($range['date_range_' . $item . '_op']) {
          case '-':
            $$item -= ($amount * $unit);
            break;
          case '+':
            $$item += ($amount * $unit);
            break;
        }
      }
      // If the ops are NOW, we set the times accordingly.
      if ($range['date_range_start_op'] == 'NOW') {
        $start = REQUEST_TIME;
      }
      if ($range['date_range_end_op'] == 'NOW') {
        $end = REQUEST_TIME + (int) DATE_RANGE_UNIT_DAY;
      }
    }
    return array($start, $end);
  }

  /**
   * Implements FacetapiQueryTypeInterface::execute().
   */
  public function execute($query) {
    $active = $this->getActiveItems();

    if (!empty($active)) {

      $facet_query = $this->adapter->getFacetQueryExtender();
      $query_info = $this->adapter->getQueryInfo($this->facet);
      $tables_joined = array();

      // Get the configured date ranges for the facet, or defaults if none have
      // been set up.
      $settings = $this->adapter->getFacetSettings($this->facet, facetapi_realm_load('block'));
      $ranges = (isset($settings->settings['ranges']) ? $settings->settings['ranges'] : date_facets_default_ranges());

      // Generate our start and end filters since a facet has been chosen.
      $range = $ranges[key($active)];
      list($start, $end) = $this->generateRange($range);

      // Iterate over the facet's fields and adds SQL clauses.
      foreach ($query_info['fields'] as $field_info) {

        // Adds join to the facet query.
        $facet_query->addFacetJoin($query_info, $field_info['table_alias']);

        // Adds adds join to search query, makes sure it is only added once.
        if (isset($query_info['joins'][$field_info['table_alias']])) {
          if (!isset($tables_joined[$field_info['table_alias']])) {
            $tables_joined[$field_info['table_alias']] = TRUE;
            $join_info = $query_info['joins'][$field_info['table_alias']];
            $query->join($join_info['table'], $join_info['alias'], $join_info['condition']);
          }
        }

        // Adds field conditions to the facet and search query.
        $field = $field_info['table_alias'] . '.' . $this->facet['field'];
        $query->condition($field, $start, '>=');
        $query->condition($field, $end, '<');
        $facet_query->condition($field, $start, '>=');
        $facet_query->condition($field, $end, '<');
      }
    }
  }

  /**
   * Implements FacetapiQueryTypeInterface::build().
   */
  public function build() {
    // Get the configured date ranges for the facet, or defaults if none have
    // been set up.
    $realm = facetapi_realm_load('block');
    $settings = $this->adapter->getFacetSettings($this->facet, $realm);
    $ranges = (isset($settings->settings['ranges']) && !empty($settings->settings['ranges']) ? $settings->settings['ranges'] : date_facets_default_ranges());

    // Build the markup for the facet's date ranges.
    $build = date_facets_get_ranges($ranges);

    if ($this->adapter->searchExecuted()) {
      $facet_global_settings = $this->adapter->getFacet($this->facet)->getSettings();
      // Iterate over each date range to get a count of results for that item.
      foreach ($ranges as $range) {
        // Generate our conditions for this date range.
        list($start, $end) = $this->generateRange($range);

        // We need to clone the query so we can get a count for each of our
        // date ranges.
        $facet_query = clone $this->adapter->getFacetQueryExtender();
        $query_info = $this->adapter->getQueryInfo($this->facet);
        $facet_query->addFacetField($query_info);

        // Add the appropriate joins to our query, and add our date range
        // conditions.
        foreach ($query_info['fields'] as $field_info) {
          $facet_query->addFacetJoin($query_info, $field_info['table_alias']);
          $field = $field_info['table_alias'] . '.' . $this->facet['field'];
          $facet_query->condition($field, $start, '>=');
          $facet_query->condition($field, $end, '<');
        }
        // Executes query, iterates over results.
        $result = $facet_query->execute()->fetchAll();
        // If the result is 0, and the mincount is set to more than 0, remove
        // the facet option.
        if (empty($result)
          && $facet_global_settings->settings['facet_mincount'] > 0) {
          unset($build[$range['machine_name']]);
        }
        // Add the facet option counts to the build array.
        foreach ($result as $record) {
          $build[$range['machine_name']]['#count'] = $record->count;
        }
      }
    }
    return $build;
  }
}
