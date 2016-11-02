function reveal_deceased(id) {
    jQuery("#deceased-" + id).removeClass("deceased");
    jQuery("#deceased-warning-" + id).addClass("cleared");
}
