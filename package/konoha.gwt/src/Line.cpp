#include <gwt.hpp>

#ifdef __cplusplus
extern "C" {
#endif

void KLine::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	if (mouse_press_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		knh_RawPtr_t *p1 = new_RawPtrFromClass(Line, this);
		knh_RawPtr_t *p2 = new_RawPtrFromClass(MouseEvent, event);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(p1));
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p2));
		knh_Func_invoke(lctx, mouse_press_func, lsfp, 2/*argc*/);
	}
}

void KLine::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
	if (mouse_move_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		knh_RawPtr_t *p1 = new_RawPtrFromClass(Line, this);
		knh_RawPtr_t *p2 = new_RawPtrFromClass(MouseEvent, event);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(p1));
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p2));
		knh_Func_invoke(lctx, mouse_move_func, lsfp, 2/*argc*/);
	}
}

void KLine::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
	if (mouse_release_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		knh_RawPtr_t *p1 = new_RawPtrFromClass(Line, this);
		knh_RawPtr_t *p2 = new_RawPtrFromClass(MouseEvent, event);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(p1));
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p2));
		knh_Func_invoke(lctx, mouse_release_func, lsfp, 2/*argc*/);
	}
}

void KLine::dragEnterEvent(QGraphicsSceneDragDropEvent *event)
{
	(void)event;
}

void KLine::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
	(void)event;
}


KLine::KLine(int x1_, int y1_, int x2_, int y2_) : GamLine(x1_, y1_, x2_, y2_)
{
	mouse_press_func = NULL;
	mouse_move_func = NULL;
	mouse_release_func = NULL;
}

KMETHOD Line_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	int x1 = Int_to(int, sfp[1]);
	int y1 = Int_to(int, sfp[2]);
	int x2 = Int_to(int, sfp[3]);
	int y2 = Int_to(int, sfp[4]);
	GamLine *l = new GamLine(x1, y1, x2, y2);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, l, NULL);
	l->setBodyUserData(p);//for ContactEvent
	RETURN_(p);
}

KMETHOD Line_setPen(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	GamLine *l = RawPtr_to(GamLine *, sfp[0]);
	QPen* pen = RawPtr_to(QPen *, sfp[1]);
	l->setPen(*pen);
	RETURNvoid_();
}

KMETHOD Line_setColor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	GamLine *l = RawPtr_to(GamLine *, sfp[0]);
	QColor *c = RawPtr_to(QColor *, sfp[1]);
	QPen p = l->pen();
	p.setColor(*c);
	l->setPen(p);
	RETURNvoid_();
}

#ifdef K_USING_BOX2D
KMETHOD Line_setRotation(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	GamLine *r = RawPtr_to(GamLine *, sfp[0]);
	qreal rotation = Float_to(qreal, sfp[1]);
	r->setRotation(rotation);
	RETURNvoid_();
}

KMETHOD Line_setDensity(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	GamLine *r = RawPtr_to(GamLine *, sfp[0]);
	qreal density = Float_to(qreal, sfp[1]);
	r->setDensity(density);
	RETURNvoid_();
}

KMETHOD Line_setFriction(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	GamLine *r = RawPtr_to(GamLine *, sfp[0]);
	qreal friction = Float_to(qreal, sfp[1]);
	r->setFriction(friction);
	RETURNvoid_();
}

KMETHOD Line_setRestitution(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	GamLine *r = RawPtr_to(GamLine *, sfp[0]);
	qreal restitution = Float_to(qreal, sfp[1]);
	r->setRestitution(restitution);
	RETURNvoid_();
}

KMETHOD Line_isSTatic(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	GamLine *r = RawPtr_to(GamLine *, sfp[0]);
	RETURNb_(r->isStatic);
}

KMETHOD Line_setShadow(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	GamLine *gl = RawPtr_to(GamLine *, sfp[0]);
	QGraphicsDropShadowEffect *se = RawPtr_to(QGraphicsDropShadowEffect *, sfp[1]);
	gl->setGraphicsEffect(se);
	RETURNvoid_();
}

#endif

DEFAPI(void) defLine(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	NO_WARNING2();
	cdef->name = "Line";
	//cdef->free = Texture_free;
	//cdef->reftrace = Texture_reftrace;
}

DEFAPI(void) constLine(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi)
{
	(void)ctx;
	(void)cid;
	(void)kapi;
	//kapi->loadIntClassConst(ctx, cid, TimeLineConstInt);
}

#ifdef __cplusplus
}
#endif
