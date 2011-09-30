#include <gwt.hpp>

#ifdef __cplusplus
extern "C" {
#endif

KMETHOD Text_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	QString text = String_to(QString, sfp[1]);
	GamText *t = new GamText(text);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, t, NULL);
	t->setBodyUserData(p);//for ContactEvent
	RETURN_(p);
}

KMETHOD Text_setPosition(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	GamText *t = RawPtr_to(GamText *, sfp[0]);
	int x = Int_to(int, sfp[1]);
	int y = Int_to(int, sfp[2]);
	t->setPosition(x, y);
	RETURNvoid_();
}

KMETHOD Text_setColor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	GamText *t = RawPtr_to(GamText *, sfp[0]);
	QColor *c = RawPtr_to(QColor *, sfp[1]);
	(void)t;
	(void)c;
	//t->setBrush(*c);
	RETURNvoid_();
}

#ifdef K_USING_BOX2D
KMETHOD Text_setRotation(Ctx *ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	GamText *t = RawPtr_to(GamText *, sfp[0]);
	qreal rotation = Float_to(qreal, sfp[1]);
	t->setRotation(rotation);
	RETURNvoid_();
}

KMETHOD Text_setDensity(Ctx *ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	GamText *t = RawPtr_to(GamText *, sfp[0]);
	qreal density = Float_to(qreal, sfp[1]);
	t->setDensity(density);
	RETURNvoid_();
}

KMETHOD Text_setFriction(Ctx *ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	GamText *t = RawPtr_to(GamText *, sfp[0]);
	qreal friction = Float_to(qreal, sfp[1]);
	t->setFriction(friction);
	RETURNvoid_();
}

KMETHOD Text_setRestitution(Ctx *ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	GamText *t = RawPtr_to(GamText *, sfp[0]);
	qreal restitution = Float_to(qreal, sfp[1]);
	t->setRestitution(restitution);
	RETURNvoid_();
}
#endif

static void Text_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
#ifdef DEBUG_MODE
		fprintf(stderr, "Text:free\n");
#endif
		GamText *t = (GamText *)p->rawptr;
		(void)t;
		//delete t;
	}
}

static void Text_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx;
	(void)p;
	(void)tail_;
	if (p->rawptr != NULL) {
#ifdef DEBUG_MODE
		fprintf(stderr, "Text:reftrace\n");
#endif
	}
}

DEFAPI(void) defText(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	NO_WARNING2();
	cdef->name = "Text";
	cdef->free = Text_free;
	cdef->reftrace = Text_reftrace;
}

DEFAPI(void) constText(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi)
{
	(void)ctx;
	(void)cid;
	(void)kapi;
	//kapi->loadIntClassConst(ctx, cid, TimeLineConstInt);
}

#ifdef __cplusplus
}
#endif
