using konoha.proc.*;
using konoha.socket.*;
using konoha.posix.*;
using konoha.io.*;

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

String dispatch(String cmd, String role, String id, String dtask, String data, OutputStream ous) {
    if (cmd == null) {
        return "";
    }
    print cmd.split(" ")[0];
    print cmd;
    print data;
    cmd = cmd.split(" ")[0];
    if (cmd == "TCHECK") {
        fname = join([role, id], ".") + "k";
        ous = new OutputStream(fname);
        ous.println(data);
        ous.close();
        line = join([$konoha.bin.path, "-a", "-c", "--enforce-security=" + role, fname], " ");
        print line;
        String res = System.exec(line);
        print res;
        ous.println("TCHECK OK");
        ous.println("Content-Length: " + res.size);
        ous.println("");
        ous.println("");
        ous.print(res);
        print res;
        ous.flush();
        return res;
    } else if (cmd == "EVAL") {
    } else if (cmd == "DEBUG") {
    }
    return data;
}

void main(String[] args) {
    int argc = |args|;
    int port = 8080;
    if (argc < 1) {
        OUT <<< "warining: you need port number" <<< EOL;
    } else {
        port = (int)args[0]
    }
    int ch;
    String line = "";
    OUT << "port: " + port << EOL;
    ServerSocket ss = new ServerSocket(port, 3);

    print ss.localPort, ss.receiveBufferSize, ss.soTimeout, ss.reuseAddress;
    while (true) {
        Socket connection = ss.accept();
        OUT << "accepted" << EOL;
        if (!connection.isClosed()) {
            ins = connection.getInputStream();
            // blocking...
            ous = connection.getOutputStream();
            protocol = ins.readLine();
            print protocol;
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
                //print line, i;
                if (line.startsWith("Auth")) {
                    auth = data;
                } else if (line.startsWith("ID")) {
                    id = data;
                } else if (line.startsWith("Content-Length")) {
                    length = (Int) data;
                } else if (line.startsWith("D-Task")) {
                    dtask = data;
                }
            }
            String s = ins.readAll(length);
            print auth, id, dtask, length, s;
            String res = dispatch(protocol, auth, id, dtask, s, ous);
            print "bye";
            connection.close();
        } else {
            OUT << "socket has been closed by the peer" << EOL;
        }
        OUT << "connection closed" << EOL;
    }
    ss.close();
}

