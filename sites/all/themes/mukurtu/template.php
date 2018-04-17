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
