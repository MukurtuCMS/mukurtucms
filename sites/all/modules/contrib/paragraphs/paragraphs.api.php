<?php

/**
 * @file
 * Hooks provided by the Paragraphs module.
 */

/**
 * Check whether a user may perform the operation on the paragraphs item.
 *
 * @param ParagraphsItemEntity $entity
 *   Entity to check the access against.
 * @param string $op
 *   The operation to be performed on the paragraphs item. Possible values are:
 *   - "view"
 *   - "update"
 *   - "delete"
 *   - "create".
 * @param object $account
 *   Optional, a user object representing the user for whom the operation is to
 *   be performed. Determines access for a user other than the current user.
 *
 * @return bool
 *   TRUE if the operation may be performed, FALSE otherwise.
 */
function hook_paragraphs_item_access(ParagraphsItemEntity $entity, $op, $account) {
  $permissions = &drupal_static(__FUNCTION__, array());

  if (!in_array($op, array('view', 'update', 'delete', 'create'), TRUE) || $entity === NULL) {
    // If there is no bundle to check against, or the $op is not one of the
    // supported ones, we return access ignore.
    return PARAGRAPHS_ITEM_ACCESS_IGNORE;
  }

  $bundle = $entity->bundle;

  // Set static cache id to use the bundle machine name.
  $cid = $bundle;

  // If we've already checked access for this bundle, user and op, return from
  // cache.
  if (isset($permissions[$account->uid][$cid][$op])) {
    return $permissions[$account->uid][$cid][$op];
  }

  if (user_access($op . ' paragraph content ' . $bundle, $account)) {
    $permissions[$account->uid][$cid][$op] = PARAGRAPHS_ITEM_ACCESS_ALLOW;
  }
  else {
    $permissions[$account->uid][$cid][$op] = PARAGRAPHS_ITEM_ACCESS_DENY;
  }

  return $permissions[$account->uid][$cid][$op];
}
