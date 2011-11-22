#include <physics.hpp>

template<class T>
inline void dragConnect(QWorld *world, T o)
{
	QObject::connect(o->dummy->pkgconnector, SIGNAL(dragBeginSignal(QGraphicsSceneMouseEvent *)),
					 world, SLOT(dragBeginSlot(QGraphicsSceneMouseEvent *)));
	QObject::connect(o->dummy->pkgconnector, SIGNAL(dragMoveSignal(QGraphicsSceneMouseEvent *)),
					 world, SLOT(dragMoveSlot(QGraphicsSceneMouseEvent *)));
	QObject::connect(o->dummy->pkgconnector, SIGNAL(dragEndSignal(QGraphicsSceneMouseEvent *)),
					 world, SLOT(dragEndSlot(QGraphicsSceneMouseEvent *)));
}

#ifdef __cplusplus
extern "C" {
#endif

QContact::QContact(void)
{
	CTX lctx = knh_getCurrentContext();
	rect_body = new_RawPtrFromClass(lctx, QGraphicsRectItem, NULL);
	ellipse_body = new_RawPtrFromClass(lctx, QGraphicsEllipseItem, NULL);
	simple_text_body = new_RawPtrFromClass(lctx, QGraphicsSimpleTextItem, NULL);
	text_body = new_RawPtrFromClass(lctx, QGraphicsTextItem, NULL);
	pixmap_body = new_RawPtrFromClass(lctx, QGraphicsPixmapItem, NULL);
	begin_contact_event_func = NULL;
	end_contact_event_func = NULL;
}

knh_RawPtr_t *QContact::getRawPtrFromCID(knh_class_t cid)
{
	knh_RawPtr_t *ret = NULL;
	if (cid == CLASS_QGraphicsRectItem) {
		ret = rect_body;
	} else if (cid == CLASS_QGraphicsEllipseItem) {
		ret = ellipse_body;
	} else if (cid == CLASS_QGraphicsSimpleTextItem) {
		ret = simple_text_body;
	} else if (cid == CLASS_QGraphicsTextItem) {
		ret = text_body;
	} else if (cid == CLASS_QGraphicsPixmapItem) {
		ret = pixmap_body;
	} else {
	}
	return ret;
}

void QContact::BeginContact(b2Contact *contact)
{
	//fprintf(stderr, "CONTACT BEGIN\n");
	b2Fixture *a = contact->GetFixtureA();
	b2Fixture *b = contact->GetFixtureB();
	b2Body *abody = a->GetBody();
	b2Body *bbody = b->GetBody();
	KQData *data1 = static_cast<KQData *>(abody->GetUserData());
	KQData *data2 = static_cast<KQData *>(bbody->GetUserData());
	if (data1 != NULL && data2 != NULL && begin_contact_event_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		knh_RawPtr_t *body1 = getRawPtrFromCID(data1->cid);
		knh_RawPtr_t *body2 = getRawPtrFromCID(data2->cid);
		if (body1 != NULL && body2 != NULL) {
			body1->rawptr = data1->i;
			body2->rawptr = data2->i;
			KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(body1));
			KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(body2));
			knh_Func_invoke(lctx, begin_contact_event_func, lsfp, 2);
		}
	}
}

void QContact::EndContact(b2Contact *contact)
{
	//fprintf(stderr, "CONTACT END\n");
	b2Fixture *a = contact->GetFixtureA();
	b2Fixture *b = contact->GetFixtureB();
	b2Body *abody = a->GetBody();
	b2Body *bbody = b->GetBody();
	KQData *data1 = static_cast<KQData *>(abody->GetUserData());
	KQData *data2 = static_cast<KQData *>(bbody->GetUserData());
	if (data1 != NULL && data2 != NULL && end_contact_event_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		knh_RawPtr_t *body1 = getRawPtrFromCID(data1->cid);
		knh_RawPtr_t *body2 = getRawPtrFromCID(data2->cid);
		if (body1 != NULL && body2 != NULL) {
			body1->rawptr = data1->i;
			body2->rawptr = data2->i;
			KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(body1));
			KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(body2));
			knh_Func_invoke(lctx, end_contact_event_func, lsfp, 2);
		}
	}
}

void QContact::PreSolve(b2Contact *contact, const b2Manifold *oldManifold)
{
	//fprintf(stderr, "CONTACT PRE SOLVE\n");
	(void)contact;
	(void)oldManifold;
}

void QContact::PostSolve(b2Contact *contact, const b2ContactImpulse *impulse)
{
	//fprintf(stderr, "CONTACT POST SOLVE\n");
	(void)contact;
	(void)impulse;
}

QQueryCallback::QQueryCallback(const b2Vec2& point)
{
	m_point = point;
	m_fixture = NULL;
}

