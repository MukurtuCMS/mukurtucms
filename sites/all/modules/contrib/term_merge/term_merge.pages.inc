<?php

/**
 * @file
 * Menu page callbacks for Term Merge module.
 */

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
 */
function term_merge_form($form, $form_state, $vocabulary = NULL, $term = NULL) {
  if (is_null($vocabulary)) {
    $vocabulary = taxonomy_vocabulary_load($term->vid);
  }

  // It's always handy to have the vocabulary by hand.
  $form['#vocabulary'] = $vocabulary;

  if (!isset($form_state['storage']['confirm'])) {
    // We are at the set up step.

    $tree = taxonomy_get_tree($vocabulary->vid);

    $term_branch_value = is_null($term) ? NULL : array($term->tid);
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
    if (is_null($form['term_branch']['#default_value'])) {
      unset($form['term_branch']['#default_value']);
    }

    $form['term_trunk'] = array(
      '#type' => 'fieldset',
      '#title' => t('Merge Into'),
      '#prefix' => '<div id="term-merge-form-term-trunk">',
      '#suffix' => '</div>',
      '#tree' => TRUE,
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
    $function($form, $form_state, $vocabulary);

    // Ensuring the Merge Into form element has the same title no matter what
    // widget has been used.
    $form['term_trunk']['tid']['#title'] = t('Merge into');

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
    // We are at the confirmation step.
    $count = count($form_state['values']['term_branch']);
    $question = format_plural($count, 'Are you sure want to merge 1 term?', 'Are you sure want to merge @count terms?');
    $form = confirm_form($form, $question, 'admin/structure/taxonomy/' . $vocabulary->machine_name);
  }

  return $form;
}

/**
 * Supportive function.
 *
 * Validate the term_merge_form(). Make sure term trunk is not among the
 * selected term branches or their children.
 */
function term_merge_form_validate($form, &$form_state) {
  if (!isset($form_state['storage']['confirm'])) {
    // We only validate the 1st step of the form.
    $prohibited_trunks = array();
    foreach ($form_state['values']['term_branch'] as $term_branch) {
      $children = taxonomy_get_tree($form['#vocabulary']->vid, $term_branch);
      $prohibited_trunks[] = $term_branch;
      foreach ($children as $child) {
        $prohibited_trunks[] = $child->tid;
      }
    }
    if (in_array($form_state['values']['term_trunk']['tid'], $prohibited_trunks)) {
      form_error($form['term_trunk']['tid'], t('Trunk term cannot be one of the selected branch terms or their children.'));
    }
  }
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

    // Before storing the submitted values we slightly preprocess them to make
    // sure they correspond to what is expected by submit handler of taxonomy
    // creation form.
    if (isset($form_state['values']['relations'])) {
      $form_state['values'] += $form_state['values']['relations'];
    }
    $form_state['storage']['info'] = $form_state['values'];
    $form_state['storage']['merge_settings'] = term_merge_merge_options_submit($form, $form_state, $form);
    $form_state['storage']['old_form'] = $form;
  }
  else {
    // The user has confirmed merging. We pull up the submitted values.
    $form_state['values'] = $form_state['storage']['info'];

    // If necessary, create the term trunk.
    if ($form_state['values']['term_trunk']['tid'] == TERM_MERGE_NEW_TERM_TRUNK) {
      // We try to mimic normal form submission for taxonomy module.
      module_load_include('inc', 'taxonomy', 'taxonomy.admin');
      taxonomy_form_term_submit($form_state['storage']['old_form']['term_trunk']['term_create'], $form_state);
      $term_trunk = $form_state['term'];
    }
    else {
      $term_trunk = taxonomy_term_load($form_state['values']['term_trunk']['tid']);
    }

    term_merge(array_values($form_state['values']['term_branch']), $term_trunk->tid, $form_state['storage']['merge_settings']);

    $form_state['redirect'] = array('taxonomy/term/' . $term_trunk->tid);
  }
}

/**
 * Supportive function.
 *
 * Generate form elements for select widget for term trunk element of the
 * term_merge_form().
 *
 * @param object $vocabulary
 *   Fully loaded taxonomy vocabulary object
 */
