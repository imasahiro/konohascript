String genFlagObjectCpp(String parent_class, Tuple<String, String>[] flag_objects)
{
	String ret = "";
	foreach (Tuple<String, String> flag_object in flag_objects) {
		if (flag_object[0] != parent_class) continue;
		String cpp_src = """
//## <P><C> <P><C>.new(int value);
KMETHOD <P><C>_new(CTX ctx, ksfp_t *sfp _RIX) {
	(void)ctx;
	<P>::<E> i = Int_to(<P>::<E>, sfp[1]);
	<P>::<C> *ret_v = new <P>::<C>(i);
	kRawPtr *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	RETURN_(rptr);
}

//## <P><C> <P><C>.and(int mask);
KMETHOD <P><C>_and(CTX ctx, ksfp_t *sfp _RIX) {
	(void)ctx;
	<P>::<C> *qp = RawPtr_to(<P>::<C>*, sfp[0]);
	if (qp != NULL) {
		int i = Int_to(int, sfp[1]);
		<P>::<C> ret = ((*qp) & i);
		<P>::<C> *ret_ = new <P>::<C>(ret);
		kRawPtr *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## <P><C> <P><C>.iand(<P>::<P><C> other);
KMETHOD <P><C>_iand(CTX ctx, ksfp_t *sfp _RIX) {
	(void)ctx;
	<P>::<C> *qp = RawPtr_to(<P>::<C>*, sfp[0]);
	if (qp != NULL) {
		<P>::<C> *other = RawPtr_to(<P>::<C> *, sfp[1]);
		*qp = ((*qp) & (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## <P><C> <P><C>.or(<P><C> f);
KMETHOD <P><C>_or(CTX ctx, ksfp_t *sfp _RIX)
{
	(void)ctx;
	<P>::<C> *qp = RawPtr_to(<P>::<C>*, sfp[0]);
	if (qp != NULL) {
		<P>::<C> *f = RawPtr_to(<P>::<C>*, sfp[1]);
		<P>::<C> ret = ((*qp) | (*f));
		<P>::<C> *ret_ = new <P>::<C>(ret);
		kRawPtr *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## <P><C> <P><C>.ior(<P>::<P><C> other);
KMETHOD <P><C>_ior(CTX ctx, ksfp_t *sfp _RIX) {
	(void)ctx;
	<P>::<C> *qp = RawPtr_to(<P>::<C>*, sfp[0]);
	if (qp != NULL) {
		<P>::<C> *other = RawPtr_to(<P>::<C> *, sfp[1]);
		*qp = ((*qp) | (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## <P><C> <P><C>.xor(<P><C> f);
KMETHOD <P><C>_xor(CTX ctx, ksfp_t *sfp _RIX)
{
	(void)ctx;
	<P>::<C> *qp = RawPtr_to(<P>::<C>*, sfp[0]);
	if (qp != NULL) {
		<P>::<C> *f = RawPtr_to(<P>::<C>*, sfp[1]);
		<P>::<C> ret = ((*qp) ^ (*f));
		<P>::<C> *ret_ = new <P>::<C>(ret);
		kRawPtr *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## <P><C> <P><C>.ixor(<P>::<P><C> other);
KMETHOD <P><C>_ixor(CTX ctx, ksfp_t *sfp _RIX) {
	(void)ctx;
	<P>::<C> *qp = RawPtr_to(<P>::<C>*, sfp[0]);
	if (qp != NULL) {
		<P>::<C> *other = RawPtr_to(<P>::<C> *, sfp[1]);
		*qp = ((*qp) ^ (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## boolean <P><C>.testFlag(int flag);
KMETHOD <P><C>_testFlag(CTX ctx, ksfp_t *sfp _RIX) {
	(void)ctx;
	<P>::<C> *qp = RawPtr_to(<P>::<C> *, sfp[0]);
	if (qp != NULL) {
		<P>::<E> flag = Int_to(<P>::<E>, sfp[1]);
		bool ret = qp->testFlag(flag);
		RETURNb_(ret);
	} else {
		RETURNb_(false);
	}
}

//## int <P><C>.value();
KMETHOD <P><C>_value(CTX ctx, ksfp_t *sfp _RIX) {
	(void)ctx;
	<P>::<C> *qp = RawPtr_to(<P>::<C> *, sfp[0]);
	if (qp != NULL) {
		int ret = int(*qp);
		RETURNi_(ret);
	} else {
		RETURNi_(0);
	}
}

static void <P><C>_free(CTX ctx, kRawPtr *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		<P>::<C> *qp = (<P>::<C> *)p->rawptr;
		(void)qp;
		delete qp;
		p->rawptr = NULL;
	}
}

static void <P><C>_reftrace(CTX ctx, kRawPtr *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		<P>::<C> *qp = (<P>::<C> *)p->rawptr;
		(void)qp;
	}
}

static int <P><C>_compareTo(kRawPtr *p1, kRawPtr *p2)
{
	if (p1->rawptr == NULL || p2->rawptr == NULL) {
		return 1;
	} else {
//		int v1 = int(*(<P>::<C>*)p1->rawptr);
//		int v2 = int(*(<P>::<C>*)p2->rawptr);
//		return (v1 == v2 ? 0 : 1);
		<P>::<C> v1 = *(<P>::<C>*)p1->rawptr;
		<P>::<C> v2 = *(<P>::<C>*)p2->rawptr;
//		return (v1 == v2 ? 0 : 1);
<COMP>
	}
}

DEFAPI(void) def<P><C>(CTX ctx, kclass_t cid, kclassdef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "<P><C>";
	cdef->free = <P><C>_free;
	cdef->reftrace = <P><C>_reftrace;
	cdef->compareTo = <P><C>_compareTo;
}
""";
		String enum_name = "";
		if (flag_object[1] == "WindowFlags") {
			enum_name = "WindowType";
		} else if (flag_object[1] == "Capabilities") {
			enum_name = "Capability";
		} else if (flag_object[1] == "BindMode") {
			enum_name = "BindFlag";
		} else if (flag_object[1] == "ShaderType") {
			enum_name = "ShaderTypeBit";
		} else if (flag_object[1].endsWith("s")) {
			enum_name = flag_object[1][0 : -1];
		} else {
			enum_name = flag_object[1] + "Flag";
		}

		cpp_src = cpp_src.replace("<E>", enum_name);
		cpp_src = cpp_src.replace("<P>", parent_class);
		cpp_src = cpp_src.replace("<C>", flag_object[1]);
		String comp = "";
		if (parent_class == "Qt" &&
			flag_object[1] == "WindowFlags") {
			comp = "\t\treturn ((v1 & Qt::WindowType_Mask) == (v2 & Qt::WindowType_Mask) ? 0 : 1);\n";
		} else {
			comp = "\t\treturn (v1 == v2 ? 0 : 1);\n";
		}
		cpp_src = cpp_src.replace("<COMP>", comp);
		ret += cpp_src;
	}
	return ret;
}

