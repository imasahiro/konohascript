class QMethod {
	String src;
	String fixed_src;
	String slot_src;
	String return_type;
	String mtd_name;
	String mtd_cname;
	String event_type_name;
	String[] argtypes;
	String[] knh_argtypes;
	String[] values;
    boolean overloadFlag;
	boolean return_value_type_object_flag;
	boolean[] argument_type_object_flag;
	
	QMethod(FunctionElement fe) {
		mtd_name = fe.func_name;
		return_type = fe.return_value_type.replace("Array<", "QList<");
		return_value_type_object_flag = fe.return_value_type_object_flag;
		argument_type_object_flag = []
		foreach (boolean b in fe.argument_type_object_flag) {
			argument_type_object_flag <<< b;
		}
		argtypes = [];
		foreach (String at in fe.argument_type) {
			at = at.replace("Array<", "QList<");
			argtypes <<< at;
		}
		values = [];
		foreach (String an in fe.argument_name) {
			values <<< an;
		}
		knh_argtypes = [];
        overloadFlag = false;
		setCTypeMethodName();
		setEventTypeMethodName();
		setFixedFunctionSource();
		setSlotSource();
		setKonohaArgTypes();
	}

	void parse(String func) {
		func = func.replace("virtual", "");
		String[] elems = func.split(" ");
		String[] tmp = [];
		foreach (String elem in elems) {
			if (elem == "" || "(" in? elem || ")" in? elem) continue;
			tmp << elem;
		}
		if (tmp[-1] == "const") tmp.remove(-1);
		for (int i = 0; i < |tmp|; i++) {
			if (tmp[i] == "const") {
				tmp[i + 1] = "const " + tmp[i + 1];
				tmp.remove(i);
			}
			if ("*" in? tmp[i]) {
				tmp[i - 1] += tmp[i];
				tmp.remove(i);
			}
			if (tmp[i] == "&") {
				tmp[i - 1] += " &";
				tmp.remove(i);
			}
			if (tmp[i] == "=") {
				tmp.remove(i);
				tmp.remove(i);
			}
		}
		elems = tmp;
		int i = 0;
		foreach (String elem in elems) {
			if (i == 0) {
				return_type = elem;
			} else if (i == 1) {
				mtd_name = elem;
			} else if (i % 2 == 0) {
				argtypes << elem;
			} else {
				elem = elem.replace(",", "");
				values << elem;
			}
			i++;
		}
	}

	void setCTypeMethodName() {
		String name = "";
		foreach (s in mtd_name) {
			lower = s.convert(to:lower);
			if (lower != s) {
				name += "_" + lower;
			} else {
				name += s;
			}
		}
		mtd_cname = name;
	}

	void setEventTypeMethodName() {
		String name = "";
		foreach (s in mtd_name) {
			lower = s.convert(to:lower);
			if (lower != s) {
				name += "-" + lower;
			} else {
				name += s;
			}
		}
		event_type_name = name;
	}

	void setFixedFunctionSource() {
//		fixed_src += return_type + " ";
		fixed_src += "bool" + " ";
		fixed_src += mtd_name + "(";
		for (int i = 0; i < |argtypes|; i++) {
			fixed_src += argtypes[i] + " ";
			fixed_src += values[i];
			if (|argtypes| > i+1) {
				fixed_src += ", ";
			}
		}
		fixed_src += ")";
	}

	void setSlotSource() {
		slot_src += return_type + " ";
		slot_src += mtd_name + "Slot" + "(";
		for (int i = 0; i < |argtypes|; i++) {
			slot_src += argtypes[i] + " ";
			slot_src += values[i];
			if (|argtypes| > i+1) {
				slot_src += ", ";
			}
		}
		slot_src += ")";
	}

	void setKonohaArgTypes() {
		String type = "";
		for (int i = 0; i < |argtypes|; i++) {
			type = "";
			type = argtypes[i];
			type = type.replace("*", "");
			type = type.replace("const", "");
			type = type.replace("&", "");
//			type = type.replace(" ", "");
			type = type.trim();
			if ("::" in? type &&
				!argument_type_object_flag[i]) type = "int";
			knh_argtypes << type;
		}
	}

	void debugPrint() {
		print "==============";
		print return_type;
		print mtd_name;
		print argtypes;
		print values;
		print "==============";
		print mtd_cname;
		print event_type_name;
	}
}


