using konoha.posix.*;

GEN_CPP_SRC = true;
GEN_ENUM_BIND = true;
OUTPUT_ALL_METHODS = true;
OUTPUT_EVENT_BIND = true;
GEN_CONCATENATE_FILE = true;

include "gen/config.k";
include "gen/script/EnumInterface.k";
include "gen/script/bind.k";

void concatenateHpp(InputStream ins)
{
	String all_class_decralation = "";
	String qt_headers = "";
	String[] kq_headers = [];

	foreach (String line in ins) {
		kq_headers <<< "include/K" + line + ".hpp";
//		qt_headers += "#include <" + line + ">\n";
		all_class_decralation += "class " + line + ";\n";
		all_class_decralation += "class Dummy" + line + ";\n";
	}
	hpp_ous = new OutputStream(CONCATENATE_HPP_FILE);
	hpp_ous.println("#include <qt4_common.hpp>\n");
	hpp_ous.println(qt_headers);
	hpp_ous.println(all_class_decralation);
	foreach (header in kq_headers) {
		hpp_ous.println(System.exec("cat " + header));
	}
	hpp_ous.flush();
	hpp_ous.close();
}

void concatenateCpp()
{
	cpp_ous = new OutputStream(CONCATENATE_CPP_FILE);
	cpp_ous.println(ConcatenateCppPreface());
	cpp_ous.println(System.exec("cat src/*"));
	cpp_ous.println("#ifdef __cplusplus\n}\n#endif");
	cpp_ous.flush();
	cpp_ous.close();
}

void main()
{
	if (!GEN_CONCATENATE_FILE) {
		return;
	}
	print "concatenate";
	String src_path = "src/";
	Dir src_dir = System.openDir(src_path);
	if (src_path == null) {
		print "error in concatenate: src directory not found!!";
		return;
	}
	String include_path = "include/";
	Dir include_dir = System.openDir(include_path);
	if (include_dir == null) {
		print "error in concatenate: moc directory not found!!";
		return;
	}
	ins = new InputStream("gen/script/concatenate_order");
	if (ins != null) {
		concatenateHpp(ins);
		concatenateCpp();
		print "exit nomally";
	} else {
		print "error in concatenate: order file not found";
	}
}
