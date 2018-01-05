<?php

/**
 * @file
 * Tokens for file hash module.
 */

/**
 * Implements hook_token_info().
 */
function filehash_token_info() {
  $info = array();
  $names = filehash_names();
  foreach (filehash_algos() as $algo) {
    $info['tokens']['file']["filehash-$algo"] = array(
      'name' => t('@algo hash', array('@algo' => $names[$algo])),
      'description' => t('The @algo hash of the file.', array('@algo' => $names[$algo])),
    );
    $info['tokens']['file']["filehash-$algo-pair-1"] = array(
      'name' => t('@algo hash: Initial pair', array('@algo' => $names[$algo])),
      'description' => t('The @algo hash of the file: first and second characters.', array('@algo' => $names[$algo])),
    );
    $info['tokens']['file']["filehash-$algo-pair-2"] = array(
      'name' => t('@algo hash: Second pair', array('@algo' => $names[$algo])),
      'description' => t('The @algo hash of the file: third and fourth characters.', array('@algo' => $names[$algo])),
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
    foreach (filehash_algos() as $algo) {
      // Generate the file hash if it is needed but does not yet exist.
      if (empty($data['file']->filehash[$algo])) {
        foreach ($tokens as $name => $original) {
          if (strpos($name, "filehash-$algo") === 0) {
            $data['file']->filehash[$algo] = hash_file($algo, $data['file']->uri);
            break;
          }
        }
      }
      if (isset($tokens["filehash-$algo"])) {
        $replacements[$tokens["filehash-$algo"]] = $data['file']->filehash[$algo];
      }
      if (isset($tokens["filehash-$algo-pair-1"])) {
        $replacements[$tokens["filehash-$algo-pair-1"]] = substr($data['file']->filehash[$algo], 0, 2);
      }
      if (isset($tokens["filehash-$algo-pair-2"])) {
        $replacements[$tokens["filehash-$algo-pair-2"]] = substr($data['file']->filehash[$algo], 2, 2);
      }
    }
  }
  return $replacements;
}
