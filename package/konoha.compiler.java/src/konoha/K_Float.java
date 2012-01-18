package konoha;

public class K_Float extends K_Number {
	
	public double n;
	
	public K_Float(double n) {
		this.n = n;
	}
	
	public static double random() {
		return random.nextDouble();
	}
	
	public String format(String fmt) {
		String r = String.format(fmt.toString(), n);
		return r;
	}
	
	public String toString() {
		return Double.toString(n);
	}
	
}
