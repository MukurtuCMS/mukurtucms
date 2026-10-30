<?php
/**
 * @file
 * Provides a field containing the representation of an atom.
 */

class scald_views_handler_field_representation extends views_handler_field {
  /**
   * Renders the atom according in the context specified in the option form.
   */
  function render($values) {
    $sid = $values->{$this->field_alias};
    return scald_render($sid, $this->options['context']);
  }

  /**
   * Add a default context to the option definition.
   */
  function option_definition() {
    $options = parent::option_definition();
    $options['context'] = array('default' => 'sdl_library_item');
    return $options;
  }

  /**
   * Allow to choose in which context the atom should be rendered.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $options = array();
    $contexts = scald_contexts_public();
    foreach ($contexts as $name => $context) {
      $options[$name] = $context['title'];
    }
    $form['context'] = array(
      '#type' => 'select',
      '#title' => t('Context'),
      '#default_value' => $this->options['context'],
      '#description' => t('The context in which the atom should be rendered.'),
      '#options' => $options,
    );
  }
}
