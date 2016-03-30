jQuery(document).ready(function($){
    // --- masonry initializer --- //
    var $container = $('.masonry-grid .view-content');
    // initialize
    $container.masonry({
        itemSelector: '.masonry-brick',
        columnWidth: 227
    });

    var $container_grid = $('.view-digital-heritage-grid-list .view-content, .view-collections-grid-list .view-content');

    $container_grid.masonry({
        itemSelector: '.views-row'
    });

    $('.views-slideshow-cycle-main-frame-row .geofieldMap').parent().addClass('half');

    if ($('.views-slideshow-cycle-main-frame-row ul li:contains(".wav")').length > 0) {
        $('.views-slideshow-cycle-main-frame-row ul li').addClass('audio');
    }

    if ( ($.cookie('dh_browse_mode') != 'grid-view')) {
        $('.view-digital-heritage-grid-list .view-content, .view-collections-grid-list .view-content').masonry('destroy');
    }

});