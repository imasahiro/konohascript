#include <gwt.hpp>

#ifdef __cplusplus
extern "C" {
#endif

KMETHOD Ellipse_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	GamEllipse *e = new GamEllipse();
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, e, NULL);
	e->setBodyUserData(p);//for ContactEvent
	RETURN_(p);
}

KMETHOD Ellipse_setRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	GamEllipse *e = RawPtr_to(GamEllipse *, sfp[0]);
	GamRect *r = RawPtr_to(GamRect *, sfp[1]);
	e->setRectShape(r);
	RETURNvoid_();
}

KMETHOD Ellipse_setColor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	GamEllipse *e = RawPtr_to(GamEllipse *, sfp[0]);
	QColor *c = RawPtr_to(QColor *, sfp[1]);
	e->setBrush(*c);
	RETURNvoid_();
}

KMETHOD Ellipse_setZValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	GamEllipse *e = RawPtr_to(GamEllipse *, sfp[0]);
	int val = Int_to(int, sfp[1]);
	e->setZValue(val);
	RETURNvoid_();
}

KMETHOD Ellipse_getZValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	GamEllipse *e = RawPtr_to(GamEllipse *, sfp[0]);
	RETURNi_(e->zValue());
}

#ifdef K_USING_BOX2D
KMETHOD Ellipse_setRotation(Ctx *ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	GamEllipse *e = RawPtr_to(GamEllipse *, sfp[0]);
	qreal rotation = Float_to(qreal, sfp[1]);
	e->setRotation(rotation);
	RETURNvoid_();
}

KMETHOD Ellipse_setDensity(Ctx *ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	GamEllipse *e = RawPtr_to(GamEllipse *, sfp[0]);
	qreal density = Float_to(qreal, sfp[1]);
	e->setDensity(density);
	RETURNvoid_();
}

KMETHOD Ellipse_setFriction(Ctx *ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	GamEllipse *e = RawPtr_to(GamEllipse *, sfp[0]);
	qreal friction = Float_to(qreal, sfp[1]);
	e->setFriction(friction);
	RETURNvoid_();
}

KMETHOD Ellipse_setRestitution(Ctx *ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	GamEllipse *e = RawPtr_to(GamEllipse *, sfp[0]);
	qreal restitution = Float_to(qreal, sfp[1]);
	e->setRestitution(restitution);
	RETURNvoid_();
}
#endif

KMETHOD Ellipse_setPosition(Ctx *ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	GamEllipse *e = RawPtr_to(GamEllipse *, sfp[0]);
	int x = Int_to(int, sfp[1]);
	int y = Int_to(int, sfp[2]);
	e->setPosition(x, y);
	RETURNvoid_();
}

KMETHOD Ellipse_setGlowCenterColor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	GamEllipse *e = RawPtr_to(GamEllipse *, sfp[0]);
	QColor *c = RawPtr_to(QColor *, sfp[1]);
	e->setGlowCenterColor(c);
	RETURNvoid_();
}

KMETHOD Ellipse_setGlow(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	GamEllipse *e = RawPtr_to(GamEllipse *, sfp[0]);
	e->setGlow();
	RETURNvoid_();
}

static void Ellipse_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
#ifdef DEBUG_MODE
		fprintf(stderr, "Ellipse:free\n");
#endif
		GamEllipse *e = (GamEllipse *)p->rawptr;
		delete e;
	}
}

static void Ellipse_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
#ifdef DEBUG_MODE
		fprintf(stderr, "Ellipse:reftrace\n");
#endif
	}
}

DEFAPI(void) defEllipse(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	NO_WARNING2();
	cdef->name = "Ellipse";
	cdef->free = Ellipse_free;
	cdef->reftrace = Ellipse_reftrace;
}

DEFAPI(void) constEllipse(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi)
{
	(void)ctx;
	(void)cid;
	(void)kapi;
	//kapi->loadIntClassConst(ctx, cid, TimeLineConstInt);
}

#ifdef __cplusplus
}
#endif
