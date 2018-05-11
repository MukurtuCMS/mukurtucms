jQuery(document).ready(function($){
    // Grid Handling for List/Grid views
    $mukurtuGridViewMasonryOptions = {
        itemSelector: '.views-row',
        gutter: 30
    }

    window.mukurtuGridActive = false;
    window.mukurtuGrid = null;

    function mukurtuMakeGrid() {
        if(window.mukurtuGridActive) {
            mukurtuDestroyGrid();
        }

        if( ($.cookie('dh_browse_mode') == 'grid-view')) {
            window.mukurtuGrid = jQuery('.grid-view').masonry($mukurtuGridViewMasonryOptions);
            window.mukurtuGridActive = true;
        }
    }
    
    function mukurtuDestroyGrid() {
        if(window.mukurtuGridActive && window.mukurtuGrid) {
            window.mukurtuGrid.masonry('destroy');
            window.mukurtuGridActive = false;
        }
    }

    $(window).load(function() {
        mukurtuMakeGrid();
        $('.view-header .btn.list').on ('click', function() { mukurtuDestroyGrid(); });
        $('.view-header .btn.grid').on ('click', function() { mukurtuMakeGrid(); });
    });

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
