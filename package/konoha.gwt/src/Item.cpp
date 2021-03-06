#include <gwt.hpp>

#ifdef __cplusplus
extern "C" {
#endif

KMETHOD Item_translate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	//QGraphicsItem *i = RawPtr_to(QGraphicsItem *, sfp[0]);
	QGraphicsItem *i = QGraphicsItem_to(sfp[0]);
	int x = Int_to(int, sfp[1]);
	int y = Int_to(int, sfp[2]);
	i->translate(x, y);
	RETURNvoid_();
}

KMETHOD Item_setTransform(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	//QGraphicsItem *i = RawPtr_to(QGraphicsItem *, sfp[0]);
	QGraphicsItem *i = QGraphicsItem_to(sfp[0]);
	QTransform *t = RawPtr_to(QTransform *, sfp[1]);
	int b = Boolean_to(int, sfp[2]);
	i->setTransform(*t, b);
	RETURNvoid_();
}

KMETHOD Item_setOpacity(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	QGraphicsItem *i = QGraphicsItem_to(sfp[0]);
	qreal opacity = Float_to(qreal, sfp[1]);
	i->setOpacity(opacity);
	RETURNvoid_();
}

KMETHOD Item_setTransformOriginPoint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	QGraphicsItem *i = QGraphicsItem_to(sfp[0]);
	qreal x = Float_to(qreal, sfp[1]);
	qreal y = Float_to(qreal, sfp[2]);
	i->setTransformOriginPoint(x, y);
	RETURNvoid_();
}

KMETHOD Item_getX(Ctx *ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	QGraphicsItem *i = QGraphicsItem_to(sfp[0]);
	RETURNi_(i->x());
}

KMETHOD Item_getY(Ctx *ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	QGraphicsItem *i = QGraphicsItem_to(sfp[0]);
	RETURNi_(i->y());
}

static void Item_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	(void)p;
	fprintf(stderr, "Item:free\n");
	//GamItem *i = (GamItem *)p->rawptr;
}

static void Item_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx;
	(void)p;
	(void)tail_;
	fprintf(stderr, "Item:reftrace\n");
	//QApplication *app = (QApplication *)p->rawptr;
}

DEFAPI(void) defItem(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	NO_WARNING2();
	cdef->name = "Item";
	cdef->free = Item_free;
	cdef->reftrace = Item_reftrace;
}

DEFAPI(void) constItem(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi)
{
	(void)ctx;
	(void)cid;
	(void)kapi;
	//kapi->loadIntClassConst(ctx, cid, TimeLineConstInt);
}

#ifdef __cplusplus
}
#endif
