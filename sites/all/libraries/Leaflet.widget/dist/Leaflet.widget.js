/*! Leaflet.widget - v0.1.0 - 2016-10-05
* Copyright (c) 2016 Affinity Bridge - Tom Nightingale <tom@affinitybridge.com> (http://affinitybridge.com)
* Licensed BSD */

L.GeoJSONUtil = {
    featureCollection: function (features) {
        return {
            type: 'FeatureCollection',
            features: features || []
        };
    },

    feature: function (geometry, properties) {
        return {
            "type": "Feature",
            "geometry": geometry,
            "properties": properties || {}
        };
    },

    latLngsToCoords: function (latlngs) {
        var coords = [],
            coord;

        for (var i = 0, len = latlngs.length; i < len; i++) {
            coord = L.GeoJSONUtil.latLngToCoord(latlngs[i]);
            coords.push(coord);
        }

        return coords;
    },

    latLngToCoord: function (latlng) {
        return [latlng.lng, latlng.lat];
    }
};

L.WidgetFeatureGroup = L.FeatureGroup.extend({
    initialize: function (layers) {
        L.FeatureGroup.prototype.initialize.call(this, layers);
        this._size = layers ? layers.length : 0;
    },

    addLayer: function (layer) {
        this._size += 1;
        L.FeatureGroup.prototype.addLayer.call(this, layer);
    },

    removeLayer: function (layer) {
        this._size -= 1;
        L.FeatureGroup.prototype.removeLayer.call(this, layer);
    },

    clearLayers: function () {
        this._size = 0;
        L.FeatureGroup.prototype.clearLayers.call(this);
    },

    toGeoJSON: function () {
        var features = [];
        this.eachLayer(function (layer) {
            features.push(layer.toGeoJSON());
        });

        return L.GeoJSONUtil.featureCollection(features);
    },

    size: function () {
        return this._size;
    },

    /**
     * Borrowing from L.FeatureGroup.
     */
    getBounds: L.FeatureGroup.prototype.getBounds
});

L.widgetFeatureGroup = function (layers) {
    return new L.WidgetFeatureGroup(layers);
};

L.Path.include({
    toGeoJSON: function () {
        return L.GeoJSONUtil.feature(this.toGeometry());
    }
});

L.FeatureGroup.include({
    toGeometry: function () {
        var coords = [];
        this.eachLayer(function (layer) {
            var geom = layer.toGeometry();
            if (geom.type !== "Point") {
                // We're assuming a FeatureGroup only contains Points
                // (currently no support for 'GeometryCollections').
                return;
            }
            coords.push(geom.coordinates);
        });

        return {
            type: "MultiPoint",
            coordinates: coords
        };
    },

    // TODO: Refactor this so we don't require two passes.
    isCollection: function () {
        var is_collection = false,
            geoms = [];

        this.eachLayer(function (layer) {
            if (!is_collection && layer.toGeometry().type !== "Point") {
                is_collection = true;
            }
        });

        return is_collection;
    },

    toGeoJSON: function () {
        if (this.isCollection()) {
            var geoms = [];
            this.eachLayer(function (layer) {
                geoms.push(layer.toGeometry());
            });
            return {
                type: "GeometryCollection",
                geometries: geoms
            };
        }
        else {
            return L.GeoJSONUtil.feature(this.toGeometry());
        }
    }
});

L.Marker.include({
    toGeometry: function () {
        return {
            type: "Point",
            coordinates: L.GeoJSONUtil.latLngToCoord(this.getLatLng())
        };
    },
    toGeoJSON: function () {
        return L.GeoJSONUtil.feature(this.toGeometry());
    }
});

L.Polyline.include({
    toGeometry: function () {
        return {
            type: "LineString",
            coordinates: L.GeoJSONUtil.latLngsToCoords(this.getLatLngs())
        };
    }
});

L.Polygon.include({
    toGeometry: function () {
        var latlngs = this.getLatLngs();
        // Close the polygon to create a LinearRing as per GeoJSON spec.
        // - http://www.geojson.org/geojson-spec.html#polygon
        latlngs.push(latlngs[0]);

        // TODO: add support for 'holes'.

        return {
            type: "Polygon",
            coordinates: [L.GeoJSONUtil.latLngsToCoords(latlngs)]
        };
    }
});

