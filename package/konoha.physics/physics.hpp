#define K_INTERNAL
#include <konoha1.h>
#include <konoha1/inlinelibs.h>
#include <QtGui>
#include <Box2D.h>

#include <KQObject.hpp>
#include <KQGraphicsItem.hpp>
#include <KQAbstractGraphicsShapeItem.hpp>
#include <KQGraphicsRectItem.hpp>
#include <KQGraphicsEllipseItem.hpp>
#include <KQGraphicsSimpleTextItem.hpp>
#include <KQGraphicsPixmapItem.hpp>
#include <KQGraphicsScene.hpp>

#define getClassTBL(ctx, CLASS) ctx->share->ClassTBL[knh_getcid(ctx, STEXT(#CLASS))]
#define new_RawPtrFromClass(ctx, CLASS, o) new_RawPtr(ctx, getClassTBL(ctx, CLASS), o)

#define PTM_RATIO 32.0f

class KQData {
public:
	knh_class_t cid;
	QGraphicsItem *i;
};

#include <QtOpenGL>

class GLDebugDraw : public QGLWidget, public b2DebugDraw {
	Q_OBJECT;
public:
	float32 mRatio;
	b2World *world;

	GLDebugDraw(void);
	GLDebugDraw(float32 ratio);
	void show(void);
	void timerEvent(QTimerEvent *event);
	void initializeGL(void);
	void paintGL(void);
	void resizeGL(int width, int height);
	void DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color);
	void DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color);
	void DrawCircle(const b2Vec2& center, float32 radius, const b2Color& color);
	void DrawSolidCircle(const b2Vec2& center, float32 radius, const b2Vec2& axis, const b2Color& color);
	void DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color);
	void DrawTransform(const b2Transform& xf);
    void DrawPoint(const b2Vec2& p, float32 size, const b2Color& color);
    void DrawString(int x, int y, const char* string, ...);
    void DrawAABB(b2AABB* aabb, const b2Color& color);
};

class QContact : public b2ContactListener {
public:
	knh_RawPtr_t *rect_body;
	knh_RawPtr_t *ellipse_body;
	knh_RawPtr_t *simple_text_body;
	knh_RawPtr_t *text_body;
	knh_RawPtr_t *pixmap_body;
	knh_Func_t *begin_contact_event_func;
	knh_Func_t *end_contact_event_func;

	QContact(void);
	knh_RawPtr_t *getRawPtrFromCID(knh_class_t cid);
	void BeginContact(b2Contact *contact);
	void EndContact(b2Contact *contact);
	void PreSolve(b2Contact *contact, const b2Manifold *oldManifold);
	void PostSolve(b2Contact *contact, const b2ContactImpulse *impulse);
};

class QQueryCallback : public b2QueryCallback {
public:
	b2Vec2 m_point;
	b2Fixture* m_fixture;
	QQueryCallback(const b2Vec2& point);
	bool ReportFixture(b2Fixture* fixture);
};

class QWorld : public QObject {
	Q_OBJECT;
public:
	int timer_id;
	int iteration;
	float timestep;
	b2World *world;
	QContact *contact;
	KQGraphicsScene *scene;
	b2Body *mouse_joint_body;
	b2MouseJoint *mouse_joint;
	GLDebugDraw *debugDraw;

	QWorld(KQGraphicsScene *scene);
	void setGravity(float x, float y);
	void timerEvent(QTimerEvent *event);
	void add(knh_class_t cid, QGraphicsItem *i);
	void remove(KQGraphicsItem *i);
	void start(void);
public slots:
	void dragBeginSlot(QGraphicsSceneMouseEvent *event);
	void dragMoveSlot(QGraphicsSceneMouseEvent *event);
	void dragEndSlot(QGraphicsSceneMouseEvent *event);
};

class QJoint {
public:
	b2Joint *joint;
	QJoint() {}
};

class QDistanceJoint : public b2DistanceJointDef, public QGraphicsLineItem, public QJoint {
public:
	QDistanceJoint(KQGraphicsItem *o1, KQGraphicsItem *o2);
	void setLocalAnchorA(const QPointF &p);
	void setLocalAnchorB(const QPointF &p);
	void setFrequencyHz(float frequency);
	void setDampingRatio(float ratio);
	void setLength(float length);
	float getFrequencyHz(void);
	float getDampingRatio(void);
	float getLength(void);
	void setCollideConnected(bool b);
	void addToWorld(QWorld *world);
};

class QRevoluteJoint : public b2RevoluteJointDef, public QGraphicsLineItem, public QJoint {
public:
	QRevoluteJoint(KQGraphicsItem *o1, KQGraphicsItem *o2);
	void setLocalAnchorA(const QPointF &p);
	void setLocalAnchorB(const QPointF &p);
	void setLowerAngle(float angle);
	void setUpperAngle(float angle);
	void setEnableLimit(bool b);
	void setMaxMotorTorque(float torque);
	void setMotorSpeed(float speed);
	void setEnableMotor(bool b);
	void addToWorld(QWorld *world);
};

class QPrismaticJoint : public b2PrismaticJointDef, public QGraphicsLineItem, public QJoint {
public:
	QPrismaticJoint(KQGraphicsItem *o1, KQGraphicsItem *o2);
	void setLowerTranslation(float translation);
	void setUpperTranslation(float translation);
	void setEnableLimit(bool b);
	void setMaxMotorForce(float force);
	void setMotorSpeed(float speed);
	void setEnableMotor(bool b);
	void addToWorld(QWorld *world);
};

class QPulleyJoint : public b2PulleyJointDef, public QGraphicsPathItem, public QJoint {
public:
	QPulleyJoint(KQGraphicsItem *o1, const QPointF &p1, KQGraphicsItem *o2, const QPointF &p2);
	void addToWorld(QWorld *world);
};

class QGearJoint : public b2GearJointDef, public QGraphicsLineItem, public QJoint {
public:
	QGearJoint(KQGraphicsItem *o1, QJoint *j1, KQGraphicsItem *o2, QJoint *j2);
	void addToWorld(QWorld *world);
};

extern unsigned int CLASS_QGraphicsRectItem;
extern unsigned int CLASS_QGraphicsEllipseItem;
extern unsigned int CLASS_QGraphicsPixmapItem;
extern unsigned int CLASS_QGraphicsTextItem;
extern unsigned int CLASS_QGraphicsSimpleTextItem;
extern unsigned int CLASS_QGraphicsItemGroup;
extern unsigned int CLASS_QGraphicsLineItem;
extern unsigned int CLASS_QDistanceJoint;
extern unsigned int CLASS_QRevoluteJoint;
extern unsigned int CLASS_QPrismaticJoint;
extern unsigned int CLASS_QPulleyJoint;
extern unsigned int CLASS_QGearJoint;

#define GET_CID(CLASS) knh_getcid(ctx, STEXT(#CLASS))
