<?php

/**
 * @file
 * Contains the SearchApiAlterNodeStatus class.
 */

/**
 * Exclude unpublished nodes from node indexes.
 */
class SearchApiAlterNodeStatus extends SearchApiAbstractAlterCallback {

  /**
   * Check whether this data-alter callback is applicable for a certain index.
   *
   * Returns TRUE only for indexes on nodes.
   *
   * @param SearchApiIndex $index
   *   The index to check for.
   *
   * @return boolean
   *   TRUE if the callback can run on the given index; FALSE otherwise.
   */
  public function supportsIndex(SearchApiIndex $index) {
    if ($this->isMultiEntityIndex($index)) {
      return in_array('node', $index->options['datasource']['types']);
    }
    return $index->getEntityType() === 'node';
  }

  /**
   * Alter items before indexing.
   *
   * Items which are removed from the array won't be indexed, but will be marked
   * as clean for future indexing.
   *
   * @param array $items
   *   An array of items to be altered, keyed by item IDs.
   */
  public function alterItems(array &$items) {
    $multi_types = $this->isMultiEntityIndex($this->index);
    foreach ($items as $id => $item) {
      $node = $item;
      if ($multi_types) {
        if ($item->item_type !== 'node') {
          continue;
        }
        $node = $item->node;
      }
      if (empty($node->status)) {
        unset($items[$id]);
      }
    }
  }

}
