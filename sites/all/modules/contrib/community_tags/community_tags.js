(function ($) {
  Drupal.communityTags = {};

  Drupal.communityTags.checkPlain = function (text) {
    text = Drupal.checkPlain(text);
    return text.replace(/^\s+/g, '')
               .replace(/\s+$/g, '')
               .replace('\n', '<br />');
  }

  Drupal.communityTags.serialize = function (data, prefix) {
    prefix = prefix || '';
    var out = '';
    for (i in data) {
      var name = prefix.length ? (prefix +'[' + i +']') : i;
      if (out.length) out += '&';
      if (typeof data[i] == 'object') {
        out += Drupal.communityTags.serialize(data[i], name);
      }
      else {
        out += name +'=';
        out += encodeURIComponent(data[i]);
      }
    }
    return out;
  }

  Drupal.behaviors.communityTags = {
    attach: function(context) {
      // Note: all tag fields are autocompleted, and have already been initialized at this point.
      $('input.form-tags', context).once('form-tags', function () {
        // Hide submit buttons.
        $('input[type=submit]', this.form).hide();

        // Fetch settings.
        var nid = $('input[name=nid]', this.form).val();
        var o = Drupal.settings.communityTags['n_' + nid];
        var vid = $('input[name=vid]', this.form).val();
        var o = Drupal.settings.communityTags['n_' + nid]['v_' + vid];

        var sequence = 0;

        // Show the textfield and empty its value.
        var textfield = $(this).val('').css('display', 'inline');

        // Prepare the add Ajax handler and add the button.
        var addHandler = function () {
          // Send existing tags and new tag string.
          $.post(o.url, Drupal.communityTags.serialize({ sequence: ++sequence, tags: o.tags, add: textfield[0].value, token: o.token }), function (data) {
            // data = $.parseJson(data);
            if (data.status && sequence == data.sequence) {
              o.tags = data.tags;
              updateList();
            }
          });

          // Add tag to local list
          o.tags.push(textfield[0].value);
          o.tags.sort(function (a,b) { a = a.toLowerCase(); b = b.toLowerCase(); return (a>b) ? 1 : (a<b) ? -1 : 0; });
          updateList();

          // Clear field and focus it.
          textfield.val('').focus();
        };
        var button = $('<input type="button" class="form-button" value="'+ Drupal.communityTags.checkPlain(o.add) +'" />').click(addHandler);
        $(this.form).submit(function () { addHandler(); return false; });

        // Prepare the delete Ajax handler.
        var deleteHandler = function () {
          // Remove tag from local list.
          var i = $(this).attr('key');
          o.tags.splice(i, 1);
          updateList();

          // Send new tag list.
          $.post(o.url, Drupal.communityTags.serialize({ sequence: ++sequence, tags: o.tags, add: '', token: o.token }), function (data) {
            // data = $.parseJson(data);

            if (data.status && sequence == data.sequence) {
              o.tags = data.tags;
              updateList();
            }
          });

          // Clear textfield and focus it.
          textfield.val('').focus();
        };

        // Callback to update the tag list.
        function updateList() {
          list.empty();
          for (i in o.tags) {
            list.append('<li key="'+ Drupal.communityTags.checkPlain(i) +'">'+ Drupal.communityTags.checkPlain(o.tags[i]) +'</li>');
          }
          $("li", list).hover(
            function () {
              $(this).addClass('hover');
            },
            function () {
              $(this).removeClass('hover');
            }
          );
          $('li', list).click(deleteHandler);
        }

        // Create widget markup.
        // @todo theme this.
        var widget = $('<div class="tag-widget"><ul class="inline-tags clearfix"></ul></div>');
        textfield.before(widget);
        widget.append(textfield).append(button);
        var list = $('ul', widget);

        updateList();
      });
    }
  }
})(jQuery);