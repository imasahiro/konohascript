package compiler;

import java.io.*;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.util.*;

import org.objectweb.asm.Type;

import compiler.ir.GenInstException;

public class JavaKonoha {
	
	private final Compiler compiler = new Compiler();
	
	public void compile(Reader r) {
		compiler.initScript();
		Parser parser = new Parser(r, compiler);
		try {
			parser.compile();
		} catch(GenInstException e) {
			System.err.println(parser.getLine());
			System.err.printf("(Error:%d) %s\n", parser.getLineNo(), e);
			return;
		} catch(Exception e) {
			System.err.printf("(Error:%d) %s\n", parser.getLineNo(), e);
			e.printStackTrace();
			return;
		}
	}
	
	public void compileFile(String fileName) throws IOException {
		if(fileName.endsWith(".k")) {
			Process proc = Runtime.getRuntime().exec("konohac " + fileName);
			compile(new InputStreamReader(proc.getInputStream()));
			Scanner err = new Scanner(proc.getErrorStream());
			while(err.hasNextLine()) {
				System.err.println("(konohac) " + err.nextLine());
			}
			try { proc.waitFor(); } catch(Exception e) { e.printStackTrace(); }
			int exitValue = proc.exitValue();
			if(exitValue != 0) {
				System.err.println("(konohac) ERROR: exitValue = " + exitValue);
				return;
			}
		} else {
			FileReader r = new FileReader(fileName);
			try {
				compile(r);
			} finally {
				r.close();
			}
		} 
	}
	
	public void eval(String script) {
		String file = "_jkonoha_eval_tmp.k";
		try {
			FileWriter fw = new FileWriter(file);
			compiler.dumpScriptDefs(new PrintWriter(fw));
			fw.write(script);
			fw.close();
			compileFile(file);
			//new File(file).delete();
			run(new String[0]);
		} catch(IOException e) {
			e.printStackTrace();
		}
	}
	
	public void writeClassFile() throws IOException {
		compiler.writeClassFile();
	}
	
	public void run(String[] args) {
		try {
			Method mtd = compiler.getMainMethod();
			mtd.invoke(null, (Object)args);
		} catch(VerifyError e) {
			e.printStackTrace();
		} catch(IllegalAccessException e) {
			e.printStackTrace();
		} catch(InvocationTargetException e) {
			System.err.println("(Error) Exception in script");
			e.getTargetException().printStackTrace();
		}
	}
	
	public static void interactive() {
		JavaKonoha konoha = new JavaKonoha();
		Scanner s = new Scanner(System.in);
		while(true) {
			System.out.print(">>>");
			String line = s.nextLine();
			if(line.equals("quit") || line.equals("exit") || line.equals("bye")) {
				System.exit(0);
			}
			konoha.eval(line);
		}
	}
	
	public static void printHelp() {
		System.out.println("usage: [command] [file] [args...]");
		System.out.println("  -c  compile only");
		System.out.println("  -i  interactive mode");
		System.out.println("  -h  show help");
	}
	
	public static void main(String args[]) throws IOException {
		boolean compile_only = false;
		String filename = null;
		for(int i=0; i<args.length; i++) {
			String arg = args[i];
			if(arg.startsWith("-")) {
				if(arg.equals("-c")) {
					compile_only = true;
				} else if(arg.equals("-h")) {
					printHelp();
					return ;
				} else if(arg.equals("-i")) {
					interactive();
					return;
				} else {
					System.err.println("bad arg: " + arg);
					return ;
				}
			} else {
				filename = args[i];
				args = Arrays.copyOfRange(args, i + 1, args.length);
				break;
			}
		}
		if(filename == null) {
			printHelp();
			return;
		}
		JavaKonoha konoha = new JavaKonoha();
		konoha.compileFile(filename);
		if(compile_only) {
			konoha.writeClassFile();
		} else {
			konoha.run(args);
		}
	}

}
