<?php

/**
 * @file
 * Contains SearchApiAlterFileEntityPublic.
 */

/**
 * Excludes file entities in the private folder from being indexed.
 */
class SearchApiAlterFileEntityPublic extends SearchApiAbstractAlterCallback {

  /**
   * {@inheritdoc}
   */
  public function supportsIndex(SearchApiIndex $index) {
    if ($this->isMultiEntityIndex($index)) {
      return in_array('file', $index->options['datasource']['types']);
    }
    return $index->getEntityType() === 'file';
  }

  /**
   * {@inheritdoc}
   */
  public function alterItems(array &$items) {
    $multi_types = $this->isMultiEntityIndex($this->index);
    foreach ($items as $id => $item) {
      $file = $item;
      if ($multi_types) {
        if ($item->item_type !== 'file') {
          continue;
        }
        $file = $item->file;
      }
      if (empty($file->uri) || substr($file->uri, 0, 10) === 'private://') {
        unset($items[$id]);
      }
    }
  }

}
