<?php

/**
 * @file
 * Scald Admin
 *
 * The Scald Core Admin Interface
 *
 * @ingroup scald
 */

require_once 'scald.constants.inc';

/**
 * The Scald Admin Dashboard.
 *
 * @return string
 *   The Dashboard rendered in XHTML.
 */
function scald_admin_dashboard() {
  $types = scald_types();
  $content = '';

  $message = '<p>' . t('This is the Scald administration dashboard. It allows to manage <em>Atom Types</em> (entity bundles) and <em>Representation Contexts</em> (entity view modes). In each context, it is possible to choose which <em>transcoder</em> (for Image atoms, it is image style) is used and how atom is rendered using different <em>players</em>. The context settings is for the atom itself, while "manage display" is to controlled how are fields displayed. If you are strange to the terminology, please read the short <a href="@readme">README.txt</a> or the long <a href="@doc">documentation pages</a>.', array('@readme' => 'http://drupalcode.org/project/scald.git/blob/refs/heads/7.x-1.x:/README.txt', '@doc' => 'https://drupal.org/node/1652740')) . '</p>';
  drupal_set_message($message);

  $content .= '<h3>' . t('Scald Unified Atom Types') . '</h3>';
  $content .= '<p>' . t('List of Scald Unified Atom Types. Each type is an entity bundle and has different fields, displays and contexts. Multiple providers (e.g. local image provider, Flickr provider) can provide atoms of the same type and share the same transcoders, players.') . '</p>';

  $list = array('type' => 'ul', 'items' => array());
  $table = array(
    'header' => array(
      t('Name'),
      array(
        'data' => t('Actions'),
        'colspan' => module_exists('i18n_string') ? 5 : 4,
      ),
    ),
    'rows' => array(),
  );

  foreach ($types as $type) {
    $rows = array(
      check_plain(scald_type_property_translate($type)),
      l(t('edit'), 'admin/structure/scald/' . $type->type),
      l(t('manage fields'), 'admin/structure/scald/' . $type->type . '/fields'),
      l(t('manage display'), 'admin/structure/scald/' . $type->type . '/display'),
      l(t('contexts'), 'admin/structure/scald/' . $type->type . '/contexts'),
    );
    // Add a 'translate' action if Internationalization is enabled.
    if (module_exists('i18n_string')) {
      $rows[] = l(t('translate'), 'admin/structure/scald/' . $type->type . '/translate');
    }
    $table['rows'][] = $rows;
  }

  $content .= theme('table', $table);

  // Tell the user, he can switch to a new export with Features.
  if (!variable_get('scald_switch_feature_export', FALSE) && module_exists('features')) {
    $content .= '<h3>' . t('Scald Context Features Export') . '</h3>';
    $switch_form = drupal_get_form('scald_switch_to_feature_form');
    $content .= drupal_render($switch_form);
  }

  // Display a context listing.
  $content .= '<h3>' . t('Scald Contexts') . '</h3>';
  $content .= '<p>' . t('List of all Scald Contexts, those created through the UI and even those hidden or defined by other modules.') . '</p>';
  $content .= '<ul class="action-links"><li>' . l(t('Add context'), 'admin/structure/scald/context/add') . '</li></ul>';

  $list = array('type' => 'ul', 'items' => array());
  $table = array(
    'header' => array(
      t('Context name'),
      t('Atom type'),
      t('Module'),
      t('Property'),
      t('Actions'),
    ),
    'rows' => array(),
  );

  $custom_contexts = variable_get('scald_custom_contexts', array());
  foreach (scald_contexts() as $name => $context) {
    $actions = array();

    // This is a context created through the UI, it could be edit or delete.
    if (array_key_exists($name, $custom_contexts)) {
      $actions[] = l(t('Edit'), 'admin/structure/scald/context/edit/' . $name);
      $actions[] = l(t('Delete'), 'admin/structure/scald/context/delete/' . $name);
    }

    $table['rows'][] = array(
      check_plain($context['title']) . '<div class="description">' . filter_xss_admin($context['description']) . '</div>',
      empty($context['formats']) ? '<em>' . t('not specified') . '</em>' : check_plain(implode(', ', array_keys($context['formats']))),
      $context['provider'],
      empty($context['hidden']) ? '' : t('hidden'),
      implode(' ', $actions),
    );
  }

  $content .= theme('table', $table);

  return $content;
}

