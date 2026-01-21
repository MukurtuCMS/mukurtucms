<?php

/**
 * @file
 * Handler for references_plugin_display.
 */

/**
 * Default class.
 *
 * @codingStandardsIgnoreStart
 */
class references_plugin_display extends views_plugin_display {
  //@codingStandardsIgnoreEnd

  /**
   * Option Definition.
   *
   * @codingStandardsIgnoreStart
   */
  public function option_definition() {
    // @codingStandardsIgnoreEnd
    $options = parent::option_definition();

    // Force the style plugin to 'references_style' and the row plugin to
    // 'fields'.
    $options['style_plugin']['default'] = 'references_style';
    $options['defaults']['default']['style_plugin'] = FALSE;
    $options['defaults']['default']['style_options'] = FALSE;
    $options['row_plugin']['default'] = 'references_fields';
    $options['defaults']['default']['row_plugin'] = FALSE;
    $options['defaults']['default']['row_options'] = FALSE;

    // Set the display title to an empty string (not used in this display type).
    $options['title']['default'] = '';
    $options['defaults']['default']['title'] = FALSE;

    return $options;
  }

  /**
   * Style type.
   *
   * @codingStandardsIgnoreStart
   */
  public function get_style_type() {
    // @codingStandardsIgnoreEnd
    return 'references';
  }

  /**
   * Execute.
   */
  public function execute() {
    return $this->view->render($this->display->id);
  }

  /**
   * Render.
   */
  public function render() {
    if (!empty($this->view->result) || !empty($this->view->style_plugin->definition['even empty'])) {
      return $this->view->style_plugin->render($this->view->result);
    }
    return '';
  }

  /**
   * Uses exposed.
   *
   * @codingStandardsIgnoreStart
   */
  public function uses_exposed() {
    // @codingStandardsIgnoreEnd
    return FALSE;
  }

  /**
   * Query.
   */
  public function query() {
    $options = $this->get_option('references_options');

    // Play nice with View UI 'preview' : if the view is not executed through
    // _*_reference_potential_references_views(), don't alter the query.
    if (empty($options)) {
      return;
    }

    // Make sure the id field is included in the results, and save its alias
    // so that references_plugin_style can retrieve it.
    $this->id_field_alias = $this->view->query->add_field($this->view->base_table, $this->view->base_field);

    // Restrict on the incoming string, or incoming ids.
    if ($options['string'] !== '') {
      switch ($options['match']) {
        case 'equals':
          $operator = '=';
          $value = $options['string'];
          break;

        case 'starts_with':
          $operator = 'LIKE';
          $value = db_like($options['string']) . '%';
          break;

        case 'contains':
        default:
          $operator = 'LIKE';
          $value = '%' . db_like($options['string']) . '%';
          break;
      }

      $table_alias = $this->view->query->ensure_table($this->view->base_table);
      $this->view->query->add_where(NULL, $table_alias . '.' . $options['title_field'], $value, $operator);
    }
    elseif ($options['ids']) {
      $table_alias = $this->view->query->ensure_table($this->view->base_table);
      $this->view->query->add_where(NULL, $table_alias . '.' . $this->view->base_field, $options['ids'], 'IN');
    }
  }

}
