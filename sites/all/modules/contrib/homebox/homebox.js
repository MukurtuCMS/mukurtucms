(function ($) {
  Drupal.homebox = {
    config: {}
  };
  Drupal.behaviors.homebox = {
    attach: function (context) {
      var $homebox = $('#homebox:not(.homebox-processed)', context).addClass('homebox-processed');

      if ($homebox.length > 0) {
        // Find all columns
        Drupal.homebox.$columns = $homebox.find('div.homebox-column');
        Drupal.homebox.$page = $homebox;

        // Try to find the button to save homebox state.
        Drupal.homebox.$pageSave = $homebox.find('#homebox-save-form [type=submit]');

        // Equilize columns height
        Drupal.homebox.equalizeColumnsHeights();

        // Make columns sortable
        Drupal.homebox.$columns.sortable({
          items: '.homebox-portlet.homebox-draggable',
          handle: '.portlet-header',
          connectWith: Drupal.homebox.$columns,
          placeholder: 'homebox-placeholder',
          forcePlaceholderSize: true,
          over: function () {
            Drupal.homebox.equalizeColumnsHeights();
          },
          stop: function () {
            Drupal.homebox.equalizeColumnsHeights();
            Drupal.homebox.pageChanged();
          }
        });

        $homebox.find('#homebox-add-link').click(function () {
          $(this).toggleClass('active');
          $homebox.find('#homebox-add').toggle();
        });

        // Populate hidden form element with block order and values.
        Drupal.homebox.$pageSave.mousedown(function () {
          var blocks = {}, regionIndex;
          Drupal.homebox.$columns.each(function () {
            // Determine region out of column-id.
            regionIndex = $(this).attr('id').replace(/homebox-column-/, '');
            $(this).find('.homebox-portlet').each(function (boxIndex) {
              var $this = $(this),
                color = 'default';

              // Determine custom color, if any
              $.each($this.attr('class').split(' '), function (key, a) {
                if (a.substr(0, 14) === 'homebox-color-') {
                  color = a.substr(14);
                }
              });

              // Build blocks object
              blocks[$this.attr('id').replace(/^homebox-block-/, '')] = $.param({
                region: regionIndex,
                status: $this.is(':visible') ? 1 : 0,
                color: color,
                open: $this.find('.portlet-content').is(':visible') ? 1 : 0
              });
            });
          });

          $(this).siblings('[name=blocks]').attr('value', $.param(blocks));
          $('#homebox-changes-made').hide();
        });

        // Equalize column heights after AJAX calls
        $homebox.ajaxStop(function () {
          Drupal.homebox.equalizeColumnsHeights();
        });
      }
    }
  };

  /**
   * Set all column heights equal
   */
  Drupal.homebox.equalizeColumnsHeights = function () {
    var maxHeight = {}, row;
    Drupal.homebox.$columns.each(function () {
      row = $(this).parent('.homebox-column-wrapper').attr('class').match(/homebox-row-(\d+)/i)[1];
      $(this).height('auto');
      maxHeight[row] = maxHeight[row] ? Math.max($(this).height(), maxHeight[row]) : $(this).height();
    }).each(function () {
      row = $(this).parent('.homebox-column-wrapper').attr('class').match(/homebox-row-(\d+)/i)[1];
      $(this).height(maxHeight[row]);
    });
  };

  Drupal.homebox.maximizeBox = function (icon) {
    // References to active portlet and its homebox
    var portlet = $(icon).parents('.homebox-portlet');
    var homebox = $(icon).parents('#homebox');

    // Only fire this action if this widget isnt being dragged
    if (!$(portlet).hasClass('ui-sortable-helper')) {
      // Check if we're maximizing or minimizing the portlet
      if ($(portlet).hasClass('portlet-maximized')) {
        // Minimizing portlet

        // Move this portlet to its original place (remembered with placeholder)
        $(portlet).insertBefore($(homebox).find('.homebox-maximized-placeholder'))
          .toggleClass('portlet-maximized');

        // Remove placeholder
        $(homebox).find('.homebox-maximized-placeholder').remove();

        // Show columns again
        $(homebox).find('.homebox-column').show();

        // Show close icon again
        $(portlet).find('.portlet-close').show();

        // Show the save button
        $('#homebox-save-form .form-submit').show();
        $('#homebox-minimize-to-save').hide();

        // Restore the checkbox under "Edit Content"
        $('input#homebox_toggle_' + $(portlet).attr('id')).removeAttr('disabled');
      }
      else {
        // Maximizing portlet

        // Add the portlet to maximized content place and create a placeholder
        // (for minimizing back to its place)
        $(portlet)
          .before('<div class="homebox-maximized-placeholder"></div>')
          .appendTo($(icon).parents('#homebox').find('.homebox-maximized'))
          .toggleClass('portlet-maximized');

        // Hide columns - only show maximized content place (including maximized widget)
        $(homebox).find('.homebox-column').hide();

        // Hide close icon (you wont be able to return if you close the widget)
        $(portlet).find('.portlet-close').hide();

        // Hide the save button
        $('#homebox-save-form .form-submit').hide();
        $('#homebox-minimize-to-save').show();

        // Disable the checkbox under "Edit content"
        $('input#homebox_toggle_' + $(portlet).attr('id')).attr('disabled', 'disabled');
      }
    }
  };

  Drupal.homebox.pageChanged = function () {
    if (Drupal.homebox.$page.hasClass('homebox-auto-save')) {
      Drupal.homebox.$pageSave.mousedown().click();
    }
    else {
      $('#homebox-changes-made').show();
    }
  };

  Drupal.homebox.hexColor = function (rgb) {
    // Handle hex strings like: #CCCCCC, #CCC, CCCCCC, CCC
    hexval = rgb.match(/^(#)?(\w{3})(\w{2})?$/);
    if (hexval) {
      return (!hexval[1] ? "#" + hexval[0] : hexval[0]);
    }

    rgb = rgb.match(/^rgba?\((\d+),\s*(\d+),\s*(\d+)(?:,\s*(\d+))?\)$/);
    function hex(x) {
        return ("0" + parseInt(x).toString(16)).slice(-2);
    }
    return "#" + hex(rgb[1]) + hex(rgb[2]) + hex(rgb[3]);
  };

  Drupal.behaviors.homeboxPortlet = {
    attach: function (context) {
      $('.homebox-portlet:not(.homebox-processed)', context).addClass('homebox-processed').each(function () {
        var $portlet = $(this),
          $portletHeader = $portlet.find('.portlet-header'),
          $portletSettings = $portlet.find('.portlet-settings'),
          $portletConfig = $portlet.find('.portlet-config');

        // Restore classes saved before AHAH, they back some page-wide
        // settings.
        if (Drupal.homebox.config[$portlet.attr('id')] !== undefined) {
          $portlet.attr('class', Drupal.homebox.config[$portlet.attr('id')]);
        }

        // Prevent double-clicks from causing a selection
        $portletHeader.disableSelection();

        // Attach click event to maximize icon
        $portletHeader.find('.portlet-maximize').click(function () {
          $(this).toggleClass('portlet-maximize').toggleClass('portlet-minimize');
          Drupal.homebox.maximizeBox(this);
          Drupal.homebox.equalizeColumnsHeights();
        });

        // Attach click event on minus
        $portletHeader.find('.portlet-minus').click(function () {
          $(this).toggleClass('portlet-minus').toggleClass('portlet-plus');
          $portlet.find('.portlet-content').toggle();
          Drupal.homebox.equalizeColumnsHeights();
          Drupal.homebox.pageChanged();
        })
        .each(function () {
          if (!$portlet.find('.portlet-content').is(':visible')) {
            $(this).toggleClass('portlet-minus').toggleClass('portlet-plus');
            Drupal.homebox.equalizeColumnsHeights();
          }
        });

        // Attach double click event on portlet header
        $portlet.find('.portlet-title').dblclick(function () {
          if ($portlet.find('.portlet-content').is(':visible')) {
            $portletHeader.find('.portlet-minus').toggleClass('portlet-plus').toggleClass('portlet-minus');
          }
          else {
            $portletHeader.find('.portlet-plus').toggleClass('portlet-minus').toggleClass('portlet-plus');
          }
          $portlet.find('.portlet-content').toggle();

          Drupal.homebox.equalizeColumnsHeights();
          Drupal.homebox.pageChanged();
        });

        // Attach click event on settings icon
        $portletSettings.click(function () {
          $portletConfig.toggle();
          Drupal.homebox.equalizeColumnsHeights();
        });
        // Show settings if there are error messages
        if ($portletConfig.find('>.messages').length) {
          $portletSettings.trigger('click');
        }
        // Save classes on submit
        $portletConfig.find('.form-submit').click(function () {
          Drupal.homebox.config[$portlet.attr('id')] = $portlet.attr('class');
        });

        // Attach click event on close
        $portletHeader.find('.portlet-close').click(function () {
          $portlet.hide();
          Drupal.homebox.equalizeColumnsHeights();
          Drupal.homebox.pageChanged();
        });

        $.each($portlet.attr('class').split(' '), function (key, a) {
          if (a.substr(0, 14) === 'homebox-color-') {
            $portletHeader.attr('style', 'background: #' + a.substr(14));
            $portlet.find('.homebox-portlet-inner').attr('style', 'border: 1px solid #' + a.substr(14));
          }
        });

        // Add click behaviour to color buttons
        $portlet.find('.homebox-color-selector').click(function () {
          var color = $(this).css('background-color');
          color = Drupal.homebox.hexColor(color);

          $.each($portlet.attr('class').split(' '), function (key, value) {
            if (value.indexOf('homebox-color-') === 0) {
              $portlet.removeClass(value);
            }
          });

          // Add color classes to blocks
          // This is used when we save so we know what color it is
          $portlet.addClass('homebox-color-' + color.replace('#', ''));

          // Apply the colors via style attributes
          // This avoid dynamic CSS
          $portletHeader.attr('style', 'background: ' + color);
          $portlet.find('.homebox-portlet-inner').attr('style', 'border: 1px solid ' + color);
          Drupal.homebox.pageChanged();
        });
      });
    }
  };
})(jQuery);