/**
 * Form for admin settings for Scald Types.
 */
function scald_admin_type_form($form, $form_state, $type) {
  $form = array();
  $type_name = $type->type;
  $type_raw = (array) $type;
  $form['type_' . $type_name . '_title'] = array(
    '#type'           => 'textfield',
    '#title'          => t('Title'),
    '#default_value'  => $type_raw['title'],
    '#size'           => 40,
    '#maxlength'      => 255,
    '#required'       => TRUE,
  );

  $default = scald_atom_defaults($type_name);

  $form['defaults'] = array(
    '#type'         => 'fieldset',
    '#title'        => t('Defaults'),
    '#description'  => t('Every Atom must have certain data associated with it.  If an Atom Provider fails to supply that data, these defaults are used.  If nothing is specified here, Scald Core will supply generic defaults.'),
    '#collapsible'  => FALSE,
  );
  $form['defaults']['type_' . $type_name . '_thumb'] = array(
    '#type'           => 'textfield',
    '#title'          => t('Default Thumbnail Image'),
    '#description'    => t('Specify a path relative to the Drupal install directory.  This image file will be automatically resized and transcoded as appropriate when generating the actual thumbnail image.'),
    '#default_value'  => $default->thumbnail_source,
    '#size'           => 40,
    '#maxlength'      => 255,
    '#required'       => TRUE,
  );
  $form['defaults']['type_' . $type_name . '_descr'] = array(
    '#type'           => 'textfield',
    '#title'          => t('Default Description'),
    '#description'    => t('Empty strings are permitted.'),
    '#default_value'  => $default->description,
    '#size'           => 40,
    '#maxlength'      => 255,
  );
  $options = array(
    'managed_file' => t('Managed file'),
  );
  if (module_exists('plupload')) {
    $options['plupload'] = t('Plupload');
  }
  $form['defaults']['type_' . $type_name . '_utype'] = array(
    '#type'           => 'select',
    '#title'          => t('Upload type'),
    '#default_value'  => $default->upload_type,
    '#options' => $options
  );
  // Create checkboxes for the defined actions.
  $actions = scald_actions();
  $options = array();
  $options_default = array();
  foreach ($actions as $name => $action) {
    $options[$name] = $action['title'];
    $options_default[$name] = $default->actions & $action['bitmask'] ? $name : '';
  }
  $form['defaults']['type_' . $type_name . '_actin'] = array(
    '#type'           => 'checkboxes',
    '#title'          => t('Default Actions'),
    '#description'    => t('Please select the actions that should be enabled by default for atom of this type. Note that the actions you choose here are the one that you want to be made available on this atom to everyone ; the actions that the atom author can perform can be configured per role using standard Drupal rights.'),
    '#options'        => $options,
    '#default_value'  => $options_default,
    '#required'       => TRUE,
  );

  $form['atom_type'] = array(
    '#type' => 'value',
    '#value' => $type_name,
  );

  $form['submit'] = array(
    '#type'   => 'submit',
    '#value'  => t('Save'),
  );

  return $form;
}

/**
 * Submit function for admin settings for Scald Types.
 *
 * Updated values are written directly back to the database and then the Scald
 * Configuration Object is rebuilt from the db.
 */
