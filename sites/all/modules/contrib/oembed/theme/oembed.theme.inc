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
  return $embed['html'];
}
