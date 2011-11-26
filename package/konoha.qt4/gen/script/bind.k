String ClassDef(String class_name)
{
	String ret = """

DEFAPI(void) def<C>(CTX ctx, kclass_t cid, kclassdef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = \"<C>\";
	cdef->free = <C>_free;
	cdef->reftrace = <C>_reftrace;
	cdef->compareTo = <C>_compareTo;
}
""";

	ret = ret.replace("<C>", class_name);
	return ret;
}

String CppPreface(String class_name)
{
	String ret = """
#include <KCLASS.hpp>

using namespace std;

#ifdef __cplusplus
extern "C" {
#endif

""";
	ret = ret.replace("CLASS", class_name);
	return ret;
}

String ConcatenateCppPreface(String class_name)
{
	String ret = """
#include <HEADER>

using namespace std;

#ifdef __cplusplus
extern "C" {
#endif

extern bool exec_flag;

""";
	ret = ret.replace("HEADER", CONCATENATE_HPP_FILE);
	return ret;
}

String CommonHpp()
{
	String ret = """
#ifndef QT_COMMON_HPP
#define QT_COMMON_HPP
#include <QtCore>
#include <QtGui>
#include <QtWebKit>
#include <QtOpenGL/QtOpenGL>
#define K_INTERNAL
#include <konoha1.h>
#include <konoha1/inlinelibs.h>
#define getClassTBL(CLASS) lctx->share->ClassTBL[knh_getcid(lctx, STEXT(#CLASS))]
#define new_RawPtrFromClass(CLASS, o) new_RawPtr(lctx, getClassTBL(CLASS), o)
#include <map>
#define new_QRawPtr(lctx, T, v) new_QRawPtr_(lctx, getClassTBL(T), v)
#define new_empty_QRawPtr(lctx, T) new_QRawPtr_(lctx, getClassTBL(T), (void*)NULL)
//#define QRawPtrNull_to(T, a) ((((a.p)->rawptr) != NULL) ? (*RawPtr_to(T, a)) : 0)

#define initFlag(NAME, T, a) T NAME;QRawPtrNull_to(NAME, T, a);
#define QRawPtrNull_to(NAME, T, a) if (((a.p)->rawptr) != NULL) { \\
(NAME) = *RawPtr_to(T*, a);								          \\
} else {														  \\
(NAME) = 0;														  \\
}

#define G_MAGIC_NUM 39543

// template<class T>
// inline kRawPtr *new_QRawPtr(CTX lctx, T *v)
// {
// 	return new_RawPtrFromClass(T, v);
// }

// template<class T>
// inline kRawPtr *new_QRawPtr(CTX lctx, const T *v)
// {
// 	return new_RawPtrFromClass(T, (void *)v);
// }

// template<class T>
// inline kRawPtr *new_QRawPtr(CTX lctx, T &v)
// {
// 	T *v_ = new T(v);
// 	return new_RawPtrFromClass(T, v_);
// }

// template<class T>
// inline kRawPtr *new_QRawPtr(CTX lctx, const T &v)
// {
// 	T *v_ = new T(v);
// 	return new_RawPtrFromClass(T, v_);
// }

template<class T>
inline kRawPtr *new_QRawPtr_(CTX lctx, const knh_ClassTBL_t *ct, T *v)
{
	return new_RawPtr(lctx, ct, v);
//return new_RawPtrFromClass(T, v);
}

template<class T>
inline kRawPtr *new_QRawPtr_(CTX lctx, const knh_ClassTBL_t *ct, const T *v)
{
//return new_RawPtrFromClass(T, (void *)v);
	return new_RawPtr(lctx, ct, (void *)v);
}

template<class T>
inline kRawPtr *new_QRawPtr_(CTX lctx, const knh_ClassTBL_t *ct, T &v)
{
	T *v_ = new T(v);
	return new_RawPtr(lctx, ct, v_);
//return new_RawPtrFromClass(T, v_);
}

template<class T>
inline kRawPtr *new_QRawPtr_(CTX lctx, const knh_ClassTBL_t *ct, const T &v)
{
	T *v_ = new T(v);
//return new_RawPtrFromClass(T, v_);
	return new_RawPtr(lctx, ct, v_);
}

#endif //QT_COMMON_HPP
""";
	return ret;
}

