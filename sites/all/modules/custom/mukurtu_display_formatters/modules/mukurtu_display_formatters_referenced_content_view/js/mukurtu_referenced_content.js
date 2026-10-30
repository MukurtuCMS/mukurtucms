// Scroll to the referenced content
jQuery(document).ready(function($) {
    var referenced_content = jQuery("[name='found-in']");

    if(referenced_content.length > 0) {
	referenced_content[0].scrollIntoView(true);
    }
});