function scald_admin_type_form_submit($form, &$form_state) {
  $scald_atom_defaults = variable_get('scald_atom_defaults', array());
  $type = $form_state['values']['atom_type'];

  if (empty($scald_atom_defaults[$type])) {
    $scald_atom_defaults[$type] = new stdClass();
  }

  foreach ($form_state['values'] as $key => $value) {
    if (drupal_substr($key, 0, 5) == 'type_') {
      $setting = substr($key, strlen(_scald_parse_machine_name($key)) + 1);
      switch ($setting) {
        case 'title':
          db_update('scald_types')
            ->fields(array('title' => $value))
            ->condition('type', $type)
            ->execute();
          break;

        case 'thumb':
          $scald_atom_defaults[$type]->thumbnail_source = $value;
          break;

        case 'descr':
          $scald_atom_defaults[$type]->description = $value;
          break;

        case 'utype':
          $scald_atom_defaults[$type]->upload_type = $value;
          break;

        case 'actin':
          $actions = scald_actions();
          $bitmask = 0;
          foreach ($actions as $name => $action) {
            if (!empty($value[$name])) {
              $bitmask |= $action['bitmask'];
            }
          }
          $scald_atom_defaults[$type]->actions = $bitmask;
          break;
      }
    }
  }

  drupal_set_message(t('Atom settings changed'));
  variable_set('scald_atom_defaults', $scald_atom_defaults);
  scald_types(TRUE);
}

/**
 * Form constructor for the context editing form.
 *
 * @param string $context_name
 *   (optional) Context name, when editing an existing Scald context.
 */
function scald_admin_context_form($form, &$form_state, $context_name = NULL) {
  if ($context_name) {
    // Edit an existing Scald context.
    $custom_contexts = variable_get('scald_custom_contexts', array());
    if (!array_key_exists($context_name, $custom_contexts)) {
      drupal_set_message(t('Custom context not found: %context', array('%context' => $context_name)), 'error');
      drupal_goto('admin/structure/scald');
    }
    else {
      $context = $custom_contexts[$context_name];
    }
  }
  else {
    // Default setting for the new context.
    $context = array(
      'name' => '',
      'title' => '',
      'description' => '',
      'render_language' => 'XHTML',
      'parseable' => TRUE,
      'formats' => array(),
    );
  }

  // Make the context array available to implementations of hook_form_alter.
  $form['#context'] = $context;

  $form['title'] = array(
    '#title' => t('Title'),
    '#type' => 'textfield',
    '#default_value' => $context['title'],
    '#description' => t('The title of this context. This text will be displayed as part of the list on the <em>Scald Dashboard</em> and on the <em>Atom type Contexts</em> pages. It is recommended that this name begin with a capital letter and contain only letters, numbers, and spaces..'),
    '#required' => TRUE,
    '#size' => 30,
  );

  $form['name'] = array(
    '#type' => 'machine_name',
    '#default_value' => $context['name'],
    '#maxlength' => 32,
    '#machine_name' => array(
      'source' => array('title'),
      'exists' => 'scald_context_load',
    ),
    '#disabled' => $context['name'] ? TRUE : FALSE,
    '#description' => t('A unique machine-readable name for this context. It must only contain lowercase letters, numbers, and underscores.'),
  );

  $form['description'] = array(
    '#title' => t('Description'),
    '#type' => 'textarea',
    '#default_value' => $context['description'],
    '#description' => t('Describe this context. The text will be displayed on the <em>Scald Dashboard</em> page.'),
  );

  $form['additional_settings'] = array(
    '#type' => 'vertical_tabs',
    // @todo provide a JavaScript to do Vertical Tabs summary stuffs.
    '#attached' => array(),
  );

  $form['system'] = array(
    '#type' => 'fieldset',
    '#title' => t('System settings'),
    '#collapsible' => TRUE,
    '#group' => 'additional_settings',
  );
  $form['system']['parseable'] = array(
    '#type' => 'checkbox',
    '#title' => t('Make parseable'),
    '#default_value'  => (bool) $context['parseable'],
  );

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => $context['name'] ? t('Save context') : t('Add context'),
    '#weight' => 40,
  );

  if ($context['name']) {
    $form['actions']['delete'] = array(
      '#markup' => l(t('Delete context'), 'admin/structure/scald/context/delete/' . $context['name']),
      '#weight' => 45,
    );
  }

  return $form;
}

