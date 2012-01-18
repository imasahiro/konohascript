package konoha;

public class K_Object {
	
	public static boolean equals(Object o1, Object o2) {
		if(o1 == null || o2 == null) {
			return o1 == o2;
		} else {
			return o1.equals(o2);
		}
	}
	
	public static boolean isNull(K_Object o) {
		return o == null;
	}
	
	public static boolean isNonNull(K_Object o) {
		return o != null;
	}
	
}
