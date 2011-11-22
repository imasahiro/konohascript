#include <physics.hpp>

unsigned int CLASS_QGraphicsRectItem;
unsigned int CLASS_QGraphicsEllipseItem;
unsigned int CLASS_QGraphicsPixmapItem;
unsigned int CLASS_QGraphicsTextItem;
unsigned int CLASS_QGraphicsSimpleTextItem;
unsigned int CLASS_QGraphicsItemGroup;
unsigned int CLASS_QGraphicsLineItem;
unsigned int CLASS_QDistanceJoint;
unsigned int CLASS_QRevoluteJoint;
unsigned int CLASS_QPrismaticJoint;
unsigned int CLASS_QPulleyJoint;
unsigned int CLASS_QGearJoint;

static bool match(const char *a, const char *b)
{
	bool ret = false;
	if (!strncmp(a, b, strlen(a)) && strlen(a) == strlen(b)) {
		ret = true;
	}
	return ret;
}

#ifdef __cplusplus
extern "C" {
#endif

KMETHOD QGraphicsItem_setDensity(CTX ctx, knh_sfp_t *sfp _RIX)
{
	KQGraphicsItem *i = RawPtr_to(KQGraphicsItem *, sfp[0]);
	float density = Float_to(float, sfp[1]);
	if (i) {
		i->dummy->density = density;
		if (density > 0) {
			i->dummy->isStatic = false;
		}
	}
	RETURNvoid_();
}

KMETHOD QGraphicsItem_getDensity(CTX ctx, knh_sfp_t *sfp _RIX)
{
	KQGraphicsItem *i = RawPtr_to(KQGraphicsItem *, sfp[0]);
	float ret = 0.0f;
	if (i) {
		ret = i->dummy->density;
	}
	RETURNf_(ret);
}

KMETHOD QGraphicsItem_setFriction(CTX ctx, knh_sfp_t *sfp _RIX)
{
	KQGraphicsItem *i = RawPtr_to(KQGraphicsItem *, sfp[0]);
	float friction = Float_to(float, sfp[1]);
	if (i) {
		i->dummy->friction = friction;
	}
	RETURNvoid_();
}

KMETHOD QGraphicsItem_getFriction(CTX ctx, knh_sfp_t *sfp _RIX)
{
	KQGraphicsItem *i = RawPtr_to(KQGraphicsItem *, sfp[0]);
	float ret = 0.0f;
	if (i) {
		ret = i->dummy->friction;
	}
	RETURNf_(ret);
}

KMETHOD QGraphicsItem_setRestitution(CTX ctx, knh_sfp_t *sfp _RIX)
{
	KQGraphicsItem *i = RawPtr_to(KQGraphicsItem *, sfp[0]);
	float restitution = Float_to(float, sfp[1]);
	if (i) {
		i->dummy->restitution = restitution;
	}
	RETURNvoid_();
}

KMETHOD QGraphicsItem_getRestitution(CTX ctx, knh_sfp_t *sfp _RIX)
{
	KQGraphicsItem *i = RawPtr_to(KQGraphicsItem *, sfp[0]);
	float ret = 0.0f;
	if (i) {
		ret = i->dummy->restitution;
	}
	RETURNf_(ret);
}

KMETHOD QGraphicsItem_setBullet(CTX ctx, knh_sfp_t *sfp _RIX)
{
	KQGraphicsItem *i = RawPtr_to(KQGraphicsItem *, sfp[0]);
	if (i) {
		bool bullet = Boolean_to(bool, sfp[1]);
		i->dummy->bullet = bullet;
	}
	RETURNvoid_();
}

KMETHOD QGraphicsItem_isBullet(CTX ctx, knh_sfp_t *sfp _RIX)
{
	KQGraphicsItem *i = RawPtr_to(KQGraphicsItem *, sfp[0]);
	bool ret = false;
	if (i->dummy->bullet) {
		ret = true;
	}
	RETURNb_(ret);
}

KMETHOD QGraphicsItem_setDraggable(CTX ctx, knh_sfp_t *sfp _RIX)
{
	KQGraphicsItem *i = RawPtr_to(KQGraphicsItem *, sfp[0]);
	if (i) {
		bool draggable = Boolean_to(bool, sfp[1]);
		i->dummy->draggable = draggable;
	}
	RETURNvoid_();
}

KMETHOD QGraphicsItem_isDraggable(CTX ctx, knh_sfp_t *sfp _RIX)
{
	KQGraphicsItem *i = RawPtr_to(KQGraphicsItem *, sfp[0]);
	bool ret = false;
	if (i->dummy->draggable) {
		ret = true;
	}
	RETURNb_(ret);
}

KMETHOD QGraphicsItem_isStatic(CTX ctx, knh_sfp_t *sfp _RIX)
{
	KQGraphicsItem *i = RawPtr_to(KQGraphicsItem *, sfp[0]);
	bool ret = false;
	if (i->dummy->isStatic) {
		ret = true;
	}
	RETURNb_(ret);
}

KMETHOD QWorld_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	KQGraphicsScene *scene = RawPtr_to(KQGraphicsScene *, sfp[1]);
	QWorld *world = new QWorld(scene);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, world, NULL);
	RETURN_(p);
}