/**
 * Form validation handler for scald_admin_context_form().
 */
function scald_admin_context_form_validate($form, &$form_state) {
  // There is still nothing to do here.
}

/**
 * Form submission handler for scald_admin_context_form().
 */
function scald_admin_context_form_submit($form, &$form_state) {
  $op = isset($form_state['values']['op']) ? $form_state['values']['op'] : '';

  if (!$context = scald_context_load($form_state['values']['name'])) {
    $context  = array();
  }

  $context = array(
    'name' => $form_state['values']['name'],
    'title' => $form_state['values']['title'],
    'description' => $form_state['values']['description'],
    'render_language' => 'XHTML',
    'parseable' => (bool) $form_state['values']['parseable'],
    'formats' => array(),
  ) + $context;

  scald_context_save($context);
  cache_clear_all('*', 'cache_scald', TRUE);
  cache_clear_all('field_info_types', 'cache_field', TRUE);
  field_info_cache_clear();

  $form_state['redirect'] = 'admin/structure/scald';
}

/**
 * Context delete confirm form.
 */
function scald_admin_context_confirm_delete_form($form, &$form_state, $context_name) {
  // Delete a Scald custom context.
  $custom_contexts = variable_get('scald_custom_contexts', array());
  if (!array_key_exists($context_name, $custom_contexts)) {
    drupal_set_message(t('Custom context not found: %context', array('%context' => $context_name)), 'error');
    drupal_goto('admin/structure/scald');
  }

  $form['#context'] = $custom_contexts[$context_name];

  return confirm_form(
    $form,
    t('Are you sure you want to delete the Scald context %context?', array('%context' => $form['#context']['name'])),
    'admin/structure/scald',
    t('Any settings for this context will also be deleted. This action cannot be undone.')
  );
}

/**
 * Process scald_admin_context_confirm_delete_form form submission.
 */
function scald_admin_context_confirm_delete_form_submit($form, &$form_state) {
  $context = $form['#context'];
  $custom_contexts = variable_get('scald_custom_contexts', array());
  unset($custom_contexts[$context['name']]);
  variable_set('scald_custom_contexts', $custom_contexts);

  $config = scald_context_config_load($context['name']);
  scald_context_config_delete($config);

  $form_state['redirect'] = 'admin/structure/scald';
}

/**
 * The Scald Admin page for Scald Atoms.
 */
function scald_admin_atoms() {
  $count = db_query("SELECT COUNT(*) FROM {scald_atoms}")->fetchField();
  $content = '<h3>' . t('Scald Atoms') . '</h3>';
  $content .= '<ul class="action-links"><li>' . l(t('Add atom'), 'atom/add') . '</li></ul>';
  $content .= '<h4>' . format_plural($count, 'Currently, there is 1 atom registered with Scald Core.', 'Currently, there are @count atoms registered with Scald Core.') . '</h4>';
  $content .= '<p>' . t('Enable the Views module to get an handy paginated table with filters which will allow you to browse your atoms.') . '</p>';

  return $content;
}

/**
 * The Scald Admin page for Scald Contexts.
 */
