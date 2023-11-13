<?php

function _services_fc_retrieve($fcid) {
  $collections=entity_load('field_collection_item', array($fcid));
  if (!empty($collections)) {
    $collection = array_pop($collections);
    $uri = entity_uri('field_collection_item', $collection);
    $collection->path = url($uri['path'], array('absolute' => TRUE));
  }
  else {
    $collection = FALSE;
  }

  return $collection;
}

// Adds backwards compatibility with regression fixed in #1083242
function _services_fc_create($field_collection) {
  // Mukurtu patch.
  if ($node = node_load ($field_collection['host_nid'])) {
    $entity = entity_create('field_collection_item', $field_collection['field_collection']);
    $entity->setHostEntity('node', $node);
    $entity->save();
    node_save($node);
    return $entity;
  }
}

// Adds backwards compatibility with regression fixed in #1083242
function _services_fc_update($fcid, $field_collection) {
  $collections=entity_load('field_collection_item', array($fcid));
  if (empty($collections[$fcid])) {

    return services_error(t('Collection @fcid not found', array('@fcid' => $fcid)), 404);
  }
  $old_collection = (array)$collections[$fcid];
  $collection = array_merge($old_collection, $field_collection);
  entity_save('field_collection_item', (object)$collection);

  return $collection;
}

function _services_fc_delete($fcid) {
  entity_delete('field_collection_item', $fcid);

  return TRUE;
}

function _services_fc_index($page, $fields, $parameters, $page_size) {
  module_load_include('inc', 'services', 'services.module');
  $fc_select = db_select('field_collection_item', 't');
  services_resource_build_index_query($fc_select, $page, $fields, $parameters, $page_size, 'field_collection_item');
  $results = services_resource_execute_index_query($fc_select);

  return services_resource_build_index_list($results, 'field_collection_item', 'item_id');
}
