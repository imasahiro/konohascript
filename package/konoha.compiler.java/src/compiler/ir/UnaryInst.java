package compiler.ir;

import org.objectweb.asm.Type;

import compiler.KMethod;
import compiler.Parser;

public class UnaryInst extends Inst {
	public static class NotInst extends UnaryInst {
		@Override public void asm(KMethod gen, Parser parser, String[] token) throws GenInstException {
			// parse
			String res = token[0];
			String var = token[4];
			// gen
			gen.mv.visitInsn(ICONST_1);
			gen.loadLocal(var);
			gen.mv.visitInsn(ISUB);
			gen.storeLocal(res, Type.BOOLEAN_TYPE);
		}
	}
}

