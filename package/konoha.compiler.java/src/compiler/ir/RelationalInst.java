package compiler.ir;

import org.objectweb.asm.*;

import compiler.KMethod;
import compiler.Parser;

public abstract class RelationalInst extends Inst {
	
	public abstract int getOpcode();
	public abstract int getOpcodeZero();

	@Override public void asm(KMethod gen, Parser parser, String[] token) throws GenInstException {
		// parse
		String p1 = token[4];
		String p2 = token[5];
		String res = token[0];
		// gen
		Type type = gen.getLocalType(p1);
		Label l1 = new Label();
		Label l2 = new Label();

		gen.loadLocal(p1);
		gen.loadLocal(p2);
		if(type == Type.INT_TYPE) {
			gen.visitJumpInsn(getOpcode(), l1);
		} else if(type == Type.DOUBLE_TYPE) {
			// p1 < p2 --> -1
			// p1 > p2 -->  1
			// p1 == p2 --> 0
			gen.visitInsn(DCMPG);
			gen.jump(getOpcodeZero(), l1);
		} else {
			throw new GenInstException("type error");
		}
		// else block: push false
		gen.visitInsn(ICONST_0);
		gen.storeLocal(res, Type.BOOLEAN_TYPE);
		gen.jump(GOTO, l2);
		// then block: push true
		gen.visitLabel(l1);
		gen.visitInsn(ICONST_1);
		gen.storeLocal(res, Type.BOOLEAN_TYPE);
		// merge block
		gen.visitLabel(l2);
	}

	public static class EqInst extends RelationalInst {
		@Override public int getOpcode()     { return IF_ICMPEQ; }
		@Override public int getOpcodeZero() { return IFEQ; }
	}
	public static class NeqInst extends RelationalInst {
		@Override public int getOpcode()     { return IF_ICMPNE; }
		@Override public int getOpcodeZero() { return IFNE; }
	}
	public static class LtInst extends RelationalInst {
		@Override public int getOpcode()     { return IF_ICMPLT; }
		@Override public int getOpcodeZero() { return IFLT; }
	}
	public static class GtInst extends RelationalInst {
		@Override public int getOpcode()     { return IF_ICMPGT; }
		@Override public int getOpcodeZero() { return IFGT; }
	}
	public static class LteInst extends RelationalInst {
		@Override public int getOpcode()     { return IF_ICMPLE; }
		@Override public int getOpcodeZero() { return IFLE; }
	}
	public static class GteInst extends RelationalInst {
		@Override public int getOpcode()     { return IF_ICMPGE; }
		@Override public int getOpcodeZero() { return IFGE; }
	}
}
