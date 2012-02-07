package konoha;

import java.util.HashMap;

public class K_Map extends K_Object {
	
	public HashMap<String, Object> map = new HashMap<String, Object>();
	
	public K_Map _new(int n) {
		return this;
	}
	
	public K_Map newMap() {
		return this;
	}
	
	public void set(String key, Object value) {
		map.put(key, value);
	}
	
	public Object get(String key) {
		return map.get(key);
	}
	
	public void remove(String key) {
		map.remove(key);
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
