/**
 * @file
 * File name: scald_youtube_defer_library.js.
 *
 * Script for setting the src attribute.
 */

function initializeYoutubeVideos(context) {
  var contextUsed = (typeof context !== 'undefined' && context !== document ? context : document);
  // If we have a jQuery object, extract the DOM element.
  if (typeof context !== 'undefined' && typeof context[0] !== 'undefined') {
    contextUsed = context[0];
  }
  var youtubeVideos = contextUsed.querySelectorAll('.js-scald-youtube');
  for (var i = 0; i < youtubeVideos.length; i++) {
    if (youtubeVideos[i].getAttribute('data-src')) {
      var source = youtubeVideos[i].getAttribute('data-src');
      // Remove the data-src attribute in order to avoid to do it several times.
      youtubeVideos[i].removeAttribute('data-src');
      youtubeVideos[i].setAttribute('src', source);
    }
  }
}

