package compiler.ir;

import org.objectweb.asm.Opcodes;
import org.objectweb.asm.Type;

import compiler.KMethod;
import compiler.Parser;

public class ConstInst extends Inst {
	
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
			val = val.replace("\\n", "\n");
			val = val.replace("\\t", "\t");
			val = val.replace("\"", "");
			gen.visitLdcInsn(val);
			gen.storeLocal(res, type);
		} else if(typeName.equals("konoha.Path")) {
			val = val.replace("\\n", "\n");
			val = val.replace("\\t", "\t");
			val = val.replace("\"", "");
			gen.visitTypeInsn(NEW, "konoha/K_Path");
			gen.visitInsn(DUP);
			gen.visitLdcInsn(val);
			gen.visitMethodInsn(INVOKESPECIAL, "konoha/K_Path", "<init>", "(Ljava/lang/String;)V");
			gen.storeLocal(res, type);
		} else if(typeName.equals("konoha.Array<konoha.Int>")) {
			line = line.substring(line.indexOf("[") + 1, line.lastIndexOf("]")).replace(" ", "");
			Object[] vals;
			if(line.length() == 0) {
				vals = new Object[0];
			} else {
				String[] tk = line.split(",");
				vals = new Object[tk.length];
				for(int i=0; i<vals.length; i++) {
					vals[i] = Integer.parseInt(tk[i]);
				}
			}
			gen.pushArray(res, Type.getType(konoha.K_Array.class), vals);
		} else if(typeName.equals("konoha.Array<konoha.Float>")) {
			Object[] vals;
			if(!token[4].equals("null")) {
				line = line.substring(line.indexOf("[") + 1, line.lastIndexOf("]")).replace(" ", "");
				if(line.length() == 0) {
					vals = new Object[0];
				} else {
					String[] tk =  line.split(",");
					vals = new Object[tk.length];
					for(int i=0; i<vals.length; i++) {
						vals[i] = Float.parseFloat(tk[i]);
					}
				}
			} else {
				vals = new Object[0];
			}
			gen.pushArray(res, Type.getType(konoha.K_Array.class), vals);
		} else if(typeName.equals("konoha.Array<konoha.Boolean>")) {
			line = line.substring(line.indexOf("[") + 1, line.lastIndexOf("]")).replace(" ", "");
			Object[] vals;
			if(line.length() == 0) {
				vals = new Object[0];
			} else {
				String[] tk =  line.split(",");
				vals = new Object[tk.length];
				for(int i=0; i<vals.length; i++) {
					vals[i] = Boolean.parseBoolean(tk[i]);
				}
			}
			gen.pushArray(res, Type.getType(konoha.K_Array.class), vals);
		} else if(typeName.equals("konoha.Regex")) {
			val = val.substring(1, val.length() - 1);
			gen.visitTypeInsn(NEW, "konoha/K_Regex");
			gen.visitInsn(DUP);
			gen.visitLdcInsn(val);
			gen.visitMethodInsn(INVOKESPECIAL, "konoha/K_Regex", "<init>", "(Ljava/lang/String;)V");
			gen.storeLocal(res, type);
		} else {
			parser.warning("unknown const type: " + typeName);
			gen.visitInsn(Opcodes.ACONST_NULL);
			gen.storeLocal(res, type);
		}
	}
}
