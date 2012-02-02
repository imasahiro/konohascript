package compiler.ir;

import java.util.Arrays;
import java.util.HashMap;

import org.objectweb.asm.Type;

import compiler.KMethod;
import compiler.Parser;

public class CallInst extends Inst {
	
	private static final HashMap<String, String> mathFunc = new HashMap<String, String>() {{
		put("fabs", "abs");
		put("ldexp", "scalb");
		put("fmod", "IEEEreminder");
		put("frexp", "exp");
	}};
	
	@Override public void asm(KMethod gen, Parser parser, String[] token) throws GenInstException {
		// parse
		boolean isStatic = token[token.length-1].equals("@static");
		String cName, mName;
		if(token[4].endsWith("..")) { // iterator?
			cName = token[4].substring(0, token[4].length() - 2);
			mName = "toIterator";
		} else {
			int n = token[4].lastIndexOf('.');
			cName = token[4].substring(0, n);
			mName = token[4].substring(n + 1);
		}
		cName = parser.toClassName(cName);
		String[] args = Arrays.copyOfRange(token, 6, token.length - 2);
		String ret = token[0];
		Type retType = parser.toType(token[3]);
		
		if(cName.equals("konoha/K_Object") || cName.equals("konoha/K_String")) {
			isStatic = true;		
		}
		// rename
		if(cName.equals("konoha/K_Int") && mName.equals("%s")) {
			cName = "konoha/K_OutputStream";
			mName = "sendInt";
		} else if(cName.equals("konoha/K_Float") && mName.equals("%s")) {
			cName = "konoha/K_OutputStream";
			mName = "sendFloat";
		} else if(cName.equals("konoha/K_Boolean") && mName.equals("%s")) {
			cName = "konoha/K_OutputStream";
			mName = "sendBoolean";
		} else if(cName.equals("java/lang/Math")) {
			String s = mathFunc.get(mName);
			if(s != null) mName = s;
		} else if(mName.equals("new:ARRAY")) {
			mName = "newArray";
		} else if(mName.equals("new:LIST")) {
			mName = "newList";
		} else if(mName.equals("new:MAP")) {
			mName = "newMap";
		} else if(mName.equals("==")) {
			mName = "equals";
		} else if(mName.equals("-")) {
			mName = "minus";
		}
		if(mName.equals("new")) {
			gen.asmCallConstructor(cName, args, retType, ret);
		} else {
			gen.asmCall(isStatic, cName, mName, args, retType, ret);
		}
	}
}
