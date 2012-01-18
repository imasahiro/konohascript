package compiler;

import java.io.*;
import java.lang.reflect.*;
import java.util.Arrays;
import compiler.ir.GenInstException;

public class JavaKonoha {
	
	public static boolean compile_only = false;
	
	public static void main(String args[]) {
		String file = null;
		for(String arg : args) {
			if(arg.startsWith("-")) {
				if(arg.equals("-c")) {
					compile_only = true;
				} else {
					System.err.println("bad arg: " + arg);
					return;
				}
			} else {
				file = arg;
				break;
			}
		}
		if(file == null) {
			System.err.println("[file] [args...]");
			return;
		}
		Compiler c = new Compiler();
		try {
			Reader r;
			if(file.endsWith(".k")) {
				Process pr = Runtime.getRuntime().exec("konohac " + file);
				r = new InputStreamReader(pr.getInputStream());
			} else {
				r = new FileReader(file);
			} 
			Parser p = new Parser(r, c);
			try {
				p.compile();
			} catch(GenInstException e) {
				System.err.println(p.getLine());
				System.err.printf("(Error:%d) %s\n", p.getLineNo(), e);
				return;
			} catch(Exception e) {
				System.err.printf("(Error:%d) %s\n", p.getLineNo(), e);
				e.printStackTrace();
				return;
			}
		} catch(IOException e) {
			e.printStackTrace();
			return;
		}
		c.end();
		if(compile_only) {
			try {
				c.writeClassFile();
			} catch(IOException e) {
				e.printStackTrace();
			}
		} else {
			try {
				Method mtd = c.getMainMethod();
				Object arg = Arrays.copyOfRange(args, 1, args.length);
				mtd.invoke(null, arg);
			} catch(VerifyError e) {
				System.err.println(e);
			} catch(NoSuchMethodException e) {
				e.printStackTrace();
			} catch(IllegalAccessException e) {
				e.printStackTrace();
			} catch(InvocationTargetException e) {
				System.err.println("(Error) Exception in script");
				e.getTargetException().printStackTrace();
			}
		}
	}
	
}
