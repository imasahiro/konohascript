package konoha;

public class K_Float extends K_Number {
	
	public double n;
	
	public K_Float(double n) {
		this.n = n;
	}
	
	public static double random() {
		return random.nextDouble();
	}
	
	public static String format(double n, String fmt) {
		return String.format(fmt.toString(), n);
	}
	
	public String toString() {
		return Double.toString(n);
	}
	
}
