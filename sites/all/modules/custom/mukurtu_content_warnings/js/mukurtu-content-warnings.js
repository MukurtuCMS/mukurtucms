function mukurtu_remove_content_warning(id) {
    jQuery(".mukurtu-content-warning-" + id).removeClass("mukurtu-content-warning");
    jQuery(".mukurtu-content-warning-instance-" + id).addClass("cleared");
}