String genHeaderSource(String class_name, QMethod[] mtds, QMethod[] sigs, BindInfo bi)
{
// //======================== Generate Macros ========================//
// 	String macros = "";
// 	macros += "//#define getClassTBL(CLASS) lctx->share->ClassTBL[knh_getcid(lctx, STEXT(#CLASS))]\n";
// 	macros += "//#define new_RawPtrFromClass(CLASS, o) new_RawPtr(lctx, getClassTBL(CLASS), o)\n";
//=========================Generate KQClass =======================//
	String kqclass = "";
	kqclass += """
<PARENT>
class K<C> : <INHERITS> {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
<CR>
""";
	if (bi.checkHaveEventMethod()) kqclass += "\tbool event(QEvent *event);\n";
	if (bi.inherits_qobject_flag) {
		kqclass = kqclass.replace("<PARENT>", "");
		kqclass = kqclass.replace("<INHERITS>", "public <C>, public Dummy<C>");
	} else {
		String parent = """
class BaseK<C> : public <C>, public QObject {
public:
    BaseK<C>(ARGS);
};
""";
		kqclass = kqclass.replace("<PARENT>", parent);
		kqclass = kqclass.replace("<INHERITS>", "public BaseK<C>, public Dummy<C>");
	}
	// foreach (QMethod mtd in mtds) {
	// 	kqclass += "\tknh_Func_t *" + mtd.mtd_cname + "_func;\n"
	// }
	// foreach (QMethod mtd in sigs) {
	// 	kqclass += "\tknh_Func_t *" + mtd.mtd_cname + "_func;\n"
	// }


//========================= Constructor ==========================//
	if (bi.checkHaveConstructor()) {
		String constructor = "\tK<C>(ARGS);";
//	if (bi.class_name == "QWidget") print constructor;
		FunctionElement f = bi.constructor;
		String args = "";//, argnames = "";
		for (int i = 0; i < f.argument_number; i++) {
//		if ("Array<" in? f.argument_type[i]) f.argument_type[i] = "";
			f.argument_type[i] = f.argument_type[i].replace("Array<", "QList<");
			args += f.argument_type[i] + " " + f.argument_name[i];
			if (f.argument_number > i + 1) {
				args += ", ";
			}
		}
//	constructor = constructor.replace("ARGS", args);
//	if (bi.class_name == "QWidget") print constructor;
		kqclass = kqclass.replace("<CR>", constructor);
		kqclass = kqclass.replace("ARGS", args);
	} else {
		kqclass = kqclass.replace("<CR>", "");
	}
// //============== Generate Public Event Method List ================//
// 	foreach (QMethod mtd in mtds) {
// 		kqclass += "\t" + mtd.fixed_src + ";\n";
// 	}
// 	kqclass += "\tvoid setEventFunc(knh_Func_t *callback_func, std::string str);\n";
// 	kqclass += "\tvoid setSlotFunc(knh_Func_t *callback_func, std::string str);\n";
// // //====================== Generate Signals ========================//
// // 	kqclass += "signals:\n";
// // 	foreach (QMethod mtd in sigs) {
// // 		kqclass += "\t" + mtd.fixed_src + ";\n";
// // 	}
// //==================== Generate Public Slot ======================//
// 	kqclass += "public slots:\n";
// 	foreach (QMethod mtd in sigs) {
// 		kqclass += "\t" + mtd.slot_src + ";\n";
// 	}
// //===============================================================//

	kqclass += "};\n";
	
	String header = ""
	if (!GEN_CONCATENATE_FILE) header += "#include <<C>>\n";

//	if (bi.class_name == "QWidget")print bi.make_rapper_class_flag;
	if (bi.make_rapper_class_flag) {
		header += kqclass;
	}
	header = header.replace("<C>", class_name);
	return header;
}

