<?php
/**
 * For DH items, populate the Muurtu Mobile Community Records text field.
 **/

$query = new EntityFieldQuery();

$query->entityCondition('entity_type', 'node')
  ->entityCondition('bundle', 'digital_heritage')
  ->propertyCondition('status', 1);
$result = $query->execute();

if (!empty($result['node'])) {
  $nids = array_keys($result['node']);

  foreach ($nids as $nid) {
    $dh_node = node_load($nid);
    $dhw = entity_metadata_wrapper('node', $nid);
    $cr_children =  $dhw->field_community_record_children->value();
    if (count($cr_children)) {
      print $nid . " ";
      $_SESSION['force_update_mm_cr_field'] = TRUE;
      node_save($dh_node);
      $_SESSION['force_update_mm_cr_field'] = FALSE;
    }
  }
}



