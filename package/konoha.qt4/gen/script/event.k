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
		foreach (boolean b in fe.argument_type_object_flags) {
			argument_type_object_flag <<< b;
		}
		argtypes = [];
		foreach (String argument_type in fe.argument_types) {
			argument_type = argument_type.replace("Array<", "QList<");
			argtypes <<< argument_type;
		}
		values = [];
		foreach (String argument_name in fe.argument_names) {
			values <<< argument_name;
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
		fixed_src += mtd_name + "Dummy(";
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
//		slot_src += return_type + " ";
		slot_src += "bool" + " ";
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
//=========================Generate KQClass =======================//
	String kqclass = "";
	if (bi.have_private_destructor_flag) {
		kqclass += """
class K<C> {
<UNUSE> Q_OBJECT;
public:
	<C> *q_self;
	knh_RawPtr_t *self;
	Dummy<C> *dummy;
<CR>
"""
	} else {
		kqclass += """
class K<C> : public <C> {
<UNUSE>	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	Dummy<C> *dummy;
<CR>
""";
	}
	
	kqclass += "\tvoid setSelf(knh_RawPtr_t *ptr);\n";
	if (bi.checkHaveEventMethod()) kqclass += "\tbool event(QEvent *event);\n";
//	if (bi.checkInheritsQObject() && |sigs| != 0) {
//		kqclass = kqclass.replace("<UNUSE>", "");
//	} else {
	kqclass = kqclass.replace("<UNUSE>", "//");
//	}
	kqclass += "};\n";
//========================= Constructor ==========================//
	String constructor = "";
	String args = "";
	if (bi.checkHaveConstructor()) {
		constructor += "\tK<C>(ARGS);";
		FunctionElement f = bi.constructor;
		for (int i = 0; i < f.argument_number; i++) {
			args += f.argument_types[i].replace("Array<", "QList<");
			args += " " + f.argument_names[i];
			if (f.argument_number > i + 1) {
				args += ", ";
			}
		}
	}

//===============================================================//
	String hpp_src = "";
	if (!GEN_CONCATENATE_FILE) header += "#include <<C>>\n";
	hpp_src += kqclass;
	hpp_src = hpp_src.replace("<CR>", constructor);
	hpp_src = hpp_src.replace("<C>", class_name);
	hpp_src = hpp_src.replace("ARGS", args);
	return hpp_src;
}

