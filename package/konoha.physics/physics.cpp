#include <physics.hpp>

unsigned int CLASS_QGraphicsRectItem;
unsigned int CLASS_QGraphicsEllipseItem;
unsigned int CLASS_QGraphicsPixmapItem;
unsigned int CLASS_QGraphicsTextItem;
unsigned int CLASS_QGraphicsSimpleTextItem;
unsigned int CLASS_QGraphicsItemGroup;
unsigned int CLASS_QGraphicsLineItem;
unsigned int CLASS_QGraphicsComplexItem;
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

KMETHOD QGraphicsItem_setDensity(CTX ctx, ksfp_t *sfp _RIX)
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

KMETHOD QGraphicsItem_applyForce(CTX ctx, ksfp_t *sfp _RIX)
{
	KQGraphicsItem *i = RawPtr_to(KQGraphicsItem *, sfp[0]);
	QPointF *force = RawPtr_to(QPointF *, sfp[1]);
	QPointF *pos = RawPtr_to(QPointF *, sfp[2]);
	if (i && i->dummy->body) {
		b2Body *body = static_cast<b2Body *>(i->dummy->body);
		body->ApplyForce(b2Vec2(force->x(), force->y()), b2Vec2(pos->x()/PTM_RATIO, pos->y()/PTM_RATIO));
	}
	RETURNvoid_();
}

KMETHOD QGraphicsItem_applyTorque(CTX ctx, ksfp_t *sfp _RIX)
{
	KQGraphicsItem *i = RawPtr_to(KQGraphicsItem *, sfp[0]);
	float torque = Float_to(float, sfp[1]);
	if (i && i->dummy->body) {
		b2Body *body = static_cast<b2Body *>(i->dummy->body);
		body->ApplyTorque(torque);
	}
	RETURNvoid_();
}

KMETHOD QGraphicsItem_setXForm(CTX ctx, ksfp_t *sfp _RIX)
{
	KQGraphicsItem *i = RawPtr_to(KQGraphicsItem *, sfp[0]);
	QPointF *pos = RawPtr_to(QPointF *, sfp[1]);
	float angle = Float_to(float, sfp[2]);
	if (i && i->dummy->body) {
		b2Body *body = static_cast<b2Body *>(i->dummy->body);
		body->SetTransform(b2Vec2(pos->x()/PTM_RATIO, pos->y()/PTM_RATIO), -1 * angle);
	}
	RETURNvoid_();
}

KMETHOD QGraphicsItem_getDensity(CTX ctx, ksfp_t *sfp _RIX)
{
	KQGraphicsItem *i = RawPtr_to(KQGraphicsItem *, sfp[0]);
	float ret = 0.0f;
	if (i) {
		ret = i->dummy->density;
	}
	RETURNf_(ret);
}

KMETHOD QGraphicsItem_setFriction(CTX ctx, ksfp_t *sfp _RIX)
{
	KQGraphicsItem *i = RawPtr_to(KQGraphicsItem *, sfp[0]);
	float friction = Float_to(float, sfp[1]);
	if (i) {
		i->dummy->friction = friction;
	}
	RETURNvoid_();
}

KMETHOD QGraphicsItem_getFriction(CTX ctx, ksfp_t *sfp _RIX)
{
	KQGraphicsItem *i = RawPtr_to(KQGraphicsItem *, sfp[0]);
	float ret = 0.0f;
	if (i) {
		ret = i->dummy->friction;
	}
	RETURNf_(ret);
}

KMETHOD QGraphicsItem_setRestitution(CTX ctx, ksfp_t *sfp _RIX)
{
	KQGraphicsItem *i = RawPtr_to(KQGraphicsItem *, sfp[0]);
	float restitution = Float_to(float, sfp[1]);
	if (i) {
		i->dummy->restitution = restitution;
	}
	RETURNvoid_();
}

KMETHOD QGraphicsItem_getRestitution(CTX ctx, ksfp_t *sfp _RIX)
{
	KQGraphicsItem *i = RawPtr_to(KQGraphicsItem *, sfp[0]);
	float ret = 0.0f;
	if (i) {
		ret = i->dummy->restitution;
	}
	RETURNf_(ret);
}

KMETHOD QGraphicsItem_setBullet(CTX ctx, ksfp_t *sfp _RIX)
{
	KQGraphicsItem *i = RawPtr_to(KQGraphicsItem *, sfp[0]);
	if (i) {
		bool bullet = Boolean_to(bool, sfp[1]);
		i->dummy->bullet = bullet;
	}
	RETURNvoid_();
}

