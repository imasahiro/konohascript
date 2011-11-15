/****************************************************************************
 * KONOHA COPYRIGHT, LICENSE NOTICE, AND DISCRIMER
 *
 * Copyright (c)  2010-      Konoha Team konohaken@googlegroups.com
 * All rights reserved.
 *
 * You may choose one of the following two licenses when you use konoha.
 * See www.konohaware.org/license.html for further information.
 *
 * (1) GNU Lesser General Public License 3.0 (with KONOHA_UNDER_LGPL3)
 * (2) Konoha Software Foundation License 1.0
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER
 * OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

// **************************************************************************
// LIST OF CONTRIBUTERS
//  kimio - Kimio Kuramitsu, Yokohama National University, Japan
//  shinpei_NKT - Shinpei Nakata, Yokohama National University, Japan
//  goccy - Masaaki Goshima, Yokohama National University, Japan
//  chen_ji - Takuma Wakamori, Yokohama National University, Japan
// **************************************************************************

using konoha.socket.*;
using konoha.io.*;
using konoha.memcached.*;
using konoha.ntrace.*;
using konoha.posix.*;

String globalRole;

class Actor {
	String name;
	String host;
	int    port;

	String errorbuf;

	Actor(String name, String host, int port) {
		_name = name;
		_host = host;
		_port = port;
	}

	@Hidden Actor opLINK(String path, NameSpace _) {
		String[] link = path.split(":");
		if (|link| == 3) {
			return new Actor("default", link[1], (to int)link[2]);
		} else if (|link| == 4) {
			return new Actor(link[3], link[1], (to int)link[2]);
		}
		return null;
	}

	boolean tcheck(InputStream ins) {
		String protocol = ins.readLine();
		print protocol;
		Int length;
		while (true) {
			line = ins.readLine();
			print line;
			if (line == "") {
				break;
			}
			data = line.split(":")[1].trim();
			if (line.startsWith("Content-Length")) {
				length = (Int) data;
			}
		}
		b = new Bytes(length);
		ins.read(b, 0, length);
		this.errorbuf = b.decode(null);
		/* "OK" or "NG" */
		return protocol == "OK";
	}

	boolean send(String msg) {
		boolean res = false;
		try {
			Socket s = new Socket(this.host, this.port);
			InputStream  ins = s.getInputStream();
			OutputStream ous = s.getOutputStream();
			ous.println(msg);
			ous.flush();
			res = tcheck(ins);
			print errorbuf;
			s.close();
		} catch (Exception!! e) {
			print "Not Connected: ", host, port;
			return false;
		}
		return res;
	}

	boolean bind(String script, String role, String id) {
		msg = "TCHECK 0.9\nAuth: " + role + "\nD-Task: " + id + "\nContent-Length: " + (script.size + 1) +"\n\n" + script;
		return send(msg);
	}

	boolean eval(String script, Map map) {
		msg = "EVAL 0.9\n";
		for(String key : map.keys()) {
			msg += key + ": " + (String)map[key] + "\n";
		}
		msg += "Content-Length: " + (script.size + 1) + "\n\n" + script;
		return send(msg);
	}

	boolean debug(String script, Map map) {
		msg = "DEBUG 0.9\n";
		for(String key : map.keys()) {
			msg += key + ": " + (String)map[key] + "\n";
		}
		msg += "\n" + script;
		return send(msg);
	}

	@Static String loadScript(Path urn) {
		InputStream ins = new InputStream(urn, "r");
		String buf = "";
		foreach (String line in ins) {
			buf += line + EOL;
		}
		return buf;
	}

	@Static void setRole(String r) {
		globalRole = r;
	}
}


class DTrace {
	String id;
	int num;

	DTrace(String id, int parallel_num) {
		_id = id;
		_num = parallel_num;
		if (parallel_num == 0) {
			_num = 1;
		}
	}

	boolean checkTaskLog () {
		String host = "192.168.0.201"; /* diag */
		int port = 11211;
		Memcache mc = new Memcache(host, port);
		for (int i = 0; i < num; i++) {
			String result, key = id + "-" + (to String)i;
			while((result = mc[key]) == null) {
				System.usleep(1000);
			}
			print result;
			if(result == "FAILED") {
				return false;
			}
		}
		return true;
	}
}

class DTask {
	String name;
	String script;
	Actor[] actors;

	DTask(String name, String script) {
		_name = name;
		_script = script;
		_actors = [];
	}

	void load(Path urn) {
		InputStream ins = new InputStream(urn, "r");
		String buf = "";
		foreach (String line in ins) {
			buf += line + EOL;
		}
		_script = buf;
	}

	void show() {
		OUT << EOL << script << EOL;
	}

	boolean bind(Actor actor, String role) {
		String trace = CTX.getTrace();
		if(role == null) {
			role = globalRole;
		}
		if(actor.bind(script, role, name)) {
			_actors.add(actor);
			return true;
		}
		else {

		}
		return false;
	}

	DTrace go(String traceid) {
		for (int i = 0; i < |actors|; i++) {
			Actor actor = actors[i];
			actor.eval(script) with {
				"D-Task": name;
				"D-Trace": traceid + "-" + (String)i;
			}
			//String host = "192.168.0.201"; /* diag */
			//int port = 11211;
			//Memcache mc = new Memcache(host, port);
			//mc.add(traceid + (to String)i + ":start", (to String)new Date(), 0, 0);
			//mc.replace(traceid + (to String)i + ":start", (to String)new Date(), 0, 0);
		}
		return new DTrace(traceid, |actors|);
	}
}

class DControl {
	String name;
	DTask[] tasks;
	DTask   helper;

	DControl(String name, DTask helper) {
		_name = name;
		_tasks = [];
	}

	void go(String traceid) {
		for(int i = 0; i < |tasks|; i++) {
			DTask task = (DTask)tasks[i];
			DTrace trace = task.go(traceid + "-" + (String)i);
			if(trace.checkTaskLog()) continue;
			helper.go(traceid);
			task.go(traceid + "-" + (String)i + "-RETRY");
		}
	}
}

