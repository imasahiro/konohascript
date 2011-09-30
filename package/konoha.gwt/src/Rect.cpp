#include <gwt.hpp>

#ifdef __cplusplus
extern "C" {
#endif

void KRect::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	if (mouse_press_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		knh_RawPtr_t *p2 = new_RawPtrFromClass(MouseEvent, event);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p2));
		knh_Func_invoke(lctx, mouse_press_func, lsfp, 2/*argc*/);
	}
}

void KRect::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
	if (mouse_move_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		knh_RawPtr_t *p2 = new_RawPtrFromClass(MouseEvent, event);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p2));
		knh_Func_invoke(lctx, mouse_move_func, lsfp, 2/*argc*/);
	}
}

void KRect::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
	if (mouse_release_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		knh_RawPtr_t *p2 = new_RawPtrFromClass(MouseEvent, event);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p2));
		knh_Func_invoke(lctx, mouse_release_func, lsfp, 2/*argc*/);
	}
}

void KRect::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
	(void)event;
}

void KRect::dragEnterEvent(QGraphicsSceneDragDropEvent *event)
{
	(void)event;
}

void KRect::wheelEvent(QGraphicsSceneWheelEvent *event)
{
	(void)event;
}

KRect::KRect(int x_, int y_, int width_, int height_) : GamRect(x_, y_, width_, height_)
{
	mouse_press_func = NULL;
	mouse_release_func = NULL;
	mouse_move_func = NULL;
}

KMETHOD Rect_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	int x = Int_to(int, sfp[1]);
	int y = Int_to(int, sfp[2]);
	int width = Int_to(int, sfp[3]);
	int height = Int_to(int, sfp[4]);
	KRect *r = new KRect(x, y, width, height);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, r, NULL);
	r->self = p;
	r->setBodyUserData(p);//for ContactEvent
	RETURN_(p);
}

KMETHOD Rect_setColor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	KRect *r = RawPtr_to(KRect *, sfp[0]);
	QColor *c = RawPtr_to(QColor *, sfp[1]);
	r->setBrush(*c);
	RETURNvoid_();
}

KMETHOD Rect_setZValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	KRect *r = RawPtr_to(KRect *, sfp[0]);
	int val = Int_to(int, sfp[1]);
	r->setZValue(val);
	RETURNvoid_();
}

KMETHOD Rect_setBullet(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	KRect *r = RawPtr_to(KRect *, sfp[0]);
	bool b = Boolean_to(bool, sfp[1]);
	r->setBullet(b);
	RETURNvoid_();
}

#ifdef K_USING_BOX2D
KMETHOD Rect_setRotation(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	KRect *r = RawPtr_to(KRect *, sfp[0]);
	qreal rotation = Float_to(qreal, sfp[1]);
	r->setRot(rotation);
	RETURNvoid_();
}

KMETHOD Rect_setDensity(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	KRect *r = RawPtr_to(KRect *, sfp[0]);
	qreal density = Float_to(qreal, sfp[1]);
	r->setDensity(density);
	RETURNvoid_();
}

KMETHOD Rect_setFriction(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	KRect *r = RawPtr_to(KRect *, sfp[0]);
	qreal friction = Float_to(qreal, sfp[1]);
	r->setFriction(friction);
	RETURNvoid_();
}

KMETHOD Rect_setRestitution(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	KRect *r = RawPtr_to(KRect *, sfp[0]);
	qreal restitution = Float_to(qreal, sfp[1]);
	r->setRestitution(restitution);
	RETURNvoid_();
}

KMETHOD Rect_isStatic(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	KRect *r = RawPtr_to(KRect *, sfp[0]);
	RETURNb_(r->isStatic);
}

KMETHOD Rect_setShadow(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	KRect *r = RawPtr_to(KRect *, sfp[0]);
	QGraphicsDropShadowEffect *se = RawPtr_to(QGraphicsDropShadowEffect *, sfp[1]);
	r->setGraphicsEffect(se);
	RETURNvoid_();
}

KMETHOD Rect_setTexture(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	KRect *r = RawPtr_to(KRect *, sfp[0]);
	KTexture *t = RawPtr_to(KTexture *, sfp[1]);
	QPixmap p = t->pixmap();
	QBrush b(p);
	r->setBrush(b);
	RETURNvoid_();
}

KMETHOD Rect_setMousePressEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	KRect *r = RawPtr_to(KRect *, sfp[0]);
	knh_Func_t *fo = sfp[1].fo;
	KNH_INITv(r->mouse_press_func, fo);
	RETURNvoid_();
}

KMETHOD Rect_setMouseReleaseEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	KRect *r = RawPtr_to(KRect *, sfp[0]);
	knh_Func_t *fo = sfp[1].fo;
	KNH_INITv(r->mouse_release_func, fo);
	RETURNvoid_();
}

KMETHOD Rect_setMouseMoveEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	KRect *r = RawPtr_to(KRect *, sfp[0]);
	knh_Func_t *fo = sfp[1].fo;
	KNH_INITv(r->mouse_move_func, fo);
	RETURNvoid_();
}

#endif

KMETHOD Rect_setSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	KRect *r = RawPtr_to(KRect *, sfp[0]);
	float width = Float_to(qreal, sfp[1]);
	float height = Float_to(qreal, sfp[2]);
	r->setSize(width, height);
	RETURNvoid_();
}

KMETHOD Rect_setPosition(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	KRect *r = RawPtr_to(KRect *, sfp[0]);
    int x = Int_to(qreal, sfp[1]);
	int y = Int_to(qreal, sfp[2]);
	r->setPos(x, y);
	RETURNvoid_();
}

KMETHOD Rect_getCenter(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	KRect *r = RawPtr_to(KRect *, sfp[0]);
	GamPoint *point = r->getCenter();
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, point, NULL);
	RETURN_(p);
}

static void Rect_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
#ifdef DEBUG_MODE
		fprintf(stderr, "Rect:free\n");
#endif
		KRect *r = (KRect *)p->rawptr;
		delete r;
	}
}

static void Rect_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
#ifdef DEBUG_MODE
		fprintf(stderr, "Rect:reftrace\n");
#endif
		KRect *r = (KRect *)p->rawptr;
		if (r->mouse_press_func != NULL) {
			KNH_ADDREF(ctx, r->mouse_press_func);
			KNH_SIZEREF(ctx);
		}
		if (r->mouse_move_func != NULL) {
			KNH_ADDREF(ctx, r->mouse_move_func);
			KNH_SIZEREF(ctx);
		}
		if (r->mouse_release_func != NULL) {
			KNH_ADDREF(ctx, r->mouse_release_func);
			KNH_SIZEREF(ctx);
		}
	}
}

DEFAPI(void) defRect(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	NO_WARNING2();
	cdef->name = "Rect";
	cdef->free = Rect_free;
	cdef->reftrace = Rect_reftrace;
}

DEFAPI(void) constRect(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi)
{
	(void)ctx;
	(void)cid;
	(void)kapi;
	//kapi->loadIntClassConst(ctx, cid, TimeLineConstInt);
}

#ifdef __cplusplus
}
#endif
