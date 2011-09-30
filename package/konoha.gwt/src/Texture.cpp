#include <gwt.hpp>

#ifdef __cplusplus
extern "C" {
#endif

void KTexture::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	if (mouse_press_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		knh_RawPtr_t *p1 = new_RawPtrFromClass(Texture, this);
		knh_RawPtr_t *p2 = new_RawPtrFromClass(MouseEvent, event);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(p1));
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p2));
		knh_Func_invoke(lctx, mouse_press_func, lsfp, 2/*argc*/);
	}
}

void KTexture::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
	if (mouse_move_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		knh_RawPtr_t *p1 = new_RawPtrFromClass(Texture, this);
		knh_RawPtr_t *p2 = new_RawPtrFromClass(MouseEvent, event);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(p1));
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p2));
		knh_Func_invoke(lctx, mouse_move_func, lsfp, 2/*argc*/);
	}
}

void KTexture::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
	if (mouse_release_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		knh_RawPtr_t *p1 = new_RawPtrFromClass(Texture, this);
		knh_RawPtr_t *p2 = new_RawPtrFromClass(MouseEvent, event);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(p1));
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p2));
		knh_Func_invoke(lctx, mouse_release_func, lsfp, 2/*argc*/);
	}
}

void KTexture::dragEnterEvent(QGraphicsSceneDragDropEvent *event)
{
	(void)event;
}


KTexture::KTexture(const char *filepath_) : GamTexture(filepath_)
{
	mouse_press_func = NULL;
	mouse_release_func = NULL;
	mouse_move_func = NULL;
}

KMETHOD Texture_new(Ctx *ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	const char *filepath = String_to(const char *, sfp[1]);
	KTexture *t = new KTexture(filepath);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, t, NULL);
	t->setBodyUserData(p);//for ContactEvent
	RETURN_(p);
}

KMETHOD Texture_setRect(Ctx *ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	KTexture *t = RawPtr_to(KTexture *, sfp[0]);
	KRect *r = RawPtr_to(KRect *, sfp[1]);
	t->setRectShape(r);
	RETURNvoid_();
}

KMETHOD Texture_setColor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	KTexture *t = RawPtr_to(KTexture *, sfp[0]);
	QColor *c = RawPtr_to(QColor *, sfp[1]);
	t->setColor(c);
	RETURNvoid_();
}

KMETHOD Texture_split(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	KTexture *t = RawPtr_to(KTexture *, sfp[0]);
	int row = Int_to(int, sfp[1]);
	int col = Int_to(int, sfp[2]);
	QList<GamTexture*> *panels = t->split(row, col);
	int size = row * col;
	knh_Array_t *a = new_Array0(ctx, size);
	knh_class_t cid = knh_getcid(ctx, STEXT("Texture"));
	for (int i = 0; i < size; i++) {
		knh_RawPtr_t *p = new_RawPtr(ctx, ClassTBL(cid), panels->at(i));
		knh_Array_add(ctx, a, (knh_Object_t *)p);
	}
	delete panels;
	RETURN_(a);
}

/*
KMETHOD Texture_setPosition(Ctx *ctx, knh_sfp_t *sfp, long rix)
{
	NO_WARNING();
	KTexture *t = RawPtr_to(KTexture *, sfp[0]);
	qreal x = Float_to(qreal, sfp[1]);
	qreal y = Float_to(qreal, sfp[2]);
	image->setPosition(x, y);
	RETURNvoid_();
}
*/

KMETHOD Texture_setDensity(Ctx *ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	KTexture *t = RawPtr_to(KTexture *, sfp[0]);
	qreal density = Float_to(qreal, sfp[1]);
	t->setDensity(density);
	RETURNvoid_();
}

KMETHOD Texture_setFriction(Ctx *ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	KTexture *t = RawPtr_to(KTexture *, sfp[0]);
	qreal friction = Float_to(qreal, sfp[1]);
	t->setFriction(friction);
	RETURNvoid_();
}

KMETHOD Texture_setRotation(Ctx *ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	KTexture *t = RawPtr_to(KTexture *, sfp[0]);
	qreal rotation = Float_to(qreal, sfp[1]);
	t->setRotation(rotation);
	RETURNvoid_();
}

KMETHOD Texture_setRestitution(Ctx *ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	KTexture *t = RawPtr_to(KTexture *, sfp[0]);
	qreal restitution = Float_to(qreal, sfp[1]);
	t->setRestitution(restitution);
	RETURNvoid_();
}

