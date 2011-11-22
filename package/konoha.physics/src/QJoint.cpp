#include <physics.hpp>

#ifdef __cplusplus
extern "C" {
#endif

//========================================= QDistanceJoint ==============================================
#define GET_DISTANCE_(x, y) sqrt((x) * (x) + (y) * (y))
#define GET_DISTANCE(posA, posB) GET_DISTANCE_(posA.x - posA.y, posB.x - posB.y)

QDistanceJoint::QDistanceJoint(KQGraphicsItem *o1, KQGraphicsItem *o2)
{
	b2Body *bodyA = static_cast<b2Body *>(o1->dummy->body);
	b2Body *bodyB = static_cast<b2Body *>(o2->dummy->body);
	if (bodyA == NULL || bodyB == NULL) {
		fprintf(stderr, "QDistanceJoint: ERROR!!, Please call QWorld.add(QGraphicsItem) previously.\n");
		return;
	}
	b2Vec2 posA = bodyA->GetPosition();
	b2Vec2 posB = bodyB->GetPosition();
#ifdef DEBUG_MODE
	fprintf(stderr, "QDistanceJoint: bodyA = (%f, %f) : bodyB = (%f, %f)\n", posA.x, posA.y, posB.x, posB.y);
#endif
	Initialize(bodyA, bodyB, posA, posB);
	setLine(posA.x * PTM_RATIO, posA.y * PTM_RATIO, posB.x * PTM_RATIO, posB.y * PTM_RATIO);
	collideConnected = true;
	frequencyHz = 4.0f;
	dampingRatio = 0.5f;
	float distance = GET_DISTANCE(posA, posB);
	length = distance;
}

void QDistanceJoint::setLocalAnchorA(const QPointF &p)
{
	localAnchorA = b2Vec2(p.x()/PTM_RATIO, p.y()/PTM_RATIO);
}

void QDistanceJoint::setLocalAnchorB(const QPointF &p)
{
	localAnchorB = b2Vec2(p.x()/PTM_RATIO, p.y()/PTM_RATIO);
}

void QDistanceJoint::setFrequencyHz(float frequency)
{
	frequencyHz = frequency;
}

void QDistanceJoint::setDampingRatio(float ratio)
{
	dampingRatio = ratio;
}

void QDistanceJoint::setLength(float length_)
{
	length = length_ / PTM_RATIO;
}

float QDistanceJoint::getFrequencyHz(void)
{
	return frequencyHz;
}

float QDistanceJoint::getDampingRatio(void)
{
	return dampingRatio;
}

float QDistanceJoint::getLength(void)
{
	return length * PTM_RATIO;
}

void QDistanceJoint::setCollideConnected(bool b)
{
	collideConnected = b;
}

void QDistanceJoint::addToWorld(QWorld *w)
{
	b2World *world = w->world;
	b2DistanceJoint *j = (b2DistanceJoint *)world->CreateJoint(this);
	joint = j;
	KQData *data = new KQData();
	QGraphicsLineItem *i = dynamic_cast<QGraphicsLineItem *>(this);
	data->i = i;
	data->cid = CLASS_QDistanceJoint;
	joint->SetUserData(data);
}

//========================================= QRevoluteJoint ===============================================//
#define DEGREE_TO_RADIAN(deg) deg * 2 * M_PI / 360.0f

QRevoluteJoint::QRevoluteJoint(KQGraphicsItem *o1, KQGraphicsItem *o2)
{
	b2Body *bodyA = static_cast<b2Body *>(o1->dummy->body);
	b2Body *bodyB = static_cast<b2Body *>(o2->dummy->body);
	if (bodyA == NULL || bodyB == NULL) {
		fprintf(stderr, "QRevoluteJoint: ERROR!!, Please call QWorld.add(QGraphicsItem) previously.\n");
		return;
	}
	b2Vec2 posA = bodyA->GetPosition();
	b2Vec2 posB = bodyB->GetPosition();
#ifdef DEBUG_MODE
	fprintf(stderr, "QRevoluteJoint: bodyA = (%f, %f) : bodyB = (%f, %f)\n", posA.x, posA.y, posB.x, posB.y);
#endif
	Initialize(bodyA, bodyB, posA);
	setLine(posA.x * PTM_RATIO, posA.y * PTM_RATIO, posB.x * PTM_RATIO, posB.y * PTM_RATIO);
	lowerAngle = DEGREE_TO_RADIAN(-90);
	upperAngle = DEGREE_TO_RADIAN(45);
	enableLimit = true;
	maxMotorTorque = 10.0f;
	motorSpeed = 0.0f;
	enableMotor = true;
}

void QRevoluteJoint::setLocalAnchorA(const QPointF &p)
{
	localAnchorA = b2Vec2(p.x()/PTM_RATIO, p.y()/PTM_RATIO);
}

void QRevoluteJoint::setLocalAnchorB(const QPointF &p)
{
	localAnchorB = b2Vec2(p.x()/PTM_RATIO, p.y()/PTM_RATIO);
}

void QRevoluteJoint::setLowerAngle(float degree_angle)
{
	lowerAngle = DEGREE_TO_RADIAN(degree_angle);
}

void QRevoluteJoint::setUpperAngle(float degree_angle)
{
	upperAngle = DEGREE_TO_RADIAN(degree_angle);
}

void QRevoluteJoint::setEnableLimit(bool b)
{
	enableLimit = b;
}

void QRevoluteJoint::setMaxMotorTorque(float torque)
{
	maxMotorTorque = torque;
}

void QRevoluteJoint::setMotorSpeed(float speed)
{
	motorSpeed = speed;
}

void QRevoluteJoint::setEnableMotor(bool b)
{
	enableMotor = b;
}

void QRevoluteJoint::addToWorld(QWorld *w)
{
	b2World *world = w->world;
	b2RevoluteJoint *j = (b2RevoluteJoint *)world->CreateJoint(this);
	joint = j;
	KQData *data = new KQData();
	QGraphicsLineItem *i = dynamic_cast<QGraphicsLineItem *>(this);
	data->i = i;
	data->cid = CLASS_QRevoluteJoint;
	joint->SetUserData(data);
}

//======================================= QPrismaticJoint ===============================================//
QPrismaticJoint::QPrismaticJoint(KQGraphicsItem *o1, KQGraphicsItem *o2)
{
	b2Body *bodyA = static_cast<b2Body *>(o1->dummy->body);
	b2Body *bodyB = static_cast<b2Body *>(o2->dummy->body);
	if (bodyA == NULL || bodyB == NULL) {
		fprintf(stderr, "QPrismaticJoint: ERROR!!, Please call QWorld.add(QGraphicsItem) previously.\n");
		return;
	}
	b2Vec2 posA = bodyA->GetPosition();
	b2Vec2 posB = bodyB->GetPosition();
#ifdef DEBUG_MODE
	fprintf(stderr, "QPrismaticJoint: bodyA = (%f, %f) : bodyB = (%f, %f)\n", posA.x, posA.y, posB.x, posB.y);
#endif
	b2Vec2 worldAxis(1.0f, 0.0f);
	Initialize(bodyA, bodyB, posA, worldAxis);
	lowerTranslation = -5.0f;
	upperTranslation = 2.5f;
	enableLimit = true;
	maxMotorForce = 1.0f;
	motorSpeed = 0.0f;
	enableMotor = true;
	setLine(posA.x * PTM_RATIO, posA.y * PTM_RATIO, posB.x * PTM_RATIO, posB.y * PTM_RATIO);
}

void QPrismaticJoint::setLowerTranslation(float translation)
{
	lowerTranslation = translation;
}

void QPrismaticJoint::setUpperTranslation(float translation)
{
	upperTranslation = translation;
}

void QPrismaticJoint::setEnableLimit(bool b)
{
	enableLimit = b;
}

void QPrismaticJoint::setMaxMotorForce(float force)
{
	maxMotorForce = force;
}

void QPrismaticJoint::setMotorSpeed(float speed)
{
	motorSpeed = speed;
}

void QPrismaticJoint::setEnableMotor(bool b)
{
	enableMotor = b;
}

void QPrismaticJoint::addToWorld(QWorld *w)
{
	b2World *world = w->world;
	b2PrismaticJoint *j = (b2PrismaticJoint *)world->CreateJoint(this);
	joint = j;
	KQData *data = new KQData();
	QGraphicsLineItem *i = dynamic_cast<QGraphicsLineItem *>(this);
	data->i = i;
	data->cid = CLASS_QPrismaticJoint;
	joint->SetUserData(data);
}

//========================================== QPulleyJoint ===============================================//
QPulleyJoint::QPulleyJoint(KQGraphicsItem *o1, const QPointF &p1, KQGraphicsItem *o2, const QPointF &p2)
{
	b2Body *bodyA = static_cast<b2Body *>(o1->dummy->body);
	b2Body *bodyB = static_cast<b2Body *>(o2->dummy->body);
	if (bodyA == NULL || bodyB == NULL) {
		fprintf(stderr, "QPulleyJoint: ERROR!!, Please call QWorld.add(QGraphicsItem) previously.\n");
		return;
	}
	b2Vec2 posA = bodyA->GetPosition();
	b2Vec2 posB = bodyB->GetPosition();
#ifdef DEBUG_MODE
	fprintf(stderr, "QPulleyJoint: bodyA = (%f, %f) : bodyB = (%f, %f)\n", posA.x, posA.y, posB.x, posB.y);
#endif
	b2Vec2 anchorA = posA;
	b2Vec2 anchorB = posB;
	b2Vec2 groundAnchorA(p1.x()/PTM_RATIO, p1.y()/PTM_RATIO);
	b2Vec2 groundAnchorB(p2.x()/PTM_RATIO, p2.y()/PTM_RATIO);
	float32 ratio = 1.0f;
	Initialize(bodyA, bodyB, groundAnchorA, groundAnchorB, anchorA, anchorB, ratio);
	QPainterPath path;
	path.moveTo(posA.x * PTM_RATIO, posA.y * PTM_RATIO);
	path.lineTo(p1.x(), p1.y());
	path.lineTo(p2.x(), p2.y());
	path.lineTo(posB.x * PTM_RATIO, posB.y * PTM_RATIO);
	setPath(path);
}

void QPulleyJoint::addToWorld(QWorld *w)
{
	b2World *world = w->world;
	b2PulleyJoint *j = (b2PulleyJoint *)world->CreateJoint(this);
	joint = j;
	KQData *data = new KQData();
	data->cid = CLASS_QPulleyJoint;
	QGraphicsPathItem *i = dynamic_cast<QGraphicsPathItem *>(this);
	data->i = i;
	joint->SetUserData(data);
}

//========================================== QGearJoint ===============================================//
QGearJoint::QGearJoint(KQGraphicsItem *o1, QJoint *j1, KQGraphicsItem *o2, QJoint *j2)
{
	b2Body *bodyA = static_cast<b2Body *>(o1->dummy->body);
	b2Body *bodyB = static_cast<b2Body *>(o2->dummy->body);
	b2Vec2 posA = bodyA->GetPosition();
	b2Vec2 posB = bodyB->GetPosition();
#ifdef DEBUG_MODE
	fprintf(stderr, "QGearJoint: bodyA = (%f, %f) : bodyB = (%f, %f)\n", posA.x, posA.y, posB.x, posB.y);
#endif
	this->bodyA = bodyA;
	this->bodyB = bodyB;
	joint1 = j1->joint;
	joint2 = j2->joint;
	float length = 100 / PTM_RATIO;
	ratio = 2 * M_PI / length;
}

void QGearJoint::addToWorld(QWorld *w)
{
	b2World *world = w->world;
	b2GearJoint *j = (b2GearJoint *)world->CreateJoint(this);
	joint = j;
	KQData *data = new KQData();
	data->cid = CLASS_QGearJoint;
	QGraphicsLineItem *i = dynamic_cast<QGraphicsLineItem *>(this);
	data->i = i;
	joint->SetUserData(data);
}

#ifdef __cplusplus
}
#endif
