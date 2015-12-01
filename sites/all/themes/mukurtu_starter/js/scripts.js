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

    if ( ($.cookie('dh_browse_mode') != 'grid-view')) {
        $('.view-digital-heritage-grid-list .view-content, .view-collections-grid-list .view-content').masonry('destroy');
    }


});