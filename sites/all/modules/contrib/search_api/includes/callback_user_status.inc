<?php

/**
 * @file
 * Contains the SearchApiAlterUserStatus class.
 */

/**
 * Filters out blocked user accounts.
 */
class SearchApiAlterUserStatus extends SearchApiAbstractAlterCallback {

  /**
   * {@inheritdoc}
   */
  public function supportsIndex(SearchApiIndex $index) {
    if ($this->isMultiEntityIndex($index)) {
      return in_array('user', $index->options['datasource']['types']);
    }
    return $index->getEntityType() == 'user';
  }

  /**
   * {@inheritdoc}
   */
  public function alterItems(array &$items) {
    $multi_types = $this->isMultiEntityIndex($this->index);
    foreach ($items as $id => $item) {
      $account = $item;
      if ($multi_types) {
        if ($item->item_type !== 'user') {
          continue;
        }
        $account = $item->user;
      }
      if (empty($account->status)) {
        unset($items[$id]);
      }
    }
  }

}
