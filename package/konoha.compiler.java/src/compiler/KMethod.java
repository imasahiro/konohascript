package compiler;
import java.lang.reflect.Constructor;
import java.lang.reflect.Method;
import java.util.*;

import org.objectweb.asm.*;
import org.objectweb.asm.tree.MethodNode;

import compiler.ir.GenInstException;

public class KMethod extends MethodNode implements Opcodes {

	private static class Local {
		public final int n;
		public final Type type;
		public Local(int n, Type type) {
			this.n = n;
			this.type = type;
		}
	}
	
	private final HashMap<Integer, Label> bb = new HashMap<Integer, Label>();
	private final HashMap<String, Local> local = new HashMap<String, Local>();
	private final Compiler compiler;
	private int localCount = 0;
	public final int argCount;
	public int lineNo;
	
	public KMethod(Compiler compiler, KClass klass, int acc, String name, Type type, String self, String[] argNames, Type[] argTypes) {
		super(ASM4, acc, name, type.getDescriptor(), null/*gen*/, null/*throws*/);
		this.compiler = compiler;
		this.argCount = argNames.length;
		// arguments
		if(self != null) {
			newLocal(self, Type.getType("L" + klass.name + ";"));
		}
		for(int i=0; i<argNames.length; i++) {
			newLocal(argNames[i], argTypes[i]);
		}
	}
	
	public String getName() {
		return name;
	}
	
	public Type getType() {
		return Type.getMethodType(desc);
	}
	
	public void setLineNumber(int n) {
		Label l = new Label();
		visitLabel(l);
		visitLineNumber(n, l);
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
		visitVarInsn(l.type.getOpcode(ILOAD), l.n);
	}
	
	public void storeLocal(String var, Type type) throws GenInstException {
		Local l = local.get(var);
		if(l == null) {
			l = newLocal(var, type);
		}
		if(!l.type.equals(type)) {
			throw new GenInstException("different local type " + var + " " + type + ", " + l.type);
		}
		visitVarInsn(l.type.getOpcode(ISTORE), l.n);
	}
	
