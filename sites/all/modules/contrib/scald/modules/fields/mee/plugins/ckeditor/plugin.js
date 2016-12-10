(function ($, dnd) {
if (typeof dnd === 'undefined') {
  CKEDITOR.plugins.add('dnd', {});
  return;
}

dnd.atomCut = null;
dnd.atomCurrent = null;

/**
 * Prevents atom from being edited inside the editor.
 */
dnd.protectAtom = function(element) {
  element
    .attr('contentEditable', false)
    // Allows atom legend to be edited inside the editor.
    .find('.dnd-legend-wrapper').attr('contentEditable', true)
    .trigger('onAtomProtect');
}

dnd.getWrapperElement = function(element) {
  while (element && !(element.type === CKEDITOR.NODE_ELEMENT && element.hasClass('dnd-atom-wrapper'))) {
    element = element.getParent();
  }
  if (element) {
    this.protectAtom($(element.$));
    this.atomCurrent = element;
  }
  return element;
};

CKEDITOR.plugins.add('dnd', {
  lang: 'en',
  requires: 'dialog,menu,htmlwriter',

  onLoad: function() {
  },

  init: function (editor) {

    // Assign the "insert atom into editor" method to be used for this editor.
    editor.dndInsertAtom = function(sid) {
      var atom = Drupal.dnd.sas2array(Drupal.dnd.Atoms[sid].sas);
      var markup = Drupal.theme('scaldEmbed', Drupal.dnd.Atoms[sid], atom.context, atom.options);
      editor.insertElement(CKEDITOR.dom.element.createFromHtml(markup));
    };

    var path = this.path;
    editor.on('mode', function (evt) {
      var editor = evt.editor;
      if (editor.mode == 'wysiwyg') {
        editor.document.appendStyleSheet(path + '../../css/editor.css');
        editor.document.appendStyleSheet(path + '../../css/editor-global.css');
        dnd.protectAtom($(editor.document.$).find('.dnd-atom-wrapper'));

        if (editor && editor.element && editor.element.$ && editor.element.$.attributes['data-dnd-context']) {
          var context = editor.element.$.attributes['data-dnd-context'].value;
          Drupal.settings.dnd.contextDefault = context;
        }
      }
    });

    CKEDITOR.dialog.add('atomProperties', this.path + 'dialogs/dnd.js' );

    editor.addCommand('atomProperties', new CKEDITOR.dialogCommand('atomProperties', {
      allowedContent: 'div[*](*);iframe[*];img(*);object[*];param[*]'
    }));

    editor.addCommand('atomDelete', {
      exec: function (editor) {
        dnd.atomCurrent.remove();
      },
      canUndo: false,
      editorFocus: CKEDITOR.env.ie || CKEDITOR.env.webkit
    });

    editor.addCommand('atomCut', {
      exec: function (editor) {
        dnd.atomCut = dnd.atomCurrent;
        dnd.atomCurrent.remove();
      },
      canUndo: false,
      editorFocus: CKEDITOR.env.ie || CKEDITOR.env.webkit
    });

    editor.addCommand('atomPaste', {
      exec: function (editor) {
        editor.insertElement(dnd.atomCut);
        dnd.atomCut = null;
      },
      canUndo: false,
      editorFocus: CKEDITOR.env.ie || CKEDITOR.env.webkit
    });

    editor.addCommand('atomView', {
      exec: function (editor) {
        var data = Drupal.dnd.atomCurrent.getChild(0).getHtml()
          .replace(/<!--\{cke_protected\}\{C\}([\s\S]+?)-->.*/, function(match, data) {
            return decodeURIComponent(data);
          })
          .replace(/^<!--\s+scald=(.+?)\s+-->[\s\S]*$/, '$1');
        var sid = data.split(':', 1)[0];
        window.open(Drupal.settings.basePath + Drupal.settings.pathPrefix + 'atom/' + sid);
      }
    });

    editor.addCommand('atomEdit', {
      exec: function (editor) {
        var data = Drupal.dnd.atomCurrent.getChild(0).getHtml()
          .replace(/<!--\{cke_protected\}\{C\}([\s\S]+?)-->.*/, function(match, data) {
            return decodeURIComponent(data);
          })
          .replace(/^<!--\s+scald=(.+?)\s+-->[\s\S]*$/, '$1');
        var sid = data.split(':', 1)[0];
        var $wrapper = $("<div></div>", {
          'class' : 'wysiwyg-atom-edit-wrapper'
        });
        var $link = $("<a></a>", {
          'target' : '_blank',
          'href' : Drupal.settings.basePath + Drupal.settings.pathPrefix + 'atom/' + sid + '/edit/nojs',
          'class' : 'ctools-use-modal ctools-modal-custom-style'
        }).appendTo($wrapper);
        Drupal.behaviors.ZZCToolsModal.attach($wrapper);
        $link.click();
      }
    });

    // Register the toolbar button.
    editor.ui.addButton && editor.ui.addButton('ScaldAtom', {
      label: editor.lang.dnd.atom_properties,
      command: 'atomProperties',
      icon: this.path + 'icons/atom.png'
    });

    editor.on('contentDom', function (evt) {
      editor.document.on('drop', function (evt) {
        var atom = Drupal.dnd.sas2array(evt.data.$.dataTransfer.getData('Text'));
        if (atom && Drupal.dnd.Atoms[atom.sid]) {
          var context = editor.element.$.attributes['data-dnd-context'].value;
          Drupal.dnd.fetchAtom(context, atom.sid, function() {
            var markup = Drupal.theme('scaldEmbed', Drupal.dnd.Atoms[atom.sid], context, atom.options);
            editor.insertElement(CKEDITOR.dom.element.createFromHtml(markup));
          });
          evt.data.preventDefault();
        }
        dnd.protectAtom($(editor.document.$).find('.dnd-atom-wrapper'));
      });

      // Prevent paste, so the new clipboard plugin will not double insert the Atom.
      editor.on('paste', function (evt) {
        if (typeof evt.data.dataTransfer !== 'undefined' && Drupal.dnd.sas2array(evt.data.dataTransfer.getData('Text'))) {
          return false;
        }
      });

      editor.document.on('click', function (evt) {
        var element = dnd.getWrapperElement(evt.data.getTarget());
        if (element) {
        }
      });

      editor.document.on('mousedown', function (evt) {
        var element = evt.data.getTarget();
        if (element.is('img')) {
          element = dnd.getWrapperElement(element);
          if (element) {
            evt.cancel();
            //evt.data.preventDefault(true);
          }
        }
      });
    });

    editor.addMenuGroup('dnd');
    editor.addMenuItems({
      atomproperties: {
        label: editor.lang.dnd.atom_properties,
        command: 'atomProperties',
        group: 'dnd'
      },
      atomview : {
        label: editor.lang.dnd.atom_view,
        command: 'atomView',
        group: 'dnd'
      },
      atomedit : {
        label: editor.lang.dnd.atom_edit,
        command: 'atomEdit',
        group: 'dnd'
      },
      atomdelete: {
        label: editor.lang.dnd.atom_delete,
        command: 'atomDelete',
        group: 'dnd'
      },
      atomcut: {
        label: editor.lang.dnd.atom_cut,
        command: 'atomCut',
        icon: 'cut',
        group: 'dnd'
      },
      atompaste: {
        label: editor.lang.dnd.atom_paste,
        command: 'atomPaste',
        icon: 'paste',
        group: 'dnd'
      }
    });

    editor.contextMenu.addListener(function (element, selection) {
      var menu = {};
      element = dnd.getWrapperElement(element);
      if (element) {
        menu.atomproperties = CKEDITOR.TRISTATE_OFF;
        menu.atomview = CKEDITOR.TRISTATE_OFF;
        menu.atomedit = CKEDITOR.TRISTATE_OFF;
        menu.atomdelete = CKEDITOR.TRISTATE_OFF;
        menu.atomcut = CKEDITOR.TRISTATE_OFF;
        editor.contextMenu.items = [];
      }
      else if (dnd.atomCut) {
        menu.atompaste = CKEDITOR.TRISTATE_OFF;
        for (var index in editor.contextMenu.items) {
          if (editor.contextMenu.items[index].name == 'paste') {
            editor.contextMenu.items.splice(index, 1);
          }
        }
      }
      return menu;
    });

    editor.on('doubleclick', function(evt) {
      var element = dnd.getWrapperElement(evt.data.element);
      if (element) {
        evt.data.dialog = 'atomProperties';
      }
    });

    editor.on('paste', function (evt) {
    });
  },

  afterInit: function (editor) {
  }
});
})(jQuery, Drupal.dnd);
