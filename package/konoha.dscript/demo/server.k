using konoha.proc.*;
using konoha.socket.*;
using konoha.posix.*;
using konoha.io.*;
using konoha.ntrace.*;

HOST="192.168.0.201";
PORT=11211;

DEBUG=false;

@Public String InputStream.readAll(int length) {
	InputStream ins = this;
	b = new Bytes(length);
	ins.read(b, 0, length);
	return b.decode(null);
}

String join(String[] args, String d) {
	String line = "";
	foreach (String s in args) {
		line = line + s + d;
	}
	return line;
}

String readError(InputStream err) {
	String res = "";
	foreach (String line in err) {
		res += line + EOL;
	}
	return res;
}

String dispatch(String cmd, String role, String id, String dtask, String data, OutputStream ous) {
	if (cmd == null) {
		return "";
	}
	if (DEBUG) print cmd.split(" ")[0];
	if (DEBUG) print cmd;
	if (DEBUG) print data;
	cmd = cmd.split(" ")[0];
	String fname = "/tmp/" + join([dtask], ".") + "k";
	if (DEBUG) print fname;
	if (cmd == "TCHECK") {

		o = new OutputStream(fname);
		o << "using konoha.memcached.*;" << EOL;
		o << "using konoha.posix.*;" << EOL;
		o << "{" << EOL;
		o << "\tMemcache ctxid_memcache = new Memcache(\"" << HOST << "\", " << PORT << ");" << EOL;
		o << "\tctxid_memcache.set(\"" + dtask + "\" + \":\" + System.getHostName(), CTX.getTrace(), 0, 0);" << EOL;
		o << "\tString g_syslogpath = \"/var/log/syslog\";" << EOL;
		o << "\tif (System.getHostName() == \"chen-pro.local\") g_syslogpath = \"/var/log/system.log\";" << EOL;
		o << "\tOutputStream g_syslog = new OutputStream(g_syslogpath, \"a\");" << EOL;
		o << "\tg_syslog << (to String)new Date() << \" \" << System.getHostName()";
		o << " << \" konoha[\" << (to String)System.getPid() << \"]: \" << CTX.getTrace()";
		o << " << \"+\" << (to String)CTX.getSeq() << \" task_start {\\\"name\\\": \\\"";
		o << dtask << "\\\", \\\"role\\\": \\\"" << role << "\\\"}\" << EOL;" << EOL;
		o << "\tg_syslog.close();" << EOL << "}" << EOL;
		o.println(data);
		o << "{" << EOL;
		o << "\tString g_syslogpath = \"/var/log/syslog\";" << EOL;
		o << "\tif (System.getHostName() == \"chen-pro.local\") g_syslogpath = \"/var/log/system.log\";" << EOL;
		o << "\tOutputStream g_syslog = new OutputStream(g_syslogpath, \"a\");" << EOL;
		o << "\tg_syslog << (to String)new Date() << \" \" << System.getHostName()";
		o << " << \" konoha[\" << (to String)System.getPid() << \"]: \" << CTX.getTrace()";
		o << " << \"+\" << (to String)(CTX.getSeq() + 1) << \" task_end {\\\"name\\\": \\\"";
		o << dtask << "\\\", \\\"role\\\": \\\"" << role << "\\\"}\" << EOL;" << EOL;
		o << "\tg_syslog.close();" << EOL;
		o << "\tMemcache ctxid_memcache = new Memcache(\"" << HOST << "\", " << PORT << ");" << EOL;
		o << "\tctxid_memcache.delete(\"" + dtask + "\" + \":\" + System.getHostName(), 0);" << EOL;
		o.close();
		Proc proc new Proc([$konoha.bin.path, "-a", "-c", "--enforce-security=" + role, fname]);

		String res = "";//readError(proc.getErrorInputStream());
		if (DEBUG) print res;

		String data = "OK"+EOL+"Content-Length: " + res.size+ EOL + res;
		ous.println(data);
		ous.flush();
		return res;
	} else if (cmd == "EVAL") {
		if (DEBUG) print role, id, dtask, data, fname;

		Map ldata = {};
		ldata["role"] = role;
		ldata["id"] = id;
		ldata["dtask"] = dtask;
		ldata["data"] = data;
		ldata["fname"] = fname;
		if (DEBUG) print ldata;
		System.ntrace_notice("d-task", ldata);

		ous = new OutputStream(fname, "a");
		ous << "\tctxid_memcache.set(\"" + id + "\", \"OK\", 0, 0);" << EOL;
		ous << "}" << EOL;
		ous.close();
		ins = new InputStream(fname);
		foreach (String l in ins) {
			if (DEBUG) print l;
		}
		if (DEBUG) print $konoha.bin.path, fname;
		//Proc proc = new Proc([$konoha.bin.path, "-a", "--logcached=" + HOST + ":" + PORT, fname], null, true);
		//Memcache mc = new Memcache(HOST, PORT);
		//mc[id] = "OK";
		//Proc proc = new Proc([$konoha.bin.path, "-a", fname], null, true);
		String cmdline = join([$konoha.bin.path, "-a", fname, "--logcached=" + HOST + ":" + PORT], " ");
		if (DEBUG) print cmdline;
		int ret = System.thread(cmdline);
		if (DEBUG) print "**";
		String res = "";//readError(proc.getErrorInputStream());
		if (DEBUG) print "**";
		if (DEBUG) print "**";
		String data = "OK"+EOL+"Content-Length: " + res.size+ EOL + res;
		if (DEBUG) print "hi";
		ous.println(data);
		ous.flush();
		if (DEBUG) print "hi";
		return res;
	} else if (cmd == "DEBUG") {
	}
	return data;
}

void main(String[] args) {
	int argc = |args|;
	int port = 8080;
	if (argc < 1) {
		if (DEBUG) OUT <<< "warining: you need port number" <<< EOL;
	} else {
		port = (int)args[0]
	}
	int ch;
	String line = "";
	if (DEBUG) OUT << "port: " + port << EOL;
	ServerSocket ss = new ServerSocket(port, 3);

	if (DEBUG) print ss.localPort, ss.receiveBufferSize, ss.soTimeout, ss.reuseAddress;
	while (true) {
		Socket connection = ss.accept();
		if (DEBUG) print connection.isClosed();
		System.usleep(1000);
		if (DEBUG) OUT << "accepted" << EOL;
		if (!connection.isClosed()) {
			ins = connection.getInputStream();
			// blocking...
			ous = connection.getOutputStream();
			protocol = ins.readLine();
			if (DEBUG) print protocol;
			String auth;
			String id;
			String dtask;
			Int length;
			while (true) {
				line = ins.readLine();
				if (line == "") {
					break;
				}
				data = line.split(":")[1].trim();
				//if (DEBUG) print line, i;
				if (line.startsWith("Auth")) {
					auth = data;
				} else if (line.startsWith("D-Trace")) {
					id = data;
				} else if (line.startsWith("Content-Length")) {
					length = (Int) data;
				} else if (line.startsWith("D-Task")) {
					dtask = data;
				}
			}
			String s = ins.readAll(length);
			if (DEBUG) print auth, id, dtask, length, s;
			String res = dispatch(protocol, auth, id, dtask, s, ous);
			if (DEBUG) print "bye";
			connection.close();
		} else {
			if (DEBUG) OUT << "socket has been closed by the peer" << EOL;
		}
		if (DEBUG) print connection.isClosed();
		if (DEBUG) OUT << "connection closed" << EOL;
	}
	ss.close();
}

