package compiler;

import java.io.*;
import java.util.*;
import java.util.regex.*;

import org.objectweb.asm.Type;

import compiler.ir.*;

public class Parser {
	private final BufferedReader br;
	private final Compiler com;
	private int topCount = 0;
	private int lineNo = -1;
	private String line;
	
	public Parser(Reader r, Compiler com) {
		this.br = new BufferedReader(r);
		this.com = com;
	}
	
	public int getLineNo() {
		return lineNo;
	}
	
	public String getLine() {
		return line;
	}
	
	public void warning(String msg) {
		System.err.printf("(Warning:%d) %s\n", lineNo, msg);
	}
	
	private void loadLines(Map<KMethod, List<String>> codes) throws IOException, GenInstException {
		String l;
		for(int no=1; (l = br.readLine()) != null; no++) {
			if(l.startsWith("class")) {
				KClass c = parseClass(l);
				br.readLine(); // {
				no++;
				while(true) {
					l = br.readLine();
					no++;
					if(l == null || l.equals("}")) break;
					if(c != null) parseField(c, l);
				}
			} else if(l.startsWith("def")) {
				KMethod mtd = parseMethod(l);
				mtd.lineNo = no;
				ArrayList<String> list = new ArrayList<String>();
				while(true) {
					l = br.readLine();
					no++;
					if(l == null || l.equals("}")) break;
					list.add(l);
				}
				codes.put(mtd, list);
			} else if(l.length() != 0) {
				warning(l);
			}
		}
	}
	
	public void compile() throws IOException, GenInstException {
		HashMap<KMethod, List<String>> codes = new HashMap<KMethod, List<String>>();
		loadLines(codes);
		for(KMethod gen : codes.keySet()) {
			boolean gen_exit = false;
			try {
				for(String l : codes.get(gen)) {
					if(l.contains("= mov")) {
						String[] tk = splitToken(l);
						gen.addSameLocal(tk[4], tk[0], toType(tk[3]));
					}
				}
				this.lineNo = gen.lineNo;
				for(String l : codes.get(gen)) {
					line = l;
					lineNo++;
					if(line.startsWith("BasicBlock")) {
						parseBlock(gen, line);
					} else if(line.length() != 0){
						String[] tk = splitToken(line);
						Inst inst = instMap.get(tk[2]);
						if(inst != null) {
							inst.asm(gen, this, tk);
						} else {
							throw new GenInstException("unknown inst: " + tk[2]);
						}
					}
				}
				gen_exit = true;
			} finally {
				if(!gen_exit) {
					gen.dump();
				}
			}
		}
	}
	
	private static final Pattern splitPattern = Pattern.compile("[ \t]*(\".*?[^\\\\]\"|[^ ]+)");
	private final ArrayList<String> tokenBuff = new ArrayList<String>();
	
	private String[] splitToken(String line) {
		tokenBuff.clear();
		Matcher m = splitPattern.matcher(line);
		while(m.find()) {
			tokenBuff.add(m.group().trim());
		}
		return tokenBuff.toArray(new String[tokenBuff.size()]);
	}
	
	private KClass parseClass(String line) throws GenInstException {
		String[] tk = splitToken(line);
		Type type = toType(tk[1]);
		String className = type.getInternalName();
		Type superType = toType(tk[3]);
		if(className.startsWith("java/")) {
			return null;
		} else {
			return com.createClass(className, superType.getInternalName());
		}
	}
	
	private void parseField(KClass c, String line) throws GenInstException {
		String[] tk = splitToken(line);
		Type type = toType(tk[0]);
		String name = tk[1];
		c.createField(name, type);
	}
	
	private KMethod parseMethod(String line) throws GenInstException {
		String[] tk = splitToken(line);
		Type ret = toType(tk[1]);
		int n = tk[2].lastIndexOf('.');
		String cName = tk[2].substring(0, n);
		String mName = tk[2].substring(n + 1);
		int offset;
		String thisObj;
		if(tk[3].equals("(")) {
			thisObj = null;
			offset = 4;
		} else {
			thisObj = tk[3];
			offset = 5;
		}
		int args = (tk.length - (offset + 2)) / 2;
		Type[] argTypes = new Type[args];
		String[] argNames = new String[args];
		for(int i=0; i<args; i++) {
			argTypes[i] = toType(tk[offset + i * 2]);
			argNames[i] = tk[offset + i * 2 + 1];
		}
		
		if(cName.equals("Script") && mName.equals("")) {
			mName = "_init" + (topCount++);
			com.addTopLevelMethod(mName);
		} else if(mName.equals("new")) {
			mName = "_new";
		}
		KClass klass = com.getClass(cName);
		if(klass == null) {
			throw new GenInstException("class not found: " + cName);
		}
		KMethod mtd = klass.createMethod(com, mName, thisObj, ret, argTypes, argNames);
		if(cName.equals("Script") && mName.equals("main")) {
			com.setMainMethod(mtd);
		}
		return mtd;
	}
	
