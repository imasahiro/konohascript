package compiler;

import java.util.*;
import org.objectweb.asm.*;

public class KClass implements Opcodes {
	
	public final String name;
	public final String superName;
	public final ClassWriter cw = new ClassWriter(ClassWriter.COMPUTE_FRAMES);
	public final ArrayList<KField> fields = new ArrayList<KField>();
	public final ArrayList<KMethod> methods = new ArrayList<KMethod>();
	
	public KClass(String name, String superName) {
		this.name = name;
		this.superName = superName;
		cw.visit(Opcodes.V1_6, Opcodes.ACC_PUBLIC, name,
				null/*generics*/, superName, null/*interface*/);
		// constructor
		int acc = Opcodes.ACC_PUBLIC;
		MethodVisitor mv = cw.visitMethod(acc, "<init>", "()V", null/*generics*/, null/*throws*/);
		mv.visitVarInsn(Opcodes.ALOAD, 0);
		mv.visitMethodInsn(Opcodes.INVOKESPECIAL, superName, "<init>", "()V");
		mv.visitInsn(Opcodes.RETURN);
		mv.visitMaxs(0, 0);
		mv.visitEnd();
	}
	
	public KMethod createMethod(Compiler com, String name, String thisObj, Type ret, Type[] argTypes, String[] argNames) {
		int acc = ACC_PUBLIC;
		if(thisObj == null) {
			acc |= ACC_STATIC;
		}
		Type type = Type.getMethodType(ret, argTypes);
		KMethod m = new KMethod(com, this, acc, name, type, thisObj, argNames, argTypes);
		methods.add(m);
		return m;
	}
	
	public void createField(Compiler com, String name, Type type) {
		fields.add(new KField(name, type));
		cw.visitField(Opcodes.ACC_PUBLIC, name, type.getDescriptor(), null/*generics*/, null/*value*/);
	}
	
	public KMethod getMethod(String name, int args) {
		for(KMethod mtd : methods) {
			if(mtd.methodName.equals(name) && mtd.getArgc() == args) {
				return mtd;
			}
		}
		return null;
	}
	
}