KMETHOD Texture_detectHuman(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	KTexture *t = RawPtr_to(KTexture *, sfp[0]);
	KTexture *background = RawPtr_to(KTexture *, sfp[1]);
	QList<GamVector> *objs = t->detectHuman(background);
	int objs_size = objs->length();
	knh_Array_t *a = new_Array0(ctx, objs_size);
	knh_class_t cid = knh_getcid(ctx, STEXT("Point"));
	for (int i = 0; i < objs_size; i++) {
		GamVector obj = objs->at(i);
		int obj_size = obj.size();
		knh_Array_t *elem = new_Array0(ctx, obj_size);
		for (int j = 0; j < obj_size; j++) {
			Vec2f p = obj.at(j);
			knh_Array_add(ctx, elem, (knh_Object_t *)new_RawPtr(ctx, ClassTBL(cid), new GamPoint(p.x, p.y)));
		}
		knh_Array_add(ctx, a, (Object *)elem);
        obj.clear();
	}
    delete objs;
	RETURN_(a);
}

KMETHOD Texture_setMousePressEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	KTexture *t = RawPtr_to(KTexture *, sfp[0]);
	knh_Func_t *fo = sfp[1].fo;
	t->mouse_press_func = fo;
	RETURNvoid_();
}

KMETHOD Texture_setMouseReleaseEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	KTexture *t = RawPtr_to(KTexture *, sfp[0]);
	knh_Func_t *fo = sfp[1].fo;
	t->mouse_release_func = fo;
	RETURNvoid_();
}

KMETHOD Texture_setMouseMoveEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	KTexture *t = RawPtr_to(KTexture *, sfp[0]);
	knh_Func_t *fo = sfp[1].fo;
	t->mouse_move_func = fo;
	RETURNvoid_();
}

KMETHOD Texture_setTransformOriginPoint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	KTexture *t = RawPtr_to(KTexture *, sfp[0]);
	qreal x = Float_to(qreal, sfp[1]);
	qreal y = Float_to(qreal, sfp[2]);
	t->setTransformOriginPoint(x, y);
	RETURNvoid_();
}

KMETHOD Texture_scale(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	KTexture *t = RawPtr_to(KTexture *, sfp[0]);
	qreal x = Float_to(qreal, sfp[1]);
	qreal y = Float_to(qreal, sfp[2]);
	t->scale(x, y);
	RETURNvoid_();
}

KMETHOD Texture_setSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	KTexture *t = RawPtr_to(KTexture *, sfp[0]);
	float width = Float_to(qreal, sfp[1]);
	float height = Float_to(qreal, sfp[2]);
	t->setSize(width, height);
	RETURNvoid_();
}

KMETHOD Texture_setPosition(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	KTexture *t = RawPtr_to(KTexture *, sfp[0]);
    int x = Int_to(int, sfp[1]);
	int y = Int_to(int, sfp[2]);
	t->x = x;
	t->y = y;
	t->setPos(x, y);
	RETURNvoid_();
}

KMETHOD Texture_setZValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	KTexture *t = RawPtr_to(KTexture *, sfp[0]);
	int val = Int_to(int, sfp[1]);
	t->setZValue(val);
	RETURNvoid_();
}

KMETHOD Texture_getCenter(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	KTexture *t = RawPtr_to(KTexture *, sfp[0]);
	GamPoint *point = t->getCenter();
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, point, NULL);
	RETURN_(p);
}

static void Texture_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
#ifdef DEBUG_MODE
		fprintf(stderr, "Texture:free\n");
#endif
		KTexture *t = (KTexture *)p->rawptr;
		delete t;
	}
}

static void Texture_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx;
	(void)p;
	(void)tail_;
	if (p->rawptr != NULL) {
#ifdef DEBUG_MODE
		fprintf(stderr, "Texture:reftrace\n");
#endif
		KTexture *t = (KTexture *)p->rawptr;
		KNH_ADDREF(ctx, t->mouse_press_func);
		KNH_ADDREF(ctx, t->mouse_move_func);
		KNH_ADDREF(ctx, t->mouse_release_func);
	}
}

DEFAPI(void) defTexture(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	NO_WARNING2();
	cdef->name = "Texture";
	cdef->free = Texture_free;
	cdef->reftrace = Texture_reftrace;
}

DEFAPI(void) constTexture(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi)
{
	(void)ctx;
	(void)cid;
	(void)kapi;
	//kapi->loadIntClassConst(ctx, cid, TimeLineConstInt);
}

/*
KMETHOD QPixmap_setSize(Ctx *ctx, knh_sfp_t *sfp, long rix)
{
	KPixmap *image = RawPtr_to(KPixmap *, sfp[0]);
	int width = Int_to(int, sfp[1]);
	int height = Int_to(int, sfp[2]);
	image->setSize(width, height);
	RETURNvoid_();
}
*/
#ifdef __cplusplus
}
#endif
