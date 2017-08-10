<?php

/**
 * @file
 * Menu page callbacks for Term Merge module.
 */

/**
 * Base of the term merge action form.
 *
 * It is extracted into a separate function to better internal code reuse.
 *
 * @param object $vocabulary
 *   Fully loaded Taxonomy vocabulary where the merge should occur
 * @param array $term_branch_value
 *   Array of Taxonomy term IDs that are nominated as branch terms.
 */
function term_merge_form_base(&$form, &$form_state, $vocabulary, $term_branch_value) {
  $form['#vocabulary'] = $vocabulary;
  $form['#term_merge_term_branch'] = $term_branch_value;

  $tree = taxonomy_get_tree($vocabulary->vid);

  $form['term_trunk'] = array(
    '#type' => 'fieldset',
    '#title' => t('Merge Into'),
    '#prefix' => '<div id="term-merge-form-term-trunk">',
    '#suffix' => '</div>',
    '#tree' => TRUE,
    '#element_validate' => array('term_merge_form_base_term_trunk_validate'),
  );

  // Array of currently available widgets for choosing term trunk.
  $term_trunk_widget_options = array(
    'autocomplete' => 'Autocomplete',
  );
  if (variable_get('taxonomy_override_selector', FALSE) && module_exists('hs_taxonomy')) {
    $term_trunk_widget_options['hs_taxonomy'] = t('Hierarchical Select');
    $term_trunk_widget = 'hs_taxonomy';
  }
  else {
    $term_trunk_widget_options['select'] = t('Select');
    $term_trunk_widget = 'select';
  }

  // If the vocabulary is too big, by default we want the trunk term widget to
  // be autocomplete instead of select or hs_taxonomy.
  if (count($tree) > 200) {
    $term_trunk_widget = 'autocomplete';
  }

  // Override the term trunk widget if settings are found in $form_state.
  if (isset($form_state['values']['term_trunk']['widget']) && in_array($form_state['values']['term_trunk']['widget'], array_keys($term_trunk_widget_options))) {
    $term_trunk_widget = $form_state['values']['term_trunk']['widget'];
  }

  // TODO: the trunk term widgets should be implemented as cTools plugins.
  $form['term_trunk']['widget'] = array(
    '#type' => 'radios',
    '#title' => t('Widget'),
    '#required' => TRUE,
    '#options' => $term_trunk_widget_options,
    '#default_value' => $term_trunk_widget,
    '#description' => t('Choose what widget you prefer for entering the term trunk.'),
    '#ajax' => array(
      'callback' => 'term_merge_form_term_trunk',
      'wrapper' => 'term-merge-form-term-trunk',
      'method' => 'replace',
      'effect' => 'fade',
    ),
  );

  // @todo:
  // There is a known bug, if user has selected something in one widget, and
  // then changes the widget, $form_states['values'] will hold the value for
  // term trunk form element in the format that is used in one widget, while
  // this value will be passed to another widget. This triggers different
  // unpleasant effects like showing tid instead of term's name or vice-versa.
  // I think we should just empty $form_state['values'] for the term trunk
  // form element when widget changes. Better ideas are welcome!
  $function = 'term_merge_form_term_trunk_widget_' . $term_trunk_widget;
  $function($form, $form_state, $vocabulary, $term_branch_value);

  // Ensuring the Merge Into form element has the same title no matter what
  // widget has been used.
  $form['term_trunk']['tid']['#title'] = t('Merge into');

  // Adding necessary options of merging.
  $form += term_merge_merge_options_elements($vocabulary);
}

/**
 * Menu callback.
 *
 * Allow user to specify which terms to be merged into which term and any
 * other settings needed for the term merge action.
 *
 * @param object $vocabulary
 *   Fully loaded taxonomy vocabulary object
 * @param object $term
 *   Fully loaded taxonomy term object that should be selected as the default
 *   merge term in the form. If the $vocabulary is omitted, the vocabulary of
 *   $term is considered
 *
 * @return array
 *   Array of the form in Form API format
 *
 * TODO: accidentally this function happens to implement hook_form() which is
 * definitely not my intention. This function must be renamed to a safer name.
 */
