document.write("<script type='text/javascript' src='jquery-1.7.1.min.js'></script>");
js.jquery = function() {
}
var initJQuery = function() {
    var jquery= function(rawptr) {
        this.rawptr = rawptr;
    }
    jquery.prototype = new konoha.Object();
    jquery.konohaclass = "js.jquery.JQuery";

    return jquery;
}
js.jquery.JQuery = initJQuery();