KMETHOD QGraphicsItem_isBullet(CTX ctx, ksfp_t *sfp _RIX)
{
	KQGraphicsItem *i = RawPtr_to(KQGraphicsItem *, sfp[0]);
	bool ret = false;
	if (i->dummy->bullet) {
		ret = true;
	}
	RETURNb_(ret);
}

KMETHOD QGraphicsItem_setDraggable(CTX ctx, ksfp_t *sfp _RIX)
{
	KQGraphicsItem *i = RawPtr_to(KQGraphicsItem *, sfp[0]);
	if (i) {
		bool draggable = Boolean_to(bool, sfp[1]);
		i->dummy->draggable = draggable;
	}
	RETURNvoid_();
}

KMETHOD QGraphicsItem_isDraggable(CTX ctx, ksfp_t *sfp _RIX)
{
	KQGraphicsItem *i = RawPtr_to(KQGraphicsItem *, sfp[0]);
	bool ret = false;
	if (i->dummy->draggable) {
		ret = true;
	}
	RETURNb_(ret);
}

KMETHOD QGraphicsItem_isStatic(CTX ctx, ksfp_t *sfp _RIX)
{
	KQGraphicsItem *i = RawPtr_to(KQGraphicsItem *, sfp[0]);
	bool ret = false;
	if (i->dummy->isStatic) {
		ret = true;
	}
	RETURNb_(ret);
}

KMETHOD QGraphicsItem_setMassData(CTX ctx, ksfp_t *sfp _RIX)
{
	KQGraphicsItem *i = RawPtr_to(KQGraphicsItem *, sfp[0]);
	if (i) {
		b2MassData *mass = RawPtr_to(b2MassData *, sfp[1]);
		b2Body *body = static_cast<b2Body *>(i->dummy->body);
		body->SetMassData(mass);
	}
	RETURNvoid_();
}

KMETHOD QGraphicsItem_getMassData(CTX ctx, ksfp_t *sfp _RIX)
{
	KQGraphicsItem *i = RawPtr_to(KQGraphicsItem *, sfp[0]);
	if (i) {
		b2Body *body = static_cast<b2Body *>(i->dummy->body);
		b2MassData *data = new b2MassData();
		body->GetMassData(data);
		kRawPtr *p = new_ReturnCppObject(ctx, sfp, data, NULL);
		RETURN_(p);
	} else {
		RETURN_(KNH_NULL);
	}
}

KMETHOD QMassData_setMass(CTX ctx, ksfp_t *sfp _RIX)
{
	b2MassData *data = RawPtr_to(b2MassData *, sfp[0]);
	if (data) {
		float mass = Float_to(float, sfp[1]);
		data->mass = mass;
	}
	RETURNvoid_();
}

KMETHOD QMassData_getMass(CTX ctx, ksfp_t *sfp _RIX)
{
	b2MassData *data = RawPtr_to(b2MassData *, sfp[0]);
	float ret = 0.0f;
	if (data) {
		ret = data->mass;
	}
	RETURNf_(ret);
}

KMETHOD QMassData_setCenterPos(CTX ctx, ksfp_t *sfp _RIX)
{
	b2MassData *data = RawPtr_to(b2MassData *, sfp[0]);
	if (data) {
		QPointF *pos = RawPtr_to(QPointF *, sfp[1]);
		b2Vec2 p(pos->x() / PTM_RATIO, pos->y() / PTM_RATIO);
		data->center = p;
	}
	RETURNvoid_();
}

KMETHOD QMassData_getCenterPos(CTX ctx, ksfp_t *sfp _RIX)
{
	b2MassData *data = RawPtr_to(b2MassData *, sfp[0]);
	if (data) {
		b2Vec2 pos = data->center;
		QPointF *pos_ = new QPointF(pos.x * PTM_RATIO, pos.y * PTM_RATIO);
		kRawPtr *p = new_ReturnCppObject(ctx, sfp, pos_, NULL);
		RETURN_(p);
	}
	RETURN_(KNH_NULL);
}

KMETHOD QWorld_new(CTX ctx, ksfp_t *sfp _RIX)
{
	KQGraphicsScene *scene = RawPtr_to(KQGraphicsScene *, sfp[1]);
	QWorld *world = new QWorld(scene);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, world, NULL);
	RETURN_(p);
}

