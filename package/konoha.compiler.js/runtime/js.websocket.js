js.websocket = function() {}
var initMessageEvent = function() {
	var me = function(rawptr) {
		this.rawptr = rawptr;
	}
	me.prototype = new konoha.Object();
	me.prototype.konohaclass = "js.websocket.MessageEvent";
	me.prototype.getData = function() {
		return new konoha.String(this.rawptr.data);
	}
	return me;
}
js.websocket.MessageEvent = new initMessageEvent();
var initWebSocket = function() {
	var verifyArgs = function(args) {
		for (var i = 0; i < args.length; i++) {
			if (args[i].rawptr) {
				args[i] = args[i].rawptr;
			}
		}
		return args;
	}
	var ws = function(rawptr) {
		this.rawptr = rawptr;
	}
	ws.prototype = new konoha.Object();
	ws.prototype.konohaclass = "js.websocket.WebSocket";
	ws.prototype._new = function() {
		if (arguments.length == 1) {
			return new ws(new WebSocket(arguments[0].rawptr));
		} else {
			return new ws(new WebSocket(arguments[0].rawptr, arguments[1].rawptr));
		}
	}
	ws.prototype.setOnOpen = function(m) {
		this.rawptr.onopen = function(e) {
			m.rawptr(new js.websocket.MessageEvent(e));
		}
	}
	ws.prototype.setOnMessage = function(m) {
		this.rawptr.onmessage = function(e) {
			m.rawptr(new js.websocket.MessageEvent(e));
		}
	}
	ws.prototype.setOnError = function(m) {
		this.rawptr.onerror = function(e) {
			m.rawptr(new js.websocket.MessageEvent(e));
		}
	}
	ws.prototype.setOnClose = function(m) {
		this.rawptr.onclose = function(e) {
			m.rawptr(new js.websocket.MessageEvent(e));
		}
	}
	ws.prototype.send = function(msg) {
		this.rawptr.send(msg.rawptr);
	}
	return ws;
}
js.websocket.WebSocket = new initWebSocket();
