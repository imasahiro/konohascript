
using konoha.socket.*;
using konoha.posix.*;

void main(String[] args) {
	int argc = |args|;
	int port = 12345;
	if (argc < 2) {
		OUT <<< "warining: you need port number" <<< EOL;
	} else {
		port = (int)args[0]
	}
	int ch;
	String line = "";
	OUT << "port: " + port << EOL;
	ServerSocket ss = new ServerSocket(port, 3);

//  you can choose socket parameters
//	ss.setSoTimeout(10000);
//	ss.setReceiveBufferSize(10000);

	print ss.localPort, ss.receiveBufferSize, ss.soTimeout, ss.reuseAddress;
	while (true){
		Socket connection = ss.accept();
		OUT << "accepted" << EOL;
		System.sleep(5);
		if (!connection.isClosed()) {
			i = connection.getInputStream();
			// blocking...
			out = connection.getOutputStream();
			foreach (String line in i) {
				OUT << line << EOL;
				out << "echo back" << EOL;
				out.flush();
			}
			print "bye";
			connection.close();
		} else {
			OUT << "socket has been closed by the peer" << EOL;
		}
		OUT << "connection closed" << EOL;
	}
	ss.close();
}
