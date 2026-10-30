<?php
/**
 * @file
 * Provides a new view display for the scald library.
 */

class scald_plugin_display_library extends views_plugin_display_page {
  /**
   * Overrides views_plugin_display_page::execute().
   *
   * The library won't go through the normal theming / page rendering
   * process. Instead, we'll just fetch / render the atoms, and print
   * the JSON by itself.
   * We won't be returning anything, which tells Drupal that everything
   * is already rendered.
   */
  public function execute() {
    $library = array();
    $summary = array('criteria' => array());

    // Hide the links that Views would normally display, as they confuse
    // DnD.
    $this->view->hide_admin_links = TRUE;

    // Execute the view to get all the filter that applies.
    $this->view->execute();

    // And now extract a summary from all the options that were filled.
    foreach ($this->view->filter as $id => $filter) {
      if ($filter->options['exposed']) {
        $value = $filter->value;
        // For Date filters, we need to preprocess a bit the date. Well,
        // ok, more than a bit...
        if ($filter instanceof date_api_filter_handler) {
          $dates = array();
          if ($filter->operator == 'between') {
            if ($value['min']) {
              $d = date_make_date($value['min']);
              $dates['min'] = '>' . date_format($d, $filter->format);
            }
            if ($value['max']) {
              $d = date_make_date($value['max']);
              $dates['max'] = '<' . date_format($d, $filter->format);
            }
          }
          else {
            if ($value['value']) {
              $d = date_make_date($value['value']);
              $dates['value'] = date_format($d, $filter->format);
            }
          }
          $value = $dates;
        }
        // For terms, we get the tids, which doesn't make the summary
        // really usefull. We'll get replace them with the term names.
        elseif ($filter instanceof views_handler_filter_term_node_tid && is_array($value)) {
          $names = array();
          // When migrating to D7, use the very useful _multiple variant
          // to reduce the number of queries.
          foreach ($value as $tid) {
            $term = taxonomy_term_load($tid);
            $names[] = $term->name;
          }
          $value = $names;
        }
        // For user names, the situation is pretty much like for terms:
        // we get the uids.
        elseif ($filter instanceof views_handler_filter_user_name && is_array($value)) {
          $names = array();
          foreach ($value as $uid) {
            $account = user_load($uid);
            $names[] = $account->name;
          }
          $value = $names;
        }
        // For boolean operators, we don't want to display anything if
        // <Any> was selected.
        elseif ($filter instanceof views_handler_filter_boolean_operator) {
          if ($value == 'All') {
            $value = '';
          }
          else {
            $value = $filter->value_options[$value];
          }
        }
        elseif (is_array($value) && isset($filter->value_options)) {
          foreach ($value as $k => $key) {
            if ($filter->value_options[$key]) {
              $value[$k] = $filter->value_options[$key];
            }
          }
        }
        if (is_array($value)) {
          $value = implode(', ', $value);
        }
        if ($value) {
          $summary['criteria'][] = $filter->options['expose']['label'] . ': ' . $value;
        }
      }
    }
    // Add info about how we sort the view in the summary.
    if (!empty($this->view->exposed_data)) {
      $exposed_data = $this->view->exposed_data;
      $sort_by = isset($exposed_data['sort_by']) ? $exposed_data['sort_by'] : FALSE;
      if ($sort_by && isset($this->view->sort[$sort_by])) {
        $label = $this->view->sort[$sort_by]->options['expose']['label'];
        if (isset($exposed_data['sort_order']) && in_array($exposed_data['sort_order'], array('ASC', 'DESC'))) {
          $order = $exposed_data['sort_order'];
        }
        else {
          $order = $this->view->sort[$sort_by]->options['expose']['order'];
        }
        $orders = array('ASC' => t('Ascending'), 'DESC' => t('Descending'));
        $summary['sort'] = t('<span class="label">Sort:</span> @criteria', array('@criteria' => $label . ' ' . $orders[$order]));
      }
    }

    // Render our header based on the built summary.
    $header = '<div class="summary">';
    $header .= '<div class="toggle"></div><div class="title">' . t('search') . '</div>';
    if (!empty($summary['sort'])) {
      $header .= '<div class="sort">' . $summary['sort'] . '</div>';
    }
    $header .= theme('item_list', array('items' => $summary['criteria']));
    $header .= '</div>';

    // Prepare the "Quick add" buttons, that will appear next to the library,
    // based on the user permissions.
    $atom_types = scald_types();
    $buttons = array('type' => 'ul', 'title' => NULL, 'attributes' => array());
    ctools_include('ajax');
    ctools_include('modal');
    foreach ($atom_types as $type) {
      if (scald_action_permitted(new ScaldAtom($type->type), 'create')) {
        $text = t($type->type);
        $alt = t('Create a new !type atom', array('!type' => $text));
        $buttons['items'][] = array(
          'data' => ctools_modal_text_button($text, 'atom/add/' . $type->type . '/nojs', $alt, 'ctools-modal-custom-style'),
          'class' => array('add-' . drupal_strtolower($type->type)),
        );
      }
    }

    // Finally render the resulting library.
    $view = $this->view->render();
    $messages = theme('status_messages');
    $library['library'] = $messages . $view . $header;
    foreach ($this->view->result as $result) {
      $sid = $result->sid;
      scald_dnd_library_add_item($library, $sid);
    }

    $library['menu'] = '<div class="scald-menu"><div class="add-buttons">' . theme('item_list', $buttons) . '</div></div>';
    $library['library'] = '<div class="scald-library">' . $library['library'] . '</div>';
    $library['anchor'] = '<div class="scald-anchor"></div>';
    drupal_json_output($library);
  }
}
