
// Inspired by the code by Rainer Halbmann
// https://github.com/heliogabal/hk_leaflet/blob/master/hk_leaflet_script.js

jQuery(document).bind('leaflet.feature', function(event, marker, feature) {
  marker.on('click', function(event) {
    var options = {
      zoom: { animate: true },
      // pan applies only when already at the required zoom level
      pan:  { animate: true, duration: 1, easeLinearity: 0.5 }
    };
    //this._map.zoomAnimation = true;
    //this._map.markerZoomAnimation = true;
    //this._map.zoomAnimationThreshold = 1;
    var zoom = (typeof this._map.options.zoomOnClick === 'undefined')
      ? this._map.options.maxZoom
      : this._map.options.zoomOnClick;
    this._map.setView(event.latlng, zoom, options);
  });
});