KMETHOD QWorld_add(CTX ctx, knh_sfp_t *sfp _RIX)
{
	QWorld *world = RawPtr_to(QWorld *, sfp[0]);
	QGraphicsItem *i = RawPtr_to(QGraphicsItem *, sfp[1]);
	if (world) world->add(sfp[1].p->h.cTBL->cid, i);
	RETURNvoid_();
}

KMETHOD QWorld_start(CTX ctx, knh_sfp_t *sfp _RIX)
{
	QWorld *world = RawPtr_to(QWorld *, sfp[0]);
	if (world) world->start();
	RETURNvoid_();
}

KMETHOD QWorld_showDebugDraw(CTX ctx, knh_sfp_t *sfp _RIX)
{
	QWorld *world = RawPtr_to(QWorld *, sfp[0]);
	if (world) world->debugDraw->show();
	RETURNvoid_();
}

KMETHOD QWorld_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	QWorld *world = RawPtr_to(QWorld *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (world) {
		if (match(event_name, "begin-contact-event")) {
			world->contact->begin_contact_event_func = callback_func;
		} else if (match(event_name, "end-contact-event")) {
			world->contact->end_contact_event_func = callback_func;
		} else {
			fprintf(stderr, "WARNING:[QWorld]unknown event name [%s]\n", event_name);
		}
	}
	RETURNvoid_();
}

KMETHOD QDistanceJoint_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	KQGraphicsItem *o1 = RawPtr_to(KQGraphicsItem *, sfp[1]);
	KQGraphicsItem *o2 = RawPtr_to(KQGraphicsItem *, sfp[2]);
	QDistanceJoint *j = new QDistanceJoint(o1, o2);
	CLASS_QDistanceJoint = GET_CID(QDistanceJoint);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, j, NULL);
	RETURN_(p);
}

KMETHOD QDistanceJoint_setLocalAnchorA(CTX ctx, knh_sfp_t *sfp _RIX)
{
	QDistanceJoint *j = RawPtr_to(QDistanceJoint *, sfp[0]);
	QPointF *p = RawPtr_to(QPointF *, sfp[1]);
	if (j) j->setLocalAnchorA(*p);
	RETURNvoid_();
}

KMETHOD QDistanceJoint_setLocalAnchorB(CTX ctx, knh_sfp_t *sfp _RIX)
{
	QDistanceJoint *j = RawPtr_to(QDistanceJoint *, sfp[0]);
	QPointF *p = RawPtr_to(QPointF *, sfp[1]);
	if (j) j->setLocalAnchorB(*p);
	RETURNvoid_();
}

KMETHOD QDistanceJoint_setFrequencyHz(CTX ctx, knh_sfp_t *sfp _RIX)
{
	QDistanceJoint *j = RawPtr_to(QDistanceJoint *, sfp[0]);
	float f = Float_to(float, sfp[1]);
	if (j) j->setFrequencyHz(f);
	RETURNvoid_();
}

KMETHOD QDistanceJoint_setDampingRatio(CTX ctx, knh_sfp_t *sfp _RIX)
{
	QDistanceJoint *j = RawPtr_to(QDistanceJoint *, sfp[0]);
	float f = Float_to(float, sfp[1]);
	if (j) j->setDampingRatio(f);
	RETURNvoid_();
}

