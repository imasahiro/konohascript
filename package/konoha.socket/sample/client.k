using konoha.socket.*;

void main(String[] args) {
	Socket s = new Socket("127.0.0.1", 12345);
	OUT <<< "client is running..." <<< EOL;
	OutputStream out = s.getOutputStream();
	out <<< "hi\n";
	out.flush();
	OUT <<< "flushed" <<< EOL;
	ins = s.getInputStream();
	str = ins.readLine();
	OUT <<< str <<< EOL;
	out.close();
	s.close();
}

