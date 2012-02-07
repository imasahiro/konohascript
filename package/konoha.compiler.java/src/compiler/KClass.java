package compiler;

import java.util.*;
import org.objectweb.asm.*;

public class KClass implements Opcodes {
	
	public final String name;
	public final String superName;
	public final String[] interfaceNames;
	public final ArrayList<KField> fields = new ArrayList<KField>();
	public final ArrayList<KMethod> methods = new ArrayList<KMethod>();
	
	public KClass(String name, String superName) {
		String[] interfaceNames = null;
		if(superName.startsWith("java/")) {
			try {
				Class<?> c = Class.forName(superName.replace("/", "."));
				if(c.isInterface()) {
					interfaceNames = new String[] { superName };
					superName = "konoha/K_Object";
				}
			} catch(ClassNotFoundException e) {}
		}
		this.name = name;
		this.superName = superName;
		this.interfaceNames = interfaceNames;
	}
	
	public void accept(ClassVisitor cv) {
		cv.visit(Opcodes.V1_6, Opcodes.ACC_PUBLIC, name, null/*generics*/, superName, interfaceNames);
		// constructor
		int acc = Opcodes.ACC_PUBLIC;
		MethodVisitor mv = cv.visitMethod(acc, "<init>", "()V", null/*generics*/, null/*throws*/);
		mv.visitVarInsn(Opcodes.ALOAD, 0);
		mv.visitMethodInsn(Opcodes.INVOKESPECIAL, superName, "<init>", "()V");
		mv.visitInsn(Opcodes.RETURN);
		mv.visitMaxs(0, 0);
		mv.visitEnd();
		for(KField field : fields) {
			field.accept(cv);
		}
		for(KMethod mtd : methods) {
			mtd.accept(cv);
		}
	}
	
	public KMethod createMethod(Compiler com, String name, String thisObj, Type ret, Type[] argTypes, String[] argNames) {		
		for(int i=0; i<methods.size(); i++) {
			if(methods.get(i).name.equals(name)) {
				methods.remove(i);
				i--;
			}
		}
		int acc = ACC_PUBLIC;
		if(thisObj == null) {
			acc |= ACC_STATIC;
		}
		Type type = Type.getMethodType(ret, argTypes);
		KMethod m = new KMethod(com, this, acc, name, type, thisObj, argNames, argTypes);
		methods.add(m);
		return m;
	}
	
	public void createField(int acc, String name, Type type) {
		fields.add(new KField(acc, name, type));
	}
	
	public void createField(String name, Type type) {
		createField(Opcodes.ACC_PUBLIC, name, type);
	}
	
	public KMethod getMethod(String name, int args) {
		for(KMethod mtd : methods) {
			if(mtd.getName().equals(name) && mtd.argCount == args) {
				return mtd;
			}
		}
		return null;
	}
	
}
