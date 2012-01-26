package compiler;
import java.lang.reflect.Constructor;
import java.lang.reflect.Method;
import java.util.*;

import org.objectweb.asm.*;

import compiler.ir.GenInstException;

public class KMethod implements Opcodes {

	private static class Local {
		public final int n;
		public final Type type;
		public Local(int n, Type type) {
			this.n = n;
			this.type = type;
		}
	}
	
	public final KClass klass;
	public final String methodName;
	public final Type methodType;
	public int lineNo;
	
	private final HashMap<Integer, Label> bb = new HashMap<Integer, Label>();
	private final HashMap<String, Local> local = new HashMap<String, Local>();
	private final Compiler compiler;
	private int localCount = 0;
	
	public final MethodVisitor mv;
	
	public static final Type type_Array = Type.getType(konoha.K_Array.class);
	public static final Type type_Date = Type.getType(konoha.K_Date.class);
	public static final Type type_String = Type.getType(String.class);
	public static final Type type_Path = Type.getType(konoha.K_Path.class);
	public static final Type type_Iterator = Type.getType(konoha.K_Iterator.class);
	public static final Type type_Regex = Type.getType(konoha.K_Regex.class);
	
	public KMethod(Compiler compiler, KClass c, int acc, String name, Type type, String self, String[] argNames, Type[] argTypes) {
		this.compiler = compiler;
		this.mv = c.cw.visitMethod(acc, name, type.getDescriptor(), null /*gen*/, null/*throws*/);
		this.klass = c;
		this.methodName = name;
		this.methodType = type;
		// arguments
		if(self != null) {
			newLocal(self, Type.getType("L" + c.name + ";"));
		}
		for(int i=0; i<argNames.length; i++) {
			newLocal(argNames[i], argTypes[i]);
		}
	}
	
	public int getArgc() {
		return methodType.getArgumentTypes().length;
	}
	
	public void setLineNumber(int n) {
		Label l = new Label();
		mv.visitLabel(l);
		mv.visitLineNumber(n, l);
	}
	
	private Local newLocal(String name, Type type) {
		Local l = new Local(localCount, type);
		localCount += (type != Type.DOUBLE_TYPE) ? 1 : 2;
		local.put(name, l);
		return l;
	}
	
	public void addSameLocal(String m1, String m2, Type type) {
		if(!local.containsKey(m1)) {
			newLocal(m1, type);
		}
		if(!local.containsKey(m2)) {
			newLocal(m2, type);
		}
	}
	
	private Local getLocal(String var) throws GenInstException {
		Local l = local.get(var);
		if(l == null) {
			throw new GenInstException("local var not found: " + var);
		}
		return l;
	}
	
	public void movLocal(Type type, String from, String to) throws GenInstException {
		Local l1 = local.get(from);
		if(l1 == null) {
			l1 = newLocal(from, type);
		}
		Local l2 = local.get(to);
		if(l2 == null) {
			l2 = newLocal(to, type);
		}
		if(l1.n != l2.n) {
			loadLocal(from);
			storeLocal(to, type);
		}
	}
	
	public Type getLocalType(String var) throws GenInstException {
		return getLocal(var).type;
	}
	
	public void loadLocal(String var) throws GenInstException {
		Local l = getLocal(var);
		mv.visitVarInsn(l.type.getOpcode(ILOAD), l.n);
	}
	
	public void storeLocal(String var, Type type) throws GenInstException {
		Local l = local.get(var);
		if(l == null) {
			l = newLocal(var, type);
		}
		if(!l.type.equals(type)) {
			throw new GenInstException("different local type " + var + " " + type + ", " + l.type);
		}
		mv.visitVarInsn(l.type.getOpcode(ISTORE), l.n);
	}
	
	public void setBasicBlock(int no) {
		mv.visitLabel(getLabel(no));
	}
	
	public Label getLabel(int n) {
		Label l = bb.get(n);
		if(l == null) {
			l = new Label();
			bb.put(n, l);
		}
		return l;
	}
	
	public void box(Type type) {
		if(type == Type.INT_TYPE) {
			mv.visitMethodInsn(INVOKESTATIC, "konoha/K_System", "boxInt", "(I)Lkonoha/K_Int;");
		} else if(type == Type.DOUBLE_TYPE) {
			mv.visitMethodInsn(INVOKESTATIC, "konoha/K_System", "boxFloat", "(D)Lkonoha/K_Float;");
		} else if(type == Type.BOOLEAN_TYPE) {
			mv.visitMethodInsn(INVOKESTATIC, "konoha/K_System", "boxBoolean", "(Z)Lkonoha/K_Boolean;");
		} else if(type.equals(type_String)) {
			mv.visitMethodInsn(INVOKESTATIC, "konoha/K_System", "boxString", "(Ljava/lang/String;)Lkonoha/K_String;");
		}
	}
	
