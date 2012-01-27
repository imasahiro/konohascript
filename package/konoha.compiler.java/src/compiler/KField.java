package compiler;
import org.objectweb.asm.*;

public class KField {
	
	public final int access;
	public final String name;
	public final Type type;
	
	public KField(int access, String name, Type type) {
		this.access = access;
		this.name = name;
		this.type = type;
	}
	
	public void accept(ClassVisitor cv) {
		cv.visitField(access, name, type.getDescriptor(), null/*generics*/, null/*value*/);
	}
	
}