String genCppSource(String class_name, QMethod[] mtds, QMethod[] sigs, BindInfo bi)
{
//================= Generate Constructor ====================//
	String constructor = "";
	if (bi.checkHaveConstructor()) {
		constructor += """
K<C>::K<C>(ARGS) : <C>(ARGNAMES)
{
	self = NULL;
	dummy = new Dummy<C>();
""";
		if (bi.inherits_qobject_flag) {
			constructor += "\tdummy->connection((QObject*)this);\n";
		}
		constructor += "}\n\n";

		FunctionElement f = bi.constructor;
		String args = "", argnames = "";
		for (int i = 0; i < f.argument_number; i++) {
			args += f.argument_types[i].replace("Array<", "QList<");
			args += " " + f.argument_names[i];
			argnames += f.argument_names[i];
			if (f.argument_number > i + 1) {
				args += ", ";
				argnames += ", ";
			}
		}
		constructor = constructor.replace("ARGS", args);
		constructor = constructor.replace("ARGNAMES", argnames);
	}

//================== Generate addEvent ====================//
	String addEvent = """
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
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, \"WARNING:[<C>]unknown event name [%s]\\n\", event_name);
			return;
		}
	}
	RETURNvoid_();
}
""";
//================== Generate signalConnect ====================//
	String signalConnect = """
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
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, \"WARNING:[<C>]unknown signal name [%s]\\n\", signal_name);
			return;
		}
	}
	RETURNvoid_();
}
""";
//========================Generate for GC================================//
	String gc += "";
    gc +="""

static void <C>_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		K<C> *qp = (K<C> *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
""";

gc += """
static void <C>_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		K<C> *qp = (K<C> *)p->rawptr;
		qp->dummy->reftrace(ctx, p, tail_);
	}
}
""";
// 	gc += """
// static void <C>_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
// {
// <UNUSE>	(void)ctx; (void)p; (void)tail_;
// 	int list_size = <NUM>;
// 	KNH_ENSUREREF(ctx, list_size);

// 	if (p->rawptr != NULL) {
// 		K<C> *qp = (K<C> *)p->rawptr;
// <UNUSE>		(void)qp;
// """;
// 	if (|mtds| == 0 && |sigs| == 0) {
// 		gc = gc.replace("<UNUSE>", "");
// 	} else {
// 		gc = gc.replace("<UNUSE>", "//");
// 	}

// 	int num = |mtds| + |sigs|;
// 	gc = gc.replace("<NUM>", (String)num);

// 	foreach (QMethod mtd in mtds) {
// 		gc += "\t\tif (qp->dummy->" + mtd.mtd_cname + "_func != NULL) {\n";
// 		gc += "\t\t\tKNH_ADDREF(ctx, qp->dummy->" + mtd.mtd_cname + "_func);\n";
// 		gc += "\t\t\tKNH_SIZEREF(ctx);\n";
// 		gc += "\t\t}\n";
// 	}
// 	foreach (QMethod mtd in sigs) {
// 		gc += "\t\tif (qp->dummy->" + mtd.mtd_cname + "_func != NULL) {\n";
// 		gc += "\t\t\tKNH_ADDREF(ctx, qp->dummy->" + mtd.mtd_cname + "_func);\n";
// 		gc	+= "\t\t\tKNH_SIZEREF(ctx);\n";
// 		gc	+= "\t\t}\n";
// 	}
// 	gc += """
// 	}
// }
// """;
//=======================Generate compareTo==============================//

	String compare_to = COMPARE_TO(class_name, bi.have_compare_operator_flag);

//================== Generate setSelf =====================//
	String setSelf = "";
	setSelf += """

void K<C>::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}
""";
//======================= Generate event ==============================//
	String event = "";
	if (bi.checkHaveEventMethod()) {
		event += """

bool K<C>::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		<CALL>event(event);
		return false;
	}
	return true;
}
""";
		if (bi.have_private_destructor_flag) {
			event = event.replace("<CALL>", "q_self->");
		} else {
			event = event.replace("<CALL>", "<C>::");
		}
	}

// //======================= def ==========================================//
// 	String def_class = """

// DEFAPI(void) def<C>(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
// {
// 	(void)ctx; (void) cid;
// 	cdef->name = \"<C>\";
// 	cdef->free = <C>_free;
// 	cdef->reftrace = <C>_reftrace;
// 	cdef->compareTo = <C>_compareTo;
// }
// """;
//=================================================================//
    String cpp_src = "";
	cpp_src += constructor;
	cpp_src += addEvent;
	cpp_src += signalConnect;
	cpp_src += gc;
	cpp_src += compare_to;
	cpp_src += setSelf;
	cpp_src += event;
//	cpp_src += def_class;
	cpp_src = cpp_src.replace("<C>", class_name);
	cpp_src = cpp_src.replace("<T>", "K" + class_name + " *");
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
//=================== Generate dummy class definition =======================//
	String class_definition = "";
	class_definition += """
class Dummy<C><INHERITS> {
<UNUSE>	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
""";
	foreach (QMethod mtd in mtds) {
		class_definition += "\tknh_Func_t *" + mtd.mtd_cname + "_func;\n"
	}
	foreach (QMethod mtd in sigs) {
		class_definition += "\tknh_Func_t *" + mtd.mtd_cname + "_func;\n"
	}
	class_definition += """
	Dummy<C>();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
<CONNECTION><EVENT><SLOTS>};
""";

	if (bi.inherits_qobject_flag && |sigs| != 0) {
		class_definition = class_definition.replace("<UNUSE>", "");
	} else {
		class_definition = class_definition.replace("<UNUSE>", "//");
	}

//====================== connection =============================//
	String connection = "";
//	if (bi.checkInheritsQObject() && |sigs| != 0) {
	connection += "\tvoid connection(QObject *o);\n";
//	}

//============== Generate Public Event Method List ================//
	String event_method = "";
	foreach (QMethod mtd in mtds) {
		event_method += "\t" + mtd.fixed_src + ";\n";
	}

//==================== Generate Public Slots ======================//
	String public_slots = "";
	if (bi.inherits_qobject_flag && |sigs| != 0) {
//	if (bi.checkInheritsQObject()) {
		public_slots += "public slots:\n";
		foreach (QMethod mtd in sigs) {
			public_slots += "\t" + mtd.slot_src + ";\n";
		}
	}

//==============================================================//
	String hpp_src = "";
	hpp_src += class_definition;
	hpp_src = hpp_src.replace("<CONNECTION>", connection);
	hpp_src = hpp_src.replace("<EVENT>", event_method);
	hpp_src = hpp_src.replace("<SLOTS>", public_slots);
	hpp_src = hpp_src.replace("<C>", bi.class_name);

	String inherits = "";
	if (bi.class_name == "QObject") {
		inherits += " : public QObject";
	} else if (|bi.parent_name| != 0) {
		for (int i = 0; i < |bi.parent_name|; i++) {
			int size = |bi.parent_name|;
			foreach (String check in bi.parent_name) {
				if (check == "QObject") size--;
			}
			if (bi.parent_name[i] == "QObject") {
				inherits = "public Dummy" + bi.parent_name[i] + (|bi.parent_name| == 1 ? "" : ", ") + inherits;
			} else {
				inherits += "public Dummy" + bi.parent_name[i];
				if (i < size - 1) inherits += ", ";
			}
		}
		inherits = " : " + inherits;
	}
	hpp_src = hpp_src.replace("<INHERITS>", inherits);

	return hpp_src;
}


