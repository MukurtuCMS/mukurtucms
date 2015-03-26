<?php
/**
 * @file
 * Implements views_plugin_style for zip_export_media
 */

/**
 * Implements views_plugin_style
 */
class zip_export_media_plugin_style extends views_plugin_style {
  /**
   * Implementation of view_style_plugin::render()
   */
  function render() {
    $files = array();
    $view = $this->view;
    // For simplicity, we just take anything that looks like a node, with
    // any fields that look like media fields.
    // TODO: Add plugin options to allow detection/selection of specific fields.
    foreach ($view->result as $node) {
      if (isset($node->nid)) {
        foreach ((array)$node as $field_name => $field) {
          if(!empty($field)) {
            foreach ($field as $item) {
              if (isset($item['raw']['file']) && is_object($item['raw']['file']) && isset($item['raw']['file']->fid)) {
                $files[$node->nid][$field_name][] = $item['raw']['file'];
              }
            }
          }
        }
      }
    }
    if ($this->view->live_preview) {
      // Returning an actual zip during the live preview breaks views AJAX.
      return '<pre>' . print_r($files, TRUE) . '</pre>';
    }
    else {
      return zip_export_media_create_zip($files, $view->name . '-' . format_date(mktime(), 'custom', 'Y-m-d-H-i') . '.zip');
    }
  }
}
