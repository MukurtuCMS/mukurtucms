<?php

/**
 * @file
 * Admin page callbacks for the og comments access module.
 */

/**
 * Menu callback; present an administrative comment listing.
 */
function og_comments_access_admin($type = 'new', $group) {
  $edit = $_POST;

  if (isset($edit['operation']) && ($edit['operation'] == 'delete') && isset($edit['comments']) && $edit['comments']) {
    return drupal_get_form('comment_multiple_delete_confirm');
  }
  else {
    return drupal_get_form('og_comments_access_admin_overview', $type, $group->nid);
  }
}

/**
 * Form builder for the comment overview administration form.
 *
 * @param $arg
 *   Current path's fourth component: the type of overview form ('approval' or
 *   'new').
 *
 * @ingroup forms
 * @see comment_admin_overview_validate()
 * @see comment_admin_overview_submit()
 * @see theme_comment_admin_overview()
 */
function og_comments_access_admin_overview($form, &$form_state, $arg, $gid) {
  // Build an 'Update options' form.
  $form['gid'] = array(
    '#type' => 'hidden',
    '#value' => $gid
  );
  $form['options'] = array(
    '#type' => 'fieldset',
    '#title' => t('Update options'),
    '#attributes' => array('class' => array('container-inline')),
  );

  if ($arg == 'approval') {
    drupal_set_title(t('Unapproved comments'));
    $options['publish'] = t('Publish the selected comments');
  }
  else {
    drupal_set_title(t('Published comments'));
    $options['unpublish'] = t('Unpublish the selected comments');
  }
  $options['delete_itmes'] = t('Delete the selected comments');

  $form['options']['operation'] = array(
    '#type' => 'select',
    '#title' => t('Operation'),
    '#title_display' => 'invisible',
    '#options' => $options,
    '#default_value' => 'publish',
  );
  $form['options']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Update'),
  );

  // Load the comments that need to be displayed.
  $status = ($arg == 'approval') ? COMMENT_NOT_PUBLISHED : COMMENT_PUBLISHED;
  $header = array(
    'subject' => array('data' => t('Subject'), 'field' => 'subject'),
    'author' => array('data' => t('Author'), 'field' => 'name'),
    'posted_in' => array('data' => t('Posted in'), 'field' => 'node_title'),
    'changed' => array('data' => t('Updated'), 'field' => 'c.changed', 'sort' => 'desc'),
    'operations' => array('data' => t('Operations')),
  );

  $query = db_select('comment', 'c')->extend('PagerDefault')->extend('TableSort');
  $query->join('node', 'n', 'n.nid = c.nid');
  $query->join('og_membership', 'ogm', 'ogm.etid = n.nid');
  $query->addField('n', 'title', 'node_title');
  $query->addTag('node_access');
  $result = $query
    ->fields('c', array('cid', 'subject', 'name', 'changed'))
    ->condition('c.status', $status)
    ->condition('ogm.gid', $gid)
    ->limit(20)
    ->orderByHeader($header)
    ->execute();

  $cids = array();

  // We collect a sorted list of node_titles during the query to attach to the comments later.
  foreach ($result as $row) {
    $cids[] = $row->cid;
    $node_titles[] = $row->node_title;
  }
  $comments = comment_load_multiple($cids);

  // Build a table listing the appropriate comments.
  $options = array();
  $destination = drupal_get_destination();

  foreach ($comments as $comment) {
    // Remove the first node title from the node_titles array and attach to the comment.
    $comment->node_title = array_shift($node_titles);
    $comment_body = field_get_items('comment', $comment, 'comment_body');
    $options[$comment->cid] = array(
      'subject' => array(
        'data' => array(
          '#type' => 'link',
          '#title' => $comment->subject,
          '#href' => 'comment/' . $comment->cid,
          '#options' => array('attributes' => array(
              'title' => truncate_utf8($comment_body[0]['value'], 128)), 'fragment' => 'comment-' . $comment->cid),
        ),
      ),
      'author' => theme('username', array('account' => $comment)),
      'posted_in' => array(
        'data' => array(
          '#type' => 'link',
          '#title' => $comment->node_title,
          '#href' => 'node/' . $comment->nid,
        ),
      ),
      'changed' => format_date($comment->changed, 'short'),
      'operations' => array(
        'data' => array(
          array(
            '#type' => 'link',
            '#title' => t('edit'),
            '#href' => 'comment/' . $comment->cid . '/edit',
            '#options' => array('query' => $destination),
          ),
          array(
            '#type' => 'link',
            '#title' => ' ' . t('delete'),
            '#href' => 'comment/' . $comment->cid . '/delete',
            '#options' => array('query' => $destination),
          )
        ),
      ),
    );
  }

  $form['comments'] = array(
    '#type' => 'tableselect',
    '#header' => $header,
    '#options' => $options,
    '#empty' => t('No comments available.'),
  );

  $form['pager'] = array('#theme' => 'pager');

  return $form;
}

/**
 * Validate comment_admin_overview form submissions.
 */
function og_comments_access_admin_overview_validate($form, &$form_state) {
  $form_state['values']['comments'] = array_diff($form_state['values']['comments'], array(0));
  // We can't execute any 'Update options' if no comments were selected.
  if (count($form_state['values']['comments']) == 0) {
    form_set_error('', t('Select one or more comments to perform the update on.'));
  }
}

/**
 * Process comment_admin_overview form submissions.
 *
 * Execute the chosen 'Update option' on the selected comments, such as
 * publishing, unpublishing or deleting.
 */
function og_comments_access_admin_overview_submit($form, &$form_state) {
  $operation = $form_state['values']['operation'];
  $cids = $form_state['values']['comments'];
  $gid = $form_state['values']['gid'];

  if ($operation == 'delete_itmes') {
    comment_delete_multiple($cids);
  }
  else {
    foreach ($cids as $cid => $value) {
      $comment = comment_load($value);

      if ($operation == 'unpublish') {
        $comment->status = COMMENT_NOT_PUBLISHED;
      }
      elseif ($operation == 'publish') {
        $comment->status = COMMENT_PUBLISHED;
      }
      comment_save($comment);
    }
  }
  drupal_set_message(t('The update has been performed.'));
  $form_state['redirect'] = "node/{$gid}/comment";
  cache_clear_all();
}
