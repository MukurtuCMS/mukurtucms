(function ($) {

  /**
   * Attaches the autocomplete behavior to all required fields.
   */
  Drupal.behaviors.autocomplete = {
    attach: function (context) {
      var $context = $(context);
      var acdb = [];
      $context.find('input.autocomplete').once('autocomplete', function () {
        var uri = this.value;
        if (!acdb[uri]) {
          acdb[uri] = new Drupal.ACDB(uri);
        }
        var $input = $context.find('#' + this.id.substr(0, this.id.length - 13))
          .attr('autocomplete', 'OFF')
          .attr('aria-autocomplete', 'list');
        $context.find($input[0].form).submit(Drupal.autocompleteSubmit);
        $input.parents('.form-item')
          .attr('role', 'application')
          .append($('<span class="element-invisible" aria-live="assertive"></span>')
            .attr('id', $input.attr('id') + '-autocomplete-aria-live')
          );
        new Drupal.jsAC($input, acdb[uri], $context);
      });
    }
  };

  /**
   * Prevents the form from submitting if the suggestions popup is open
   * and closes the suggestions popup when doing so.
   */
  Drupal.autocompleteSubmit = function () {
    // NOTE: Do not return true as this is non-standard. Keep it similar to
    // core. If another contrib project alters this functionality, then it is
    // the responsibility of a sub-theme to override this method and combine
    // this project with the other project.
    return $('.form-autocomplete > .dropdown').each(function () {
      this.owner.hidePopup();
    }).length == 0;
  };

  /**
   * Highlights a suggestion.
   */
  Drupal.jsAC.prototype.highlight = function (node) {
    if (this.selected) {
      $(this.selected).removeClass('active');
    }
    $(node).addClass('active');
    this.selected = node;
    $(this.ariaLive).html($(this.selected).html());
  };

  /**
   * Unhighlights a suggestion.
   */
  Drupal.jsAC.prototype.unhighlight = function (node) {
    $(node).removeClass('active');
    this.selected = false;
    $(this.ariaLive).empty();
  };

  /**
   * Positions the suggestions popup and starts a search.
   */
  Drupal.jsAC.prototype.populatePopup = function () {
    var $input = $(this.input);
    // Show popup.
    if (this.popup) {
      $(this.popup).remove();
    }
    this.selected = false;
    this.popup = $('<div class="dropdown"></div>')[0];
    this.popup.owner = this;
    $input.parent().after(this.popup);

    // Do search.
    this.db.owner = this;
    this.db.search(this.input.value);
  };

  /**
   * Fills the suggestion popup with any matches received.
   */
  Drupal.jsAC.prototype.found = function (matches) {
    // If no value in the textfield, do not show the popup.
    if (!this.input.value.length) {
      return false;
    }

    // Prepare matches.
    var ul = $('<ul class="dropdown-menu"></ul>');
    var ac = this;
    ul.css({
      display: 'block',
      right: 0
    });
    for (var key in matches) {
      $('<li></li>')
        .html($('<a href="#"></a>').html(matches[key]).on('click', function (e) {
          e.preventDefault();
        }))
        .on('mousedown', function () {
          ac.hidePopup(this);
        })
        .on('mouseover', function () {
          ac.highlight(this);
        })
        .on('mouseout', function () {
          ac.unhighlight(this);
        })
        .data('autocompleteValue', key)
        .appendTo(ul);
    }

    // Show popup with matches, if any.
    if (this.popup) {
      if (ul.children().length) {
        $(this.popup).empty().append(ul).show();
        $(this.ariaLive).html(Drupal.t('Autocomplete popup'));
      }
      else {
        $(this.popup).css({visibility: 'hidden'});
        this.hidePopup();
      }
    }
  };

  /**
   * Finds the next sibling item.
   */
  Drupal.jsAC.prototype.findNextSibling = function (element) {
    var sibling = element && element.nextSibling;
    if (sibling && !this.validItem(sibling)) {
      return this.findNextSibling(sibling.nextSibling);
    }
    return sibling;
  };

  /**
   * Finds the previous sibling item.
   */
  Drupal.jsAC.prototype.findPreviousSibling = function (element) {
    var sibling = element && element.previousSibling;
    if (sibling && !this.validItem(sibling)) {
      return this.findPreviousSibling(sibling.previousSibling);
    }
    return sibling;
  };

  /**
   * Highlights the next suggestion.
   */
  Drupal.jsAC.prototype.selectDown = function () {
    var sibling = this.findNextSibling(this.selected);
    if (sibling) {
      this.highlight(sibling);
    }
    else if (this.popup) {
      var lis = $('li', this.popup);
      if (lis.length > 0) {
        if (this.validItem(lis[0])) {
          this.highlight(lis[0]);
        }
        else {
          this.highlight(this.findNextSibling(lis[0]));
        }
      }
    }
  };

  /**
   * Highlights the previous suggestion.
   */
  Drupal.jsAC.prototype.selectUp = function () {
    var sibling = this.findPreviousSibling(this.selected);
    if (sibling) {
      this.highlight(sibling);
    }
    else if (this.popup) {
      var lis = $('li', this.popup);
      if (lis.length > 0) {
        if (this.validItem(lis[lis.length - 1])) {
          this.highlight(lis[lis.length - 1]);
        }
        else {
          this.highlight(this.findPreviousSibling(lis[lis.length - 1]));
        }
      }
    }
  };

  /**
   * Ensures the item is valid.
   */
  Drupal.jsAC.prototype.validItem = function (element) {
    return !$(element).is('.dropdown-header, .divider, .disabled');
  };

  Drupal.jsAC.prototype.setStatus = function (status) {
    var $throbber = $(this.input).parent().find('.glyphicon-refresh, .autocomplete-throbber').first();
    var throbbingClass = $throbber.is('.autocomplete-throbber') ? 'throbbing' : 'glyphicon-spin';
    switch (status) {
      case 'begin':
        $throbber.addClass(throbbingClass);
        $(this.ariaLive).html(Drupal.t('Searching for matches...'));
        break;
      case 'cancel':
      case 'error':
      case 'found':
        $throbber.removeClass(throbbingClass);
        break;
    }
  };

  // Save the previous autocomplete prototype.
  var oldPrototype = Drupal.jsAC.prototype;

  /**
   * Override the autocomplete constructor.
   */
  Drupal.jsAC = function ($input, db, context) {
    var ac = this;

    // Context is normally passed by Drupal.behaviors.autocomplete above. However,
    // if a module has manually invoked this method they will likely not know
    // about this feature and a global fallback context to document must be used.
    // @see https://www.drupal.org/node/2594243
    // @see https://www.drupal.org/node/2315295
    this.$context = context && $(context) || $(document);

    this.input = $input[0];
    this.ariaLive = this.$context.find('#' + this.input.id + '-autocomplete-aria-live');
    this.db = db;
    $input
      .keydown(function (event) {
        return ac.onkeydown(this, event);
      })
      .keyup(function (event) {
        ac.onkeyup(this, event);
      })
      .blur(function () {
        ac.hidePopup();
        ac.db.cancel();
      });
  };

  // Restore the previous prototype.
  Drupal.jsAC.prototype = oldPrototype;

})(jQuery);
