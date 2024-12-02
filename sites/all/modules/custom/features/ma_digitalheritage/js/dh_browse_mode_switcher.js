/**
 * @file
 * A JavaScript file for the theme.
 *
 * In order for this JavaScript to be loaded on pages, see the instructions in
 * the README.txt next to this file.
 */

// JavaScript should be made compatible with libraries other than jQuery by
// wrapping it with an "anonymous closure". See:
// - https://drupal.org/node/1446420
// - http://www.adequatelygood.com/2010/3/JavaScript-Module-Pattern-In-Depth
(function ($, Drupal, window, document, undefined) {

// To understand behaviors, see https://drupal.org/node/756722#behaviors
Drupal.behaviors.my_custom_behavior = {
  attach: function(context, settings) {

    // Sets default class for DH views and toggles between list/grid/map.
    $('#main-content').once('browse-view', function() {

      if ($(".view").hasClass("browse-view")) {

        $('a.list').addClass('active');

        // Set the cookie to list view mode (default) if cookie is unset
        if (!$.cookie('dh_browse_mode')) {
          $.cookie('dh_browse_mode', 'list-view', {path: "/"});
        }

        else if ($.cookie('dh_browse_mode') == 'grid-view') {
          $('a.grid').addClass('active');
          $('a.list').removeClass('active');
          $('a.map').removeClass('active');
          $('.field-name-field-media-asset').removeClass('col-md-push-8');
        }

        else if ($.cookie('dh_browse_mode') == 'map-view') {
          $('a.map').addClass('active');
          $('a.list').removeClass('active');
          $('a.grid').removeClass('active');
          $('.field-name-field-media-asset').removeClass('col-md-push-8');
        }

        var originalViewMode = $.cookie('dh_browse_mode');
        $(".view").addClass($.cookie('dh_browse_mode')); // use whichever mode is set in the cookie

        $("a.grid").click(function() {
          $('.field-name-field-media-asset').removeClass('col-md-push-8');
          $(this).addClass('active');
          $('a.list').removeClass('active');
          $('a.map').removeClass('active');
          $(".view").addClass("grid-view"); // adds .grid-view to the view class
          $(".view").removeClass("list-view"); // removes .list-view from the view class

          $.cookie('dh_browse_mode', 'grid-view', {path: "/"}); // set the cookie to grid mode

          //$('.view-digital-heritage-grid-list .view-content').masonry();

          if (originalViewMode == "map-view") {
            location.reload();
          }

        });

        $("a.list").click(function() {
          $('.field-name-field-media-asset').addClass('col-md-push-8');
          $(this).addClass('active');
          $('a.grid').removeClass('active');
          $('a.map').removeClass('active');
          $(".view").addClass("list-view"); // adds .list-view to the view class
          $(".view").removeClass("grid-view"); // removes .grid-view from the view class
          $.cookie('dh_browse_mode', 'list-view', {path: "/"}); // set the cookie to list-view

          //$('.view-digital-heritage-grid-list .view-content').masonry('destroy');

          if (originalViewMode == "map-view") {
            location.reload();
          }

        });

        $("a.map").click(function() {
          $(this).addClass('active');
          $('a.list').removeClass('active');
          $('a.grid').removeClass('active');
          $.cookie('dh_browse_mode', 'map-view', {path: "/"}); // set the cookie to map-view
          location.reload();
        });

      }
    });

  }
};


})(jQuery, Drupal, this, this.document);
