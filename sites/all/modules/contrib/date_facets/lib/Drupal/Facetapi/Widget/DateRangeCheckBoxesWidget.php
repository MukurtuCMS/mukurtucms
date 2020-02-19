<?php

/**
 * @file
 * Contains Drupal_Apachesolr_Facetapi_Widget_DateRangeCheckBoxesWidget
 */

/**
 * Date range widget with check boxes that displays ranges similar to major
 * search engines.
 *
 * This is an implementation of check boxes links for Date Range Widget
 */
class Drupal_Apachesolr_Facetapi_Widget_DateRangeCheckBoxesWidget extends Drupal_Apachesolr_Facetapi_Widget_DateRangeWidget {

  /**
   * Overrides FacetapiWidgetLinks::init().
   *
   * Adds additional JavaScript settings and CSS.
   */
  public function init() {
    parent::init();
    $this->jsSettings['makeCheckboxes'] = 1;
    drupal_add_css(drupal_get_path('module', 'facetapi') . '/facetapi.css');
  }

  /**
   * Overrides FacetapiWidgetLinks::getItemClasses().
   *
   * Sets the base class for checkbox facet items.
   */
  public function getItemClasses() {
    return array('facetapi-checkbox');
  }
}
