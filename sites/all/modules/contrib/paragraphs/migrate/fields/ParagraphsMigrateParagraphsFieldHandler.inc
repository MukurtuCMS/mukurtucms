<?php

/**
 * Class ParagraphsMigrateParagraphsFieldHandler
 *
 * Provides migrate field handler for paragraphs field.
 */
class ParagraphsMigrateParagraphsFieldHandler extends MigrateSimpleFieldHandler {

  /**
   * @inheritdoc
   */
  public function __construct() {
    parent::__construct(array(
      'value_key' => 'value',
      'skip_empty' => TRUE,
    ));
    $this->registerTypes(array('paragraphs'));
  }

  /**
   * Provide additional fields for migration.
   *
   * @param $type
   * @param $instance
   * @param null $migration
   *
   * @return array
   */
  public function fields($type, $instance, $migration = NULL) {
    return array(
      'revision_id' => t('Option: Provide optional revision id.'),
    );
  }

  /**
   * @inheritdoc
   */
  protected function notNull($value) {
    return !is_null($value) && $value !== FALSE;
  }

  /**
   * @inheritdoc
   */
  public function prepare($entity, array $field_info, array $instance, array $values) {
    $arguments = array();
    if (isset($values['arguments'])) {
      $arguments = $values['arguments'];
      unset($values['arguments']);
    }
    $language = $this->getFieldLanguage($entity, $field_info, $arguments);

    // Let the derived class skip empty values.
    if ($this->skipEmpty) {
      $values = array_filter($values, array($this, 'notNull'));
    }

    // Do not proceed if we got no values.
    if (empty($values)) {
      return NULL;
    }

    $revision_ids = $this->getRevisionIds($values, $arguments);

    // Setup the Field API array for saving.
    $delta = 0;
    foreach ($values as $value) {
      if (is_array($language)) {
        $current_language = $language[$delta];
      }
      else {
        $current_language = $language;
      }
      $return[$current_language][] = array(
        $this->fieldValueKey => $value,
        'revision_id' => $revision_ids[$delta],
      );
      $delta++;
    }
    return isset($return) ? $return : NULL;
  }

  /**
   * Helper to get set of revision ids for import.
   *
   * @param $values
   * @param $arguments
   */
  protected function getRevisionIds($values, $arguments) {
    $return = array();

    if (!isset($arguments['revision_id'])) {
      $arguments['revision_id'] = array();
    }
    elseif (!is_array($arguments['revision_id'])) {
      $arguments['revision_id'] = array($arguments['revision_id']);
    }

    $revision_ids = db_select('paragraphs_item', 'p')
      ->fields('p', array('item_id', 'revision_id'))
      ->condition('item_id', $values)
      ->execute()
      ->fetchAllKeyed();

    foreach ($values as $delta => $item_id) {
      // Get revision ID provided by the migration.
      if (!empty($arguments['revision_id'][$delta])) {
        $return[$delta] = $arguments['revision_id'][$delta];
      }
      // Provide latest revision id.
      else {
        $return[$delta] = $revision_ids[$item_id];
      }
    }

    return $return;
  }
}
