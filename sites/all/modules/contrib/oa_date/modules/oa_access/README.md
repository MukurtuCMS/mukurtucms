OPTIONAL: Provides framework for group-specific and team-specific access
permissions, similar to Roles.

Drupal normally assigned user permissions based on user roles.  Roles can be
site-wide, or space-specific.  However, in some cases you want permissions to be
related to users in a Group or Team.  For example, LDAP might provide a Group of
"managers" and you want these users to have different permissions across the
site, without creating a separate role.

oa_access provides the code framework, and admin UI for managing Group and Team
permissions.  Enabling this module by default will not show any permissions. 
Other modules that require oa_access need to be enabled to add specific
permissions.  The oa_workbench module adds permissions for workflow.  The
oa_profile2 module adds permissions for user profiles.

Group Permissions
-----------------

To change Group permissions, navigate to /groups/oa_access.  There is a "Group
Permission" contextual tab button on the main /groups page.

The Chosen boxes in the Groups column can be used to determine which Groups have
the given permission.

Team Permissions
----------------

To control the permissions of a Team, go to group/node/teamid/admin/oa_access,
or go to the Space -> Config -> Team Permissions screen.

The Chosen boxes in the Teams column can be used to determine which Teams have
the given permission.
