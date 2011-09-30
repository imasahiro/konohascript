#include <gwt.hpp>

#ifdef __cplusplus
extern "C" {
#endif

#ifdef K_USING_BOX2D
KWorld::KWorld(KScene *scene) : GamWorld(scene)
{
	contact = new KContact();
	world->SetContactListener(contact);
}

KMETHOD World_new(Ctx *ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	qsrand(time(0));
	KScene *s = RawPtr_to(KScene *, sfp[1]);
	KWorld *w = new KWorld(s);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, w, NULL);
	RETURN_(p);
}

KMETHOD World_add(Ctx *ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	KWorld *world = RawPtr_to(KWorld *, sfp[0]);
	GamObject *o = GamObject_to(sfp[1]);
	world->add(o);
	RETURNvoid_();
}

KMETHOD World_remove(Ctx *ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	KWorld *world = RawPtr_to(KWorld *, sfp[0]);
	GamObject *o = GamObject_to(sfp[1]);
	world->remove(o);
	RETURNvoid_();
}

KMETHOD World_start(Ctx *ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	KWorld *w = RawPtr_to(KWorld *, sfp[0]);
	w->start();
	RETURNvoid_();
}

KMETHOD World_setGravity(Ctx *ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	KWorld *w = RawPtr_to(KWorld *, sfp[0]);
	float x = Float_to(float, sfp[1]);
	float y = Float_to(float, sfp[2]);
	if (w->world != NULL) {
		w->world->SetGravity(b2Vec2(x, y));
	}
	RETURNvoid_();
}

KMETHOD World_setBeginContactEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	KWorld *w = RawPtr_to(KWorld *, sfp[0]);
	knh_Func_t *f = sfp[1].fo;
	w->contact->begin = f;
	RETURNvoid_();
}

KMETHOD World_setEndContactEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	KWorld *w = RawPtr_to(KWorld *, sfp[0]);
	knh_Func_t *f = sfp[1].fo;
	w->contact->end = f;
	RETURNvoid_();
}

#endif

static void World_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
#ifdef DEBUG_MODE
		fprintf(stderr, "World:free\n");
#endif
		KWorld *w = (KWorld *)p->rawptr;
		delete w;
	}
}

static void World_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
#ifdef DEBUG_MODE
		fprintf(stderr, "World:reftrace\n");
#endif
	}
}

DEFAPI(void) defWorld(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	NO_WARNING2();
	cdef->name = "World";
	cdef->free = World_free;
	cdef->reftrace = World_reftrace;
}

DEFAPI(void) constWorld(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi)
{
	(void)ctx;
	(void)cid;
	(void)kapi;
	//kapi->loadIntClassConst(ctx, cid, TimeLineConstInt);
}

#ifdef __cplusplus
}
#endif
