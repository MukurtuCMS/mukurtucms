<?php

$plugin = array(
  'title' => 'File',
  'capture subpatterns' => TRUE,
  'scheme' => url('', array('absolute' => TRUE)) . 'file/*',
  'callback' => 'oembedprovider_file_provider',
  'provider' => TRUE,
);

/**
 * The default provider to handle files
 *
 * @param string $url
 * @param array $matches
 */
function oembedprovider_file_provider($plugin, $url, $matches, $parameters) {
  $block_endless_recursion = &drupal_static(__FUNCTION__, array());

  $result = FALSE;

  $fid = $matches[1];
  $defaults = array('view_mode' => 'full', 'langcode' => NULL);
  $parameters = array_merge($defaults, $parameters);

  if (!isset($block_endless_recursion[$fid])) {
    $block_endless_recursion[$fid] = TRUE;

    $file = file_load($fid);
    if ($file && file_entity_access('view', $file, drupal_anonymous_user())) {
      $author = user_load($file->uid);
      $build = file_view_file($file, $parameters['view_mode'], $parameters['langcode']);
      $result = array(
        'title' => $file->filename,
        'author_name' => $author->name,
        'author_url' => url('user/' . $author->uid, array('absolute' => TRUE)),
        '#entity_type' => 'file',
      );
      list($result['#id'], $result['#vid'], $result['#bundle']) = entity_extract_ids('file', $file);

      if ($file->type == 'image') {
        if ($build['#theme'] == 'image_style') {
          $dimensions = $file->image_dimensions;
          image_style_transform_dimensions($build['#style_name'], $dimensions);
          $result += array(
            'type' => 'photo',
            'url' => image_style_url($build['#style_name'], $build['#path']),
          ) + $dimensions;
        }
        else {
          $result += array(
            'type' => 'photo',
            'url' => file_create_url($file->uri),
          ) + $file->image_dimensions;
        }
      }
      else {
        $result += array(
          'type' => 'rich',
          'html' => drupal_render($build),
        );
      }

      $result = _oembedprovider_result($result['type'], $result);
    }

    unset($block_endless_recursion[$fid]);
  }

  return $result;
}
