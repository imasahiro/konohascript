package konoha;

public class K_Int extends K_Number {
	
	public int n;
	
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
	
}