String KPreface()
{
	String ret = """
include "lib:gluelink";
//include "hierarchy.k";

""";
	return ret;
}


String InitFunc()
{
	String ret = """
#define K_INTERNAL
#include <konoha1.h>
#include <konoha1/inlinelibs.h>

// #ifdef __cplusplus
// extern "C" {
// #endif

// //Array<String> System.parents(Object c);
// KMETHOD System_parents(CTX ctx, ksfp_t *sfp _RIX)
// {
// 	(void)ctx;
// 	const knh_ClassTBL_t *ct = O_cTBL(sfp[1].o);
// 	if(IS_Class(sfp[1].o)) {
// 		ct = ClassTBL(((kClass*)sfp[1].o)->cid);
// 		kArray *a = new_Array0(ctx, 10);
// 		while(ct->supcid != CLASS_Object) {
// 			ct = ct->supTBL;
// 			knh_Array_add(ctx, a, (kObject *)ct->lname);
// 		}
// 		RETURN_(a);
// 	} else {
// 		RETURN_(KNH_NULL);
// 	}
// }

//Array<String> System.getClassParents(String class_name);
KMETHOD System_getClassParents(CTX ctx, ksfp_t *sfp _RIX)
{
	(void)ctx;
	kString *class_name = sfp[1].s;
	kbytes_t lname = class_name->str;
	const knh_ClassTBL_t *ct = (const knh_ClassTBL_t *)knh_DictSet_get(ctx, ctx->share->classNameDictSet, lname);
	if(ct != 0) {
		kArray *a = new_Array0(ctx, 10);
		while(ct->supcid != CLASS_Object) {
			ct = ct->supTBL;
			knh_Array_add(ctx, a, (kObject *)ct->lname);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}

bool exec_flag = false;

DEFAPI(const knh_PackageDef_t*) init(CTX, const knh_LoaderAPI_t *)
{
	RETURN_PKGINFO("Qt-4.7");
}

// #ifdef __cplusplus
// }
// #endif
"""
	return ret;
}

String EnumKeyPair(String key, String class_name)
{
	String ret = '\t{"KEY", CLASS::KEY}';
	ret = ret.replace("KEY", key);
	ret = ret.replace("CLASS", class_name);
	return ret;
}

String EnumLoad(String class_name)
{
	String ret = """
DEFAPI(void) constCLASS(CTX ctx, kclass_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, CLASSConstInt);
}
"""
	ret = ret.replace("CLASS", class_name);
	return ret;
}

String Int_to(String name, String type, int sfp_num)
{
	String ret = "TYPE NAME = Int_to(TYPE, sfp[SFP_NUM]);\n";
	ret = ret.replace("TYPE", type);
	ret = ret.replace("NAME", name);
	ret = ret.replace("SFP_NUM", (String)sfp_num);
	return ret;
}

String Float_to(String name, String type, int sfp_num)
{
	String ret = "TYPE NAME = Float_to(TYPE, sfp[SFP_NUM]);\n";
	ret = ret.replace("TYPE", type);
	ret = ret.replace("NAME", name);
	ret = ret.replace("SFP_NUM", (String)sfp_num);
	return ret;
}

String Boolean_to(String name, String type, int sfp_num)
{
	String ret = "TYPE NAME = Boolean_to(TYPE, sfp[SFP_NUM]);\n";
	ret = ret.replace("TYPE", type);
	ret = ret.replace("NAME", name);
	ret = ret.replace("SFP_NUM", (String)sfp_num);
	return ret;
}

