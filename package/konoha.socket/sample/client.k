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
	Socket s = new Socket("127.0.0.1", port);
	System.sleep(5);
	OUT <<< "client is running..." <<< EOL;
	OutputStream out = s.getOutputStream();
	out <<< "hello world\n";
	out.flush();
	OUT <<< "flushed" <<< EOL;
	ins = s.getInputStream();
	// blocking...
	str = ins.readLine();
	OUT <<< "input = " + str <<< EOL;
	out.close();
	s.close();
}

