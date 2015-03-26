<?php

$plugin = array(
  'title' => 'Node',
  'capture subpatterns' => TRUE,
  'scheme' => url('', array('absolute' => TRUE)) . 'node/*',
  'callback' => 'oembedprovider_node_provider',
  'provider' => TRUE,
);

/**
 * The default provider to handle nodes
 *
 * @param string $url
 * @param array $matches
 */
function oembedprovider_node_provider($plugin, $url, $matches, $parameters) {
  $block_endless_recursion = &drupal_static(__FUNCTION__, array());

  $result = FALSE;

  $nid = $matches[1];
  $defaults = array('view_mode' => 'full', 'langcode' => NULL);
  $parameters = array_merge($defaults, $parameters);

  if (!isset($block_endless_recursion[$nid])) {
    $block_endless_recursion[$nid] = TRUE;

    $node = node_load($nid);
    if ($node && node_access('view', $node, drupal_anonymous_user())) {
      $author = user_load($node->uid);
      $build = node_view($node, $parameters['view_mode'], $parameters['langcode']);
      $result = array(
        'type' => 'rich',
        'html' => render($build),
        'title' => $node->title,
        'author_name' => $author->name,
        'author_url' => url('user/' . $author->uid, array('absolute' => TRUE)),
        '#entity_type' => 'node',
      );
      list($result['#id'], $result['#vid'], $result['#bundle']) = entity_extract_ids('node', $node);
      $result = _oembedprovider_result($result['type'], $result);
    }

    unset($block_endless_recursion[$nid]);
  }

  return $result;
}
