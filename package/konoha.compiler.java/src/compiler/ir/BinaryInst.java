package compiler.ir;

import org.objectweb.asm.Type;

import compiler.KMethod;
import compiler.Parser;

public abstract class BinaryInst extends Inst {

	public abstract int getOpcode();

	@Override public void asm(KMethod gen, Parser parser, String[] token) throws GenInstException {
		// parse
		String p1 = token[4];
		String p2 = token[5];
		String res = token[0];
		Type type = parser.toType(token[3]);
		// gen
		gen.loadLocal(p1);
		gen.loadLocal(p2);
		gen.visitInsn(type.getOpcode(getOpcode()));
		gen.storeLocal(res, type);
	}
	
	public static class AddInst extends BinaryInst {
		@Override public int getOpcode() { return IADD; }
	}
	public static class SubInst extends BinaryInst {
		@Override public int getOpcode() { return ISUB; }
	}
	public static class MulInst extends BinaryInst {
		@Override public int getOpcode() { return IMUL; }
	}
	public static class DivInst extends BinaryInst {
		@Override public int getOpcode() { return IDIV; }
	}
	public static class ModInst extends BinaryInst {
		@Override public int getOpcode() { return IREM; }
	}
	public static class AndInst extends BinaryInst {
		@Override public int getOpcode() { return IAND; }
	}
	public static class OrInst extends BinaryInst {
		@Override public int getOpcode() { return IOR; }
	}
	public static class XorInst extends BinaryInst {
		@Override public int getOpcode() { return IXOR; }
	}
	public static class LSftInst extends BinaryInst {
		@Override public int getOpcode() { return ISHL; }
	}
	public static class RSftInst extends BinaryInst {
		@Override public int getOpcode() { return ISHR; }
	}
}

