#include <gwt.hpp>

#ifdef __cplusplus
extern "C" {
#endif

KMETHOD Video_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	const char* filename = String_to(const char*, sfp[1]);
	GamVideo *video = new GamVideo(filename);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, video, NULL);
	RETURN_(p);
}

KMETHOD Video_queryFrame(CTX ctx, knh_sfp_t *sfp _RIX)
{
	GamVideo *v = RawPtr_to(GamVideo *, sfp[0]);
	GamTexture *frame = v->queryFrame();
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, frame, NULL);
	RETURN_(p);
}

static void Video_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		fprintf(stderr, "Video:free\n");
		GamVideo *v = (GamVideo *)p->rawptr;
		delete v;
	}
}

static void Video_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		fprintf(stderr, "Video:reftrace\n");
	}
}

DEFAPI(void) defVideo(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	NO_WARNING2();
	cdef->name = "Video";
	cdef->free = Video_free;
	cdef->reftrace = Video_reftrace;
}

DEFAPI(void) constVideo(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi)
{
	(void)ctx;
	(void)cid;
	(void)kapi;
	//kapi->loadIntClassConst(ctx, cid, TimeLineConstInt);
}

#ifdef __cplusplus
}
#endif
