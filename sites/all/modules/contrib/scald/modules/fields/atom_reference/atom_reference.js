/**
 * @file
 *   Provides the JavaScript behaviors for the Atom Reference field.
 */
(function($) {

  var $edit_link_model = $('<a target="_blank">')
    .addClass('ctools-use-modal ctools-modal-custom-style atom-reference-edit');
  var $view_link_model = $('<a target="_blank">')
    .addClass('atom-reference-view');

Drupal.behaviors.atom_reference = {
  attach: function(context, settings) {
    var this_behavior_attach = this;

    $edit_link_model.html(Drupal.t('Edit'));
    $view_link_model.html(Drupal.t('View'));

    // Record if the edit target link modal frame is updated
    $('.ctools-modal-content form', context).bind('formUpdated', function() {
      this_behavior_attach['update_atom_reference_drop_zone'] = true;
    });

    // Update drop zone (especially when returning from the edit modal frame).
    if (typeof(this.update_atom_reference_drop_zone) !== 'undefined') {
      this.update_atom_reference_drop_zone = undefined;
      $('div.atom_reference_drop_zone.atom_reference_processed', context).each(function() {
        var $this = $(this);
        var rendering_context = $this.attr('data-rendering-context');
        var match_atom_id = /<!-- scald=(\d+):.*-->/g.exec($this.html());
        if (match_atom_id) {
          var atom_id = match_atom_id[1];
          delete Drupal.dnd.Atoms[atom_id].contexts[rendering_context]; // to force reload
          Drupal.dnd.fetchAtom(rendering_context, atom_id, function() {
            Drupal.detachBehaviors($this);
            $this
              .empty()
              .append(Drupal.dnd.Atoms[atom_id].contexts[rendering_context]);
            Drupal.attachBehaviors($this);
          });
        }
      });
    }

    $("div.atom_reference_drop_zone:not(.atom_reference_processed)", context).each(function() {
      var $this = $(this);
      var $context = $this.closest('div.form-item').parent().find('.context-select').closest('div.form-item');

      // Build operations (remove reference, edit and view) structure.
      var $operation_wrapper = $('<div class="atom_reference_operations">');
      var $operation_buttons = $('<div id="ctools-button-0" class="buttons ctools-no-js ctools-button">')
        .append('<div class="ctools-link"><a href="#" class="ctools-twisty ctools-text"><span class="element-invisible">' + Drupal.t('Operation') + '</span></a></div>')
        .append('<div class="ctools-content"><ul><li class="edit"><li class="remove"><li class="view"></ul></div>')
        .prependTo($operation_wrapper);

      // Add the remove link
      $('<a href="#" />')
        .html(Drupal.t('Remove'))
        .click(function(e) {
          e.preventDefault();
          var $formItem = $operation_buttons.closest('div.form-item');
          $formItem
            .find('input:text')
            .val('')
            .change();
          var $dropZone = $formItem.find('div.atom_reference_drop_zone');
          Drupal.detachBehaviors($dropZone.children());
          $dropZone
            .empty()
            .append(Drupal.t('Drop a resource from Scald media library here.'));
          $formItem.find('div.atom_reference_operations')
            .hide();
          atomReferenceSetContext($context, 0);
        })
        .appendTo($operation_buttons.find('li.remove'));

      var match_atom_id = /<!-- scald=(\d+):.*-->/g.exec($this.html());
      if (match_atom_id) {
        var atom_id = match_atom_id[1];

        Drupal.dnd.fetchAtom('', atom_id, function() {

          // Add the edit link
          if ($.grep(Drupal.dnd.Atoms[atom_id].actions, function(e){ return e == 'edit'; }).length > 0) {
            // Permission granted for edit

            $edit_link_model.clone()
              .attr('href', settings.basePath + settings.pathPrefix + 'atom/' + atom_id + '/edit/nojs')
              .appendTo($operation_buttons.find('li.edit'));
            Drupal.behaviors.ZZCToolsModal.attach($operation_buttons);
            $operation_buttons.addClass('ctools-dropbutton');
          }

          // Add the view link
          if ($.grep(Drupal.dnd.Atoms[atom_id].actions, function(e){ return e == 'view'; }).length > 0) {
            // Permission granted for view

            $view_link_model.clone()
              .attr('href', settings.basePath + settings.pathPrefix + 'atom/' + atom_id)
              .appendTo($operation_buttons.find('li.view'));
            $operation_buttons.addClass('ctools-dropbutton');
          }

          Drupal.attachBehaviors($operation_buttons);
          atomReferenceSetContext($context, atom_id);
        });
      }
      else {
        atomReferenceSetContext($context, 0);
      }

      // If the element doesn't have a value yet, hide the operations wrapper
      // by default
      if (!$this.closest('div.form-item').find('input:text').val()) {
        $operation_wrapper.css('display', 'none');
      }
      $this
        .addClass('atom_reference_processed')
        .bind('dragover', function(e) {e.preventDefault();})
        .bind('dragenter', function(e) {e.preventDefault();})
        .bind('drop', function(e) {
          if (!Drupal.dnd.currentAtom) {
            // Not an atom drop.
            return;
          }
          var resource_id = Drupal.dnd.sas2array(Drupal.dnd.currentAtom).sid;
          var ret = Drupal.atom_reference.droppable(resource_id, this);
          var $this = $(this);

          if (ret.found && ret.keepgoing) {
            var rendering_context = $this.attr('data-rendering-context');

            // Display and set id of dropped atom
            Drupal.dnd.fetchAtom(rendering_context, resource_id, function() {
              $this
                .empty()
                .append(Drupal.dnd.Atoms[resource_id].contexts[rendering_context])
                .closest('div.form-item')
                .find('input:text')
                .val(resource_id)
                .change()
                .end()
                .find('.atom_reference_operations')
                .show();

              // Process atom's operation links (edit and view) rendering
              var $operation_buttons = $this.closest('.form-item')
                .find('.atom_reference_operations').show()
                .find('.buttons');
              $operation_buttons
                .removeClass('ctools-dropbutton')
                .removeClass('ctools-dropbutton-processed')
                .removeClass('ctools-button-processed')
                .find('li.edit, li.view').empty();

              // Process Edit link
              if ($.grep(Drupal.dnd.Atoms[resource_id].actions, function(e){ return e == 'edit'; }).length > 0) {
                // Permission granted for edit

                var atom_edit_link = settings.basePath + settings.pathPrefix + 'atom/' + resource_id + '/edit/nojs';
                $edit_link_model.clone()
                  .attr('href', atom_edit_link)
                  .appendTo($operation_buttons.find('li.edit'));
                Drupal.behaviors.ZZCToolsModal.attach($operation_buttons);
                $operation_buttons.addClass('ctools-dropbutton');
              }

              // Process View link
              if ($.grep(Drupal.dnd.Atoms[resource_id].actions, function(e){ return e == 'view'; }).length > 0) {
                // Permission granted for view

                var atom_view_link = settings.basePath + settings.pathPrefix + 'atom/' + resource_id;
                $view_link_model.clone()
                  .attr('href', atom_view_link)
                  .appendTo($operation_buttons.find('li.view'));
                $operation_buttons.addClass('ctools-dropbutton')
              }
              atomReferenceSetContext($context, resource_id);
              Drupal.attachBehaviors($this);
            });
          }
          else {
            var placeholder = Drupal.t("You can't drop a resource of type %type in this field", {'%type': ret.type});
            $this.empty().append(placeholder);
          }
          e.stopPropagation();
          e.preventDefault();

          return false;
        })
        .closest('div.form-item')
        .find('input')
        .css('display', 'none')
        .end()
        .append($operation_wrapper);
    });
  }
};

function atomReferenceSetContext($context, sid) {
  if ($context.length == 0) {
    return false;
  }
  if ( typeof Drupal.dnd.Atoms[sid] !== "undefined" && Drupal.dnd.Atoms[sid]) {
    $context.show();

    var atom_type = Drupal.dnd.Atoms[sid].meta.type;

    if (typeof Drupal.settings.dnd.contexts[atom_type] !== "undefined" && Drupal.settings.dnd.contexts[atom_type]) {
      var scald_context = $context.find('select.context-select').val();

      $context.find('select.context-select').find('option[value!="use_the_default"]').remove();

      $.each( Drupal.settings.dnd.contexts[atom_type], function( key, value ) {
        $context.find('select.context-select').append(
          new Option(value, key)
        );
      });

      // Triggering chosen:updated in case chosen is used on this list.
      $context.find('select.context-select').val(scald_context).change().trigger('chosen:updated');
    }
  }
  else {
    $context.hide();
  }
}

if (!Drupal.atom_reference) {
  Drupal.atom_reference = {};
  Drupal.atom_reference.droppable = function(resource_id, field) {
    var retVal = {'keepgoing': true, 'found': true};
    if (Drupal.dnd.Atoms[resource_id]) {
      var type = Drupal.dnd.Atoms[resource_id].meta.type;
      var accept = $(field).closest('div.form-item').find('input:text').data('types').split(',');
      if (jQuery.inArray(type, accept) == -1) {
        retVal.keepgoing = false;
      }
      retVal.type = type;
    }
    else {
      retVal.found = false;
    }
    return retVal;
  }
}
})(jQuery);