function scald_admin_contexts($type) {
  $content = '<h3>' . t('Scald Rendering Contexts') . '</h3>';
  $content .= '<p>' . t('Scald Rendering Contexts are something like view modes for Scald atoms. Any atom can be rendered in any supported context and the context determines what that rendering looks like, which player it uses, and what language (XHTML etc.) it is in.') . '</p>';
  $content .= '<p>' . t('If a context is <em>parseable</em>, that means that its output is wrapped in HTML comments (currently this feature only works reliably for contexts which have a render language of XHTML) which make it possible for Scald to uniquely identify the atom based on the rendering. For instance, if a WYSIWYG editor is being used in some text areas and Scald atoms should be included in the WYSIWYG preview of the text, a context can be chosen and specified as parseable. That ensures that when the textarea is submitted, Scald will be able to determine which atoms are present in the textarea, convert the rendered versions to Scald Atom Shorthand (SAS).') . '</p>';

  $output[] = array('#markup' => $content);
  $output[] = drupal_get_form('scald_admin_contexts_form', $type);

  return $output;
}

/**
 * Form for admin settings for Scald Contexts.
 */
function scald_admin_contexts_form($form, $form_state, $type) {
  $form = array();

  $contexts = scald_contexts();
  $transcoders = scald_transcoders();
  $players = scald_players();
  $transcoder_options = array();
  $player_options = array();
  foreach ($transcoders as $tname => $transcoder) {
    $transcoder_options[$tname] = $transcoder['title'];
  }
  foreach ($players as $player_name => $player) {
    if (array_intersect($player['type'], array('*', $type->type))) {
      $player_options[$player_name] = $player['name'];
    }
  }

  foreach ($contexts as $name => $context) {
    // Only list visible contexts.
    if (!empty($context['hidden'])) {
      continue;
    }

    $default = !empty($contexts[$name]['type_format'][$type->type]['transcoder']) ? $contexts[$name]['type_format'][$type->type]['transcoder'] : NULL;
    $form[$name] = array(
      '#type'         => 'fieldset',
      '#title'        => check_plain($context['title']),
      '#description'  => check_plain($context['description']) . '<br />' . t('Provided by <code>@module.module</code>.', array('@module' => $context['provider'])),
      '#collapsible'  => TRUE,
      '#collapsed'    => TRUE,
    );
    $form[$name][$name . '_parse'] = array(
      '#type'           => 'checkbox',
      '#title'          => t('Make parseable.'),
      '#default_value'  => (bool) $context['parseable'],
      '#disabled'       => TRUE,
    );

    $form[$name][$name . '_trans'] = array(
      '#type'            => 'select',
      '#title'           => t('Transcoder'),
      '#options'         => $transcoder_options,
      '#default_value'   => $default,
    );

    $form[$name][$name . '_playe'] = array(
      '#type'            => 'select',
      '#title'           => t('Player'),
      '#options'         => $player_options,
      '#default_value'   => isset($context['player'][$type->type]) ? $context['player'][$type->type]['*'] : 'default',
      '#ajax'            => array(
        'callback' => 'scald_admin_contexts_player_ajax',
        'wrapper' => $name . '-player-settings',
      ),
    );

    $current_player = isset($form_state['values'][$name . '_playe']) ? $form_state['values'][$name . '_playe'] : $form[$name][$name . '_playe']['#default_value'];
    $form[$name][$name . '_player_settings'] = array(
      '#markup' => empty($players[$current_player]['settings']) ? '' : t('Configure the player <a href="@url">settings</a>.', array('@url' => url('admin/structure/scald/' . $type->type . '/player/' . $name . '/' . $current_player))),
      '#prefix' => '<div id="' . $name . '-player-settings">',
      '#suffix' => '</div>',
    );

    $context_config = scald_context_config_load($name);
    $form[$name][$name . '_dimensions'] = array(
      '#type'         => 'fieldset',
      '#title'        => t('Dimensions'),
      '#description'  => t('Context width and height are used to hint the Scald rendering process to fit into the specified dimensions. While transcoder is about what to be displayed, the dimensions are about how large an atom is displayed. The unit could be omitted: "200px", "80%" or simply "150" etc.'),
    );
    $form[$name][$name . '_dimensions'][$name . '_width'] = array(
      '#type' => 'textfield',
      '#title' => t('Width'),
      '#size' => 20,
      '#default_value' => isset($context_config->data['width']) ? $context_config->data['width'] : '',
    );
    $form[$name][$name . '_dimensions'][$name . '_height'] = array(
      '#type' => 'textfield',
      '#title' => t('Height'),
      '#size' => 20,
      '#default_value' => isset($context_config->data['height']) ? $context_config->data['height'] : '',
    );
  }

  $form['submit'] = array(
    '#type'   => 'submit',
    '#value'  => t('Save'),
  );

  return $form;
}

