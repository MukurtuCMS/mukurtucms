<?php

/**
 * @file
 * A handler to output site's base url.
 *
 * @ingroup views_field_handlers
 */

class ViewsBaseUrlHandlerBaseUrl extends views_handler_field {
  /**
   * Do nothing here. Just required to override the parent method.
   */
  public function query() {}

  /**
   * More base url options.
   */
  public function option_definition() {
    $options = parent::option_definition();

    $options['show_link'] = array('default' => FALSE);
    $options['show_link_options']['link_path'] = array('default' => '');
    $options['show_link_options']['link_text'] = array('default' => '');
    $options['show_link_options']['link_class'] = array('default' => '');
    $options['show_link_options']['link_title'] = array('default' => '');
    $options['show_link_options']['link_rel'] = array('default' => '');
    $options['show_link_options']['link_fragment'] = array('default' => '');
    $options['show_link_options']['link_query'] = array('default' => '');
    $options['show_link_options']['link_target'] = array('default' => '');

    return $options;
  }

  /**
   * More options form.
   */
  public function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['show_link'] = array(
      '#type' => 'checkbox',
      '#title' => t('Display as link'),
      '#description' => t('Show base URL as link. You can create a custom link using this option.'),
      '#default_value' => $this->options['show_link'],
    );

    $form['show_link_options'] = array(
      '#type' => 'container',
      '#states' => array(
        'invisible' => array(
          ':input[type=checkbox][name="options[show_link]"]' => array('checked' => FALSE),
        ),
      ),
    );

    $form['show_link_options']['link_path'] = array(
      '#type' => 'textfield',
      '#title' => t('Link path'),
      '#description' => t('Drupal path for this link. The base url will be prepended to this path. If nothing provided then base url will appear as link.'),
      '#default_value' => $this->options['show_link_options']['link_path'],
    );

    $form['show_link_options']['link_text'] = array(
      '#type' => 'textfield',
      '#title' => t('Link text'),
      '#description' => t('Link text. If nothing provided then link path will appear as link text.'),
      '#default_value' => $this->options['show_link_options']['link_text'],
    );

    $form['show_link_options']['link_class'] = array(
      '#type' => 'textfield',
      '#title' => t('Link class'),
      '#description' => t('CSS class to be applied to this link.'),
      '#default_value' => $this->options['show_link_options']['link_class'],
    );

    $form['show_link_options']['link_title'] = array(
      '#type' => 'textfield',
      '#title' => t('Link title'),
      '#description' => t('Title attribute for this link.'),
      '#default_value' => $this->options['show_link_options']['link_title'],
    );

    $form['show_link_options']['link_rel'] = array(
      '#type' => 'textfield',
      '#title' => t('Link rel'),
      '#description' => t('Rel attribute for this link.'),
      '#default_value' => $this->options['show_link_options']['link_rel'],
    );

    $form['show_link_options']['link_fragment'] = array(
      '#type' => 'textfield',
      '#title' => t('Fragment'),
      '#description' => t('Provide the ID with which you want to create fragment link.'),
      '#default_value' => $this->options['show_link_options']['link_fragment'],
    );

    $form['show_link_options']['link_query'] = array(
      '#type' => 'textfield',
      '#title' => t('Link query'),
      '#description' => t('Attach queries to the link. If there are multiple queries separate them using a space. For eg: %example1 OR %example2', array('%example1' => 'destination=node/add/page', '%example2' => 'destination=node/add/page q=some/page')),
      '#default_value' => $this->options['show_link_options']['link_query'],
    );

    $form['show_link_options']['link_target'] = array(
      '#type' => 'textfield',
      '#title' => t('Link target'),
      '#description' => t('Target attribute for this link.'),
      '#default_value' => $this->options['show_link_options']['link_target'],
    );

    // Get a list of the available fields and arguments for token replacement.
    $options = array();
    foreach ($this->view->display_handler->get_handlers('field') as $field => $handler) {
      $options[t('Fields')]["[$field]"] = $handler->ui_name();
      // We only use fields up to (and including) this one.
      if ($field == $this->options['id']) {
        break;
      }
    }

