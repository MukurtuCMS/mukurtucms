<?php

/**
 * @file
 * The primary PHP file for this theme.
 */
function mukurtu_preprocess_html(&$variables) {
    $color_scheme = theme_get_setting('mukurtu_theme_color_scheme');
    $css = join(DIRECTORY_SEPARATOR, array(path_to_theme(), 'css', "style-{$color_scheme}.css"));
    if (file_exists($css)) {
        drupal_add_css($css, array('group' => CSS_THEME, 'every_page' => TRUE));
    }
}

function mukurtu_preprocess_page(&$vars, $hook = null){
    if (isset($vars['node'])) {
        switch ($vars['node']->type) {
        case 'collection':
            $js = join(DIRECTORY_SEPARATOR, array(drupal_get_path('theme', 'mukurtu'), 'js', 'collection-grid.js'));
            drupal_add_js($js);
            break;
        case 'digital_heritage':
            // Add slick carousel
            $slick = libraries_get_path('slick');
            $css = join(DIRECTORY_SEPARATOR, array($slick, 'slick.css'));
            drupal_add_css($css);
            $css = join(DIRECTORY_SEPARATOR, array($slick, 'slick-theme.css'));
            drupal_add_css($css);
            $js = join(DIRECTORY_SEPARATOR, array($slick, 'slick.min.js'));
            drupal_add_js($js);
            $js = join(DIRECTORY_SEPARATOR, array(drupal_get_path('theme', 'mukurtu'), 'js', 'mukurtu-slick-carousel.js'));
            drupal_add_js($js);

            // Add custom DH template suggestion so we can render any multipage nav before the CR quicktabs
            $vars['theme_hook_suggestions'][] = 'page__node__digital_heritage';
        }
    }
}

function mukurtu_preprocess_panels_pane(&$variables) {
    // Add custom theme suggestions for the dictionary browse page search facets
    if($variables['display']->storage_id == 'page_dictionary_browse__dictionary-browse-theme-v2') {
        if($variables['pane']->panel == 'search_facets' && $variables['pane']->subtype != 'views--exp-dictionary_words-all') {
            $variables['theme_hook_suggestions'][] = 'panels_pane__block__dictionary_browse';
        }
    }
}

function mukurtu_preprocess_field(&$variables, $hook) {
    $element = $variables['element'];

    // Add anchors for Person type full view
    if(!empty($element['#object']->type) && $element['#object']->type == 'person' && $element['#view_mode'] == 'full') {

        // Related People
        if($element['#field_name'] == 'field_related_people') {
            $variables['items'][key($variables['items'])]['#prefix'] = '<a name="related-people"></a>';
        }

        // Sections
        $section_number = 1;
        if($element['#field_name'] == 'field_sections') {
            foreach($element['#items'] as $index => $section) {
                foreach($variables['items'][$index]['entity']['paragraphs_item'] as $p_index => $paragraph) {
                    $variables['items'][$index]['entity']['paragraphs_item'][$p_index]['#prefix'] = '<a name="section-' . $section_number++ . '"></a>';
                }
            }
        }
    }
}

/*function mukurtu_process_qt_quicktabs_tabset(&$vars) {
    kpr($vars);
    }*/