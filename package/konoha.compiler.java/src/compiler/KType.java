package compiler;

import org.objectweb.asm.Type;

public class KType {
	public static final Type kArray = Type.getType(konoha.K_Array.class);
	public static final Type kDate = Type.getType(konoha.K_Date.class);
	public static final Type kString = Type.getType(String.class);
	public static final Type kPath = Type.getType(konoha.K_Path.class);
	public static final Type kIterator = Type.getType(konoha.K_Iterator.class);
	public static final Type kRegex = Type.getType(konoha.K_Regex.class);
	public static final Type kInputStream = Type.getType(konoha.K_InputStream.class);
}
