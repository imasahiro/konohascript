/* Math */
js.math = function() {
}
js.math.Math = function() {
}

js.math.Math.prototype = new konoha.Object();
js.math.Math.prototype.konohaclass = "js.math.Math";
js.math.Math.sqrt = function(f) {
    return Math.sqrt(f);
}
js.math.Math.cos = function(f) {
    return Math.cos(f);
}
js.math.Math.sin = function(f) {
    return Math.sin(f);
}
js.math.Math.floor = function(f) {
    return Math.floor(f);
}
js.math.Math.abs = function(f) {
    return Math.abs(f);
}
js.math.Math.fabs = function(f) {
    return Math.abs(f);
}