/**
 * Re-generates the player settings form.
 */
function scald_admin_contexts_player_ajax($form, $form_state) {
  $context_name = _scald_parse_machine_name($form_state['triggering_element']['#name']);
  return $form[$context_name][$context_name . '_player_settings'];
}

/**
 * Submit handler for Scald Contexts admin settings form.
 *
 * Updated values are written directly back to the database and then the Scald
 * Configuration Object is rebuilt from the db.
 */
function scald_admin_contexts_form_submit($form, &$form_state) {
  drupal_set_message(t('Context transcoders settings saved'));
  $typename = $form_state['build_info']['args'][0]->type;
  $players = scald_players();
  $contexts = scald_contexts();

  foreach ($form_state['values'] as $key => $value) {
    $context = _scald_parse_machine_name($key);
    $setting = substr($key, strlen($context) + 1);
    if (!isset($contexts[$context])) {
      continue;
    }
    switch ($setting) {
      // Handle transcoders submission.
      case 'trans':
        $transcoder = $value;
        $context_config = scald_context_config_load($context);
        $context_config->transcoder[$typename]['*'] = $transcoder;
        scald_context_config_save($context_config);
        break;

      // Handler players submission.
      case 'playe':
        $context_config = scald_context_config_load($context);
        $context_config->player[$typename]['*'] = $value;
        // Load and save default settings for the player.
        if (empty($context_config->player[$typename]['settings']) && isset($players[$value]['settings'])) {
          $context_config->player[$typename]['settings'] = $players[$value]['settings'];
        }
        scald_context_config_save($context_config);
        break;

      case 'width':
        $context_config = scald_context_config_load($context);
        $context_config->data['width'] = $form_state['values'][$context . '_width'];
        $context_config->data['height'] = $form_state['values'][$context . '_height'];
        scald_context_config_save($context_config);
        break;
    }
  }

  // The transcoders associated to the contexts might have change. In this case,
  // all the output that we keep in the cache is invalid, which means that we'll
  // need to regenerate it.
  cache_clear_all('*', 'cache_scald', TRUE);
}

/**
 * Generates Scald admin settings form.
 */