KMETHOD QWorld_setGravity(CTX ctx, ksfp_t *sfp _RIX)
{
	QWorld *world = RawPtr_to(QWorld *, sfp[0]);
	float x = Float_to(float, sfp[1]);
	float y = Float_to(float, sfp[2]);
	if (world) world->setGravity(x, y);
	RETURNvoid_();
}

KMETHOD QWorld_add(CTX ctx, ksfp_t *sfp _RIX)
{
	QWorld *world = RawPtr_to(QWorld *, sfp[0]);
	QGraphicsItem *i = RawPtr_to(QGraphicsItem *, sfp[1]);
	if (world) world->add(sfp[1].p->h.cTBL->cid, i);
	RETURNvoid_();
}

KMETHOD QWorld_remove(CTX ctx, ksfp_t *sfp _RIX)
{
	QWorld *world = RawPtr_to(QWorld *, sfp[0]);
	KQGraphicsItem *i = RawPtr_to(KQGraphicsItem *, sfp[1]);
	if (world) world->remove(i);
	RETURNvoid_();
}

KMETHOD QWorld_removeAll(CTX ctx, ksfp_t *sfp _RIX)
{
	QWorld *world = RawPtr_to(QWorld *, sfp[0]);
	if (world) world->removeAll();
	RETURNvoid_();
}

KMETHOD QWorld_start(CTX ctx, ksfp_t *sfp _RIX)
{
	QWorld *world = RawPtr_to(QWorld *, sfp[0]);
	if (world) world->start();
	RETURNvoid_();
}

KMETHOD QWorld_showDebugDraw(CTX ctx, ksfp_t *sfp _RIX)
{
	QWorld *world = RawPtr_to(QWorld *, sfp[0]);
	if (world) world->debugDraw->show();
	RETURNvoid_();
}

KMETHOD QWorld_addEvent(CTX ctx, ksfp_t *sfp _RIX)
{
	QWorld *world = RawPtr_to(QWorld *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	kFunc *callback_func = sfp[2].fo;
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

KMETHOD QDistanceJoint_new(CTX ctx, ksfp_t *sfp _RIX)
{
	KQGraphicsItem *o1 = RawPtr_to(KQGraphicsItem *, sfp[1]);
	KQGraphicsItem *o2 = RawPtr_to(KQGraphicsItem *, sfp[2]);
	QDistanceJoint *j = new QDistanceJoint(o1, o2);
	CLASS_QDistanceJoint = GET_CID(QDistanceJoint);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, j, NULL);
	RETURN_(p);
}

KMETHOD QDistanceJoint_setLocalAnchorA(CTX ctx, ksfp_t *sfp _RIX)
{
	QDistanceJoint *j = RawPtr_to(QDistanceJoint *, sfp[0]);
	QPointF *p = RawPtr_to(QPointF *, sfp[1]);
	if (j) j->setLocalAnchorA(*p);
	RETURNvoid_();
}

KMETHOD QDistanceJoint_setLocalAnchorB(CTX ctx, ksfp_t *sfp _RIX)
{
	QDistanceJoint *j = RawPtr_to(QDistanceJoint *, sfp[0]);
	QPointF *p = RawPtr_to(QPointF *, sfp[1]);
	if (j) j->setLocalAnchorB(*p);
	RETURNvoid_();
}

KMETHOD QDistanceJoint_setFrequencyHz(CTX ctx, ksfp_t *sfp _RIX)
{
	QDistanceJoint *j = RawPtr_to(QDistanceJoint *, sfp[0]);
	float f = Float_to(float, sfp[1]);
	if (j) j->setFrequencyHz(f);
	RETURNvoid_();
}

KMETHOD QDistanceJoint_setDampingRatio(CTX ctx, ksfp_t *sfp _RIX)
{
	QDistanceJoint *j = RawPtr_to(QDistanceJoint *, sfp[0]);
	float f = Float_to(float, sfp[1]);
	if (j) j->setDampingRatio(f);
	RETURNvoid_();
}

KMETHOD QDistanceJoint_setLength(CTX ctx, ksfp_t *sfp _RIX)
{
	QDistanceJoint *j = RawPtr_to(QDistanceJoint *, sfp[0]);
	float f = Float_to(float, sfp[1]);
	if (j) j->setLength(f);
	RETURNvoid_();
}

KMETHOD QDistanceJoint_getFrequencyHz(CTX ctx, ksfp_t *sfp _RIX)
{
	QDistanceJoint *j = RawPtr_to(QDistanceJoint *, sfp[0]);
	float ret = 0.0f;
	if (j) {
		ret = j->getFrequencyHz();
	}
	RETURNf_(ret);
}

KMETHOD QDistanceJoint_getDampingRatio(CTX ctx, ksfp_t *sfp _RIX)
{
	QDistanceJoint *j = RawPtr_to(QDistanceJoint *, sfp[0]);
	float ret = 0.0f;
	if (j) {
		ret = j->getDampingRatio();
	}
	RETURNf_(ret);
}

KMETHOD QDistanceJoint_getLength(CTX ctx, ksfp_t *sfp _RIX)
{
	QDistanceJoint *j = RawPtr_to(QDistanceJoint *, sfp[0]);
	float ret = 0.0f;
	if (j) {
		ret = j->getLength();
	}
	RETURNf_(ret);
}

KMETHOD QRevoluteJoint_new(CTX ctx, ksfp_t *sfp _RIX)
{
	KQGraphicsItem *o1 = RawPtr_to(KQGraphicsItem *, sfp[1]);
	KQGraphicsItem *o2 = RawPtr_to(KQGraphicsItem *, sfp[2]);
	QRevoluteJoint *j = new QRevoluteJoint(o1, o2);
	CLASS_QRevoluteJoint = GET_CID(QRevoluteJoint);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, j, NULL);
	RETURN_(p);
}