String genDummyCppSource(BindInfo bi, QMethod[] mtds, QMethod[] sigs, BindInfo[] bia, String[] e_table)
{
//======================== Generate constructor ==============================//
	String constructor = "";
	constructor += """
Dummy<C>::Dummy<C>()
{
	self = NULL;
""";
	foreach (QMethod mtd in mtds) {
		constructor += "\t" + mtd.mtd_cname + "_func = NULL;\n";
	}
	foreach (QMethod mtd in sigs) {
		constructor += "\t" + mtd.mtd_cname + "_func = NULL;\n";
	}
	constructor += "\tevent_map = new map<string, knh_Func_t *>();\n";
	constructor += "\tslot_map = new map<string, knh_Func_t *>();\n";
	foreach (QMethod mtd in mtds) {
		constructor += "\tevent_map->insert(map<string, knh_Func_t *>::value_type(\"" + mtd.event_type_name + "\", NULL));\n";
	}
	foreach (QMethod mtd in sigs) {
		constructor += "\tslot_map->insert(map<string, knh_Func_t *>::value_type(\"" + mtd.event_type_name + "\", NULL));\n";
	}
	constructor += "}\n"

//====================== setSelf =================================//

	String setSelf = "";
	setSelf += """

void Dummy<C>::setSelf(knh_RawPtr_t *ptr)
{
	Dummy<C>::self = ptr;
""";
	foreach (String pn in bi.parent_name) {
		setSelf += "\tDummy" + pn + "::setSelf(ptr);\n";
	}
	setSelf += "}\n";

//======================== Generate eventDispatcher ================================//
	String eventDispatcher = "";
	eventDispatcher += """

bool Dummy<C>::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {""";
	foreach (QMethod mtd in mtds) {
		if (|mtd.argtypes| != 1) {
			continue;
		}
		String case_ = "";
		case_ += "<EVENT>\n";
		case_ += "\t\tret = " + mtd.mtd_name + "Dummy(dynamic_cast<" + mtd.argtypes[0] + ">(event));\n";
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
		eventDispatcher += case_;
	}

	eventDispatcher +=  "\n\tdefault:\n";
	if (|bi.parent_name| == 0) {
		eventDispatcher += "\t\tret = false;\n";
	} else {
		for (int i = 0; i < |bi.parent_name|; i++) {
			eventDispatcher += "\t\tret = Dummy" + bi.parent_name[i] + "::eventDispatcher(event);\n";
			if (i < |bi.parent_name| - 1) {
				eventDispatcher += "\t\tif (ret) break;\n";
			}
		}
	}
	eventDispatcher += "\t\tbreak;\n";
	eventDispatcher += "\t}\n\treturn ret;\n}\n\n";

//================= Generate Event Methods =================//
    String eventMethods = "";
	int i = 0;
	foreach (QMethod mtd in mtds) {
		eventMethods += "bool Dummy<C>::<M>(";
		for (i = 0; i < |mtd.argtypes|; i++) {
			eventMethods += mtd.argtypes[i] + " " + mtd.values[i];
			if (|mtd.argtypes| > i+1) {
				eventMethods += ", ";
			}
		}
		eventMethods += ")\n";
		eventMethods += "{\n";
		eventMethods += "\tif (<F> != NULL) {\n";
		eventMethods += "\t\tCTX lctx = knh_getCurrentContext();\n";
		eventMethods += "\t\tknh_sfp_t *lsfp = lctx->esp;\n";
		eventMethods += "\t\tKNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));\n";
		for (i = 0; i < |mtd.argtypes|; i++) {
			if ("::" in? mtd.knh_argtypes[i]) {
				print bi.class_name;
				print mtd.mtd_name;
			}
			eventMethods += EventArgPassing(mtd.knh_argtypes[i]);
			eventMethods = eventMethods.replace("<N>", (String)(i + 1));
			eventMethods = eventMethods.replace("<KT>", mtd.knh_argtypes[i]);
			eventMethods = eventMethods.replace("<V>", mtd.values[i]);
			eventMethods = eventMethods.replace("<T>", mtd.knh_argtypes[i] - "QList<" - ">");
			eventMethods = eventMethods.replace("<N>", (String)(i + 1));
			eventMethods = eventMethods.replace("<DELTA>", (String)(i + 2));
		}
		eventMethods += "\t\tknh_Func_invoke(lctx, " + mtd.mtd_cname + "_func, lsfp, <N>);\n";
		eventMethods += "\t\treturn true;\n";
		eventMethods = eventMethods.replace("<N>", (String)(i + 1));
		eventMethods += "\t}\n";
		eventMethods += "\treturn false;\n";
		eventMethods += "}\n";
		eventMethods += "\n";
		eventMethods = eventMethods.replace("<R>", mtd.return_type);
		eventMethods = eventMethods.replace("<C>", bi.class_name);
		eventMethods = eventMethods.replace("<M>", mtd.mtd_name + "Dummy");
		eventMethods = eventMethods.replace("<F>", mtd.mtd_cname + "_func");
	}
//================ Generate Slot Methods ===================//
    String slotMethods = "";
	i = 0;
	foreach (QMethod mtd in sigs) {
		slotMethods += "bool Dummy<C>::<M>(";
		for (i = 0; i < |mtd.argtypes|; i++) {
			slotMethods += mtd.argtypes[i] + " " + mtd.values[i];
			if (|mtd.argtypes| > i+1) {
				slotMethods += ", ";
			}
		}
		slotMethods += ")\n";
		slotMethods += "{\n";
		slotMethods += "\tif (<F> != NULL) {\n";
		slotMethods	+= "\t\tCTX lctx = knh_getCurrentContext();\n";
		slotMethods += "\t\tknh_sfp_t *lsfp = lctx->esp;\n";
		slotMethods += "\t\tKNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));\n";
		for (i = 0; i < |mtd.argtypes|; i++) {
			// if ("::" in? mtd.knh_argtypes[i]) {
			// 	print bi.class_name;
			// 	print mtd.mtd_name;
			// }
			slotMethods += EventArgPassing(mtd.knh_argtypes[i]);
			slotMethods = slotMethods.replace("<N>", (String)(i + 1));
			slotMethods = slotMethods.replace("<KT>", mtd.knh_argtypes[i]);
			slotMethods = slotMethods.replace("<V>", mtd.values[i]);
			slotMethods = slotMethods.replace("<T>", mtd.knh_argtypes[i] - "QList<" - ">");
			slotMethods = slotMethods.replace("<N>", (String)(i + 1));
			slotMethods = slotMethods.replace("<DELTA>", (String)(i + 2));
		}
		slotMethods += "\t\tknh_Func_invoke(lctx, " + mtd.mtd_cname + "_func, lsfp, <N>);\n";
		slotMethods += "\t\treturn true;\n";
		slotMethods = slotMethods.replace("<N>", (String)(i + 1));
		slotMethods += "\t}\n";
		slotMethods += "\treturn false;\n";
		slotMethods += "}\n";
		slotMethods += "\n";
		slotMethods = slotMethods.replace("<R>", mtd.return_type);
		slotMethods = slotMethods.replace("<C>", bi.class_name);
		slotMethods = slotMethods.replace("<M>", mtd.mtd_name + "Slot");
		slotMethods = slotMethods.replace("<F>", mtd.mtd_cname + "_func");
	}
//===================== Generate dummy::addEvent =========================//
	String addEvent = "";
	addEvent += """
bool Dummy<C>::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = Dummy<C>::event_map->bigin();
	if ((itr = Dummy<C>::event_map->find(str)) == Dummy<C>::event_map->end()) {
		bool ret = false;
""";
	for (int i = 0; i < |bi.parent_name|; i++) {
		addEvent += "\t\tret = Dummy" + bi.parent_name[i] + "::addEvent(callback_func, str);\n";
		if (i < |bi.parent_name| - 1) {
			addEvent += "\t\tif (ret) return true;\n";
		}
	}
	addEvent += """
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
""";
	foreach (QMethod mtd in mtds) {
		addEvent += "\t\t" + mtd.mtd_cname + "_func = (*event_map)[\"" + mtd.event_type_name + "\"];\n";
	}
	addEvent += "\t\treturn true;\n\t}\n}\n\n";
//=================== dummy::signalConnect  ==================//
	String signalConnect = "";
	signalConnect += """
bool Dummy<C>::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = Dummy<C>::slot_map->bigin();
	if ((itr = Dummy<C>::slot_map->find(str)) == Dummy<C>::slot_map->end()) {
		bool ret = false;
""";
	for (int i = 0; i < |bi.parent_name|; i++) {
		signalConnect += "\t\tret = Dummy" + bi.parent_name[i] + "::signalConnect(callback_func, str);\n";
		if (i < |bi.parent_name| - 1) {
			signalConnect += "\t\tif (ret) return true;\n";
		}
	}
	signalConnect += """
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
""";
	foreach (QMethod mtd in sigs) {
		signalConnect += "\t\t" + mtd.mtd_cname + "_func = (*slot_map)[\"" + mtd.event_type_name + "\"];\n";
	}
	signalConnect += "\t\treturn true;\n\t}\n}\n\n";

//================== dummy::reftrace ====================//

	String reftrace = "";
	reftrace += """
void Dummy<C>::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
<UNUSE>	(void)ctx; (void)p; (void)tail_;
	int list_size = <NUM>;
	KNH_ENSUREREF(ctx, list_size);

""";
	if (|mtds| == 0 && |sigs| == 0) {
		reftrace = reftrace.replace("<UNUSE>", "");
	} else {
		reftrace = reftrace.replace("<UNUSE>", "//");
	}

	int num = |mtds| + |sigs|;
	reftrace = reftrace.replace("<NUM>", (String)num);

	foreach (QMethod mtd in mtds) {
		reftrace += "\tKNH_ADDNNREF(ctx, " + mtd.mtd_cname + "_func);\n";
	}
	foreach (QMethod mtd in sigs) {
		reftrace += "\tKNH_ADDNNREF(ctx, " + mtd.mtd_cname + "_func);\n";
	}
	reftrace += "\n\tKNH_SIZEREF(ctx);\n\n";
//	reftrace += "\t}\n";
	foreach (String pn in bi.parent_name) {
		reftrace += "\tDummy" + pn + "::reftrace(ctx, p, tail_);\n";
	}
	reftrace += "}\n";

//================== connection =========================//

	String connection = "";
	connection = """

void Dummy<C>::connection(QObject *o)
{
	<C> *p = dynamic_cast<<C>*>(o);
""";
	connection += "\tif (p != NULL) {\n";
	foreach (QMethod sig in sigs) {
		String line = "";
		line += "\t\tconnect(p, SIGNAL(" + sig.mtd_name + "(<ARGTYPES>)), this, SLOT(" + sig.mtd_name + "Slot(<ARGTYPES>)));\n";
		String argtypes = "";
		for (int i = 0; i < |sig.argtypes|; i++) {
			argtypes += sig.argtypes[i];
			if (i < |sig.argtypes| - 1) argtypes += ", ";
		}
		line = line.replace("<ARGTYPES>", argtypes);
		connection += line;
	}
	connection += "\t}\n";
	if (|bi.parent_name| != 0) {
		for (int i = 0; i < |bi.parent_name|; i++) {
			connection += "\tDummy" + bi.parent_name[i] + "::connection(o);\n";
		}
	}
	connection += "}\n";

//=======================================================//
	String dummy_cpp = "";
	dummy_cpp += constructor;
	dummy_cpp += setSelf;
	dummy_cpp += eventDispatcher;
	dummy_cpp += eventMethods;
	dummy_cpp += slotMethods;
	dummy_cpp += addEvent;
	dummy_cpp += signalConnect;
	dummy_cpp += reftrace;
	dummy_cpp += connection;

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

int genEventSource(BindInfo[] bia, QtInterface[] interfaces)
{
	OUT << "genEventSource" << EOL;

	int qevent_index = QIsearchClassIndex(interfaces, "QEvent");
	String[] e_table = makeEventTable(interfaces[qevent_index]);
	int event_mtd_num = 0;

	foreach (BindInfo bi in bia) {
		if (bi.checkUnusedClass()) {
			continue;
		}
		QMethod[] mtds = [];
		QMethod[] sigs = [];
		String class_name = bi.class_name;

		QtInterface interface = interfaces[bi.qtInterfaceIndex];

		foreach (f in interface.protected_functions) {
			if (bi.checkUnusedWord(f)) continue;
			FunctionElement fe = new FunctionElement(f, class_name);
			fe.renamePublicTypes(bi.all_enums, bi.all_typedefed_objects, bi.all_flag_objects, bi.all_class_objects);
//			if (bi.constructor == null && fe.constructorFlag) bi.constructor = fe;
			if (bi.checkUnusedMethod(fe) ||
				fe.constructorFlag ||
				!("Event" in? fe.func_name && fe.virtualFlag)) continue;
			QMethod mtd = new QMethod(fe);
			mtds << mtd;
		}
		removeOverloadQMethod(mtds);
		foreach (f in interface.signals) {
			if (bi.checkUnusedWord(f)) continue;
			FunctionElement fe = new FunctionElement(f, class_name);
			fe.renamePublicTypes(bi.all_enums, bi.all_typedefed_objects, bi.all_flag_objects, bi.all_class_objects);
			if (bi.checkUnusedMethod(fe) ||
				fe.constructorFlag) continue;
			QMethod mtd = new QMethod(fe);
			sigs << mtd;
		}
		removeOverloadQMethod(sigs);

		event_mtd_num += (|mtds| + |sigs|);

		bi.dummy_hpp = genDummyHeaderSource(bi, mtds, sigs, bia);
		bi.dummy_cpp = genDummyCppSource(bi, mtds, sigs, bia, e_table);
		bi.header = genHeaderSource(class_name, mtds, sigs, bi);
		bi.event_bind = genCppSource(class_name, mtds, sigs, bi);
	}
	return event_mtd_num;
}
