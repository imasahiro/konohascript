class MessageEvent {
	String getData();
}
class WebSocket {
	void setOnOpen(Method m);
	void setOnMessage(Method m);
	void setOnError(Method m);
	void setOnClose(Method m);
	void send(String msg);
}
@Overload WebSocket WebSocket.new(String host);
@Overload WebSocket WebSocket.new(String host, String protocol);
