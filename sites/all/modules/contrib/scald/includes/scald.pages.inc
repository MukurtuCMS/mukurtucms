<?php
/**
 * @file
 * This file contains the various callbacks related to Scald defined pages.
 *
 * A lot of callbacks related to the creation and  edition of the atoms
 * entities are defined here.
 */

/**
 * Creates the page listing possible Scald Atom Types.
 */
function scald_atom_add() {
  $types = scald_types();
  if (empty($types)) {
    return '<p>' . t('You have not installed any Scald providers yet. Go to the <a href="@admin-modules">modules administration page</a> to install a Scald provider.', array('@admin-modules' => url('admin/modules', array('fragment' => 'edit-modules-scald')))) . '</p>';
  }

  $content = array();

  foreach ($types as $name => $type) {
    // Skip atom type the user isn't allowed to create.
    if (!scald_action_permitted(new ScaldAtom($name), 'create')) {
      continue;
    }
    $content[] = array(
      'title' => scald_type_property_translate($type),
      'href'  => 'atom/add/' . $name,
      'localized_options' => array(),
      'description' => '',
      'page_arguments' => serialize(array($name)),
    );
  }
  return theme('node_add_list', array('content' => $content));
}

/**
 * Atom add page callback.
 */
function scald_atom_add_page($js, $type, $step = NULL, $atom_id = NULL) {
  if ($js) {
    ctools_include('modal');
    ctools_include('ajax');
  }

  ctools_include('object-cache');
  ctools_include('wizard');

  // If we are not currently edit an atom and there is a temporary saved atom,
  // reopen it.
  $cache = ctools_object_cache_get('scald_atom', 'edit:-1');
  if (!$atom_id && $cache && $cache['atoms'][0]->type === $type->type) {
    $atom_id = -1;
    $step = 'options';
  }

  $cache_id = isset($atom_id) ? 'edit:' . $atom_id : 'add';

  // Start by getting the list of all the modules that said they can provide
  // this atom type.
  $providers = scald_atom_providers_opt();
  $sources = $providers[$type->type];
  $source = key($sources);
  $provider = current($sources);

  // If there's more than one, provide a choice between them. Otherwise, skip
  // a step and select the only provider upfront.
  if (empty($step)) {
    if (count($sources) < 2) {
      if (!empty($provider['starting_step'])) {
        $step = $provider['starting_step'];
      }
      else {
        $step = 'add';
      }
    }
    else {
      $step = 'source';
    }
    ctools_object_cache_clear('scald_atom', $cache_id);
  }

  $form_state = array(
    'ajax' => $js,
    'scald' => ctools_object_cache_get('scald_atom', $cache_id),
  );

  // Entity Translation workaround when the fix https://drupal.org/node/2027513
  // is not corporated in a stable release.
  if (isset($form_state['scald']['atoms'][0])) {
    $form_state['atom'] = $form_state['scald']['atoms'][0];
  }

  if (empty($form_state['scald'])) {
    $form_state['scald'] = array(
      'type' => $type,
      'source' => isset($source) ? $source : NULL,
      'provider' => $provider,
    );
  }

  $form_state['scald']['step'] = $step;

  $form_info = array(
    'id' => 'scald-atom-add',
    'path' => 'atom/add/' . $type->type . '/' . ($js ? 'ajax' : 'nojs') . '/%step',
    'show trail' => TRUE,
    'show back' => FALSE,
    'show cancel' => TRUE,
    'show return' => FALSE,
    'next callback' => 'scald_atom_add_wizard_next',
    'finish callback' => 'scald_atom_add_wizard_finish',
    'cancel callback' => 'scald_atom_add_wizard_cancel',
    'order' => array(
      'source' => t('Source'),
      'add' => t('Add'),
      'options' => t('Options'),
    ),
    'forms' => array(
      'source' => array(
        'form id' => 'scald_atom_add_form_source',
      ),
      'add' => array(
        'form id' => 'scald_atom_add_form_add',
      ),
      'options' => array(
        'form id' => 'scald_atom_add_form_options',
      ),
    ),
  );

  // Send this all off to our form. This is like drupal_get_form only wizardy.
  $form = ctools_wizard_multistep_form($form_info, $step, $form_state);
  $output = drupal_render($form);

  // If $output is FALSE, there was no actual form.
  if ($js) {
    // If javascript is active, we have to use a render array.
    $commands = array();
    if ($output === FALSE || !empty($form_state['complete'])) {
      // Dismiss the modal.
      $commands[] = array('command' => 'dnd_refresh');
      $commands[] = ctools_modal_command_dismiss();
    }
    elseif (!empty($form_state['cancel'])) {
      // If cancelling, return to the activity.
      $commands[] = ctools_modal_command_dismiss();
    }
    else {
      $commands = ctools_modal_form_render($form_state, $output);
    }
    print ajax_render($commands);
    exit;
  }
  else {
    if ($output === FALSE || !empty($form_state['complete'])) {
      $atom = $form_state['scald']['atoms'][0];
      drupal_goto('atom/' . $atom->sid);
    }
    elseif (!empty($form_state['cancel'])) {
      drupal_goto('atom/add');
    }
    else {
      return $output;
    }
  }
}

