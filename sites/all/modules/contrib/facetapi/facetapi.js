(function ($) {

  Drupal.behaviors.facetapi = {
    attach: function(context, settings) {
      // Iterates over facet settings, applies functionality like the "Show more"
      // links for block realm facets.
      // @todo We need some sort of JS API so we don't have to make decisions
      // based on the realm.
      if (settings.facetapi) {
        for (var index in settings.facetapi.facets) {
          if (null != settings.facetapi.facets[index].makeCheckboxes) {
            Drupal.facetapi.makeCheckboxes(settings.facetapi.facets[index].id);
          }
          if (null != settings.facetapi.facets[index].limit) {
            // Applies soft limit to the list.
            Drupal.facetapi.applyLimit(settings.facetapi.facets[index]);
          }
        }
      }
    }
  };

  /**
   * Class containing functionality for Facet API.
   */
  Drupal.facetapi = {};

  /**
   * Applies the soft limit to facets in the block realm.
   */
  Drupal.facetapi.applyLimit = function(settings) {
    if (settings.limit > 0 && !$('ul#' + settings.id).hasClass('facetapi-processed')) {
      // Only process this code once per page load.
      $('ul#' + settings.id).addClass('facetapi-processed');

      // Ensures our limit is zero-based, hides facets over the limit.
      var limit = settings.limit - 1;
      $('ul#' + settings.id).find('li:gt(' + limit + ')').hide();

      // Adds "Show more" / "Show fewer" links as appropriate.
      $('ul#' + settings.id).filter(function() {
        return $(this).find('li').length > settings.limit;
      }).each(function() {
        $('<a href="#" class="facetapi-limit-link"></a>').text(settings.showMoreText).click(function() {
          if ($(this).hasClass('open')) {
            $(this).siblings().find('li:gt(' + limit + ')').slideUp();
            $(this).removeClass('open').text(settings.showMoreText);
          }
          else {
            $(this).siblings().find('li:gt(' + limit + ')').slideDown();
            $(this).addClass('open').text(Drupal.t(settings.showFewerText));
          }
          return false;
        }).insertAfter($(this));
      });
    }
  };

  /**
   * Constructor for the facetapi redirect class.
   */
  Drupal.facetapi.Redirect = function(href) {
    this.href = href;
  };

  /**
   * Method to redirect to the stored href.
   */
  Drupal.facetapi.Redirect.prototype.gotoHref = function() {
    window.location.href = this.href;
  };

  /**
   * Turns all facet links into checkboxes.
   * Ensures the facet is disabled if a link is clicked.
   */
  Drupal.facetapi.makeCheckboxes = function(facet_id) {
    var $facet = $('#' + facet_id),
        $items = $('a.facetapi-checkbox, span.facetapi-checkbox', $facet);

    // Find all checkbox facet links and give them a checkbox.
    $items.once('facetapi-makeCheckbox').each(Drupal.facetapi.makeCheckbox);
    $items.once('facetapi-disableClick').click(function (e) {
      Drupal.facetapi.disableFacet($facet);
    });
  };

  /**
   * Disable all facet links and checkboxes in the facet and apply a 'disabled'
   * class.
   */
  Drupal.facetapi.disableFacet = function ($facet) {
    var $elem = $(this);
    // Apply only for links.
    if ($elem[0].tagName == 'A') {
      $facet.addClass('facetapi-disabled');
      $('a.facetapi-checkbox').click(Drupal.facetapi.preventDefault);
      $('input.facetapi-checkbox', $facet).attr('disabled', true);
    }
  };

  /**
   * Event listener for easy prevention of event propagation.
   */
  Drupal.facetapi.preventDefault = function (e) {
    e.preventDefault();
  };

  /**
   * Replace an unclick link with a checked checkbox.
   */
  Drupal.facetapi.makeCheckbox = function() {
    var $elem = $(this),
        active = $elem.hasClass('facetapi-active');

    if (!active && !$elem.hasClass('facetapi-inactive')) {
      // Not a facet element.
      return;
    }

    // Derive an ID and label for the checkbox based on the associated link.
    // The label is required for accessibility, but it duplicates information
    // in the link itself, so it should only be shown to screen reader users.
    var id = this.id + '--checkbox',
        description = $elem.find('.element-invisible').html(),
        label = $('<label class="element-invisible" for="' + id + '">' + description + '</label>');

    // Link for elements with count 0.
    if ($elem[0].tagName == 'A') {
      var checkbox = $('<input type="checkbox" class="facetapi-checkbox" id="' + id + '" />'),
        // Get the href of the link that is this DOM object.
        href = $elem.attr('href'),
        redirect = new Drupal.facetapi.Redirect(href);
    }
    // Link for elements with count more than 0.
    else {
      var checkbox = $('<input disabled type="checkbox" class="facetapi-checkbox" id="' + id + '" />');
    }

    checkbox.click(function (e) {
      Drupal.facetapi.disableFacet($elem.parents('ul.facetapi-facetapi-checkbox-links'));
      redirect.gotoHref();
    });

    if (active) {
      checkbox.attr('checked', true);
      // Add the checkbox and label, hide the link.
      $elem.before(label).before(checkbox).hide();
    }
    else {
      $elem.before(label).before(checkbox);
    }
  };

})(jQuery);