function term_merge_form($form, $form_state, $vocabulary = NULL, $term = NULL) {
  if (is_null($vocabulary)) {
    $vocabulary = taxonomy_vocabulary_load($term->vid);
  }

  if (!isset($form_state['storage']['confirm'])) {
    // We are at the set up step.

    $tree = taxonomy_get_tree($vocabulary->vid);

    $term_branch_value = is_null($term) ? array() : array($term->tid);
    if (variable_get('taxonomy_override_selector', FALSE) && module_exists('hs_taxonomy')) {
      // We use Hierarchical Select module if it's available and configured to
      // be used for taxonomy selects.
      $form['term_branch'] = array(
        '#type' => 'hierarchical_select',
        // @todo: figure out why #required => TRUE doesn't work.
        // As a matter of fact, this issue seems to cover our case.
        // http://drupal.org/node/1275862.
        //'#required' => TRUE,
        '#config' => array(
          'module' => 'hs_taxonomy',
          'params' => array(
            'vid' => $vocabulary->vid,
            'exclude_tid' => NULL,
            'root_term'   => FALSE,
          ),
          'enforce_deepest' => 0,
          'entity_count' => 0,
          'require_entity' => 0,
          'save_lineage' => 0,
          'level_labels' => array(
            'status' => 0,
          ),
          'dropbox' => array(
            'status' => 1,
            'limit' => 0,
          ),
          'editability' => array(
            'status' => 0,
          ),
          'resizable' => TRUE,
          'render_flat_select' => 0,
        ),
      );
    }
    else {
      // Falling back on a simple <select>.
      $options = array();
      foreach ($tree as $v) {
        $options[$v->tid] = str_repeat('-', $v->depth) . $v->name . ' [tid: ' . $v->tid . ']';
      }
      $form['term_branch'] = array(
        '#type' => 'select',
        '#required' => TRUE,
        '#multiple' => TRUE,
        '#options' => $options,
        '#size' => 8,
      );
    }

    $form['term_branch'] = array(
      '#title' => t('Terms to Merge'),
      '#description' => t('Please, choose the terms you want to merge into another term.'),
      '#ajax' => array(
        'callback' => 'term_merge_form_term_trunk',
        'wrapper' => 'term-merge-form-term-trunk',
        'method' => 'replace',
        'effect' => 'fade',
      ),
      '#default_value' => $term_branch_value,
    ) + $form['term_branch'];

    // We overwrite term branch value with the one from $form_state, if there is
    // something there.
    if (isset($form_state['values']['term_branch']) && is_array($form_state['values']['term_branch'])) {
      $term_branch_value = $form_state['values']['term_branch'];
    }

    term_merge_form_base($form, $form_state, $vocabulary, $term_branch_value);

    $form['actions'] = array(
      '#type' => 'actions',
    );

    $form['actions']['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Submit'),
    );
  }
  else {
    // We are at the confirmation step.
    $count = count($form_state['values']['term_branch']);
    $question = format_plural($count, 'Are you sure want to merge 1 term?', 'Are you sure want to merge @count terms?');
    $form = confirm_form($form, $question, 'admin/structure/taxonomy/' . $vocabulary->machine_name);
  }

  return $form;
}

/**
 * Submit handler for term_merge_form(). Merge terms one into another.
 */
function term_merge_form_submit($form, &$form_state) {
  if (!isset($form_state['storage']['confirm'])) {
    // Since merging terms is an important operation, we better confirm user
    // really wants to do this.
    $form_state['storage']['confirm'] = 0;
    $form_state['rebuild'] = TRUE;

    $form_state['storage']['info'] = $form_state['values'];
    $form_state['storage']['merge_settings'] = term_merge_merge_options_submit($form, $form_state, $form);
  }
  else {
    // The user has confirmed merging. We pull up the submitted values.
    $form_state['values'] = $form_state['storage']['info'];

    term_merge(array_values($form_state['values']['term_branch']), $form_state['values']['term_trunk']['tid'], $form_state['storage']['merge_settings']);

    $form_state['redirect'] = array('taxonomy/term/' . $form_state['values']['term_trunk']['tid']);
  }
}

/**
 * Menu page callback function.
 *
 * Autocomplete callback function for the trunk term form element in the widget
 * of autocomplete. The code of this function was mainly copy-pasted from
 * Taxonomy autocomplete widget menu callback function.
 *
 * @param object $vocabulary
 *   Fully loaded vocabulary object inside of which the terms are about to be
 *   merged
 */
