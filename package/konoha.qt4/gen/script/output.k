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
		ous.println(Class_Def(bi.class_name));
		ous.println(genFlagObjectCpp(bi.class_name, bi.all_flag_objects));
//		if (!GEN_CONCATENATE_FILE) ous.println("\n#ifdef __cplusplus\n}\n#endif");
		ous.flush();
		ous.close();
	}
	outputInitFunction();
	outputGlobalFlags();
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
	String k_flag_class = "";
	String k_flag_func = "";

	foreach (BindInfo bi in bia) {
		k_func += bi.k_src + "\n";
		k_flag_class += genFlagObjectKClass(bi.class_name, bi.all_flag_objects);
		k_flag_func += genFlagObjectKMtd(bi.class_name, bi.all_flag_objects);
		if (bi.class_name == "QPolygonF") k_func += "void QPolygonF.append(QPointF value);\n";
		if (bi.class_name == "QGraphicsScene") k_func += "void QGraphicsScene.addGraphicsTextItem(QGraphicsTextItem item);\n";
	}
	for (int i = 0; i < |hierarchy.defined_classes|; i++) {
		foreach (BindInfo bi in bia) {
			if (bi.class_name == hierarchy.defined_classes[i]) {
				k_class += hierarchy.list[i];
				break;
			}
		}
	}
	String k_data = KPreface();
	k_data += k_class;
	k_data += "@Native class Qt;\n";
	k_data += genGlobalFlagObjectKClass();
	k_data += k_flag_class;
	k_data += genGlobalFlagObjectKMtd();
	k_data += "QModelIndexList = Array<QModelIndex>;\n";
	k_data += "@Public @Native Array<String> System.getClassParents(String class_name);\n";
	k_data += k_func;
	k_data += k_flag_func;
	ous = new OutputStream("qt4.k");
	ous.println(k_data);
	ous.flush();
	ous.close();
}

void outputSrc(BindInfo[] bia, QtHierarchy hierarchy)
{
	OUT << "genSrc" << EOL;
	foreach (BindInfo bi in bia) {
		bi.genSrc();
	}
	OUT << "outputCppSrc" << EOL;
	outputCppSrc(bia);
	OUT << "outputHppSrc" << EOL;
	outputHppSrc(bia);
	OUT << "outputKSrc" << EOL;
	outputKSrc(bia, hierarchy);
}

void outputCompletionRate(QtInterface[] interfaces, BindInfo[] bia, int event_mtds_num) {
	if (!OUTPUT_ALL_METHODS) return;

	OUT << "output compretion rate" << EOL;

	boolean denomi_flag = false;

	int denominator = 0;
	if (denomi_flag) {
		foreach (QtInterface interface in interfaces) {
			denominator += (|interface.public_functions|);
			denominator += (|interface.public_slots|);
			denominator += (|interface.signals|);
			denominator += (|interface.static_public_members|);
			denominator += (|interface.protected_functions|);
			denominator += (|interface.reimplemented_public_functions|);
			denominator += (|interface.reimplemented_protected_functions|);
			denominator += (|interface.protected_slots|);
		}
	} else {
		int index = 0;
		foreach (BindInfo bi in bia) {
			if (bi.checkUnusedClass()) continue;
			index = bi.qtInterfaceIndex;
			denominator += (|interfaces[index].public_functions|);
			denominator += (|interfaces[index].public_slots|);
			denominator += (|interfaces[index].signals|);
			denominator += (|interfaces[index].static_public_members|);
			denominator += (|interfaces[index].protected_functions|);
			denominator += (|interfaces[index].reimplemented_public_functions|);
			denominator += (|interfaces[index].reimplemented_protected_functions|);
			denominator += (|interfaces[index].protected_slots|);
		}
	}

	float numerator = 0.0;
	numerator += event_mtds_num;
//	print numerator;
	ins = new InputStream("qt4.k");
	if (ins == null) return;
	foreach (String line in ins) {
		if (line == "") {
			continue;
		}
		if (!("class " in? line) &&
			!("addEvent" in? line) &&
			!("signalConnect" in? line)) {
			numerator++;
		} else {
//			print line;
		}
	}
//	print numerator;

//	print denominator;
//	print numerator;
	float completion_rate = numerator / denominator * 100;
	OUT << "compretion rate = " << completion_rate << EOL;
	return;
}

