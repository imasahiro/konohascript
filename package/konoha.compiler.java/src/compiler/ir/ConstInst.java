package compiler.ir;

import org.objectweb.asm.Type;
import compiler.KMethod;
import compiler.Parser;

public class ConstInst extends Inst {
	
	private static Integer[] toIntArray(String[] tk) {
		Integer[] a = new Integer[tk.length];
		for(int i=0; i<tk.length; i++) {
			a[i] = Integer.parseInt(tk[i]);
		}
		return a;
	}
	
	private static Double[] toDoubleArray(String[] tk) {
		Double[] a = new Double[tk.length];
		for(int i=0; i<tk.length; i++) {
			a[i] = Double.parseDouble(tk[i]);
		}
		return a;
	}
	
	private static Boolean[] toBooleanArray(String[] tk) {
		Boolean[] a = new Boolean[tk.length];
		for(int i=0; i<tk.length; i++) {
			a[i] = Boolean.parseBoolean(tk[i]);
		}
		return a;
	}
	
	private static String upescape(String s) {
		return s.replace("\\n", "\n").replace("\\t", "\t").replace("\"", "");
	}
	
	@Override public void asm(KMethod gen, Parser parser, String[] token) throws GenInstException {
		// parse
		String res = token[0];
		String typeName = token[3];
		Type type = parser.toType(typeName);
		String val = token[4];
		String line = parser.getLine();
		// gen
		if(typeName.equals("konoha.Int")) {
			int n = val.equals("null") ? 0 : Integer.parseInt(val);
			gen.visitLdcInsn(n);
			gen.storeLocal(res, type);
		} else if(typeName.equals("konoha.Float")) {
			double n = val.equals("null") ? 0 : Double.parseDouble(val);
			gen.visitLdcInsn(n);
			gen.storeLocal(res, type);
		} else if(typeName.equals("konoha.Boolean")) {
			boolean b = val.equals("true");
			gen.visitLdcInsn(b);
			gen.storeLocal(res, type);
		} else if(typeName.equals("konoha.String")) {
			gen.visitLdcInsn(upescape(val));
			gen.storeLocal(res, type);
		} else if(typeName.equals("konoha.Path")) {
			gen.visitTypeInsn(NEW, "konoha/K_Path");
			gen.visitInsn(DUP);
			gen.visitLdcInsn(upescape(val));
			gen.visitMethodInsn(INVOKESPECIAL, "konoha/K_Path", "<init>", "(Ljava/lang/String;)V");
			gen.storeLocal(res, type);
		} else if(typeName.startsWith("konoha.Array")) {
			if(token[4].equals("null")) {
				gen.visitInsn(ACONST_NULL);
				gen.storeLocal(res, type);
			} else {
				line = line.substring(line.indexOf("[") + 1, line.lastIndexOf("]")).replace(" ", "");
				String[] tk = line.split(",");
				Object[] obj;
				Type ty;
				if(typeName.equals("konoha.Array<konoha.Int>")) {
					obj = toIntArray(tk);
					ty = Type.INT_TYPE;
				} else if(typeName.equals("konoha.Array<konoha.Float>")) {
					obj = toDoubleArray(tk);
					ty = Type.DOUBLE_TYPE;
				} else if(typeName.equals("konoha.Array<konoha.Boolean>")) {
					obj = toBooleanArray(tk);
					ty = Type.BOOLEAN_TYPE;
				} else {
					throw new GenInstException("array type error");
				}
				gen.visitTypeInsn(NEW, "konoha/K_Array");
				gen.visitInsn(DUP);
				gen.visitMethodInsn(INVOKESPECIAL, "konoha/K_Array", "<init>", "()V");
				for(int i=0; i<obj.length; i++) {
					gen.visitInsn(DUP);
					gen.visitLdcInsn(i);
					gen.visitLdcInsn(obj[i]);
					gen.box(ty);
					gen.visitMethodInsn(INVOKESPECIAL, "konoha/K_Array", "set", "(ILjava/lang/Object;)V");
				}
				gen.storeLocal(res, type);
			}
		} else if(typeName.equals("konoha.Regex")) {
			val = val.substring(1, val.length() - 1);
			gen.visitTypeInsn(NEW, "konoha/K_Regex");
			gen.visitInsn(DUP);
			gen.visitLdcInsn(val);
			gen.visitMethodInsn(INVOKESPECIAL, "konoha/K_Regex", "<init>", "(Ljava/lang/String;)V");
			gen.storeLocal(res, type);
		} else if(typeName.equals("konoha.Class")) {
			String name = parser.toClassName(val).replace("/", ".");
			gen.visitTypeInsn(NEW, "konoha/K_Class");
			gen.visitInsn(DUP);
			gen.visitLdcInsn(name);
			gen.visitMethodInsn(INVOKESPECIAL, "konoha/K_Class", "<init>", "(Ljava/lang/String;)V");
			gen.storeLocal(res, type);
		} else {
			parser.warning("unknown const type: " + typeName);
			gen.visitInsn(ACONST_NULL);
			gen.storeLocal(res, type);
		}
	}
}
