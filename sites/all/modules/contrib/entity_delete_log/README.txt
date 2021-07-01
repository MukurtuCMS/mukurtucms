|===================|
| Entity Delete Log |
|===================|

  Creates a custom database log entry when entities are deleted.

|==============|
| Installation |
|==============|

  1. Download module
  2. Upload module to sites/all/modules
  3. Enable module
  4. Flush All of Drupal's Caches

|=======|
| Setup |
|=======|

  (admin/config/system/entity-delete-log)

  Configuration -> System -> Entity Delete Log

    Choose which entity types will have delete logging enabled.

|=============|
| Permissions |
|=============|

  To make changes to the Entity Delete Log settings, users need the "Adminster
  site configuration" permission.

  To view the Entity Delete Log, users need the "View site reports" permission.

|=======|
| Usage |
|=======|

  (admin/reports/entity-delete-log)

  Reports -> Entity Delete Log
  
    This page provides a listing of entity deletion log events.

|========|
| Extras |
|========|

  Organic Groups
  --------------
  
    Enable the "Entity Delete Log Organic Groups" sub module to track which
    Organic Group(s) an entity belonged to before it was deleted.

      (admin/reports/entity-delete-log/og)  

      Reports -> Entity Delete Log -> Organic Groups

|=======|
| Hooks |
|=======|

To customize the entity delete log data before it is inserted into the
database, use this hook:

/**
 * Implements hook_entity_delete_log_alter().
 */
function MY_MODULE_entity_delete_log_alter($entity, $type, $variables) {
  // Make changes to $variables here, then return $variables.
  return $variables;
}

After the entity delete log data has been inserted, this hook can be used to
do any additional processing.

/**
 * Implements hook_entity_delete_log_post_process().
 */
function MY_MODULE_entity_delete_log_post_process($entity, $type, $variables) {
  // Do anything you want after the entity deletion has been logged.
} 

