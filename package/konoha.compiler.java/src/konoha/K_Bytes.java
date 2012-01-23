package konoha;

public class K_Bytes extends K_Object {
	
	byte[] data = new byte[0];
	
	public K_Bytes newArray(int len) {
		data = new byte[len];
		return this;
	}
	
	public int getSize() {
		return data.length;
	}
	
	public int get(int n) {
		return data[n];
	}
	
	public int set(int n, int c) {
		data[n] = (byte)c;
		return c;
	}
	
}