String genCppSource(String class_name, QMethod[] mtds, QMethod[] sigs, BindInfo bi)
{
	String cpp_src = "";
	//================= Generate Constructor ====================//
	if (bi.checkHaveConstructor()) {
//    if (bi.make_rapper_class_flag) {
// 	if (bi.class_name == "QGraphicsAnchor") {
// 		cpp_src += """
// KQGraphicsAnchor::KQGraphicsAnchor()
// {
// """; 
//	} else if (bi.inherits_qobject_flag) {
		if (bi.inherits_qobject_flag) {
			cpp_src += """
K<C>::K<C>(ARGS) : <C>(ARGNAMES)
{
""";
		} else {
			cpp_src += """
BaseK<C>::BaseK<C>(ARGS) : <C>(ARGNAMES)
{
}

K<C>::K<C>(ARGS) : BaseK<C>(ARGNAMES)
{
""";
		}
		cpp_src += "\tself = NULL;\n";

		FunctionElement f = bi.constructor;
		String args = "", argnames = "";
		for (int i = 0; i < f.argument_number; i++) {
			args += f.argument_type[i] + " " + f.argument_name[i];
			argnames += f.argument_name[i];
			if (f.argument_number > i + 1) {
				args += ", ";
				argnames += ", ";
			}
		}
		cpp_src = cpp_src.replace("ARGS", args);
		cpp_src = cpp_src.replace("ARGNAMES", argnames);

// 		foreach (QMethod mtd in mtds) {
// 			cpp_src += "\t" + mtd.mtd_cname + "_func = NULL;\n";
// 		}
// 		foreach (QMethod mtd in sigs) {
// 			cpp_src += "\t" + mtd.mtd_cname + "_func = NULL;\n";
// 		}
// 		cpp_src += "\tevent_map = new map<string, knh_Func_t *>();\n";
// 		cpp_src += "\tslot_map = new map<string, knh_Func_t *>();\n";
// 		foreach (QMethod mtd in mtds) {
// //			cpp_src += "\tevent_map->insert(map<string, knh_Func_t *>::value_type(\"" + mtd.event_type_name + "\", " + mtd.mtd_cname + "_func));\n";
// 			cpp_src += "\tevent_map->insert(map<string, knh_Func_t *>::value_type(\"" + mtd.event_type_name + "\", NULL));\n";
// 		}
// 		foreach (QMethod mtd in sigs) {
// //			cpp_src += "\tslot_map->insert(map<string, knh_Func_t *>::value_type(\"" + mtd.event_type_name + "\", " + mtd.mtd_cname + "_func));\n";
// 			cpp_src += "\tslot_map->insert(map<string, knh_Func_t *>::value_type(\"" + mtd.event_type_name + "\", NULL));\n";
// 		}
		foreach (QMethod mtd in sigs) {
			cpp_src += "\tconnect(this, SIGNAL(<SIG>), this, SLOT(<SLOT>));\n";
			String tmp = "";
			for (int i = 0; i < |mtd.argtypes|; i++) {
				tmp += mtd.argtypes[i];
				if (|mtd.argtypes| > i+1) tmp += ", ";
			}
			cpp_src = cpp_src.replace("<SIG>", mtd.mtd_name + "(" + tmp + ")");
			cpp_src = cpp_src.replace("<SLOT>", mtd.mtd_name + "Slot(" + tmp + ")");
		}
		cpp_src += "}\n\n";
	}
// 	//================= Generate Event Methods =================//
//     if (bi.make_rapper_class_flag) {
// 		int i = 0;
// 		foreach (QMethod mtd in mtds) {
// 			cpp_src += "<R> K<C>::<M>(";
// 			for (i = 0; i < |mtd.argtypes|; i++) {
// 				cpp_src += mtd.argtypes[i] + " " + mtd.values[i];
// 				if (|mtd.argtypes| > i+1) {
// 					cpp_src += ", ";
// 				}
// 			}
// 			cpp_src += ")\n";
// 			cpp_src += "{\n";
// 			cpp_src += "\tif (<F> != NULL) {\n";
// 			cpp_src	+= "\t\tCTX lctx = knh_getCurrentContext();\n";
// 			cpp_src += "\t\tknh_sfp_t *lsfp = lctx->esp;\n";
// 			cpp_src += "\t\tKNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));\n";
//  			for (i = 0; i < |mtd.argtypes|; i++) {
// 				if ("::" in? mtd.knh_argtypes[i]) {
// 					print bi.class_name;
// 					print mtd.mtd_name;
// 				}
// 				// if ("QList" in? mtd.knh_argtypes[i]) {
// 				// 	print bi.class_name;
// 				// 	print mtd.mtd_name;
// 				// }
// 				cpp_src += EventArgPassing(mtd.knh_argtypes[i]);
//  				cpp_src = cpp_src.replace("<N>", (String)(i + 1));
//  				cpp_src = cpp_src.replace("<KT>", mtd.knh_argtypes[i]);
//  				cpp_src = cpp_src.replace("<V>", mtd.values[i]);
//  				cpp_src = cpp_src.replace("<T>", mtd.knh_argtypes[i] - "QList<" - ">");
//  				cpp_src = cpp_src.replace("<N>", (String)(i + 1));
//  				cpp_src = cpp_src.replace("<DELTA>", (String)(i + 2));
//  			}
// 			cpp_src += "\t\tknh_Func_invoke(lctx, " + mtd.mtd_cname + "_func, lsfp, <N>);\n";
// 			cpp_src = cpp_src.replace("<N>", (String)(i + 1));
// 			cpp_src += "\t}\n";
// 			cpp_src += EventReturn_(mtd.return_type, mtd.return_value_type_object_flag);
// 			cpp_src += "}\n";
// 			cpp_src += "\n";
// 			cpp_src = cpp_src.replace("<R>", mtd.return_type);
// 			cpp_src = cpp_src.replace("<C>", class_name);
// 			cpp_src = cpp_src.replace("<M>", mtd.mtd_name);
// 			cpp_src = cpp_src.replace("<F>", mtd.mtd_cname + "_func");
// 		}
// 	}
// //================ Generate Slot Methods ===================//
// 	if (bi.make_rapper_class_flag) {
// 		i = 0;
// 		foreach (QMethod mtd in sigs) {
// 			cpp_src += "<R> K<C>::<M>(";
// 			for (i = 0; i < |mtd.argtypes|; i++) {
// 				cpp_src += mtd.argtypes[i] + " " + mtd.values[i];
// 				if (|mtd.argtypes| > i+1) {
// 					cpp_src += ", ";
// 				}
// 			}
// 			cpp_src += ")\n";
// 			cpp_src += "{\n";
// 			cpp_src += "\tif (<F> != NULL) {\n";
// 			cpp_src	+= "\t\tCTX lctx = knh_getCurrentContext();\n";
// 			cpp_src += "\t\tknh_sfp_t *lsfp = lctx->esp;\n";
// 			cpp_src += "\t\tKNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));\n";
//  			for (i = 0; i < |mtd.argtypes|; i++) {
// 				if ("::" in? mtd.knh_argtypes[i]) {
// 					print bi.class_name;
// 					print mtd.mtd_name;
// 				}
// 				// if ("QList<" in? mtd.knh_argtypes[i]) {
// 				// 	print bi.class_name;
// 				// 	print mtd.mtd_name;
// 				// }
// 				cpp_src += EventArgPassing(mtd.knh_argtypes[i]);
//  				cpp_src = cpp_src.replace("<N>", (String)(i + 1));
//  				cpp_src = cpp_src.replace("<KT>", mtd.knh_argtypes[i]);
//  				cpp_src = cpp_src.replace("<V>", mtd.values[i]);
//  				cpp_src = cpp_src.replace("<T>", mtd.knh_argtypes[i] - "QList<" - ">");
//  				cpp_src = cpp_src.replace("<N>", (String)(i + 1));
//  				cpp_src = cpp_src.replace("<DELTA>", (String)(i + 2));
//  			}
// 			cpp_src += "\t\tknh_Func_invoke(lctx, " + mtd.mtd_cname + "_func, lsfp, <N>);\n";
// 			cpp_src = cpp_src.replace("<N>", (String)(i + 1));
// 			cpp_src += "\t}\n";
// 			cpp_src += EventReturn_(mtd.return_type, mtd.return_value_type_object_flag);
// 			cpp_src += "}\n";
// 			cpp_src += "\n";
// 			cpp_src = cpp_src.replace("<R>", mtd.return_type);
// 			cpp_src = cpp_src.replace("<C>", class_name);
// 			cpp_src = cpp_src.replace("<M>", mtd.mtd_name + "Slot");
// 			cpp_src = cpp_src.replace("<F>", mtd.mtd_cname + "_func");
// 		}
// 	}
// //================== Generate setFunc =========================//
// 	if (bi.make_rapper_class_flag) {
// 		cpp_src += """
// void K<C>::setEventFunc(knh_Func_t *callback_func, string str)
// {
// 	KNH_INITv((*event_map)[str], callback_func);
// """;
// 		foreach (QMethod mtd in mtds) {
// 			cpp_src += "\t" + mtd.mtd_cname + "_func = (*event_map)[\"" + mtd.event_type_name + "\"];\n";
// 		}
// 		cpp_src += "}\n\n";


// 		cpp_src += """
// void K<C>::setSlotFunc(knh_Func_t *callback_func, string str)
// {
// 	KNH_INITv((*slot_map)[str], callback_func);
// """;
// 		foreach (QMethod mtd in sigs) {
// 			cpp_src += "\t" + mtd.mtd_cname + "_func = (*slot_map)[\"" + mtd.event_type_name + "\"];\n";
// 		}
// 		cpp_src += "}\n\n";
// 	}

//================== Generate Binding Methods ====================//
//	if (bi.make_rapper_class_flag) {
cpp_src += """
KMETHOD <C>_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	<T>qp = RawPtr_to(<T>, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, \"WARNING:[<C>]unknown event name [%s]\\n\", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->Dummy<C>::addEvent(callback_func, str)) {
			fprintf(stderr, \"WARNING:[<C>]unknown event name [%s]\\n\", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD <C>_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	<T>qp = RawPtr_to(<T>, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, \"WARNING:[<C>]unknown signal name [%s]\\n\", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->Dummy<C>::signalConnect(callback_func, str)) {
			fprintf(stderr, \"WARNING:[<C>]unknown signal name [%s]\\n\", signal_name);
			return;
		}
	}
	RETURNvoid_();
}
""";
cpp_src = cpp_src.replace("<C>", class_name);
cpp_src = cpp_src.replace("<T>", "K" + class_name + " *");
//	}
//========================Generate for GC================================//
cpp_src += """

static void <CLASSNAME>_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		<RAPPER><CLASSNAME> *qp = (<RAPPER><CLASSNAME> *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
""";

cpp_src += """
static void <CLASSNAME>_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
<UNUSE>	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		<RAPPER><CLASSNAME> *qp = (<RAPPER><CLASSNAME> *)p->rawptr;
<UNUSE>		(void)qp;
""";
if (|mtds| == 0 && |sigs| == 0) {
	cpp_src = cpp_src.replace("<UNUSE>", "");
} else {
	cpp_src = cpp_src.replace("<UNUSE>", "//");
		}

	foreach (QMethod mtd in mtds) {
		cpp_src += "\t\tif (qp->" + mtd.mtd_cname + "_func != NULL) {\n";
		cpp_src += "\t\t\tKNH_ADDREF(ctx, qp->" + mtd.mtd_cname + "_func);\n";
		cpp_src	+= "\t\t\tKNH_SIZEREF(ctx);\n";
		cpp_src	+= "\t\t}\n";
	}
	foreach (QMethod mtd in sigs) {
		cpp_src += "\t\tif (qp->" + mtd.mtd_cname + "_func != NULL) {\n";
		cpp_src += "\t\t\tKNH_ADDREF(ctx, qp->" + mtd.mtd_cname + "_func);\n";
		cpp_src	+= "\t\t\tKNH_SIZEREF(ctx);\n";
		cpp_src	+= "\t\t}\n";
	}
	cpp_src += """
	}
}
""";
//=======================Generate compareTo==============================//

	cpp_src += COMPARE_TO(class_name, bi.have_compare_operator_flag);

//======================= Generate event ==============================//
	if (bi.checkHaveEventMethod()) {
		cpp_src += """

bool K<CLASSNAME>::event(QEvent *event)
{
	if (!Dummy<CLASSNAME>::eventDispatcher(event)) {
		<CLASSNAME>::event(event);
		return false;
	}
	return true;
}
""";
	}
	// } else {
	// 	int i = 0;
	// 	String wrapper = "";
	// 	foreach (QMethod mtd in mtds) {
	// 		 += "<R> K<C>::<M>(";
	// 		for (i = 0; i < |mtd.argtypes|; i++) {
	// 			dummy_cpp += mtd.argtypes[i] + " " + mtd.values[i];
	// 			if (|mtd.argtypes| > i+1) {
	// 				dummy_cpp += ", ";
	// 			}
	// 		}
	// 		dummy_cpp += ")\n";
	// 		dummy_cpp += "{\n";
	// 		for (i = 0; i < |mtd.argtypes|; i++) {
	// 			if ("::" in? mtd.knh_argtypes[i]) {
	// 				print bi.class_name;
	// 				print mtd.mtd_name;
	// 			}
	// 			// if ("QList" in? mtd.knh_argtypes[i]) {
	// 			// 	print bi.class_name;
	// 			// 	print mtd.mtd_name;
	// 			// }
	// 			dummy_cpp += EventArgPassing(mtd.knh_argtypes[i]);
	// 			dummy_cpp = dummy_cpp.replace("<N>", (String)(i + 1));
	// 			dummy_cpp = dummy_cpp.replace("<KT>", mtd.knh_argtypes[i]);
	// 			dummy_cpp = dummy_cpp.replace("<V>", mtd.values[i]);
	// 			dummy_cpp = dummy_cpp.replace("<T>", mtd.knh_argtypes[i] - "QList<" - ">");
	// 			dummy_cpp = dummy_cpp.replace("<N>", (String)(i + 1));
	// 			dummy_cpp = dummy_cpp.replace("<DELTA>", (String)(i + 2));
	// 		}
	// 		dummy_cpp = dummy_cpp.replace("<N>", (String)(i + 1));
	// 		dummy_cpp += "}\n";
	// 		dummy_cpp += "\n";
	// 		dummy_cpp = dummy_cpp.replace("<R>", mtd.return_type);
	// 		dummy_cpp = dummy_cpp.replace("<C>", bi.class_name);
	// 		dummy_cpp = dummy_cpp.replace("<M>", mtd.mtd_name);
	// 		dummy_cpp = dummy_cpp.replace("<F>", mtd.mtd_cname + "_func");
	// 	}
	// }




//======================= def ==========================================//
	cpp_src += """

DEFAPI(void) def<CLASSNAME>(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = \"<CLASSNAME>\";
	cdef->free = <CLASSNAME>_free;
	cdef->reftrace = <CLASSNAME>_reftrace;
	cdef->compareTo = <CLASSNAME>_compareTo;
}
""";
//=================================================================//
	if (!bi.make_rapper_class_flag) {
		cpp_src = cpp_src.replace("<RAPPER>", "");
	} else {
		cpp_src = cpp_src.replace("<RAPPER>", "K");
	}
	cpp_src = cpp_src.replace("<CLASSNAME>", class_name);
	return cpp_src;
}

