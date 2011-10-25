/*
 * Start konoha actor processes before executing this script.
 * $ konoha -p2000
 * $ konoha -p2001
 */

using konoha.actor.*;

void main(String[] args)
{
	ping = actor:localhost:2000;
	pong = actor:localhost:2001;
	try {
		ping.eval("""
using konoha.actor.*;

pong = actor:localhost:2001;

void recvmsg(String msg) {
	OUT << 'Ping: ' + msg << EOL;
	pong.eval("recvmsg('ping')");
}
""");
	} catch (Script!! s) {
		OUT << "please run $ konoha -p2000" << EOL;
		exit(0);
	}
	try {
		pong.eval("""
using konoha.actor.*;

ping = actor:localhost:2000;

count = 100;

void recvmsg(String msg) {
	OUT << 'Pong: ' + msg << EOL;
	OUT << 'count: ' + count-- << EOL;
	if (count == 0) {
		ping.close();
		exit(0);
	} else {
		ping.eval("recvmsg('pong')");
	}
}
""");
	} catch (Script!! s) {
		OUT << "please run $ konoha -p2001" << EOL;
		exit(0);
	}
	ping.eval("recvmsg('kick')");
}