function scald_settings_form() {
  $form = array();
  $form['intro'] = array(
    '#value' => t("
      <h3>Scald Settings</h3>
      <p>Below you'll find some general Scald settings. Beware that some of
      them are very useful for debugging, but may completely kill performance.
      Use with caution.</p>
    "),
  );
  $form['scald_always_rebuild'] = array(
    '#type' => 'checkbox',
    '#default_value' => variable_get('scald_always_rebuild', FALSE),
    '#title' => t('Always rebuild rendered content'),
    '#description' => t("By default, Scald tries to agressively cache the atom's rendered content, by context and by actions available to the user viewing it. Checking this box, Scald will re-render the atom each time. This is a massive performance hit."),
  );

  // Scald tags vocabulary configuration.
  $options = array();
  $vocabularies = taxonomy_get_vocabularies();
  foreach ($vocabularies as $vocabulary) {
    $options[$vocabulary->machine_name] = $vocabulary->name;
  }
  $form['scald_tags_vocabulary'] = array(
    '#type' => 'select',
    '#title' => t('Vocabulary used for tags storing'),
    '#description' => t('By default, Scald uses its own vocabulary to store atoms tags, you can override it here.'),
    '#options' => $options,
    '#default_value' => variable_get('scald_tags_vocabulary', 0),
  );

  // Add our custom submit handler.
  $form['#submit'][] = 'scald_settings_form_submit';

  return system_settings_form($form);
}

/**
 * Returns the machine name from element name.
 *
 * Element name is built on {machine name}_{setting name} where 'machine name'
 * is either type, context machine name or anything else. Historically, the
 * 'setting name' is limited to exactly 5 characters for easy parsing.
 */
function _scald_parse_machine_name($element_name) {
  $position = strrpos($element_name, '_');
  return substr($element_name, 0, $position);
}

/**
 * Handles the admin settings form submission.
 */
function scald_settings_form_submit($form, &$form_state) {
  // Fetch info on the scald_tags taxonomy reference field and changed
  // the allowed vocabulary.
  $field = field_info_field('scald_tags');
  $field['settings']['allowed_values'][0]['vocabulary'] = $form_state['values']['scald_tags_vocabulary'];
  field_update_field($field);
}

/**
 * Player settings form.
 */
function scald_player_settings_form($form, $form_state, $type, $context, $player) {
  $contexts = scald_contexts();
  $players = scald_players();

  // If either the context or the player is missing (for example
  // because the module providing it was disabled), return an
  // empty form.
  if (!isset($contexts[$context]) || !isset($players[$player])) {
    return array();
  }

  // If the current player is not the same as the configure player, display a
  // notice message.
  if (($current_player = $contexts[$context]['player'][$type->type]['*']) != $player) {
    drupal_set_message(t('You are configuring the player %player, which is not the current player %current_player.', array('%player' => $player, '%current_player' => $current_player)), 'warning');
  }

  $settings_form = array();
  $function = $players[$player]['provider'] . '_scald_player_settings_form';
  if (function_exists($function)) {
    // Handle the default settings.
    $player_settings = isset($contexts[$context]['player'][$type->type]['settings']) ? $contexts[$context]['player'][$type->type]['settings'] : array();
    if (isset($players[$player]['settings'])) {
      $player_settings += $players[$player]['settings'];
    }

    $form['#scald'] = array(
      'type' => $type,
      'context' => $context,
      'player' => $player,
      'player_settings' => $player_settings,
    );

    $settings_form = $function($form, $form_state);
  }

  if ($settings_form) {
    $form['settings'] = array(
      '#type' => 'container',
      'settings' => $settings_form,
      'actions' => array(
        '#type' => 'action',
        'save_settings' => array(
          '#type' => 'submit',
          '#value' => t('Update'),
          '#op' => 'update',
        ),
      ),
    );
  }

  return $form;
}


/**
 * Player settings form submission.
 */
function scald_player_settings_form_submit($form, &$form_state) {
  $op = $form_state['triggering_element']['#op'];
  if ($op == 'update') {
    $scald = $form['#scald'];
    $config = scald_context_config_load($scald['context']);

    foreach ($scald['player_settings'] as $key => $value) {
      $config->player[$scald['type']->type]['settings'][$key] = $form_state['values'][$key];
    }
    scald_context_config_save($config);
    cache_clear_all('*', 'cache_scald', TRUE);

    drupal_set_message(t('Your player settings has been updated.'));
  }
}

/**
 * Switch to feature form.
 */
function scald_switch_to_feature_form() {
  $form = array();

  $form['text'] = array(
    '#markup' => '<p>' . t('You can now export your contexts with Features. This will break existing exports and you will have to review your existing features containing scald contexts.') . '</p>',
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Switch to Features Export')
  );

  return $form;
}


/**
 * Switch to feature form submission.
 */
function scald_switch_to_feature_form_submit($form, &$form_state) {
  variable_set('scald_switch_feature_export', TRUE);
  cache_clear_all();

  $message = '<p>' . t('You are now using the new Features export. Please make sure you have checked and recreated the features involved. Cache clear is necessary.') . '</p>';
  drupal_set_message($message, 'warning');

  $form_state['redirect'] = 'admin/structure/scald';
}
