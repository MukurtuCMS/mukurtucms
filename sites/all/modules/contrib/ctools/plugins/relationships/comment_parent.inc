<?php

/**
 * @file relationships/comment_parent.inc
 * Plugin to provide a relationship handler for comment parent.
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t('Parent comment'),
  'keyword' => 'parent_comment',
  'description' => t('Adds a parent comment from a comment context.'),
  'required context' => new ctools_context_required(t('Comment'), 'entity:comment'),
  'context' => 'ctools_comment_parent_context',
);

/**
 * Return a new context based on an existing context.
 */
function ctools_comment_parent_context($context, $conf) {
  if (empty($context->data)) {
    return ctools_context_create_empty('entity:comment');
  }

  if (isset($context->data->pid) && ($context->data->pid !== 0)) {
    $parent_comment = comment_load($context->data->pid);
    return ctools_context_create('entity:comment', $parent_comment);
  }
}
