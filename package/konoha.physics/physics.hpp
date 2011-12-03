#define K_INTERNAL
#include <konoha1.h>
#include <konoha1/inlinelibs.h>
#include <QtGui>
#include <Box2D.h>

#include <KQObject.hpp>

//===================================== for generation of moc file ====================================//
class PKGConnector : public QObject {
	Q_OBJECT;
public:
	PKGConnector();
	void emitDragBeginSignal(QGraphicsSceneMouseEvent *event);
	void emitDragMoveSignal(QGraphicsSceneMouseEvent *event);
	void emitDragEndSignal(QGraphicsSceneMouseEvent *event);
signals:
	void dragBeginSignal(QGraphicsSceneMouseEvent *event);
	void dragMoveSignal(QGraphicsSceneMouseEvent *event);
	void dragEndSignal(QGraphicsSceneMouseEvent *event);
};

class DummyQGraphicsItem {
	//Q_OBJECT;
public:
	kRawPtr *self;
//========== for physics package ==========//
	float density;
	float restitution;
	float friction;
	bool bullet;
	bool isStatic;
	bool draggable;
	void *body;
	PKGConnector *pkgconnector;
//========================================//
	std::map<std::string, kFunc *> *event_map;
	std::map<std::string, kFunc *> *slot_map;
	kFunc *context_menu_event_func;
	kFunc *drag_enter_event_func;
	kFunc *drag_leave_event_func;
	kFunc *drag_move_event_func;
	kFunc *drop_event_func;
	kFunc *focus_in_event_func;
	kFunc *focus_out_event_func;
	kFunc *hover_enter_event_func;
	kFunc *hover_leave_event_func;
	kFunc *hover_move_event_func;
	kFunc *input_method_event_func;
	kFunc *key_press_event_func;
	kFunc *key_release_event_func;
	kFunc *mouse_double_click_event_func;
	kFunc *mouse_move_event_func;
	kFunc *mouse_press_event_func;
	kFunc *mouse_release_event_func;
	kFunc *scene_event_func;
	kFunc *wheel_event_func;
	kFunc *paint_func;
	kRawPtr *contextMenuEventPtr;
	kRawPtr *dragEnterEventPtr;
	kRawPtr *dragLeaveEventPtr;
	kRawPtr *dragMoveEventPtr;
	kRawPtr *dropEventPtr;
	kRawPtr *focusInEventPtr;
	kRawPtr *focusOutEventPtr;
	kRawPtr *hoverEnterEventPtr;
	kRawPtr *hoverLeaveEventPtr;
	kRawPtr *hoverMoveEventPtr;
	kRawPtr *inputMethodEventPtr;
	kRawPtr *keyPressEventPtr;
	kRawPtr *keyReleaseEventPtr;
	kRawPtr *mouseDoubleClickEventPtr;
	kRawPtr *mouseMoveEventPtr;
	kRawPtr *mousePressEventPtr;
	kRawPtr *mouseReleaseEventPtr;
	kRawPtr *sceneEventPtr;
	kRawPtr *wheelEventPtr;
	DummyQGraphicsItem();
	virtual ~DummyQGraphicsItem();
	void setSelf(kRawPtr *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(kFunc *callback_func, std::string str);
	bool signalConnect(kFunc *callback_func, std::string str);
	kObject** reftrace(CTX ctx, kRawPtr *p FTRARG);
	void connection(QObject *o);
	bool contextMenuEventDummy(QGraphicsSceneContextMenuEvent* event);
	bool dragEnterEventDummy(QGraphicsSceneDragDropEvent* event);
	bool dragLeaveEventDummy(QGraphicsSceneDragDropEvent* event);
	bool dragMoveEventDummy(QGraphicsSceneDragDropEvent* event);
	bool dropEventDummy(QGraphicsSceneDragDropEvent* event);
	bool focusInEventDummy(QFocusEvent* event);
	bool focusOutEventDummy(QFocusEvent* event);
	bool hoverEnterEventDummy(QGraphicsSceneHoverEvent* event);
	bool hoverLeaveEventDummy(QGraphicsSceneHoverEvent* event);
	bool hoverMoveEventDummy(QGraphicsSceneHoverEvent* event);
	bool inputMethodEventDummy(QInputMethodEvent* event);
	bool keyPressEventDummy(QKeyEvent* event);
	bool keyReleaseEventDummy(QKeyEvent* event);
	bool mouseDoubleClickEventDummy(QGraphicsSceneMouseEvent* event);
	bool mouseMoveEventDummy(QGraphicsSceneMouseEvent* event);
	bool mousePressEventDummy(QGraphicsSceneMouseEvent* event);
	bool mouseReleaseEventDummy(QGraphicsSceneMouseEvent* event);
	bool sceneEventDummy(QEvent* event);
	bool wheelEventDummy(QGraphicsSceneWheelEvent* event);
};

class KQGraphicsItem : public QGraphicsItem {
	//Q_OBJECT;
public:
	int magic_num;
	kRawPtr *self;
	DummyQGraphicsItem *dummy;
	KQGraphicsItem(QGraphicsItem* parent);
	~KQGraphicsItem();
	void setSelf(kRawPtr *ptr);
	bool sceneEvent(QEvent *event);
	void paint(QPainter *painter, const QStyleOptionGraphicsItem * option, QWidget * widget);
};
//==============================================================================================//
//#include <KQGraphicsItem.hpp>
#include <KQGraphicsItemGroup.hpp>
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
	kclass_t cid;
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
	kRawPtr *rect_body;
	kRawPtr *ellipse_body;
	kRawPtr *simple_text_body;
	kRawPtr *text_body;
	kRawPtr *pixmap_body;
	kRawPtr *complex_body;
	kFunc *begin_contact_event_func;
	kFunc *end_contact_event_func;

	QContact(void);
	kRawPtr *getRawPtrFromCID(kclass_t cid);
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
	QList<b2Body *> *bodys;

	QWorld(KQGraphicsScene *scene);
	void setGravity(float x, float y);
	void timerEvent(QTimerEvent *event);
	void add(kclass_t cid, QGraphicsItem *i);
	void remove(KQGraphicsItem *i);
	void removeAll(void);
	void start(void);
	~QWorld(void);
public slots:
	void dragBeginSlot(QGraphicsSceneMouseEvent *event);
	void dragMoveSlot(QGraphicsSceneMouseEvent *event);
	void dragEndSlot(QGraphicsSceneMouseEvent *event);
};

class QGraphicsComplexItem : public KQGraphicsItemGroup {
public:
	QList<QGraphicsPolygonItem *> *polygons;

	QGraphicsComplexItem(const QList<QPointF> &pts);
	void setBrush(const QBrush &b);
	~QGraphicsComplexItem(void);
	void addToWorld(QWorld *world);
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
extern unsigned int CLASS_QGraphicsComplexItem;
extern unsigned int CLASS_QDistanceJoint;
extern unsigned int CLASS_QRevoluteJoint;
extern unsigned int CLASS_QPrismaticJoint;
extern unsigned int CLASS_QPulleyJoint;
extern unsigned int CLASS_QGearJoint;

#define GET_CID(CLASS) knh_getcid(ctx, STEXT(#CLASS))
