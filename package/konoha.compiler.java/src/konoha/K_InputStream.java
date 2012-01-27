package konoha;

import java.io.*;

public class K_InputStream {
	
	public BufferedReader in;
	
	public K_InputStream _new(K_Path name, String mode, K_Map map) {
		try {
			in = new BufferedReader(new FileReader(name.toString()));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		return this;
	}
	
	public String readLine() {
		try {
			return in.readLine();
		} catch(IOException e) {
			e.printStackTrace();
			return null;
		}
	}
	
	public void close() throws IOException {
		try {
			in.close();
		} catch(IOException e) {
			e.printStackTrace();
		}
	}
	
	public K_Iterator toIterator() {
		return new K_Iterator() {
			private String line;
			@Override public boolean hasNext() {
				line = readLine();
				return line != null;
			}
			@Override public Object getNext() {
				return K_String.box(line);
			}
		};
	}
}
