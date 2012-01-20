document.write("<script type='text/javascript' src='jquery-1.7.1.min.js'></script>");
js.offset = function(rawptr) {
    this.rawptr = rawptr;
}
js.offset.prototype = new konoha.Object();
js.offset.prototype.new = function(top, left) {
    this.rawptr = {
     top: top,
     left: left
    };
}
js.offset.prototype.getTop = function() {
    return this.rawptr.top;
}
js.offset.prototype.getLeft = function() {
    return this.rawptr.left;
}

js.jquery = function(rawptr) {
}
var initJQuery = function() {
    var jquery= function(rawptr) {
        this.rawptr = rawptr;
    }
    jquery.prototype = new konoha.Object();
    jquery.konohaclass = "js.jquery.JQuery";
    jquery.prototype.new = function() {
        if (arguments.length == 2) {
            this.rawptr = $(arguments[0].rawptr, arguments[1].rawptr);
        } else if (arguments.length == 1) {
            this.rawptr = $(arguments[0].rawptr);
        } else {
            throw("Script!!");
        }
    }
    return new jquery();
}
js.jquery.JQuery = initJQuery();
