package konoha;

public class K_Class extends K_Object {
	
	public static K_Class create(String name) {
		return new K_Class(name);
	}
	
	private final String name;
	
	public K_Class(String name) {
		this.name = name;
	}
	
	public String toString() {
		return name;
	}
	
}
