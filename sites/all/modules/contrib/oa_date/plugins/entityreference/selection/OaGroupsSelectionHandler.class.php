<?php
/**
 * @file
 * Contains the OaGroupsSelectionHandler class.
 */

/**
 * An EntityReference selection plugin for Open Atrium Groups.
 *
 * It show the appropriate list of groups including the current space.
 */
class OaGroupsSelectionHandler implements EntityReference_SelectionHandler {
  /**
   * Implements EntityReferenceHandler::getInstance().
   */
  public static function getInstance($field, $instance = NULL, $entity_type = NULL, $entity = NULL) {
    if ($field['settings']['target_type'] !== 'node') {
      return EntityReference_SelectionHandler_Broken::getInstance($field, $instance);
    }

    return new OaGroupsSelectionHandler($field, $instance);
  }

  protected function __construct($field, $instance) {
    $this->field = $field;
    $this->instance = $instance;
  }

  /**
   * Implements EntityReferenceHandler::settingsForm().
   */
  public static function settingsForm($field, $instance) {
    $field['settings']['handler_settings'] += array(
      'target_bundles' => array(),
      'include_space' => FALSE,
    );
    $settings = $field['settings']['handler_settings'];

    $form['target_bundles'] = array(
      '#type' => 'value',
      '#value' => array(),
    );

    $form['include_space'] = array(
      '#title' => t('Include current space'),
      '#type' => 'checkbox',
      '#default_value' => $settings['include_space'],
    );

    return $form;
  }

  /**
   * Implements EntityReferenceHandler::getReferencableEntities().
   */
  public function getReferencableEntities($match = NULL, $match_operator = 'CONTAINS', $limit = 0) {
    $settings = $this->field['settings']['handler_settings'];

    $include_space = $settings['include_space'];
    $all_groups = oa_core_get_all_groups($match, $match_operator, $limit);
    $groups = array_map(create_function('$group', 'return $group->title;'), $all_groups);

    $group_options = array();
    foreach ($groups as $nid => $group_name) {
      $group_options[$nid] = $group_name;
    }

    if ($space_id = oa_core_get_space_context()) {
      // Bring current group to front.
      if (!empty($group_options[$space_id])) {
        $group_options = array($space_id => t('!name (current)', array('!name' => $group_options[$space_id]))) + $group_options;
      }
      // Include current space if configured.
      elseif ($include_space) {
        // NOTE: This title text is ignored and overwritten by select2widget
        // in select2widget_render_modes().  All that matters is the $space_id.
        // Current space should be cached.
        $space = node_load($space_id);
        if (empty($match) || (stripos($space->title, $match) !== FALSE)) {
          $group_options = array($space_id => t('- All space members -')) + $group_options;
        }
      }
    }

    return array(OA_GROUP_TYPE => $group_options);
  }

  /**
   * Implements EntityReferenceHandler::countReferencableEntities().
   */
  public function countReferencableEntities($match = NULL, $match_operator = 'CONTAINS') {
    $options = $this->getReferencableEntities();
    return count($options['node']);
  }

  /**
   * Implements EntityReferenceHandler::validateReferencableEntities().
   */
  public function validateReferencableEntities(array $ids) {
    // Assume any are valid.
    $validated = $ids;
    return $validated;
  }

  /**
   * Implements EntityReferenceHandler::validateAutocompleteInput().
   *
   * Copied from EntityReference_SelectionHandler_Generic::validateAutocompleteInput().
   */
  public function validateAutocompleteInput($input, &$element, &$form_state, $form) {
    $entities = $this->getReferencableEntities($input, '=', 6);
    if (empty($entities)) {
      // Error if there are no entities available for a required field.
      form_error($element, t('There are no entities matching "%value"', array('%value' => $input)));
    }
    elseif (count($entities) > 5) {
      // Error if there are more than 5 matching entities.
      form_error($element, t('Many entities are called %value. Specify the one you want by appending the id in parentheses, like "@value (@id)"', array(
        '%value' => $input,
        '@value' => $input,
        '@id' => key($entities),
      )));
    }
    elseif (count($entities) > 1) {
      // More helpful error if there are only a few matching entities.
      $multiples = array();
      foreach ($entities as $id => $name) {
        $multiples[] = $name . ' (' . $id . ')';
      }
      form_error($element, t('Multiple entities match this reference; "%multiple"', array('%multiple' => implode('", "', $multiples))));
    }
    else {
      // Take the one and only matching entity.
      return key($entities);
    }
  }

  /**
   * Implements EntityReferenceHandler::entityFieldQueryAlter().
   */
  public function entityFieldQueryAlter(SelectQueryInterface $query) {
  }

  /**
   * Implements EntityReferenceHandler::getLabel().
   */
  public function getLabel($entity) {
    return entity_access('view', 'node', $entity) ? entity_label('node', $entity) : t('- Restricted access -');
  }

}