function term_merge_form_term_trunk_widget_autocomplete_autocomplete($vocabulary) {
  // If the request has a '/' in the search text, then the menu system will have
  // split it into multiple arguments, recover the intended $tags_typed.
  $args = func_get_args();
  // Shift off the $vocabulary argument.
  array_shift($args);
  $tags_typed = implode('/', $args);

  // Querying database for suggestions.
  $query = db_select('taxonomy_term_data', 't');
  $tags_return = $query->addTag('translatable')
    ->addTag('term_access')
    ->fields('t', array('tid', 'name'))
    ->condition('t.vid', $vocabulary->vid)
    ->condition('t.name', '%' . db_like($tags_typed) . '%', 'LIKE')
    ->range(0, 10)
    ->execute()
    ->fetchAllKeyed();

  $term_matches = array();
  foreach ($tags_return as $tid => $name) {
    // Add both term name and tid to array key in order to allow multiple terms
    // with same name to be displayed.
    $key = "$name ($tid)";
    // Names containing commas or quotes must be wrapped in quotes.
    if (strpos($key, ',') !== FALSE || strpos($key, '"') !== FALSE) {
      $key = '"' . str_replace('"', '""', $key) . '"';
    }
    $term_matches[$key] = check_plain($name . ' [tid: ' . $tid . ']');
  }

  drupal_json_output($term_matches);
}

/**
 * Ajax callback function.
 *
 * Used in term_merge_term_merge_form() to replace the term_trunk element
 * depending on already selected term_branch values.
 */
function term_merge_form_term_trunk($form, $form_state) {
  return $form['term_trunk'];
}

/**
 * Generate 'term_merge_duplicates_form'.
 *
 * Allow merging terms with the same or similar names.
 *
 * @param object $vocabulary
 *   Fully loaded taxonomy vocabulary object inside of which term merging
 *   occurs, if this argument is omitted, then $parent_term is required and will
 *   be used to obtain information about Taxonomy vocabulary
 * @param object $parent_term
 *   Fully loaded taxonomy term object using which the function will pull up
 *   the vocabulary inside of which term merging occurs. Duplicate terms will be
 *   sought only among children of this term
 */