bool QQueryCallback::ReportFixture(b2Fixture* fixture)
{
	b2Body* body = fixture->GetBody();
	b2Vec2 pos = body->GetPosition();
	if (body->GetType() == b2_dynamicBody) {
		bool inside = fixture->TestPoint(m_point);
		if (inside) {
			m_fixture = fixture;
			return false;
		}
	}
	return true;
}

QWorld::QWorld(KQGraphicsScene *scene_)
{
	world = new b2World(b2Vec2(0.0f, 10.0f), true);
	world->SetContinuousPhysics(true);
	iteration = 10;
	timestep = 1.0f / 30.0f;
	timer_id = 0;

	b2BodyDef bodyDef;
	mouse_joint_body = world->CreateBody(&bodyDef);
	mouse_joint = NULL;
	scene = scene_;

	contact = new QContact();
	world->SetContactListener(contact);
//	connect(this, SIGNAL(emitUpdatePointSignal(QList<GamVectorIdx> *)),
//			wobble, SLOT(updatePoint(QList<GamVectorIdx> *)));
	//========================== for debug =============================//
	debugDraw = new GLDebugDraw(PTM_RATIO);
	world->SetDebugDraw(debugDraw);
	debugDraw->resize(600, 600);
	uint32 flags = 0;
	flags += b2DebugDraw::e_shapeBit;
	flags += b2DebugDraw::e_jointBit;
	flags += b2DebugDraw::e_aabbBit;
	flags += b2DebugDraw::e_pairBit;
	flags += b2DebugDraw::e_centerOfMassBit;
	debugDraw->SetFlags(flags);
	debugDraw->world = world;
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

void QWorld::dragBeginSlot(QGraphicsSceneMouseEvent *event)
{
	QPointF pos = event->scenePos();
	b2Vec2 p(pos.x()/PTM_RATIO, pos.y()/PTM_RATIO);
	b2AABB aabb;
	b2Vec2 d;
	d.Set(0.001f, 0.001f);
	aabb.lowerBound = p - d;
	aabb.upperBound = p + d;
	// Query the world for overlapping shapes.
	QQueryCallback callback(p);
	world->QueryAABB(&callback, aabb);
	if (callback.m_fixture) {
		b2Body* body = callback.m_fixture->GetBody();
		b2MouseJointDef md;
		md.bodyA = mouse_joint_body;
		md.bodyB = body;
		md.target = p;
		md.maxForce = 1000.0f * body->GetMass();
		mouse_joint = (b2MouseJoint*)world->CreateJoint(&md);
		body->SetAwake(true);
	}
}

void QWorld::dragMoveSlot(QGraphicsSceneMouseEvent *event)
{
	if (mouse_joint) {
		QPointF pos = event->scenePos();
		b2Vec2 p(pos.x()/PTM_RATIO, pos.y()/PTM_RATIO);
		mouse_joint->SetTarget(p);
	}
}

void QWorld::dragEndSlot(QGraphicsSceneMouseEvent *event)
{
	if (mouse_joint) {
		world->DestroyJoint(mouse_joint);
		mouse_joint = NULL;
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
	r->dummy->body = body;

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
	e->dummy->body = body;

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

void QGraphicsSimpleTextItem_addToWorld(KQGraphicsSimpleTextItem *t, QWorld *w)
{
	QPointF pos = t->pos();
	float x = pos.x();
	float y = pos.y();
	QFontMetrics metrics(t->font());
	QRect rect = metrics.tightBoundingRect(t->text());
	float width = rect.width();
	float height = rect.height();
	/* reset position for synchronization with box2d [anchor:center] */
	b2World *world = w->world;
	b2BodyDef bodyDef;
	if (!t->dummy->isStatic) {
		bodyDef.type = b2_dynamicBody;
	}
	QTransform trans;
	trans.translate(-width/2.0f, -height/2.0f-3);
	t->setTransform(trans);
	/* box2d's anchor point is center position */
	bodyDef.position.Set((x+width/2)/PTM_RATIO, (y+height/2)/PTM_RATIO);
	bodyDef.angle = -(t->rotation() * (2 * M_PI)) / 360.0;
	b2Body *body = world->CreateBody(&bodyDef);
	t->dummy->body = body;

	b2FixtureDef shapeDef;
	b2PolygonShape shape;
	shape.SetAsBox(width/2/PTM_RATIO, height/2/PTM_RATIO);
	shapeDef.shape = &shape;
	shapeDef.density = t->dummy->density;
	shapeDef.friction = t->dummy->friction;
	shapeDef.restitution = t->dummy->restitution;
	body->CreateFixture(&shapeDef);
	QGraphicsItem *i = dynamic_cast<QGraphicsItem *>(t);
	KQData *data = new KQData();
	data->cid = CLASS_QGraphicsTextItem;
	data->i = i;
	body->SetUserData(data);
}

void QGraphicsPixmapItem_addToWorld(KQGraphicsPixmapItem *p, QWorld *w)
{
	QPointF pos = p->pos();
	QPixmap pixmap = p->pixmap();
	QRect rect = pixmap.rect();
	float x = pos.x();
	float y = pos.y();
	float width = rect.width();
	float height = rect.height();
	/* reset position for synchronization with box2d [anchor:center] */
	p->setOffset(-width/2, -height/2);
	b2World *world = w->world;
	b2BodyDef bodyDef;
	if (!p->dummy->isStatic) {
		bodyDef.type = b2_dynamicBody;
	}
	/* box2d's anchor point is center position */
	bodyDef.position.Set(x/PTM_RATIO, y/PTM_RATIO);
	bodyDef.angle = -(p->rotation() * (2 * M_PI)) / 360.0;
	b2Body *body = world->CreateBody(&bodyDef);
	p->dummy->body = body;

	b2FixtureDef shapeDef;
	b2PolygonShape shape;
	shape.SetAsBox(width/2/PTM_RATIO, height/2/PTM_RATIO);
	shapeDef.shape = &shape;
	shapeDef.density = p->dummy->density;
	shapeDef.friction = p->dummy->friction;
	shapeDef.restitution = p->dummy->restitution;
	body->CreateFixture(&shapeDef);
	QGraphicsItem *i = dynamic_cast<QGraphicsItem *>(p);
	KQData *data = new KQData();
	data->cid = CLASS_QGraphicsTextItem;
	data->i = i;
	body->SetUserData(data);
}

void QWorld::add(knh_class_t cid, QGraphicsItem *i)
{
	if (cid == CLASS_QGraphicsRectItem) {
		QGraphicsRectItem_addToWorld((KQGraphicsRectItem *)i, this);
		dragConnect(this, (KQGraphicsRectItem *)i);
	} else if (cid == CLASS_QGraphicsEllipseItem) {
		QGraphicsEllipseItem_addToWorld((KQGraphicsEllipseItem *)i, this);
		dragConnect(this, (KQGraphicsEllipseItem *)i);
	} else if (cid == CLASS_QGraphicsSimpleTextItem) {
		QGraphicsSimpleTextItem_addToWorld((KQGraphicsSimpleTextItem *)i, this);
		dragConnect(this, (KQGraphicsSimpleTextItem *)i);
	} else if (cid == CLASS_QGraphicsPixmapItem) {
		QGraphicsPixmapItem_addToWorld((KQGraphicsPixmapItem *)i, this);
		dragConnect(this, (KQGraphicsPixmapItem *)i);
	} else if (cid == CLASS_QGraphicsItemGroup) {

	} else if (cid == CLASS_QGraphicsLineItem) {

	} else if (cid == CLASS_QDistanceJoint) {
		QDistanceJoint *j = (QDistanceJoint *)i;
		j->addToWorld(this);
	} else if (cid == CLASS_QRevoluteJoint) {
		QRevoluteJoint *j = (QRevoluteJoint *)i;
		j->addToWorld(this);
	} else if (cid == CLASS_QPrismaticJoint) {
		QPrismaticJoint *j = (QPrismaticJoint *)i;
		j->addToWorld(this);
	} else if (cid == CLASS_QPulleyJoint) {
		QPulleyJoint *j = (QPulleyJoint *)i;
		j->addToWorld(this);
	} else if (cid == CLASS_QGearJoint) {
		QGearJoint *j = (QGearJoint *)i;
		j->addToWorld(this);
	} else {
		fprintf(stderr, "QWorld add: [WARNING] UNNOWN OBJECT [%d]\n", cid);
	}
}

void QWorld::start(void)
{
	if (!timer_id) {
		timer_id = startTimer(1000 / 60.0f);
	}
}

static void QWorld_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		QWorld *w = static_cast<QWorld *>(p->rawptr);
		delete w;
		p->rawptr = NULL;
	}
}

static void QWorld_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		QWorld *w = static_cast<QWorld *>(p->rawptr);
		QContact *c = w->contact;
		KNH_ENSUREREF(ctx, 4);
		KNH_ADDNNREF(ctx, c->rect_body);
		KNH_ADDNNREF(ctx, c->ellipse_body);
		KNH_ADDNNREF(ctx, c->text_body);
		KNH_ADDNNREF(ctx, c->pixmap_body);
		KNH_SIZEREF(ctx);
	}
}

DEFAPI(void) defQWorld(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QWorld";
	cdef->free = QWorld_free;
	cdef->reftrace = QWorld_reftrace;
}

#ifdef __cplusplus
}
#endif
