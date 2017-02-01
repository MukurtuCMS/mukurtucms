<?php

/**
 * @file
 * Views handlers for Colorbox Node module.
 */

/**
 * A handler to provide a field that is completely custom by the administrator.
 *
 * @ingroup views_field_handlers
 */
class colorbox_node_handler_field_colorbox_node_link extends views_handler_field_node_link {

  function option_definition() {
    $options = parent::option_definition();
    $options['node_in_colorbox'] = array('default' => isset($this->definition['node_in_colorbox default']) ? $this->definition['node_in_colorbox default'] : FALSE, 'bool' => FALSE);
    $options['node_in_colorbox_width'] = array('default' => isset($this->definition['node_in_colorbox_width default']) ? $this->definition['node_in_colorbox_width default'] : FALSE, 'string' => '600');
    $options['node_in_colorbox_height'] = array('default' => isset($this->definition['node_in_colorbox_height default']) ? $this->definition['node_in_colorbox_height default'] : FALSE, 'string' => '600');
    $options['node_in_colorbox_rel'] = array('default' => isset($this->definition['node_in_colorbox_rel default']) ? $this->definition['node_in_colorbox_rel default'] : FALSE, 'string' => '');
    return $options;
  }

  /**
   * Provide node in colorbox option
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['link_to_node']['#weight'] = '-98';
    $form['node_in_colorbox'] = array(
      '#type' => 'checkbox',
      '#title' => t('Display the content inside of a colorbox.'),
      '#description' => t("Enable to add colorbox support for this node."),
      '#default_value' => !empty($this->options['node_in_colorbox']),
      '#dependency' => array(
        'edit-options-link-to-node' => array(1),
      ),
      '#weight' => '-97',
    );
    $form['node_in_colorbox_width'] = array(
      '#type' => 'textfield',
      '#title' => t('Colorbox Width'),
      '#default_value' => !empty($this->options['node_in_colorbox_width']) ? $this->options['node_in_colorbox_width'] : '600',
      '#description' => t("Set a fixed total width. This includes borders and buttons. Example: \"100%\", or 600"),
      '#dependency' => array(
        'edit-options-node-in-colorbox' => array(1),
      ),
      '#dependency_count' => 1,
      '#weight' => -96,
    );
    $form['node_in_colorbox_height'] = array(
      '#type' => 'textfield',
      '#title' => t('Colorbox Height'),
      '#default_value' => !empty($this->options['node_in_colorbox_height']) ? $this->options['node_in_colorbox_height'] : '600',
      '#description' => t("Set a fixed total height. This includes borders and buttons. Example: \"100%\", or 600"),
      '#dependency' => array(
        'edit-options-node-in-colorbox' => array(1),
      ),
      '#dependency_count' => 1,
      '#weight' => -95,
    );
    $form['node_in_colorbox_rel'] = array(
      '#type' => 'textfield',
      '#title' => t('Colorbox Rel'),
      '#default_value' => !empty($this->options['node_in_colorbox_rel']) ? $this->options['node_in_colorbox_rel'] : '',
      '#description' => t("Enter a rel attribute here to group colorbox node links into a gallery."),
      '#dependency' => array(
        'edit-options-link-to-node' => array(1),
        'edit-options-node-in-colorbox' => array(1),
      ),
      '#dependency_count' => 2,
      '#weight' => -94,
    );
  }

  /**
   * Apply our colorbox-node class and add our widths and heights
   * to the query params.
   */
  function render_link($node, $values) {
    if (node_access('view', $node)) {
        if (!empty($this->options['node_in_colorbox'])) {
          // If we have a rel gallery for the colorbox, lets add our rel attribute
          // and our gallery class to the link output.
          if(!empty($this->options['node_in_colorbox_rel'])) {
            $this->options['alter']['rel'] = $this->options['node_in_colorbox_rel'];
            $this->options['alter']['link_class'] = 'colorbox-node colorbox-node-gallery';
          }
          else {
            $this->options['alter']['link_class'] = 'colorbox-node';
          }
          $this->options['alter']['link_attributes']['data-inner-width'] = $this->options['node_in_colorbox_width'];
          $this->options['alter']['link_attributes']['data-inner-height'] = $this->options['node_in_colorbox_height'];
        }
    }
    return parent::render_link($node, $values);
  }
}