KMETHOD QDistanceJoint_setLength(CTX ctx, knh_sfp_t *sfp _RIX)
{
	QDistanceJoint *j = RawPtr_to(QDistanceJoint *, sfp[0]);
	float f = Float_to(float, sfp[1]);
	if (j) j->setLength(f);
	RETURNvoid_();
}

KMETHOD QDistanceJoint_getFrequencyHz(CTX ctx, knh_sfp_t *sfp _RIX)
{
	QDistanceJoint *j = RawPtr_to(QDistanceJoint *, sfp[0]);
	float ret = 0.0f;
	if (j) {
		ret = j->getFrequencyHz();
	}
	RETURNf_(ret);
}

KMETHOD QDistanceJoint_getDampingRatio(CTX ctx, knh_sfp_t *sfp _RIX)
{
	QDistanceJoint *j = RawPtr_to(QDistanceJoint *, sfp[0]);
	float ret = 0.0f;
	if (j) {
		ret = j->getDampingRatio();
	}
	RETURNf_(ret);
}

KMETHOD QDistanceJoint_getLength(CTX ctx, knh_sfp_t *sfp _RIX)
{
	QDistanceJoint *j = RawPtr_to(QDistanceJoint *, sfp[0]);
	float ret = 0.0f;
	if (j) {
		ret = j->getLength();
	}
	RETURNf_(ret);
}

KMETHOD QRevoluteJoint_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	KQGraphicsItem *o1 = RawPtr_to(KQGraphicsItem *, sfp[1]);
	KQGraphicsItem *o2 = RawPtr_to(KQGraphicsItem *, sfp[2]);
	QRevoluteJoint *j = new QRevoluteJoint(o1, o2);
	CLASS_QRevoluteJoint = GET_CID(QRevoluteJoint);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, j, NULL);
	RETURN_(p);
}

KMETHOD QPrismaticJoint_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	KQGraphicsItem *o1 = RawPtr_to(KQGraphicsItem *, sfp[1]);
	KQGraphicsItem *o2 = RawPtr_to(KQGraphicsItem *, sfp[2]);
	QPrismaticJoint *j = new QPrismaticJoint(o1, o2);
	CLASS_QPrismaticJoint = GET_CID(QPrismaticJoint);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, j, NULL);
	RETURN_(p);
}

KMETHOD QPulleyJoint_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	KQGraphicsItem *o1 = RawPtr_to(KQGraphicsItem *, sfp[1]);
	QPointF *p1 = RawPtr_to(QPointF *, sfp[2]);
	KQGraphicsItem *o2 = RawPtr_to(KQGraphicsItem *, sfp[3]);
	QPointF *p2 = RawPtr_to(QPointF *, sfp[4]);
	QPulleyJoint *j = new QPulleyJoint(o1, *p1, o2, *p2);
	CLASS_QPulleyJoint = GET_CID(QPulleyJoint);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, j, NULL);
	RETURN_(p);
}

KMETHOD QGearJoint_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	KQGraphicsItem *o1 = RawPtr_to(KQGraphicsItem *, sfp[1]);
	QJoint *j1 = RawPtr_to(QJoint *, sfp[2]);
	KQGraphicsItem *o2 = RawPtr_to(KQGraphicsItem *, sfp[3]);
	QJoint *j2 = RawPtr_to(QJoint *, sfp[4]);
	QGearJoint *j = new QGearJoint(o1, j1, o2, j2);
	CLASS_QGearJoint = GET_CID(QGearJoint);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, j, NULL);
	RETURN_(p);
}

DEFAPI(const knh_PackageDef_t*) init(CTX ctx, const knh_LoaderAPI_t *)
{
	CLASS_QGraphicsRectItem = GET_CID(QGraphicsRectItem);
	CLASS_QGraphicsEllipseItem = GET_CID(QGraphicsEllipseItem);
	CLASS_QGraphicsPixmapItem = GET_CID(QGraphicsPixmapItem);
	CLASS_QGraphicsSimpleTextItem = GET_CID(QGraphicsSimpleTextItem);
	CLASS_QGraphicsTextItem = GET_CID(QGraphicsTextItem);
	CLASS_QGraphicsItemGroup = GET_CID(QGraphicsItemGroup);
	CLASS_QGraphicsLineItem = GET_CID(QGraphicsLineItem);
	RETURN_PKGINFO("physics");
}

#ifdef __cplusplus
}
#endif