function term_merge_form_term_trunk_widget_select(&$form, &$form_state, $vocabulary) {
  $tree = taxonomy_get_tree($vocabulary->vid);
  $options = array();
  foreach ($tree as $v) {
    $options[$v->tid] = str_repeat('-', $v->depth) . $v->name . ' [tid: ' . $v->tid . ']';
  }

  $term_branch_value = array();
  // Firstly trying to look up selected term branches in the default value of
  // term branch form element.
  if (isset($form['term_branch']['#default_value']) && is_array($form['term_branch']['#default_value'])) {
    $term_branch_value = $form['term_branch']['#default_value'];
  }
  if (isset($form_state['values']['term_branch']) && is_array($form_state['values']['term_branch'])) {
    $term_branch_value = $form_state['values']['term_branch'];
  }

  if (!empty($term_branch_value)) {
    // We have to make sure among term_trunk there is no term_branch or any of
    // their children.
    foreach ($term_branch_value as $v) {
      unset($options[$v]);
      foreach (taxonomy_get_tree($vocabulary->vid, $v) as $child) {
        unset($options[$child->tid]);
      }
    }
    $options = array(TERM_MERGE_NEW_TERM_TRUNK => 'New Term') + $options;
  }
  else {
    // Term branch has not been selected yet.
    $options = array();
  }

  $form['term_trunk']['tid'] = array(
    '#type' => 'select',
    '#required' => TRUE,
    '#description' => t('Choose into what term you want to merge.'),
    '#options' => $options,
    '#ajax' => array(
      'callback' => 'term_merge_form_term_trunk_term_create',
      'wrapper' => 'term-merge-form-term-trunk-term-create',
      'method' => 'replace',
      'effect' => 'fade',
    ),
  );

  $form['term_trunk']['term_create'] = array(
    '#prefix' => '<div id="term-merge-form-term-trunk-term-create">',
    '#suffix' => '</div>',
  );
  // We throw in the Taxonomy native term create form only if the option for
  // creation of a new term was selected by user.
  if (isset($form_state['values']['term_trunk']['tid']) && $form_state['values']['term_trunk']['tid'] == TERM_MERGE_NEW_TERM_TRUNK) {
    module_load_include('inc', 'taxonomy', 'taxonomy.admin');

    $form['term_trunk']['term_create'] += array(
      '#type' => 'fieldset',
      '#title' => t('Create New Term'),
    );

    $form['term_trunk']['term_create'] += taxonomy_form_term($form['term_trunk']['term_create'], $form_state, array(), $vocabulary);
    // We have our own submit button, so we unset the normal one from the term
    // create form.
    unset($form['term_trunk']['term_create']['actions']);
    // Additionally we have to filter out from "Parent Terms" select the already
    // selected branch terms and their children, because we can't merge into
    // the term itself or its children.
    // We do a trick here, since we know the 1st element is the <root> option
    // and all others are normal taxonomy terms, we keep the 1st element as it
    // is while all the other elements we substitute with our $options array
    // which is basically identical but already has been filtered out unwanted
    // terms. Plus we have to unset the 'New Term' option from $options.
    unset($options[TERM_MERGE_NEW_TERM_TRUNK]);
    if (is_array($form['term_trunk']['term_create']['relations']['parent']['#options'])) {
      $form['term_trunk']['term_create']['relations']['parent']['#options'] = array_slice($form['term_trunk']['term_create']['relations']['parent']['#options'], 0, 1, TRUE) + $options;
    }

    // For each field attached to taxonomy term of this vocabulary that has
    // unlimited cardinality we have to extra process the results, otherwise
    // "Add another item" button doesn't work.
    $instances = field_info_instances($form['term_trunk']['term_create']['#entity_type'], $form['term_trunk']['term_create']['#bundle']);
    foreach ($instances as $instance) {
      $field = field_info_field($instance['field_name']);
      if ($field['cardinality'] == FIELD_CARDINALITY_UNLIMITED) {
        if (isset($form['term_trunk']['term_create'][$field['field_name']][LANGUAGE_NONE]['add_more']['#limit_validation_errors'])) {
          $form['term_trunk']['term_create'][$field['field_name']][LANGUAGE_NONE]['add_more']['#limit_validation_errors'] = array(array('term_branch'), array('term_trunk'));
        }
      }
    }
  }
}

