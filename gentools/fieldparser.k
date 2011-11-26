#!/usr/local/bin/konoha
/* Generate ./src/lang/llvm_struct.h */

String[][] typemap = [];
typemap.add(["kuintptr_t",       "ASMCODE_TYPE_LONG"]);
typemap.add(["void*",               "ASMCODE_TYPE_VOIDPTR"]);
typemap.add(["void**",              "ASMCODE_TYPE_VOIDPTR"]);
typemap.add(["kint_t",           "ASMCODE_TYPE_INT64"]);
typemap.add(["kuint_t",          "ASMCODE_TYPE_INT64"]);
typemap.add(["kunbox_t",         "ASMCODE_TYPE_INT64"]);
typemap.add(["size_t",              "ASMCODE_TYPE_LONG"]);
typemap.add(["kline_t",         "ASMCODE_TYPE_LONG"]);
typemap.add(["char[16]",            "ASMCODE_TYPE_VEC16"]);
typemap.add(["kflag_t",          "ASMCODE_TYPE_SHORT"]);
typemap.add(["kushort_t",        "ASMCODE_TYPE_SHORT"]);
typemap.add(["kclass_t",         "ASMCODE_TYPE_SHORT"]);
typemap.add(["kmethodn_t",       "ASMCODE_TYPE_SHORT"]);
typemap.add(["kuri_t",           "ASMCODE_TYPE_SHORT"]);
typemap.add(["ksfp_t*",          "ASMCODE_TYPE_SFPPTR"]);
typemap.add(["kshare_t",         "ASMCODE_TYPE_VOIDPTR"]);
typemap.add(["kSystem*",       "ASMCODE_TYPE_SYSPTR"]);
typemap.add(["knh_SystemEX_t*",     "ASMCODE_TYPE_SYSB"]);
typemap.add(["kObject*",       "ASMCODE_TYPE_OBJECTPTR"]);
typemap.add(["kObject**",      "ASMCODE_TYPE_OBJECTPTRPTR"]);
typemap.add(["kObjectHeader",       "ASMCODE_TYPE_HOBJECT"]);
typemap.add(["kArray*",        "ASMCODE_TYPE_ARRAYPTR"]);
typemap.add(["knh_Fmethod",         "ASMCODE_TYPE_FUNCTION"]);
typemap.add(["knh_Fitrnext",        "ASMCODE_TYPE_FUNCTION"]);
typemap.add(["kOutputStream*", "ASMCODE_TYPE_OUSPTR"]);
typemap.add(["kInputStream*",  "ASMCODE_TYPE_INSPTR"]);
String toLLVMTYPE(String type) {
	boolean matched = false;
	foreach (String[] types in typemap) {
		if (types[0] == type) {
			type = types[1];
			return type;
		}
	}
	return "ASMCODE_TYPE_VOIDPTR";
}

class Field {
	String type;
	String name;
	Field(String line) {
		v = line.split(" ");
		r = $/\[([0-9]*)\]/;
		if (v[1] in? r) {
			a = v[1].match(r);
			v[0] = v[0] + a[0];
			v[1] = v[1].replace(a[0], "");
		}
		type = toLLVMTYPE(v[0]);
		name = v[1].replace(";");
	}
	@Virtual Map<String,String> toJson() {
		return {name: _name, type: _type};
	}
	String toCStruct() {
		Map<String,String> v = toJson();
		return "{\"" + v["name"] + "\", " + v["type"] + "}";
	}
}
class RecordField extends Field {
	Field[] fields;
	RecordField(String line) {
		String[] v = line.split(";");
		fields = [];
		foreach (e in v) {
			if (e != "") {
				fields <<< new Field(e);
			}
		}
		type = "__union__";
		name = "__union__";
	}
	@Override Map<String,String> toJson() {
		return {name: fields[0].name, type: fields[0].type};
	}
}
class UnionField  extends RecordField {}
class StructField extends RecordField {}

Field[] genstruct(String name, OutputStream ous)
{
	t = "";
	int state = 0;
	ret = System.exec("gcc -E ./include/konoha1.h -DK_INTERNAL=1");
	reta = ret.split("\n");
	String[] retv = [];
	foreach (String s in reta) {
		foreach (String v in s.split(";")) {
			retv <<< v;
		}
	}
	foreach (String line in retv) {
		if ("struct " + name + " {" in? line) {
			state = 1;
		}
		else if (state == 1) {
			if (line == "") {
				continue;
			}
			if(line.startsWith("}")) {
				break;
			}
			t += line[1 to |line|-1] + "\n";
		}
	}
	t = t.replace(" * ", "* ");
	t = t.replace(" **", "** ");
	t = t.replace(" *", "* ");
	t = t.replace("struct knh_", "knh_");
	t = t.replace("const ", "");
	a = t.split("\n");
	String[] fields = [];
	for (int i=0; i < |a|; i++) {
		String v = a[i];
		if (v == "") continue;
		if (not "union {" in? v) {
			fields <<< v;
		} else {
			buf = "union:";
			for (int j=i+1; j < |a|; j++) {
				i++;
				if ("}" in? a[j]) {
					fields <<< buf;
					break;
				}
				buf += (a[j])[1 to];
			}
			continue;
		}
	}
	Field[] fa = [];
	foreach (String s in fields) {
		if (s.startsWith("union:")) {
			fa.add(new UnionField(s.replace("union:", "")));
		}
		else {
			fa.add(new Field(s));
		}
	}
	return fa;
}

void genstruct_start(String name, OutputStream ous) {
	String sname = "F_" + name.convert(to:upper);
	ous.println("static const struct codeasm_field " + sname + "[] = {");
}
void genstruct_end(String name, Field[] fa, OutputStream ous) {
	for (int i=0; i < |fa|; i++) {
		Field f = fa[i];
		/* FIXME "\t" + f.toCStruct() does not work */
		ous.print("\t");
		ous.print(f.toCStruct());
		if (i != |fa|-1) {
			ous.println(",")
		} else {
			ous.println("")
		}
	}
	ous.println("};");
	size  = "SIZE_F_" + name.convert(to:upper);
	sname = "STRUCT_" + name.convert(to:upper);
	fname = "F_" + name.convert(to:upper);
	ous.println("#define " + size + " " + |fa|);
	ous.println("static const struct cstruct " + sname + " = {");
	ous.println("\t\"" + name + "\",");
	ous.println("\t" + size + ",");
	ous.println("\t" + fname + "");
	ous.println("};");
}


void main (String[] args)
{
	targets = [
		"kObjectHeader", "kObject", "kArray", "kObject",
		"kOutputStream", "kInputStream", 
		"ksfp_t", "knh_SystemEX_t", "kSystem", "kMethod", "kIterator",
		"kcontext_t"/*kcontext_t must be last */
	]

	OutputStream ous = new OutputStream(file:./src/lang/llvm_struct.h);
	//OutputStream ous = OUT;//new OutputStream(file:./src/lang/llvm_struct.h);
	ous.println("""
#ifdef __cplusplus
extern "C" {
#endif
// THIS FILE WAS AUTOMATICALLY GENERATED
""");
	foreach (String t in targets) {
		genstruct_start(t, ous);
		fa = genstruct(t, ous);
		genstruct_end(t, fa, ous);
	}
	ous.println("""
#ifdef __cplusplus
}
#endif

// THIS FILE WAS AUTOMATICALLY GENERATED. DON'T EDIT.
""");
	ous.close();
}

