<?php

/**
 * Provides fallback implementations for all Tree_Provider methods.
 */
abstract class Tree_Provider_Abstract implements Tree_Provider {

  /**
   * The storage object used by this provider.
   *
   * @var Tree_Storage
   */
  public $storage;

  /**
   * Constructs a Tree_Provider_Abstract object.
   */
  public function __construct(Tree_Storage $storage) {
    $this->storage = $storage;
  }

  /**
   * Implements Tree_Provider::postDelete().
   */
  public function postDelete($item_id) {
    // Nothing to do here.
  }

  /**
   * Implements Tree_Provider::postLoad().
   */
  public function postLoad(Tree_Storage_Item $item) {
    // Nothing to do here.
  }

  /**
   * Implements Tree_Provider::postInsert().
   */
  public function postInsert(Tree_Storage_Item $item) {
    // Nothing to do here.
  }

  /**
   * Implements Tree_Provider::postUpdate().
   */
  public function postUpdate(Tree_Storage_Item $item) {
    // Nothing to do here.
  }

  /**
   * Implements Tree_Provider::preSave().
   */
  public function preSave(Tree_Storage_Item &$item) {
    // Nothing to do here.
  }
}
