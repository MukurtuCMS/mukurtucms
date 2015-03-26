Drupal.media_plupload = {};
Drupal.media_plupload.popup = false;
Drupal.media_plupload.fids = [];

(function ($){
  Drupal.ajax.prototype.beforeSubmit = function (form_values, element, options) {
    if (Drupal.media_plupload.popup) {
      field_name = options.extraData._triggering_element_name.replace(/_add_more/, '');
      regex = new RegExp('^' + field_name + '\\[([a-z]+)\\]\\[(\\d+)\\]\\[fid\\]$');
      max = -1;
      max_id = 0;
      for(i in form_values) {
       if (match = form_values[i].name.match(regex)) {
         lang = match[1];
         delta = parseInt(match[2]);
         if (delta > max) {
           max = delta;
           max_id = i;
         }
       }
      }
      if (Drupal.media_plupload.fids.length > 0) {
       form_values[max_id].value = Drupal.media_plupload.fids.pop();
      }
      for (i in Drupal.media_plupload.fids) {
       max++;
       form_values.push({name : field_name + '[' + lang + '][' + max + '][fid]', value : Drupal.media_plupload.fids[i]});
       form_values.push({name : field_name + '[' + lang + '][' + max + '][_weight]', value : max});
      }
      Drupal.media_plupload.popup = false;
      Drupal.media_plupload.fids = [];
    }
  }

  Drupal.behaviors.media_plupload = {
    attach : function (context, settings) {
      $('.media_plupload_add_more', context).once('media_plupload', function () {
        var addMoreButton = $(this).hide();
        var addMoreId = addMoreButton.attr('id');
        var id = addMoreId + '-plupload';
        // Use "Add another" as the button text if there are already files uploaded.
        var existingUploads = $(this).parents('.field-widget-media-plupload').find('.field-multiple-table tbody tr');
        var value = existingUploads.length > 1 ? addMoreButton.val() : Drupal.t('Add media'); // The table always contains at least one row.
        var button = $('<input type="button" id="' + id + '" class="field-add-more-submit media-plupload-add-more-submit form-submit" value="' + value + '">');
        button.insertAfter(this).click(function () {
          Drupal.media.popups.mediaBrowser(function (mediaFiles) {
            for (i in mediaFiles) {
              Drupal.media_plupload.fids.push(mediaFiles[i].fid);
            }
            Drupal.media_plupload.popup = true;
            addMoreButton.trigger('mousedown');
          }, {multiselect : 'true'});
        });
      });
      $('.field-widget-media-plupload input.fid').each(function () {
        if ($(this).val() === '0') {
          $(this).parents('tr').hide();
        }
      });
    }
  }
})(jQuery);