String String_to(String name, String type, int sfp_num)
{
	String ret = "TYPE NAME = String_to(TYPE, sfp[SFP_NUM]);\n";
	ret = ret.replace("TYPE", type);
	ret = ret.replace("NAME", name);
	ret = ret.replace("SFP_NUM", (String)sfp_num);
	return ret;
}

String RawPtr_to(String name, String type, int sfp_num, boolean object_flag = false)
{
	String ret = "";
	if (object_flag) {
//		ret = "TYPE NAME;\n\t\tQRawPtrNull_to(NAME, TYPE, sfp[SFP_NUM]);\n";
//		ret = ret.replace("CAST", type + "*");
		ret = "initFlag(NAME, TYPE, sfp[SFP_NUM]);\n";
		ret = ret.replace("TYPE", type);
		ret = ret.replace("NAME", name);
		ret = ret.replace("SFP_NUM", (String)sfp_num);
	} else {
		ret = "TYPE  NAME = RawPtr_to(CAST, sfp[SFP_NUM]);\n";
		if ("*" in? type && !("*>" in? type)) {
			ret = ret.replace("CAST", type);
			ret = ret.replace("TYPE", type);
		} else {
			ret = ret.replace("CAST", type + " *");
			ret = ret.replace("RawPtr", "*RawPtr");
			ret = ret.replace("TYPE", type);
		}
		ret = ret.replace("NAME", name);
		ret = ret.replace("SFP_NUM", (String)sfp_num);
	}
	return ret;
}

String Array_to(String name, String type_, int sfp_num)
{
	String ret = """
kArray *a = sfp[SFP_NUM].a;
		int asize = knh_Array_size(a);
		TYPE NAME;
		for (int n = 0; n < asize; n++) {
			kRawPtr *p = (kRawPtr*)(a->list[n]);
			NAME.append(CASTp->rawptr);
		}
""";
	String type = type_.replace("Array", "QList");
	if ("*" in? type) {
		ret = ret.replace("CAST", "(" + type - "const "- "QList<" - ">" + ")");
		ret = ret.replace("TYPE",  type - "const ");//type - "Array<" - ">");
	} else {
		ret = ret.replace("CAST", "*(" + type - "const " - "QList<" - ">" + "*)");
		ret = ret.replace("TYPE", type - "const ");// - "Array<" - ">");
	}
	ret = ret.replace("NAME", name);
	ret = ret.replace("SFP_NUM", (String)sfp_num);
	return ret;
}

String RETURNvoid_()
{
	String ret = """
	}
	RETURNvoid_();
}""";
	return ret;
}

String RETURNi_()
{
	String ret = """
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}""";
	return ret;
}

String RETURNip_()
{
	String ret = """
		RETURNi_(*ret_v);
	} else {
		RETURNi_(0);
	}
}""";
	return ret;
}

String RETURNf_()
{
	String ret = """
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}""";
	return ret;
}

String RETURNfp_()
{
	String ret = """
		RETURNf_(*ret_v);
	} else {
		RETURNf_(0.0f);
	}
}""";
	return ret;
}

String RETURNb_()
{
	String ret = """
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}""";
	return ret;
}

String RETURNs_()
{
	String ret = """
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}""";
	
	return ret;
}

String RETURNrc_()
{
	String ret = """
	kRawPtr *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
""";
	return ret;
}

String RETURNc_()
{
	String ret = """
	kRawPtr *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	RETURN_(rptr);
}
""";
	return ret;
}

String RETURNr_(String type)
{
	String ret = """
		kRawPtr *rptr = new_ReturnCppObject(ctx, sfp, RETVALUE, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}""";
	if ("*" in? type) {
		String exclude_const_type = type - "const ";
		ret = ret.replace("RETVALUE", "(" + exclude_const_type + ")ret_v");
	} else {
		ret = "\t\tTYPE *ret_v_ = new CLASS(ret_v);\n" + ret;
		ret = ret.replace("CLASS", type - "const ");
		ret = ret.replace("TYPE", type - "const ");
		ret = ret.replace("RETVALUE", "ret_v_");
	}
	return ret;
}