/**
 * Supportive function.
 *
 * Generate form element for hierarchical select widget for term trunk element
 * of the term_merge_form().
 *
 * @param object $vocabulary
 *   Fully loaded taxonomy vocabulary object
 */
function term_merge_form_term_trunk_widget_hs_taxonomy(&$form, &$form_state, $vocabulary) {
  $form['term_trunk']['tid'] = array(
    '#type' => 'hierarchical_select',
    '#description' => t('Please select a term to merge into.'),
    '#required' => TRUE,
    '#element_validate' => array('term_merge_form_trunk_term_widget_hs_taxonomy_validate'),
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
        'status' => 0,
      ),
      'editability' => array(
        'status' => 0,
      ),
      'resizable' => TRUE,
      'render_flat_select' => 0,
    ),
  );
}

/**
 * Supportive function.
 *
 * Generate form elements for autocomplete widget for term trunk element of the
 * term_merge_form().
 *
 * @param object $vocabulary
 *   Fully loaded taxonomy vocabulary object
 */
function term_merge_form_term_trunk_widget_autocomplete(&$form, &$form_state, $vocabulary) {
  $form['term_trunk']['tid'] = array(
    '#type' => 'textfield',
    '#description' => t("Start typing in a term's name in order to get some suggestions."),
    '#required' => TRUE,
    '#autocomplete_path' => 'term-merge/autocomplete/term-trunk/' . $vocabulary->machine_name,
    '#element_validate' => array('term_merge_form_trunk_term_widget_autocomplete_validate'),
  );
}

/**
 * Supportive function.
 *
 * Validate form element of the autocomplete widget of term trunk element of
 * the form term_merge_form(). Make sure the entered string is a name of one of
 * the existing terms in the vocabulary where the merge occurs. If term is found
 * the function substitutes the name with its {taxonomy_term_data}.tid as it is
 * what is expected from a term trunk widget to provide in its value.
 */
function term_merge_form_trunk_term_widget_autocomplete_validate($element, &$form_state, $form) {
  $term = taxonomy_get_term_by_name($element['#value'], $form['#vocabulary']->machine_name);
  if (!is_array($term) || empty($term)) {
    // Seems like the user has entered a non existing name in the autocomplete
    // textfield.
    form_error($element, t('There are no terms with name %name in the %vocabulary vocabulary.', array(
      '%name' => $element['#value'],
      '%vocabulary' => $form['#vocabulary']->name,
    )));
  }
  else {
    // We have to substitute the term's name with its tid in order to make this
    // widget consistent with the interface.
    $term = array_pop($term);
    form_set_value($element, $term->tid, $form_state);
  }
}

/**
 * Supportive function.
 *
 * Validate form element of the Hierarchical Select widget of term trunk element
 * of the form term_merge_form(). Convert the value from array to a single tid
 * integer value.
 */
