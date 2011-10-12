int QIsearchClassIndex(QtInterface[] interfaces, String class_name)
{
	int i;
	for (i = 0; i < |interfaces|; i++) {
		if (interfaces[i].class_name == class_name) return i;
	}
	return -1;
}

void QIsetParentIndex(QtInterface[] interfaces, QtHierarchy hierarchy)
{
//	ins = new InputStream("gen/hierarchy.k");
	foreach (String line in hierarchy.list) {
		line = line - "class " - ";" - "/" - "@Native " - "\n";
		String[] token = line.split(" ");
//		print token;
		if (|token| != 3) continue;
//		print token[0];
//		print token[2];

		int cci = QIsearchClassIndex(interfaces, token[0]); //child class index
		int pci = QIsearchClassIndex(interfaces, token[2]); //parent class index
		if (cci == -1 || pci == -1) continue;

		if (interfaces[cci].parent_index.indexOf(pci) == -1) {
			interfaces[cci].parent_index <<< pci;
			interfaces[cci].parent_name <<< token[2];
		}
	}
	return;
}

void setParentMemberTypes(QtInterface[] interfaces)
{
	foreach (QtInterface interface in interfaces) {
//		if (interface.class_name == "QWidget") print interface;
		if (|interface.parent_index| == 0) continue;
		foreach (int index in interface.parent_index) {
			foreach (String pto in interfaces[index].typedefed_objects) {
				interface.parent_typedefed_objects <<< pto;
			}
			foreach (EnumInterface ppe in interfaces[index].enums) {
				interface.parent_enums <<< ppe;
			}
		}
	}
}

void genInterfaceFile(QtInterface[] interfaces)
{
	System.chdir("gen");
	Dir interface_dir = System.openDir("interface");
	if (interface_dir == null) {
		System.exec("mkdir interface");
	}
	System.chdir("interface");
	foreach (QtInterface interface in interfaces) {
		ous = new OutputStream(interface.class_name);
		ous.println(MEMBERs_info("input_urn", interface.input_urn));
		ous.println(MEMBERs_info("output_urn", interface.output_urn));
		ous.println(MEMBERsa_info("inherits", interface.inherits));
		ous.println(MEMBERsa_info("public_types", interface.public_types));
		ous.println(MEMBERsa_info("properties", interface.properties));
		ous.println(MEMBERsa_info("public_functions", interface.public_functions));
		ous.println(MEMBERsa_info("public_slots", interface.public_slots));
		ous.println(MEMBERsa_info("signals", interface.signals));
		ous.println(MEMBERsa_info("static_public_members", interface.static_public_members));
		ous.println(MEMBERsa_info("protected_functions", interface.protected_functions));
		ous.println(MEMBERsa_info("reimplemented_public_functions", interface.reimplemented_public_functions));
		ous.println(MEMBERsa_info("reimplemented_protected_functions", interface.reimplemented_protected_functions));
		ous.println(MEMBERsa_info("protected_slots", interface.protected_slots));
		ous.println(MEMBERsa_info("related_non_members", interface.related_non_members));
		ous.println(MEMBERb_info("templateClass", interface.templateClass));
		ous.println(MEMBERb_info("abstractClass", interface.abstractClass));
		ous.println(MEMBERb_info("enbeddedClass", interface.enbeddedClass));
		ous.println(MEMBERsa_info("typedefed_objects", interface.typedefed_objects));
		ous.println(MEMBERsa_info("parent_typedefed_objects", interface.parent_typedefed_objects));
		ous.println(MEMBERea_info("enums", interface.enums));
		ous.println(MEMBERea_info("parent_enums", interface.parent_enums));
		ous.println(MEMBERia_info("parent_index", interface.parent_index));
		ous.println(MEMBERsa_info("parent_name", interface.parent_name));
		ous.flush();
		ous.close();
	}
	System.chdir("../..");
}

