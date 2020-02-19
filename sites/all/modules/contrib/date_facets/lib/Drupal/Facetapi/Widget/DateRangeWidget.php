<?php

/**
 * @file
 * Contains Drupal_Apachesolr_Facetapi_QueryType_DateRangeQueryType
 */

/**
 * Date range widget that displays ranges similar to major search engines.
 *
 * There is a hack in place that only allows one item to be active at a time
 * since if would make sense to have multiple active values.
 */
class Drupal_Apachesolr_Facetapi_Widget_DateRangeWidget extends FacetapiWidgetLinks {

  /**
   * Overrides FacetapiWidget::settingsForm().
   */
  function settingsForm(&$form, &$form_state) {
    parent::settingsForm($form, $form_state);
    unset($form['widget']['widget_settings']['links'][$this->id]['soft_limit']);
    unset($form['widget']['widget_settings']['links'][$this->id]['show_expanded']);
  }

  /**
   * Overrides FacetapiWidget::getDefaultSettings().
   */
  function getDefaultSettings() {
    return array(
      'nofollow' => 1,
    );
  }
}