L.MultiPolyline.include({
    toGeometry: function () {
        var coords = [];

        this.eachLayer(function (layer) {
            coords.push(layer.toGeometry().coordinates);
        });

        return {
            type: "MultiLineString",
            coordinates: coords
        };
    }
});

L.MultiPolygon.include({
    toGeometry: function () {
        var coords = [];

        this.eachLayer(function (layer) {
            coords.push(layer.toGeometry().coordinates);
        });

        return {
            type: "MultiPolygon",
            coordinates: coords
        };
    }
});

L.Map.mergeOptions({
    widget: false
});

L.Handler.Widget = L.Handler.extend({
    includes: L.Mixin.Events,

    options: {
        multiple: true,
        cardinality: 0, // Unlimited if multiple === true.
        autoCenter: true,
        polyline: {
            shapeOptions: {
                drawVectorStyle: {
                    color: '#F0F',
                    clickable: true
                }
            }
        },
        polygon: {
            shapeOptions: {
                drawVectorStyle: {
                    color: '#F0F',
                    clickable: true
                }
            }
        },
        rectangle: true,
        circle: true,
        marker: true
    },

    initialize: function (map, options) {
        L.Util.setOptions(this, options);
        L.Handler.prototype.initialize.call(this, map);

        if (!this._map.drawControl) {
            this._initDraw();
        }
    },

    addHooks: function () {
        if (this._map && this.options.attach) {
            this._attach = L.DomUtil.get(this.options.attach);
            this._full = false;
            this._cardinality = this.options.multiple ? this.options.cardinality : 1;

            this.load(this._attach.value);

            // Map event handlers.
            this._map.on({
                'draw:created': this._onCreated,
                'layerremove': this._unbind
            }, this);

            if (this.vectors.size() > 0 && this.options.autoCenter) {
                this._map.fitBounds(this.vectors.getBounds());
            }
        }
    },

    removeHooks: function () {
        if (this._map) {
            this._map.removeLayer(this.vectors);

            this._map.off({
                'draw:created': this._onCreated,
                'layerremove': this._unbind
            }, this);
        }
    },

    _initDraw: function () {
        this.vectors = L.widgetFeatureGroup().addTo(this._map);

        this._map.drawControl = new L.Control.Draw({
            position: 'topright',
            draw: {
                polyline: this.options.polyline,
                polygon: this.options.polygon,
                rectangle: this.options.rectangle,
                circle: this.options.circle,
                marker: this.options.marker
            },
            edit: { featureGroup: this.vectors }
        }).addTo(this._map);
    },

    // Add vector layers.
    _addVector: function (feature) {
        this.vectors.addLayer(feature);

        if (this._cardinality > 0 && this._cardinality <= this.vectors.size()) {
            this._full = true;
        }
    },

    // Handle features drawn by user.
    _onCreated: function (e) {
        var type = e.layerType,
        layer = e.layer;

        if (layer && !this._full) {
            this._addVector(layer);
        }
    },

    _unbind: function (e) {
        var layer = e.layer;
        if (this.vectors.hasLayer(layer)) {
            this.vectors.removeLayer(layer);

            if (this._cardinality > this.vectors.size()) {
                this._full = false;
            }
        }
    },

    // Read GeoJSON features into widget vector layers.
    load: function (geojson) {
        var data,
            on_each = function (feature, layer) {
                this._addVector(layer);
            };

        // Empty data isn't an exceptional scenario.
        if (!geojson) {
            // Return like nothing happened.
            return;
        }

        // Invalid GeoJSON is and an exception will be thrown.
        data = typeof geojson === 'string' ? JSON.parse(geojson) : geojson;

        return L.geoJson(data, {
            onEachFeature: L.Util.bind(on_each, this)
        });
    },

    // Write widget vector layers to GeoJSON.
    write: function () {
        var obj = this.vectors.toGeoJSON();
        this._attach.value = JSON.stringify(obj);
    }
});

L.Map.addInitHook(function () {
    if (this.options.widget) {
        var options = this.options.widget;
        this.widget = new L.Handler.Widget(this, options);
    }
});