QtInterface[] loadInterfaceFile()
{
//	print "start loadInterfaceFile";
	String interface_path = "gen/interface/";
	Dir interface_dir = System.openDir(interface_path);
	if (interface_dir == null) {
		print "interface file not found";
		return [];
	}
	QtInterface[] interfaces = [];
	foreach (String filename in interface_dir.readName() ..) {

//		if (filename != "QWidget") continue;

//		print filename;
		QtInterface qi = new QtInterface("");
		qi.class_name = filename;
		ins = new InputStream(interface_path + filename);
		String line = "";
		while ((line = ins.readLine()) != null) {
			switch (line) {
			case "input_urn":
				qi.input_urn = toMEMBERs(ins);
				break;
			case "output_urn":
				qi.output_urn = toMEMBERs(ins);
				break;
			case "error_flag":
				qi.error_flag = toMEMBERb(ins);
				break;
//			case "inherits": not use
			case "public_types":
				setMEMBERsa(qi.public_types, ins);
				break;
			case "properties":
				setMEMBERsa(qi.properties, ins);
				break;
			case "public_functions":
				setMEMBERsa(qi.public_functions, ins);
				break;
			case "public_slots":
				setMEMBERsa(qi.public_slots, ins);
				break;
			case "signals":
				setMEMBERsa(qi.signals, ins);
				break;
			case "static_public_members":
				setMEMBERsa(qi.static_public_members, ins);
				break;
			case "protected_functions":
				setMEMBERsa(qi.protected_functions, ins);
				break;
			case "reimplemented_public_functions":
				setMEMBERsa(qi.reimplemented_public_functions, ins);
				break;
			case "reimplemented_protected_functions":
				setMEMBERsa(qi.reimplemented_protected_functions, ins);
				break;
			case "protected_slots":
				setMEMBERsa(qi.protected_slots, ins);
				break;
			case "related_non_members":
				setMEMBERsa(qi.related_non_members, ins);
				break;
			case "templateClass":
				qi.templateClass = toMEMBERb(ins);
				break;
			case "abstractClass":
				qi.abstractClass = toMEMBERb(ins);
				break;
			case "enbeddedClass":
				qi.enbeddedClass = toMEMBERb(ins);
				break;
			case "typedefed_objects":
				setMEMBERsa(qi.typedefed_objects, ins);
				break;
			case "parent_typedefed_objects":
				setMEMBERsa(qi.parent_typedefed_objects, ins);
				break;
			case "enums":
				setMEMBERea(qi.enums, ins);
				break;
			case "parent_enums":
				setMEMBERea(qi.parent_enums, ins);
				break;
			case "parent_index":
				setMEMBERia(qi.parent_index, ins);
				break;
			case "parent_name":
				setMEMBERsa(qi.parent_name, ins);
				break;
			}
		}
//		print qi;
		interfaces <<< qi;
	}
	return interfaces;
}

QtInterface[] makeQtInterface(Path doc_path, QtHierarchy hierarchy) {
	QtInterface[] ret = [];
	Dir doc_dir = System.openDir(doc_path);
	if (doc_dir == null) return [];
	if (GEN_INTERFACE_FILE) {
		foreach (String filename in doc_dir.readName() ..) {
			if (filename.startsWith("q") &&	filename.indexOf("qt3") == -1 &&
				filename.indexOf("q3") == -1 && filename.indexOf("-") == -1 &&
				filename.endsWith(".html")) {
//				print filename;
				QtInterface qi = new QtInterface(doc_path + filename);
				if (qi.error_flag) continue;
				ret << qi;
			}
		}
		QIsetParentIndex(ret, hierarchy);
		setParentMemberTypes(ret);
		genInterfaceFile(ret);
	} else {
		ret = loadInterfaceFile();
//		foreach (i in ret) {
//			if (i.class_name == "QAbstractItemView") print i;
//		}
	}
//	ous = new OutputStream("face_" + (String)GEN_INTERFACE_FILE);
//	foreach (r in ret) {
//		ous.println(r);
//	}
//	ous.flush();
//	ous.close();


	return ret;
}
