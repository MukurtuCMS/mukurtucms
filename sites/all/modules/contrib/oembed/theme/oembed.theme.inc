<?php

/**
 * @file
 * Theme related functions for oEmbed Core
 */

/**
 * Theme for oEmbed output.
 */
function theme_oembed($vars) {
  $embed = $vars['embed'];

  $variables = array(
    'path' => $embed['original_url'],

    // oembed_alt_attr() returns output from t() and is sanitized.
    'text' => empty($embed['title']) ? oembed_alt_attr($embed) : check_plain($embed['title']),
    'options' => array(
      'absolute' => TRUE,
      'attributes' => array('class' => 'oembed-link'),
      'html' => TRUE,
    ),
  );

  return theme('link', $variables);
}

/**
 * Theme for photo oEmbed output.
 */
function theme_oembed__photo($vars) {
  $embed = $vars['embed'];
  $variables = array(
    'path' => $embed['url'],
    'alt' => oembed_alt_attr($embed),
    'width' => $embed['width'],
    'height' => $embed['height'],
  );
  return theme('image', $variables);
}

/**
 * Theme for rich oEmbed output.
 */
function theme_oembed__rich($vars) {
  $embed = $vars['embed'];
  return $embed['html'];
}

/**
 * Theme for video oEmbed output.
 */
function theme_oembed__video($vars) {
  $embed = $vars['embed'];

  // Add query parameters from original URL back into the embed
  // HTML as YouTube ignores them when generating the oEmbed code.
  if ($embed['provider'] == 'default:youtube') {
    // Parse original URL and isolate the query.
    $parsed_url = drupal_parse_url($embed['original_url']);
    $query = $parsed_url['query'];
    // Remove video ID from query.
    unset($query['v']);
    // Build query string and insert it into the embed HTML..
    $query_string = drupal_http_build_query($query);
    $search = '?feature=oembed';
    $replace = $search . '&' . $query_string;
    $embed['html'] = str_replace($search, $replace, $embed['html']);
  }

  return $embed['html'];
}
