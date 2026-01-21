<?php
/**
 * For DH items, populate new Original Date field from old Date (now Date Description) field where possible.
 *
 * Using a separate script for this in case the update hook fails, in which case this can be run
 * with 'drush scr populate_original_date.php'.
 **/

$query = new EntityFieldQuery();

$query->entityCondition('entity_type', 'node')
  ->entityCondition('bundle', 'digital_heritage')
  ->propertyCondition('status', 1);
$result = $query->execute();

if (!empty($result['node'])) {
  $nids = array_keys($result['node']);

  foreach ($nids as $nid) {
    $dhw = entity_metadata_wrapper('node', $nid);
    $date_desc =  $dhw->field_date->value();
    if (isset($date_desc)) {
      print "NID " . $nid . " | date desc: $date_desc | ";
      $orig_date = $dhw->field_original_date->value();
      if (empty($orig_date)) {
        $orig_date_ts = strtotime($date_desc);
        if ($orig_date_ts) {
          $year = date('Y', $orig_date_ts);
          $month = date('n', $orig_date_ts);
          $day = date('j', $orig_date_ts);
          print "Populating Original Date with: y $year m $month d $day";
          $node = node_load($nid);
          $node->field_original_date[LANGUAGE_NONE][0]['from']['year'] = $year;
          $node->field_original_date[LANGUAGE_NONE][0]['from']['month'] = $month;
          $node->field_original_date[LANGUAGE_NONE][0]['from']['day'] = $day;
          node_save($node);
        }
        else {
          print "Cannot get timestamp out Date Description. Not populating Original Date.";
        }
      }
      else {
        print "Original date field already set.";
      }
    }
    print "\n";
  }
}



