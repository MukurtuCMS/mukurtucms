<?php

/**
 * A SQL-specific implementation of trees based on nested sets.
 */
class Tree_Provider_NestedSet extends Tree_Provider_Simple implements Tree_Provider_SQL {

  /**
   * The storage object used by this provider.
   *
   * @var Tree_Storage_SQL
   */
  public $storage;

  /**
   * The database connection used by this provider's storage.
   *
   * @var DatabaseConnection
   */
  protected $database;

  /**
   * An array describing the column map.
   *
   * @var array
   */
  protected $columnMap;

  /**
   * The name of the base table.
   *
   * @var string
   */
  public $mainTable;

  /**
   * The name of the additional table needed by this provider.
   *
   * @var string
   */
  public $treeTable;

  /**
   * Constructs a Tree_Provider_NestedSet object.
   */
  public function __construct(Tree_Storage_SQL $storage) {
    parent::__construct($storage);

    $this->database = $this->storage->getDatabase();
    $this->columnMap = $this->storage->getColumnMap();

    $this->mainTable = $this->storage->getTableName();
    $this->treeTable = $this->mainTable . '_nested';
  }

  /**
   * Implements Tree_Provider_SQL::schema().
   */
  public function schema() {
    $schema[$this->treeTable] = array(
      'fields' => array(
        'id' => array(
          'description' => 'The ID of this item.',
          'type' => 'int',
          'not null' => TRUE,
        ),
        'nested_left' => array(
          'description' => 'The left count of this item.',
          'type' => 'int',
          'not null' => TRUE,
        ),
        'nested_right' => array(
          'description' => 'The right count of this item.',
          'type' => 'int',
          'not null' => TRUE,
        ),
      ),
      'indexes' => array(
        'left_right' => array('nested_left', 'nested_right'),
        'right' => array('nested_right'),
      ),
    );

    return $schema;
  }

  /**
   * Implements Tree_Provider_SQL::views_data_alter().
   */
  public function views_data_alter(&$data) {
    $data[$this->mainTable]['tree'] = array(
      'title' => t('Nested tree'),
      'help' => t('The tree table for the nested sets.'),
      'real field' => $this->columnMap['id'],
      'group' => t('Tree'),
      'relationship' => array(
        'title' => t('Nested tree'),
        'help' => t('Relate to the tree table for the nested sets.'),
        'handler' => 'views_handler_relationship',
        'base' => $this->treeTable,
        'base field' => 'id',
        'field' => $this->columnMap['id'],
        'label' => t('nested tree'),
      ),
    );

    $data[$this->treeTable]['table']['group']  = t('Tree');

    $data[$this->treeTable]['table']['join'] = array(
      $this->mainTable => array(
        'left_field' => $this->columnMap['id'],
        'field' => 'id',
      ),
    );

    // Expose the tree sort.
    $data[$this->treeTable]['tree_sort'] = array(
      'title' => t('Tree order sort'),
      'help' => t('Sort in tree order.'),
      'real field' => 'nested_left',
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
    );
  }

  /**
   * Returns a SQL query, specific to the nested set implementation.
   *
   * @return SelectQueryInterface
   *   A SelectQuery object.
   */
  protected function treeQuery() {
    $query = $this->database->select($this->mainTable, 'i');
    $query->innerJoin($this->treeTable, 't', 't.id = i.' . $this->columnMap['id']);

    foreach ($this->columnMap as $key => $field) {
      $query->addField('i', $field, $key);
    }
    $query->addField('t', 'nested_left', 'nested_left');
    $query->addField('t', 'nested_right', 'nested_right');

    return $query;
  }

  /**
   * Overrides Tree_Provider_Simple::descendantsOf().
   */
  public function descendantsOf(Tree_Storage_Item $item, Tree_Storage_Query $query = NULL) {
    $query = $this->treeQuery();

    $current_row = $this->treeQuery()->condition('t.id', $item->id)->execute()->fetchAssoc();
    $query->condition('t.nested_left', $current_row['nested_left'], '>=');
    $query->condition('t.nested_right', $current_row['nested_right'], '<=');
    $query->condition('t.id', $current_row['id'], '!=');
    $query->orderBy('t.nested_left');

    return $query;
  }

