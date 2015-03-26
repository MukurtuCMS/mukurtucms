/**
 * @file
 *   Provides the JavaScript behaviors for the Atom Reference field.
 */
(function($) {
Drupal.behaviors.atom_reference = {
  attach: function(context) {
    $("div.atom_reference_drop_zone:not(.atom_reference_processed)").each(function() {
      var $this = $(this);
      var $reset = $("<input type='button' />")
        .val(Drupal.t('Delete'))
        .click(function() {
          $(this)
            .hide()
            .closest('div.form-item')
            .find('input:text')
            .val('')
            .end()
            .find('div.atom_reference_drop_zone')
            .empty()
            .append(Drupal.t('Drop a resource here'))
        });
      // If the element doesn't have a value yet, hide the Delete button
      // by default
      if (!$this.closest('div.form-item').find('input:text').val()) {
        $reset.css('display', 'none');
      }
      $this
        .addClass('atom_reference_processed')
        .bind('dragover', function(e) {e.preventDefault();})
        .bind('dragenter', function(e) {e.preventDefault();})
        .bind('drop', function(e) {
          var dt = Drupal.dnd.currentAtom.replace(/^\[scald=(\d+).*$/, '$1');
          var ret = Drupal.atom_reference.droppable(dt, this);
          var $this = $(this);
          if (ret.found && ret.keepgoing) {
            var context = $this.closest('div.form-item').find('input:text').data('dnd-context');
            Drupal.dnd.fetchAtom(context, dt, function() {
              $this
                .empty()
                .append(Drupal.dnd.Atoms[dt].contexts[context])
                .closest('div.form-item')
                .find('input:text')
                .val(dt)
                .end()
                .find('input:button')
                .show();
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
        .append($reset);
    });
  }
}

if (!Drupal.atom_reference) {
  Drupal.atom_reference = {};
  Drupal.atom_reference.droppable = function(ressource_id, field) {
    var retVal = {'keepgoing': true, 'found': true};
    if (Drupal.dnd.Atoms[ressource_id]) {
      var type = Drupal.dnd.Atoms[ressource_id].meta.type;
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
