(function ($) {
  Drupal.behaviors.geofieldMapInit = {
    attach: function (context, settings) {

      // Init all maps in Drupal.settings.
      if (settings.geofield_gmap) {
        $.each(settings.geofield_gmap, function(mapid, options) {
          geofield_gmap_initialize({
            lat: options.lat,
            lng: options.lng,
            zoom: options.zoom,
            latid: options.latid,
            lngid: options.lngid,
            searchid: options.searchid,
            mapid: options.mapid,
            widget: options.widget,
            map_type: options.map_type,
            confirm_center_marker: options.confirm_center_marker,
            click_to_place_marker: options.click_to_place_marker,
          });
        });
      }

    }
  };
})(jQuery);

var geofield_gmap_geocoder;
var geofield_gmap_data = [];

// Center the map to the marker location.
function geofield_gmap_center(mapid) {
  google.maps.event.trigger(geofield_gmap_data[mapid].map, 'resize');
  geofield_gmap_data[mapid].map.setCenter(geofield_gmap_data[mapid].marker.getPosition());
}

// Place marker at the current center of the map.
function geofield_gmap_marker(mapid) {
  if (geofield_gmap_data[mapid].confirm_center_marker) {
    if (!window.confirm('Change marker position ?')) return;
  }

  google.maps.event.trigger(geofield_gmap_data[mapid].map, 'resize');
  var position = geofield_gmap_data[mapid].map.getCenter();
  geofield_gmap_data[mapid].marker.setPosition(position);
  geofield_gmap_data[mapid].lat.val(position.lat());
  geofield_gmap_data[mapid].lng.val(position.lng());

  if (geofield_gmap_data[mapid].search) {
    geofield_gmap_geocoder.geocode({'latLng': position}, function (results, status) {
      if (status == google.maps.GeocoderStatus.OK) {
        if (results[0]) {
          geofield_gmap_data[mapid].search.val(results[0].formatted_address);
        }
      }
    });
  }
}

