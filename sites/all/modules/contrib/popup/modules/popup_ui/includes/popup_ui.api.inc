<?php



/**
 * Renders a link that pops up a yes/no confirmation dialog.
 *
 * This method can be used to provide in page confirmation popups.
 *
 * @param string $title 
 * The title of the link that is displayed to the user, eg. 'Delete'
 *
 * @param string $message
 * Message to be displayed to the user when the link is clicked
 *
 * @param array $attributes
 * Popup attributes to be used for the popup. See popup($attributes) doc in popup.api.inc
 * for more details.
 * In addition to the normal attributes the following are processed:
 * 'confirm label' => Label to be displayed as the confirmation link.
 * 'cancel label' => Label to be displayed as the cancellation link. This link just closes the 
 * popup. See the popup formats config page for a demo.
 *
 */ 
function popup_ui_confirm($title, $message, $confirm_path, $attributes = array()){

  module_load_include('inc', 'popup', 'includes/popup.api');
  drupal_add_css(drupal_get_path('module', 'popup_ui').'/style/popup-confirm.css');
  
  $confirm_title = isset($attributes['confirm label'])
    ? $attributes['confirm label']
    : t('Yes');
  $cancel_title = isset($attributes['cancel label'])
    ? $attributes['cancel label']
    : t('No');

  $body = 
    '<div class="popup-message">'.$message.'</div>'.
    '<div class="popup-buttons">'.
      l(
        '<span>' . $confirm_title . '</title>',
        $confirm_path,
        array(
          'attributes' => array(
            'class' => array('popup-confirm button'),
          ),
          'html' => TRUE,
        )
      ). '&nbsp;'.
      ($cancel_title ? '<a href="#" class="popup-close button"><span>'.$cancel_title.'</span></a>' : '') .
    '</div>';

	$attributes += array(
		'activate' => 'click',
		'class' => 'popup-confirm',
	);

  return popup_element(
		$title,
		$body,
		$attributes
  );
}


