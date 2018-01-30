<?php

class fasttoggle_user_views_handler_field_user_link extends views_handler_field_user_link {
  var $fasttoggle_key = 'status';

  function construct() {
    parent::construct();

    // We need these fields for state checking later in the render() function.
    $this->additional_fields['uid'] = 'uid';
    $this->additional_fields['status'] = 'status';
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    unset($form['text']);
  }

  function render($values) {
    $account = new stdClass();
    if (!isset($this->aliases['uid'])) {
      return FALSE;
    }
    $account->uid = $values->{$this->aliases['uid']};
    $account->status = $values->{$this->aliases['status']};
    return $this->render_link($account, $values);
  }

  function render_link($user, $values) {
    drupal_load('module', 'fasttoggle');

    $options = fasttoggle_get_allowed_links('user', $user, $user->uid);
    $key = $this->fasttoggle_key;

    if (!empty($options) && isset($options['fields']['status']['instances'][$key])) {
      $link_info = fasttoggle($options, 'status', $key, $user, FASTTOGGLE_FORMAT_LINK_ARRAY);
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
