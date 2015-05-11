<?php

$query = new EntityFieldQuery();
$query->entityCondition('entity_type', 'scald_atom')
  #->fieldCondition('field_scald_protocol', 'target_id', 'NULL')
  #->fieldCondition('og_group_ref', 'target_id', NULL, '!=');
  ;
$results = $query->execute();
$scald_atoms = array_keys ($results['scald_atom']);

foreach ($scald_atoms as $scald_atom) {
   $atom_wrapper = entity_metadata_wrapper('scald_atom', $scald_atom);
  if ($old_prots = $atom_wrapper->og_group_ref->value()) {
    print "\n" . $atom_wrapper->getIdentifier() . ":" .$atom_wrapper->title->value();
    $new_prots = array();
    foreach ($old_prots as $old_prot) {
      if ($old_prot->nid) {
        $new_prots[] = $old_prot->nid;
      }
    }
    $new_prots = array_unique ($new_prots);
    print " => " . implode (', ', $new_prots);
    $atom_wrapper->field_scald_protocol = $new_prots;
    $atom_wrapper->save();
  }
}