	public void setBasicBlock(int no) {
		visitLabel(getLabel(no));
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
			visitMethodInsn(INVOKESTATIC, "konoha/K_Int", "box", "(I)Lkonoha/K_Int;");
		} else if(type == Type.DOUBLE_TYPE) {
			visitMethodInsn(INVOKESTATIC, "konoha/K_Float", "box", "(D)Lkonoha/K_Float;");
		} else if(type == Type.BOOLEAN_TYPE) {
			visitMethodInsn(INVOKESTATIC, "konoha/K_Boolean", "box", "(Z)Lkonoha/K_Boolean;");
		} else if(type.equals(KType.kString)) {
			visitMethodInsn(INVOKESTATIC, "konoha/K_String", "box", "(Ljava/lang/String;)Lkonoha/K_String;");
		}
	}
	
	public void unbox(Type type) {
		if(type == Type.INT_TYPE) {
			visitTypeInsn(CHECKCAST, "konoha/K_Int");
			visitMethodInsn(INVOKESTATIC, "konoha/K_Int", "unbox", "(Lkonoha/K_Int;)I");
		} else if(type == Type.DOUBLE_TYPE) {
			visitTypeInsn(CHECKCAST, "konoha/K_Float");
			visitMethodInsn(INVOKESTATIC, "konoha/K_Float", "unbox", "(Lkonoha/K_Float;)D");
		} else if(type == Type.BOOLEAN_TYPE) {
			visitTypeInsn(CHECKCAST, "konoha/K_Boolean");
			visitMethodInsn(INVOKESTATIC, "konoha/K_Boolean", "unbox", "(Lkonoha/K_Boolean;)Z");
		} else if(type.equals(KType.kString)) {
			visitTypeInsn(CHECKCAST, "konoha/K_String");
			visitMethodInsn(INVOKESTATIC, "konoha/K_String", "unbox", "(Lkonoha/K_String;)Ljava/lang/String;");
		} else {
			visitTypeInsn(CHECKCAST, type.getInternalName());
		}
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
		if(compiler.isLibClass(cName) && !cName.startsWith("konoha/")) {
			// library constructor
			for(int i=0; i<args.length; i++) {
				loadLocal(args[i]);
			}
			try {
				for(Constructor<?> con : Class.forName(cName.replace("/", ".")).getConstructors()) {
					int n = con.getParameterTypes().length;
					if(n == args.length - 1) {
						visitMethodInsn(INVOKESPECIAL, cName, "<init>", Type.getConstructorDescriptor(con));
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
		if(compiler.isLibClass(cName)) {
			for(Method method : toClass(cName.replace("/", ".")).getMethods()) {
				if(method.getName().equals(mName)) {
					return Type.getType(method);
				}
			}
		} else {
			KMethod mtd = compiler.getMethod(cName, mName, args);
			if(mtd != null) {
				return mtd.getType();
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
			visitIntInsn(SIPUSH, args.length);
			visitTypeInsn(ANEWARRAY, "konoha/K_Object");
			// store args
			for(int i=0; i<args.length; i++) {
				visitInsn(DUP);
				visitIntInsn(SIPUSH, i);
				loadLocal(args[i]);
				box(getLocalType(args[i]));
				visitInsn(AASTORE);
			}
		} else {
			Type[] argTypes = type.getArgumentTypes();
			for(int i=0; i<args.length; i++) {
				loadLocal(args[i]);
				Type ty = getLocalType(args[i]);
				if(argTypes[i] == Type.LONG_TYPE) {
					if(ty == Type.INT_TYPE) {
						visitInsn(I2L);
					} else if(ty == Type.DOUBLE_TYPE) {
						visitInsn(D2L);
					}
				}
				if(argTypes[i] == Type.FLOAT_TYPE) {
					if(ty == Type.INT_TYPE) {
						visitInsn(I2F);
					} else if(ty == Type.DOUBLE_TYPE) {
						visitInsn(D2F);
					}
				}
			}
		}
		if(compiler.isLibClass(cName)) { // library method call
			Class<?> c = toClass(cName.replace("/", "."));
			invoke(c, mName, op);
		} else { // user method
			if(cName.equals("")) {
				// dynamic
				//Handle h = new Handle(isStatic ? H_INVOKESTATIC : H_INVOKEVIRTUAL, m_name,  m_name, a);
				//visitInvokeDynamicInsn(m_name, a, h);
				throw new GenInstException("TODO: dynamic call");
			} else {
				KMethod mtd = compiler.getMethod(cName, mName, args.length);
				if(mtd == null) {
					throw new GenInstException("method not found: " + cName + "." + mName);
				}
				visitMethodInsn(op, cName, mName, mtd.desc);
			}
		}
		if(retType != Type.VOID_TYPE) {
			if(retType == Type.LONG_TYPE) {
				visitInsn(L2I);
			} else if(retType == Type.FLOAT_TYPE) {
				visitInsn(F2D);
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
		visitFieldInsn(GETFIELD, className, field.name, field.type.getDescriptor());
	}
	
	public void storeField(String self, String value, int index, Type type) throws GenInstException {
		String className = getLocalType(self).getInternalName();
		KField field = compiler.getField(className, getLocalType(value), index);
		if(field == null) {
			throw new GenInstException("field not found: " + self + " " + index);
		}
		visitFieldInsn(PUTFIELD, className, field.name, field.type.getDescriptor());
	}
	
	public void jump(int opcode, int bb) {
		jump(opcode, getLabel(bb));
	}
	
	public void jump(int opcode, Label label) {
		visitJumpInsn(opcode, label);
	}
	
	public void invoke(Class<?> klass, String methodName, int opcode) throws GenInstException {
		for(Method method : klass.getMethods()) {
			if(method.getName().equals(methodName)) {
				String className = Type.getType(klass).getInternalName();
				String desc = Type.getType(method).getDescriptor();
				visitMethodInsn(opcode, className, methodName, desc);
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
	
	public void dump() {
		System.out.println("---" + name + desc + "---");
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
