package konoha;

public class K_Boolean extends K_Object {
	
	private final boolean b;
	
	public K_Boolean(boolean b) {
		this.b = b;
	}
	
	public String toString() {
		return Boolean.toString(b);
	}
	
	public static K_Boolean box(boolean n) {
		return new K_Boolean(n);
	}
	
	public static boolean unbox(K_Boolean n) {
		return n != null ? n.b : false;
	}

}