void removeOverloadQMethod(QMethod[] methods)
{
	boolean[] finishedFlags = [];
	for (int i = 0; i < |methods|; i++) {
		finishedFlags <<< false;
	}
	for (int i = 0; i < |methods|; i++) {
		boolean overloadFlag = false;
		if (!finishedFlags[i]) {
			for (int j = i + 1; j < |methods|; j++) {
				if (!finishedFlags[j]) {
					if (methods[i].mtd_name == methods[j].mtd_name) {
						methods[j].overloadFlag = true;
						finishedFlags[j] = true;
						overloadFlag = true;
					}
				}
			}
			finishedFlags[i] = true;
			if (overloadFlag) methods[i].overloadFlag = true;
		}
	}
	for (int i = 0; i < |methods|; i++) {
		if (methods[i].overloadFlag) {
			methods.remove(i);
			i--;
		}
	}
	return;
}

String genDummyHeaderSource(BindInfo bi, QMethod[] mtds, QMethod[] sigs, BindInfo[] bia)
{
	String dummy_hpp = "";
//=================== Generate dummy class definition =======================//
	dummy_hpp += """
class Dummy<CLASS><INHERITS> {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
""";
	foreach (QMethod mtd in mtds) {
		dummy_hpp += "\tknh_Func_t *" + mtd.mtd_cname + "_func;\n"
	}
	foreach (QMethod mtd in sigs) {
		dummy_hpp += "\tknh_Func_t *" + mtd.mtd_cname + "_func;\n"
	}
	dummy_hpp += """
	Dummy<CLASS>();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
""";
//============== Generate Public Event Method List ================//
	foreach (QMethod mtd in mtds) {
		dummy_hpp += "\t" + mtd.fixed_src + ";\n";
	}
	dummy_hpp += "\tbool addEvent(knh_Func_t *callback_func, std::string str);\n";
	dummy_hpp += "\tbool signalConnect(knh_Func_t *callback_func, std::string str);\n";
// //====================== Generate Signals ========================//
// 	kqclass += "signals:\n";
// 	foreach (QMethod mtd in sigs) {
// 		kqclass += "\t" + mtd.fixed_src + ";\n";
// 	}
//==================== Generate Public Slot ======================//
	// dummy_hpp += "public slots:\n";
	// foreach (QMethod mtd in sigs) {
	// 	dummy_hpp += "\t" + mtd.slot_src + ";\n";
	// }
//======================== replace ==================================//
	dummy_hpp = dummy_hpp.replace("<CLASS>", bi.class_name);
	String inherits = "";
	if (|bi.parent_name| != 0) {
		inherits += " : ";
		for (int i = 0; i < |bi.parent_name|; i++) {
			inherits += "public Dummy" + bi.parent_name[i];
			if (i < |bi.parent_name| - 1) inherits += ", ";
		}
	}
	dummy_hpp = dummy_hpp.replace("<INHERITS>", inherits);

	dummy_hpp += "};";
	return dummy_hpp;
}


