#include <gwt.hpp>

#ifdef __cplusplus
extern "C" {
#endif

#ifdef K_USING_BOX2D

KWorld::KWorld(int width, int height)
{
	world = new b2World(b2Vec2(0.0f, -10.0f), true);
	iteration = 10;
	timestep = 1.0f / 30.0f;
	timer_id = 0;
	contact = new KContact();
	world->SetContactListener(contact);
}
	
void KWorld::start()
{
	if (!timer_id) {
		timer_id = startTimer(1000 / 60.0);
	}
}

#define addWorld(T, o) ((T)o)->addToWorld(this)

void KWorld::add(GObject *o)
{
	switch (o->tag()) {
	case GRect:
		addWorld(KRect *, o);
		break;
	case GEllipse:
		addWorld(KEllipse *, o);
		break;
	case GTexture:
		addWorld(KTexture *, o);
		break;
	case GText:
		addWorld(KText *, o);
		break;
	case GLine:
		addWorld(KLine *, o);
		break;
	case GComplexItem:
		addWorld(KComplexItem *, o);
		break;
	default:
		fprintf(stderr, "World: [WARNING] UNNOWN OBJECT\n");
		break;
	}
}

void KWorld::timerEvent(QTimerEvent *event)
{
	if (event->timerId() == timer_id) {
		world->Step(timestep, 8, 1);
		for (b2Body* b = world->GetBodyList(); b; b = b->GetNext())	{
			if (b->GetUserData() != NULL) {
				knh_GraphicsUserData_t *data = (knh_GraphicsUserData_t *)b->GetUserData();
				QGraphicsItem *i = (QGraphicsItem *)data->o;
				i->setPos(b->GetPosition().x, -b->GetPosition().y);
				i->setRotation(-1 * b->GetAngle() * 360.0 / (2 * M_PI));
			}
		}
	}
	QObject::timerEvent(event);
}

KMETHOD World_new(Ctx *ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	qsrand(time(0));
	int width = Int_to(int, sfp[1]);
	int height = Int_to(int, sfp[2]);
	KWorld *w = new KWorld(width, height);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, w, NULL);
	RETURN_(p);
}

KMETHOD World_add(Ctx *ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	KWorld *world = RawPtr_to(KWorld *, sfp[0]);
	GObject *o = GObject_to(sfp[1]);
	world->add(o);
	RETURNvoid_();
}

KMETHOD World_remove(Ctx *ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	KWorld *w = RawPtr_to(KWorld *, sfp[0]);
	QObject *o = RawPtr_to(QObject *, sfp[1]);
	QString name = o->objectName();
	b2World *world = w->world;
	if (name == "KRect") {
		KRect *r = RawPtr_to(KRect *, sfp[1]);
		b2Body *body = r->body;
		world->DestroyBody(body);
	} else if (name == "KEllipse") {
		KEllipse *e = RawPtr_to(KEllipse *, sfp[1]);
		b2Body *body = e->body;
		world->DestroyBody(body);
	} else if (name == "KTexture") {
		KTexture *t = RawPtr_to(KTexture *, sfp[1]);
		b2Body *body = t->body;
		world->DestroyBody(body);
	} else if (name == "KText") {
		KText *t = RawPtr_to(KText *, sfp[1]);
		b2Body *body = t->body;
		world->DestroyBody(body);
	} else if (name == "KLine") {
		KLine *l = RawPtr_to(KLine *, sfp[1]);
		b2Body *body = l->body;
		world->DestroyBody(body);
	} else if (name == "KComplexItem") {
		KComplexItem *c = RawPtr_to(KComplexItem *, sfp[1]);
		b2Body *body = c->body;
		world->DestroyBody(body);
	} else {
		fprintf(stderr, "World: [WARNING] UNNOWN OBJECT\n");
	}
	RETURNvoid_();
}

KMETHOD World_start(Ctx *ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	KWorld *w = RawPtr_to(KWorld *, sfp[0]);
	w->start();
	RETURNvoid_();
}

KMETHOD World_setGravity(Ctx *ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	KWorld *w = RawPtr_to(KWorld *, sfp[0]);
	float x = Float_to(float, sfp[1]);
	float y = Float_to(float, sfp[2]);
	if (w->world != NULL) {
		w->world->SetGravity(b2Vec2(x, y));
	}
	RETURNvoid_();
}

KMETHOD World_setBeginContactEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	KWorld *w = RawPtr_to(KWorld *, sfp[0]);
	knh_Func_t *f = sfp[1].fo;
	w->contact->begin = f;
	RETURNvoid_();
}

KMETHOD World_setEndContactEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	KWorld *w = RawPtr_to(KWorld *, sfp[0]);
	knh_Func_t *f = sfp[1].fo;
	w->contact->end = f;
	RETURNvoid_();
}

#endif

static void World_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL && O_cTBL(p)->total < 4) {
#ifdef DEBUG_MODE
		fprintf(stderr, "World:free\n");
#endif
		KWorld *w = (KWorld *)p->rawptr;
		delete w;
	}
}

static void World_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx;
	(void)p;
	(void)tail_;
	if (p->rawptr != NULL) {
#ifdef DEBUG_MODE
		fprintf(stderr, "World:reftrace\n");
#endif
	}
}

DEFAPI(void) defWorld(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	NO_WARNING2();
	cdef->name = "World";
	cdef->free = World_free;
	cdef->reftrace = World_reftrace;
}

DEFAPI(void) constWorld(CTX ctx, knh_class_t cid, const knh_PackageLoaderAPI_t *kapi)
{
	(void)ctx;
	(void)cid;
	(void)kapi;
	//kapi->loadIntClassConst(ctx, cid, TimeLineConstInt);
}

#ifdef __cplusplus
}
#endif
