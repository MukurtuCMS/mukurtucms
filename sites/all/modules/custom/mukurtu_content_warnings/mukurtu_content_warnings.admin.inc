<?php

function mukurtu_content_warnings_form($form, &$form_state, $no_js = FALSE) {
    $form['#tree'] = TRUE;

    // Scald contexts configured for warnings
    $scald_contexts_defaults = variable_get('mukurtu_content_warning_scald_contexts');
    $form['mukurtu_content_warning_scald_contexts'] = array(
        '#type' => 'fieldset',
        '#title' => t('Enable Warnings Per Scald Context'),
        '#collapsible' => FALSE,
        '#description' => t('Select the Scald contexts that should be enabled to support warnings. Unchecked contexts will not display warnings configured below.'),
    );

    $all_contexts = scald_contexts();
    foreach($all_contexts as $context) {
        // Skip hidden contexts, can't display warnings for something hidden
        if(isset($context['hidden']) && $context['hidden']) {
            continue;
        }

        // Skip contexts with no machine name (built-ins)
        if(empty($context['name'])) {
            continue;
        }

        // Build checkbox for the context
        $form['mukurtu_content_warning_scald_contexts'][$context['name']] = array(
            '#type' => 'checkbox',
            '#title' => $context['title'],
            '#default_value' => isset($scald_contexts_defaults[$context['name']]) ? $scald_contexts_defaults[$context['name']] : TRUE,
        );
    }

    // Deceased person warning
    if(module_exists('ma_person')) {
        // Get the saved settings
        $person_defaults = variable_get('mukurtu_content_warning_people');

        $form['mukurtu_content_warning_people'] = array(
            '#type' => 'fieldset',
            '#title' => t('People Warnings'),
            '#collapsible' => FALSE,
            '#description' => t('Configure warnings for media pertaining to a person who is deceased.'),
        );

        $form['mukurtu_content_warning_people']['enabled'] = array(
            '#type' => 'checkbox',
            '#title' => t('Enable People Warnings'),
            '#default_value' => isset($person_defaults['enabled']) ? $person_defaults['enabled'] : FALSE,
            '#description' => t('This is a site-wide setting.'),
        );

        $form['mukurtu_content_warning_people']['warning_single'] = array(
            '#title' => t('Warning Text: Single Person'),
            '#type' => 'textfield',
            '#description' => t('The text that will be displayed on the media overlay for a single deceased person. Use the replacement token "[name]" to insert the person\'s name in the message.'),
            '#default_value' => isset($person_defaults['warning_single']) ? $person_defaults['warning_single'] : t('Warning: [name] is deceased. Click through to access content.'),
        );

        $form['mukurtu_content_warning_people']['warning_multiple'] = array(
            '#title' => t('Warning Text: Multiple People'),
            '#type' => 'textfield',
            '#description' => t('The text that will be displayed on the media overlay for multiple deceased people. Use the replacement token "[names]" to insert the names in the message.'),
            '#default_value' => isset($person_defaults['warning_multiple']) ? $person_defaults['warning_multiple'] : t('Warning: The following people are deceased. Click through to access content. [names]'),
        );
    }

    // Taxonomy warning fieldset
    $form['mukurtu_content_warning_taxonomy'] = array(
        '#type' => 'fieldset',
        '#title' => t('Taxonomy Triggered Warnings'),
        '#collapsible' => FALSE,
        '#prefix' => '<div id="taxonomy-warnings-fieldset-wrapper">',
        '#suffix' => '</div>',
        '#description' => t('Configure warnings for scald atoms tagged with a specific taxonomy term.') . ' '. t('This is a site-wide setting'),
    );

    // Display each taxonomy warning config
    $term_options = mukurtu_content_warnings_term_list();
    $taxonomy_defaults = variable_get('mukurtu_content_warning_taxonomy');
    if(!empty($taxonomy_defaults) && empty($form_state['input']['mukurtu_content_warning_taxonomy']) && !$form_state['submitted']) {
        foreach($taxonomy_defaults as $index => $taxonomy_warning) {
            $form_state['input']['mukurtu_content_warning_taxonomy'][$index] = array('term' => $taxonomy_warning['term'],
                                                                                     'warning' => $taxonomy_warning['warning']);
        }
    }

    if(!empty($form_state['input']['mukurtu_content_warning_taxonomy'])) {
        foreach($form_state['input']['mukurtu_content_warning_taxonomy'] as $i => $values) {
            $form['mukurtu_content_warning_taxonomy'][$i] = array(
                '#type' => 'fieldset',
                '#collapsible' => FALSE,
            );

            // Taxonomy Term
            $form['mukurtu_content_warning_taxonomy'][$i]['term'] = array(
                '#type' => 'select',
                '#title' => t('Term'),
                '#options' => $term_options,
                '#default_value' => isset($taxonomy_defaults[$i]['term']) ? $taxonomy_defaults[$i]['term'] : -1,
                '#description' => t('Select the term attached to the scald atom that will trigger the warning.'),
            );

            // Warning for that taxonomy term
            $default_warning = $values['warning'];

            if(!empty($form_state['input']['mukurtu_content_warning_taxonomy']['warning'])) {
                $default_warning = $form_state['input']['mukurtu_content_warning_taxonomy']['warning'];
            }
            if(!empty($taxonomy_defaults[$i]['warning'])) {
                $default_warning = $taxonomy_defaults[$i]['warning'];
            }
            $form['mukurtu_content_warning_taxonomy'][$i]['warning'] = array(
                '#title' => t('Warning Text'),
                '#type' => 'textfield',
                '#description' => t('The text that will be displayed on the media overlay.'),
                '#default_value' => $default_warning,
            );

            // Remove warning button
            $form['mukurtu_content_warning_taxonomy'][$i]['remove'] = array(
                '#type' => 'submit',
                '#value' => t('Remove'),
                '#submit' => array('mukurtu_content_warnings_form_remove_taxonomy_warning'),
                '#name' => 'taxonomy_warning_remove_' . $i,
                '#ajax' => array(
                    'callback' => 'mukurtu_content_warnings_form_taxonomy_callback',
                    'wrapper' => 'taxonomy-warnings-fieldset-wrapper',
                ),
            );
        }
    }

    // Add taxonomy warning button
    $form['mukurtu_content_warning_taxonomy']['add_another'] = array(
        '#type' => 'submit',
        '#value' => t('Add taxonomy warning'),
        '#submit' => array('mukurtu_content_warnings_form_add_taxonomy_warning'),
        '#ajax' => array(
            'callback' => 'mukurtu_content_warnings_form_taxonomy_callback',
            'wrapper' => 'taxonomy-warnings-fieldset-wrapper',
        ),
    );
    //    return $form;
    return system_settings_form($form);
}

