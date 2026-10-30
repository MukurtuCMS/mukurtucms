<?php

/**
 * @file
 * Documentation for Term Merge module.
 */

/**
 * Notify other modules when merging of 2 taxonomy terms occurs.
 *
 * @param object $term_trunk
 *   Fully loaded taxonomy term object of the term trunk, term into which
 *   merging occurs, aka 'destination'
 * @param object $term_branch
 *   Fully loaded taxonomy term object of the term branch, term that is being
 *   merged, aka 'source'
 * @param array $context
 *   Array $context as it is passed to term_merge_action() - you can get a
 *   little more info about context about merging from this array
 */
function hook_term_merge($term_trunk, $term_branch, $context) {
  // Here we might want to run a query like:
  // UPDATE {my_table}
  //   SET term_tid = $term_trunk->tid
  //   WHERE term_tid = $term_branch->tid
  // Or do anything else that your own logic requires when merging of 2 terms
  // happens.
}
