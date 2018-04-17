<?php


/**
 * @file
 * Hooks provided by the Message subscribe module.
 */

/**
 * @addtogroup hooks
 * @{
 */

/**
 * Allow modules to add user IDs that need to be notified.
 */
function hook_message_subscribe_get_subscribers(Message $message, $subscribe_options = array(), $context = array()) {

}

/**
 * Alter the subscribers list.
 */
function hook_message_subscribe_get_subscribers_alter(&$uids, $values) {

}

/**
 * @} End of "addtogroup hooks".
 */
