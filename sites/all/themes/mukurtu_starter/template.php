<?php

/**
 * @file
 * template.php
 */
function mukurtu_starter_preprocess_field(&$variables, $hook) {
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

    // Page & Community Record count labels on digital heritage search results
    if(!empty($element['#object']->type) && $element['#object']->type == 'digital_heritage' && $element['#view_mode'] == 'search_result') {
        if($element['#field_name'] == 'title') {
            // Community Record Count Label
            if(!empty($variables['element']['#object']->field_community_record_children[LANGUAGE_NONE])) {
                // Only count those we have access to
                $cr_count = 1;
                foreach($variables['element']['#object']->field_community_record_children[LANGUAGE_NONE] as $cr) {
                    $node = node_load($cr['target_id']);
                    if($node && node_access('view', $node)) {
                        $cr_count++;
                    }
                }

                // Create community record label
                if($cr_count > 1) {
                    $cr_label = '<span class="label label-default community-record-label">'. t("@count Records", array('@count' => $cr_count)).'</span>';
                    $variables['items'][0]['#markup'] = $variables['items'][0]['#markup'] . $cr_label;
                }
            }

            // Book Page Count Label
            if(!empty($variables['element']['#object']->field_book_children[LANGUAGE_NONE])) {
                $count = count($variables['element']['#object']->field_book_children[LANGUAGE_NONE]);
                if($count) {
                    $cr_label = '<span class="label label-default page-label">'. t("@count Pages", array('@count' => $count + 1)).'</span>';
                    $variables['items'][0]['#markup'] = $variables['items'][0]['#markup'] . $cr_label;
                }
            }
        }
    }
}

/**
* Implements hook_node_view_alter().
*/
function mukurtu_starter_node_view_alter(&$build) {
    // For DH items, only show author if user has edit rights
    if($build['#entity_type'] == 'node' && $build['#bundle'] == 'digital_heritage' && $build['#view_mode'] == 'full') {
        if(!user_is_logged_in() || !node_access('update', $build['#node'])) {
            $build['author']['#access'] = FALSE;
        }
    }
}