String RETURNa_(String type)
{
	String ret = """
		int list_size = ret_v.size();
		kArray *a = new_Array0(ctx, list_size);
		kclass_t cid = knh_getcid(ctx, STEXT(\"TYPE\"));
		for (int n = 0; n < list_size; n++) {ADDED_SRC
			kRawPtr *p = new_RawPtr(ctx, ClassTBL(cid), RETVALUE);
			knh_Array_add(ctx, a, (kObject *)p);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}
	""";
	if ("*" in? type) {
		ret = ret.replace("ADDED_SRC", "");
		ret = ret.replace("TYPE", type - "Array<" - ">" - "*" - "const ");
		ret = ret.replace("RETVALUE", "ret_v[n]");
	} else {
		ret = ret.replace("ADDED_SRC", "\n\t\t\tTYPE *ret_v_ = new CLASS(ret_v[n]);");
		ret = ret.replace("CLASS", type - "Array<" - ">" - "*" - "const ");
		ret = ret.replace("TYPE", type - "Array<" - ">" - "*" - "const ");
		ret = ret.replace("RETVALUE", "ret_v_");
	}
	return ret;
}

String CMAKELISTS(String cppsrc, String hppsrc)
{
	String ret = """
if(USE_QT4)
cmake_minimum_required(VERSION 2.6)

set(CMAKE_C_FLAGS_RELEASE "-Wall -O2 -g")
set(CMAKE_C_FLAGS_DEBUG   "-Wall -O0 -g3")
set(CMAKE_CXX_FLAGS_RELEASE "-Wall -O2 -g")
set(CMAKE_CXX_FLAGS_DEBUG   "-Wall -O0 -g3")
set(CMAKE_BUILD_TYPE DEBUG)

# it must be configured

project(qt4)
set(QT_USE_QTWEBKIT TRUE)
find_package(Qt4 REQUIRED)
find_package(OpenGL)
#find_package(Qt4 COMPONENTS QtCore QtGui QtWebKit REQUIRED)
set(PACKAGE_SOURCE_CODE
CPPSRC
	)
set(PACKAGE_SCRIPT_CODE qt4.k)
set(PACKAGE_EXTRA_LIBRARY
	${QT_QTCORE_LIBRARY}
	${QT_QTWEBKIT_LIBRARY}
	${QT_QTGUI_LIBRARY}
	${QT_QTNETWORK_LIBRARY}
	${QT_QTOPENGL_LIBRARY}
	)

set(PACKAGE_HEADERS
HPPSRC
    )
qt4_wrap_cpp(PACKAGE_HEADERS_MOC ${PACKAGE_HEADERS})

include(${QT_USE_FILE})

set(PACKAGE_NAME    ${PROJECT_NAME})
set(PACKAGE_VERSION ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH})
set(PACKAGE_STRING  ${CMAKE_PROJECT_NAME}-${PACKAGE_VERSION})
set(KONOHA_PACKAGE_DIR konoha/package/${KONOHA_VERSION}/konoha.${PROJECT_NAME})

set(INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}
		${CMAKE_CURRENT_SOURCE_DIR}/include  ${CMAKE_CURRENT_BINARY_DIR}
		${KONOHA_INCLUDE_DIRS} ${PACKAGE_INCLUDE_DIR})
include_directories(${INCLUDE_DIRS})

add_definitions(-D_SETUP)
add_definitions(${QT_DEFINITIONS})

add_library(${PACKAGE_NAME} SHARED ${PACKAGE_SOURCE_CODE} ${PACKAGE_HEADERS_MOC})
set_target_properties(${PACKAGE_NAME} PROPERTIES PREFIX "")
target_link_libraries(${PACKAGE_NAME} konoha)
target_link_libraries(${PACKAGE_NAME} ${PACKAGE_EXTRA_LIBRARY})

install(TARGETS ${PACKAGE_NAME} DESTINATION ${KONOHA_PACKAGE_DIR})
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/${PACKAGE_SCRIPT_CODE} DESTINATION ${KONOHA_PACKAGE_DIR})

endif(USE_QT4)
""";
	ret = ret.replace("CPPSRC", cppsrc);
	ret = ret.replace("HPPSRC", hppsrc);
	return ret;
}

