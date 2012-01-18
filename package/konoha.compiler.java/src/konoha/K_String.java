package konoha;

public class K_String extends K_Object {
	
	public static K_String create(String s) {
		return new K_String(s);
	}
	
	private final String string;
	
	public K_String(String s) {
		this.string = s;
	}
	
	public boolean equals(String s) {
		return string.equals(s);
	}
	
	public boolean equals(K_Object o) {
		return string.equals(o.toString());
	}
	
	public String toString() {
		return string;
	}
	
	public K_Array split(K_Regex r) {
		K_Array a = new K_Array();
		for(String s : string.split(r.toString())) {
			a.add1(new K_String(s));
		}
		return a;
	}
	
	public K_String substring(int n, int len) {
		return new K_String(string.substring(n, n + len));
	}
	
	public boolean startsWith(K_String s) {
		return string.startsWith(s.string);
	}
	
	public boolean endsWith(K_String s) {
		return string.endsWith(s.string);
	}
	
	public int indexOf(K_String s) {
		return string.indexOf(s.string);
	}
	
	public int getSize() {
		return string.length();
	}
	
	public K_String get(int n) {
		char c = string.charAt(n);
		return new K_String(Character.toString(c));
	}
	
	public K_String replace(K_Regex r, K_String s) {
		return new K_String(string.replaceAll(r.toString(), s.string));
	}
	
	public K_String minus(K_String s) {
		return new K_String(string.replaceAll(s.string, ""));
	}
	
	public K_Path castPath() {
		return new K_Path(string);
	}
	
	public K_Iterator toIterator() {
		return new K_Iterator() {
			int index = 0;
			
			public boolean hasNext() {
				return index < string.length();
			}

			@Override
			public K_Object getNext() {
				return get(index++);
			}
			
		};
	}
	
}