<?php
/**
 * @file
 * Code for OG Subspaces selection handler
 */

/**
 * OG Subspaces selection handler for OA.
 */
class OgSubspacesSelectionHandler extends EntityReference_SelectionHandler_Generic {

  /**
   * Implements EntityReferenceHandler::getInstance().
   */
  public static function getInstance($field, $instance = NULL, $entity_type = NULL, $entity = NULL) {
    return new OgSubspacesSelectionHandler($field, $instance, $entity_type, $entity);
  }

  /**
   * Override EntityReferenceHandler::settingsForm().
   */
  public static function settingsForm($field, $instance) {
    $form = parent::settingsForm($field, $instance);
    $entity_type = $field['settings']['target_type'];
    $entity_info = entity_get_info($entity_type);

    $bundles = array();
    foreach ($entity_info['bundles'] as $bundle_name => $bundle_info) {
      if (og_is_group_type($entity_type, $bundle_name)) {
        $bundles[$bundle_name] = $bundle_info['label'];
      }
    }

    if (!$bundles) {
      $form['target_bundles'] = array(
        '#type' => 'item',
        '#title' => t('Target bundles'),
        '#markup' => t('Error: The selected "Target type" %entity does not have bundles that are a group type', array('%entity' => $entity_info['label'])),
      );
    }
    else {
      $settings = $field['settings']['handler_settings'];
      $settings += array(
        'target_bundles' => array(),
        'membership_type' => OG_MEMBERSHIP_TYPE_DEFAULT,
      );

      $form['target_bundles'] = array(
        '#type' => 'select',
        '#title' => t('Target bundles'),
        '#options' => $bundles,
        '#default_value' => $settings['target_bundles'],
        '#size' => 6,
        '#multiple' => TRUE,
        '#description' => t('The bundles of the entity type acting as group, that can be referenced. Optional, leave empty for all bundles.')
      );

      $options = array();
      foreach (og_membership_type_load() as $og_membership) {
        $options[$og_membership->name] = $og_membership->description;
      }
      $form['membership_type'] = array(
        '#type' => 'select',
        '#title' => t('OG membership type'),
        '#description' => t('Select the membership type that will be used for a subscribing user.'),
        '#options' => $options,
        '#default_value' => $settings['membership_type'],
        '#required' => TRUE,
      );
    }

    return $form;
  }

  /**
   * Implements EntityReferenceHandler::getReferencableEntities().
   */
  public function getReferencableEntities($match = NULL, $match_operator = 'CONTAINS', $limit = 0) {
    $options = array();
    $entity_type = $this->field['settings']['target_type'];

    $query = $this->buildEntityFieldQuery($match, $match_operator);
    if ($limit > 0) {
      $query->range(0, $limit);
    }
    $results = $query->execute();

    if (!empty($results[$entity_type])) {
      // call the OA helper function to get the title of nodes quickly
      $titles = oa_core_get_titles(array_keys($results[$entity_type]), '', '', array('id', 'title', 'type'), TRUE, $limit);
      if (!empty($titles['titles'])) {
        foreach ($titles['titles'] as $key => $title) {
          $options[$titles['types'][$key]][$titles['ids'][$key]] = $title;
        }
      }
    }
    return $options;
  }

  /**
   * Implements EntityReferenceHandler::countReferencableEntities().
   */
  public function countReferencableEntities($match = NULL, $match_operator = 'CONTAINS') {
    if (!empty($this->instance) && ($this->instance['entity_type'] == 'node')) {
      // Organic Groups calls this method in og_node_access to determine "create X content" permission.
      // There comment is this:
      // -----
      // We can't check if user has create permissions using og_user_access(), as
      // there is no group context. However, we can check if there are any groups
      // the user will be able to select, and if not, we don't allow access.
      // @see OgSelectionHandler::getReferencableEntities()
      // -----
      // Well, in Open Atrium, we DO know the group context because it's stored in the session
      // So we can just use og_user_access('create X content', $space_id) to determine access
      // Since this method isn't used anywhere else, we'll return a zero or one to determine
      // create X access.
      // ------
      // We directly check session as oa_core_get_space_context checks menu_get_item
      // which checks node_access.
      // ------
      // BEWARE: If you use some other module that relies on the TRUE count, it won't work
      $space_id = &drupal_static('oa_core_count_ref_space_id', NULL);
      if (!isset($space_id)) {
        if (!empty($_SESSION['og_context']['group_type']) && $_SESSION['og_context']['group_type'] == 'node'
          && ($node = node_load($_SESSION['og_context']['gid'])) && node_access('view', $node)) {
          $space_id = $_SESSION['og_context']['gid'];
        }
        else {
          $space_id = FALSE;
        }
      }
      if ($space_id) {
        $node_type = $this->instance['bundle'];
        return og_user_access('node', $space_id, 'create ' . $node_type . ' content') ? 1 : 0;
      }
    }
    return 0;
  }

  /**
   * Implements EntityReferenceHandler::validateReferencableEntities().
   */
  public function validateReferencableEntities(array $ids) {
    if (!$ids) {
      return $ids;
    }
    $field_mode = isset($this->instance['field_mode']) ? $this->instance['field_mode'] : 'all';
    if ($field_mode == 'default') {
      $group_type = $this->field['settings']['target_type'];
      $user_groups = oa_core_get_groups_by_user(NULL, $group_type);

      if ($this->field['field_name'] == 'oa_parent_space') {
        // Let existing parent field be valid.
        $parents = oa_core_get_parents($this->entity->nid);
        foreach ($parents as $parent) {
          $user_groups[$parent] = $parent;
        }
      }

      $result = array_intersect($ids, $user_groups);
      return $result;
    }
    else {
      $entity_type = $this->field['settings']['target_type'];
      $query = $this->buildEntityFieldQuery();
      $query->entityCondition('entity_id', $ids, 'IN');
      $result = $query->execute();
      if (!empty($result[$entity_type])) {
        return array_keys($result[$entity_type]);
      }
    }
    return array();
  }

