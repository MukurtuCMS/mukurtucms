<?php

/**
 * @file
 * template.php
 */
function mukurtu_starter_preprocess_field(&$variables, $hook) {
    $element = $variables['element'];

    // Add anchors for Person type full view
    if($element['#object']->type == 'person' && $element['#view_mode'] == 'full') {

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

        // Content found in
        if($element['#field_name'] == 'field_node_aggregate') {
            if(!empty($variables['items'][0]['node'])) {
                $variables['items'][0]['node'][key($variables['items'][0]['node'])]['#prefix'] = '<a name="found-in"></a>';
            }
        }
        
        //        dpm($variables);
    }
}