/**
 * Source form.
 */
function scald_atom_add_form_source($form, &$form_state) {
  $providers = scald_atom_providers();
  $sources = $providers[$form_state['scald']['type']->type];

  // Localize the source names. Note that all the strings
  // have been marked for extraction in their corresponding
  // modules, so this call is safe.
  $sources = array_map('t', $sources);

  $form_state['title'] = t('Source');
  $form['source'] = array(
    '#title' => t('Source'),
    '#type' => 'select',
    '#options' => $sources,
    '#description' => t('Please choose the source of your new atom'),
  );

  return $form;
}

/**
 * Handles the source step form submission.
 */
function scald_atom_add_form_source_submit(&$form, &$form_state) {
  $source = $form_state['scald']['source'] = $form_state['values']['source'];
  $type = $form_state['scald']['type']->type;
  $providers = scald_atom_providers_opt();
  $provider = $providers[$type][$source];
  $form_state['scald']['provider'] = $provider;
  if (isset($form_state['scald']['provider']['starting_step']) && $form_state['scald']['provider']['starting_step'] == 'options') {
    $form_state['clicked_button']['#next'] = 'options';
  }
}

/**
 * Add form.
 */
function scald_atom_add_form_add($form, &$form_state) {
  $scald = $form_state['scald'];
  $function = $scald['source'] . '_scald_add_form';
  if (function_exists($function)) {
    $function($form, $form_state);
  }
  else {
    // TODO: Figure out what should be done here.
    $form['error'] = array(
      '#markup' => 'Import without form; does it makes sense ?',
    );
  }

  return $form;
}

/**
 * Handles the add step form submission.
 */
function scald_atom_add_form_add_submit(&$form, &$form_state) {
  $scald = $form_state['scald'];

  $count = 1;
  $atom_count_implemented = FALSE;
  // Allow the source provider to define how many atoms to create
  // and handle differences between upload modules.
  $function = $scald['source'] . '_scald_add_atom_count';
  if (function_exists($function)) {
    $count = $function($form, $form_state);
    $atom_count_implemented = TRUE;
  }

  for ($delta = 0; $delta < $count; $delta++) {
    $atoms[$delta] = new ScaldAtom($scald['type']->type, $scald['source']);
  }

  // Allow the source provider to alter it, filling in defaults value.
  $function = $scald['source'] . '_scald_add_form_fill';
  if (function_exists($function)) {
    if ($atom_count_implemented) {
      $function($atoms, $form, $form_state);
    }
    else {
      $function($atoms[0], $form, $form_state);
    }

    $context = array(
      'form' => $form,
      'form_state' => $form_state,
    );
    drupal_alter('scald_add_form_fill', $atoms, $context);
  }

  // And put it in the form_state.
  $form_state['scald']['atoms'] = $atoms;
}

/**
 * Options form.
 */