// Init google map.
function geofield_gmap_initialize(params) {
  geofield_gmap_data[params.mapid] = params;
  jQuery.noConflict();

  if (!geofield_gmap_geocoder) {
    geofield_gmap_geocoder = new google.maps.Geocoder();
  }

  var location = new google.maps.LatLng(params.lat, params.lng);
  var options = {
    zoom: Number(params.zoom),
    center: location,
    mapTypeId: google.maps.MapTypeId.SATELLITE,
    scaleControl: true,
    zoomControlOptions: {
      style: google.maps.ZoomControlStyle.LARGE
    }
  };

  switch (params.map_type) {
    case "ROADMAP":
      options.mapTypeId = google.maps.MapTypeId.ROADMAP;
      break;
    case "SATELLITE":
      options.mapTypeId = google.maps.MapTypeId.SATELLITE;
      break;
    case "HYBRID":
      options.mapTypeId = google.maps.MapTypeId.HYBRID;
      break;
    case "TERRAIN":
      options.mapTypeId = google.maps.MapTypeId.TERRAIN;
      break;
    default:
      options.mapTypeId = google.maps.MapTypeId.ROADMAP;
  }

  var map = new google.maps.Map(document.getElementById(params.mapid), options);
  geofield_gmap_data[params.mapid].map = map;

  // Fix http://code.google.com/p/gmaps-api-issues/issues/detail?id=1448.
  google.maps.event.addListener(map, "idle", function () {
    google.maps.event.trigger(map, 'resize');
  });

  // Fix map issue in fieldgroups / vertical tabs
  // https://www.drupal.org/node/2474867.
  google.maps.event.addListenerOnce(map, "idle", function () {
    // Show all map tiles when a map is shown in a vertical tab.
    jQuery('#' + params.mapid).closest('div.vertical-tabs').find('.vertical-tab-button a').click(function () {
      google.maps.event.trigger(map, 'resize');
      geofield_gmap_center(params.mapid);
    });
    // Show all map tiles when a map is shown in a collapsible fieldset.
    jQuery('#' + params.mapid).closest('fieldset.collapsible').find('a.fieldset-title').click(function () {
      google.maps.event.trigger(map, 'resize');
      geofield_gmap_center(params.mapid);
    });
  });

  // Place map marker.
  var marker = new google.maps.Marker({
    map: map,
    draggable: params.widget
  });
  geofield_gmap_data[params.mapid].marker = marker;
  marker.setPosition(location);

  if (params.widget && params.latid && params.lngid) {
    geofield_gmap_data[params.mapid].lat = jQuery("#" + params.latid);
    geofield_gmap_data[params.mapid].lng = jQuery("#" + params.lngid);
    if (params.searchid) {
      geofield_gmap_data[params.mapid].search = jQuery("#" + params.searchid);
      geofield_gmap_data[params.mapid].search.autocomplete({
        // This bit uses the geocoder to fetch address values.
        source: function (request, response) {
          geofield_gmap_geocoder.geocode({'address': request.term }, function (results, status) {
            response(jQuery.map(results, function (item) {
              return {
                label: item.formatted_address,
                value: item.formatted_address,
                latitude: item.geometry.location.lat(),
                longitude: item.geometry.location.lng()
              };
            }));
          });
        },
        // This bit is executed upon selection of an address.
        select: function (event, ui) {
          geofield_gmap_data[params.mapid].lat.val(ui.item.latitude);
          geofield_gmap_data[params.mapid].lng.val(ui.item.longitude);
          var location = new google.maps.LatLng(ui.item.latitude, ui.item.longitude);
          marker.setPosition(location);
          map.setCenter(location);
        }
      });

      // Geocode user input on enter.
      geofield_gmap_data[params.mapid].search.keydown(function (e) {
        if (e.which == 13) {
          var input = geofield_gmap_data[params.mapid].search.val();
          // Execute the geocoder
          geofield_gmap_geocoder.geocode({'address': input }, function (results, status) {
            if (status == google.maps.GeocoderStatus.OK) {
              if (results[0]) {
                // Set the location
                var location = new google.maps.LatLng(results[0].geometry.location.lat(), results[0].geometry.location.lng());
                marker.setPosition(location);
                map.setCenter(location);
                // Fill the lat/lon fields with the new info
                geofield_gmap_data[params.mapid].lat.val(marker.getPosition().lat());
                geofield_gmap_data[params.mapid].lng.val(marker.getPosition().lng());
              }
            }
          });
        }
      });

      // Add listener to marker for reverse geocoding.
      google.maps.event.addListener(marker, 'drag', function () {
        geofield_gmap_geocoder.geocode({'latLng': marker.getPosition()}, function (results, status) {
          if (status == google.maps.GeocoderStatus.OK) {
            if (results[0]) {
              geofield_gmap_data[params.mapid].search.val(results[0].formatted_address);
              geofield_gmap_data[params.mapid].lat.val(marker.getPosition().lat());
              geofield_gmap_data[params.mapid].lng.val(marker.getPosition().lng());
            }
          }
        });
      });
    }

    if (params.click_to_place_marker) {
      // Change marker position with mouse click.
      google.maps.event.addListener(map, 'click', function (event) {
        var position = new google.maps.LatLng(event.latLng.lat(), event.latLng.lng());
        marker.setPosition(position);
        geofield_gmap_data[params.mapid].lat.val(position.lat());
        geofield_gmap_data[params.mapid].lng.val(position.lng());
        //google.maps.event.trigger(geofield_gmap_data[params.mapid].map, 'resize');
      });
    }

    geofield_onchange = function () {
      var location = new google.maps.LatLng(
        parseInt(geofield_gmap_data[params.mapid].lat.val()),
        parseInt(geofield_gmap_data[params.mapid].lng.val()));
      marker.setPosition(location);
      map.setCenter(location);
    };

    geofield_gmap_data[params.mapid].lat.change(geofield_onchange);
    geofield_gmap_data[params.mapid].lng.change(geofield_onchange);
  }
}
