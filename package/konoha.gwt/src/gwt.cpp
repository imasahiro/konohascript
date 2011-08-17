#include <gwt.hpp>

#ifdef __cplusplus
extern "C" {
#endif

DEFAPI(void) defGwt(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	NO_WARNING2();
	cdef->name = "Gwt";
}

static knh_IntData_t GwtConstInt[] = {
	{"YAxis", Qt::YAxis},
	{NULL, 0}
};

DEFAPI(void) constGwt(CTX ctx, knh_class_t cid, const knh_PackageLoaderAPI_t *kapi)
{
	kapi->loadClassIntConst(ctx, cid, GwtConstInt);
}

DEFAPI(const knh_PackageDef_t*) init(CTX ctx, const knh_PackageLoaderAPI_t *kapi)
{
	RETURN_PKGINFO("konoha.gwt");
}

#ifdef __cplusplus
}
#endif
