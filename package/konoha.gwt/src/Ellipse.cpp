#include <gwt.hpp>

#ifdef __cplusplus
extern "C" {
#endif

KEllipse::KEllipse()
{
	setObjectName("KEllipse");
	isDrag = false;
	setTag(GEllipse);
#ifdef K_USING_BOX2D
	isStatic = true;
#endif
}

#ifdef K_USING_BOX2D
void KEllipse::addToWorld(KWorld *w)
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
	b2CircleShape shape;
	shape.m_p = b2Vec2(x + width / 2, -y - height / 2);
	shape.m_radius = width / 2;
	shapeDef.shape = &shape;
	shapeDef.density = density;
	shapeDef.friction = friction;
	shapeDef.restitution = restitution;
	body->CreateFixture(&shapeDef);

	QGraphicsItem *i = dynamic_cast<QGraphicsItem *>(this);
	knh_GraphicsUserData_t *data = (knh_GraphicsUserData_t *)malloc(sizeof(knh_GraphicsUserData_t));
	memset(data, 0, sizeof(knh_GraphicsUserData_t));
	CTX lctx = knh_getCurrentContext();
	data->ct = getClassTBL(Ellipse);
	data->o = i;
	body->SetUserData(data);
}

#endif

void KEllipse::setRectShape(KRect *r)
{
	setRect(*r->r);
	x = r->x;
	y = r->y;
	width = r->width;
	height = r->height;
}

KMETHOD Ellipse_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	KEllipse *e = new KEllipse();
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, e, NULL);
	RETURN_(p);
}

KMETHOD Ellipse_setRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	KEllipse *e = RawPtr_to(KEllipse *, sfp[0]);
	KRect *r = RawPtr_to(KRect *, sfp[1]);
	e->setRectShape(r);
	RETURNvoid_();
}

KMETHOD Ellipse_setColor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	KEllipse *e = RawPtr_to(KEllipse *, sfp[0]);
	QColor *c = RawPtr_to(QColor *, sfp[1]);
	e->setBrush(*c);
	RETURNvoid_();
}

KMETHOD Ellipse_setZValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	KEllipse *e = RawPtr_to(KEllipse *, sfp[0]);
	int val = Int_to(int, sfp[1]);
	e->setZValue(val);
	RETURNvoid_();
}

KMETHOD Ellipse_getZValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	KEllipse *e = RawPtr_to(KEllipse *, sfp[0]);
	RETURNi_(e->zValue());
}

#ifdef K_USING_BOX2D
KMETHOD Ellipse_setRotation(Ctx *ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	KEllipse *e = RawPtr_to(KEllipse *, sfp[0]);
	qreal rotation = Float_to(qreal, sfp[1]);
	e->setRotation(rotation);
	RETURNvoid_();
}

KMETHOD Ellipse_setDensity(Ctx *ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	KEllipse *e = RawPtr_to(KEllipse *, sfp[0]);
	qreal density = Float_to(qreal, sfp[1]);
	e->setDensity(density);
	RETURNvoid_();
}

KMETHOD Ellipse_setFriction(Ctx *ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	KEllipse *e = RawPtr_to(KEllipse *, sfp[0]);
	qreal friction = Float_to(qreal, sfp[1]);
	e->setFriction(friction);
	RETURNvoid_();
}

KMETHOD Ellipse_setRestitution(Ctx *ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	KEllipse *e = RawPtr_to(KEllipse *, sfp[0]);
	qreal restitution = Float_to(qreal, sfp[1]);
	e->setRestitution(restitution);
	RETURNvoid_();
}
#endif

static void Ellipse_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
#ifdef DEBUG_MODE
		fprintf(stderr, "Ellipse:free\n");
#endif
		KEllipse *e = (KEllipse *)p->rawptr;
		(void)e;
		//delete e;
	}
}

static void Ellipse_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx;
	(void)p;
	(void)tail_;
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

DEFAPI(void) constEllipse(CTX ctx, knh_class_t cid, const knh_PackageLoaderAPI_t *kapi)
{
	(void)ctx;
	(void)cid;
	(void)kapi;
	//kapi->loadIntClassConst(ctx, cid, TimeLineConstInt);
}

#ifdef __cplusplus
}
#endif
