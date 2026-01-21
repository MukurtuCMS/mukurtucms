<?php

/**
 * The interface defining a provider for a tree.
 */
interface Tree_Provider {

  /**
   * Gets the parent of an item.
   *
   * @return Tree_Storage_Query
   */
  public function parentOf(Tree_Storage_Item $item, Tree_Storage_Query $query = NULL);

  /**
   * Gets the whole ancestry of an item.
   *
   * @return Tree_Storage_Query
   */
  public function ancestorsOf(Tree_Storage_Item $item, Tree_Storage_Query $query = NULL);

  /**
   * Gets the children of an item.
   *
   * @return Tree_Storage_Query
   */
  public function childrenOf(Tree_Storage_Item $item, Tree_Storage_Query $query = NULL);

  /**
   * Gets the siblings of an item.
   *
   * @return Tree_Storage_Query
   */
  public function siblingsOf(Tree_Storage_Item $item, Tree_Storage_Query $query = NULL);

  /**
   * Gets the descendants of an item.
   *
   * @return Tree_Storage_Query
   */
  public function descendantsOf(Tree_Storage_Item $item, Tree_Storage_Query $query = NULL);

  /**
   * Gets the root item of an item.
   *
   * @return Tree_Storage_Query
   */
  public function rootOf(Tree_Storage_Item $item, Tree_Storage_Query $query = NULL);

  /**
   * Gets all the root items of the tree.
   *
   * @return Tree_Storage_Query
   */
  public function getRoots(Tree_Storage_Query $query = NULL);

  /**
   * Act after deletion has happend.
   *
   * @param int $item_id
   */
  public function postDelete($item_id);

  /**
   * Act after insertion has happened.
   *
   * @param Tree_Storage_Item $item
   */
  public function postInsert(Tree_Storage_Item $item);

  /**
   * Act after load has happened.
   */
  public function postLoad(Tree_Storage_Item $item);

  /**
   * Act after update has happened.
   *
   * @param Tree_Storage_Item $item
   */
  public function postUpdate(Tree_Storage_Item $item);

  /**
   * Act on pre-save.
   */
  public function preSave(Tree_Storage_Item &$item);
}

/**
 * A tree provider that supports querying in tree order.
 */
interface Tree_Provider_Orderable extends Tree_Provider {

  public function orderByTree(Tree_Storage_Query $query);
}

/**
 * A tree provider that requires a SQL-joinable storage.
 */
interface Tree_Provider_SQL extends Tree_Provider {

  /**
   * Returns the database schema used by this tree provider.
   *
   * @return array
   *   An array as needed by hook_schema().
   */
  public function schema();

  /**
   * Alters views data definition.
   *
   * @return array
   *   An array as needed by hook_views_data_alter().
   */
  public function views_data_alter(&$data);
}
