<?php
/**
 * @file
 * Custom callbacks.
 */

/**
 * Handles menu callback for replying and editing comments in a ctools modal.
 *
 * @param object $parent
 *   The $node if this is a new comment or the parent $comment if we are
 *   replying to an existing comment.
 * @param string $action
 *   The action we are taking on the comment.
 * @param bool $js
 *   True if using javascript.
 * @param object $comment
 *   The comment we are acting on.
 */
function oa_comment_comment_actions($parent, $action, $js = NULL, $comment = NULL) {
  $reply = ($action == 'reply') ? TRUE : FALSE;
  $edit = ($action == 'edit') ? TRUE : FALSE;

  // Get the correct form_id.
  $form_id = ($edit) ? $parent->node_type . '_form' : (($reply) ? 'comment_node_' . $parent->type . '_form' : array());

  // Set a title for the modal.
  $title = t('!action', array('!action' => ucwords($action)));

  if (!$js) {
    if ($reply) {
      $path = 'comment/reply/' . $parent->nid;
    }
    if ($edit) {
      $path = 'comment/' . $parent->cid . '/edit';
    }
    drupal_goto($path);
  }

  if ($reply) {
    $comment_reply = array(
      'nid' => $parent->nid,
      'pid' => $comment->cid,
      'uid' => 0,
      'mail' => '',
      'homepage' => '',
      'subject' => '',
      'cid' => NULL,
      'language' => LANGUAGE_NONE,
    );
  }

  // Include ctools files.
  ctools_include('modal');
  ctools_include('ajax');

  // Build a custom form state.
  $form_state = array(
    'build_info' => array(
      'args' => array(
        ($edit) ? $parent : NULL,
      ),
    ),
    'comment' => ($reply) ? (object) $comment_reply : NULL,
    'ajax' => TRUE,
    'title' => $title,
  );

  // Render the commands array.
  $commands = ctools_modal_form_wrapper($form_id, $form_state);

  // After the form has been submitted.
  if (!empty($form_state['executed'])) {
    $commands = array();
    $commands[] = ctools_ajax_command_reload();
    $commands[] = ctools_modal_command_dismiss();
    if (isset($_GET['destination'])) {
      $commands[] = ctools_ajax_command_redirect($_GET['destination']);
    }
  }
  print ajax_render($commands);
  exit;
}
