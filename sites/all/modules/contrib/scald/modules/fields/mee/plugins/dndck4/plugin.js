(function ($) {
// Drop out if for some reason Drupal.dnd is not available.
if (typeof Drupal.dnd === 'undefined') {
  CKEDITOR.plugins.add('dndck4', {});
  return;
}

CKEDITOR.plugins.add('dndck4', {
  lang: 'en',
  requires: 'widget',

  init: function (editor) {
    var lang = editor.lang.dndck4;

    var path = this.path;
    editor.on('mode', function (evt) {
      if (editor.mode == 'wysiwyg') {
        editor.document.appendStyleSheet(path + '../../css/editor.css');
        // editor-global.css is included in all pages, and already applies
        // (possibly overriden by the theme) if we are in divarea mode, so we do
        // not want to re-include it in this case.
        if (!editor.editable().isInline()) {
          editor.document.appendStyleSheet(path + '../../css/editor-global.css');
        }
      }
    });

    editor.widgets.add('dndck4', {
      dialog: 'atomProperties',
      pathName: 'atom',
      editables: {
        caption: {
          selector: '.dnd-caption-wrapper',
          pathName: 'caption',
        }
      },
      requiredContent: 'div span figure[data-scald-sid](dnd-atom-wrapper)',
      allowedContent: {},

      /**
       * Turns the marker tag into the actual rendered widget.
       */
      upcast: function(el, data) {
        // Convert atoms embedded with the legacy plugin if needed.
        el = Drupal.dndck4.convertLegacyEmbed(el);

        if (el.name == 'div' && el.hasClass('dnd-atom-wrapper')) {
          // Initialize the widget data from the attributes, and remove the
          // attributes from the element, as they would not stay up to date.
          $.extend(data, Drupal.dndck4.dataFromAttributes(el.attributes));
          el.attributes = {class: el.attributes.class};
          // If we find caption content, set the data accordingly.
          if (el.children[0] && el.children[0].type == CKEDITOR.NODE_ELEMENT && el.children[0].hasClass('dnd-caption-wrapper')) {
            $.extend(data, {usesCaption: true});
          }
          // We're done. The HTML for the expanded widget is fetched using AJAX
          // in the data() callback.
          return el;
        }
      },

      /**
       * Turns the rendered widget back into the marker tag.
       */
      downcast: function(el) {
        var caption = '';
        if (this.data.usesCaption && this.editables.caption) {
          caption = this.editables.caption.getHtml();
        }
        var html = Drupal.dndck4.downcastedHtml(this.data, caption);
        return CKEDITOR.htmlParser.fragment.fromHtml(html);
      },

      /**
       * Do stuff after the widget has been initialized.
       */
      init: function() {
        // Add a shortcut method so that the widget can update the atom render
        // itself.
        this.refreshAtom = function() {
          Drupal.dndck4.fetchExpandedContent(this);
        };
      },

      /**
       * Updates the widget markup when the data changes (also runs after
       * initial creation or upcast).
       */
      data: function() {
        // Don't refresh dragged atom until it's actually dropped.
        if (this.element.$.parentNode.parentNode) {
          this.refreshAtom();
        }
      }
    });

    // Assign the "insert atom into editor" method to be used by the Library on
    // this editor.
    editor.dndInsertAtom = function(sid) {
      var range = editor.getSelection().getRanges()[0];
      var data = Drupal.dndck4.getDefaultInsertData(editor, Drupal.dnd.Atoms[sid]);
      var caption = Drupal.dnd.Atoms[sid].meta.legend || '';
      Drupal.dndck4.insertNewWidget(editor, range, data, caption);
    };

    editor.on('instanceReady', function (evt) {
      // Listen to atom drags from the Library. Namespace the event so that we
      // can unbind it when the editor is disabled.
      $(document).bind('dragstart.dndck4_' + editor.name, function (evt) {
        var editable = editor.editable();
        if (Drupal.dnd.currentAtom && $(editable.$).is(':visible')) {
          var dragInfo = Drupal.dnd.sas2array(Drupal.dnd.currentAtom);
          var atomInfo = Drupal.dnd.Atoms[dragInfo.sid];
          var data = Drupal.dndck4.getDefaultInsertData(editor, atomInfo);
          var caption = atomInfo.meta.legend || '';
          var widget = Drupal.dndck4.createNewWidget(editor, data, caption);
          Drupal.dndck4.onLibraryAtomDrag.call(widget, atomInfo);
        }
      });
    });

    editor.on('destroy', function (evt) {
      // Remove the drag listener so that it can be safely re-added if the
      // editor is re-created.
      $(document).unbind('dragstart.dndck4_' + editor.name);
    });

    // Setup the "atom properties" dialog.
    CKEDITOR.dialog.add('atomProperties', this.path + 'dialogs/atomProperties.js' );
    editor.ui.addButton('ScaldAtom', {
      label: lang.atom_properties,
      command: 'atomProperties',
      icon: this.path + 'icons/atom.png'
    });
    editor.addCommand('atomProperties', {
      allowedContent: 'div span figure figcaption[data-scald-sid,data-scald-align,data-scald-context,data-scald-options,data-scald-type](dnd-atom-wrapper,dnd-caption-wrapper)',
      exec: function (editor) {
        var widget = editor.widgets.focused;
        if (widget && widget.name == 'dndck4') {
          widget.edit();
        }
        else {
          // If the library is hidden, show it
          var library_wrapper = $('.dnd-library-wrapper');
          if (library_wrapper.length && !library_wrapper.hasClass('library-on')) {
            $('.scald-anchor', library_wrapper).click();
          }
          else {
            alert(lang.atom_none);
          }
        }
      }
    });

    editor.addCommand('atomView', {
      exec: function (editor) {
        var widget = editor.widgets.focused;
        window.open(Drupal.settings.basePath + Drupal.settings.pathPrefix + 'atom/' + widget.data.sid);
      }
    });

    editor.addCommand('atomEdit', {
      exec: function (editor) {
        var widget = editor.widgets.focused;
        var $wrapper = $("<div></div>", {
          'class' : 'wysiwyg-atom-edit-wrapper'
        });
        var $link = $("<a></a>", {
          'target' : '_blank',
          'href' : Drupal.settings.basePath + Drupal.settings.pathPrefix + 'atom/' + widget.data.sid + '/edit/nojs',
          'class' : 'ctools-use-modal ctools-modal-custom-style'
        }).appendTo($wrapper);
        Drupal.behaviors.ZZCToolsModal.attach($wrapper);
        $link.click();
        $(document).one("CToolsDetachBehaviors", function() {
          widget.refreshAtom();
        });
      }
    });

    editor.addCommand('atomRefresh', {
      exec: function (editor) {
        var widget = editor.widgets.focused;
        widget.refreshAtom();
      }
    });

    // Setup right-click menu items.
    editor.addMenuGroup('dnd', -100);
    editor.addMenuItems({
      atomproperties: {
        label: lang.atom_properties,
        command: 'atomProperties',
        group: 'dnd'
      },
      atomview : {
        label: lang.atom_view,
        command: 'atomView',
        group: 'dnd'
      },
      atomedit : {
        label: lang.atom_edit,
        command: 'atomEdit',
        group: 'dnd'
      },
      atomrefresh : {
        label: lang.atom_refresh,
        command: 'atomRefresh',
        group: 'dnd'
      },
      atomdelete: {
        label: lang.atom_delete,
        command: 'atomDelete',
        group: 'dnd'
      },
      atomcopy: {
        label: lang.atom_copy,
        command: 'atomCopy',
        icon: 'copy',
        group: 'dnd'
      },
      atomcut: {
        label: lang.atom_cut,
        command: 'atomCut',
        icon: 'cut',
        group: 'dnd'
      },
      atompaste: {
        label: lang.atom_paste,
        command: 'atomPaste',
        icon: 'paste',
        group: 'dnd'
      }
    });
    editor.contextMenu.addListener(function (element, selection) {
      var menu = {};
      var widget = editor.widgets.getByElement(element);
      if (widget && widget.name == 'dndck4') {
        menu.atomproperties = CKEDITOR.TRISTATE_OFF;
        menu.atomview = CKEDITOR.TRISTATE_OFF;
        menu.atomedit = CKEDITOR.TRISTATE_OFF;
        menu.atomrefresh = CKEDITOR.TRISTATE_OFF;
        menu.atomcopy = CKEDITOR.TRISTATE_OFF;
        menu.atomcut = CKEDITOR.TRISTATE_OFF;
        menu.atomdelete = CKEDITOR.TRISTATE_OFF;
        editor.contextMenu.items = [];
      }
      else if (Drupal.dndck4.atomPaste) {
        menu.atompaste = CKEDITOR.TRISTATE_OFF;
        for (var index in editor.contextMenu.items) {
          if (editor.contextMenu.items[index].name == 'paste') {
            editor.contextMenu.items.splice(index, 1);
          }
        }
      }
      return menu;
    });
    editor.addCommand('atomDelete', {
      exec: function (editor) {
        editor.fire('saveSnapshot');
        editor.fire('lockSnapshot', {dontUpdate: 1});

        var widget = editor.widgets.focused;
        Drupal.detachBehaviors(widget.element.$);
        widget.wrapper.remove();
        widget.destroy(true);

        editor.fire('unlockSnapshot');
        editor.fire('saveSnapshot');
      },
      canUndo: false,
      editorFocus: CKEDITOR.env.ie || CKEDITOR.env.webkit
    });
    editor.addCommand('atomCut', {
      exec: function (editor) {
        editor.fire('saveSnapshot');
        editor.fire('lockSnapshot', {dontUpdate: 1});

        var widget = editor.widgets.focused;
        Drupal.dndck4.atomPaste = {
          data: widget.data,
          caption: widget.editables.caption.getHtml()
        };
        Drupal.detachBehaviors(widget.element.$);
        widget.wrapper.remove();
        widget.destroy(true);

        editor.fire('unlockSnapshot');
        editor.fire('saveSnapshot');
      },
      canUndo: false,
      editorFocus: CKEDITOR.env.ie || CKEDITOR.env.webkit
    });
    editor.addCommand('atomCopy', {
      exec: function (editor) {
        var widget = editor.widgets.focused;
        Drupal.dndck4.atomPaste = {
          data: widget.data,
          caption: widget.editables.caption.getHtml()
        };
      },
      canUndo: false,
      editorFocus: CKEDITOR.env.ie || CKEDITOR.env.webkit
    });
    editor.addCommand('atomPaste', {
      exec: function (editor) {
        if (Drupal.dndck4.atomPaste) {
          var range = editor.getSelection().getRanges()[0];
          // insertNewWidget already handles snapshot.
          Drupal.dndck4.insertNewWidget(editor, range, Drupal.dndck4.atomPaste.data, Drupal.dndck4.atomPaste.caption);
        }
      },
      canUndo: false,
      editorFocus: CKEDITOR.env.ie || CKEDITOR.env.webkit
    });

  },

  afterInit: function (editor) {
    function setupAlignCommand(value) {
      var command = editor.getCommand('justify' + value);
      if (command) {
        if (value in {right: 1, left: 1, center: 1}) {
          command.on('exec', function (event) {
            var widget = editor.widgets.focused;
            if (widget && widget.name === 'dndck4') {
              widget.setData({align: value});
            }
          });
        }

        command.on('refresh', function (event) {
          var widget = editor.widgets.focused,
            allowed = { left: 1, center: 1, right: 1 },
            align;

          if (widget && widget.name === 'dndck4') {
            align = widget.data.align;

            this.setState(
              (align === value) ? CKEDITOR.TRISTATE_ON : (value in allowed) ? CKEDITOR.TRISTATE_OFF : CKEDITOR.TRISTATE_DISABLED);

            event.cancel();
          }
        });
      }
    }

    // Customize the behavior of the alignment commands.
    setupAlignCommand('left');
    setupAlignCommand('right');
    setupAlignCommand('center');
  }

});

/**
 * Helper methods and properties.
 */
Drupal.dndck4 = {

  registeredCallbacks: [],

  registerCallback: function (hook, callback) {
    Drupal.dndck4.registeredCallbacks.push({hook: hook, callback: callback});
  },

  unRegisterCallback: function (hook) {
    Drupal.dndck4.registeredCallbacks = $.map(Drupal.dndck4.registeredCallbacks, function(item, index) {
      if (item.hook == hook || item.hook.lastIndexOf(hook + '.', 0) === 0) {
        return null;
      }
      return item;
    });
  },

  invokeCallbacks: function(hook, param) {
    $.each(Drupal.dndck4.registeredCallbacks, function(i) {
      var name = this.hook.split('.')[0];
      if (name == hook) {
        if (typeof this.callback === 'function') {
          this.callback(param);
        }
      }
    });
  },

  registeredOptions: [],

  registerOptions: function(id, type, mode, name) {
    var found = false;
    $.each(Drupal.dndck4.registeredOptions, function() {
      if (found = (this.id == id && this.type == type && this.mode == mode && this.name == name)) {
        return false;
      }
    });
    if (!found) {
      var item = {id: id, type: type, mode: mode, name: name};
      Drupal.dndck4.registeredOptions.push(item);
    }
  },

  addOption: function(id, type, mode, name, callback) {
    $('body').once(id, function() {
      if (typeof CKEDITOR === 'undefined') {
        // CKEditor is not available yet, lets try a little bit later.
        setTimeout(function() {
          // If It's still not available, stop trying.
          if (typeof CKEDITOR !== 'undefined') {
            Drupal.dndck4.processOption(id, type, mode, name, callback);
          }
        }, 1000);
      }
      else {
        Drupal.dndck4.processOption(id, type, mode, name, callback);
      }
    });
  },

  processOption: function(id, type, mode, name, callback) {
    CKEDITOR.on('dialogDefinition', function(ev) {
      if (typeof Drupal.dndck4 !== 'undefined') {
        if (ev.data.name == 'atomProperties') {
          var dialogDefinition = ev.data.definition;
          var infoTab = dialogDefinition.getContents('info');
          callback.call(this, infoTab, dialogDefinition);
          Drupal.dndck4.registerOptions(id, type, mode, name);
        }
      }
    });
  },

  dataFromAttributes: function (attributes) {
    return {
      sid : attributes['data-scald-sid'],
      type : attributes['data-scald-type'],
      context : attributes['data-scald-context'],
      // 'options' is kept as a JSON string, so that widget.setData() correctly
      // detects value changes.
      options : attributes['data-scald-options'] ? decodeURIComponent(attributes['data-scald-options']) : '{}',
      align : attributes['data-scald-align'],
      usesCaption : false
    }
  },

  attributesFromData: function (data) {
    return {
      'data-scald-sid' : data.sid,
      'data-scald-type' : data.type,
      'data-scald-context' : data.context,
      'data-scald-options' : (data.options == '{}') ? '' : encodeURIComponent(data.options),
      'data-scald-align' : data.align
      // Note : we don't include "usesCaption", that is derived from the actual
      // presence of a caption in the downcasted HTML.
    }
  },

  implodeAttributes: function (attributes) {
    var parts = [];
    $.each(attributes, function(key, value) {
      parts.push(key + "='" + value + "'");
    });
    return parts.join(' ');
  },

  getDefaultInsertData: function (editor, atomInfo) {
    var sasData = Drupal.dnd.sas2array(atomInfo.sas), data;
    data = {
      sid : atomInfo.sid,
      type: atomInfo.meta.type,
      // The default context for newly embedded atoms is a setting of the text
      // field, and is placed in the 'data-dnd-context' attribute on the
      // textarea.
      context : (editor.element.$.attributes['data-dnd-context']) ?
        editor.element.$.attributes['data-dnd-context'].value :
        Drupal.settings.dnd.contextDefault,
      // Modules can use hook_scald_dnd_library_item_alter() to add default
      // options in the sas code for the atom.
      options : sasData.options || '{}',
      align : 'none',
      usesCaption : Drupal.settings.dnd.usesCaptionDefault
    };

    Drupal.dndck4.invokeCallbacks('GetDefaultInsertData', data);

    return data;
  },

  createNewWidget: function(editor, data, caption) {
    // Generate the downcasted HTML for the widget, and run upcast() on it.
    var html = Drupal.dndck4.downcastedHtml(data, caption);
    var element = CKEDITOR.htmlParser.fragment.fromHtml(html).children[0];
    element = editor.widgets.registered.dndck4.upcast(element);
    // Turn it into a proper DOM element, and insert it.
    element = CKEDITOR.dom.element.createFromHtml(element.getOuterHtml());
    // Promote it to a widget. This runs the init() / data() methods, which
    // fetches the expanded HTML for the atom embed.
    return editor.widgets.initOn(element, 'dndck4', data);
  },

  insertWidget: function(widget, editor, range) {
    // Group all following operations in one snapshot.
    editor.fire('saveSnapshot');
    editor.fire('lockSnapshot', {dontUpdate: 1});

    editor.editable().insertElementIntoRange(widget.wrapper, range);

    widget.ready = true;
    widget.fire('ready');
    widget.focus();

    // Unlock snapshot and save new one, which will contain all changes done
    // in this method.
    editor.fire('unlockSnapshot');
    editor.fire('saveSnapshot');
  },

  insertNewWidget: function(editor, range, data, caption) {
    var widget = Drupal.dndck4.createNewWidget(editor, data, caption);
    Drupal.dndck4.insertWidget(widget, editor, range);
    widget.refreshAtom();
  },

  // Heavily inspired from CKE widget plugin's onBlockWidgetDrag().
  onLibraryAtomDrag: function (atomInfo) {
    var widget = this,
      finder = widget.repository.finder,
      locator = widget.repository.locator,
      liner = widget.repository.liner,
      editor = widget.editor,
      editable = editor.editable(),
      listeners = [],
      sorted = [],
      dropRange = null;
    var relations, locations, y;

    // Mark dragged widget for repository#finder.
    this.repository._.draggedWidget = widget;

    // Dropping into an empty CKEditor requires special logic.
    var editableHasContent = (editable.getFirst() != null);

    // Determine candidate drop locations.
    if (editableHasContent) {
      // Use the finder to harvest all possible drop locations.
      relations = finder.greedySearch();
    }
    else {
      // If no content yet, hardcode one single drop location, which is the
      // editable itself.
      var element = new CKEDITOR.dom.element(editable.$);
      relations = {0: {
        element: element,
        elementRect: element.getClientRect(),
        type: CKEDITOR.LINEUTILS_BEFORE
      }}
    }

    var eventBuffer = CKEDITOR.tools.eventsBuffer(50, function () {
      locations = locator.locate(relations);
      // There's only a single line displayed for D&D.
      sorted = locator.sort(y, 1);
      if (sorted.length) {
        liner.prepare(relations, locations);
        liner.placeLine(sorted[0]);
        liner.cleanup();
      }
      dropRange = finder.getRange(sorted[0]);
    });

    // Let's have the "dragging cursor" over entire editable.
    editable.addClass('cke_widget_dragging');

    // Cache mouse position so it is re-used in events buffer.
    listeners.push(editable.on('dragover', function (evt) {
      y = evt.data.$.clientY;
      eventBuffer.input();
    }));

    // Listen to the 'drop' event:
    // - on the editable div if the CKEditor is in "divarea" mode,
    // - on the iframe document if the CKEditor is in "iframe" mode.
    var dropElement = editable.isInline() ? editable : editor.document;
    // On Chrome, the 'drop' event on the iframe document does not catches drops
    // made outside the body content, which might be smaller than the iframe.
    // Temporarily extend its height so that the whole editor is a drop area.
    if (!editable.isInline()) {
      var previousMinHeight = editable.getStyle('min-height');
      var documentHeight = $(editor.document.$).height() + 'px';
      var bodyMargin = '(' + $(editable.$).css('marginTop') + ' + ' + $(editable.$).css('marginBottom') + ')';
      var height = 'calc( ' + documentHeight + ' - ' + bodyMargin + ' )';
      editable.setStyle('min-height', height);
    }
    // On drop, insert the atom and cleanup the events.
    listeners.push(dropElement.on('drop', function (evt) {
      evt.data.preventDefault();
      var range;
      if (dropRange && editableHasContent && !CKEDITOR.tools.isEmpty(liner.visible)) {
        range = dropRange;
      }
      else {
        // If no liner position was determined, insert at the end of the
        // editable.
        range = editor.createRange();
        range.moveToElementEditablePosition(editable, true);
      }
      Drupal.dndck4.insertWidget(widget, editor, range);
      widget.refreshAtom();
      cleanupDrag(true);
    }));

    // Prevent paste, so the new clipboard plugin will not double insert the Atom.
    listeners.push(editor.on('paste', function (evt) {
      return false;
    }));

    // On dragend (without drop), cleanup the events.
    listeners.push(CKEDITOR.document.on('dragend', function (evt) {
      cleanupDrag();
    }));

    // On dragleave, hide the liner.
    // @todo doesn't work, dragleave doesn't have a reliable implementation
    // across browsers...
//      listeners.push(editable.on('dragleave', function (evt) {
//        liner.hideVisible();
//        console.log('dragleave');
//      }));

    function cleanupDrag(dropped) {
      // Stop observing events.
      eventBuffer.reset();
      var l;
      while (l = listeners.pop()) {
        l.removeListener();
      }
      // Clean-up unused widget.
      if (!dropped) {
        widget.repository._.draggedWidget = null;
        widget.repository.destroy(widget, true);
      }
      // Clean-up all remaining lines.
      liner.hideVisible();
      // Clean-up custom cursor for editable.
      editable.removeClass('cke_widget_dragging');
      // Reset the min-height.
      if (!editable.isInline()) {
        editable.setStyle('min-height', previousMinHeight);
      }
    }
  },

  fetchExpandedContent: function (widget) {
    var data = widget.data;
    // Use a throwaway Drupal.ajax object to fetch the HTML. Using Drupal's Ajax
    // framework lets us retrieve out-of-band assets (JS, CSS) and attach
    // behaviors.
    var ajax = new Drupal.ajax('dnd-library', $('#dnd-library'), {
      url: Drupal.settings.basePath + Drupal.settings.pathPrefix + 'atom/ajax-widget-expand/' + data.sid + '?' + $.param({
        context: data.context,
        options: encodeURIComponent(data.options),
        align: data.align
      }),
      progress: {type: 'none'},
      // The call is triggered programmatically, this event is not used.
      event: 'dndck4_dummy_event',
      // Add the target for the insertRenderedAtom directly as a custom
      // property, this avoids passing the editor name and target ID through the
      // network roundtrip.
      dndck4_widget: widget
    });
    // Trigger the call manually.
    ajax.eventResponse(ajax.element);
  },

  /**
   * AJAX 'dndck4_cache_atom_metadatadata' command: cache metadata about atoms.
   */
  AjaxCacheAtomMetadata: function(ajax, response, status) {
    var atomInfo = response.data;
    if (Drupal.dnd.Atoms[atomInfo.sid]) {
      $.extend(true, Drupal.dnd.Atoms[atomInfo.sid], atomInfo);
    }
    else {
      Drupal.dnd.Atoms[atomInfo.sid] = atomInfo;
    }
  },

  /**
   * AJAX 'dndck4_expand_widget' command: replace the widget content with the
   * expanded HTML generated on the server_side.
   */
  AjaxExpandWidget: function(ajax, response, status) {
    var widget = ajax.dndck4_widget;
    var widgetElement = widget.element;

    // First, detach behaviors for the current embed.
    Drupal.detachBehaviors(widgetElement.$, response.settings || ajax.settings || Drupal.settings);

    // The caption was not sent over the network and is not part of the HTML we
    // received. Grab it before we replace the HTML, so that we can re-add it
    // after that.
    var caption = '';
    if (widget.editables.caption) {
      caption = widget.editables.caption.getHtml();

      if (caption == '') {
        caption = Drupal.dnd.Atoms[widget.data.sid].meta.legend || '';
      }
      widget.destroyEditable('caption');
    }

    // Merge the content of the new markup into the existing widget element,
    // that we want to keep in place.
    var newElement = CKEDITOR.dom.element.createFromHtml(response.data);
    // Take the classes of the outer div of the new markup.
    widgetElement.setAttribute('class', 'cke_widget_element ' + newElement.getAttribute('class'));
    // Replace the inner HTML.
    widgetElement.setHtml(newElement.getHtml());

    // Notify external scripts of new atom rendering.
    Drupal.dndck4.invokeCallbacks('AjaxExpandWidget', widget);

    // Initialize the new caption editable, and fill it with the previous
    // caption.
    widget.initEditable('caption', widget.definition.editables.caption);
    var captionElement = widget.editables.caption;
    captionElement.setHtml(caption);
    // Hide the editable if the "Use caption" checkbox is unchecked. This lets
    // us preserves the current caption in the HTML in case the checkbox is
    // checked back in the same editing session.
    if (!widget.data.usesCaption) {
      captionElement.setAttribute('style', 'display:none');
    }

    // Finally, re-attach behaviors on the newly inserted markup.
    Drupal.attachBehaviors(widgetElement.$, response.settings || ajax.settings || Drupal.settings);
  },

  /**
   * Returns the downcasted HTML for a widget.
   *
   * This is a marker tag that gets stored in the database, and is transformed:
   * - on edit, by the widget upcast step.
   * - on display, by the 'mee_scald_widgets' text filter on the PHP side.
   *
   * This is not a theme function, since the marker tag use for storage should
   * not be customized.
   *
   * @param {object} data
   *   The widget data.
   * @param {string} caption
   *   The widget caption.
   *
   * @returns {string}
   *   The downcasted HTML for the widget.
   */
  downcastedHtml: function(data, caption) {
    var html = '<div class="dnd-atom-wrapper" ' + Drupal.dndck4.implodeAttributes(Drupal.dndck4.attributesFromData(data)) + '>';
    if (data.usesCaption && caption) {
      html += '<div class="dnd-caption-wrapper">' + caption + '</div>';
    }
    else {
      // The div cannot be empty or it will be discarded by CKEditor.
      html += '<!-- scald embed -->';
    }
    html += '</div>';
    return html;
  },

  /**
   * Converts atoms embedded with the legacy (non-widget) scald plugin.
   *
   * @param {CKEDITOR.htmlParser.element} el
   *   The candidate element to convert. It will be replaced in the DOM by an
   *   element with the new widget markup.
   */
  convertLegacyEmbed: function (el) {
    if (el.name == 'div' && el.hasClass('dnd-atom-wrapper') && !el.attributes['data-scald-sid']
      && el.children[0] && el.children[0].type == CKEDITOR.NODE_ELEMENT && el.children[0].hasClass('dnd-drop-wrapper')) {
      var sas = el.children[0].getHtml();
      var data = Drupal.dnd.sas2array(sas);
      if (typeof data === 'undefined') {
        // Check for any markup that can be converted to sas first.
        sas = Drupal.dnd.htmlcomment2sas(sas);
        if (typeof sas !== 'undefined') {
          data = Drupal.dnd.sas2array(sas);
        }
      }
      if (typeof data === 'undefined') {
        // Remove the Atom Wrapper so we don't process it again.
        el.removeClass('dnd-atom-wrapper');
        // Remove the Drop wrapper so it doesn't process.
        el.children[0].removeClass('dnd-drop-wrapper');
      }
      else {
        // Grab the atom type and alignment.
        data.align = 'none';
        $.each(el.attributes['class'].split(/\s+/), function (index, item) {
          if (item.substr(0, 5) == 'type-') {
            data.type = item.substr(5);
          }
          else if (item.substr(0, 11) == 'atom-align-') {
            data.align = item.substr(11);
          }
        });
        // Grab the caption if present.
        var caption = '';
        data.usesCaption = false;
        if (el.children[1] && el.children[1].type == CKEDITOR.NODE_ELEMENT && el.children[1].hasClass('dnd-legend-wrapper')) {
          caption = el.children[1].getHtml();
          data.usesCaption = true;
        }
        // Replace the element with the markup for a downcasted widget.
        var html = Drupal.dndck4.downcastedHtml(data, caption);
        var newEl = CKEDITOR.htmlParser.fragment.fromHtml(html).children[0];
        el.replaceWith(newEl);
        el = newEl;
      }
    }
    return el;
  }

};

// Declare our custom commands for the AJAX framework.
Drupal.ajax.prototype.commands.dndck4_cache_atom_metadatadata = Drupal.dndck4.AjaxCacheAtomMetadata;
Drupal.ajax.prototype.commands.dndck4_expand_widget = Drupal.dndck4.AjaxExpandWidget;

})(jQuery);