String genDummyCppSource(BindInfo bi, QMethod[] mtds, QMethod[] sigs, BindInfo[] bia, String[] e_table)
{
	String dummy_cpp = "";
//======================== Generate constructor ==============================//
	dummy_cpp += """
Dummy<CLASS>::Dummy<CLASS>()
{
	self = NULL;
""";
	foreach (QMethod mtd in mtds) {
		dummy_cpp += "\t" + mtd.mtd_cname + "_func = NULL;\n";
	}
	foreach (QMethod mtd in sigs) {
		dummy_cpp += "\t" + mtd.mtd_cname + "_func = NULL;\n";
	}
	dummy_cpp += "\tevent_map = new map<string, knh_Func_t *>();\n";
	dummy_cpp += "\tslot_map = new map<string, knh_Func_t *>();\n";
	foreach (QMethod mtd in mtds) {
		dummy_cpp += "\tevent_map->insert(map<string, knh_Func_t *>::value_type(\"" + mtd.event_type_name + "\", NULL));\n";
	}
	foreach (QMethod mtd in sigs) {
		dummy_cpp += "\tslot_map->insert(map<string, knh_Func_t *>::value_type(\"" + mtd.event_type_name + "\", NULL));\n";
	}
	dummy_cpp += "}\n"

//====================== setSelf =================================//

	dummy_cpp += """

void Dummy<C>::setSelf(knh_RawPtr_t *ptr)
{
	Dummy<C>::self = ptr;
""";
	foreach (String pn in bi.parent_name) {
		dummy_cpp += "\tDummy" + pn + "::setSelf(ptr);\n";
	}
	dummy_cpp += "}\n";

//======================== Generate eventDispatcher ================================//
	dummy_cpp += """

bool Dummy<CLASS>::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {""";
	foreach (QMethod mtd in mtds) {
		if (|mtd.argtypes| != 1) {
			continue;
		}
		String case_ = "";
		case_ += "<EVENT>\n";
		case_ += "\t\tret = " + mtd.mtd_name + "(dynamic_cast<" + mtd.argtypes[0] + ">(event));\n";
		case_ += "\t\tbreak;";

		String event = "";
		if (bi.class_name == "QGraphicsScene") {
			foreach (String enum_name in e_table) {
				if ((enum_name + "event").convert(to:lower) == ("GraphicsScene" + mtd.mtd_name).convert(to:lower)) {
					event = "";
					event += "\n\tcase QEvent::" + enum_name + ":";
					break;
				} else if ((enum_name + "event").convert(to:lower) == mtd.mtd_name.convert(to:lower)) {
					event += "\n\tcase QEvent::" + enum_name + ":";
				}
			}
		} else {
			foreach (String enum_name in e_table) {
				if ((enum_name + "event").convert(to:lower) == mtd.mtd_name.convert(to:lower)) {
					event += "\n\tcase QEvent::" + enum_name + ":";
					break;
				} else if ("Action" in? enum_name && mtd.mtd_name == "actionEvent") {
					event += "\n\tcase QEvent::" + enum_name + ":";
				} else if (((enum_name + "event").convert(to:lower) - "button") == mtd.mtd_name.convert(to:lower)) {
					event += "\n\tcase QEvent::" + enum_name + ":";
				} else if (!("Action" in? enum_name) && "Change" in? enum_name && "changeEvent" == mtd.mtd_name) {
					event += "\n\tcase QEvent::" + enum_name + ":";
				} else if ("Tablet" in? enum_name && "tabletEvent" == mtd.mtd_name) {
					event += "\n\tcase QEvent::" + enum_name + ":";
				} else if (enum_name ==  "MouseButtonDblClick" && mtd.mtd_name == "mouseDoubleClickEvent") {
					event += "\n\tcase QEvent::" + enum_name + ":";
				}
			}
		}
		case_ = case_.replace("<EVENT>", event);
		dummy_cpp += case_;
	}

	dummy_cpp +=  "\n\tdefault:\n";
	if (|bi.parent_name| == 0) {
		dummy_cpp += "\t\tret = false;\n";
	} else {
		for (int i = 0; i < |bi.parent_name|; i++) {
			dummy_cpp += "\t\tret = Dummy" + bi.parent_name[i] + "::eventDispatcher(event);\n";
			if (i < |bi.parent_name| - 1) {
				dummy_cpp += "\t\tif (ret) break;\n";
			}
		}
	}
	dummy_cpp += "\t\tbreak;\n";
	dummy_cpp += "\t}\n\treturn ret;\n}\n\n";

//================= Generate Event Methods =================//
//    if (bi.make_rapper_class_flag) {
	int i = 0;
	foreach (QMethod mtd in mtds) {
		dummy_cpp += "bool Dummy<C>::<M>(";
		for (i = 0; i < |mtd.argtypes|; i++) {
			dummy_cpp += mtd.argtypes[i] + " " + mtd.values[i];
			if (|mtd.argtypes| > i+1) {
				dummy_cpp += ", ";
			}
		}
		dummy_cpp += ")\n";
		dummy_cpp += "{\n";
		dummy_cpp += "\tif (<F> != NULL) {\n";
		dummy_cpp += "\t\tCTX lctx = knh_getCurrentContext();\n";
		dummy_cpp += "\t\tknh_sfp_t *lsfp = lctx->esp;\n";
		dummy_cpp += "\t\tKNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));\n";
		for (i = 0; i < |mtd.argtypes|; i++) {
			if ("::" in? mtd.knh_argtypes[i]) {
				print bi.class_name;
				print mtd.mtd_name;
			}
			// if ("QList" in? mtd.knh_argtypes[i]) {
			// 	print bi.class_name;
			// 	print mtd.mtd_name;
			// }
			dummy_cpp += EventArgPassing(mtd.knh_argtypes[i]);
			dummy_cpp = dummy_cpp.replace("<N>", (String)(i + 1));
			dummy_cpp = dummy_cpp.replace("<KT>", mtd.knh_argtypes[i]);
			dummy_cpp = dummy_cpp.replace("<V>", mtd.values[i]);
			dummy_cpp = dummy_cpp.replace("<T>", mtd.knh_argtypes[i] - "QList<" - ">");
			dummy_cpp = dummy_cpp.replace("<N>", (String)(i + 1));
			dummy_cpp = dummy_cpp.replace("<DELTA>", (String)(i + 2));
		}
		dummy_cpp += "\t\tknh_Func_invoke(lctx, " + mtd.mtd_cname + "_func, lsfp, <N>);\n";
		dummy_cpp += "\t\treturn true;\n";
		dummy_cpp = dummy_cpp.replace("<N>", (String)(i + 1));
		dummy_cpp += "\t}\n";
		dummy_cpp += "\treturn false;\n";
//		dummy_cpp += EventReturn_(mtd.return_type, mtd.return_value_type_object_flag);
		dummy_cpp += "}\n";
		dummy_cpp += "\n";
		dummy_cpp = dummy_cpp.replace("<R>", mtd.return_type);
		dummy_cpp = dummy_cpp.replace("<C>", bi.class_name);
		dummy_cpp = dummy_cpp.replace("<M>", mtd.mtd_name);
		dummy_cpp = dummy_cpp.replace("<F>", mtd.mtd_cname + "_func");
	}
//	}
//================ Generate Slot Methods ===================//
//	if (bi.make_rapper_class_flag) {
	i = 0;
	foreach (QMethod mtd in sigs) {
		dummy_cpp += "bool Dummy<C>::<M>(";
		for (i = 0; i < |mtd.argtypes|; i++) {
			dummy_cpp += mtd.argtypes[i] + " " + mtd.values[i];
			if (|mtd.argtypes| > i+1) {
				dummy_cpp += ", ";
			}
		}
		dummy_cpp += ")\n";
		dummy_cpp += "{\n";
		dummy_cpp += "\tif (<F> != NULL) {\n";
		dummy_cpp	+= "\t\tCTX lctx = knh_getCurrentContext();\n";
		dummy_cpp += "\t\tknh_sfp_t *lsfp = lctx->esp;\n";
		dummy_cpp += "\t\tKNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));\n";
		for (i = 0; i < |mtd.argtypes|; i++) {
			if ("::" in? mtd.knh_argtypes[i]) {
				print bi.class_name;
				print mtd.mtd_name;
			}
			// if ("QList<" in? mtd.knh_argtypes[i]) {
			// 	print bi.class_name;
			// 	print mtd.mtd_name;
			// }
			dummy_cpp += EventArgPassing(mtd.knh_argtypes[i]);
			dummy_cpp = dummy_cpp.replace("<N>", (String)(i + 1));
			dummy_cpp = dummy_cpp.replace("<KT>", mtd.knh_argtypes[i]);
			dummy_cpp = dummy_cpp.replace("<V>", mtd.values[i]);
			dummy_cpp = dummy_cpp.replace("<T>", mtd.knh_argtypes[i] - "QList<" - ">");
			dummy_cpp = dummy_cpp.replace("<N>", (String)(i + 1));
			dummy_cpp = dummy_cpp.replace("<DELTA>", (String)(i + 2));
		}
		dummy_cpp += "\t\tknh_Func_invoke(lctx, " + mtd.mtd_cname + "_func, lsfp, <N>);\n";
		dummy_cpp += "\t\treturn true;\n";
		dummy_cpp = dummy_cpp.replace("<N>", (String)(i + 1));
		dummy_cpp += "\t}\n";
		dummy_cpp += "\treturn false;\n";
//		dummy_cpp += EventReturn_(mtd.return_type, mtd.return_value_type_object_flag);
		dummy_cpp += "}\n";
		dummy_cpp += "\n";
		dummy_cpp = dummy_cpp.replace("<R>", mtd.return_type);
		dummy_cpp = dummy_cpp.replace("<C>", bi.class_name);
		dummy_cpp = dummy_cpp.replace("<M>", mtd.mtd_name + "Slot");
		dummy_cpp = dummy_cpp.replace("<F>", mtd.mtd_cname + "_func");
	}
//	}
//=========== Generate dummy::addEvent, dummy::signalConnect (setFunc) ==================//
//	if (bi.make_rapper_class_flag) {
	dummy_cpp += """
bool Dummy<C>::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = Dummy<C>::event_map->bigin();
	if ((itr = Dummy<C>::event_map->find(str)) == Dummy<C>::event_map->end()) {
		bool ret;
""";
	for (int i = 0; i < |bi.parent_name|; i++) {
		dummy_cpp += "\t\tret = Dummy" + bi.parent_name[i] + "::addEvent(callback_func, str);\n";
		if (i < |bi.parent_name| - 1) {
			dummy_cpp += "\t\tif (ret) return true;\n";
		}
	}
	dummy_cpp += """
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
""";
	foreach (QMethod mtd in mtds) {
		dummy_cpp += "\t\t" + mtd.mtd_cname + "_func = (*event_map)[\"" + mtd.event_type_name + "\"];\n";
	}
	dummy_cpp += "\t\treturn true;\n\t}\n}\n\n";
//
	dummy_cpp += """
bool Dummy<C>::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = Dummy<C>::slot_map->bigin();
	if ((itr = Dummy<C>::event_map->find(str)) == Dummy<C>::slot_map->end()) {
		bool ret;
""";
	for (int i = 0; i < |bi.parent_name|; i++) {
		dummy_cpp += "\t\tret = Dummy" + bi.parent_name[i] + "::signalConnect(callback_func, str);\n";
		if (i < |bi.parent_name| - 1) {
			dummy_cpp += "\t\tif (ret) return true;\n";
		}
	}
	dummy_cpp += """
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
""";
	foreach (QMethod mtd in sigs) {
		dummy_cpp += "\t\t" + mtd.mtd_cname + "_func = (*slot_map)[\"" + mtd.event_type_name + "\"];\n";
	}
	dummy_cpp += "\t\treturn true;\n\t}\n}\n\n";

//======================= replace ============================//
	dummy_cpp = dummy_cpp.replace("<C>", bi.class_name);
	dummy_cpp = dummy_cpp.replace("<T>", "K" + bi.class_name + " *");
	dummy_cpp = dummy_cpp.replace("<CLASS>", bi.class_name);
                 
	return dummy_cpp;
}

