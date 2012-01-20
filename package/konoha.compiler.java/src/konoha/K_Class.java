package konoha;

public class K_Class extends K_Object {
	
	private final Class<?> klass;
	
	public K_Class(String name) {
		Class<?> c;
		try {
			c = Class.forName(name);
		} catch(ClassNotFoundException e) {
			e.printStackTrace();
			c = null;
		}
		klass = c;
	}
	
}