  /**
   * Overrides Tree_Provider_Simple::ancestorsOf().
   */
  public function ancestorsOf(Tree_Storage_Item $item, Tree_Storage_Query $query = NULL) {
    $query = $this->treeQuery();

    $current_row = $this->treeQuery()->condition('t.id', $item->id)->execute()->fetchAssoc();
    $query->condition('t.nested_left', $current_row['nested_left'], '<');
    $query->condition('t.nested_right', $current_row['nested_right'], '>');
    $query->orderBy('t.nested_left');

    return $query;
  }

  /**
   * Overrides Tree_Provider_Abstract::postInsert().
   */
  public function postInsert(Tree_Storage_Item $item) {
    $query = db_select($this->treeTable);
    $query->addExpression('MAX(nested_right)', 'nested_right');
    $left = $query->execute()->fetchField() + 1;
    $right = $left + 1;

    // Start by inserting the item at the end of the tree.
    $current_row = array(
      'id' => $item->id,
      'nested_left' => $left,
      'nested_right' => $right,
    );
    $this->database->insert($this->treeTable)->fields($current_row)->execute();

    // Then go through the insert process.
    $this->updateItem($item, $current_row);
  }

  /**
   * Overrides Tree_Provider_Abstract::postUpdate().
   */
  public function postUpdate(Tree_Storage_Item $item) {
    $current_row = $this->treeQuery()->condition('i.' . $this->columnMap['id'], $item->id)->execute()->fetchAssoc();

    // TODO: make it lazy.
    $this->updateItem($item, $current_row);
  }

  /**
   * Overrides Tree_Provider_Abstract::postDelete().
   */
  public function postDelete($item_id) {
    // Clean-up the row.
    // TODO: decide what to do with regard to cascading.
    $this->database->delete($this->treeTable)
      ->condition('id', $item_id)
      ->execute();
  }

  /**
   * Performs operations specific to the nested set implementation after an item
   * has been inserted or updated.
   *
   * @param Tree_Storage_SQL_Item $item
   *   A tree item.
   * @param array $current_row
   *   An array containing properties specific to the nested set implementation
   *   of a tree item.
   *
   * @throws Exception
   */
  public function updateItem(Tree_Storage_SQL_Item $item, array $current_row) {
    // Find the insertion point.
    list($target, $mode) = $this->findInsertionTarget($item);

    if ($mode == 'root') {
      // Nothing to do.
      return;
    }

    if (!$target) {
      // This means there is a bug in our code.
      throw new Exception(t('No target found for @id, strategy @mode', array('@id' => $item->id, '@mode' => $mode)));
    }

    if ($current_row['id'] == $target['id']) {
      throw new Exception(t('Invalid move: would move node @id as its own parent.', array('@id' => $current_row['id'])));
    }
    else if (($current_row['nested_left'] <= $target['nested_left'] && $target['nested_left'] <= $current_row['nested_right'])
      || ($current_row['nested_left'] <= $target['nested_right'] && $target['nested_right'] <= $current_row['nested_right'])) {
      throw new Exception(t('Invalid move: would move node @id as a child of @id2, which is already its child.', array('@id' => $current_row['id'], '@id2' => $target['id'])));
    }

    if ($mode == 'child') {
      $bound = $target['nested_right'];
    }
    elseif ($mode == 'before') {
      $bound = $target['nested_left'];
    }
    elseif ($mode == 'after') {
      $bound = $target['nested_right'] + 1;
    }

    if ($bound > $current_row['nested_right']) {
      $bound--;
      $other_bound = $current_row['nested_right'] + 1;
    }
    else {
      $other_bound = $current_row['nested_left'] - 1;
    }

    if ($bound == $current_row['nested_right'] || $bound == $current_row['nested_left']) {
      return;
    }

    // Build the bounds and the shifts.
    $bounds = array($current_row['nested_left'], $current_row['nested_right'], $bound, $other_bound);
    sort($bounds);
    list($a, $b, $c, $d) = $bounds;
    $shift_a_b = $d - $b;
    $shift_c_d = $a - $c;

    $this->database->update($this->treeTable)
      ->expression('nested_left', 'CASE WHEN nested_left BETWEEN :a1 AND :b1 THEN nested_left + :shift_a_b1 WHEN nested_left BETWEEN :c1 AND :d1 THEN nested_left + :shift_c_d1 ELSE nested_left END', array(':a1' => $a, ':b1' => $b, ':c1' => $c, ':d1' => $d, ':shift_a_b1' => $shift_a_b, ':shift_c_d1' => $shift_c_d))
      ->expression('nested_right', 'CASE WHEN nested_right BETWEEN :a2 AND :b2 THEN nested_right + :shift_a_b2 WHEN nested_right BETWEEN :c2 AND :d2 THEN nested_right + :shift_c_d2 ELSE nested_right END', array(':a2' => $a, ':b2' => $b, ':c2' => $c, ':d2' => $d, ':shift_a_b2' => $shift_a_b, ':shift_c_d2' => $shift_c_d))
      ->condition(db_or()
        ->condition('nested_left', array($a, $d), 'BETWEEN')
        ->condition('nested_right', array($a, $d), 'BETWEEN')
      )
      ->execute();
  }

