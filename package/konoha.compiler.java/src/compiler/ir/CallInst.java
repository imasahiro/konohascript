package compiler.ir;

import java.util.Arrays;

import org.objectweb.asm.Type;

import compiler.KMethod;
import compiler.Parser;

public class CallInst extends Inst {
	
	@Override public void asm(KMethod gen, Parser parser, String[] token) throws GenInstException {
		// parse
		boolean isStatic = token[token.length-1].equals("@static");
		String c_name, m_name;
		if(token[4].endsWith("..")) { // iterator?
			c_name = token[4].substring(0, token[4].length() - 2);
			m_name = "toIterator";
		} else {
			int n = token[4].lastIndexOf('.');
			c_name = token[4].substring(0, n);
			m_name = token[4].substring(n + 1);
		}
		c_name = parser.toClassName(c_name);
		String[] args = Arrays.copyOfRange(token, 6, token.length - 2);
		String ret = token[0];
		Type retType = parser.toType(token[3]);
		
		if(c_name.equals("konoha/K_Object")) {
			if(m_name.equals("isNull")) {
				gen.asmIsNull(args[0], ret);
				return;
			} else if(m_name.equals("isNotNull")) {
				gen.asmIsNotNull(args[0], ret);
				return;
			}
		}
		// rename
		if(c_name.equals("konoha/K_Int") && m_name.equals("%s")) {
			c_name = "konoha/K_OutputStream";
			m_name = "sendInt";
		} else if(c_name.equals("konoha/K_Float") && m_name.equals("%s")) {
			c_name = "konoha/K_OutputStream";
			m_name = "sendFloat";
		} else if(c_name.equals("konoha/K_Boolean") && m_name.equals("%s")) {
			c_name = "konoha/K_OutputStream";
			m_name = "sendBoolean";
		} else if(m_name.equals("new:ARRAY")) {
			m_name = "newArray";
		} else if(m_name.equals("new:LIST")) {
			m_name = "newList";
		} else if(m_name.equals("new:MAP")) {
			m_name = "newMap";
		} else if(m_name.equals("new")) {
			m_name = "_new";
		} else if(m_name.equals("==")) {
			m_name = "equals";
		} else if(m_name.equals("-")) {
			m_name = "minus";
		}
		gen.asmCall(isStatic, c_name, m_name, args, retType, ret);
	}
}
