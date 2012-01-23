package compiler;

import java.io.*;
import java.util.*;
import konoha.*;
import org.objectweb.asm.*;

public class Compiler extends ClassLoader implements Opcodes {
	
	private final HashMap<String, KClass> classList = new HashMap<String, KClass>();
	private final ArrayList<String> initList = new ArrayList<String>();
	private KMethod mainMethod = null;
	
	public Compiler() {
		// add Script class
		KClass c = new KClass("Script", "konoha/K_Object");
		classList.put("Script", c);
		// add Script.script0 field
		int acc = ACC_STATIC + ACC_PUBLIC;
		c.cw.visitField(acc, "script0", "LScript;", null/*generics*/, null/*value*/);
	}
	
	public KClass createClass(String name, String superClass) {
		assert !classList.containsKey(name);
		KClass c = new KClass(name, superClass);
		classList.put(name, c);
		return c;
	}
	
	private int getFieldOffset(KClass c) {
		int size = c.fields.size();
		if(c.superName.equals("konoha/K_Object")) {
			return size;
		} else {
			return size + getFieldOffset(classList.get(c.superName));
		}
	}
	
	public KClass getClass(String name) {
		return classList.get(name);
	}
	
	public KMethod getMethod(String className, String methodName, int argc) {
		KClass c = classList.get(className);
		return c.getMethod(methodName, argc);
	}
	
	public KField getField(String className, Type type, int id) {
		KClass c = classList.get(className);
		if(className.equals("Script")) {
			while(c.fields.size() <= id) c.fields.add(null);
			KField f = c.fields.get(id);
			if(f == null) {
				String name = "field_" + id;
				f = new KField(name, type);
				c.fields.set(id, f);
				int access = ACC_PUBLIC;
				c.cw.visitField(access, name, type.getDescriptor(), null/*generics*/, null/*value*/);
			}
			return f;
		}
		int offset = 0;
		if(!c.superName.equals("konoha/K_Object")) {
			KField f = getField(c.superName, type, id);
			if(f != null) {
				return f;
			}
			offset = getFieldOffset(classList.get(c.superName));
		}
		if(id - offset < c.fields.size()) {
			return c.fields.get(id - offset);
		} else {
			return null;
		}
	}
	
	public void end() {
		// create main method
		int acc = ACC_PUBLIC + ACC_STATIC;
		MethodVisitor mv = classList.get("Script").cw.visitMethod(acc, "main", "([Ljava/lang/String;)V", null, null);
		int n = 1;
		// create Script Object
		mv.visitTypeInsn(NEW, "Script");
		mv.visitVarInsn(ASTORE, n);
		mv.visitVarInsn(ALOAD, n);
		mv.visitMethodInsn(INVOKESPECIAL, "Script", "<init>", "()V");
		mv.visitVarInsn(ALOAD, n);
		mv.visitFieldInsn(PUTSTATIC, "Script", "script0", "LScript;");
		// call top level methods
		for(String name : initList) {
			mv.visitVarInsn(ALOAD, n);
			mv.visitMethodInsn(INVOKESTATIC, "Script", name, "(LScript;)V");
		}
		// call main method
		if(mainMethod != null) {
			if(mainMethod.getArgc() == 1) {
				mv.visitVarInsn(ALOAD, 0);
				mv.visitMethodInsn(INVOKESTATIC, "compiler/Compiler", "createArgs", "([Ljava/lang/String;)Lkonoha/K_Array;");//TODO
			}
			mv.visitMethodInsn(INVOKESTATIC, "Script", "main", mainMethod.methodType.getDescriptor());
		} else {
			System.err.println("(Warning) main method not found!");
		}
		mv.visitInsn(RETURN);
		mv.visitMaxs(0, 0);
		mv.visitEnd();
	}
	
	public static K_Array createArgs(String[] args) {
		K_Array a = new K_Array();
		a.newArray(args.length);
		for(int i=0; i<args.length; i++) {
			a.set(i, new K_String(args[i]));
		}
		return a;
	}
	
	private void defineClass(KClass c, HashMap<String, Class<?>> map) {
		if(!c.superName.equals("konoha/K_Object")) {
			defineClass(classList.get(c.superName), map);
		}
		if(!map.containsKey(c.name)) {
			byte[] code = c.cw.toByteArray();
			Class<?> cl = defineClass(c.name, code, 0, code.length);
			map.put(c.name, cl);
		}
	}
	
	public void addTopLevelMethod(String name) {
		initList.add(name);
	}
	
	public void setMainMethod(KMethod mtd) {
		Type[] argTypes = mtd.methodType.getArgumentTypes();
		if(argTypes.length == 1 && argTypes[0].equals(Type.getType(K_Array.class))) {
			mainMethod = mtd;
		} else if(argTypes.length == 0) {
			mainMethod = mtd;
		} else {
			System.err.println("main method arguments error: " + mtd.methodType);
		}
	}
	
	public java.lang.reflect.Method getMainMethod() throws NoSuchMethodException {
		HashMap<String, Class<?>> map = new HashMap<String, Class<?>>();
		for(KClass k : classList.values()) {
			defineClass(k, map);
		}
		return map.get("Script").getMethod("main", String[].class);
	}

	public void writeClassFile() throws IOException {
		for(String name : classList.keySet()) {
			ClassWriter cw = classList.get(name).cw;
			byte[] code = cw.toByteArray();
			String file = name + ".class";
			FileOutputStream fos = null;
			try {
				fos = new FileOutputStream(file);
				fos.write(code);
			} finally {
				if(fos != null) fos.close();
			}
		}
	}
	
}