  /**
   * Determines the insertion target and mode for an item that has been inserted
   * or updated.
   *
   * @param Tree_Storage_SQL_Item $item
   *   A tree item.
   *
   * @return array
   *   An associative array containing the following elements:
   *   - target: an array containing properties specific to a tree item.
   *   - mode: the insertion mode for this item ('root', 'child', 'before',
   *     'after').
   */
  protected function findInsertionTarget(Tree_Storage_SQL_Item $item) {
    // First, look if the parent element already has children and get the
    // min and max weight of those.
    $query = $this->database->select($this->mainTable, 'i');
    $query->addExpression('MIN(i.' . $this->columnMap['weight'] . ')', 'weight_min');
    $query->addExpression('MAX(i.' . $this->columnMap['weight'] . ')', 'weight_max');
    if ($item->parent !== NULL) {
      $query->condition('i.' . $this->columnMap['parent'], $item->parent);
    }
    else {
      $query->isNull('i.' . $this->columnMap['parent']);
    }
    $query->condition('i.' . $this->columnMap['id'], $item->id, '<>');
    $bounds = $query->execute()->fetchAssoc();

    // There are four possible cases:
    //   - 'root': the current item is the first item inserted in the tree;
    //   - 'child': the parent of the current item does not have children yet;
    //   - 'before': the parent of the current item has children, and we want it
    //     to be inserted before the first child;
    //   - 'after': the parent of the current item has children, and we want it
    //     to be inserted after one of the children.
    if ($item->parent === NULL && $bounds['weight_min'] === NULL) {
      $target = NULL;
      $mode = 'root';
    }
    elseif ($item->parent !== NULL && $bounds['weight_min'] === NULL) {
      // Insert directly as a child.
      $target = $this->treeQuery()->condition('i.' . $this->columnMap['id'], $item->parent)->execute()->fetchAssoc();
      $mode = 'child';
    }
    elseif ($bounds['weight_min'] >= $item->weight) {
      // Insert before the lightest child of the parent.
      $query = $this->treeQuery();
      if ($item->parent !== NULL) {
        $query->condition('i.' . $this->columnMap['parent'], $item->parent);
      }
      else {
        $query->isNull('i.' . $this->columnMap['parent']);
      }
      $query->condition('i.' . $this->columnMap['id'], $item->id, '<>');
      $target = $query->orderBy('t.nested_left', 'ASC')->range(0, 1)->execute()->fetchAssoc();
      $mode = 'before';
    }
    else {
      // Insert after an existing child of the parent.
      $query = $this->treeQuery();
      if ($item->parent !== NULL) {
        $query->condition('i.' . $this->columnMap['parent'], $item->parent);
      }
      else {
        $query->isNull('i.' . $this->columnMap['parent']);
      }
      $query->condition('i.' . $this->columnMap['id'], $item->id, '<>');
      $target = $query
        ->condition('i.' . $this->columnMap['weight'], $item->weight, '<')
        ->orderBy('t.nested_left', 'DESC')->range(0, 1)->execute()->fetchAssoc();
      $mode = 'after';
    }

    return array($target, $mode);
  }
}
