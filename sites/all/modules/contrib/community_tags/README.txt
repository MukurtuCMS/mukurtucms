
-----------------------
  OVERVIEW
-----------------------
Community Tags module allows users with the proper permissions to tag other users' content. These
tags can be displayed in a "tag cloud" from Tagedlic module in a variety of ways in order to
emphasize popular items.

-----------------------
  INSTALLATION
-----------------------

1. Download the 6.x version of Community Tags module and place its directory into your Drupal
   modules directory.

2. Enable the modules by navigating to:

     Administer > Site Building > Modules

3. Add term reference fields to your content type(s) by going to:

     Administer > Structure > Content types

     Note: Ensure that the "number of values" setting for the field is appropriate.

4. Select which vocabularies should use community tagging by going to:

     Administer > Configuration > Content authoring > Community tags

5. Select how each node type should display the community tagging form by going to:

     Administer > Structure > Content Types

   Note: The community tagging settings can be found in the "Community tags settings" section
   of the content type settings form. They will only be visible if a community tags
   enabled vocabulary is assigned to the content type. See steps 3 and 4 above!

6. Set permissions for tagging content and editing tags by going to:

     Administer > People > Permissions

   Note: Don't give community tags permissions to anonymous users. See note below.

-----------------------
  NOTES
-----------------------

1. Block caching - Block caching is not supported for the community tags block.

2. Anonymous tagging - Basically this is not supported. It may appear to work but
all anonymous users are effectively treated as the same user - i.e. if 1000 anon users
all tag with the same term it only registers a single tag. If 1 anon user the removes
it it's gone.

------------------------
  WORKFLOW
------------------------
These are the rules applied to community tags WRT to affecting workflow.

Note: In the following discussion "valid terms" refer to taxonomy terms belonging
to free-tagging vocabularies that have been configured for use as "community tags".


Community Tags operations:
==========================

Tag added
---------
If not already present add term to node terms via node_save() (sync mode).


Tag removed
-----------
1. If node has this tag as a node term and no other user has tagged this node with this
term then remove node term via node_save() (sync mode).

2. Orphaned terms are removed (delete orphans mode only)


Node operations:
================

New node
--------
Community tags are created for all valid node terms with user set to
the node editor (not author).


Node update
-----------
1. Any valid node terms that are not community tags (for any user)
are added as community tags for the node editor - i.e. current user.

2. Any community tags for the node (for any user) that are not valid node terms
are either a) deleted for all users (snyc mode) or b) deleted for the current user (non-sync mode).

3. Orphaned terms are removed (delete orphans mode only)


Node delete
-----------
1. All community tags records are removed for the deleted node.
2. Remove orphaned terms (delete orphans mode only)


User operations:
================

User delete
-----------
All community tags are removed for the deleted user. Where the deleted user's tags were the
only tag for the combination of node/term then do:
1. Remove corresponding node terms (sync mode)
2. Remove orphaned terms (delete orphans mode only)

(NB thinking of having the option of moving tags to a "dead" user rather than
lose potentially valuable tagging activity).


Taxonomy operations:
====================

Term delete
-----------
All community tags are removed for the deleted term. No synchronisation issues.

Vocabulary operations:

Vocabulary update
-----------------
If the machine_name of a vocabulary is updated then update the community_tags settings.


Configuration changes:
======================

What happens when configuration that affects CT behaviour changes? NB: a valid
CT vocabulary is free-tagging, CT enabled, and has content type(s) assigned.

Valid CT vocabulary is changed to non-free-tagging
------------------------------------------------------
Does nothing. Tags will remain in the database. All CT operations including
orphan control etc only affect tags in valid CT vocabularies. If vocabulary is
subsequently reverted back to free-tagging then there may be some orphaned
tags for any nodes, terms or users that have been deleted in the mean time. Rebuild.

Valid CT vocabulary has community tagging disabled via the Community Tags settings page
---------------------------------------------------------------------------------------
Similar to above.

Valid CT vocabulary has content type assignation(s) removed
-----------------------------------------------------------
Similar to above. Will prevent orphaned terms from being removed (delete orphans mode only)
if tags were created for the de-assigned content type and other content type(s) are
being tagged with the same vocabulary. Need a solution?

CT Synchronisation mode changes
-------------------------------
No affect.


-----------------------
  AUTHOR INFORMATION
-----------------------

Tagadelic was originally written by Bèr Kessels and more information can be
found on http://www.webschuur.com/modules/tagadelic.

Carpentered in the webschuur.com

Additional modifications including weighted node tagging, the quick tag form and
user tags have been authored by Rob Barreca of Electronic Insight and more
information can be found at http://www.electronicinsight.com.

Cherry-picking from Rob Barreca's work and using it to create the Community Tags
module was done by Angela Byron of Lullabot with support from the Bryght guys.

Steven Wittens of Bryght updated this module to 5.x, cleaned up the code some more
and added more shiny features.

Andy Chapman - partial rewrite for 2.x. and port to D7.