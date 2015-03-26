<?php

/**
 * @file
 * Various non-administration page callbacks for the mollom module.
 */

/**
 * AJAX callback to retrieve a CAPTCHA.
 *
 * @param $type
 *   The new CAPTCHA type to retrieve, e.g. 'image' or 'audio'.
 * @param $form_build_id
 *   The internal form build id of the form to update the CAPTCHA for.
 * @param $contentId
 *   (optional) The associated content ID in the form.
 *
 * @return
 *   A JSON array containing:
 *   - content: The HTML markup for the new CAPTCHA.
 *   - captchaId: The ID for the new CAPTCHA.
 *
 * @todo Add error handling.
 */
function mollom_captcha_js($type, $form_build_id, $contentId = NULL) {
  // Deny GET requests to make automated security audit tools not complain
  // about a JSON Hijacking possibility.
  // @see http://capec.mitre.org/data/definitions/111.html
  // @see http://haacked.com/archive/2009/06/24/json-hijacking.aspx
  if ($_SERVER['REQUEST_METHOD'] !== 'POST') {
    header($_SERVER['SERVER_PROTOCOL'] . ' 405 Method Not Allowed');
    // A HTTP 405 response MUST specify allowed methods.
    header('Allow: POST');
    drupal_exit();
  }

  // Load $form_state from cache or create a dummy state.
  $cid = 'form_state_' . $form_build_id;
  if ($cache = cache_get($cid, 'cache_form')) {
    $form_state = $cache->data;
  }
  else {
    $form_state['mollom'] = array();
    if (isset($contentId)) {
      $form_state['values']['mollom']['contentId'] = $contentId;
    }
  }
  $form_state['mollom']['captcha_type'] = $type;
  $captcha = mollom_get_captcha($form_state);

  if (!empty($form_state['mollom']['response']['captcha']['id'])) {
    // Update the CAPTCHA ID in the cached $form_state, since it might have
    // changed.
    // @todo Replace the entire CAPTCHA switch/refresh with new AJAX framework
    //   functionality.
    if ($cache) {
      cache_set($cid, $form_state, 'cache_form', REQUEST_TIME + 21600);
    }
    // Return new content and CAPTCHA ID via JSON.
    $data = array(
      'content' => $captcha,
      'captchaId' => $form_state['mollom']['response']['captcha']['id'],
    );
    drupal_json_output($data);
  }
  drupal_exit();
}

/**
 * Form builder for report to Mollom form.
 *
 * @param $entity
 *   The entity type of the data to report, e.g. 'node' or 'comment'.
 * @param $id
 *   The entity id the data belongs to.
 *
 * @see mollom_report_access()
 */
function mollom_report_form($form, &$form_state, $entity, $id) {
  $form['entity'] = array(
    '#type' => 'value',
    '#value' => $entity,
  );
  $form['id'] = array(
    '#type' => 'value',
    '#value' => $id,
  );
  // @todo "Delete" does not work for reporting mails to Mollom. In D7+, this
  //   form should be used solely for mails, as other entities are reported
  //   through existing delete confirmation forms instead. Perhaps there should
  //   be a dedicated form for reporting mails, as they are not really
  //   compatible with any of the standard processes either way.
  $form = confirm_form($form,
    t('Are you sure you want to delete and report the content as inappropriate?'),
    '<front>',
    t('This action cannot be undone.'),
    t('Delete'), t('Cancel')
  );
  mollom_data_delete_form_alter($form, $form_state);
  return $form;
}

/**
 * Form submit handler for mollom_report_form().
 */
function mollom_report_form_submit($form, &$form_state) {
  if ($form_state['values']['confirm']) {
    $entity = $form_state['values']['entity'];
    $id = $form_state['values']['id'];

    // Load the Mollom session data.
    $data = mollom_data_load($entity, $id);

    // Send feedback to Mollom, if we have session data.
    if ((!empty($data->contentId) || !empty($data->captchaId)) && !empty($form_state['values']['mollom']['feedback'])) {
      if (_mollom_send_feedback($data, $form_state['values']['mollom']['feedback'], 'moderate', 'mollom_report_form_submit')) {
        drupal_set_message(t('The content was successfully reported as inappropriate.'));
      }
    }

    // Delete the content. The callback should take care of proper deletion and
    // cache clearing on its own.
    foreach (mollom_form_list() as $form_id => $info) {
      if (!isset($info['entity']) || $info['entity'] != $entity) {
        continue;
      }
      // If there is a 'report delete callback', invoke it.
      if (isset($info['report delete callback']) && function_exists($info['report delete callback'])) {
        $function = $info['report delete callback'];
        $function($entity, $id);
        break;
      }
    }

   $form_state['redirect'] = '<front>';
  }
}