String MEMBERb_info(String label, boolean value)
{
	String ret = """
LABEL
VALUE
""";
	ret = ret.replace("LABEL", label);
	ret = ret.replace("VALUE", (String)value);
	return ret;
}

String MEMBERi_info(String label, int value)
{
	String ret = """
LABEL
VALUE
""";
	ret = ret.replace("LABEL", label);
	ret = ret.replace("VALUE", (String)value);
	return ret;
}

String MEMBERia_info(String label, int[] values)
{
	String ret = label;
	foreach (int value in values) {
		ret += "\n" + value;
	}
	ret += "\n";
	return ret;
}

String MEMBERs_info(String label, String value)
{
	String ret = """
LABEL
VALUE
""";
	ret = ret.replace("LABEL", label);
	ret = ret.replace("VALUE", value);
	return ret;
}

String MEMBERsa_info(String label, String[] values)
{
	String ret = label;
	foreach (String value in values) {
		ret += "\n" + value;
	}
	ret += "\n";
	return ret;
}

String MEMBERtssa_info(String label, Tuple<String, String>[] values)
{
	String ret = label + "\n";
	foreach (Tuple<String, String> value in values) {
		ret += MEMBERs_info("class", value[0]);
		ret += MEMBERs_info("name", value[1]);
	}
	return ret;
}

String MEMBERea_info(String label, EnumInterface[] values)
{
	String ret = label + "\n";
	foreach (EnumInterface value in values) {
		ret += MEMBERs_info("class_name", value.class_name);
		ret += MEMBERs_info("name", value.name);
		ret += MEMBERsa_info("key", value.key);
		ret += MEMBERb_info("public_flag", value.public_flag);
	}
	return ret;
}


String toMEMBERs(InputStream ins)
{
	String ret = "";
	String line = "";
	while ((line = ins.readLine()) != "") {
		ret = line;
	}
	return ret;
}

void setMEMBERsa(String[] member, InputStream ins)
{
//	String ret = "";
	String line = "";
	while ((line = ins.readLine()) != "") {
		member <<< line;
	}
}

int toMEMBERi(InputStream ins)
{
	int ret = 0;
	String line = "";
	while ((line = ins.readLine()) != "") {
//		print line;
		ret = (int)line;
	}
//	print ret;
	return ret;
}

void setMEMBERia(int[] values, InputStream ins)
{
	String line = "";
	while ((line = ins.readLine()) != "") {
		values <<< (int)line;
	}
	return;
}

boolean toMEMBERb(InputStream ins)
{
	boolean ret = false;
	String line = "";
	while ((line = ins.readLine()) != "") {
		if (line == "true") ret = true;
		if (line == "false") ret = false;
	}
	return ret;
}

void setMEMBERea(EnumInterface[] members, InputStream ins)
{
	String line = "";
	while ((line = ins.readLine()) != "") {
		if (line == "class_name") {
			EnumInterface e = new EnumInterface();
			e.class_name = ins.readLine();
			while ((line = ins.readLine()) != "name"){;}
			e.name = ins.readLine();
			while ((line = ins.readLine()) != "key"){;}
			while ((line = ins.readLine()) != "public_flag") {
				e.key <<< line;
			}
			if (ins.readLine() == "true") {
				e.public_flag = true;
			} else {
				e.public_flag = false;
			}
			members <<< e;
		}
	}
}