function term_merge_duplicates_form($form, &$form_state, $vocabulary = NULL, $parent_term = NULL) {
  $form['#attached']['js'][drupal_get_path('module', 'term_merge') . '/js/duplicate.form.js'] = array();

  // Checking if we were not given vocabulary object, we will use term object to
  // obtain the former.
  if (!is_null($parent_term) && is_null($vocabulary)) {
    $vocabulary = taxonomy_vocabulary_load($parent_term->vid);
  }

  $tree = taxonomy_get_tree($vocabulary->vid, is_null($parent_term) ? 0 : $parent_term->tid);

  // Helpful and self explaining text that should help people understand what's
  // up.
  $form['help'] = array(
    '#markup' => '<p>' . t('Here you can merge terms with the same names. It is a useful tool against term-duplicates. If this tool is invoked on a term (not on the entire vocabulary), duplicate terms will be sought only among children of that term. The terms are grouped by names. Term into which the merging will occur is selected manually by user, however you must know that it is impossible to merge a parent term into any of its children.') . '</p>',
  );

  $form['settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Advanced settings'),
    '#description' => t('Fine tune the duplicate search tool. You can adjust these settings if your vocabulary is very large. Also, you can control within these settings how the potential duplicates are presented below.'),
    '#tree' => TRUE,
    '#collapsible' => TRUE,
  );

  $form['settings']['help'] = array(
    '#markup' => '<p>' . format_plural(count($tree), 'Vocabulary %vocabulary has only 1 term. It is very unlikely you will merge anything here.', 'Vocabulary %vocabulary has @count terms. If this tool works slow, you may instruct the duplicate finder tool to terminate its work after it has found a specific number of possible duplicates.', array(
      '%vocabulary' => $vocabulary->name,
    )) . '</p>',
  );

  $form['settings']['max_duplicates'] = array(
    '#type' => 'textfield',
    '#title' => t('Show N duplicates'),
    '#description' => t('Input an integer here - this many duplicates will be shown on the form. Once this amount of possible duplicates is found, the search process terminates.'),
    '#required' => TRUE,
    '#default_value' => isset($form_state['values']['settings']['max_duplicates']) ? $form_state['values']['settings']['max_duplicates'] : 300,
    '#element_validate' => array('element_validate_integer_positive'),
  );

  $options = array();
  foreach (term_merge_duplicate_suggestion() as $plugin) {
    $options[$plugin['name']] = $plugin['title'];
  }
  $form['settings']['duplicate_suggestion'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Mark terms as duplicate if all the checked conditions stand true'),
    '#options' => $options,
    '#default_value' => isset($form_state['values']['settings']['duplicate_suggestion']) ? $form_state['values']['settings']['duplicate_suggestion'] : array('name'),
  );

  $options = array();
  $bundle = field_extract_bundle('taxonomy_term', $vocabulary);
  foreach (field_info_instances('taxonomy_term', $bundle) as $instance) {
    $options[$instance['field_name']] = $instance['label'];
  }

  if (!empty($options)) {
    $form['settings']['fields'] = array(
      '#type' => 'checkboxes',
      '#title' => t('Display fields'),
      '#description' => t('Check which fields you wish to display in the results below for each possible duplicate term.'),
      '#options' => $options,
      '#default_value' => isset($form_state['values']['settings']['fields']) ? array_values(array_filter($form_state['values']['settings']['fields'])) : array(),
    );
  }

  $form['settings']['update'] = array(
    '#type' => 'button',
    '#value' => t('Re-run duplicate search'),
    '#ajax' => array(
      'callback' => 'term_merge_duplicates_form_settings',
      'wrapper' => 'term-merge-duplicate-wrapper',
      'method' => 'replace',
      'effect' => 'fade',
    ),
  );

  // Amount of found duplicates.
  $count = 0;

  // Array of groups of terms with the same name. Each group is an array of
  // duplicates. Trunk term of each group will be chosen by user.
  $groups = array();

  foreach ($tree as $term) {
    if ($count >= $form['settings']['max_duplicates']['#default_value']) {
      // We have reached the limit of possible duplicates to be found.
      break;
    }
    $hash = '';
    foreach ($form['settings']['duplicate_suggestion']['#default_value'] as $duplicate_suggestion) {
      $duplicate_suggestion = term_merge_duplicate_suggestion($duplicate_suggestion);
      $function = ctools_plugin_get_function($duplicate_suggestion, 'hash callback');
      if ($function) {
        $hash .= $function($term);
      }
    }
    if (!isset($groups[$hash])) {
      $groups[$hash] = array();
    }
    else {
      // We increment count by one for the just encountered duplicate. Plus, if
      // it is the second duplicate in this group, we also increment it by one
      // for the 1st duplicate in the group.
      $count++;
      if (count($groups[$hash]) == 1) {
        $count++;
      }
    }
    $groups[$hash][$term->tid] = $term;
  }

  $form['wrapper'] = array(
    '#prefix' => '<div id="term-merge-duplicate-wrapper">',
    '#suffix' => '</div>',
  );

  if ($count > 0) {
    $form['wrapper']['global_switch'] = array(
      '#type' => 'checkbox',
      '#title' => t('Select All Terms'),
      '#description' => t('Checking here will select for merging all the encountered duplicate terms.'),
      '#attributes' => array(
        'class' => array('term-merge-duplicate-general-switch'),
      ),
    );
  }

  $form['wrapper']['group'] = array(
    '#tree' => TRUE,
  );

  $groups = array_filter($groups, 'term_merge_duplicates_form_filter');

  $tids = array();
  foreach ($groups as $group) {
    $tids = array_merge($tids, array_keys($group));
  }

  // This array will be keyed by term tid and values will be counts of how many
  // other entities reference to this term through values of fields attached to
  // them.
  $terms_count = array_fill_keys($tids, 0);
  if (!empty($tids)) {
    foreach (term_merge_fields_with_foreign_key('taxonomy_term_data', 'tid') as $referencing_field) {
      if ($referencing_field['storage']['type'] == 'field_sql_storage') {
        $table = array_keys($referencing_field['storage']['details']['sql'][FIELD_LOAD_CURRENT]);
        $table = reset($table);
        $column = $referencing_field['storage']['details']['sql'][FIELD_LOAD_CURRENT][$table][$referencing_field['term_merge_field_column']];
        $select = db_select($table, 'reference')
          ->condition($column, $tids);
        $select->addField('reference', $column, 'tid');
        $select->addExpression('COUNT(1)', 'count');
        $select->groupBy($column);
        $select = $select->execute();
        foreach ($select as $row) {
          $terms_count[$row->tid] += $row->count;
        }
      }
    }
  }

  if (!empty($form['settings']['fields']['#default_value'])) {
    // We need to load full term entities, because we are requested to show
    // fields.
    $terms = taxonomy_term_load_multiple($tids);
    foreach ($groups as $i => $group) {
      $groups[$i] = array_intersect_key($terms, $group);
    }
  }

  foreach ($groups as $i => $group) {
    // Sorting terms by tid for better usage experience.
    ksort($group);

    $first_term = reset($group);

    $options = array();
    foreach ($group as $term) {
      $parents = array();
      // Adding Root to the hierarchy.
      $parents[] = t('Vocabulary Root');
      foreach (taxonomy_get_parents_all($term->tid) as $parent) {
        // We do not include the current term in the hierarchy.
        if ($parent->tid != $term->tid) {
          $parents[] = $parent->name;
        }
      }
      $language = isset($term->language) ? $term->language : LANGUAGE_NONE;
      if ($language == LANGUAGE_NONE) {
        $language = t('Not Specified');
      }

      $options[$term->tid] = array(
        'id' => $term->tid,
        'title' => l($term->name, 'taxonomy/term/' . $term->tid),
        'language' => $language,
        'description' => check_markup($term->description, $term->format),
        'parents' => implode(' &raquo; ', $parents),
        'count' => format_plural($terms_count[$term->tid], '@count time', '@count times'),
      );

      if (isset($form['settings']['fields'])) {
        foreach ($form['settings']['fields']['#default_value'] as $instance) {
          $field = field_info_field($instance);
          $items = field_get_items('taxonomy_term', $term, $field['field_name']);
          $options[$term->tid][$field['field_name']] = '';
          if (is_array($items)) {
            $options[$term->tid][$field['field_name']] = array(
              '#theme' => 'item_list',
              '#items' => array(),
            );
            foreach ($items as $item) {
              switch ($field['type']) {
                case 'image':
                  $display = array();
                  $image_style = image_style_load('thumbnail');
                  if ($image_style) {
                    $cache = _field_info_field_cache();
                    $display = $cache->prepareInstanceDisplay($display, $field['type']);
                    $display['settings']['image_style'] = $image_style['name'];
                  }
                  $rendered_item = drupal_render(field_view_value('taxonomy_term', $term, $field['field_name'], $item, $display));
                  break;

                default:
                  $rendered_item = drupal_render(field_view_value('taxonomy_term', $term, $field['field_name'], $item));
                  break;
              }
              $options[$term->tid][$field['field_name']]['#items'][] = $rendered_item;
            }
            if (count($options[$term->tid][$field['field_name']]['#items']) > 1) {
              $options[$term->tid][$field['field_name']] = drupal_render($options[$term->tid][$field['field_name']]);
            }
            else {
              $options[$term->tid][$field['field_name']] = $options[$term->tid][$field['field_name']]['#items'][0];
            }
          }
        }
      }
    }

    $form['wrapper']['group'][$i] = array(
      '#type' => 'fieldset',
      '#title' => check_plain($first_term->name),
      '#collapsible' => TRUE,
      '#pre_render' => array('term_merge_duplicates_fieldset_preprocess'),
      '#element_validate' => array('term_merge_duplicates_fieldset_validate'),
    );

    $header = array(
      'id' => t('ID'),
      'title' => t('Title'),
      'description' => t('Description'),
      'language' => t('Language'),
      'parents' => t('Parents'),
      'count' => t('Referenced'),
    );

    if (isset($form['settings']['fields'])) {
      $header += array_map('check_plain', array_intersect_key($form['settings']['fields']['#options'], drupal_map_assoc($form['settings']['fields']['#default_value'])));
    }

    $form['wrapper']['group'][$i]['duplicates'] = array(
      '#type' => 'tableselect',
      '#title' => 'Duplicates',
      '#header' => $header,
      '#options' => $options,
    );

    $options = array();
    foreach ($group as $term) {
      $options[$term->tid] = $term->name;
    }
    $form['wrapper']['group'][$i]['trunk_tid'] = array(
      '#type' => 'radios',
      '#title' => t('Merge Into'),
      '#options' => $options,
      '#attributes' => array(
        'class' => array('term-merge-duplicate-trunk'),
      ),
    );
  }

  if ($count > 0) {
    // Adding necessary options of merging.
    $form += term_merge_merge_options_elements($vocabulary);

    $form['actions'] = array(
      '#type' => 'actions',
    );

    $form['actions']['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Submit'),
    );
  }
  else {
    if (is_null($parent_term)) {
      $no_match_text = t('Sorry, seems like we were not able to find any possible duplicate terms in %vocabulary vocabulary.', array(
        '%vocabulary' => $vocabulary->name,
      ));
    }
    else {
      $no_match_text = t('Sorry, seems like we were not able to find any possible duplicate terms among children of %term term. You may want to search for duplicates through the entire <a href="!url">vocabulary</a>.', array(
        '%term' => $parent_term->name,
        '!url' => url('admin/structure/taxonomy/' . $vocabulary->machine_name . '/merge/duplicates'),
      ));
    }
    $form['nothing_found'] = array(
      '#markup' => '<p><b>' . $no_match_text . '</b></p>',
    );
  }

  return $form;
}