KMETHOD QPrismaticJoint_new(CTX ctx, ksfp_t *sfp _RIX)
{
	KQGraphicsItem *o1 = RawPtr_to(KQGraphicsItem *, sfp[1]);
	KQGraphicsItem *o2 = RawPtr_to(KQGraphicsItem *, sfp[2]);
	QPrismaticJoint *j = new QPrismaticJoint(o1, o2);
	CLASS_QPrismaticJoint = GET_CID(QPrismaticJoint);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, j, NULL);
	RETURN_(p);
}

KMETHOD QPulleyJoint_new(CTX ctx, ksfp_t *sfp _RIX)
{
	KQGraphicsItem *o1 = RawPtr_to(KQGraphicsItem *, sfp[1]);
	QPointF *p1 = RawPtr_to(QPointF *, sfp[2]);
	KQGraphicsItem *o2 = RawPtr_to(KQGraphicsItem *, sfp[3]);
	QPointF *p2 = RawPtr_to(QPointF *, sfp[4]);
	QPulleyJoint *j = new QPulleyJoint(o1, *p1, o2, *p2);
	CLASS_QPulleyJoint = GET_CID(QPulleyJoint);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, j, NULL);
	RETURN_(p);
}

KMETHOD QGearJoint_new(CTX ctx, ksfp_t *sfp _RIX)
{
	KQGraphicsItem *o1 = RawPtr_to(KQGraphicsItem *, sfp[1]);
	QJoint *j1 = RawPtr_to(QJoint *, sfp[2]);
	KQGraphicsItem *o2 = RawPtr_to(KQGraphicsItem *, sfp[3]);
	QJoint *j2 = RawPtr_to(QJoint *, sfp[4]);
	QGearJoint *j = new QGearJoint(o1, j1, o2, j2);
	CLASS_QGearJoint = GET_CID(QGearJoint);
	kRawPtr *p = new_ReturnCppObject(ctx, sfp, j, NULL);
	RETURN_(p);
}

KMETHOD QGraphicsComplexItem_new(CTX ctx, ksfp_t *sfp _RIX)
{
	CLASS_QGraphicsComplexItem = GET_CID(QGraphicsComplexItem);
	kArray *a = sfp[1].a;
	size_t size = knh_Array_size(a);
	if (size < 3) {
		RETURN_(KNH_NULL);
	} else {
		QList<QPointF> pts;
		for (size_t i = 0; i < size; i++) {
			kRawPtr *p = (kRawPtr *)a->list[i];
			QPointF *pt = static_cast<QPointF *>(p->rawptr);
			pts << *pt;
		}
		QGraphicsComplexItem *i = new QGraphicsComplexItem(pts);
		kRawPtr *p = new_ReturnCppObject(ctx, sfp, i, NULL);
		i->setSelf(p);
		RETURN_(p);
	}
}

KMETHOD QGraphicsComplexItem_setBrush(CTX ctx, ksfp_t *sfp _RIX)
{
	QGraphicsComplexItem *i = RawPtr_to(QGraphicsComplexItem *, sfp[0]);
	QBrush *b = RawPtr_to(QBrush *, sfp[1]);
	if (i) i->setBrush(*b);
	RETURNvoid_();
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
