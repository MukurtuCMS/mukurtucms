<?php

/**
 * @file
 *   Contains the SearchApiViewsHandlerFilterLanguage class.
 */

/**
 * Views filter handler class for handling the special "Item language" field.
 *
 * Definition items:
 * - options: An array of possible values for this field.
 */
class SearchApiViewsHandlerFilterLanguage extends SearchApiViewsHandlerFilterOptions {

  /**
   * {@inheritdoc}
   */
  protected function get_value_options() {
    parent::get_value_options();
    $options = array();
    if (module_exists('language_hierarchy')) {
      $options['fallback'] = t("Current user's language with fallback");
    }
    $options['current'] = t("Current user's language");
    $options['default'] = t('Default site language');
    $this->value_options = $options + $this->value_options;
  }

  /**
   * Add this filter to the query.
   */
  public function query() {
    global $language_content;

    if (!is_array($this->value)) {
      $this->value = $this->value ? array($this->value) : array();
    }
    foreach ($this->value as $i => $v) {
      if ($v == 'current') {
        $this->value[$i] = $language_content->language;
      }
      elseif ($v == 'default') {
        $this->value[$i] = language_default('language');
      }
      elseif ($v == 'fallback' && module_exists('language_hierarchy')) {
        $fallbacks = array($language_content->language => $language_content->language);
        $fallbacks += array_keys(language_hierarchy_get_ancestors($language_content->language));
        $this->value[$i] = drupal_map_assoc($fallbacks);
      }
    }
    parent::query();
  }

}
