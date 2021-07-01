(function ($) {
Drupal.settings.views = Drupal.settings.views || {'ajax_path': '/views/ajax'};

Drupal.quicktabs = Drupal.quicktabs || {};

Drupal.quicktabs.getQTName = function (el) {
  return el.id.substring(el.id.indexOf('-') +1);
}

Drupal.behaviors.quicktabs = {
  attach: function (context, settings) {
    $.extend(true, Drupal.settings, settings);
    $('.quicktabs-wrapper', context).once(function(){
      Drupal.quicktabs.prepare(this);
    });
  }
}

// Enable tab memory.
// Relies on the jQuery Cookie plugin.
// @see http://plugins.jquery.com/cookie
Drupal.behaviors.quicktabsTabMemory = {
  attach: function(context, settings) {
    // The .each() is in case there is more than one quicktab on a page.
    $('.quicktabs-wrapper', context).each(function () {

      var $this = $(this);
      var wrapperID = $this.attr('id');
      if (wrapperID.substr(0, 23) == 'quicktabs-protocol-tabs') {

        var $activeTabLink = $('.quicktabs-tabs li.active a', context);
        var activeTabLinkID = $activeTabLink.attr('id');

        // Use a unique cookie namespace for each set of Quicktabs, which
        // should allow for more than one set on a page.
        var cookieName = 'Drupal-quicktabs-active-tab-id-' + wrapperID;
        // Default cookie options.
        var cookieOptions = {path: '/'};

        // Click the tab ID if a cookie exists otherwise set a cookie for
        // the default active tab.
        var $cookieValue = $.cookie(cookieName);
        if ($cookieValue) {
          $('#' + $cookieValue).click();
        }
        else {
          $.cookie(cookieName, activeTabLinkID, cookieOptions);
        }

        // Set the click handler for all tabs, this updates the cookie on every
        // tab click.
        $this.find('ul.quicktabs-tabs a').click(function quicktabsCookieClickHandler() {
          $activeTabLink = $this.find('.quicktabs-tabs li.active a', context);
          activeTabLinkID = $activeTabLink.attr('id');
          $.cookie(cookieName, activeTabLinkID, cookieOptions);
        });
      }
    });
  }
};

// Setting up the inital behaviours
Drupal.quicktabs.prepare = function(el) {
  // el.id format: "quicktabs-$name"
  var qt_name = Drupal.quicktabs.getQTName(el);
  var $ul = $(el).find('ul.quicktabs-tabs:first');

  $("ul.quicktabs-tabs li a span#active-quicktabs-tab").remove();

  $ul.find('li a').each(function(i, element){
    element.myTabIndex = i;
    element.qt_name = qt_name;

    var tab = new Drupal.quicktabs.tab(element);
    var parent_li = $(element).parents('li').get(0);
    if ($(parent_li).hasClass('active')) {
      $(element).addClass('quicktabs-loaded');
      $(element).append('<span id="active-quicktabs-tab" class="element-invisible">' + Drupal.t('(active tab)') + '</span>');
    }
    $(element).once(function() {$(this).bind('click', {tab: tab}, Drupal.quicktabs.clickHandler);});
  });
}

Drupal.quicktabs.clickHandler = function(event) {
  var tab = event.data.tab;
  var element = this;
  // Set clicked tab to active.
  $(this).parents('li').siblings().removeClass('active');
  $(this).parents('li').addClass('active');

  $("ul.quicktabs-tabs li a span#active-quicktabs-tab").remove();
  $(this).append('<span id="active-quicktabs-tab" class="element-invisible">' + Drupal.t('(active tab)') + '</span>');

  // Hide all tabpages.
  tab.container.children().addClass('quicktabs-hide');
  
  if (!tab.tabpage.hasClass("quicktabs-tabpage")) {
    tab = new Drupal.quicktabs.tab(element);
  }

  tab.tabpage.removeClass('quicktabs-hide');
  $(element).trigger('switchtab');
  return false;
}

// Constructor for an individual tab
Drupal.quicktabs.tab = function (el) {
  this.element = el;
  this.tabIndex = el.myTabIndex;
  var qtKey = 'qt_' + el.qt_name;
  var i = 0;
  for (var key in Drupal.settings.quicktabs[qtKey].tabs) {
    if (i == this.tabIndex) {
      this.tabObj = Drupal.settings.quicktabs[qtKey].tabs[key];
      this.tabKey = key;
    }
    i++;
  }
  this.tabpage_id = 'quicktabs-tabpage-' + el.qt_name + '-' + this.tabKey;
  this.container = $('#quicktabs-container-' + el.qt_name);
  this.tabpage = this.container.find('#' + this.tabpage_id);
}

if (Drupal.ajax) {
  /**
   * Handle an event that triggers an AJAX response.
   *
   * We unfortunately need to override this function, which originally comes from
   * misc/ajax.js, in order to be able to cache loaded tabs, i.e. once a tab
   * content has loaded it should not need to be loaded again.
   *
   * I have removed all comments that were in the original core function, so that
   * the only comments inside this function relate to the Quicktabs modification
   * of it.
   */
  Drupal.ajax.prototype.eventResponse = function (element, event) {
    var ajax = this;

    if (ajax.ajaxing) {
      return false;
    }
  
    try {
      if (ajax.form) {
        if (ajax.setClick) {
          element.form.clk = element;
        }
  
        ajax.form.ajaxSubmit(ajax.options);
      }
      else {
        // Do not perform an ajax request for already loaded Quicktabs content.
        if (!$(element).hasClass('quicktabs-loaded')) {
          ajax.beforeSerialize(ajax.element, ajax.options);
          $.ajax(ajax.options);
          if ($(element).parents('ul').hasClass('quicktabs-tabs')) {
            $(element).addClass('quicktabs-loaded');
          }
        }
      }
    }
    catch (e) {
      ajax.ajaxing = false;
      alert("An error occurred while attempting to process " + ajax.options.url + ": " + e.message);
    }
    return false;
  };
}


})(jQuery);
