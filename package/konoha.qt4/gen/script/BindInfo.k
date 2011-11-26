class BindInfo {
	String class_name;
	FunctionElement[] fea;
	FunctionElement constructor;
//	String[] unused_classes, unused_words;
	boolean abstract_class_flag;
	boolean template_class_flag;
	boolean inherits_qobject_flag;
	boolean inherits_qgraphicsitem_flag;
	boolean make_rapper_class_flag;
	boolean have_parent_flag;
	boolean have_compare_operator_flag;
	boolean have_private_destructor_flag;
	boolean have_event_method_flag;
	boolean have_scene_event_method_flag;
	String[] all_enums;
	String[] all_typedefed_objects;
//	String[] flag_objects;
	Tuple<String, String>[] all_flag_objects;
	String[] class_objects;
	String[] all_class_objects;
	String enum_bind;
	String func_bind;
	String event_bind;
	String header;
	String k_src;
	String dummy_hpp;
	String dummy_cpp;
	int[] parent_index;
	String[] parent_name;
	int[] children_index;
	String[] children_name;
	int hierarchy_depth;
	int qtInterfaceIndex;

	BindInfo(QtInterface interface) {
		inherits_qobject_flag = false;
		inherits_qgraphicsitem_flag = false;
		make_rapper_class_flag = true;
		have_compare_operator_flag = false;
		have_private_destructor_flag = false;
		have_event_method_flag = false;
		have_scene_event_method_flag = false;
		fea = [];
		unused_classes = [];
		constructor = null;
		unused_words = [];
		enum_bind = "";
		func_bind = "";
		event_bind = "";
		header = "";
		k_src = "";
		parent_index = [];
		parent_name = [];
		children_index = [];
		children_name = [];
		hierarchy_depth = -1;
		qtInterfaceIndex = -1;
		dummy_hpp = "";
		dummy_cpp = "";
		all_enums = [];
		all_typedefed_objects = [];
		all_flag_objects = [];
		class_objects = [];
		all_class_objects = [];

		class_name = interface.class_name;
		abstract_class_flag = interface.isAbstractClass();
		template_class_flag = interface.isTemplateClass();
		if (checkUnusedClass()) return;

		have_parent_flag = (|interface.parent_index| == 0 ? false : true);
		have_compare_operator_flag = checkHaveCompareToOperator(interface);
		all_enums = organizeAllEnums(interface);
		all_typedefed_objects = mergeStringArray(interface.typedefed_objects, interface.parent_typedefed_objects);

		all_flag_objects = organizeAllFlagObjects(interface);
		class_objects = interface.class_objects;
		all_class_objects = mergeStringArray(interface.class_objects, interface.parent_class_objects);

		makeFunctionElements(interface.reimplemented_public_functions, true);
		makeFunctionElements(interface.public_functions);
		makeFunctionElements(interface.static_public_members, false, true);
		makeFunctionElements(interface.public_slots);

		holdConstructor();
		checkEventDispatcher(interface);

		enum_bind = genEnumBind(interface.enums);
		have_private_destructor_flag = checkHavePrivateDestructor();
	}

	void genSrc() {
		String bind = "";
		String kinterface = "";
		foreach (FunctionElement fe in fea) {
			bind = "";
			bind = fe.genBind(make_rapper_class_flag, have_private_destructor_flag);
			bind = checkRenameFunctionList(bind);
			kinterface = "";
			kinterface = fe.genKonohaInterface();
			kinterface = checkRenameFunctionList(kinterface);
			bind = "//" + kinterface + bind;
			if (fe.overloadFlag || checkUnusedMethod(fe)) {
				bind = "/*\n" + bind + "*/";
				kinterface = "//" + kinterface;
			}
			bind += "\n";
			if (inherits_qgraphicsitem_flag &&
				fe.func_name == "paint") {
//				func_bind += FUNC_PAINT(class_name);
			} else {
				func_bind += bind;
			}
			if (kinterface == "") {
//				print "error bind";
//				print bind;
			} else {
				kinterface = kinterface.replace("QList<", "Array<");
				k_src += kinterface;
			}
		}
		if (inherits_qgraphicsitem_flag) {
			func_bind += FUNC_PAINT(class_name);
		}
		if (!checkObsolateClass()) {
			if (have_parent_flag) k_src += "@Override ";
			k_src += "@Virtual void <CLASS>.addEvent(String event_name, dynamic callback_func);\n";
			if (have_parent_flag) k_src += "@Override ";
			k_src += "@Virtual void <CLASS>.signalConnect(String signal_name, dynamic callback_func);\n";
			if (|parent_index| == 0) {
				func_bind += FUNC_PARENTS(class_name);
				k_src += "Array<String> <CLASS>.parents();\n";
			}
			k_src = k_src.replace("<CLASS>", class_name);
		}
	}

// 	boolean checkMakeRapperClass() {
// 		if (have_destructor_flag) {
// 			return true;
// 		} else {
// //			print class_name;
// 			return false;
// 		}
// 	}

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

	Tuple<String, String>[] organizeAllFlagObjects(QtInterface interface) {
		Tuple<String, String>[] ret = [];
		foreach (Tuple<String, String> flag_object in interface.flag_objects) {
			ret <<< flag_object;
		}
		foreach (Tuple<String, String> parent_flag_object in interface.parent_flag_objects) {
			ret <<< parent_flag_object;
		}
		foreach (Tuple<String, String> global_flag_object in GLOBAL_FLAG_LIST) {
			ret <<< global_flag_object;
		}
// 		if (class_name == "QAbstractFileEngine") {
// //			print interface;
// //			print ret;
// 		}
		return ret;
	}

	String[] mergeStringArray(String[] sa1, String[] sa2) {
		String[] ret = [];
		foreach (String s in sa1) {
			ret <<< s;
		}
		foreach (String s in sa2) {
			ret <<< s;
		}
		return ret;
	}

	void checkEventDispatcher(QtInterface interface) {
		foreach (String hsem in HAVE_SCENE_EVENT_METHOD) {
			if (class_name == hsem) {
				have_scene_event_method_flag = true;
				return;
			}
		}
		foreach (String mtd in NOT_HAVE_EVENT_METHOD) {
			if (class_name == mtd) {
				return;
			}
		}
		have_event_method_flag = true;
	}

	boolean checkUnusedWord(String mtd) {
		if (mtd == "") return true;
		foreach (key in UNUSED_WORDS) {
			if (key in? mtd) return true;
		}
		return false;
	}

	boolean checkHavePrivateDestructor() {
		foreach (String key in HAVE_PRIVATE_DESTRUCTOR_LIST) {
			if (key == class_name) return true;
		}
		return false;
	}

	boolean checkHaveProtectedDestructor() {
		foreach (String key in HAVE_PROTECTED_DESTRUCTOR_LIST) {
			if (key == class_name) return true;
		}
		return false;
	}

	boolean checkHaveConstructor() {
		if (constructor == null) {
			return false;
		} else {
			return true;
		}
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
//		if (fe.return_value_type_object_flag) return true;
		// foreach (boolean b in fe.argument_type_object_flag) {
		// 	if (b) return true;
		// }
		foreach (String key in UNUSED_METHOD) {
			if (key == fe.func_name) return true;
		}
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

	void renameGetter() {
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

	boolean checkHaveCompareToOperator(QtInterface interface) {
		foreach (String declaration in interface.public_functions) {
			if ("operator==" in? declaration) {
//				|declaration.split(class_name)| == 3) {
				return true;
			}
		}
		foreach (String declaration in interface.related_non_members) {
			if ("operator==" in? declaration &&
				|declaration.split(class_name)| == 3) {
				return true;
			}
		}
		return false;
	}

	void makeFunctionElements(String[] declarations, boolean overrideFlag = false, boolean staticFlag = false) {
		foreach (String declaration in declarations) {
			if (checkUnusedWord(declaration)) continue;
			FunctionElement fe = new FunctionElement(declaration, class_name);
			fe.pureVirtualFlag = checkPureVirtual(fe);
			fe.renamePublicTypes(all_enums, all_typedefed_objects, all_flag_objects, all_class_objects);
			fe.overrideFlag = overrideFlag;
			fe.staticFlag = staticFlag;
			fe.setKonohaTypes();
			if (checkUnusedMethod(fe)) continue;
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
