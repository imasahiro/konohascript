#define K_INTERNAL
#include <konoha1.h>
#include <konoha1/inlinelibs.h>

// #ifdef __cplusplus
// extern "C" {
// #endif

// //Array<String> System.parents(Object c);
// KMETHOD System_parents(CTX ctx, knh_sfp_t *sfp _RIX)
// {
// 	(void)ctx;
// 	const knh_ClassTBL_t *ct = O_cTBL(sfp[1].o);
// 	if(IS_Class(sfp[1].o)) {
// 		ct = ClassTBL(((knh_Class_t*)sfp[1].o)->cid);
// 		knh_Array_t *a = new_Array0(ctx, 10);
// 		while(ct->supcid != CLASS_Object) {
// 			ct = ct->supTBL;
// 			knh_Array_add(ctx, a, (knh_Object_t *)ct->lname);
// 		}
// 		RETURN_(a);
// 	} else {
// 		RETURN_(KNH_NULL);
// 	}
// }

//Array<String> System.getClassParents(String class_name);
KMETHOD System_getClassParents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	knh_String_t *class_name = sfp[1].s;
	knh_bytes_t lname = class_name->str;
	const knh_ClassTBL_t *ct = (const knh_ClassTBL_t *)knh_DictSet_get(ctx, ctx->share->classNameDictSet, lname);
	if(ct != 0) {
		knh_Array_t *a = new_Array0(ctx, 10);
		while(ct->supcid != CLASS_Object) {
			ct = ct->supTBL;
			knh_Array_add(ctx, a, (knh_Object_t *)ct->lname);
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