String[] makeEventTable(QtInterface qevent)
{
	String[] e_table = [];
	foreach (EnumInterface enum in qevent.enums) {
		if (enum.name == "Type") {
			foreach (String key in enum.key) {
				e_table <<< key;
			}
			break;
		}
	}
	return e_table;
}

void genEventSource(BindInfo[] bia, QtInterface[] interfaces)
{
	int qevent_index = QIsearchClassIndex(interfaces, "QEvent");
	String[] e_table = makeEventTable(interfaces[qevent_index]);
//    print e_table;
	int event_mtd_num = 0;

	foreach (BindInfo bi in bia) {
		if (bi.checkUnusedClass()) {
			continue;
		}
//		if (!bi.inherits_qobject_flag) {
//			continue;
//		}
		QMethod[] mtds = [];
		QMethod[] sigs = [];
		String class_name = bi.class_name;

		QtInterface interface = interfaces[bi.qtInterfaceIndex];

		foreach (f in interface.protected_functions) {
			if (bi.checkUnusedWord(f)) continue;
			FunctionElement fe = new FunctionElement(f, class_name);
			fe.renamePublicTypes(bi.all_enums, bi.all_typedefed_objects);
			if (bi.constructor == null && fe.constructorFlag) bi.constructor = fe;
			if (bi.checkUnusedMethod(fe) ||
				fe.constructorFlag ||
				!("Event" in? fe.func_name && fe.virtualFlag)) continue;
//				(fe.virtualFlag && fe.return_value_type != "void")) continue;
//			if (fe.virtualFlag && fe.return_value_type != "void") print  "v & v " + fe.func_name;
			QMethod mtd = new QMethod(fe);
			mtds << mtd;
		}
		removeOverloadQMethod(mtds);
		foreach (f in interface.signals) {
			if (bi.checkUnusedWord(f)) continue;
			FunctionElement fe = new FunctionElement(f, class_name);
			fe.renamePublicTypes(bi.all_enums, bi.all_typedefed_objects);
			if (bi.checkUnusedMethod(fe) ||
				fe.constructorFlag) continue;
//				!("Event" in? fe.func_name && fe.virtualFlag)) continue;
//				(fe.virtualFlag && fe.return_value_type != "void")) continue;
//			if (fe.virtualFlag && fe.return_value_type != "void") print  "v & v " + fe.func_name;
			QMethod mtd = new QMethod(fe);
			sigs << mtd;
		}
		removeOverloadQMethod(sigs);

		// if (OUTPUT_EVENT_BIND) {
		// 	if (!(|mtds| == 0 && |sigs| == 0)) {
		// 		bi.make_rapper_class_flag = true;
		// 	} else {
		// 		print "not make rapper class of " + class_name;
		// 	}
		// }

		event_mtd_num += (|mtds| + |sigs|);

		// bi.dummy_hpp = genDummyHeaderSource(bi, mtds, sigs, bia);
		// bi.dummy_cpp = genDummyCppSource(bi, mtds, sigs, bia, e_table);
		// bi.header = genHeaderSource(class_name, mtds, sigs, bi);
		// bi.event_bind = genCppSource(class_name, mtds, sigs, bi);
		bi.dummy_hpp = genDummyHeaderSource(bi, mtds, [], bia);
		bi.dummy_cpp = genDummyCppSource(bi, mtds, [], bia, e_table);
		bi.header = genHeaderSource(class_name, mtds, [], bi);
		bi.event_bind = genCppSource(class_name, mtds, [], bi);

	}
}




