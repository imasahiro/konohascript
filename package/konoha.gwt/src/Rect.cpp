#include <gwt.hpp>

#ifdef __cplusplus
extern "C" {
#endif

GObject::GObject(void)
{
	_tag = 0;
}

void GObject::setTag(int tag)
{
	_tag = tag;
}

int GObject::tag(void)
{
	return _tag;
}

void KRect::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	if (mouse_press_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		knh_RawPtr_t *p1 = new_RawPtrFromClass(Rect, this);
		knh_RawPtr_t *p2 = new_RawPtrFromClass(MouseEvent, event);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(p1));
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p2));
		knh_Func_invoke(lctx, mouse_press_func, lsfp, 2/*argc*/);
	}
}

void KRect::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
	if (mouse_move_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		knh_RawPtr_t *p1 = new_RawPtrFromClass(Rect, this);
		knh_RawPtr_t *p2 = new_RawPtrFromClass(MouseEvent, event);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(p1));
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p2));
		knh_Func_invoke(lctx, mouse_move_func, lsfp, 2/*argc*/);
	}
}

void KRect::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
	if (mouse_release_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		knh_RawPtr_t *p1 = new_RawPtrFromClass(Rect, this);
		knh_RawPtr_t *p2 = new_RawPtrFromClass(MouseEvent, event);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(p1));
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

KRect::KRect(int x_, int y_, int width_, int height_)
{
	r = new QRect(x_, y_, width_, height_);
	x = x_;
	y = y_;
	width = width_;
	height = height_;
	isDrag = false;
	this->setRect(*r);
	mouse_press_func = NULL;
	mouse_release_func = NULL;
	mouse_move_func = NULL;
	setObjectName("KRect");
	setTag(GRect);
	se = NULL;
#ifdef K_USING_BOX2D
	isStatic = true;
#endif
}

KRect::~KRect(void)
{
	delete r;
	if (se != NULL)	delete se;
	if (body != NULL) {
		body->GetWorld()->DestroyBody(body);
	}
}

#ifdef K_USING_BOX2D

KRigidBody::KRigidBody()
{
	_rotation = 0.0f;
	density = 0.0f;
	friction = 0.0f;
	restitution = 0.0f;
}

void KRigidBody::setRot(qreal rotation)
{
	_rotation = rotation;
}

void KRigidBody::setDensity(qreal density_)
{
	density = density_;
	if (density_ > 0) {
		isStatic = false;
	} else {
		isStatic = true;
	}
}
void KRigidBody::setFriction(qreal friction_)
{
	friction = friction_;
}

void KRigidBody::setRestitution(qreal restitution_)
{
	restitution = restitution_;
}

void KRect::addToWorld(KWorld *w)
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
	shape.SetAsBox(width/2, height/2, b2Vec2(x + width/2, -y - height/2), 0.0);
	shapeDef.shape = &shape;
	shapeDef.density = density;
	shapeDef.friction = friction;
	shapeDef.restitution = restitution;
	body->CreateFixture(&shapeDef);

	//QGraphicsItem *i = dynamic_cast<QGraphicsItem *>(this);
	QGraphicsItem *i = (QGraphicsItem *)this;
	knh_GraphicsUserData_t *data = (knh_GraphicsUserData_t *)malloc(sizeof(knh_GraphicsUserData_t));
	memset(data, 0, sizeof(knh_GraphicsUserData_t));
	CTX lctx = knh_getCurrentContext();
	data->ct = getClassTBL(Rect);
	data->o = i;
	data->self = this;
	body->SetUserData(data);
}
#endif

KMETHOD Rect_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	int x = Int_to(int, sfp[1]);
	int y = Int_to(int, sfp[2]);
	int width = Int_to(int, sfp[3]);
	int height = Int_to(int, sfp[4]);
	KRect *r = new KRect(x, y, width, height);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, r, NULL);
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

KMETHOD Rect_isSTatic(CTX ctx, knh_sfp_t *sfp _RIX)
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
	r->mouse_press_func = fo;
	RETURNvoid_();
}

KMETHOD Rect_setMouseReleaseEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	KRect *r = RawPtr_to(KRect *, sfp[0]);
	knh_Func_t *fo = sfp[1].fo;
	r->mouse_release_func = fo;
	RETURNvoid_();
}

KMETHOD Rect_setMouseMoveEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	KRect *r = RawPtr_to(KRect *, sfp[0]);
	knh_Func_t *fo = sfp[1].fo;
	r->mouse_move_func = fo;
	RETURNvoid_();
}

#endif

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
	(void)ctx;
	(void)p;
	(void)tail_;
	if (p->rawptr != NULL) {
#ifdef DEBUG_MODE
		fprintf(stderr, "Rect:reftrace\n");
#endif
		KRect *r = (KRect *)p->rawptr;
		KNH_ADDREF(ctx, r->mouse_press_func);
		KNH_ADDREF(ctx, r->mouse_move_func);
		KNH_ADDREF(ctx, r->mouse_release_func);
	}
}

DEFAPI(void) defRect(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	NO_WARNING2();
	cdef->name = "Rect";
	cdef->free = Rect_free;
	cdef->reftrace = Rect_reftrace;
}

DEFAPI(void) constRect(CTX ctx, knh_class_t cid, const knh_PackageLoaderAPI_t *kapi)
{
	(void)ctx;
	(void)cid;
	(void)kapi;
	//kapi->loadIntClassConst(ctx, cid, TimeLineConstInt);
}

#ifdef __cplusplus
}
#endif
