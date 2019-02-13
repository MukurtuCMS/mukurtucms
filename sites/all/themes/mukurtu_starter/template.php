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

/**
 * Implements theme_file_link.
 * Make files open in a separate window/tab when clicked. This applies to the generic file formatter as well as table of files formatter,
 * which is used for the Collab section documents files. This formatter is also
 * used by the some scald image fields, which shouldn't matter much. This theme function is also called
 * from a couple other places, none of which should matter much. What we really want this for is the generic file formatter
 * on the collab documents as they appear in the Document library, and if we could target just that, we would.
 */
function mukurtu_starter_file_link($variables) {
  $file = $variables['file'];
  $icon_directory = $variables['icon_directory'];

  $url = file_create_url($file->uri);

  // Human-readable names, for use as text-alternatives to icons.
  $mime_name = array(
    'application/msword' => t('Microsoft Office document icon'),
    'application/vnd.ms-excel' => t('Office spreadsheet icon'),
    'application/vnd.ms-powerpoint' => t('Office presentation icon'),
    'application/pdf' => t('PDF icon'),
    'video/quicktime' => t('Movie icon'),
    'audio/mpeg' => t('Audio icon'),
    'audio/wav' => t('Audio icon'),
    'image/jpeg' => t('Image icon'),
    'image/png' => t('Image icon'),
    'image/gif' => t('Image icon'),
    'application/zip' => t('Package icon'),
    'text/html' => t('HTML icon'),
    'text/plain' => t('Plain text icon'),
    'application/octet-stream' => t('Binary Data'),
  );

  $mimetype = file_get_mimetype($file->uri);

  $icon = theme('file_icon', array(
    'file' => $file,
    'icon_directory' => $icon_directory,
    'alt' => !empty($mime_name[$mimetype]) ? $mime_name[$mimetype] : t('File'),
  ));

  // Set options as per anchor format described at
  // http://microformats.org/wiki/file-format-examples
  $options = array(
    'attributes' => array(
      'type' => $file->filemime . '; length=' . $file->filesize,
      'target' => '_blank', // MUKURTU -- THIS IS THE ONLY CUSTOMIZATION
    ),
  );

  // Use the description as the link text if available.
  if (empty($file->description)) {
    $link_text = $file->filename;
  }
  else {
    $link_text = $file->description;
    $options['attributes']['title'] = check_plain($file->filename);
  }

  return '<span class="file">' . $icon . ' ' . l($link_text, $url, $options) . '</span>';
}

function mukurtu_starter_preprocess_panels_pane(&$variables)
{
    // Add custom theme suggestions for the dictionary browse page search facets
    if ($variables['display']->storage_id == 'page_dictionary_browse__dictionary-browse-theme-v2') {
        if ($variables['pane']->panel == 'search_facets' && $variables['pane']->subtype != 'views--exp-dictionary_words-all') {
            $variables['theme_hook_suggestions'][] = 'panels_pane__block__dictionary_browse';
        }
    }
}
