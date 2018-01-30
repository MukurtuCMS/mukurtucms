<?php

class fasttoggle_comment_views_handler_field_comment_link extends views_handler_field_comment_link {
  var $fasttoggle_key = 'status';

  function construct() {
    parent::construct();
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    unset($form['text']);
  }

  function access() {
    //needs permission to administer comments in general
    return user_access('administer comments');
  }

  function render($values) {
    if ($entity = $this->get_value($values)) {
      return $this->render_link($entity, $values);
    }
  }

  function render_link($comment, $values) {
    drupal_load('module', 'fasttoggle');

    $options = fasttoggle_get_allowed_links('comment', $comment, $comment->cid);
    $key = $this->fasttoggle_key;

    if (!empty($options['fields']['status']['instances'][$key])) {
      $link_info = fasttoggle($options, 'status', $key, $comment, FASTTOGGLE_FORMAT_LINK_ARRAY);
      $this->options['alter']['make_link'] = TRUE;
      $this->options['alter']['path'] = $link_info['href'];
      $this->options['alter']['text'] = $link_info['title'];
      $this->options['alter']['query'] = $link_info['query'];
      $this->options['alter']['link_class'] = implode(' ', $link_info['attributes']['class']);
      $this->options['alter']['title'] = $link_info['attributes']['title'];

      return $link_info['title'];
    }
  }
}
