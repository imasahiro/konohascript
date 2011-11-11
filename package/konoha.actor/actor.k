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

class Actor
{
	String name;
	String host;
	int port;
	String role;
	String task;

	Actor(String name, String host, int port) {
		_name = name;
		_host = host;
		_port = port;
		try {
			Socket s = new Socket(host, port);
			Map ldata = {};
			ldata["name"] = name;
			ldata["host"] = host;
			ldata["port"] = port;
			System.ntrace_notice("actor:new", ldata);
			OutputStream ous = s.getOutputStream();
			ous.writeMsgPack("ping");
			ous.close();
			s.close();
		} catch (Exception!! e) {
			throw new Script!!("cannot establish connection to host: " + host + ", port: " + (to String)port);
		}
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

	@Virtual boolean eval(String script) {
		try {
			Socket s = new Socket(this.host, this.port);
			OutputStream ous = s.getOutputStream();
			ous.writeMsgPack(script);
			ous.flush();
			ous.close();
			s.close();
		} catch (Exception!! e) {
			throw new Script!!("cannot establish connection to host: " + host + ", port: " + (to String)port);
		}
		return true;
	}

	boolean evalFile(Path urn) {
		InputStream ins = new InputStream(urn, "r");
		String buf = "";
		foreach (String line in ins) {
			buf += line + EOL;
		}
		this.eval(buf);
		ins.close();
		return true;
	}

	void interactive(String task_name) {
		String script = "";
		int n = 1;
		while (true) {
			String line = System.readLine("(ash:" + n++ + ") ");
			if (line == null) {
				break;
			}
			script += line + EOL;
		}
		OUT << EOL;
		startTask(task_name);
		eval(script);
		endTask();
	}

	void startTask(String task_name, String role) {
		_task = task_name;
		_role = role;
		if (role == null) {
			_role = "Role";
		}
		this.eval("<< " + role + ":" + task);
	}

	void endTask() {
		this.eval(">> " + role + ":" + task);
	}

	boolean close() {
		this.eval("close()");
		Map ldata = {};
		ldata["name"] = name;
		ldata["host"] = host;
		ldata["port"] = port;
		System.ntrace_notice("actor:close", ldata);
		return true;
	}
}

class StoreActor
{
	Map m;
	String name;

	StoreActor(String name, String host, int port) {
		_m = Map.open("memcached:" + host + ":" + (to String)port);
		if (_m == null) throw new Script!!("cannot open memcached");
		_name = name;
	}

	dynamic get(String key) {
		if (m[key] == null) return null;
		Bytes b;
		if (m[key] <: String)
			b = (to Bytes)(to String)m[key];
		else
			b = m[key];
		return b.readMsgPack(0, |b|);
	}

	void set(String key, Object data) {
		Bytes b = new Bytes();
		b.writeMsgPack(data);
		m[key] = b;
	}
}
