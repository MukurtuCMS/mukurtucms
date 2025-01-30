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
  var consent = contextUsed.querySelectorAll('.scald-youtube-consent-wrapper');
  var consent_buttons = contextUsed.querySelectorAll('button.js-scald-youtube-consent');
  for (var i = 0; i < consent_buttons.length; i++) {
    consent_buttons[i].addEventListener('click', function () {
      if (Drupal.eu_cookie_compliance === undefined || Drupal.eu_cookie_compliance.hasAgreed()) {
        scaldYoutubeCreateCookie('scald_youtube_consent', '1', 90);
      }
      scaldYoutubeInitVideos(contextUsed);
    });
  }
  if (consent.length === 0 || scaldYoutubeReadCookie('scald_youtube_consent') === '1') {
    scaldYoutubeInitVideos(contextUsed);
  }
}

function scaldYoutubeInitVideos(contextUsed) {
  var youtubeVideos = contextUsed.querySelectorAll('.js-scald-youtube');
  for (var i = 0; i < youtubeVideos.length; i++) {
    if (youtubeVideos[i].getAttribute('data-src')) {
      var source = youtubeVideos[i].getAttribute('data-src');
      // Remove the data-src attribute in order to avoid to do it several times.
      youtubeVideos[i].removeAttribute('data-src');
      youtubeVideos[i].setAttribute('src', source);
    }
  }
  var consentWrappers = contextUsed.querySelectorAll('.scald-youtube-consent-wrapper');
  for (var i = 0; i < consentWrappers.length; i++) {
    consentWrappers[i].parentNode.removeChild(consentWrappers[i]);
  }
}

function scaldYoutubeCreateCookie(name, value, days) {
  var expires;

  if (days) {
    var date = new Date();
    date.setTime(date.getTime() + (days * 24 * 60 * 60 * 1000));
    expires = '; expires=' + date.toGMTString();
  } else {
    expires = '';
  }
  document.cookie = encodeURIComponent(name) + '=' + encodeURIComponent(value) + expires + '; path=/';
}

function scaldYoutubeReadCookie(name) {
  var nameEQ = encodeURIComponent(name) + '=';
  var ca = document.cookie.split(';');
  for (var i = 0; i < ca.length; i++) {
    var c = ca[i];
    while (c.charAt(0) === ' ')
      c = c.substring(1, c.length);
    if (c.indexOf(nameEQ) === 0)
      return decodeURIComponent(c.substring(nameEQ.length, c.length));
  }
  return null;
}

if (typeof window.loadYoutubeWysiwyg === 'function') {
  loadYoutubeWysiwyg();
}

