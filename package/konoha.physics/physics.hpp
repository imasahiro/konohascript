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
#include <KQGraphicsScene.hpp>

#define PTM_RATIO 32.0f

class KQData {
public:
	knh_class_t cid;
	QGraphicsItem *i;
};

class QContact : public QObject, public b2ContactListener {
	Q_OBJECT;
public:
	//QContact(void);
	//void BeginContact(b2Contact *contact);
	//void EndContact(b2Contact *contact);
	//void PreSolve(b2Contact *contact, const b2Manifold *oldManifold);
	//void PostSolve(b2Contact *contact, const b2ContactImpulse *impulse);
//signals:
	//void emitBeginContactSignal(GamObject *o1, GamObject *o2);
	//void emitEndContactSignal(GamObject *o1, GamObject *o2);
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
	//GamGL *debugDraw;
	QWorld(KQGraphicsScene *scene);
	void setGravity(float x, float y);
	void timerEvent(QTimerEvent *event);
	void add(knh_class_t cid, QGraphicsItem *i);
	void start(void);
};

#define GET_CID(CLASS) knh_getcid(ctx, STEXT(#CLASS))