void setMEMBERtssa(Tuple<String, String>[] members, InputStream ins)
{
	String line = "";
	while ((line = ins.readLine()) != "") {
		if (line == "class") {
//			Tuple<String, String> t = ("", "");
			t0 = ins.readLine();
			while ((line = ins.readLine()) != "name"){;}
			t1 = ins.readLine();
			t = (t0, t1);
			members <<< t;
		}
	}
}


String MEMBERb_info(String label, boolean value)
{
	String ret = """
LABEL
VALUE
""";
	ret = ret.replace("LABEL", label);
	ret = ret.replace("VALUE", (String)value);
	return ret;
}

String MEMBERi_info(String label, int value)
{
	String ret = """
LABEL
VALUE
""";
	ret = ret.replace("LABEL", label);
	ret = ret.replace("VALUE", (String)value);
	return ret;
}

String MEMBERs_info(String label, String value)
{
	String ret = """
LABEL
VALUE
""";
	ret = ret.replace("LABEL", label);
	ret = ret.replace("VALUE", value);
	return ret;
}

String MEMBERsa_info(String label, String[] values)
{
	String ret = label;
	foreach (String value in values) {
		ret += "\n" + value;
	}
	ret += "\n";
	return ret;
}

String MEMBERea_info(String label, EnumInterface[] values)
{
	String ret = label + "\n";
	foreach (EnumInterface value in values) {
		ret += MEMBERs_info("class_name", value.class_name);
		ret += MEMBERs_info("name", value.name);
		ret += MEMBERsa_info("key", value.key);
		ret += MEMBERb_info("public_flag", value.public_flag);
	}
	return ret;
}


String toMEMBERs(InputStream ins)
{
	String ret = "";
	String line = "";
	while ((line = ins.readLine()) != "") {
		ret = line;
	}
	return ret;
}

void setMEMBERsa(String[] member, InputStream ins)
{
//	String ret = "";
	String line = "";
	while ((line = ins.readLine()) != "") {
		member <<< line;
	}
}

int toMEMBERi(InputStream ins)
{
	int ret = 0;
	String line = "";
	while ((line = ins.readLine()) != "") {
//		print line;
		ret = (int)line;
	}
//	print ret;
	return ret;
}

boolean toMEMBERb(InputStream ins)
{
	boolean ret = false;
	String line = "";
	while ((line = ins.readLine()) != "") {
		if (line == "true") ret = true;
		if (line == "false") ret = false;
	}
	return ret;
}

void setMEMBERea(EnumInterface[] members, InputStream ins)
{
	String line = "";
	while ((line = ins.readLine()) != "") {
		if (line == "class_name") {
			EnumInterface e = new EnumInterface();
			e.class_name = ins.readLine();
			while ((line = ins.readLine()) != "name"){;}
			e.name = ins.readLine();
			while ((line = ins.readLine()) != "key"){;}
			while ((line = ins.readLine()) != "public_flag") {
				e.key <<< line;
			}
			if (ins.readLine() == "true") {
				e.public_flag = true;
			} else {
				e.public_flag = false;
			}
			members <<< e;
		}
	}
}

// String EventArg_to(String arg_type)
// {
// 	String ret = "";
// 	if (arg_type.startsWith("Q")) {
// 	}
// 	return ret;
// }

