(function ($) {
    // Sync checkboxes -> chosen
    $(document).on("click", "#mukurtu-taxonomy-records-manage-record-form .form-item-terms .form-checkbox", function() {
	var box = $(this);
	var select = $("#edit-terms-all");

	// User clicked checkbox. Sync that value with the select control for all terms
	$("#edit-terms-all option[value='" + box.val() + "']").prop('selected', box.is(':checked'));

	// Update chosen
	$("#edit-terms-all").trigger("chosen:updated");
    });

    // Sync chosen -> checkboxes
    $(document).on("change", "select#edit-terms-all", function(event, params) {
	if(params.deselected) {
	    $("#edit-terms input:checkbox[value='" + params.deselected + "']").prop('checked', false);
	}

	if(params.selected) {
	    $("#edit-terms input:checkbox[value='" + params.selected + "']").prop('checked', true);
	}
    });

})(jQuery);
