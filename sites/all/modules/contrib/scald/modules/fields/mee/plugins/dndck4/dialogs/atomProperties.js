(function($) {

CKEDITOR.dialog.add('atomProperties', function(editor) {
  var lang = editor.lang.dndck4;

  function showHideOptions(ctx) {
    var dialog = ctx.getDialog(),
      context = ctx.getValue(),
      config = Drupal.settings.dnd.contexts_config[context],
      widget = editor.widgets.focused,
      atom = Drupal.dnd.Atoms[widget.data.sid],
      type = atom.meta.type,
      provider = atom.meta.provider;

    $.each(Drupal.dndck4.registeredOptions, function(){
      if ((this.mode == 'atom' && this.name == provider) ||
          (this.mode == 'player' && this.type == type && this.name == config.player[type]['*']) ||
          (this.mode == 'context' && this.type == type && this.name == context)) {
        dialog.getContentElement('info', this.id).getElement().show();
      }
      else {
        dialog.getContentElement('info', this.id).getElement().hide();
      }
    });
  }

  return {
    title: lang.atom_properties,
    minWidth: 420,
    minHeight: 360,
    contents: [
      {
        id: 'info',
        label: lang.tab_info,
        title: '',
        expand: true,
        padding: 0,
        elements: [
          {
            id: 'cmbContext',
            type: 'select',
            label: lang.properties_context,
            items: [],
            setup: function(widget) {
              // Populate the available context options for the atom type.
              this.clear();
              var type = Drupal.dnd.Atoms[widget.data.sid].meta.type;
              for (var context in Drupal.settings.dnd.contexts[type]) {
                this.add(Drupal.settings.dnd.contexts[type][context], context);
              }
              this.setValue(widget.data.context);
            },
            onChange: function(ev){
              showHideOptions(this);
            },
            commit: function(widget) {
              widget.setData('context', this.getValue());
            }
          },
          {
            id: 'cmbAlign',
            type: 'select',
            label: lang.properties_alignment,
            items: [ [lang.alignment_none, 'none'],
                     [lang.alignment_left, 'left'],
                     [lang.alignment_right, 'right'],
                     [lang.alignment_center, 'center'] ],
            setup: function(widget) {
              this.setValue(widget.data.align);
            },
            commit: function(widget) {
              widget.setData('align', this.getValue());
            }
          },
          {
            id: 'chkCaption',
            type: 'checkbox',
            label: lang.properties_has_caption,
            setup: function(widget) {
              this.setValue(widget.data.usesCaption);
            },
            commit: function(widget) {
              widget.setData('usesCaption', this.getValue());
            }
          }
        ]
      },
      {
        id: 'advanced',
        label: lang.tab_advanced,
        title: '',
        expand: true,
        padding: 0,
        elements: [
          {
            id: 'txtClasses',
            type: 'text',
            label: lang.properties_classes,
            setup: function(widget) {
              var options = JSON.parse(widget.data.options);
              if (options.additionalClasses) {
                this.setValue(options.additionalClasses);
              }
            },
            commit: function(widget) {
              var options = JSON.parse(widget.data.options);
              options.additionalClasses = this.getValue();
              widget.setData('options', JSON.stringify(options));
            }
          }
        ]
      }
    ]
  };
});

})(jQuery);
