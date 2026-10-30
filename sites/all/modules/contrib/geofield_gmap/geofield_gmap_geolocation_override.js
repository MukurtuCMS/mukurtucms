;(function ($) {
  Drupal.behaviors.geofieldGeolocation = {
    attach: function (context, settings) {

      if (settings.geofield_gmap) {
        $.each(settings.geofield_gmap, function(mapid, options) {

          var lat = $('#' + options.latid, context);
          var lng = $('#' + options.lngid, context);

          // Update map is values already set for location.
          if (lat.val() && lng.val()) {
            updateMapLocation(lat.val(), lng.val(), mapid);
          }

          // Don't do anything if we're on field configuration.
          if (!$("#edit-instance", context).length) {
            // Check that we have something to fill up
            // on multi values check only that the first one is empty.
            if (lat.val() == '' && lng.val() == '') {
              // Check to see if we have geolocation support, either natively or through Google.
              if (navigator.geolocation) {
                navigator.geolocation.getCurrentPosition(function(position) {
                  updateMapLocation(position.coords.latitude, position.coords.longitude, mapid);
                });
              }
            }
          }

          $(':input[name="geofield-html5-geocode-button"]').once('geofield_geolocation').click(function(e) {
            e.preventDefault();
            // Find element IDs based on clicked button.
            var base_id = $(this).attr('id');
            var mapid = 'gmap-' + base_id.substring(5, base_id.length - 13);
            if (navigator.geolocation) {
              navigator.geolocation.getCurrentPosition(function(position) {
                updateMapLocation(position.coords.latitude, position.coords.longitude, mapid);
              });
            }
          });

        });
      }

    }
  };
})(jQuery);

// Update the map marker.
function updateMapLocation(lat, lon, mapid) {
  var pos = new google.maps.LatLng(lat, lon);
  geofield_gmap_data[mapid].lat.val(lat);
  geofield_gmap_data[mapid].lng.val(lon);
  geofield_gmap_data[mapid].marker.setPosition(pos);
  geofield_gmap_data[mapid].map.setCenter(pos);

  if (geofield_gmap_data[mapid].search) {
    geofield_gmap_geocoder.geocode({'latLng': pos}, function(results, status) {
      if (status == google.maps.GeocoderStatus.OK) {
        if (results[0]) {
          geofield_gmap_data[mapid].search.val(results[0].formatted_address);
        }
      }
    });
  }
}
