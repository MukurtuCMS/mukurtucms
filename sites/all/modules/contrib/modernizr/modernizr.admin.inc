<?php

/**
 * Form callback for 'admin/config/user-interface/modernizr'.
 */
function modernizr_admin_form() {
  $f = array();
  
  $serverside = variable_get('modernizr_serverside');
  
  $f['modernizr_serverside'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable server side support'),
    '#description' => $serverside > 1 ?
      t('Serverside can\'t be disabled, ' .
        'because one or more module requires it to be turned on.'):
      t('Note, that by enabling this option, a big cookie will be made, ' .
        'which can cause problems on certain browsers.'),
    '#disabled' => $serverside > 1,
    '#default_value' => $serverside,
  );
  
  return system_settings_form($f);
}