String EventArgPassing(boolean event_flag, String arg_type, String mtd_name)
{
	String ret  = "";
	if ("QList<" in? arg_type) {
		ret += """
		int size = <V>.length();
		kArray *p<N> = new_Array0(lctx, size);
		kclass_t cid = knh_getcid(lctx, STEXT(\"<T>\"));
		for (int i = 0; i < size; i++) {
			<T> *<V>_ = new <T>(<V>[i]);
			kRawPtr *p = new_RawPtr(lctx, lctx->share->ClassTBL[cid], <V>_);
			knh_Array_add(lctx, p<N>, UPCAST(p));
		}
""";
		return ret;
	}

	if (!arg_type.startsWith("Q")) {

	}

	switch (arg_type) {
	case "int":
		ret += "\t\tlsfp[K_CALLDELTA+<DELTA>].ivalue = <V>;\n";
		break;
	case "float":
	case "qreal":
		ret += "\t\tlsfp[K_CALLDELTA+<DELTA>].fvalue = <V>;\n";
	break;
	case "bool":
		ret += "\t\tlsfp[K_CALLDELTA+<DELTA>].bvalue = <V>;\n";
		break;
	case "char":
		ret += "\t\tkString *s<N> = new_String(lctx, <V>);\n";
		ret += "\t\tlsfp[K_CALLDELTA+<DELTA>].s = s<N>;\n";
		break;
	default:
		if (event_flag) {
			ret += "\t\t" + mtd_name + "Ptr->rawptr = <V>;\n";
			ret += "\t\tKNH_SETv(lctx, lsfp[K_CALLDELTA+<DELTA>].o, (UPCAST(" + mtd_name + "Ptr)));\n";
		} else {
			ret += "\t\tkRawPtr *p<N> = new_QRawPtr(lctx, <T>, <V>);\n";
			ret += "\t\tKNH_SETv(lctx, lsfp[K_CALLDELTA+<DELTA>].o, UPCAST(p<N>));\n";
		}
	}
	return ret;
}

String EventReturn_(String return_type, boolean return_value_type_object_flag) //to remove warnning
{
	if ("::" in? return_type) {
		if (return_value_type_object_flag) {
			return "\treturn NULL;\n";
		} else {
			String ret = """
	<TYPE> *ret = new <TYPE>();
	return *ret;
""";
			ret = ret.replace("<TYPE>", return_type);
			return ret;
		}
	}
	switch (return_type) {
	case "int":
		return "\treturn 0;\n";
	case "float":
		return "\treturn 0.0;\n";
	case "bool":
		return "\treturn true;\n";
	case "char":
		return "\treturn NULL;\n";
	case "void":
		return "";
	default:
		if ("*" in? return_type && !return_type.startsWith("QList<")) {
			return "\treturn NULL;\n";
		} else {
			String ret = """
	<TYPE> ret;
	return ret;
""";
			ret = ret.replace("<TYPE>", return_type);
			return ret;
		}
	}
}

String COMPARE_TO(String class_name, boolean have_compare_operator_flag)
{
	String ret = """

static int <CLASS>_compareTo(kRawPtr *p1, kRawPtr *p2)
{
<COMP>
}
""";
	if (have_compare_operator_flag) {
		String comp = "\treturn (*static_cast<<CLASS>*>(p1->rawptr) == *static_cast<<CLASS>*>(p2->rawptr) ? 0 : 1);";
		ret = ret.replace("<COMP>", comp);
	} else {
		String comp = "\treturn (p1->rawptr == p2->rawptr ? 0 : 1);";
		ret = ret.replace("<COMP>", comp);
	}
	ret = ret.replace("<CLASS>", class_name);
	return ret;
}

String QApplicationNew()
{
	String ret = """
KMETHOD QApplication_new(CTX ctx, ksfp_t *sfp _RIX)
{
	int dummy = 0;
	char **argv = (char **)malloc(1 * sizeof(char *));
	memset(argv, 0, sizeof(char *));
//	QApplication *app = new QApplication(dummy, argv);
	KQApplication *app = new KQApplication(dummy, argv);
	QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, app, NULL);
	app->setSelf(p);
	RETURN_(p);
}
""";
	return ret;
}

String QApplicationExec()
{
	String ret = """
KMETHOD QApplication_exec(CTX ctx, ksfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		exec_flag = true;
		int ret_v = QApplication::exec();
//		fprintf(stderr, "exec end\\n");
		exec_flag = false;
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}
""";
	return ret;
}

