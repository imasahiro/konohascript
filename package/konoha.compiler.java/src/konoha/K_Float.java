package konoha;

public class K_Float extends K_Number {
	
	private final double n;
	
	public K_Float(double n) {
		this.n = n;
	}
	
	public String toString() {
		return Double.toString(n);
	}
	
	public static double random() {
		return random.nextDouble();
	}
	
	public static String format(double n, String fmt) {
		return String.format(fmt.toString(), n);
	}
	
	public static K_Float box(double n) {
		return new K_Float(n);
	}
	
	public static double unbox(K_Float n) {
		return n != null ? n.n : 0.0;
	}
}
