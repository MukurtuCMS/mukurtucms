window.ga = window.ga || function() {
  var type = arguments[0];
  if (type === 'create') {
    gtag('config', arguments[1], arguments[2]);
  } else if (type === 'set') {
    gtag('set', arguments[1], arguments[2]);
  } else if (type === 'require') {
    // Anything needed in `require` is bundled into Google Tag.
  }
  else if (type === 'send') {
    if (typeof arguments[1] === 'object') {
      gtag('event', arguments[1].eventAction, {
        event_category: arguments[1].eventCategory,
        event_label: arguments[1].eventLabel,
        transport_type: arguments[1].transport || 'beacon',
      })
    }
    else if (arguments[1] === 'pageview') {
      gtag('event', 'page_view');
    }
    else if (arguments.length === 2) {
      gtag('event', arguments[1]);
    }
    else {
      gtag('event', arguments[3] || '', {
        event_category: arguments[2] || '',
        event_label: arguments[4] || '',
      })
    }
  } else {
    gtag(arguments);
  }
}
