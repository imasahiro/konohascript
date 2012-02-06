package konoha;

public class K_Class extends K_Object {
	
	private final Class<?> klass;
	
	public K_Class(String name) throws ClassNotFoundException {
		klass = Class.forName(name);
	}
	
}
