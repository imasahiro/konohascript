package konoha;

import java.util.*;

public class K_Array extends K_Object {
	
	private final ArrayList<Object> data = new ArrayList<Object>();
	
	public K_Array _new(int n) {
		return newArray(n);
	}
	
	public K_Array newArray(int n) {
		for(int i=0; i<n; i++) {
			data.add(null);
		}
		return this;
	}
	
	public K_Array newList(Object[] obj) {
		data.addAll(Arrays.asList(obj));
		return this;
	}
	
	public Object get(int i) {
		return data.get(i);
	}
	
	public void set(int i, Object n) {
		data.set(i, n);
	}
	
	public void add1(Object a) {
		data.add(a);
	}
	
	public void add(Object[] a) {
		data.addAll(Arrays.asList(a));
	}
	
	public void send(Object[] a) {
		data.addAll(Arrays.asList(a));
	}
	
	public void clear() {
		data.clear();
	}
	
	public void remove(int n) {
		data.remove(n);
	}
	
	public void shuffle() {
		Collections.shuffle(data);
	}
	
	public void reverse() {
		Collections.reverse(data);
	}
	
	public int getSize() {
		return data.size();
	}
	
	public K_Iterator toIterator() {
		return new K_Iterator() {
			int index = 0;
			
			public boolean hasNext() {
				return index < data.size();
			}
			
			public Object getNext() {
				return data.get(index++);
			}
		};
	}
	
	public String toString() {
		return data.toString();
	}
	
}