function scald_atom_add_form_options($form, &$form_state) {
  if (empty($form_state['scald']['atoms'])) {
    scald_atom_add_form_add_submit($form, $form_state);
  }
  $atoms = $form_state['scald']['atoms'];

  $actions = scald_actions();

  $form['#entity_type'] = 'scald_atom';

  foreach ($atoms as $delta => $atom) {
    $form['atom' . $delta] = array(
      '#prefix' => '<div class="atom-wrapper">',
      '#suffix' => '</div>',
      '#parents' => array('atom' . $delta),
    );
    if (count($atoms) > 1) {
      $title = 'atom' . $delta .' : '. $atom->title;
      $form['atom' . $delta] += array(
        '#title' => $title,
        '#type' => 'fieldset',
        '#collapsible' => TRUE,
        '#collapsed' => FALSE,
      );
    }
    $form['atom' . $delta]['title'] = array(
      '#type' => 'textfield',
      '#title' => t('Title'),
      '#required' => TRUE,
      '#default_value' => $atom->title,
      '#parents' => array('atom' . $delta, 'title'),
      '#maxlength' => 255,
      '#weight' => -10,
    );
    $form['language'] = array(
      '#type' => 'value',
      '#value' => $atom->language,
    );
    field_attach_form('scald_atom', $atom, $form['atom' . $delta], $form_state, entity_language('scald_atom', $atom));
    $instances = field_info_instances('scald_atom', $atom->type);
    foreach ($instances as $instance) {
      $field_name = $instance['field_name'];
      $form['atom' . $delta][$field_name]['#parents'] = array('atom' . $delta, $field_name);
    }
    $options = array();
    $options_default = array();
    foreach ($actions as $name => $action) {
      $options[$name] = $action['title'];
      $options_default[$name] = $atom->actions & $action['bitmask'] ? $name : '';
    }
    $form['atom' . $delta]['scald_actions'] = array(
      '#type' => 'checkboxes',
      '#title' => t('Openly available actions'),
      '#group' => 'additional_settings',
      '#options' => $options,
      '#default_value' => $options_default,
      '#parents' => array('atom' . $delta, 'scald_actions'),
      '#access' => user_access('restrict atom access'),
    );
  }

  $form['actions']['submit']['#value'] = t('Save');

  return $form;
}

/**
 * Handles the final atom creation step form submission.
 */
function scald_atom_add_form_options_submit(&$form, &$form_state) {
  if (!$atoms = $form_state['scald']['atoms']) {
    return;
  }

  $atom_keys = array();
  foreach(array_keys($atoms) as $delta) {
    $atom_keys[] = 'atom' . $delta;
  }
  $values_excluding_atoms = array_diff_key($form_state['values'], array_flip($atom_keys));

  foreach ($atoms as $delta => $atom) {
    $index = 'atom' . $delta;
    $values = &$form_state['values'][$index];

    if (is_array($values['scald_actions'])) {
      $bitstream = 0;
      $actions = scald_actions();
      foreach ($actions as $name => $action) {
        if (!empty($values['scald_actions'][$name])) {
          $bitstream |= $action['bitmask'];
        }
      }
      $values['actions'] = $bitstream;
    }

    $op = empty($atom->sid) ? t('created') : t('updated');

    // Prepare a form state that is suitable for modules that provide extra fields.
    $atom_form_state = array('values' => $values + $values_excluding_atoms) + $form_state;
    // Add back the structure required for fields and maintain a reference to
    // the original form state values.
    $atom_form_state['values'][$index] = &$values;

    // Let entity add its properties to the atom.
    entity_form_submit_build_entity('scald_atom', $atom, $form[$index], $atom_form_state);

    // Then save it...
    scald_atom_save($atom);
  }

  // Add a message confirming the creation.
  $type = scald_type_property_translate(scald_type_load($atoms[0]->type));
  if (count($atoms) == 1) {
    drupal_set_message(t('Atom %title, of type %type has been @op.', array(
      '%title' => $atoms[0]->title,
      '%type' => $type,
      '@op' => $op,
    )));
  }
  else {
    drupal_set_message(t('%count atoms of type %type have been @op.', array(
      '%count' => count($atoms),
      '%type' => $type,
      '@op' => $op,
    )));
  }
}

/**
 * Handle the 'next' click on the add/edit pane form wizard.
 */
function scald_atom_add_wizard_next(&$form_state) {
  $cache_id = isset($form_state['scald']['atoms'][0]->sid) ? 'edit:' . $form_state['scald']['atoms'][0]->sid : 'add';
  ctools_object_cache_set('scald_atom', $cache_id, $form_state['scald']);
}

/**
 * Handle the 'finish' click on the add/edit pane form wizard.
 */
