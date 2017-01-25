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
