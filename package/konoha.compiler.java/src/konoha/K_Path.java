package konoha;

public class K_Path {
	
	private String path;
	
	public K_Path(String str) {
		path = str;
	}
	
	public static K_Path create(String s) {
		return new K_Path(s);
	}
	
	@Override public String toString() {
		return path;
	}
	
}
