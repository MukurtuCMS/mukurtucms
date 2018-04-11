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