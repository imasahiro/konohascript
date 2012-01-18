package konoha;

public class K_Regex extends K_Object {
	
	public static K_Regex create(String s) {
		return new K_Regex(s);
	}
	
	private final String s;
	
	public K_Regex(String s) {
		this.s = s;
	}
	
	public String toString() {
		return s;
	}
	
}