// void genEventSource(String class_name, String[] protected_functions, String[] signals)
// {
// 	QMethod[] mtds = [];
// 	QMethod[] sigs = [];
// //	print protected_functions;
// 	foreach (f in protected_functions) {
// 		FunctionElement fe = new FunctionElement(f, class_name);
// 		QMethod mtd = new QMethod(fe.func_name, fe.return_value_type, fe.argument_type, fe.argument_name);
// 		//mtd.debugPrint();
// 		mtds << mtd;
// 	}
// //	print signals;
// 	foreach (f in signals) {
// 		FunctionElement fe = new FunctionElement(f, class_name);
// 		QMethod mtd = new QMethod(fe.func_name, fe.return_value_type, fe.argument_type, fe.argument_name);
// 		//mtd.debugPrint();
// 		sigs << mtd;
// 	}
// 	//print |mtds|;
// 	//print |sigs|;
// 	String header = genHeaderSource(class_name, mtds, sigs);
// 	String src = genCppSource(class_name, mtds, sigs);
//     //========== Please write to File!! ==============//
//     hous = new OutputStream(class_name + ".hpp");
// 	sous = new OutputStream(class_name + ".cpp");
// 	hous << header << EOL;
//     tmp = "#include <" + class_name + ".hpp>\n\n";
//     tmp += """#ifdef __cplusplus
// extern \"C\" {
// #endif
// """;
//     sous << tmp << EOL;
//     sous << src << EOL;
//     sous << """
// DEFAPI(const knh_PackageDef_t*) init(CTX ctx, const knh_LoaderAPI_t *kapi)
// {
// 	(void)ctx; (void)kapi;
// 	RETURN_PKGINFO("konoha.tmp");
// }