/**
 * Submit handler for 'term_merge_duplicates_form'.
 *
 * Actually merge duplicate terms.
 */
function term_merge_duplicates_form_submit($form, &$form_state) {
  $batch = array(
    'title' => t('Merging terms'),
    'operations' => array(),
    'finished' => 'term_merge_batch_finished',
    'file' => drupal_get_path('module', 'term_merge') . '/term_merge.batch.inc',
  );

  // Processing general options for merging.
  $merge_settings = term_merge_merge_options_submit($form, $form_state, $form);

  if (isset($form_state['values']['group'])) {
    foreach ($form_state['values']['group'] as $values) {
      // Filtering out only the selected duplicate terms.
      $term_branches = array_filter($values['duplicates']);
      // We also do not want to have trunk term to be among the branch terms.
      unset($term_branches[$values['trunk_tid']]);
      if (!empty($term_branches)) {
        // If something has been selected in this group we schedule its merging.
        $batch['operations'][] = array('_term_merge_batch_process', array(
          $term_branches,
          $values['trunk_tid'],
          $merge_settings,
        ));
      }
    }
  }

  if (empty($batch['operations'])) {
    drupal_set_message(t('No merging has been made, because you have not selected any duplicate term to merge.'));
  }
  else {
    batch_set($batch);
  }
}

