void outputInitFunction()
{
	ous = new OutputStream("QtInitFunction.cpp");
	ous.println(InitFunc());
	ous.flush();
	ous.close();
	return;
}

void outputCppSrc(BindInfo[] bia)
{
	Dir src_dir = System.openDir("src");
	if (src_dir == null) {
		System.exec("mkdir src");
	}
	System.chdir("src");
	foreach (BindInfo bi in bia) {
		if (bi.checkUnusedClass()) continue;
		ous = new OutputStream("K" + bi.class_name + ".cpp");
		if (!GEN_CONCATENATE_FILE) ous.println(CppPreface(bi.class_name));
		ous.println(bi.func_bind);
		ous.println(bi.dummy_cpp);
		if (OUTPUT_EVENT_BIND) ous.println(bi.event_bind);
		ous.println(bi.enum_bind);
		if (!GEN_CONCATENATE_FILE) ous.println("\n#ifdef __cplusplus\n}\n#endif");
		ous.flush();
		ous.close();
	}
	outputInitFunction();
	System.chdir("..");
}

void outputHppSrc(BindInfo[] bia)
{
	Dir include_dir = System.openDir("include");
	if (include_dir == null) {
		System.exec("mkdir include");
	}
	System.chdir("include");
	foreach (BindInfo bi in bia) {
		if (bi.checkUnusedClass()) continue;
		ous = new OutputStream("K" + bi.class_name + ".hpp");
		if (!GEN_CONCATENATE_FILE) ous.println("#include <qt4_common.hpp>");
		ous.println("#ifndef " + bi.class_name.convert(to:upper));
		ous.println("#define " + bi.class_name.convert(to:upper));
		ous.println(bi.dummy_hpp);
		ous.println(bi.header);
		ous.println("#endif //" + bi.class_name.convert(to:upper) + "\n\n");
		ous.flush();
		ous.close();
	}
	ous = new OutputStream("qt4_common.hpp");
	ous.println(CommonHpp());
	ous.flush();
	ous.close();
	System.chdir("..");
}

void outputKSrc(BindInfo[] bia, QtHierarchy hierarchy)
{
	String k_class = "";
	String k_func = "";
	foreach (BindInfo bi in bia) {
		k_func+= bi.k_src + "\n";
	}
	for (int i = 0; i < |hierarchy.defined_classes|; i++) {
		foreach (BindInfo bi in bia) {
			if (bi.class_name == hierarchy.defined_classes[i]) {
				k_class += hierarchy.list[i];
				break;
			}
		}
	}
//	print k_class;
	String k_data = KPreface();
	k_data += k_class;
	k_data += "QModelIndexList = Array<QModelIndex>;\n";
	k_data += k_func;
	ous = new OutputStream("qt4.k");
	ous.println(k_data);
	ous.flush();
	ous.close();
}

void outputSrc(BindInfo[] bia, QtHierarchy hierarchy)
{
	print "genSrc()";
	foreach (BindInfo bi in bia) {
		bi.genSrc();
	}
	print "outputCppSrc";
	outputCppSrc(bia);
	print "outputHppSrc";
	outputHppSrc(bia);
	print "outputKSrc";
	outputKSrc(bia, hierarchy);
}

float calcurateCompRate(int all_methods_number, int event_mtds_num)
{
	int count = 0;
	ins = new InputStream("qt4.k");
	if (ins == null) return -1;
	foreach (String line in ins) {
		if (line == "") continue;
		if (!("class" in? line)) count++;
	}
	return (float)(count + event_mtds_num) / (float)all_methods_number * 100;
}

void outputAllMethods(QtInterface[] interfaces, int event_mtds_num) {
	if (!OUTPUT_ALL_METHODS) return;

	print "output allmethods";
	String[] all_methods = [];
	foreach (QtInterface interface in interfaces) {
		foreach (String public_function in interface.public_functions) {
			all_methods <<< public_function;
		}
		foreach (String public_slot in interface.public_slots) {
			all_methods <<< public_slot;
		}
		foreach (String static_public_member in interface.static_public_members) {
			all_methods <<< static_public_member;
		}
		foreach (String protected_function in interface.protected_functions) {
			all_methods <<< protected_function;
		}
		foreach (String reimplemented_public_function in interface.reimplemented_public_functions) {
			all_methods <<< reimplemented_public_function;
		}
		foreach (String reimplemented_protected_function in interface.reimplemented_protected_functions) {
			all_methods <<< reimplemented_protected_function;
		}
		foreach (String protected_slot in interface.protected_slots) {
			all_methods <<< protected_slot;
		}
		foreach (String signal in interface.signals) {
			all_methods <<< signal;
		}
	}
	ous = new OutputStream("allMethods");
	foreach (String mtd in all_methods) {
		ous.println(mtd);
	}
	ous.flush();
	ous.close();
//	int all_methods_number = |all_methods|;
//	String k_file_line_number = System.exec("wc -l qt4.k") - System" qt4.k\n";
//	String hierarchy_file_line_number = System.exec("wc -l qt4.k") - System" qt4.k\n";
//	float conpletion_rate = ((float)binded_methods_number / (float)all_methods_number) * 100;
//	print binded_methods_number;
//	print all_methods_number;
	float completion_rate = calcurateCompRate(|all_methods|, event_mtds_num);
	print "completion rate = " +completion_rate + "%";
	return;
}

