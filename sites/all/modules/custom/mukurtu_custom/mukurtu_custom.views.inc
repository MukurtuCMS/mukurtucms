<?php
function mukurtu_custom_views_pre_view (&$view) {

  if ($view->name == "export" && $view->current_display == 'views_data_export') {
    global $_GET;
    
    foreach($_GET as $key => $val) {
      if($key != 'q') {
        unset($view->display_handler->display->display_options['fields'][$val]);
      }
    }
  }
}