<?php

/**
 * @file
 * Describe hooks provided by Scald Dailymotion.
 */

/**
 * @addtogroup hooks
 * @{
 */

/**
 * Allow modules to add DailyMotion fields to the retrieved data.
 */
function hook_scald_dailymotion_api_fields_alter(&$fields) {
  // Also retrieve the video duration from DailyMotion.
  $fields[] = 'duration';
}

/**
 * Allow modules to modify the atom generated from the retrieved data.
 *
 * @param object $atom
 *   The atom currently built.
 * @param object $video
 *   The raw atom data retrieved from DailyMotion.
 */
function hook_scald_dailymotion_create_atom_alter($atom, $video) {
  // Store the video duration in the atom data bag. Note: if you want
  // to actually use that information to expose it in front, you probably
  // should add a field to your video atoms, and set the duration in that
  // field instead.
  $atom->data['duration'] = $video->duration;
}

/**
 * @} End of "addtogroup hooks".
 */