function mukurtu_content_warnings_form_validate($form, &$form_state) {
    // Check that terms were selected, not left on default
    if(!empty($form_state['input']['mukurtu_content_warning_taxonomy'])) {
        foreach($form_state['input']['mukurtu_content_warning_taxonomy'] as $i => $values) {
            if($values['term'] == -1) {
                form_set_error("mukurtu_content_warning_taxonomy][{$i}][term", t('You must select a term'));
            }
        }
    }
}

function mukurtu_content_warnings_form_add_taxonomy_warning($form, &$form_state) {
    if(!isset($form_state['taxonomy_warning_count'])) {
        $form_state['taxonomy_warning_count'] = 0;
    }
    $form_state['taxonomy_warning_count'] += 1;
    $form_state['input']['mukurtu_content_warning_taxonomy'][] = array('term' => 0,
                                               'warning' => t('Warning: This media may contain sensitive content.'));
    $form_state['rebuild'] = TRUE;
}

function mukurtu_content_warnings_form_remove_taxonomy_warning($form, &$form_state) {
    $id = $form_state['triggering_element']['#parents'][1];
    if(isset($form_state['input']['mukurtu_content_warning_taxonomy'][$id])) {
        unset($form_state['input']['mukurtu_content_warning_taxonomy'][$id]);
    }

    $form_state['rebuild'] = TRUE;
}

function mukurtu_content_warnings_form_taxonomy_callback($form, $form_state) {
    return $form['mukurtu_content_warning_taxonomy'];
}

// Build the options list for taxonomy terms for the admin config form
function mukurtu_content_warnings_term_list() {
    $vocabs = taxonomy_get_vocabularies();

    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'taxonomy_term')
        ->propertyOrderBy('vid', 'ASC')
        ->propertyOrderBy('name', 'ASC');

    $result = $query->execute();
    if(isset($result['taxonomy_term'])) {
        foreach($result['taxonomy_term'] as $term_ref) {
            $term = taxonomy_term_load($term_ref->tid);
            if($term) {
                $options[$term->tid] = "{$vocabs[$term->vid]->name}: " . $term->name;
            }
        }
    }

    // Sort by vocab name
    asort($options, SORT_STRING);

    // Add the default "blank" option
    $options = array('-1' => t('Select a term')) + $options;

    return $options;
}