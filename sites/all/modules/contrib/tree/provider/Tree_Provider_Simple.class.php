<?php

/**
 * Base implementation for trees; it works regardless of the underlying storage
 * engine.
 */
class Tree_Provider_Simple extends Tree_Provider_Abstract implements Tree_Provider {

  /**
   * Overrides Tree_Provider_Abstract::preSave().
   */
  public function preSave(Tree_Storage_Item &$item) {
    // Calculate the 'depth' property if necessary.
    if ($item->depth === NULL) {
      if ($item->parent !== NULL) {
        // Get the parent of this item and use it to calculate its depth.
        $items = $this->parentOf($item)->execute();
        $parent = reset($items);
        $item->depth = $parent->depth + 1;
      }
      else {
        // Root items always have a depth of 0.
        $item->depth = 0;
      }
    }
  }

  /**
   * Implements Tree_Provider::parentOf().
   */
  public function parentOf(Tree_Storage_Item $item, Tree_Storage_Query $query = NULL) {
    if (!isset($query)) {
      $query = $this->storage->query();
    }

    if ($item->parent !== NULL) {
      $query->condition('id', $item->parent);
    }
    else {
      // We are a root node.
      $query->alwaysFalse();
    }
    return $query;
  }

  /**
   * Implements Tree_Provider::ancestorsOf().
   */
  public function ancestorsOf(Tree_Storage_Item $item, Tree_Storage_Query $query = NULL) {
    if (!isset($query)) {
      $query = $this->storage->query();
    }

    if ($item->parent === NULL) {
      // This is a root item, it does not have any parent.
      $query->alwaysFalse();
      return $query;
    }

    // Keep a list of seen IDs to avoid possible recursion.
    $parents = array($item->parent => $item);

    // In this simple implementation, we have to load all the ancestors
    // and manually add them to the query.
    $current = $item;
    do {
      $items = $this->parentOf($current)->execute();
      $current = reset($items);
      if ($current) {
        if (isset($current->parent) && !isset($parents[$current->parent])) {
          $parents[$current->parent] = $current;
          continue;
        }
      }
      break;
    }
    while (TRUE);

    if ($parents) {
      $query->condition('id', array_keys($parents));
    }
    else {
      $query->alwaysFalse();
    }

    return $query;
  }

  /**
   * Implements Tree_Provider::childrenOf().
   */
  public function childrenOf(Tree_Storage_Item $item, Tree_Storage_Query $query = NULL) {
    if (!isset($query)) {
      $query = $this->storage->query();
    }

    $query->condition('parent', $item->id);
    $query->orderBy('weight');
    return $query;
  }

  /**
   * Implements Tree_Provider::siblingsOf().
   */
  public function siblingsOf(Tree_Storage_Item $item, Tree_Storage_Query $query = NULL) {
    if (!isset($query)) {
      $query = $this->storage->query();
    }

    if ($item->parent !== NULL) {
      // Return the children of the parent of the current item.
      $items = $this->parentOf($item)->execute();
      $parent = reset($items);
      $this->childrenOf($parent, $query);
    }
    else {
      // The siblings of a root item are all the root items.
      $this->getRoots($query);
    }
    return $query;
  }

  /**
   * Implements Tree_Provider::descendantsOf().
   */
  public function descendantsOf(Tree_Storage_Item $item, Tree_Storage_Query $query = NULL) {
    if (!isset($query)) {
      $query = $this->storage->query();
    }

    if ($children_ids = $this->getChildrenIds($item)) {
      $query->condition('id', array_keys($children_ids));
    }
    else {
      $query->alwaysFalse();
    }

    return $query;
  }

  /**
   * Implements Tree_Provider::rootOf().
   */
  public function rootOf(Tree_Storage_Item $item, Tree_Storage_Query $query = NULL) {
    if (!isset($query)) {
      $query = $this->storage->query();
    }

    if ($item->parent !== NULL) {
      // The root item of a normal item is its last ancestor.
      $ancestors = $this->ancestorsOf($item)->execute();
      foreach ($ancestors as $ancestor) {
        if ($ancestor->parent === NULL) {
          $root = $ancestor;
          break;
        }
      }
      if (empty($root)) {
        $root = $item;
      }
      $query->condition('id', $root->id);
    }
    else {
      // The root of a root item is itself.
      $query->condition('id', $item->id);
    }
    return $query;
  }

  /**
   * Implements Tree_Provider::getRoots().
   */
  public function getRoots(Tree_Storage_Query $query = NULL) {
    if (!isset($query)) {
      $query = $this->storage->query();
    }

    $query->isNull('parent', NULL);
    return $query;
  }

  /**
   * Recursively retrieves children IDs for a tree item.
   *
   * @param Tree_Storage_Item $item
   *   A tree item.
   *
   * @return array
   *   An array of numeric IDs representing all the descendants of a tree item.
   */
  protected function getChildrenIds(Tree_Storage_Item $item) {
    $children_ids = array();
    if ($children = $this->childrenOf($item)->execute()) {
      foreach ($children as $child) {
        $children_ids[$child->id] = $child;
        $children_ids += $this->getChildrensIds($child);
      }
    }
    return $children_ids;
  }
}
