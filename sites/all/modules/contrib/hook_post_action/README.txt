=== DESCRIPTION  ===
  You don't need this module unless you're either a developer or another module you're using depends on it.
  
  Currently Drupal core does not offer any hook to do actions after a node/entity is insered/updated/deleted in Database.
  So this module introduces several new Drupal hooks to overcome this limitation
  - hook_entity_postsave
  - hook_entity_postinsert
  - hook_entity_postupdate
  - hook_entity_postdelete
  - hook_node_postsave
  - hook_node_postinsert
  - hook_node_postupdate
  - hook_node_postdelete

=== INSTALLATION ===
  Install and enable the module as usual: http://drupal.org/node/70151

=== USAGE ===
  Please read the hook_post_action.api file

  Also if you want to quickly see it working, you can enable the bundled module hook_post_action_example,
  add/delete/update some contents and visit logs admin/reports/dblog

  WARNING: The _postsave, _postinsert and _postupdate hooks are also called when the entity/node is deleted,
  as there is no way to find out whether the entity/node is actually saved/inserted/updated.
  However, the module does only call the delete hooks when the entity/node is actually deleted from database. 

AUTHORS AND MAINTAINERS
=======================
  Sina Salek http://sina.salek.ws