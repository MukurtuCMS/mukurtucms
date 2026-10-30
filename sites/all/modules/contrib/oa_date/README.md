OA Core is the primary module for Open Atrium 2.  It contains several submodules
for different functionality. Most of these submodules are required and are
split-out for code modularity.  Some submodules are optional (will be
indicated).  Submodules are found in the oa_core/modules directory.  Common
utility functions are found in oa_core/includes and will be documented below.

Submodules (alphabetical)
=========================

- [**Bootstrap Pane Styles** (bootstrap_pane_styles)](modules/bootstrap_pane_styles) : OPTIONAL.
  Provides panels pane styles for menus. Good example module for building
  custom Panels Pane Styles.

- [**Open Atrium Access** (oa_access)](modules/oa_access) : OPTIONAL.
  Provides framework for group-specific and team-specific access permissions,
  similar to Roles.

- [**Open Atrium Admin Role** (oa_adminrole)](modules/oa_adminrole) : OPTIONAL but Recommended.
  Provides default Permissions for Admins and Members.

- [**Open Atrium Appearance** (oa_appearance)](modules/oa_appearance) : OPTIONAL.
  Enables site and space-specific banners and colors.

- [**Open Atrium Buttons** (oa_buttons)](modules/oa_buttons) : REQUIRED.
  Manages the Command Buttons for Open Atrium. Also defines the default Space
  and Section type taxonomy terms.

- [**Open Atrium Config** (oa_config)](modules/oa_config) : OPTIONAL but Recommended.
  Stores default settings for various contrib modules.

- [**Open Atrium Date** (oa_date)](modules/oa_date) : REQUIRED.
  Adds the relative date formatter used in the Recent Activity views.

- [**Open Atrium Diff** (oa_diff)](modules/oa_diff) : REQUIRED.
  Integrates the Diff module to show differences in the Update messages in the
  Recent Activity.

- [**Open Atrium Domains** (oa_domains)](modules/oa_domains) : OPTIONAL.
  Allows per-space domain name support.
- [**Open Atrium Favorites** (oa_favorites)](modules/oa_favorites) : OPTIONAL.
  Adds the Favorites widget in the toolbar for marking favorite spaces.

- [**Open Atrium Home** (oa_home)](modules/oa_home) : OPTIONAL.
  Featurizes the default Home page markup

- [**Open Atrium HTML Email** (oa_htmlmail)](modules/oa_htmlmail) : OPTIONAL.
  Adds the markup for better HTML email notifications.

- [**Open Atrium Layouts** (oa_layouts)](modules/oa_layouts) : REQUIRED.
  Defines the default panelizer layouts for spaces, groups. Provides the
  default Mini Panels for the Header, Footer, Sidebars.

- [**Open Atrium Messages** (oa_messages)](modules/oa_messages) : REQUIRED.
  Provides the default message types used for Recent Activity and notifications.

- [**Open Atrium Messages Digest** (oa_messages_digest)](modules/oa_messages_digest) : OPTIONAL.
  Integrates the messages_digest module to add Weekly and Daily digests.

- [**Open Atrium News** (oa_news)](modules/oa_news) : OPTIONAL.
  Provides the News Section type view and panels layout.

- [**Open Atrium Panopoly Users** (oa_panopoly_users)](modules/oa_panopoly_users) : REQUIRED.
  Overrides the Panopoly User pages to provide default dashboard layout.

- [**Open Atrium Permissions** (oa_permissions)](modules/oa_permissions) : OPTIONAL.
  Provides the default permissions (Drupal and OG).

- [**Open Atrium Recent Activity** (oa_river)](modules/oa_river) : REQUIRED.
  Provides the Recent Activity view.

- [**Open Atrium Sandbox** (oa_sandbox)](modules/oa_sandbox) : OPTIONAL.
  Adds the Sandbox functionality.

- [**Open Atrium Search** (oa_search)](modules/oa_search) : OPTIONAL.
  Integrates Panopoly Search and search_api. Provides default indexes and
  Facets and Views along with a sidebar search widget.

- [**Open Atrium Sections** (oa_sections)](modules/oa_sections) : REQUIRED.
  Provides Section functionality.

- [**Open Atrium Section Session Context** (oa_section_context)](modules/oa_section_context) : REQUIRED.
  Stores the current section context into user session.

- [**Open Atrium Styles** (oa_styles)](modules/oa_styles) : OPTIONAL.
  Provides general Panels Pane Styles.

