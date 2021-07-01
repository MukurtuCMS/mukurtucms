<?php
/**
 * @file
 * Contains the OaTeams_SelectionHandler class.
 */

/**
 * An EntityReference selection plugin for Open Atrium Teams.
 *
 * It show the appropriate list of teams for the current Space, including
 * inherited Teams.
 */
class OaTeams_SelectionHandler implements EntityReference_SelectionHandler {
  /**
   * Implements EntityReferenceHandler::getInstance().
   */
  public static function getInstance($field, $instance = NULL, $entity_type = NULL, $entity = NULL) {
    if ($field['settings']['target_type'] !== 'node') {
      return EntityReference_SelectionHandler_Broken::getInstance($field, $instance);
    }

    return new OaTeams_SelectionHandler();
  }

  protected function __construct() {
    // We don't need to construct anything!
  }

  /**
   * Implements EntityReferenceHandler::settingsForm().
   */
  public static function settingsForm($field, $instance) {
    return array();
  }

  /**
   * Implements EntityReferenceHandler::getReferencableEntities().
   */
  public function getReferencableEntities($match = NULL, $match_operator = 'CONTAINS', $limit = 0) {
    $nids = array_keys(oa_teams_get_teams_for_space());
    $teams = node_load_multiple($nids);

    $options = array(OA_TEAM_TYPE => array());
    $count = 0;
    foreach ($teams as $nid => $team) {
      $count++;
      $label = $this->getLabel($team);
      if (!$match || stripos($label, $match) !== FALSE) {
        $options[OA_TEAM_TYPE][$nid] = check_plain($this->getLabel($team));
      }
      if ($limit && $count == $limit) {
        break;
      }
    }

    return $options;
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