  /**
   * Build an EntityFieldQuery to get referencable entities.
   */
  public function buildEntityFieldQuery($match = NULL, $match_operator = 'CONTAINS') {
    global $user;

    $handler = EntityReference_SelectionHandler_Generic::getInstance($this->field, $this->instance, $this->entity_type, $this->entity);
    $query = $handler->buildEntityFieldQuery($match, $match_operator);

    // FIXME: http://drupal.org/node/1325628
    unset($query->tags['node_access']);

    // FIXME: drupal.org/node/1413108
    unset($query->tags['entityreference']);

    $query->addTag('entity_field_access');
    $query->addTag('og');

    $group_type = $this->field['settings']['target_type'];
    $entity_info = entity_get_info($group_type);

    if (!field_info_field(OG_GROUP_FIELD)) {
      // There are no groups, so falsify query.
      $query->propertyCondition($entity_info['entity keys']['id'], -1, '=');
      return $query;
    }

    // Show only the entities that are active groups.
    $query->fieldCondition(OG_GROUP_FIELD, 'value', 1, '=');

    if (empty($this->instance['field_mode'])) {
      return $query;
    }

    $field_mode = $this->instance['field_mode'];
    if ($field_mode == 'default' || $field_mode == 'admin') {
      $user_groups = oa_core_get_groups_by_user(NULL, $group_type);
      $user_groups = array_merge($user_groups, $this->getGidsForCreate());
      // This is a workaround for not being able to choice which default value for
      // 'my groups', which causes my groups to be lost.
      // @todo find a way to default my groups based on selection handler.
      $user_groups_only = og_get_entity_groups();
      $user_groups_only = !empty($user_groups_only['node']) ? $user_groups_only['node'] : array();
  
      // Show the user only the groups they belong to.
      if ($field_mode == 'default') {
        if ($user_groups && !empty($this->instance) && $this->instance['entity_type'] == 'node') {
          // Determine which groups should be selectable.
          $node = $this->entity;
          $node_type = $this->instance['bundle'];
          $has_create_access = array_keys(array_filter(oa_user_access_nids('node', $user_groups, "create $node_type content")));
          $has_update_access = array();
          $remaining = array_diff($user_groups, $has_create_access);
          if (!empty($node->nid) && $remaining) {
            $groups = og_get_entity_groups('node', $node->nid);
            $node_groups = !empty($groups['node']) ? $groups['node'] : array();
            if ($node_groups = array_diff($node_groups, $remaining)) {
              $check_perms = array("update any $node_type content");
              if ($user->uid == $node->uid) {
                $check_perms = "update own $node_type content";
              }
              $has_update_access = array_keys(array_filter(oa_user_access_nids('node', $node_groups, $check_perms)));
            }
          }
          $ids = array_merge($has_update_access, $has_create_access);
        }
        else {
          $ids = $user_groups;
        }
  
        if ($ids) {
          $query->propertyCondition($entity_info['entity keys']['id'], $ids, 'IN');
        }
        else {
          // User doesn't have permission to select any group so falsify this
          // query.
          $query->propertyCondition($entity_info['entity keys']['id'], -1, '=');
        }
      }
      elseif ($field_mode == 'admin' && $user_groups_only) {
        // Show only groups the user doesn't belong to.
        if (!empty($this->instance) && $this->instance['entity_type'] == 'node') {
          // Don't include the groups, the user doesn't have create
          // permission.
          $node_type = $this->instance['bundle'];
          foreach ($user_groups_only as $delta => $gid) {
            if (!og_user_access($group_type, $gid, "create $node_type content")) {
              unset($user_groups_only[$delta]);
            }
          }
        }
        if ($user_groups) {
          $query->propertyCondition($entity_info['entity keys']['id'], $user_groups_only, 'NOT IN');
        }
      }
    }

    return $query;
  }

  public function entityFieldQueryAlter(SelectQueryInterface $query) {
    $handler = EntityReference_SelectionHandler_Generic::getInstance($this->field, $this->instance);
    // FIXME: Allow altering, after fixing http://drupal.org/node/1413108
    // $handler->entityFieldQueryAlter($query);
  }

  /**
   * Get group IDs from URL or OG-context, with access to create group-content.
   *
   * @return
   *   Array with group IDs a user (member or non-member) is allowed to
   * create, or empty array.
   */
  private function getGidsForCreate() {
    if ($this->instance['entity_type'] != 'node') {
      return array();
    }

    if (!empty($this->entity->nid)) {
      // Existing node.
      return array();
    }
    $node_type = $this->instance['bundle'];

    // want to check for create access to public spaces
    $ids = oa_core_get_public_spaces();

    // add support for entityreference_prepopulate
    if (module_exists('entityreference_prepopulate') && !empty($this->instance['settings']['behaviors']['prepopulate'])) {
      $pre_ids = entityreference_prepopulate_get_values($this->field, $this->instance, FALSE);
      if (is_array($pre_ids)) {
        $ids = array_merge($ids, $pre_ids);
      }
    }
    // Allow bypassing this logic if user can create content globally.
    if (user_access('administer group') || (!variable_get('og_node_access_strict', TRUE) || user_access("create $node_type content"))) {
      return $ids;
    }

    $access = oa_user_access_nids($this->field['settings']['target_type'], $ids, "create $node_type content");
    return array_intersect($ids, array_keys(array_filter($access)));
  }
}
