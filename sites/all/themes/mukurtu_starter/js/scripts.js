jQuery(document).ready(function($){
    $(window).load(function(){
	// --- masonry initializer --- //
	var $container = $('.masonry-grid .view-content');

	// initialize
	$container.masonry({
            itemSelector: '.masonry-brick',
            columnWidth: 227
	});
    });

    var $container_grid = $('.view-digital-heritage-grid-list .view-content, .view-collections-grid-list .view-content');
    $container_grid.masonry({
        itemSelector: '.views-row'
    });

    if ( ($.cookie('dh_browse_mode') != 'grid-view')) {
        $('.view-digital-heritage-grid-list .view-content, .view-collections-grid-list .view-content').masonry('destroy');
    }

    // ckedtor tooltip fix
    // The ckeditor hides the original field textarea, which is where the tooltip is attached.
    // Copy the tooltip to the parent wrapper.
    var options = Drupal.settings.bootstrap.tooltipOptions;
    $('.ckeditor-mod[data-toggle="tooltip"]').each(function() {
	jQuery(this).parent().attr('data-toggle', 'ckeditor-tooltip');
	jQuery(this).parent().attr('title', jQuery(this).attr('data-original-title'));
    });
    $('[data-toggle="ckeditor-tooltip"]').tooltip(options);
});
