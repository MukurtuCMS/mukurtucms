<?php

/**
 * @file
 * Functions for the oEmbed filter
 */

function _oembed_filter_apply($text, $filter, $format, $langcode, $cache, $cache_id) {
  global $_oembed_default_parameters;
  $_oembed_default_parameters = array_filter(array(
    'maxwidth' => intval($filter->settings['maxwidth']),
    'maxheight' => intval($filter->settings['maxheight']),
  ));
  $text = preg_replace_callback("`(^|<p(?:\s[^>]*)*>|<li(?:\s[^>]*)*>|<br(?:\s[^>]*)*>|[ \n\r\t\(])((http://|https://|ftp://|mailto:|smb://|afp://|file://|gopher://|news://|ssl://|sslv2://|sslv3://|tls://|tcp://|udp://)([a-zA-Z0-9@:%_+*~#?&=.,/;-]*[a-zA-Z0-9@:%_+*~#&=/;-]))([.,?!]*?)(?=($|</p>|</li>|<br\s*/?>|[ \n\r\t\)]))`i", '_oembed_preg_parse', $text);
  unset($_oembed_default_parameters);
  return $text;
}

/**
 * Settings callback for the oEmbed filter.
 */
function _oembed_filter_settings($form, &$form_state, $filter, $format, $defaults) {
  $filter->settings += $defaults;

  $settings = array();
  $settings['maxwidth'] = array(
    '#type' => 'textfield',
    '#title' => t('Maximum width of embed'),
    '#default_value' => $filter->settings['maxwidth'],
    '#description' => t('The maximum width of an embed, isn\'t respected by all providers'),
  );
  $settings['maxheight'] = array(
    '#type' => 'textfield',
    '#title' => t('Maximum height of embed'),
    '#default_value' => $filter->settings['maxheight'],
    '#description' => t('The maximum height of an embed, isn\'t respected by all providers'),
  );
  return $settings;
}

function _oembed_preg_parse($match) {
  return _oembed_resolve_link($match[2], $match[1], $match[5]);
}

function _oembed_resolve_link($match, $prefix, $suffix) {
  global $_oembed_default_parameters;

  $url = decode_entities($match);
  return $prefix . oembed_resolve_link($_oembed_default_parameters, $url) . $suffix;
}