	public void unbox(Type type) {
		if(type == Type.INT_TYPE) {
			mv.visitTypeInsn(CHECKCAST, "konoha/K_Int");
			mv.visitMethodInsn(INVOKESTATIC, "konoha/K_System", "unboxInt", "(Lkonoha/K_Int;)I");
		} else if(type == Type.DOUBLE_TYPE) {
			mv.visitTypeInsn(CHECKCAST, "konoha/K_Float");
			mv.visitMethodInsn(INVOKESTATIC, "konoha/K_System", "unboxFloat", "(Lkonoha/K_Float;)D");
		} else if(type == Type.BOOLEAN_TYPE) {
			mv.visitTypeInsn(CHECKCAST, "konoha/K_Boolean");
			mv.visitMethodInsn(INVOKESTATIC, "konoha/K_System", "unboxBoolean", "(Lkonoha/K_Boolean;)Z");
		} else if(type.equals(type_String)) {
			mv.visitTypeInsn(CHECKCAST, "konoha/K_String");
			mv.visitMethodInsn(INVOKESTATIC, "konoha/K_System", "unboxString", "(Lkonoha/K_String;)Ljava/lang/String;");
		} else {
			mv.visitTypeInsn(CHECKCAST, type.getInternalName());
		}
	}
	
	public void pushArray(String res, Type type, Object[] vals) throws GenInstException {
		mv.visitMethodInsn(INVOKESTATIC, "konoha/K_Array", "create", "()Lkonoha/K_Array;");
		storeLocal(res, type);
		loadLocal(res);
		mv.visitLdcInsn(vals.length);
		mv.visitMethodInsn(INVOKEVIRTUAL, "konoha/K_Array", "newArray", "(I)Lkonoha/K_Array;");
		storeLocal(res, type);
		String mt_type = Type.getMethodDescriptor(Type.VOID_TYPE, Type.INT_TYPE, type);
		for(int i=0; i<vals.length; i++) {
			loadLocal(res);
			mv.visitLdcInsn(i);
			mv.visitLdcInsn(vals[i]);
			mv.visitMethodInsn(INVOKEVIRTUAL, "konoha/K_Array", "set", mt_type);
		}
	}
	
	public void pushClass(String res, Type type, String val) throws GenInstException {
		mv.visitTypeInsn(NEW, "konoha/K_Class");
		mv.visitInsn(DUP);
		mv.visitLdcInsn(val);
		mv.visitMethodInsn(INVOKESPECIAL, "konoha/K_Class", "<init>", "(Ljava/lang/String;)V");
		storeLocal(res, type);
		
	}
	
	private static Class<?> toClass(String name) throws GenInstException {
		try {
			return Class.forName(name);
		} catch(ClassNotFoundException e) {
			throw new GenInstException("class not found: " + name);
		}
	}
	
	public static boolean isVariableLengthArgMethod(String cName, String mName) {
		if(cName.equals("konoha/K_Array")) {
			if(mName.equals("newList") || mName.equals("add") || mName.equals("send")) {
				return true;
			}
		}
		return false;
	}
	
	public void asmCallConstructor(String cName, String[] args, Type retType, String ret) throws GenInstException {
		if(cName.startsWith("java/") || cName.startsWith("javax/")) {
			// library constructor
			for(int i=0; i<args.length; i++) {
				loadLocal(args[i]);
			}
			try {
				for(Constructor<?> con : Class.forName(cName.replace("/", ".")).getConstructors()) {
					int n = con.getParameterTypes().length;
					if(n == args.length - 1) {
						mv.visitMethodInsn(INVOKESPECIAL, cName, "<init>", Type.getConstructorDescriptor(con));
						loadLocal(args[0]);
						storeLocal(ret, retType);
						return;
					}
				}
			} catch(Exception e) {e.printStackTrace();}
			throw new GenInstException("constructor not found: " + cName + " arg=" + args.length);
		} else {
			asmCall(false, cName, "_new", args, retType, ret);
		}
	}
	
	private Type getMtdType(String cName, String mName, int args) throws GenInstException {
		if(cName.startsWith("konoha/") || cName.startsWith("java/") || cName.startsWith("javax/")) {
			for(Method method : toClass(cName.replace("/", ".")).getMethods()) {
				if(method.getName().equals(mName)) {
					return Type.getType(method);
				}
			}
		} else {
			KMethod mtd = compiler.getMethod(cName, mName, args);
			if(mtd != null) {
				return mtd.methodType;
			}
		}
		throw new GenInstException("method not found");
	}
	