function scald_atom_add_wizard_finish(&$form_state) {
  $form_state['complete'] = TRUE;
}

/**
 * Handle the 'cancel' click on the add/edit pane form wizard.
 */
function scald_atom_add_wizard_cancel(&$form_state) {
  $form_state['cancel'] = TRUE;
}

/**
 * Page callback for the view of an atom.
 */
function scald_atom_page_view($atom) {
  return scald_render($atom, 'full');
}

/**
 * Atom edit page callback.
 */
function scald_atom_edit_page($js, $atom) {
  // The edit page is nothing else other than the add page, at the Options step.
  // We prepare data for this step then send back to the add page. The only
  // useful information at this step is the atom itself.
  $scald = array(
    'atoms' => array($atom),
  );
  $types = scald_types();
  ctools_include('object-cache');
  ctools_object_cache_set('scald_atom', 'edit:' . $atom->sid, $scald);
  return scald_atom_add_page($js, $types[$atom->type], 'options', $atom->sid);
}

/**
 * Handles the deletion of an existing atom.
 */
function scald_atom_delete_confirm($form, &$form_state, $atom) {
  // Always provide entity id in the same form key as in the entity edit form.
  $form['sid'] = array('#type' => 'value', '#value' => $atom->sid);
  return confirm_form($form,
    t('Are you sure you want to delete %title?', array('%title' => $atom->title)),
    'admin/content/atoms',
    t('<p>Note that unchecking the Fetch checkbox in the "<em>Openly available actions</em>" field of this atom <a href="!url">edit form</a> makes the atom disappear for everyone but Scald administrators, and is usually a better idea.</p><p>This action cannot be undone.</p>', array('!url' => url("atom/{$atom->sid}/edit"))),
    t('Delete'),
    t('Cancel')
  );
}

/**
 * Handles the deletion of an existing atom in ctools modal.
 */
function scald_atom_delete_confirm_ajax($js, $atom) {
  $form = drupal_get_form('scald_atom_delete_confirm', $atom);
  if ($js) {
    ctools_include('modal');
    ctools_include('ajax');
    $form_state = array();
    $form['actions']['cancel']['#attributes']['class'][] = 'ctools-close-modal';
    $commands = ctools_modal_form_render($form_state, $form);
    print ajax_render($commands);
    exit;
  }
  else {
    return $form;
  }
}

/**
 * Execute atom deletion.
 */
function scald_atom_delete_confirm_submit($form, &$form_state) {
  if ($form_state['values']['confirm']) {
    $atom = scald_atom_load($form_state['values']['sid']);
    scald_atom_delete($atom->sid);
    watchdog('scald_atom', '@type: deleted %title.', array('@type' => $atom->type, '%title' => $atom->title));
    $types = scald_types();
    $type = scald_type_property_translate($types[$atom->type]);
    drupal_set_message(t('@type %title has been deleted.', array('@type' => $type, '%title' => $atom->title)));
  }
  if (!empty($form_state['input']['js'])) {
    ctools_include('modal');
    ctools_include('ajax');
    $commands = array();
    $commands[] = array('command' => 'dnd_refresh');
    $commands[] = ctools_modal_command_dismiss();
    print ajax_render($commands);
    exit();
  }
  else {
    $form_state['redirect'] = 'admin/content/atoms';
  }
}
/**
 * Fetch atoms and return in JSON format.
 *
 * @param string $sids
 *   Comma separated list of atom ids.
 *
 * Other parameters, such as context, could also be passed via the querystring.
 */
function scald_atom_fetch_atoms($sids) {
  $output = array();
  $atoms = scald_atom_load_multiple(explode(',', $sids));

  // Context can be passed via the querystring.
  $context = isset($_GET['context']) && array_key_exists($_GET['context'], scald_contexts_public()) ? $_GET['context'] : '';

  foreach ($atoms as $sid => $atom) {
    $output[$sid] = array(
      'sid' => $sid,
      'contexts' => $context ? array($context => scald_render($atom, $context)) : array(),
      'meta' => array(
        'title' => $atom->title,
        'type' => $atom->type,
        'data' => !empty($atom->data) ? $atom->data : array(),
      ),
      'actions' => array_keys(scald_atom_actions_available($atom)),
    );
  }
  drupal_json_output($output);
}
