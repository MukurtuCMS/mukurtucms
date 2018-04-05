/**
 * @file
 * Javascript for comments.
 *
 * This file handles the expanding/collapsing of individual comments, all
 * comments at once, and moving a comment to the top and expanding it if the url
 * contains the comment hash.
 */

(function ($) {
  Drupal.behaviors.adjustComments = {
    attach: function(context, settings) {
      $('.oa-list.oa-comment .oa-pullout-left', context).each(function() {
        if ($(this).width() > 25) {
          // For wide comment ids, add extra padding to first paragraph.
          $(this).parents('.accordion-toggle').find('.oa-comment-reply-body p:nth-child(1)').css('text-indent', ($(this).width() - 25) + 'px');
        }
      });
    }
  };

  Drupal.behaviors.toggleReplyVisibility = {
    attach: function(context, settings) {
      var expandText = '<i class="icon-plus"></i> ' + Drupal.t('Expand All');
      // Add a div that will contain the 'Expand/Collapse All' button if these
      // selectors have no content.
      if ($.trim($('.oa-comment').html())) {
        $('#comments, .pane-node-comments').once('comments', function() {
          $(this).prepend('<div id="toggle-comment-visibility" class="toggle-comment-visibility btn btn-default">' + expandText + '</div>');
        });
      }

      var expand = true;
      var collapseText = '<i class="icon-minus"></i> ' + Drupal.t('Collapse All');

      $(function() {
        $('.toggle-comment-visibility').each(function() {
          // This will get all '.oa-list-header divs that belong with the correct 'toggle'.
          var replies = ($(this).siblings('.pane-content').length > 0)
            ? $(this).siblings('.pane-content').find('.oa-list')
            : $(this).siblings('.oa-list');
          replies = replies.find('.oa-list-header');
          $(this).on('click', function(event) {
            event.preventDefault();
            // $replies.collapse(expand ? 'show' : 'hide');
            // Due to a bug in bootstrap's collapse, bodies that have been expanded
            // by default (By adding the class "in") are collapsed the first time
            // you run .collapse('show');. Use the above if this gets fixed.
            if (expand) {
              replies.each(function() {
                if (!$(this).hasClass('in')) {
                  $(this).removeClass('oa-comment-hide');
                }
              });
            }
            else {
              replies.addClass('oa-comment-hide');
            }

            expand = !expand;
            $(this).html(expand ? expandText : collapseText);

            // Get rid of 'new' marker on initial pageload.
            $('.oa-list.oa-comment').find('.new-marker').empty();
          });
        });
      });

      // Target the <p> tag so we can click on links, images, etc inside a 'paragraph comment' and it won't close the comment.
      $('.accordion-toggle .oa-list-header .oa-comment-reply-body:not(.oa-list-header-processed)', context).addClass('oa-list-header-processed').click(function(event) {
        var skipTags = ['A', 'IMG'];
        var target = $(event.target).prop('tagName');
        // Don't expand/collapse if original click as on a link or image/
        // Note, do not just use stopPropogation as images need to support colorbox popups
        if (skipTags.indexOf(target) < 0) {
          // This is targeting '.oa-list-header'
          $(this).parents('.oa-list-header').eq(0).toggleClass('oa-comment-hide');
          // This is targeting '.oa-list-header'
          if ($(this).parents('.oa-list-header').eq(0).hasClass('oa-comment-is-new') && !$(this.parents('.oa-list-header').eq(0).hasClass('oa-comment-new-processed'))) {
            // This is targeting '.oa-list-header'
            $(this).parents('.oa-list-header').eq(0).addClass('oa-comment-new-processed');
            // This is targeting '.accordion'
            $(this).parents('.accordion').eq(0).find('.new-marker').empty();
          }
        }
      });

      // This will expand the comment with the same hash that exists in the url.
      $(window).bind('load hashchange', function() {
        // Get the fragment that contains the comment number.
        var hash = document.location.hash;
        if (hash && hash.indexOf("#/") != 0 ) {
          // Expand that comment.
          $(hash).next().find('.oa-list-header').toggleClass('oa-comment-hide');
          // Get the height of the fixed oa-navbar.
          var nav = $('#oa-navbar').height();
          // Scroll to the top - the height of the navbar.
          window.scrollTo(0, $(hash).offset().top - nav);
        }
        // If the comment is new then expand it.
        $('.oa-comment-is-new').each(function() {
          $(this).removeClass('oa-comment-hide');
        });
      });

      // Override ctools so we not only dismiss the modal but trigger a page
      // reload when the modal is closed. The WYSIWYG buttons vanish on the
      // underlying page when the modal is closed.
      // @todo: Figure out why the WYSIWYG buttons go missing and remove this
      // temporary hack.
      $('.ctools-close-modal', context).once('ctools-close-modal').click(function() {
        Drupal.CTools.Modal.dismiss();
        location.reload();
        return false;
      });
    }
  };
})(jQuery);
