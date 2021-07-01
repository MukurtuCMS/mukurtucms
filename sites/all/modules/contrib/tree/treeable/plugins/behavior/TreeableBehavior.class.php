<?php

class TreeableBehavior extends EntityReference_BehaviorHandler_Abstract {
  public function schema_alter(&$schema, $field) {
    $schema['columns'] += _treeable_columns();
  }
}