- [**Open Atrium Teams** (oa_teams)](modules/oa_teams) : REQUIRED.
  Adds Team functionality.

- [**Open Atrium Tour** (oa_tour)](modules/oa_tour) : OPTIONAL.
  Integrates the Bootstrap Tour module to provide popup help. Adds the Help
  button widget.

- [**Open Atrium Tour Defaults** (oa_tour_defaults)](modules/oa_tour_defaults) : OPTIONAL.
  Adds the default tours for teaching about Open Atrium.

- [**Open Atrium Updater** (oa_update)](modules/oa_update) : OPTIONAL but Recommended.
  Replaces the Drupal Module update page with a distribution profile update page.

- [**Open Atrium Users** (oa_users)](modules/oa_users) : REQUIRED.
  Adds fields to the User entity and provides Views and pages for User's
  activity and basic profile.

- [**Open Atrium Variables** (oa_variables)](modules/oa_variables) : OPTIONAL.
  Adds the default site variables for site-specific values.

- [**Open Atrium Widgets** (oa_widgets)](modules/oa_widgets) : REQUIRED.
  Provides various core Panels Pane widgets.

Common Utility Functions
========================

Located in oa_core/includes:

- **oa_core_util.inc** - Always loaded. Contains many different and useful
  functions, such as returning the current space context, current section context,
  list of groups a user is a member of, etc.  See the code file for PHPDOC
  documentation and comments.

- **oa_core_access.inc** - Always loaded. Contains common access-control
  functions.  All of the node grant and node access hooks are here, along with
  file_entity access.  There is also a utility function to return all of the
  visibility information for a given node.

- **oa_core_login.inc** - Always loaded. Contains the alter hooks to handle the
  user login redirection and the user dashboard. - **oa_core_theme.inc** - Always
  loaded. Contains the hook_theme function to point to various template files.

Content Types
=============

The following core content types are provided by oa_core via Features export:

oa_space
--------

An Organic Group "group type" for defining spaces or sub-spaces.  Note sub-space
functionality is handled by the Open Atrium Subspaces (oa_subspaces) module. 
Additional Base fields include:

- **field_oa_space_type** - points to the Space Type (Space Blueprint) taxonomy.
  The Taxonomy term provides the default command buttons and panelizer layout for
  a given space type.

- **field_oa_section_override** - allows custom command buttons to be enabled
  for the space to appear in the + menu.  See Open Atrium Buttons (oa_buttons)

- **group_access** - the Organic Groups field that allows spaces to be marked as
  Public/Private

- **group_group** - the Organic Groups field that marks a Space as an OG Group type

- **og_roles_permissions** - the Organic Groups field that allows space-specific
  roles and permissions

oa_group
--------

An Organic Group "group type" for defining user access Groups.  While OG
supports assigning nodes to a group, Open Atrium only uses the user membership
features to enable Groups to be used for access control on sections.  Additional
Base fields include:

- **group_access** - the Organic Groups field that allows Groups to be marked as
  Public/Private

- **group_group** - the Organic Groups field that marks a Group as an OG Group type

- **og_roles_permissions** - the Organic Groups field that allows group-specific
  roles and permissions

Global Fields
=============

The following Base fields are defined in oa_core for other content types to
share:

- **field_oa_media** - the file entity reference field used for attachments. 
  oa_core implements custom access control over files assigned to this field based
  upon the node_access of the node being attached to.

Taxonomy
========

The following core taxonomies are defined:

space_type (Space Blueprint)
----------------------------

Used to define the default command buttons and panelizer layout for a particular
space-type.  Allows a space-type to clone an existing space structure via
blueprints.  Additional Base fields include:

- **field_oa_section_layout** - stores the panelizer layout to be used for this
  space type

Views
=====

The following views are exported into oa_core:

- **oa_core_space_types** - a view used for the node/add/oa_space page to list
  the available space types for selection when creating content

- **open_atrium_content** - a view of Recent Content.  The most general purpose
  Views widget in Open Atrium allows most any type of content to be shown for a
  specific space and/or section

- **open_atrium_groups** - a view of Spaces and Groups, typically added to the
  user's dashboard to show subscribed spaces.  Has options for subscribed,
  favorites, inherited.

- **open_atrium_user_filters** -
  provides a list of users of a given group.  Used in other fields to restrict the
  user selection to the users of the current space (such as for teams)
