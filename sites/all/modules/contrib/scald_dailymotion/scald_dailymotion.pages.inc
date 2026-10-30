<?php

/**
 * @file
 * Contains form handlers for the DailyMotion search form.
 */

/**
 * Generates the search and search results form.
 */
function scald_dailymotion_search_form($form, &$form_state) {
  $terms = '';

  // Check if storage contains a value. A value is set only after the form is
  // submitted and 'rebuild' is set to TRUE.
  if (!empty($form_state['storage']['terms'])) {
    $terms = $form_state['storage']['terms'];
    // Display a message with the submitted value.
    drupal_set_message(t("Your search terms: @terms", array('@terms' => $terms)));
  }

  // Define form elements.
  $form = array();
  $form['search'] = array(
    '#type' => 'fieldset',
    '#tree' => TRUE,
    '#attributes' => array('class' => array('container-inline')),
  );
  $form['search']['search_term'] = array(
    '#type' => 'textfield',
    '#title' => t('Terms'),
    '#default_value' => $terms,
  );
  $form['search']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Search'),
    '#submit' => array('scald_dailymotion_search_form_search_submit'),
  );

  // If we have specified terms, execute the search and display the results.
  if (!empty($terms)) {
    $form['results'] = array(
      '#type' => 'fieldset',
      '#title' => t('Search results'),
      '#tree' => TRUE,
      '#theme' => 'scald_dailymotion_search_results_table',
    );

    $params = array(
      'fields' => _scald_dailymotion_api_fields(),
      'limit' => SCALD_DAILYMOTION_MAX_ITEMS,
      'search' => $terms,
    );
    $params['fields'][] = 'thumbnail_120_url';
    $data = _scald_dailymotion_api_call('videos', $params);
    if ($data && $data->list) {
      $items = $data->list;
      // Iterate on all results.
      foreach ($items as $video) {
        // Prepare variables for theme_image().
        $image_variables = array(
          'path' => str_replace('large', 'small', $video->thumbnail_120_url),
          'alt' => $video->title,
          'title' => $video->title,
        );

        // Prepare row data.
        $form['results']['videos'][$video->id] = array(
          'import' => array(
            '#type'         => 'radio',
            '#return_value' => $video->id,
            // This ensure the selected result is in a variable named
            // 'identifier'.
            '#parents'      => array('identifier'),
          ),
          'title' => array(
            '#type'   => 'item',
            '#markup' => $video->title,
          ),
          'thumbnail' => array(
            '#type'   => 'item',
            '#markup' => theme('image', $image_variables),
          ),
          'id' => array(
            '#type'   => 'item',
            '#markup' => $video->id,
          ),
          'date' => array(
            '#type'   => 'item',
            '#markup' => format_date($video->created_time, 'medium'),
          ),
        );
      }
      $form['results']['import'] = array(
        '#type' => 'submit',
        '#value' => t('Import'),
        '#submit' => array('scald_dailymotion_search_form_submit'),
      );
    }
    else {
      // No need to show a table.
      unset($form['results']['#theme']);

      // No results message.
      $form['results']['empty'] = array(
        '#type' => 'item',
        '#markup' => t('No results'),
      );
    }
  }

  return $form;
}

/**
 * Handles search terms form submission.
 */
function scald_dailymotion_search_form_search_submit($form, &$form_state) {
  if ($form_state['clicked_button']['#value'] == t('Search')) {
    $form_state['rebuild'] = TRUE;
    $form_state['storage']['terms'] = $form_state['values']['search']['search_term'];
  }
}

/**
 * Handlers import form submission.
 */
function scald_dailymotion_search_form_submit($form, &$form_state) {
  $identifier = $form_state['values']['identifier'];
  if (!$identifier) {
    drupal_set_message(t('No video selected for import'));
    // Present again the list of result.
    $form_state['rebuild'] = TRUE;
    return;
  }

  // End the multistep search workflow.
  unset($form_state['storage']);
  $form_state['rebuild'] = FALSE;

  // Redirect user to the import form (special page).
  $form_state['redirect'] = array(
    'atoms/dailymotion/import',
    array(
      'query' => array(
        'dm-id' => $identifier,
      ),
    ),
  );
}

/**
 * Themes the results table.
 */
function theme_scald_dailymotion_search_results_table($variables) {
  $form = $variables['form'];
  $header = array(t('Import'), t('Title'), t('Thumbnail'), t('ID'), t('Date'));
  $rows = array();
  foreach (element_children($form['videos']) as $key) {
    $rows[] = array(
      'data' => array(
        drupal_render($form['videos'][$key]['import']),
        drupal_render($form['videos'][$key]['title']),
        drupal_render($form['videos'][$key]['thumbnail']),
        drupal_render($form['videos'][$key]['id']),
        drupal_render($form['videos'][$key]['date']),
      ),
    );
  }
  $output = theme('table', array(
    'header' => $header,
    'rows' => $rows,
    'attributes' => array('id' => 'scald-dailymotion-videos'),
  ));
  $output .= drupal_render_children($form);
  return $output;
}