	public void asmCall(boolean isStatic, String cName, String mName, String[] args, Type retType, String ret) throws GenInstException {
		int op = isStatic ? INVOKESTATIC : INVOKEVIRTUAL;
		if(!isStatic) {
			loadLocal(args[0]);
			args = Arrays.copyOfRange(args, 1, args.length);
		}
		Type type = getMtdType(cName, mName, args.length);
		if(isVariableLengthArgMethod(cName, mName)) { // variable length argument method
			// create object array
			mv.visitIntInsn(SIPUSH, args.length);
			mv.visitTypeInsn(ANEWARRAY, "konoha/K_Object");
			// store args
			for(int i=0; i<args.length; i++) {
				mv.visitInsn(DUP);
				mv.visitIntInsn(SIPUSH, i);
				loadLocal(args[i]);
				box(getLocalType(args[i]));
				mv.visitInsn(AASTORE);
			}
		} else {
			Type[] argTypes = type.getArgumentTypes();
			for(int i=0; i<args.length; i++) {
				loadLocal(args[i]);
				Type ty = getLocalType(args[i]);
				if(argTypes[i] == Type.LONG_TYPE) {
					if(ty == Type.INT_TYPE) {
						mv.visitInsn(I2L);
					} else if(ty == Type.DOUBLE_TYPE) {
						mv.visitInsn(D2L);
					}
				}
				if(argTypes[i] == Type.FLOAT_TYPE) {
					if(ty == Type.INT_TYPE) {
						mv.visitInsn(I2F);
					} else if(ty == Type.DOUBLE_TYPE) {
						mv.visitInsn(D2F);
					}
				}
			}
		}
		if(cName.startsWith("konoha/") || cName.startsWith("java/") || cName.startsWith("javax/")) { // library method call
			Class<?> c = toClass(cName.replace("/", "."));
			invoke(c, mName, op);
		} else { // user method
			if(cName.equals("")) {
				// dynamic
				//Handle h = new Handle(isStatic ? H_INVOKESTATIC : H_INVOKEVIRTUAL, m_name,  m_name, a);
				//mv.visitInvokeDynamicInsn(m_name, a, h);
				throw new GenInstException("TODO: dynamic call");
			} else {
				KMethod mtd = compiler.getMethod(cName, mName, args.length);
				if(mtd == null) {
					throw new GenInstException("method not found: " + cName + "." + mName);
				}
				mv.visitMethodInsn(op, cName, mName, mtd.methodType.getDescriptor());
			}
		}
		if(retType != Type.VOID_TYPE) {
			if(retType == Type.LONG_TYPE) {
				mv.visitInsn(L2I);
			} else if(retType == Type.FLOAT_TYPE) {
				mv.visitInsn(F2D);
			}
			storeLocal(ret, retType);
		}
	}
	
	public void loadField(String self, int index, Type type) throws GenInstException {
		String className = getLocal(self).type.getInternalName();
		KField field = compiler.getField(className, type, index);
		if(field == null) {
			throw new GenInstException("field not found: " + self + " " + index);
		}
		mv.visitFieldInsn(GETFIELD, className, field.name, field.type.getDescriptor());
	}
	
	public void storeField(String self, String value, int index, Type type) throws GenInstException {
		String className = getLocalType(self).getInternalName();
		KField field = compiler.getField(className, getLocalType(value), index);
		if(field == null) {
			throw new GenInstException("field not found: " + self + " " + index);
		}
		mv.visitFieldInsn(PUTFIELD, className, field.name, field.type.getDescriptor());
	}
	
	public void jump(int opcode, int bb) {
		jump(opcode, getLabel(bb));
	}
	
	public void jump(int opcode, Label label) {
		mv.visitJumpInsn(opcode, label);
	}
	
	public void invoke(Class<?> klass, String methodName, int opcode) throws GenInstException {
		for(Method method : klass.getMethods()) {
			if(method.getName().equals(methodName)) {
				String className = Type.getType(klass).getInternalName();
				String desc = Type.getType(method).getDescriptor();
				mv.visitMethodInsn(opcode, className, methodName, desc);
				return;
			}
		}
		throw new GenInstException("method not found " + klass.getName() + " " + methodName);
	}
	
	public void invokeStatic(Class<?> klass, String methodName) throws GenInstException {
		invoke(klass, methodName, INVOKESTATIC);
	}
	
	public void invokeVirtual(Class<?> klass, String methodName) throws GenInstException {
		invoke(klass, methodName, INVOKEVIRTUAL);
	}
	
	public void end() {
		mv.visitMaxs(0, 0);
		mv.visitEnd();
	}
	
	public void dump() {
		System.out.println("---" + klass.name + "." + methodName + methodType.getDescriptor() + "---");
		System.out.println("local count = " + localCount);
		Local[] ls = new Local[localCount];
		String[] names = new String[localCount];
		for(String name : local.keySet()) {
			Local l = local.get(name);
			if(l != null && l.n >= 0) {
				ls[l.n] = l;
				names[l.n] = name;
			}
		}
		for(Local l : ls) {
			if(l != null) {
				System.out.printf("[local] %03d %s = %s\n", l.n, names[l.n], l.type);
			}
		}
	}

}
