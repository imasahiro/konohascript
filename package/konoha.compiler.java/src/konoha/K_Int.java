package konoha;

public class K_Int extends K_Number {
	
	private final int n;
	
	public K_Int(int n) {
		this.n = n;
	}
	
	public static int random(int n) {
		if(n > 0) {
			return random.nextInt(n);
		} else {
			return random.nextInt();
		}
	}
	
	public String toString() {
		return Integer.toString(n);
	}
	
	public static K_Int box(int n) {
		return new K_Int(n);
	}
	
	public static int unbox(K_Int n) {
		return n != null ? n.n : 0;
	}
	
}
