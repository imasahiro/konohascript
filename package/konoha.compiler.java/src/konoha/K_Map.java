package konoha;

import java.util.HashMap;

public class K_Map extends K_Object {
	
	public HashMap<String, K_Object> map = new HashMap<String, K_Object>();
	
	public K_Map _new(int n) {
		return this;
	}
	
	public K_Map newMap() {
		return this;
	}
	
	public void set(K_String key, K_Object value) {
		map.put(key.toString(), value);
	}
	
	public K_Object get(K_String key) {
		return map.get(key.toString());
	}
	
	public void remove(K_String key) {
		map.remove(key.toString());
	}
	
	public int getSize() {
		return map.size();
	}
	
	public K_Array keys() {
		K_Array a = new K_Array();
		for(String s : map.keySet()) {
			a.add1(new K_String(s));
		}
		return a;
	}
	
	public String toString() {
		return map.toString();
	}
}
