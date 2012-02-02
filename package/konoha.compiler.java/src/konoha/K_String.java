package konoha;

public class K_String extends K_Object {
	
	private final String string;
	
	public K_String(String s) {
		this.string = s;
	}
	
	@Override public boolean equals(Object o) {
		if(o instanceof String || o instanceof K_String) {
			return o.toString().equals(string);
		}
		return false;
	}
	
	@Override public String toString() {
		return string;
	}
	
	public static K_String box(String s) {
		return new K_String(s);
	}
	
	public static String unbox(K_String n) {
		return n != null ? n.string : "";
	}
	
	public static K_Array split(String self, K_Regex r) {
		K_Array a = new K_Array();
		for(String s : self.split(r.toString())) {
			a.add1(new K_String(s));
		}
		return a;
	}
	
	public static String substring(String self, int n, int len) {
		return self.substring(n, n + len);
	}
	
	public static boolean startsWith(String self, String s) {
		return self.startsWith(s);
	}
	
	public static boolean endsWith(String self, String s) {
		return self.endsWith(s);
	}
	
	public static int indexOf(String self, String s) {
		return self.indexOf(s);
	}
	
	public static int getSize(String self) {
		return self.length();
	}
	
	public static String trim(String self) {
		return self.trim();
	}
	
	public static String get(String self, int n) {
		return Character.toString(self.charAt(n));
	}
	
	public static String replace(String self, K_Regex r, String s) {
		return self.replaceAll(r.toString(), s);
	}
	
	public static String minus(String self, String s) {
		return self.replaceAll(s, "");
	}
	
	public static K_Path castPath(String self) {
		return new K_Path(self);
	}
	
	public static K_Iterator toIterator(final String self) {
		return new K_Iterator() {
			private int index = 0;
			@Override public boolean hasNext() {
				return index < self.length();
			}
			@Override public Object getNext() {
				return box(get(self, index++));
			}
			
		};
	}
	
}