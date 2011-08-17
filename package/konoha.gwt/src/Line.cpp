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

KLine::KLine(int x1_, int y1_, int x2_, int y2_)
{
	x1 = x1_;
	y1 = y1_;
	x2 = x2_;
	y2 = y2_;
	width = ((x1_ - x2_) > 0) ? (x1_ - x2_) : (x2_ - x1_);
	height = ((y1_ - y2_) > 0) ? (y1_ - y2_) : (y2_ - y1_);
	isDrag = false;
	l = new QLine(x1_, y1_, x2_, y2_);
	setLine(*l);
	setObjectName("KLine");
	setTag(GLine);
	mouse_press_func = NULL;
	mouse_move_func = NULL;
	mouse_release_func = NULL;

#ifdef K_USING_BOX2D
	isStatic = true;
#endif
}


#ifdef K_USING_BOX2D
void KLine::addToWorld(KWorld *w)
{
	b2World *world = w->world;
	b2BodyDef bodyDef;
	if (!isStatic) {
		bodyDef.type = b2_dynamicBody;
	}
	bodyDef.position.Set(0, 0);
	bodyDef.angle = -(rotation() * (2 * M_PI)) / 360.0;
	body = world->CreateBody(&bodyDef);

	b2FixtureDef shapeDef;
	b2PolygonShape shape;
	shape.SetAsBox(width / 2, 1, *(new b2Vec2(x1 + width/2, -y1)), 0.0);
	shapeDef.shape = &shape;
	shapeDef.density = density;
	shapeDef.friction = friction;
	shapeDef.restitution = restitution;
	body->CreateFixture(&shapeDef);

	QGraphicsItem *i = dynamic_cast<QGraphicsItem *>(this);
	knh_GraphicsUserData_t *data = (knh_GraphicsUserData_t *)malloc(sizeof(knh_GraphicsUserData_t));
	memset(data, 0, sizeof(knh_GraphicsUserData_t));
	CTX lctx = knh_getCurrentContext();
	data->ct = getClassTBL(Texture);
	data->o = i;
	body->SetUserData(data);
}

#endif

KMETHOD Line_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	int x1 = Int_to(int, sfp[1]);
	int y1 = Int_to(int, sfp[2]);
	int x2 = Int_to(int, sfp[3]);
	int y2 = Int_to(int, sfp[4]);
	KLine *l = new KLine(x1, y1, x2, y2);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, l, NULL);
	RETURN_(p);
}

KMETHOD Line_setPen(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	KLine *l = RawPtr_to(KLine *, sfp[0]);
	QPen* pen = RawPtr_to(QPen *, sfp[1]);
	l->setPen(*pen);
	RETURNvoid_();
}

KMETHOD Line_setColor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	KLine *l = RawPtr_to(KLine *, sfp[0]);
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
	KLine *r = RawPtr_to(KLine *, sfp[0]);
	qreal rotation = Float_to(qreal, sfp[1]);
	r->setRotation(rotation);
	RETURNvoid_();
}

KMETHOD Line_setDensity(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	KLine *r = RawPtr_to(KLine *, sfp[0]);
	qreal density = Float_to(qreal, sfp[1]);
	r->setDensity(density);
	RETURNvoid_();
}

KMETHOD Line_setFriction(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	KLine *r = RawPtr_to(KLine *, sfp[0]);
	qreal friction = Float_to(qreal, sfp[1]);
	r->setFriction(friction);
	RETURNvoid_();
}

KMETHOD Line_setRestitution(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	KLine *r = RawPtr_to(KLine *, sfp[0]);
	qreal restitution = Float_to(qreal, sfp[1]);
	r->setRestitution(restitution);
	RETURNvoid_();
}

KMETHOD Line_isSTatic(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	KLine *r = RawPtr_to(KLine *, sfp[0]);
	RETURNb_(r->isStatic);
}

KMETHOD Line_setShadow(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	KLine *gl = RawPtr_to(KLine *, sfp[0]);
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

DEFAPI(void) constLine(CTX ctx, knh_class_t cid, const knh_PackageLoaderAPI_t *kapi)
{
	(void)ctx;
	(void)cid;
	(void)kapi;
	//kapi->loadIntClassConst(ctx, cid, TimeLineConstInt);
}

#ifdef __cplusplus
}
#endif
