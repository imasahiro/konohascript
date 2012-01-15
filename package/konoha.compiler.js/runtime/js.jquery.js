document.write("<script type='text/javascript' src='jquery-1.7.1.min.js'></script>");
js.jquery = function() {
}
var initJQuery = function() {
    var jquery= function(rawptr) {
        this.rawptr = rawptr;
    }
    jquery.prototype = new konoha.Object();
    console.log(jquery.konohaclass);
    jquery.konohaclass = "js.jquery.JQuery";

    console.log(jquery.konohaclass);
    return jquery;
}
js.jquery.JQuery = initJQuery();
console.log(js.jquery.JQuery.konohaclass);
console.log(new konoha.Object().konohaclass);
