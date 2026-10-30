(function ($) {
    // Mukurtu Records Record Management Custom Widget
    $(document).on("click", "#edit-field-mukurtu-terms-und-mukurtu-record-terms .form-checkbox", function() {
	var box = $(this);
	var select = $("[id^=edit-field-mukurtu-terms-und-mukurtu-record-terms-all]");

	// User clicked checkbox. Sync that value with the select control for all terms
	$("[id^=edit-field-mukurtu-terms-und-mukurtu-record-terms-all] option[value='" + box.val() + "']").prop('selected', box.is(':checked'));

	// Update chosen
	$("[id^=edit-field-mukurtu-terms-und-mukurtu-record-terms-all]").trigger("chosen:updated");
    });

    // Sync chosen -> checkboxes
    $(document).on("change", "select[id^=edit-field-mukurtu-terms-und-mukurtu-record-terms-all]", function(event, params) {
	if(params.deselected) {
	    $("#edit-field-mukurtu-terms-und-mukurtu-record-terms input:checkbox[value='" + params.deselected + "']").prop('checked', false);
	}

	if(params.selected) {
	    $("#edit-field-mukurtu-terms-und-mukurtu-record-terms input:checkbox[value='" + params.selected + "']").prop('checked', true);
	}
    });

})(jQuery);
