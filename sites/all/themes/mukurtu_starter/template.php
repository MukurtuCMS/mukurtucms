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
            $parent_record = NULL;
            if(!empty($variables['element']['#object']->field_community_record_children[LANGUAGE_NONE])) {
                $parent_record = $variables['element']['#object'];
            }

            // If this is a community record, load the parent and run through all records
            if(!empty($variables['element']['#object']->field_community_record_parent[LANGUAGE_NONE])) {
                $parent_record = node_load($variables['element']['#object']->field_community_record_parent[LANGUAGE_NONE][0]['target_id']);
            }

            if($parent_record) {
                // Only count those we have access to
                $cr_count = 1;
                foreach($parent_record->field_community_record_children[LANGUAGE_NONE] as $cr) {
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

            // Child book page label
            if(!empty($variables['element']['#object']->field_book_parent[LANGUAGE_NONE])) {
                $parent = node_load($variables['element']['#object']->field_book_parent[LANGUAGE_NONE][0]['target_id']);
                if($parent) {
                    $page = 1;
                    $total_pages = count($parent->field_book_children[LANGUAGE_NONE]) + 1;
                    foreach($parent->field_book_children[LANGUAGE_NONE] as $child_page) {
                        $page++;
                        if($child_page['target_id'] == $variables['element']['#object']->nid) {
                            break;
                        }
                    }
                    $pages = array('@page' => $page, '@pages' => $total_pages);
                    $page_label = '<span class="label label-default page-label">'. t("Page @page of @pages", $pages).'</span>';
                    $variables['items'][0]['#markup'] = $variables['items'][0]['#markup'] . $page_label;
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