String genFlagObjectKClass(String parent_class, Tuple<String, String>[] flag_objects)
{
	String ret = "";
	foreach (Tuple<String, String> flag_object in flag_objects) {
        if (flag_object[0] != parent_class) continue;
		ret += "@Native class " + parent_class + flag_object[1] + ";\n";
	}
	// if (parent_class == "QWidget") {
	// 	print flag_objects;
	// 	print ret;
	// }
	return ret;
}

String genFlagObjectKMtd(String parent_class, Tuple<String, String>[] flag_objects)
{
	String ret = "";
	foreach (Tuple<String, String> flag_object in flag_objects) {
		if (flag_object[0] != parent_class) continue;
		String k_mtd_src = """

<P><C> <P><C>.new(int value);
<P><C> <P><C>.and(int mask);
<P><C> <P><C>.iand(<P><C> other);
<P><C> <P><C>.or(<P><C> f);
<P><C> <P><C>.ior(<P><C> other);
<P><C> <P><C>.xor(<P><C> f);
<P><C> <P><C>.ixor(<P><C> other);
boolean <P><C>.testFlag(int flag);
int <P><C>.value();
""";

		k_mtd_src = k_mtd_src.replace("<P>", parent_class);
		k_mtd_src = k_mtd_src.replace("<C>", flag_object[1]);
		ret += k_mtd_src;
	}
	return ret;
}

String genGlobalFlagObjectCpp()
{
	String ret = "";
//	foreach (Tuple<String, String> flag_object in GLOBAL_FLAG_LIST) {
	ret += genFlagObjectCpp("Qt", GLOBAL_FLAG_LIST);
//	}
	return ret;
}

String genGlobalFlagObjectKClass()
{
	String ret = "";
	ret += genFlagObjectKClass("Qt", GLOBAL_FLAG_LIST);
	return ret;
}

String genGlobalFlagObjectKMtd()
{
	String ret = "";
	ret += genFlagObjectKMtd("Qt", GLOBAL_FLAG_LIST);
	return ret;
}

void outputGlobalFlags()
{
	ous = new OutputStream("QtGlobalFlags.cpp");
	ous.println(genGlobalFlagObjectCpp());
	ous.flush();
	ous.close();
}

