js.websocket = function() {}
var initMessageEvent = function() {
	var me = function(rawptr) {
		this.rawptr = rawptr;
	}
	me.prototype = new konoha.Object();
	me.prototype.konohaclass = "js.websocket.MessageEvent";
	me.getData = function() {
		return new konoha.String(me.data);
	}
}
js.websocket.MessageEvent = new initMessageEvent();
var initWebSocket = function() {
	var ws = function(rawptr) {
		this.rawptr = rawptr;
	}
	ws.prototype = new konoha.Object();
	ws.prototype.konohaclass = "js.websocket.WebSocket";
	ws._new = function(host) {
		return new ws(new WebSocket(host.rawptr));
	}
	ws.setOnOpen = function(m) {
		ws.rawptr.onopen = function(e) {
			m.rawptr(new js.websocket.MessageEvent(e));
		}
	}
	ws.setOnMessage = function(m) {
		ws.rawptr.onmessage = function(e) {
			m.rawptr(new js.websocket.MessageEvent(e));
		}
	}
	ws.setOnError = function(m) {
		ws.rawptr.onerror = function(e) {
			m.rawptr(new js.websocket.MessageEvent(e));
		}
	}
	ws.setOnClose = function(m) {
		ws.rawptr.onclose = function(e) {
			m.rawptr(new js.websocket.MessageEvent(e));
		}
	}
	ws.send = function(msg) {
		this.rawptr.send(msg.rawptr);
	}
	return ws;
}
js.websocket.WebSocket = new initWebSocket();
