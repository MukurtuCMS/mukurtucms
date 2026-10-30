REQUIRED. Manages the Command Buttons for Open Atrium. Also defines the default
Space and Section type taxonomy terms.

Feature that exports the fields for setting Blueprint Type (space_type) and
Section Type (section_type) to Spaces and Sections.  Also exports the node_types
and override to set which node_types (command buttons) are available within a
Space and Section.

Space Types
===========

The Blueprint Type (space_type) taxonomy is created by oa_core, but oa_buttons
is responsible for creating initial default terms and managing the space_type
drop down field on the Space content type.  The space_type taxonomy term is used
to determine what Panelizer layout to use for a space landing page, as well as
which command buttons (node_types) are available via the Add Content dropdown
menu (+ button in toolbar).  A Space can Override the node_types from the
taxonomy term and store space-specific node_types stored with the space node.
The Space can also override the Panelizer layout if the space has not already
customized the panelizer layout.

The Command Buttons (command_buttons) module is responsible for creating a
button that creates a specific content type node.  The Add Content dropdown menu
displays those command buttons for:

- The current section (if any)
- Any sections within the current space
- The current space
- The chain of parent spaces

For example, if the "Event" node_type is enabled for the Parent space, then
selecting "Add Event" from the Add Content dropdown would create a new oa_event
content node that lives within the Parent space.  If "event" node_type is
enabled for a Section within the current space, the new oa_event content node
will live in that section.

TODO: If there is more than one section that enables the same node_type, the
content will be placed in the "first" section (undefined).  Expand this
functionality to specify which Section the node will be created in.  Such as
"Create Event within XYZ Section"

Initially, only a "Default" Space Type term will be created.  Users create
additional space_type terms by creating Blueprints from existing spaces.  A
field of the space_type term determines if the layout should be cloned from an
existing space, or whether the layout is taken from a specific Panelizer layout.

Section Types
=============

Section Types are very similar to Space Type except they apply to Sections.
Currently oa_buttons creates the Section Type terms for Calendar Section, News
Section, and Discussion Section

TODO: The specific plugins should be responsible for creating their own Section
Type taxonomy terms.