String FUNC_PARENTS(String class_name)
{
	String array_size = "10";
	String ret = """
//Array<String> <C>.parents();
KMETHOD <C>_parents(CTX ctx, ksfp_t *sfp _RIX)
{
	(void)ctx;
	<C> *qp = RawPtr_to(<C>*, sfp[0]);
	if (qp != NULL) {
		int size = <SIZE>;
		kArray *a = new_Array0(ctx, size);
		const knh_ClassTBL_t *ct = sfp[0].p->h.cTBL;
		while(ct->supcid != CLASS_Object) {
			ct = ct->supTBL;
			knh_Array_add(ctx, a, (kObject *)ct->lname);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}
""";
	ret = ret.replace("<C>", class_name);
	ret = ret.replace("<SIZE>", array_size);
	return ret;
}

String FUNC_PAINT(String class_name) //qp cast "KQ~" and 
{
	String ret = """
// //@Virtual void <C>.paint(QPainter painter, QStyleOptionGraphicsItem option, QWidget widget);
// KMETHOD <C>_paint(CTX ctx, ksfp_t *sfp _RIX)
// {
// 	(void)ctx;
// 	K<C> *  qp = RawPtr_to(K<C> *, sfp[0]);
// 	if (qp) {
// 		if (qp->dummy->paint_func != NULL) {
// 			knh_Func_invoke(ctx, qp->dummy->paint_func, sfp, 4);
// 		}
// 	}
// 	RETURNvoid_();
// }

//@Virtual void <C>.paint(QPainter painter, QStyleOptionGraphicsItem option, QWidget widget);
KMETHOD <C>_paint(CTX ctx, ksfp_t *sfp _RIX)
{
	(void)ctx;
	K<C> *  qp = RawPtr_to(K<C> *, sfp[0]);
	if (qp) {
		QPainter*  painter = RawPtr_to(QPainter*, sfp[1]);
		const QStyleOptionGraphicsItem*  option = RawPtr_to(const QStyleOptionGraphicsItem*, sfp[2]);
		QWidget*  widget = RawPtr_to(QWidget*, sfp[3]);
		qp->paint(painter, option, widget);
	}
	RETURNvoid_();
}

void K<C>::paint(QPainter *painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{
	if (dummy->paint_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		ksfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		kRawPtr *p1 = new_QRawPtr(lctx, QPainter, painter);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		kRawPtr *p2 = new_QRawPtr(lctx, QStyleOptionGraphicsItem, option);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+3].o, UPCAST(p2));
		kRawPtr *p3 = new_QRawPtr(lctx, QWidget, widget);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+4].o, UPCAST(p3));
		knh_Func_invoke(lctx, dummy->paint_func, lsfp, 4);
	} else {
<UNUSED>		<C>::paint(painter, option, widget);
	}
}
""";
	ret = ret.replace("<C>", class_name);
	if (class_name == "QGraphicsItem" ||
		class_name == "QGraphicsObject" ||
		class_name == "QAbstractGraphicsShapeItem") {
		ret = ret.replace("<UNUSED>", "//");
	} else {
		ret = ret.replace("<UNUSED>", "");
	}
	return ret;
}

// String FUNC_parentCall(String class_name)
// {
// 	String ret = "";
// 	ret += ""

// KMETHOD <C>_parentCall(CTX ctx, ksfp_t *sfp, _RIX)
// {
// 	<C> *qp = RawPtr_to(<C> *, sfp[0]);
// 	if (qp) {
// 		char *c_str = String_to(char *, sfp[1]);
// 		std::string str(c_str);

// 		std::map<string, kFunc*> *mp = qp->dummy->event_map;
// 		std::map<string, kFunc*>::iterator itr;
// 		if ((itr = em->find(str)) == em->end()) {
// 		}
// 		if ((itr = em->find(str)) == em->end()) {
// 		}



// 	} else {

// 	}
// }

// 	return ret;
// }
