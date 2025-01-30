<?php

/**
 * @file
 * Tokens for File Hash module.
 */

/**
 * Implements hook_token_info().
 */
function filehash_token_info() {
  $info = array();
  $names = filehash_names();
  foreach (filehash_columns() as $column) {
    $info['tokens']['file']["filehash-$column"] = array(
      'name' => t('@algo hash', array('@algo' => $names[$column])),
      'description' => t('The @algo hash of the file.', array('@algo' => $names[$column])),
    );
    $info['tokens']['file']["filehash-$column-pair-1"] = array(
      'name' => t('@algo hash: Initial pair', array('@algo' => $names[$column])),
      'description' => t('The @algo hash of the file: first and second characters.', array('@algo' => $names[$column])),
    );
    $info['tokens']['file']["filehash-$column-pair-2"] = array(
      'name' => t('@algo hash: Second pair', array('@algo' => $names[$column])),
      'description' => t('The @algo hash of the file: third and fourth characters.', array('@algo' => $names[$column])),
    );
  }
  return $info;
}

/**
 * Implements hook_tokens().
 */
function filehash_tokens($type, $tokens, array $data = array(), array $options = array()) {
  $replacements = array();
  if ($type == 'file' && !empty($data['file'])) {
    foreach (filehash_algos() as $column => $algo) {
      // Generate the file hash if it is needed but does not yet exist.
      if (empty($data['file']->filehash[$column])) {
        foreach ($tokens as $name => $original) {
          if (strpos($name, "filehash-$column") === 0) {
            $data['file']->filehash[$column] = filehash_hash($algo, $data['file']->uri) ?: NULL;
            break;
          }
        }
      }
      if (isset($tokens["filehash-$column"])) {
        $replacements[$tokens["filehash-$column"]] = $data['file']->filehash[$column];
      }
      if (isset($tokens["filehash-$column-pair-1"])) {
        $replacements[$tokens["filehash-$column-pair-1"]] = substr($data['file']->filehash[$column], 0, 2);
      }
      if (isset($tokens["filehash-$column-pair-2"])) {
        $replacements[$tokens["filehash-$column-pair-2"]] = substr($data['file']->filehash[$column], 2, 2);
      }
    }
  }
  return $replacements;
}
