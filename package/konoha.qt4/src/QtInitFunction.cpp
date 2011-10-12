#define K_INTERNAL
#include <konoha1.h>
#include <konoha1/inlinelibs.h>

#ifdef __cplusplus
extern "C" {
#endif

DEFAPI(const knh_PackageDef_t*) init(CTX, const knh_LoaderAPI_t *)
{
	RETURN_PKGINFO("Qt-4.7");
}

#ifdef __cplusplus
}
#endif

