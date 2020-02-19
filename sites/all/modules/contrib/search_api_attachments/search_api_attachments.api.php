<?php

/**
 * @file
 * Hooks provided by the "Search API attachments" module.
 */

/**
 * @addtogroup hooks
 * @{
 */

/**
 * Determines whether an attachment should be indexed.
 *
 * @param array $file
 *   An attachment file array.
 * @param object $item
 *   A field item object.
 * @param string|null $field_name
 *   The name of the field the file was in, if applicable.
 *
 * @return bool|null
 *   Return FALSE if the attachment should not be indexed.
 */
function hook_search_api_attachments_indexable(array $file, $item, $field_name) {
  // Don't index files on entities owned by our bulk upload bot accounts.
  if (in_array($item->uid, my_module_blocked_uids())) {
    return FALSE;
  }
}

/**
 * @} End of "addtogroup hooks".
 */
