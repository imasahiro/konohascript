package konoha;

public class K_Boolean extends K_Object {
	
	public boolean b;
	
	public K_Boolean(boolean b) {
		this.b = b;
	}
	
	public String toString() {
		return Boolean.toString(b);
	}

}
