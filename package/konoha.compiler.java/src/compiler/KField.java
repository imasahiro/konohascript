package compiler;
import org.objectweb.asm.Type;

public class KField {
	
	public final String name;
	public final Type type;
	
	public KField(String name, Type type) {
		this.name = name;
		this.type = type;
	}
	
}
