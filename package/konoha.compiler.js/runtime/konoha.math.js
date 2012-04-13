/* Math */
konoha.math = function() {
}
konoha.math.Math = function() {
}

konoha.math.Math.prototype = new konoha.Object();
konoha.math.Math.prototype.konohaclass = "konoha.math.Math";
konoha.math.Math.sqrt = function(f) {
    return Math.sqrt(f);
}
konoha.math.Math.cos = function(f) {
    return Math.cos(f);
}
konoha.math.Math.sin = function(f) {
    return Math.sin(f);
}
konoha.math.Math.floor = function(f) {
    return Math.floor(f);
}
konoha.math.Math.abs = function(f) {
    return Math.abs(f);
}
konoha.math.Math.fabs = function(f) {
    return Math.abs(f);
}
