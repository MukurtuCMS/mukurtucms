<?php

/**
 * @file
 * Hooks for scald_index module.
 */

/**
 * This hook is invoked after gathering all atoms for a given node.
 *
 * With this hook, other modules can add unfound atoms to the list before processing.
 *
 * @param object $node
 *   The node for which atoms are gathered.
 * @param array $sids
 *   The array of atoms SID.
 */
function hook_scald_index_node_atoms_alter($node, &$sids) {
  // Add some atoms.
}

/**
 * This hook is invoked after building the index for a given node.
 *
 * @param object $node
 *   The given node.
 * @param array $sid_all
 *   The array of atom SID.
 */
function hook_scald_index_after_build_node_index($node, $sid_all) {
  // Do things.
}
