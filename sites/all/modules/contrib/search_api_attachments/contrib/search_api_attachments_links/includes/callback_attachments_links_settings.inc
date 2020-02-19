<?php

/**
 * @file
 * Search API data alteration callback.
 */

class SearchApiAttachmentsLinksAlterSettings extends SearchApiAttachmentsAlterSettings {

  /**
   * {@inheritdoc}
   */
  public function alterItems(array &$items) {
    $link_fields = $this->getLinkFields();

    foreach ($items as $id => &$item) {
      $item_wrapper = entity_metadata_wrapper($this->index->item_type, $item);

      foreach ($link_fields as $name => $link_field) {
        if (isset($item->$name)) {
          $links = $item_wrapper->$name->value();
          // Manage case of single value fields by reproducing the structure of
          // multiple values fields.
          if (isset($links['url'])) {
            $links = array($links);
          } else if ($links == NULL) {
            $links = [];
          }
          // Limit to the max number of value per field.
          if (isset($this->options['number_indexed']) && $this->options['number_indexed'] != '0' && count($links) > $this->options['number_indexed']) {
            $links = array_slice($links, 0, $this->options['number_indexed']);
          }
          foreach ($links as $link) {
            if (isset($link['url'])) {
              // Get the files.
              if ($this->isFileIndexable($link, $item, $name)) {
                $attachments = 'attachments_links_' . $name;
                if (isset($item->{$attachments})) {
                  $item->{$attachments} .= ' ' . $this->getLinkContent($link);
                }
                else {
                  $item->{$attachments} = $this->getLinkContent($link);
                }
              }
            }
          }
        }
      }
    }
  }

  /**
   * {@inheritdoc}
   */
  public function propertyInfo() {
    $ret = array();
    $fields = $this->getLinkFields();
    foreach ($fields as $name => $field) {
      $ret['attachments_links_' . $name] = array(
        'label' => 'Attachment linked content: ' . $name,
        'description' => $name,
        'type' => 'text',
      );
    }
    return $ret;
  }

  public function isFileIndexable($link, $item, $field_name = NULL) {
    // Extension restriction.
    $exclude = explode(' ', $this->options['excluded_extensions']);

    // File size restriction.
    if (isset($this->options['max_file_size'])) {
      $max_file_size = parse_size($this->options['max_file_size']);
    }
    else {
      $max_file_size = '0';
    }
    // Extension restriction.
    if (!in_array(pathinfo($link['url'], PATHINFO_EXTENSION), $exclude)) {
      // File size restriction.
      if ($max_file_size > $this->getUrlSize($link['url'])) {
        // Allow customization of indexability rules.
        foreach (module_implements('search_api_attachments_indexable') as $module) {
          if (module_invoke($module, 'search_api_attachments_indexable', $link, $item, $field_name) === FALSE) {
            return FALSE;
          }
        }
        return TRUE;
      }
    }
    return FALSE;
  }

  protected function getUrlSize($url) {
    $headers = get_headers($url, 1);
    if (isset($headers['Content-Length'])) {
      return $headers['Content-Length'];
    } else {
      return false;
    }
  }

  /**
   * {@inheritdoc}
   */
  protected function getLinkFields() {
    $ret = array();
    foreach (field_info_fields() as $name => $field) {
      if ($field['type'] == 'link_field') {
        $ret[$name] = $field;
      }
    }
    return $ret;
  }

  public function getLinkContent($link) {
    $extraction = FALSE;

    // Before running the (performance-intensive) extraction process, check
    // if we already have a cached copy of the extracted data.
    if (isset($link['url'])) {
      // Load cached extraction based off link ID.
      $cid = 'cached_extraction_:' . $link['url'];
      $cached_extraction = cache_get($cid, self::CACHE_TABLE);

      // If we have a cache hit, there really is no need to continue.
      if (!empty($cached_extraction->data)) {
        return $cached_extraction->data;
      }
    }

    if ($headers = get_headers($link['url'], 1)) {
      if ($headers['Content-Type'] == 'text/plain' || $headers['Content-Type'] == 'text/x-diff') {
        $extraction = $this->extract_simple($link);
      }
      elseif (in_array($headers['Content-Type'], array('image/jpeg', 'image/jpg', 'image/tiff'))) {
        $extraction = $this->extract_exif($link);
      }
      else {
        $extraction_method = variable_get('search_api_attachments_extract_using', 'tika');
        // Send the extraction request to the right place depending on the
        // current setting.
        if ($extraction_method == 'tika') {
          $extraction = $this->extract_tika($link);
        }
        elseif ($extraction_method == 'python_pdf2txt') {
          if (in_array($headers['Content-Type'], $this->pdf_mimetypes())) {
            $extraction = $this->extract_python_pdf2txt($link);
          }
          elseif (variable_get('search_api_attachments_debug', FALSE)) {
            watchdog('search_api_attachments', 'The python_pdf2txt extraction method does not support %mime_type', array('%mime_type' => $headers['Content-Type']), WATCHDOG_WARNING);
          }
        }
        elseif ($extraction_method == 'pdftotext') {
          if (in_array($headers['Content-Type'], $this->pdf_mimetypes())) {
            $extraction = $this->extract_pdftotext($link);
          }
          elseif (variable_get('search_api_attachments_debug', FALSE)) {
            watchdog('search_api_attachments', 'The pdftotext extraction method does not support %mime_type', array('%mime_type' => $headers['Content-Type']), WATCHDOG_WARNING);
          }
        }
        else {
          $extraction = $this->extract_solr($link);
        }
      }
    }
    else {
      // Log the missing link information.
      watchdog('search_api_attachments', "Couldn't index %filename content because this link was missing.", array('%filename' => $link['url']));
    }

    // If we have actual extracted data, write it to the cache.
    if ($extraction !== FALSE && isset($cid)) {
      cache_set($cid, $extraction, self::CACHE_TABLE);
    }
    if (variable_get('search_api_attachments_debug', FALSE)) {
      watchdog('search_api_attachments', "File: @filename\nExtraction: @extraction", array('@filename' => $link['url'], '@extraction' => $extraction), WATCHDOG_DEBUG);
    }
    return $extraction;
  }

  protected function get_realpath($link) {
    return $link['url'];
  }
}
