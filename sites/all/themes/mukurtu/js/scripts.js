jQuery(document).ready(function($){
    // Grid Handling for List/Grid views
    $mukurtuGridViewMasonryOptions = {
        itemSelector: '.views-row',
        gutter: 30
    }

    window.mukurtuGridActive = false;
    window.mukurtuGrid = null;

    function mukurtuGridListMejsResize() {
        for (var pKey in mejs.players) {
            mejs.players[pKey].setPlayerSize();
            mejs.players[pKey].setControlsSize();
        };
    }

    function mukurtuMakeGrid() {
        if(window.mukurtuGridActive) {
            mukurtuDestroyGrid();
        }

        if($.cookie) {
            if( ($.cookie('dh_browse_mode') == 'grid-view')) {
                mukurtuGridListMejsResize();
                window.mukurtuGrid = jQuery('.grid-view').masonry($mukurtuGridViewMasonryOptions);
                window.mukurtuGrid.on('layoutComplete', mukurtuGridListMejsResize);
                window.mukurtuGrid.on('removeComplete', mukurtuGridListMejsResize);
                window.mukurtuGridActive = true;
            }
        }
    }

    function mukurtuDestroyGrid() {
        if(window.mukurtuGridActive && window.mukurtuGrid) {
            window.mukurtuGrid.masonry('destroy');
            window.mukurtuGridActive = false;
            mukurtuGridListMejsResize();
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
    try {
        $('[data-toggle="ckeditor-tooltip"]').tooltip(options);
    } catch (err) {

    }

    // Hide the add new comment block title if the user can't see the form.
    if ($('#comments form.comment-form').length == 0) {
        $('#comments .title.comment-form').hide();
    }
});
