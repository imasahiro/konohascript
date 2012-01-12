/* Math */
konoha.Math = function() {
}

konoha.Math.prototype = new konoha.Object();
konoha.Math.prototype.konohaclass = "konoha.math.Math";
konoha.Math.prototype.sqrt = function(f) {
    return Math.sqrt(f);
}
konoha.Math.prototype.cos = function(f) {
    return Math.cos(f);
}
konoha.Math.prototype.sin = function(f) {
    return Math.sin(f);
}
konoha.Math.prototype.floor = function(f) {
    return Math.floor(f);
}
konoha.Math.abs = function(f) {
    return Math.abs(f);
}
