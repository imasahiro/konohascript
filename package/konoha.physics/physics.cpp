#include <physics.hpp>

#ifdef __cplusplus
extern "C" {
#endif
static unsigned int CLASS_QGraphicsRectItem;
static unsigned int CLASS_QGraphicsEllipseItem;
static unsigned int CLASS_QGraphicsPixmapItem;
static unsigned int CLASS_QGraphicsTextItem;
static unsigned int CLASS_QGraphicsItemGroup;
static unsigned int CLASS_QGraphicsLineItem;

QWorld::QWorld(KQGraphicsScene *scene_)
{
	world = new b2World(b2Vec2(0.0f, 10.0f), true);
	world->SetContinuousPhysics(true);
	iteration = 10;
	timestep = 1.0f / 30.0f;
	timer_id = 0;

	//contact = new QContact();
	//world->SetContactListener(contact);
	b2BodyDef bodyDef;
	mouse_joint_body = world->CreateBody(&bodyDef);
	mouse_joint = NULL;
	scene = scene_;
	//GamWobble *wobble = new GamWobble(0);
	//scene_->wobble = wobble;
	//wobble->resize(600, 600);
	//wobble->show();
	/*
	connect(this, SIGNAL(emitUpdatePointSignal(QList<GamVectorIdx> *)),
			wobble, SLOT(updatePoint(QList<GamVectorIdx> *)));
	connect(contact, SIGNAL(emitBeginContactSignal(GamObject *, GamObject *)),
			this, SLOT(beginContactSlot(GamObject *, GamObject *)));
	connect(contact, SIGNAL(emitEndContactSignal(GamObject *, GamObject *)),
			this, SLOT(endContactSlot(GamObject *, GamObject *)));
	*/
	//========================== for debug =============================//
	//debugDraw = new GamGL(PTM_RATIO);
	//world->SetDebugDraw(debugDraw);
	//debugDraw->resize(600, 600);
	//uint32 flags = 0;
	//flags += b2DebugDraw::e_shapeBit;
	//flags += b2DebugDraw::e_jointBit;
	//flags += b2DebugDraw::e_aabbBit;
	//flags += b2DebugDraw::e_pairBit;
	//flags += b2DebugDraw::e_centerOfMassBit;
	//debugDraw->SetFlags(flags);
	//debugDraw->world = world;
	//connect(scene, SIGNAL(dragBeginSignal(QGraphicsSceneMouseEvent *)),
//			this, SLOT(dragBeginSlot(QGraphicsSceneMouseEvent *)));
	//connect(scene, SIGNAL(dragMoveSignal(QGraphicsSceneMouseEvent *)),
//			this, SLOT(dragMoveSlot(QGraphicsSceneMouseEvent *)));
	//connect(scene, SIGNAL(dragEndSignal(QGraphicsSceneMouseEvent *)),
	//	this, SLOT(dragEndSlot(QGraphicsSceneMouseEvent *)));
	//=================================================================//
}

void QWorld::timerEvent(QTimerEvent *event)
{
	if (event->timerId() == timer_id) {
		world->Step(timestep, 8, 1);
		//QList<GamVectorIdx> *vec_list = new QList<GamVectorIdx>();
		for (b2Body* b = world->GetBodyList(); b; b = b->GetNext()) {
			KQData *data = (KQData *)b->GetUserData();
			if (data) {
				b2Vec2 posA = b->GetPosition();
				QGraphicsItem *i = data->i;
				i->setPos(posA.x * PTM_RATIO, posA.y * PTM_RATIO);
//				if (data->tag() == GamComplexItemTag) {
//					i->setRotation(b->GetAngle() * 360.0 / (2 * M_PI));
//				} else {
				i->setRotation(-1 * b->GetAngle() * 360.0 / (2 * M_PI));
//				}
//				if (data->tag() == GamWobbleItemTag) {
//					wobbleEffect(data->idx, b, vec_list);
//					continue;
//				}
				b2JointEdge *jointList = b->GetJointList();
				if (jointList) {
					KQData *d = (KQData *)jointList->joint->GetUserData();
					b2Body *b2 = jointList->other;
					if (d) {
						if (jointList->joint->GetType() == e_pulleyJoint) {
							b2PulleyJoint *pulley = (b2PulleyJoint *)jointList->joint;
							b2Vec2 anchorA = pulley->GetAnchorA();
							b2Vec2 anchorB = pulley->GetAnchorB();
							b2Vec2 groundAnchorA = pulley->GetGroundAnchorA();
							b2Vec2 groundAnchorB = pulley->GetGroundAnchorB();
							QGraphicsPathItem *p = dynamic_cast<QGraphicsPathItem *>(d->i);
							QPainterPath path;
							path.moveTo(anchorA.x * PTM_RATIO, anchorA.y * PTM_RATIO);
							path.lineTo(groundAnchorA.x * PTM_RATIO, groundAnchorA.y * PTM_RATIO);
							path.lineTo(groundAnchorB.x * PTM_RATIO, groundAnchorB.y * PTM_RATIO);
							path.lineTo(anchorB.x * PTM_RATIO, anchorB.y * PTM_RATIO);
							p->setPath(path);
						} else {
							QGraphicsLineItem *line = dynamic_cast<QGraphicsLineItem *>(d->i);
							b2Vec2 posB = b2->GetPosition();
							line->setLine(posA.x * PTM_RATIO, posA.y * PTM_RATIO,
										  posB.x * PTM_RATIO, posB.y * PTM_RATIO);
						}
					}
				}
			}
		}
		//fprintf(stderr, "list-size = [%d]\n", vec_list->length());
		//fprintf(stderr, "================== emit ====================\n");
//		if (vec_list->length() > 0) {
//			emit emitUpdatePointSignal(vec_list);
//		}
//		if (wobble) {
//			//wobble->draw();
//		}
		//fprintf(stderr, "================== end ====================\n");
//		delete vec_list;
	}
}

void QWorld::setGravity(float x, float y)
{
	if (world) {
		world->SetGravity(b2Vec2(x, -y));
	}
}

static void QGraphicsRectItem_addToWorld(KQGraphicsRectItem *r, QWorld *w)
{
	QRectF rect = r->rect();
	int x = rect.x();
	int y = rect.y();
	int width = rect.width();
	int height = rect.height();
	r->setRect(-width/2, -height/2, width, height);
	b2World *world = w->world;
	b2BodyDef bodyDef;
	if (!r->dummy->isStatic) {
		bodyDef.type = b2_dynamicBody;
	}
	/* box2d's anchor point is center position */
	bodyDef.position.Set((x+width/2)/PTM_RATIO, (y+height/2)/PTM_RATIO);
	bodyDef.angle = -(r->rotation() * (2 * M_PI)) / 360.0;
	b2Body *body = world->CreateBody(&bodyDef);

	b2FixtureDef shapeDef;
	b2PolygonShape shape;
	/* box size is half size of original size */
	shape.SetAsBox(width/2/PTM_RATIO, height/2/PTM_RATIO);
	shapeDef.shape = &shape;
	shapeDef.density = r->dummy->density;
	shapeDef.friction = r->dummy->friction;
	shapeDef.restitution = r->dummy->restitution;
	body->CreateFixture(&shapeDef);
	body->SetBullet(r->dummy->bullet);
	QGraphicsItem *i = dynamic_cast<QGraphicsItem *>(r);
	KQData *data = new KQData();
	data->cid = CLASS_QGraphicsRectItem;
	data->i = i;
	body->SetUserData(data);
}

static void QGraphicsEllipseItem_addToWorld(KQGraphicsEllipseItem *e, QWorld *w)
{
	/* reset position for synchronization with box2d [anchor:center] */
	QRectF rect = e->rect();
	int x = rect.x();
	int y = rect.y();
	int width = rect.width();
	int height = rect.height();
	e->setRect(-width/2, -height/2, width, height);
	/*
	if (glow) {
		QColor c = *color;
		QRadialGradient radial(0, 0, width/2);
		QColor c1(c);
		c1.setAlpha(0xcc);
		QColor c2(c);
		c2.setAlpha(0x44);
		QColor c3(c);
		c3.setAlpha(0x11);
		radial.setColorAt(0.4, *glow_center_color);
		radial.setColorAt(0.8, c1);
		radial.setColorAt(1.0, c2);
		setBrush(radial);
	}
	*/
	b2World *world = w->world;
	b2BodyDef bodyDef;
	if (!e->dummy->isStatic) {
		bodyDef.type = b2_dynamicBody;
	}
	/* box2d's anchor point is center position */
	bodyDef.position.Set(x/PTM_RATIO, y/PTM_RATIO);
	bodyDef.angle = -(e->rotation() * (2 * M_PI)) / 360.0;
	b2Body *body = world->CreateBody(&bodyDef);

	b2FixtureDef shapeDef;
	b2CircleShape shape;
	shape.m_radius = width/2/PTM_RATIO;
	shapeDef.shape = &shape;
	shapeDef.density = e->dummy->density;
	shapeDef.friction = e->dummy->friction;
	shapeDef.restitution = e->dummy->restitution;
	body->CreateFixture(&shapeDef);
	QGraphicsItem *i = dynamic_cast<QGraphicsItem *>(e);
	KQData *data = new KQData();
	data->cid = CLASS_QGraphicsEllipseItem;
	data->i = i;
	body->SetUserData(data);
}

void QWorld::add(knh_class_t cid, QGraphicsItem *i)
{
	if (cid == CLASS_QGraphicsRectItem) {
		QGraphicsRectItem_addToWorld((KQGraphicsRectItem *)i, this);
	} else if (cid == CLASS_QGraphicsEllipseItem) {
		QGraphicsEllipseItem_addToWorld((KQGraphicsEllipseItem *)i, this);
	} else {
		fprintf(stderr, "World Add: [WARNING] UNNOWN OBJECT [%d]\n", cid);
	}
}

void QWorld::start(void)
{
	if (!timer_id) {
		timer_id = startTimer(1000 / 60.0f);
	}
}

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
	world->add(sfp[1].p->h.cTBL->cid, i);
}

KMETHOD QWorld_start(CTX ctx, knh_sfp_t *sfp _RIX)
{
	QWorld *world = RawPtr_to(QWorld *, sfp[0]);
	world->start();
}

DEFAPI(const knh_PackageDef_t*) init(CTX ctx, const knh_LoaderAPI_t *)
{
	CLASS_QGraphicsRectItem = (GET_CID(QGraphicsRectItem));
	CLASS_QGraphicsEllipseItem = GET_CID(QGraphicsEllipseItem);
	CLASS_QGraphicsPixmapItem = GET_CID(QGraphicsPixmapItem);
	CLASS_QGraphicsTextItem = GET_CID(QGraphicsTextItem);
	CLASS_QGraphicsItemGroup = GET_CID(QGraphicsItemGroup);
	CLASS_QGraphicsLineItem = GET_CID(QGraphicsLineItem);
	RETURN_PKGINFO("physics");
}

#ifdef __cplusplus
}
#endif
