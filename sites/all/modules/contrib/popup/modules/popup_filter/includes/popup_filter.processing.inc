<?php



/**
 * Replaces all [popup] tags with suitable html
 */
function popup_filter_process_text($text){

  $tagPattern = '/\[popup[^\[]+\]/';
  $found = array();
  preg_match_all($tagPattern, $text, $found);

  // Replace each found tag with its generated HTML
  foreach($found[0] as $tag){
    $text = str_replace($tag, popup_filter_process_tag($tag), $text);
  }

  return $text;
}



/**
 * Processes a popup tag
 */
function popup_filter_process_tag($tag){

  module_load_include('inc', 'popup', 'includes/popup.api');

  $attributes = _popup_tag_attributes($tag);

  return popup($attributes);
}



function _popup_tag_attributes($tag){

  $attributes = array();
  $inner = preg_replace('/\s?\=\s?/', '=', trim(substr($tag, 6, strlen($tag) - 7))).' ';

  $attribPattern =
    '/'.
    '(?:\s?[^\s=]+\s)|'.             // xx-_.01
    '(?:[^\s]*="[^"]+")|'.           // xx-_.01="..."
    '(?:[^\s]*=[\'][^\']+[\'])|'.    // xx-_.01='...'
    '(?:[^\s]*=[^\s]*)'.             // xx-_.01=xx-_.01
    '/';

  $found = array();
  preg_match_all($attribPattern, $inner, $found);
  
  foreach($found[0] as $attribute){

    $parts = explode('=', $attribute);

    $value = count($parts) > 1
    	? preg_replace('/(^[\'\"]{1})|([\'\"]{1}$)/', '', trim($parts[1]))
    	: '';

    $attributes[trim($parts[0])] = strlen($value)
      ? $value
      : TRUE;
  }

  return $attributes;
}