/**
 * Form element preprocess function.
 *
 * Insert extra column for choosing term trunk into tableselect of terms to be
 * merged.
 */
function term_merge_duplicates_fieldset_preprocess($element) {
  $options = &$element['duplicates']['#options'];
  foreach ($options as $tid => $row) {
    $element['trunk_tid'][$tid]['#title_display'] = 'invisible';
    $options[$tid] = array(
      'trunk' => drupal_render($element['trunk_tid'][$tid]),
    ) + $options[$tid];
  }
  $element['trunk_tid']['#title_display'] = 'invisible';
  $element['duplicates']['#header'] = array(
    'trunk' => $element['trunk_tid']['#title'],
  ) + $element['duplicates']['#header'];

  return $element;
}

/**
 * FAPI element validation callback.
 *
 * Validate fieldset of a 'term_merge_duplicates_form' form, if any duplicate
 * has been selected for merging, it makes sure the trunk term has been
 * selected. We can't allow merging without knowing the explicit trunk term.
 */
function term_merge_duplicates_fieldset_validate($element, &$form_state, $form) {
  if (!empty($element['duplicates']['#value']) && !is_numeric($element['trunk_tid']['#value'])) {
    form_error($element, t('Please, choose %trunk_tid_label for the group %group_label', array(
      '%trunk_tid_label' => $element['trunk_tid']['#title'],
      '%group_label' => $element['#title'],
    )));
  }
}

/**
 * Ajax callback function.
 *
 * Used in term_merge_duplicates_form() to replace the duplicates tables with
 * new data per current settings.
 */
function term_merge_duplicates_form_settings($form, &$form_state) {
  return $form['wrapper'];
}

/**
 * Supportive array_filter() callback function.
 *
 * Eliminate all array elements, whose length is less than 1.
 */
function term_merge_duplicates_form_filter($array_element) {
  return count($array_element) > 1;
}
