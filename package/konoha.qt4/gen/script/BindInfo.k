class BindInfo {
	String class_name;
	FunctionElement[] fea;
	FunctionElement constructor;
//	String[] unused_classes, unused_words;
	boolean abstract_class_flag;
	boolean template_class_flag;
	boolean inherits_qobject_flag;
	boolean make_rapper_class_flag;
	boolean have_parent_flag;
	boolean have_compare_operator_flag;
	String[] all_enums;
	String[] all_typedefed_objects;
	String enum_bind;
	String func_bind;
	String event_bind;
	String header;
	String k_src;
	String dummy_hpp;
	String dummy_cpp;
	int[] parent_index;
	String[] parent_name;
	int hierarchy_depth;
	int qtInterfaceIndex;

	BindInfo(QtInterface interface) {
		class_name = interface.class_name;
		abstract_class_flag = interface.isAbstractClass();
		template_class_flag = interface.isTemplateClass();
		have_parent_flag = (|interface.parent_index| == 0 ? false : true);
//		inherits_qobject_flag = checkInheritsQObject(class_name);
		inherits_qobject_flag = true;
		make_rapper_class_flag = true;
		have_compare_operator_flag = false;
		fea = [];
		unused_classes = [];
		unused_words = [];
		enum_bind = "";
		func_bind = "";
		event_bind = "";
		header = "";
		k_src = "";
		all_enums = [];
		all_typedefed_objects = [];
		parent_index = [];
		parent_name = [];
		hierarchy_depth = -1;
		qtInterfaceIndex = -1;
		dummy_hpp = "";
		dummy_cpp = "";

		if (checkUnusedClass()) return;

//		initializeAllMemberTypes(interface);
		all_enums = organizeAllEnums(interface);
		all_typedefed_objects = organizeAllTypedefedObjects(interface);
		makeFunctionElements(interface.reimplemented_public_functions, true);
		makeFunctionElements(interface.public_functions);
		holdConstructor();
		makeFunctionElements(interface.static_public_members);
		makeFunctionElements(interface.public_slots);
		enum_bind = genEnumBind(interface.enums);
//		genSrc();
	}

	void genSrc() {
		String bind = "";
		String knh_interface = "";
		foreach (FunctionElement fe in fea) {
			bind = "";
			bind = fe.genBind(make_rapper_class_flag);
			bind = checkRenameFunctionList(bind);
			knh_interface = "";
			knh_interface = fe.genKonohaInterface();
			knh_interface = checkRenameFunctionList(knh_interface);
			bind = "//" + knh_interface + bind;
			if (fe.overloadFlag) {
				bind = "/*\n" + bind + "*/";
				knh_interface = "//" + knh_interface;
			}
			bind += "\n";
			func_bind += bind;
			if (knh_interface == "") {
//				print "error bind";
//				print bind;
			} else {
				k_src = k_src.replace("QList<", "Array<");
				k_src += knh_interface;
			}
		}
		if (!checkObsolateClass()) {
			if (have_parent_flag) k_src += "@Override ";
			k_src += "@Virtual void <CLASS>.addEvent(String event_name, dynamic callback_func);\n";
			if (have_parent_flag) k_src += "@Override ";
			k_src += "@Virtual void <CLASS>.signalConnect(String signal_name, dynamic callback_func);\n";
			k_src = k_src.replace("<CLASS>", class_name);
		}
//		if (class_name == "QGestureEvent") print k_src;
	}

	boolean checkInheritsQObject(String name) {
		foreach (String nio in NOT_INHERITS_QOBJECT) {
			if (nio == name) {
				return false;
			}
		}
		return true;
	}

	boolean checkUnusedEnumName(String name) {
		foreach (String unused_enum in UNUSED_ENUM_NAME) {
			if (unused_enum == name) return true;
		}
		return false;
	}

	boolean checkUnusedEnumKey(String key) {
		foreach (String unused_enum in UNUSED_ENUM_KEY) {
			if (unused_enum in? key) return true;
		}
		return false;
	}

	String genEnumBind(EnumInterface[] enums) {
		if (|enums| == 0) return "";
		String enum_bind = "";
		enum_bind += "static knh_IntData_t CLASSConstInt[] = {\n";
//		print enum_bind;
//		print class_name;
		enum_bind = enum_bind.replace("CLASS", class_name);
//		print "!!!";
		boolean first = true;
		for (int j = 0; j < |enums|; j++) {
			EnumInterface e = enums[j];
//			print e;
			if (!e.isPublic()) {
				print "protected enum " + e.name + " in " + class_name;
				continue;
			}
			if (checkUnusedEnumName(e.name)) continue;
			for (int i = 0; i < |e.key|; i++) {
//				if (!(i == 0 && j == 0)) enum_bind += ",\n";
				if (first) {
					first = false;
				} else {
					enum_bind += ",\n";
				}
				if (checkUnusedEnumKey(e.key[i])) enum_bind += "//";
				enum_bind += EnumKeyPair(e.key[i], class_name);
			}
		}
		enum_bind += ",\n\t{NULL, 0}";
		enum_bind += "\n};\n\n";
		enum_bind += EnumLoad(class_name);
		return enum_bind;
	}

	String[] organizeAllEnums(QtInterface interface) {
		String[] ret = [];
		foreach (EnumInterface e in interface.enums) {
			ret <<< e.name;
		}
		foreach (EnumInterface pe in interface.parent_enums) {
			ret <<< pe.name;
		}
		return ret;
	}

	String[] organizeAllTypedefedObjects(QtInterface interface) {
		String[] ret = [];
		foreach (String typedefed_object in interface.typedefed_objects) {
			ret <<< typedefed_object;
		}
		foreach (String parent_typedefed_object in interface.parent_typedefed_objects) {
			ret <<< parent_typedefed_object;
		}
		return ret;
	}

	boolean checkUnusedWord(String mtd) {
		if (mtd == "") return true;
		foreach (key in UNUSED_WORDS) {
			if (key in? mtd) return true;
		}
		return false;
	}

	boolean checkHaveEventMethod() {
		foreach (String key in NOT_HAVE_EVENT_METHOD) {
			if (key == class_name) return false;
		}
		return true;
	}

	boolean checkHaveConstructor() {
		foreach (String key in NOT_HAVE_CONSTRUCTOR) {
			if (key == class_name) return false;
		}
		return true;
	}

	boolean checkObsolateClass() {
		foreach (String key in OBSOLATE_CLASS) {
			if (key == class_name) return true;
		}
		return false;
	}


	boolean checkUnusedClass() {
		if (template_class_flag) return true;
		foreach (String key in UNUSED_CLASSES) {
			if (key in? class_name) return true;
		}
		foreach (String key in OBSOLATE_CLASS) {
			if (key == class_name) return true;
		}
		return false;
	}

	boolean checkUnusedMethod(FunctionElement fe) {
		if (fe.notMakeFlag) return true;
		if (fe.destructorFlag) return true;
//		if (abstract_class_flag &&
//			fe.func_name == "new") return true;
		return false;
	}

	boolean checkPureVirtual(FunctionElement fe) {
		if (abstract_class_flag &&
			fe.func_name == "new") return true;
		return false;
	}

	String checkRenameFunctionList(String str) {
		String tmp = "";
		foreach (String[] a in RENAME_FUNCTION_LIST) {
			tmp = a[0] + "_" + a[1];
			str = str.replace(tmp, tmp + "OL");

			tmp = a[0] + "." + a[1];
			str = str.replace(tmp, tmp + "OL");
		}
		return str;
	}

	void checkAddVirtualFunctionList() {
		foreach (FunctionElement fe in fea) {
			foreach (String[] a in ADD_VIRTUAL_FUNCTION_LIST) {
				if (a[0] == fe.class_name &&
					a[1] == fe.func_name) {
					fe.virtualFlag = true;
					break;
				}
			}
		}
	}

	FunctionElement[] renameGetter() {
		FunctionElement[] setter = [];
		foreach (fe in fea) {
			if (fe.func_name.startsWith("set")) {
				setter <<< fe;
			}
		}
		boolean not_rename_flag = false;
		FunctionElement[] getter = [];
		foreach (set_fe in setter) {
			not_rename_flag = false;
			foreach (fe in fea) {
				if ((fe.func_name).startsWith("get") &&
					(set_fe.func_name - "set").convert(to:lower) == (fe.func_name - "get").convert(to:lower)) {
					not_rename_flag = true;
					break;
				}
			}
			if (not_rename_flag == true) continue;
			foreach (fe in fea) {
				if ((set_fe.func_name - "set").convert(to:lower) == fe.func_name.convert(to:lower)) {
					fe.funcGetterFlag = true;
					fe.default_getter_name = fe.func_name;
					fe.func_name = "get" + (set_fe.func_name - "set");
				}
			}
		}
	}

	void overloadCheck(boolean overrideFlag) {
		boolean[] finishedFlags = [];
		for (int i = 0; i < |fea|; i++) {
			finishedFlags <<< false;
		}

		for (int i = 0; i < |fea|; i++) {
			boolean overloadFlag = false;
			if (!finishedFlags[i]) {
				for (int j = i + 1; j < |fea|; j++) {
					if (!finishedFlags[j]) {
						if (fea[i].func_name == fea[j].func_name) {
							fea[j].overloadFlag = true;
							finishedFlags[j] = true;
							overloadFlag = true;
						}
					}
				}
				finishedFlags[i] = true;
				if (overloadFlag && overrideFlag) fea[i].overloadFlag = true;
			}
		}
		return;
	}

	void makeFunctionElements(String[] declarations, boolean overrideFlag = false) {
		foreach (String declaration in declarations) {
			if ("operator==" in? declaration) have_compare_operator_flag = true;
			if (checkUnusedWord(declaration)) continue;
			FunctionElement fe = new FunctionElement(declaration, class_name);
			if (checkUnusedMethod(fe)) continue;
			fe.pureVirtualFlag = checkPureVirtual(fe);
			fe.renamePublicTypes(all_enums, all_typedefed_objects);
			fe.overrideFlag = overrideFlag;
			fea <<< fe;
		}
		overloadCheck(overrideFlag);
		renameGetter();
		checkAddVirtualFunctionList();
		return;
	}

	void holdConstructor() {
		foreach (FunctionElement fe in fea) {
			if (fe.constructorFlag && !fe.overloadFlag) {
				constructor = fe;
				break;
			}
		}
	}
}
