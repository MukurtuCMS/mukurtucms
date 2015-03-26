
Index
=====

1. Requirements
2. API
    - Methods
    - Hooks
3. Caveats
4. Credits



1. Requirements
---------------

a) This is a JavaScript intensive feature. It is the responsibility of the
   site admin to ensure that all popups have link attributes. Without these the
   script degradation is meaningless.



2. API - Methods
----------------



  function popup($attributes)
  ---------------------------

    Renders a popup element using specified attributes. This method should be
    used to create popups programmatically.

    @param array $attributes

    Attributes is a keyed array where the key is the attribute name.

    Accepted content related attributes are:
    ------------------------------------------

      text   - Actual text to display within the popup body.

      node   - Nid of the node to be displayed within the popup body. Additional
              options for the node display are:

                teaser-display - set to TRUE the node will be rendered as a
                                 teaser.
                links          - set to TRUE the node links will be displayed.
                page-display   - set to TRUE will render the node with its page
                                 value set.
                panel-display  - set to TRUE will render the node with a node
                                 panel view. The Panels module is required to
                                 render panels.

      form   - form id of the form to be displayed within the popup block.

      block  - Id of the block to be popped up OR a value of TRUE, indicating
               that a block provided by a module should be displayed. In the
               latter case, the following attributes should also be provided:

                  module - the name of the module that provides the block.
                  delta  - the delta of the module block.

      menu   - Machine name of the menu to be popped up. Note that the menu
               module prefixes some menu ids with "menu-". Additional attributes
               for menus are:

                  flat   - set to TRUE exposes the top level children of the
                           menu, while its root is not rendered.
                  inline - causes the top level children to be displayed next to
                           eachother, rather than below.

      view   - Machine name of the view to be popped up. The following
               attributes may be provided for views:

                  display - the menu display to be rendered. Defaults to the
                            Default display.
                  args    - a comma separated list of arguments to be passed to
                            the view.

      php    - A string of php that returns rendered text to be displayed within
               the popup body.

      image  - A path relative an image to be used as the popup title. It may be
               relative to:
                  a) Drupal root
                  b) Files folder (public:// and I think private:// may work too )
                  c) Theme folder
               Preference in that order.

      title  - The title that should be used for the popup. This will override
               any of the automatically generated titles provided by each of the
               above popup types. If an image is provided, this will be used as
               the alt attribute.

      link   - The URL to assign to the anchor of the popup. Note that this
               attribute will have no effect if activate is set to click, and
               Javascript is enabled within the client browser. It is still
               recommended to provide one to degrade semi-gracefully.


      Display related attributes:
      ---------------------------

      id     - The CSS id, prefixed with "popup-element-id-", that will be
               assigned to the wrapper of the entire popup element. Note that
               the body will be wrapped within an element with "-active"
               appended to the id, and class "popup-element-wrapper", before
               being appended to the "popup-active-overlay" at the end of the
               HTML body.

      class  - The CSS class, prefixed with "class-" that will be assigned to
               the wrapper of the entire popup element, as well as the wrapper
               of the body. See above.

      origin - The corner of the title that the popup will originate at.
               Accepted values:

                  top-left, top-right, bottom-left and bottom-right

      expand - The direction in which the popup should expand.
               Accepted values:

                  top-left, top-right, bottom-left and bottom-right

      effect - The name of the showing/hiding animation effect to use. Modules
               may provide their own effects by implementing hook_popup_effects.
               The popup suite provides these effects:

                  default         - show or hide the popup with no animation.
                  fade            - fades the popup in or out.
                  slide-down      - slides the popup up/down.
                  slide-down-fade - a combination of both of the above.

      style  - The visual style to be used to display this popup item.

      format - Predefined popup format as managed by the popup_ui module.

      width  - Displayed width of the popup body inner in pixels.


      Behaviour related attributes:
      -----------------------------

      activate     - How the popup should be activated. Accepted values:

                      click - users must click on the popup title to reveal the
                              body.
                      hover - (Default) users activate popups by hovering over
                              the popup title.

      ajax         - Causes the body of the popup to be retrieved with an AJAX
                     call only when the body is to be shown to the user. This
                     attribute applies to nodes, blocks, forms, views and php
                     only.

      close        - Provides a close button within the popup body. Only applies
                     to click activated popups.

      empty-body	 - How an empty body should be handled. Accepted values:

                      all 	- show the popup with an empty body.
                      title - just show the popup title, default.
                      none	- show nothing.



  function popup_element($title, $body, $attributes = array())
  ------------------------------------------------------------

    Renders a popup elements' HTML

    @param string $title
    @param string $body
    @param array $attributes

    This method should be used to create popups programmatically where the title
    and body of the popup element is known. It will automatically assign classes
    and default behaviors.

    Any additional information should be passed in attributes, eg.
    array('activate' => 'click')



  function popup_ui_confirm($title, $message, $confirm_path, $attributes = array())
  ---------------------------------------------------------------------------------

    Renders a link that pops up a yes/no confirmation dialog.

    This method can be used to provide in-page confirmation popups.

    @param string $title
    The title of the link that is displayed to the user, eg. 'Delete'

    @param string $message
    Message to be displayed to the user when the link is clicked

    @param array $attributes
    Popup attributes to be used for the popup.

    In addition to the normal attributes the following are processed:
    'confirm label' => Label to be displayed as the confirmation link.
    'cancel label' => Label to be displayed as the cancellation link.
        This link just closes the popup.

    See the popup formats config page for a demo.



2. API - Hooks
----------------



  hook_popup_effects()
  --------------------

    This hook allows modules to supply Javascript methods to showing/hiding
    popups.

    @return a keyed array in the form:

     array(
       'show' => array(
         'effect-name' => 'javascript to show the popup',
         ...
       ),
       'hide' => array(
         'effect-name' => 'javascript to hide the popup'
         ...
       ),
      );

   The Javascript is executed within the context of the PopupElement wrapper
   ojbect. The following properties are available as JQuery objects:

    element:  The popup element wrapper
    title:    the title element of the popup
    body:     the body element of the popup. Keep in mind that the body is no
              longer contained within the popup element wrapper, but within its
              own wrapper within the #popup-active-overlay element at the end
              of the HTML body.
    wrapper:  Wrapper of the popup element body. This has the same id as the
              popup element, with "-active" appended.
    origin:   Invisible div element prepended to the element wrapper, to
              establish the popup top/left offset in relation to the document.



  hook_popup_styles()
  -------------------

    This hook allows modules to provide popup display styles. Note that the
    templates of these styles cannot be overridden by the theme.

    @return a keyed array

    in the form:

      array(
        'Style name 1' => 'path/to/style-1',
        'Style label 2' => 'path/to/style-2',
        ...
      )

    For style-1 the following files must exist in the path/to/style-1 directory:

      popup-element-body.tpl.php
      popup-element-title.tpl.php
      popup-element.tpl.php

    For style-1 the following files may exist in the path/to/style-1 directory,
    and will be included if present:

      popup-element.css
      popup-element.js



3. Caveats
----------

a) IE6 is no longer supported from version 6x-3.2. Popups will work, however
   ugly it makes them.



4. Credits
----------

  JQuery text insertion within the popup_filter:
  By Alex King, adapted to jquery by Alex Brem
  http://www.mail-archive.com/jquery-en@googlegroups.com/msg08708.html

  Popup description label position concept
  By Jan-Jan van der Vyver

  Node reference field integration
  Original Idea by Greg McKeen

  The flying spagetty monster.
  For touching us with his noodly appendage.