function term_merge_form_trunk_term_widget_hs_taxonomy_validate($element, &$form_state, $form) {
  $tid = 0;
  if (is_array($element['#value']) && !empty($element['#value'])) {
    $tid = (int) array_pop($element['#value']);
  }
  form_set_value($element, $tid, $form_state);
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
    $n = $name;
    // Term names containing commas or quotes must be wrapped in quotes.
    if (strpos($name, ',') !== FALSE || strpos($name, '"') !== FALSE) {
      $n = '"' . str_replace('"', '""', $name) . '"';
    }
    $term_matches[$n] = check_plain($name . ' [tid: ' . $tid . ']');
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
 * Ajax callback function.
 *
 * Used in term_merge_term_merge_form() to replace the term create fieldset
 * depending on already selected term_branch values and the term_trunk value.
 */
function term_merge_form_term_trunk_term_create($form, $form_state) {
  return $form['term_trunk']['term_create'];
}

/**
 * Generate 'term_merge_duplicates_form'.
 *
 * Allow merging terms with the same or similar names.
 *
 * @param object $vocabulary
 *   Fully loaded taxonomy vocabulary object inside of which term merging
 *   occurs, if this argument is omitted, then $term is required and will be
 *   used to obtain information about Taxonomy vocabulary
 * @param object $parent_term
 *   Fully loaded taxonomy term object using which the function will pull up
 *   the vocabulary inside of which term merging occurs. Duplicate terms will be
 *   sought only among children of this term
 */
function term_merge_duplicates_form($form, &$form_state, $vocabulary = NULL, $parent_term = NULL) {
  // TODO: make this JavaScript #attached.
  drupal_add_js(drupal_get_path('module', 'term_merge') . '/js/duplicate.form.js');

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

  $form['scaling'] = array(
    '#type' => 'fieldset',
    '#title' => t('Scaling for large vocabularies'),
    '#description' => t('Adjust these settings if your vocabulary is very large.'),
    '#tree' => TRUE,
    '#collapsible' => TRUE,
  );

  $form['scaling']['help'] = array(
    '#markup' => '<p>' . format_plural(count($tree), 'Vocabulary %vocabulary has only 1 term. It is very unlikely you will merge anything here.', 'Vocabulary %vocabulary has @count terms. If this tool works slow, you may instruct the duplicate finder tool to terminate its work after it has found a specific number of possible duplicates.', array(
      '%vocabulary' => $vocabulary->name,
    )) . '</p>',
  );

  $form['scaling']['max_duplicates'] = array(
    '#type' => 'textfield',
    '#title' => t('Show N duplicates'),
    '#description' => t('Input an integer here - this many duplicates will be show on the form. Once this amount of possible duplicates is found, the search process terminates.'),
    '#required' => TRUE,
    '#default_value' => isset($form_state['values']['scaling']['max_duplicates']) ? $form_state['values']['scaling']['max_duplicates'] : 300,
    '#element_validate' => array('element_validate_integer_positive'),
  );

  $form['scaling']['update'] = array(
    '#type' => 'button',
    '#value' => t('Re-run duplicate search'),
    '#ajax' => array(
      'callback' => 'term_merge_duplicates_form_scaling',
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
    if ($count >= $form['scaling']['max_duplicates']['#default_value']) {
      // We have reached the limit of possible duplicates to be found.
      break;
    }
    $name = term_merge_duplicates_process_name($term->name);
    if (!isset($groups[$name])) {
      $groups[$name] = array();
    }
    else {
      // We increment count by one for the just encountered duplicate. Plus, if
      // it is the second duplicate in this group, we also increment it by one
      // for the 1st duplicate in the group.
      $count++;
      if (count($groups[$name]) == 1) {
        $count++;
      }
    }
    $groups[$name][$term->tid] = $term;
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

  foreach ($groups as $i => $group) {
    if (count($group) > 1) {
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
        );
      }

      $form['wrapper']['group'][$i] = array(
        '#type' => 'fieldset',
        '#title' => check_plain($first_term->name),
        '#collapsible' => TRUE,
        '#pre_render' => array('term_merge_duplicates_fieldset_preprocess'),
        '#element_validate' => array('term_merge_duplicates_fieldset_validate'),
      );

      $form['wrapper']['group'][$i]['duplicates'] = array(
        '#type' => 'tableselect',
        '#title' => 'Duplicates',
        '#header' => array(
          'id' => t('ID'),
          'title' => t('Title'),
          'description' => t('Description'),
          'language' => t('Language'),
          'parents' => t('Parents'),
        ),
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
 * String process function.
 *
 * Manipulate supplied var $name and by the output of this function terms in a
 * vocabulary are grouped as duplicates.
 *
 * @param string $name
 *   String that needs to be manipulated
 *
 * @return string
 *   Processed string (normally it implies making it upper case, stripping down
 *   any special chars, etc.)
 */
function term_merge_duplicates_process_name($name) {
  // Making upper case.
  $name = drupal_strtoupper($name);
  // Trying transliteration, if available.
  if (module_exists('transliteration')) {
    $name = transliteration_get($name);
    // Keeping only ASCII chars.
    $name = preg_replace('#\W#', '', $name);
  }
  return $name;
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
 * new data per current scaling settings.
 */
function term_merge_duplicates_form_scaling($form, &$form_state) {
  return $form['wrapper'];
}
