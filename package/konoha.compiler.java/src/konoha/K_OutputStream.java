package konoha;

import java.io.*;

public class K_OutputStream extends K_Object {
	
	public StringBuilder cwb = new StringBuilder();
	public PrintStream out;
	
	public static K_OutputStream getCwb() {
		return new K_OutputStream();
	}
	
	public K_OutputStream _new(K_Path name, String mode, K_Map map) {
		try {
			out = new PrintStream(new BufferedOutputStream(new FileOutputStream(name.toString())));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		return this;
	}
	
	public void print(Object o) {
		out.print(o);
	}

	public void println(Object o) {
		out.println(o);
	}

	public void putByte(int n) {
		out.write(n);
	}
	
	public void write(K_Bytes bytes, int offset, int length) {
		out.write(bytes.data, offset, length);
	}
	
	public void flush() {
		out.flush();
	}
	
	public void close() {
		out.close();
	}
	
	public void send(String s) {
		if(s.equals("\n")) {
			out.println(cwb.toString());
			cwb = new StringBuilder();
		} else {
			cwb.append(s);
		}
	}
	
	public void sendInt(int n) {
		cwb.append(n);
	}
	
	public void sendFloat(double n) {
		cwb.append(n);
	}
	
	public void sendBoolean(boolean n) {
		cwb.append(n);
	}
	
	public String toStr() {
		return cwb.toString();
	}
	
}
