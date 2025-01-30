<?php

/**
 * @file
 * Contains FeedsEntityProcessorPropertyDate.
 */

/**
 * Handler for date property.
 */
class FeedsEntityProcessorPropertyDate extends FeedsEntityProcessorPropertyDefault {

  /**
   * Implements FeedsEntityProcessorPropertyInterface::getFormField().
   *
   * Adds a note about enabling the Date API module.
   */
  public function getFormField(array &$form, array &$form_state, $default) {
    $field = parent::getFormField($form, $form_state, $default);
    if (!module_exists('date_api')) {
      $field['#description'] .= '<br />' . t('Enter a timestamp or enable the Date API module (part of the <a href="@url">Date</a> project) to be able to input the date in various date formats.', array(
        '@url' => 'https://www.drupal.org/project/date',
      ));
    }
    return $field;
  }

  /**
   * {@inheritdoc}
   */
  public function validate(&$value) {
    // Entity API won't accept empty date values.
    if (empty($value)) {
      $value = NULL;
      return array();
    }

    // Convert the date value.
    if (module_exists('date_api') && !is_numeric($value)) {
      $date = $this->convertDate($value);
      // Prevent to save the conversion for the config form.
      $date_value = $date->format('U');
      return parent::validate($date_value);
    }

    return parent::validate($value);
  }

  /**
   * {@inheritdoc}
   */
  public function getMappingTarget() {
    $target = parent::getMappingTarget();

    if (module_exists('date_api')) {
      $target['form_callbacks'][] = array($this, 'mappingFormCallback');
      $target['summary_callbacks'][] = array($this, 'mappingSummaryCallback');
    }

    $target['preprocess_callbacks'][] = array($this, 'preprocessCallback');

    return $target;
  }

  /**
   * Form callback for date targets.
   */
  public function mappingFormCallback(array $mapping, $target, array $form, array $form_state) {
    $mapping += array('timezone' => 'UTC');

    return array(
      'timezone' => array(
        '#type' => 'select',
        '#title' => t('Timezone handling'),
        '#options' => $this->getTimezoneOptions(),
        '#default_value' => $mapping['timezone'],
        '#description' => t('This value will only be used if the timezone is mising.'),
      ),
    );
  }

  /**
   * Summary callback for date targets.
   */
  public function mappingSummaryCallback(array $mapping, $target, array $form, array $form_state) {
    $mapping += array('timezone' => 'UTC');

    $options = $this->getTimezoneOptions();

    return t('Default timezone: %zone', array('%zone' => $options[$mapping['timezone']]));
  }

  /**
   * Preprocess callback for date targets.
   *
   * Used only to issue a warning about limited date import functionality when
   * the date_api module is not enabled.
   */
  public function preprocessCallback(array $target, array &$mapping) {
    if (!module_exists('date_api')) {
      drupal_set_message(t('Dates can only be imported as timestamps now. Enable the Date API module (part of the <a href="@url">Date</a> project) to be able to import dates in various date formats.', array(
        '@url' => 'https://www.drupal.org/project/date',
      )), 'warning', FALSE);
    }
  }

  /**
   * Returns the timezone options.
   *
   * @return array
   *   A map of timezone options.
   */
  protected function getTimezoneOptions() {
    return array(
      '__SITE__' => t('Site default'),
    ) + system_time_zones();
  }

  /**
   * Returns the timezone to be used as the default.
   *
   * @param array $mapping
   *   The mapping array.
   *
   * @return string
   *   The timezone to use as the default.
   */
  protected function getDefaultTimezone(array $mapping) {
    $mapping += array('timezone' => 'UTC');

    if ($mapping['timezone'] === '__SITE__') {
      return variable_get('date_default_timezone', 'UTC');
    }

    return $mapping['timezone'];
  }

  /**
   * Implements FeedsEntityProcessorPropertyInterface::setValue().
   */
  public function setValue($value, array $mapping) {
    // Convert the date value.
    if (module_exists('date_api') && !is_numeric($value)) {
      $default_tz = new DateTimeZone($this->getDefaultTimezone($mapping));

      $date = $this->convertDate($value, $default_tz);
      $value = $date->format('U');
    }

    parent::setValue($value, $mapping);
  }

  /**
   * Converts a date string or object into a DateObject.
   *
   * @param DateTime|string|int $value
   *   The date value or object.
   * @param DateTimeZone $default_tz
   *   The default timezone.
   *
   * @return DateObject
   *   The converted DateObject.
   *
   * @throws RuntimeException
   *   In case the DateObject class does not exist.
   */
  protected function convertDate($value, DateTimeZone $default_tz = NULL) {
    if (!class_exists('DateObject')) {
      if (!module_exist('date_api')) {
        throw new RuntimeException('Enable the date_api module to handle importing dates correctly.');
      }
      else {
        throw new RuntimeException('Class "DateObject" not found. Clear caches or rebuild the Drupal class registry and try again.');
      }
    }

    if (empty($timezone)) {
      $timezone = variable_get('date_default_timezone', 'UTC');
    }

    if ($value instanceof DateObject) {
      return $value;
    }

    // Convert DateTime and FeedsDateTime.
    if ($value instanceof DateTime) {
      if (!$value->getTimezone() || !preg_match('/[a-zA-Z]/', $value->getTimezone()->getName())) {
        $value->setTimezone($default_tz);
      }
      return new DateObject($value->format(DATE_FORMAT_ISO), $value->getTimezone());
    }

    if (is_string($value) || is_object($value) && method_exists($value, '__toString')) {
      $value = trim($value);
    }

    // Filter out meaningless values.
    if (empty($value) || !is_string($value) && !is_int($value)) {
      return FALSE;
    }

    // Support year values.
    if ((string) $value === (string) (int) $value) {
      if ($value >= variable_get('date_min_year', 100) && $value <= variable_get('date_max_year', 4000)) {
        return new DateObject('January ' . $value, $default_tz);
      }
    }

    return new DateObject($value, $default_tz);
  }

}