    // This lets us prepare the key as we want it printed.
    $count = 0;

    foreach ($this->view->display_handler->get_handlers('argument') as $handler) {
      $options[t('Arguments')]['%' . ++$count] = t('@argument title', array('@argument' => $handler->ui_name()));
      $options[t('Arguments')]['!' . $count] = t('@argument input', array('@argument' => $handler->ui_name()));
    }

    $this->document_self_tokens($options[t('Fields')]);

    // Default text.
    $output = '<p>' . t('You must add some additional fields to this display before using this field. These fields may be marked as <em>Exclude from display</em> if you prefer. Note that due to rendering order, you cannot use fields that come after this field; if you need a field not listed here, rearrange your fields.') . '</p>';
    // We have some options, so make a list.
    if (!empty($options)) {
      $output = '<p>' . t('The following tokens are available for this field. Note that due to rendering order, you cannot use fields that come after this field; if you need a field not listed here, rearrange your fields.
If you would like to have the characters \'[\' and \']\' please use the html entity codes \'%5B\' or  \'%5D\' or they will get replaced with empty space.') . '</p>';
      foreach (array_keys($options) as $type) {
        if (!empty($options[$type])) {
          $items = array();
          foreach ($options[$type] as $key => $value) {
            $items[] = $key . ' == ' . check_plain($value);
          }
          $output .= theme('item_list',
            array(
              'items' => $items,
              'type' => $type,
            ));
        }
      }
    }
    // This construct uses 'hidden' and not markup because process doesn't
    // run. It also has an extra div because the dependency wants to hide
    // the parent in situations like this, so we need a second div to
    // make this work.
    $form['show_link_options']['help'] = array(
      '#type' => 'fieldset',
      '#title' => t('Replacement patterns'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
      '#value' => $output,
    );
  }

  /**
   * Render site's base url.
   */
  public function render($values) {
    global $base_url;
    $output = '';
    $link_query = array();
    $tokens = $this->get_render_tokens($output);

    if ($this->options['show_link']) {
      global $language;

      if (!empty($this->options['show_link_options']['link_path'])) {
        $aliased_path = str_replace(array_keys($tokens), $tokens, $this->options['show_link_options']['link_path']);
        $aliased_path = drupal_get_path_alias($aliased_path);
      }

      // Link path.
      $link_path = empty($aliased_path) ? $base_url : $base_url . '/' . $aliased_path;

      // Link text.
      if (empty($this->options['show_link_options']['link_text'])) {
        if (empty($aliased_path)) {
          $link_text = $base_url;
        }
        else {
          $link_text = $base_url . '/' . $aliased_path;
        }
      }
      else {
        $link_text = $this->options['show_link_options']['link_text'];
      }

      // Link class.
      $link_class = empty($this->options['show_link_options']['link_class']) ? array() : explode(' ', $this->options['show_link_options']['link_class']);

      // Link query.
      if (!empty($this->options['show_link_options']['link_query'])) {
        $queries = explode(' ', $this->options['show_link_options']['link_query']);

        foreach ($queries as $query) {
          $param = explode('=', $query);
          $link_query[$param[0]] = $param[1];
        }
      }

      // Create link with options.
      $output = l($link_text, $link_path, array(
        'attributes' => array(
          'class' => $link_class,
          'title' => $this->options['show_link_options']['link_title'],
          'rel' => $this->options['show_link_options']['link_rel'],
          'target' => $this->options['show_link_options']['link_target'],
        ),
        'fragment' => $this->options['show_link_options']['link_fragment'],
        'query' => $link_query,
        'language' => $language,
        'html' => TRUE,
      ));
    }
    else {
      $output = $base_url;
    }

    // Replace token with values and return it as output.
    return str_replace(array_keys($tokens), $tokens, $output);
  }
}
