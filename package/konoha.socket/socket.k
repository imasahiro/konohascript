@Native class Socket;
include objectlink;

Socket Socket.new(String ip_addr, Int port);
void Socket.close();
boolean Socket.beClosed();
InputStream Socket.getInputStream();
OutputStream Socket.getOutputStream();

class ServerSocket extends Socket;
ServerSocket ServerSocket.new(Int port, Int maxConnection);
Socket ServerSocket.accept();

