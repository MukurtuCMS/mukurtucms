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
            '#description' => t('Configure warnings for media pertaining to a person who is no longer alive.'),
        );

        $form['mukurtu_content_warning_people']['enabled'] = array(
            '#type' => 'checkbox',
            '#title' => t('Enable People Warnings'),
            '#default_value' => isset($person_defaults['enabled']) ? $person_defaults['enabled'] : FALSE,
            '#description' => t('This is a site-wide setting.'),
        );

        $form['mukurtu_content_warning_people']['warning'] = array(
            '#title' => t('Warning Text'),
            '#type' => 'textfield',
            '#description' => t('The text that will be displayed on the media overlay. Use the replacement token "[name]" to insert the person\'s name in the message.'),
            '#default_value' => isset($person_defaults['warning']) ? $person_defaults['warning'] : t('Warning: [name] is no longer alive. Click through to access media.'),
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
    if(empty($form_state['input']['mukurtu_content_warning_taxonomy']) && !$form_state['submitted']) {
        foreach($taxonomy_defaults as $index => $taxonomy_warning) {
            $form_state['input']['mukurtu_content_warning_taxonomy'][$index] = array('term' => $taxonomy_warning['term'],
                                                                                     'warning' => $taxonomy_warning['warning']);
        }
    }

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
        $form['mukurtu_content_warning_taxonomy'][$i]['warning'] = array(
            '#title' => t('Warning Text'),
            '#type' => 'textfield',
            '#description' => t('The text that will be displayed on the media overlay.'),
            '#default_value' => isset($taxonomy_defaults[$i]['warning']) ? $taxonomy_defaults[$i]['warning'] : $form_state['input']['mukurtu_content_warning_taxonomy']['warning'],
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



function mukurtu_content_warnings_form_add_taxonomy_warning($form, &$form_state) {
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
        ->propertyOrderBy('name', 'ASC');

    $options = array('-1' => t('Select a term'));
    $result = $query->execute();
    if(isset($result['taxonomy_term'])) {
        foreach($result['taxonomy_term'] as $term_ref) {
            $term = taxonomy_term_load($term_ref->tid);
            if($term) {
                $options[$term->tid] = $term->name . " ({$vocabs[$term->vid]->name})";
            }
        }
    }

    return $options;
}