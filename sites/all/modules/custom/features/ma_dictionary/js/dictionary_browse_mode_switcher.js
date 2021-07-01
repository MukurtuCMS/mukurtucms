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

    // Sets default class for browse views and toggles between list/grid.
    $('#main-content').once('browse-view', function() {

      if ($(".view").hasClass("browse-view")) {

        $('a.list').addClass('active');

        // Set the cookie to list view mode (default) if cookie is unset
        if (!$.cookie('dictionary_browse_mode')) {
          $.cookie('dictionary_browse_mode', 'list-view', {path: "/"});

        } else if ($.cookie('dictionary_browse_mode') == 'grid-view') {
          $('a.grid').addClass('active');
          $('a.list').removeClass('active');
          //$('.field-name-field-dictionary-word-recording').removeClass('col-md-push-8');
        }

        $(".view").addClass($.cookie('dictionary_browse_mode')); // use whichever mode is set in the cookie

        $("a.grid").click(function() {
          if ($(".view").hasClass("list-view")) {
            //$('.field-name-field-dictionary-word-recording').removeClass('col-md-push-8');
            $(this).addClass('active');
            $('a.list').removeClass('active');
            $(".view").addClass("grid-view"); // adds .grid-view to the view class
            $(".view").removeClass("list-view"); // removes .list-view from the view class
            $.cookie('dictionary_browse_mode', 'grid-view', {path: "/"}); // set the cookie to grid mode

            $('.view-dictionary-words .view-content').masonry();
          }
        });

        $("a.list").click(function() {
          if ($(".view").hasClass("grid-view")) {
            //$('.field-name-field-dictionary-word-recording').removeClass('col-md-push-8');
            $(this).addClass('active');
            $('a.grid').removeClass('active');
            $(".view").addClass("list-view"); // adds .list-view to the view class
            $(".view").removeClass("grid-view"); // removes .grid-view from the view class
            $.cookie('dictionary_browse_mode', 'list-view', {path: "/"}); // set the cookie to list-view

            $('.view-dictionary-words .view-content').masonry('destroy');
          }
        });

      }
    });

  }
};


})(jQuery, Drupal, this, this.document);
