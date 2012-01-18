package konoha;

public class K_System extends K_Object {
	
	public static K_OutputStream stdout = new K_OutputStream();
	
	public static K_OutputStream getOut() {
		return stdout;
	}
	
	public static int getTime() {
		return (int)System.currentTimeMillis();
	}
	
	public static K_Int boxInt(int n) {
		return new K_Int(n);
	}
	
	public static K_Float boxFloat(double n) {
		return new K_Float(n);
	}
	
	public static K_Boolean boxBoolean(boolean n) {
		return new K_Boolean(n);
	}
	
	public static int unboxInt(K_Int n) {
		return n != null ? n.n : 0;
	}
	
	public static double unboxFloat(K_Float n) {
		return n != null ? n.n : 0.0;
	}
	
	public static boolean unboxBoolean(K_Boolean n) {
		return n != null ? n.b : false;
	}
	
	public static int castInt(K_String obj) {
		return Integer.parseInt(obj.toString());
	}
	
	public static double castFloat(K_String obj) {
		return Double.parseDouble(obj.toString());
	}
	
	public static void print(String varName, int n1, int n2, Object obj) {
		System.out.printf("(line %d) ", n1);
		if(varName == null) {
			System.out.println(obj);
		} else {
			System.out.println(varName + "=" + obj);
		}
	}
	
	public static Object getProp(K_String str) {
		return new K_Array();//TODO
	}
	
}
