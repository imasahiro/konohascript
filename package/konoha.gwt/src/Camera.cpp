#include <gwt.hpp>

#ifdef __cplusplus
extern "C" {
#endif

KMETHOD Camera_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	int n = Int_to(int, sfp[1]);
	GamCamera *c = new GamCamera(n);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, c, NULL);
	RETURN_(p);
}

KMETHOD Camera_queryFrame(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	GamCamera *c = RawPtr_to(GamCamera *, sfp[0]);
	GamTexture *t = c->queryFrame();
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, t, NULL);
	RETURN_(p);
}

static void Camera_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
#ifdef DEBUG_MODE
		fprintf(stderr, "Camera:free\n");
#endif
		GamCamera *c = (GamCamera *)p->rawptr;
		delete c;
	}
}

static void Camera_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx;
	(void)p;
	(void)tail_;
	if (p->rawptr != NULL) {
#ifdef DEBUG_MODE
		fprintf(stderr, "Camera:reftrace\n");
#endif
	}
}

DEFAPI(void) defCamera(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	NO_WARNING2();
	cdef->name = "Camera";
	cdef->free = Camera_free;
	cdef->reftrace = Camera_reftrace;
}

DEFAPI(void) constCamera(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi)
{
	(void)ctx;
	(void)cid;
	(void)kapi;
	//kapi->loadIntClassConst(ctx, cid, TimeLineConstInt);
}

#ifdef __cplusplus
}
#endif
