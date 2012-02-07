package konoha;

import java.io.*;

public class K_System extends K_Object {
	
	private static final K_OutputStream stdout = new K_OutputStream();
	private static final K_InputStream  stdin  = new K_InputStream();
	private static final K_OutputStream stderr = new K_OutputStream();
	static {
		stdout.out = System.out;
		stdin.in = new BufferedReader(new InputStreamReader(System.in));
		stderr.out = System.err;
	}
	
	public static K_OutputStream getOut() {
		return stdout;
	}
	
	public static K_InputStream getIn() {
		return stdin;
	}
	
	public static K_OutputStream getErr() {
		return stderr;
	}
	
	public static int getTime() {
		return (int)System.currentTimeMillis();
	}
	
	public static int castInt(String s) {
		return Integer.parseInt(s);
	}
	
	public static double castFloat(String s) {
		return Double.parseDouble(s);
	}
	
	public static void print(String varName, int n1, int n2, Object obj) {
		System.out.printf("(line %d) ", n1);
		if(varName == null || varName.equals("")) {
			System.out.println(obj);
		} else {
			System.out.println(varName + "=" + obj);
		}
	}
	
	public static Object getProp(K_String str) {
		return new K_Array();//TODO
	}
	
}
