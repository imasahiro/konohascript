package compiler;

import java.io.*;
import java.util.*;
import konoha.*;
import org.objectweb.asm.*;

public class Compiler implements Opcodes {
	
	private final HashMap<String, KClass> classList = new HashMap<String, KClass>();
	private ArrayList<String> initList;
	private KMethod mainMethod;
	
	{
		
		// create Script class
		KClass script = new KClass("Script", "konoha/K_Object");
		classList.put("Script", script);
		script.createField(ACC_STATIC + ACC_PUBLIC, "script0", Type.getType("LScript;"));

	}
	
	public void initScript() {
		initList = new ArrayList<String>();
		mainMethod = null;
	}
	
	public static String typeToStr(Type type) {
		if(type == Type.INT_TYPE) {
			return "int";
		} else if(type == Type.DOUBLE_TYPE) {
			return "float";
		} else {
			return "void";
		}
	}
	
	public void dumpScriptDefs(PrintWriter out) {
		KClass script = classList.get("Script");
		if(script != null) {
			for(KField field : script.fields) {
				if(field.name.equals("script0")) continue;
				out.printf("%s %s;\n", typeToStr(field.type), field.name);
			}
			for(KMethod method : script.methods) {
				if(!method.name.equals("main") && !method.name.startsWith("_init")) {
					Type t = Type.getMethodType(method.desc);
					Type ret = t.getReturnType();
					out.write(typeToStr(ret) + " " + method.name + "(");
					int i = 0;
					for(Type type : t.getArgumentTypes()) {
						if(i != 0) out.write(", ");
						out.write(typeToStr(type) + " p" + i);
						i++;
					}
					out.write(");\n");
				}
			}
		}
	}
	
	public KClass createClass(String name, String superClass) {
		KClass c = new KClass(name, superClass);
		classList.put(name, c);
		return c;
	}
	
	public boolean isLibClass(String name) {
		return !classList.containsKey(name);
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
	
	public KMethod getMethod(String cName, String mName, int argc) {
		KClass c = classList.get(cName);
		return c.getMethod(mName, argc);
	}
	
	public KField getField(String cName, Type type, int id) {
		KClass c = classList.get(cName);
		if(cName.equals("Script")) {
			id++;
			while(c.fields.size() <= id) c.fields.add(null);
			KField f = c.fields.get(id);
			if(f == null) {
				String name = "field_" + id;
				f = new KField(ACC_PUBLIC, name, type);
				c.fields.set(id, f);
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
	
	public void genJavaMainMethod(ClassVisitor cw) {
		// create main method
		int acc = ACC_PUBLIC + ACC_STATIC;
		MethodVisitor mv = cw.visitMethod(acc, "main", "([Ljava/lang/String;)V", null, null);
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
			if(mainMethod.argCount == 1) {
				mv.visitVarInsn(ALOAD, 0);
				mv.visitMethodInsn(INVOKESTATIC, "compiler/Compiler", "createArgs", "([Ljava/lang/String;)Lkonoha/K_Array;");//TODO
			}
			mv.visitMethodInsn(INVOKESTATIC, "Script", "main", mainMethod.desc);
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
	
	public void addTopLevelMethod(String name) {
		initList.add(name);
	}
	
	public void setMainMethod(KMethod mtd) {
		Type[] argTypes = mtd.getType().getArgumentTypes();
		if(argTypes.length == 1 && argTypes[0].equals(Type.getType(K_Array.class))) {
			mainMethod = mtd;
		} else if(argTypes.length == 0) {
			mainMethod = mtd;
		} else {
			System.err.println("main method arguments error: " + mtd.desc);
		}
	}
	
	public byte[] genBytecode(String name) {
		KClass klass = classList.get(name);
		ClassWriter cw = new ClassWriter(ClassWriter.COMPUTE_FRAMES);
		klass.accept(cw);
		if(name.equals("Script")) {
			genJavaMainMethod(cw);
		}
		return cw.toByteArray();
	}
	
	private class KLoader extends ClassLoader {
		private final HashSet<String> set = new HashSet<String>();
		public void define(KClass c) {
			KClass superClass = classList.get(c.superName);
			if(superClass != null) {
				define(superClass);
			}
			if(!set.contains(c.name)) {
				byte[] code = genBytecode(c.name);
				defineClass(c.name, code, 0, code.length);
				set.add(c.name);
			}
		}
	}
	
	public java.lang.reflect.Method getMainMethod() {
		KLoader loader = new KLoader();
		for(KClass k : classList.values()) {
			loader.define(k);
		}
		try {
			return loader.loadClass("Script").getMethod("main", String[].class);
		} catch(Exception e) {
			e.printStackTrace();
			return null;
		}
	}
	
	public void writeClassFile() throws IOException {
		for(String name : classList.keySet()) {
			String file = name + ".class";
			FileOutputStream fos = null;
			try {
				fos = new FileOutputStream(file);
				fos.write(genBytecode(name));
			} finally {
				if(fos != null) fos.close();
			}
		}
	}
	
}
