<?php

/**
 * @file
 * The primary PHP file for this theme.
 */
function mukurtu_preprocess_html(&$variables) {
  $color_scheme = theme_get_setting('mukurtu_theme_color_scheme');

  // This option was added for users who wanted to sub-theme with completely recompiled less
  // files.
  if ($color_scheme == 'none') {
    return;
  }

  // Add the css for the particular color scheme.
  $css = join('/', array(path_to_theme(), 'css', "style-{$color_scheme}.css"));
  if (file_exists($css)) {
    drupal_add_css($css, array('group' => CSS_THEME, 'every_page' => TRUE));
  }
}

/**
 * Helper function to include slick carousel css & files
 */
function _mukurtu_include_slick_carousel() {
    $slick = libraries_get_path('slick');
    $css = join('/', array($slick, 'slick.css'));
    drupal_add_css($css);
    $css = join('/', array($slick, 'slick-theme.css'));
    drupal_add_css($css);
    $js = join('/', array($slick, 'slick.min.js'));
    drupal_add_js($js);
    $js = join('/', array(drupal_get_path('theme', 'mukurtu'), 'js', 'mukurtu-slick-carousel.js'));
    drupal_add_js($js);
}

function mukurtu_preprocess_page(&$vars, $hook = null){
    if (isset($vars['node'])) {
        switch ($vars['node']->type) {
        case 'collection':
        case 'personal_collection':
            $js = join('/', array(drupal_get_path('theme', 'mukurtu'), 'js', 'collection-grid.js'));
            drupal_add_js($js);
            break;
        case 'digital_heritage':
        case 'person':
            _mukurtu_include_slick_carousel();

            // Add custom DH template suggestion so we can render any multipage nav before the CR quicktabs
            $vars['theme_hook_suggestions'][] = 'page__node__digital_heritage';
        }
    }

    // Taxonomy terms w/Mukurtu Records
    if(isset($vars['page']['content']['system_main']['term_heading']['term']['field_mukurtu_records'])) {
        _mukurtu_include_slick_carousel();
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

function mukurtu_block_view_alter(&$data, $block) {
    // Rather than mess with block display, we configure all pre-packaged frontpage
    // blocks to display and hide the ones not selected in the theme settings.
    $frontpage_hero_setting = theme_get_setting('mukurtu_theme_frontpage_layout');

    if(isset($block->bid)) {
        switch($block->bid) {
            case 'bean-frontpage-hero-image-one-column':
                if($frontpage_hero_setting != 'large-hero') {
                    unset($data['content']);
                }
                break;
            case 'bean-frontpage-hero-image-two-columns':
                if($frontpage_hero_setting != 'side-by-side') {
                    unset($data['content']);
                }
                break;
            default:
        }
    }
}

/**
* Implements hook_node_view_alter().
*/
function mukurtu_node_view_alter(&$build) {
  // For nodes, only show author if user has edit rights.
  if ($build['#entity_type'] == 'node') {
    if (isset($build['author']) && (!user_is_logged_in() || !node_access('update', $build['#node']))) {
      $build['author']['#access'] = FALSE;
    }
  }
}
