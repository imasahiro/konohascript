#include <gwt.hpp>

#ifdef __cplusplus
extern "C" {
#endif

KMETHOD ComplexItem_new(Ctx *ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	knh_Array_t *a = sfp[1].a;
	int asize = knh_Array_size(a);
	std::vector<Vec2f> pts;
	for (int i = 0; i < asize; i++) {
		knh_RawPtr_t *o = (knh_RawPtr_t *)a->list[i];
		GamPoint *p = (GamPoint *)o->rawptr;
		pts.push_back(Vec2f(p->x, p->y));
	}
	GamComplexItem *c = new GamComplexItem(pts, asize);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, c, NULL);
	RETURN_(p);
}

KMETHOD ComplexItem_setPosition(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	GamComplexItem *c = RawPtr_to(GamComplexItem *, sfp[0]);
	int x = Int_to(int, sfp[1]);
	int y = Int_to(int, sfp[2]);
	c->setPosition(x, y);
	RETURNvoid_();
}

KMETHOD ComplexItem_setColor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	GamComplexItem *c = RawPtr_to(GamComplexItem *, sfp[0]);
	QColor *clr = RawPtr_to(QColor *, sfp[1]);
	c->setColor(clr);
	RETURNvoid_();
}

KMETHOD ComplexItem_setBullet(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	GamComplexItem *c = RawPtr_to(GamComplexItem *, sfp[0]);
	bool b = Boolean_to(bool, sfp[1]);
	c->setBullet(b);
	RETURNvoid_();
}

#ifdef K_USING_BOX2D
KMETHOD ComplexItem_setDensity(Ctx *ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	GamComplexItem *c = RawPtr_to(GamComplexItem *, sfp[0]);
	qreal density = Float_to(qreal, sfp[1]);
	c->setDensity(density);
	RETURNvoid_();
}
#endif

static void ComplexItem_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
#ifdef DEBUG_MODE
		//fprintf(stderr, "ComplexItem:free\n");
#endif
		GamComplexItem *t = (GamComplexItem *)p->rawptr;
		delete t;
	}
}

static void ComplexItem_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx;
	(void)p;
	(void)tail_;
	if (p->rawptr != NULL) {
#ifdef DEBUG_MODE
		fprintf(stderr, "ComplexItem:reftrace\n");
#endif
	}
}

DEFAPI(void) defComplexItem(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	NO_WARNING2();
	cdef->name = "ComplexItem";
	cdef->free = ComplexItem_free;
	cdef->reftrace = ComplexItem_reftrace;
}

DEFAPI(void) constComplexItem(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi)
{
	(void)ctx;
	(void)cid;
	(void)kapi;
	//kapi->loadIntClassConst(ctx, cid, TimeLineConstInt);
}

#ifdef __cplusplus
}
#endif
