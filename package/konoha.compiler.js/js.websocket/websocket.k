class WebSocket {
	void setOnOpen(Method m);
	void setOnMessage(Method m);
	void setOnError(Method m);
	void setOnClose(Method m);
	void send(String msg);
}
WebSocket WebSocket.new(String host);