	private void parseBlock(KMethod mtd, String line) {
		int n = line.indexOf(":");
		if(n == -1) n = line.length();
		int no = Integer.parseInt(line.substring(10, n));
		mtd.setBasicBlock(no);
	}
	
	public String toClassName(String name) throws GenInstException {
		int n = name.indexOf("<");
		if(n != -1) {
			name = name.substring(0, n);
		}
		if(name.startsWith("konoha.") || name.startsWith("java.") || name.startsWith("javax.") || name.startsWith("org.")) {
			if(name.startsWith("konoha.compiler.java")) {
				name = name.substring(21);
				name = "j" + name.substring(1).replace("_", ".");
			} else if(name.equals("konoha.math.Math")) {
				return "java/lang/Math";
			} else if(name.startsWith("konoha.")) {
				n = name.lastIndexOf('.');
				name = name.substring(0, n + 1) + "K_" + name.substring(n + 1);
			}
			try {
				Class.forName(name);
			} catch (ClassNotFoundException e) {
				throw new GenInstException("class not found: " + name);
			}
		} else {
			name = name.substring(name.indexOf('.') + 1);
		}
		return name.replace(".", "/");
	}
	
	public Type toType(String type) throws GenInstException {
		if(type.equals("konoha.Int")) {
			return Type.INT_TYPE;
		} else if(type.equals("konoha.Float")) {
			return Type.DOUBLE_TYPE;
		} else if(type.equals("konoha.Boolean")) {
			return Type.BOOLEAN_TYPE;
		} else if(type.equals("konoha.String")) {
			return Type.getType(String.class);
		} else if(type.equals("dynamic")) {
			return Type.getType(Object.class);
		} else if(type.equals("konoha.compiler.Script")) {
			return Type.getType("LScript;");
		} else if(type.equals("null")) {
			return Type.VOID_TYPE;
		}
		return Type.getType("L" + toClassName(type) + ";");
	}
	
	public int toBBn(String s) {
		return Integer.parseInt(s.substring(2));
	}
	
	private static final Map<String, Inst> instMap = new HashMap<String, Inst>();
	
	static {
		instMap.put("const",  new ConstInst());
		instMap.put("call",   new CallInst());
		instMap.put("mov" ,   new Inst.MovInst());
		instMap.put("phi" ,   new Inst.PhiInst());
		instMap.put("print" , new Inst.PrintInst());
		instMap.put("select", new Inst.SelectInst());
		instMap.put("return", new Inst.ReturnInst());
		instMap.put("jmp" ,   new Inst.JmpInst());
		instMap.put("cond",   new Inst.CondInst());
		instMap.put("new" ,   new Inst.NewInst());
		instMap.put("getidx", new Inst.GetIdxInst());
		instMap.put("setidx", new Inst.SetIdxInst());
		instMap.put("getfield", new Inst.GetFieldInst());
		instMap.put("setfield", new Inst.SetFieldInst());
		instMap.put("next",   new Inst.NextInst());
		instMap.put("cast",   new Inst.CastInst());
		instMap.put("bnul" ,  new Inst.TRInst.NullInst());
		instMap.put("cwb"  ,  new Inst.TRInst.CwbInst());
		instMap.put("tostr",  new Inst.TRInst.ToStrInst());
		instMap.put("box",    new Inst.TRInst.BoxInst());
		instMap.put("prop",   new Inst.TRInst.PropInst());
		instMap.put("not" ,   new UnaryInst.NotInst());
		instMap.put("add" ,   new BinaryInst.AddInst());
		instMap.put("sub" ,   new BinaryInst.SubInst());
		instMap.put("mul" ,   new BinaryInst.MulInst());
		instMap.put("div" ,   new BinaryInst.DivInst());
		instMap.put("mod" ,   new BinaryInst.ModInst());
		instMap.put("lsft",   new BinaryInst.LSftInst());
		instMap.put("rsft",   new BinaryInst.RSftInst());
		instMap.put("and" ,   new BinaryInst.AndInst());
		instMap.put("or"  ,   new BinaryInst.OrInst());
		instMap.put("xor" ,   new BinaryInst.XorInst());
		instMap.put("lt"  ,   new RelationalInst.LtInst());
		instMap.put("lte" ,   new RelationalInst.LteInst());
		instMap.put("gt"  ,   new RelationalInst.GtInst());
		instMap.put("gte" ,   new RelationalInst.GteInst());
		instMap.put("eq"  ,   new RelationalInst.EqInst());
		instMap.put("neq" ,   new RelationalInst.NeqInst());
	}
	
}
