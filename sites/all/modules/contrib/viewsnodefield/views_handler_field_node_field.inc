<?php

/**
 * Field handler to present a node.
 */
class views_handler_field_node_field extends views_handler_field {
  function construct() {
    parent::construct();
    $this->additional_fields['nid'] = 'nid';
  }

  function option_definition() {
    $options = parent::option_definition();

    $options['build_mode'] = array('default' => 'teaser');
    $options['links'] = array('default' => TRUE);
    $options['comments'] = array('default' => FALSE);

    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $entity_info = entity_get_info('node');
    $options = array();
    if (!empty($entity_info['view modes'])) {
      foreach ($entity_info['view modes'] as $mode => $settings) {
        $options[$mode] = $settings['label'];
      }
    }
    if (empty($options)) {
      $options = array(
        'teaser' => t('Teaser'),
        'full' => t('Full node')
      );
    }

    $form['build_mode'] = array(
      '#type' => 'select',
      '#options' => $options,
      '#title' => t('Build mode'),
      '#default_value' => $this->options['build_mode'],
     );
    $form['links'] = array(
      '#type' => 'checkbox',
      '#title' => t('Display links'),
      '#default_value' => $this->options['links'],
    );
    $form['comments'] = array(
      '#type' => 'checkbox',
      '#title' => t('Display node comments'),
      '#default_value' => $this->options['comments'],
    );
  }

  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function render($values) {
    if ($values->{$this->aliases['nid']} && ($node = node_load($values->{$this->aliases['nid']}))) {
      $node->view = $this->view;
      $options = $this->options;

      // Detect which build module should be used.
      $node->build_mode = (!empty($options['build_mode'])) ? $options['build_mode'] : 'full';

      $content = node_view($node, $node->build_mode);

      if (!$options['links']) {
        unset($content['links']);
      }
      if (!empty($options['comments']) && user_access('access comments') && $node->comment) {
        $content['comments'] = comment_node_page_additions($node);
      }
      return drupal_render($content);
    }
    return array();
  }
}
