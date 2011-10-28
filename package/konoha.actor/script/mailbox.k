using konoha.io.*;
using konoha.socket.*;

// we only suppose
// mailbox.k $(port)
void main(String[] args)
{
	int port = 2000;
	if (|args| > 0) {
		port = (int)args[0];
	}

	ServerSocket ss = new ServerSocket(port, 3);
	while (true) {
		try {
			Socket conn = ss.accept();
			InputStream ins = conn.getInputStream();
			String msg = ins.readMsgPack();
			if (msg == "close()" + EOL) {
				break;
			}
			OUT << msg << EOL;
			conn.close();
		} catch (Exception!! e) {
			ERR << e << EOL;
		}
	}
	ss.close();
}
