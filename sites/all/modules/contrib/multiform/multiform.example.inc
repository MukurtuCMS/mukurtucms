<?php
/**
 * @file
 * 
 * 
 *
 * @author Kálmán Hosszu - hosszu.kalman@gmail.com - http://premiumcmsthemes.com http://www.kalman-hosszu.com
 */
 
function multiform_test_menu() {
  return array(
    'multiform_test' => array(
      'access callback' => TRUE,
      'type' => MENU_CALLBACK,
      'page callback' => 'multiform_get_form',
      'page arguments' => array(array('multiform_eaxample_test1'), array('multiform_test2')),
    ),
  );
}

function multiform_test1($form, $form_state) {
  $form['test1'] = array('#type' => 'textfield', '#title' => 'test1');
  $form['submit'] = array('#type' => 'submit', '#value' => 'save', '#submit' => array('multiform_test_submit_button'));
  $form['delete'] = array('#type' => 'submit', '#value' => 'delete', '#submit' => array('multiform_test_delete'));
  return $form;
}

function multiform_test2($form) {
  $form['submit'] = array('#type' => 'submit', '#value' => 'save', '#submit' => array('multiform_test_submit_button'));
  $form['delete'] = array('#type' => 'submit', '#value' => 'delete', '#submit' => array('multiform_test_delete'));
  $form['test2'] = array('#type' => 'textfield', '#title' => 'test2');
  return $form;
}

function multiform_test_submit_button($form, $form_state) {
  drupal_set_message($form['#form_id'] . 'multiform_test_submit_button');
}

function multiform_test_delete($form, $form_state) {
  drupal_set_message($form['#form_id'] . 'multiform_test_delete');
}