// #ifdef __cplusplus
// }
// #endif
// """;
//     hous.close();
//     sous.close();
//     //================================================//
//}

// void main(String[] args)
// {
// 	String class_name = "QGraphicsScene";
// 	String[] signals = [
// 		" void changed ( const QList<QRectF> & region )",
// 		" void sceneRectChanged ( const QRectF & rect )",
// 		" void selectionChanged ()"
// 		];
// 	String[] protected_functions = [
// 		" virtual void contextMenuEvent ( QGraphicsSceneContextMenuEvent * contextMenuEvent )",
// 		" virtual void dragEnterEvent ( QGraphicsSceneDragDropEvent * event )",
// 		" virtual void dragLeaveEvent ( QGraphicsSceneDragDropEvent * event )",
// 		" virtual void dragMoveEvent ( QGraphicsSceneDragDropEvent * event )",
// 		" virtual void drawBackground ( QPainter * painter, const QRectF & rect )",
// 		" virtual void drawForeground ( QPainter * painter, const QRectF & rect )",
// 		" virtual void dropEvent ( QGraphicsSceneDragDropEvent * event )",
// 		" virtual void focusInEvent ( QFocusEvent * focusEvent )",
// 		" virtual void focusOutEvent ( QFocusEvent * focusEvent )",
// 		" virtual void helpEvent ( QGraphicsSceneHelpEvent * helpEvent )",
// 		" virtual void inputMethodEvent ( QInputMethodEvent * event )",
// 		" virtual void keyPressEvent ( QKeyEvent * keyEvent )",
// 		" virtual void keyReleaseEvent ( QKeyEvent * keyEvent )",
// 		" virtual void mouseDoubleClickEvent ( QGraphicsSceneMouseEvent * mouseEvent )",
// 		" virtual void mouseMoveEvent ( QGraphicsSceneMouseEvent * mouseEvent )",
// 		" virtual void mousePressEvent ( QGraphicsSceneMouseEvent * mouseEvent )",
// 		" virtual void mouseReleaseEvent ( QGraphicsSceneMouseEvent * mouseEvent )",
// 		" virtual void wheelEvent ( QGraphicsSceneWheelEvent * wheelEvent )"
// 		];
// 	genEventSource(class_name, protected_functions, signals);
// }
