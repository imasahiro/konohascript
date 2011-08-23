#include <QtGui>
#ifdef K_USING_BOX2D
#include <Box2D.h>
#endif
#ifdef K_USING_OPENCV
#include <cv.h>
#include <highgui.h>
#endif
#include <iostream>
#define K_INTERNAL
#include <konoha1.h>

using namespace std;

typedef enum {
	GRect,
	GEllipse,
	GTexture,
	GText,
	GLine,
	GComplexItem,
} GamClassDef;

class GObject {
private:
	int _tag;
public:
	GObject(void);
	int tag(void);
	void setTag(int id);
};

class Connector : public QObject, public GObject {
	Q_OBJECT;
public:
	knh_context_t *ctx;
	knh_sfp_t *sfp;
	knh_Func_t *fo;
	Connector();
	void signalConnect(QTimeLine *t, int signal, knh_Func_t *fo, knh_context_t *ctx, knh_sfp_t *sfp);
public slots:
	void slot_func(qreal val);
};

class KPoint {
public:
	int x;
	int y;
	KPoint(int x_, int y_) {
		x = x_;
		y = y_;
	}
};

#ifdef K_USING_BOX2D
typedef struct _knh_GraphicsUserData_t {
	void *self;
	void *o;
	const knh_ClassTBL_t *ct;
} knh_GraphicsUserData_t;

class KContact : public b2ContactListener {
public:
	knh_Func_t *begin;
	knh_Func_t *end;

	KContact();
	knh_ClassTBL_t *getClassTBL(QString class_name);
	void BeginContact(b2Contact *contact);
	void EndContact(b2Contact *contact);
	void PreSolve(b2Contact *contact, const b2Manifold *oldManifold);
	void PostSolve(b2Contact *contact, const b2ContactImpulse *impulse);
};

class KWorld : public QObject, public GObject {
public:
	int timer_id;
	int iteration;
	float timestep;
	b2World *world;
	KContact *contact;

	KWorld(int width, int height);
	void add(GObject *o);
	void start(void);
	void joint(void);
	void timerEvent(QTimerEvent *event);
};

#endif

class KScene : public QGraphicsScene {
	Q_OBJECT;
public:
	knh_Func_t *mouse_press_func;
	knh_Func_t *mouse_move_func;
	knh_Func_t *mouse_release_func;
	//knh_Func_t *mouse_dragEnter_func;

	KScene();
};

class KRigidBody {
#ifdef K_USING_BOX2D
public:
	bool isStatic;
	qreal _rotation;
	qreal friction;
	qreal density;
	qreal restitution;
	
	KRigidBody(void);
	void setRot(qreal rotation_);
	void setDensity(qreal density_);
	void setFriction(qreal friction_);
	void setRestitution(qreal restitution_);
#endif
};

class KRect : public QObject, public GObject, public QGraphicsRectItem, public KRigidBody {
	Q_OBJECT;
public:
	QRect *r;
	bool isDrag;
	int x;
	int y;
	int width;
	int height;
	QGraphicsDropShadowEffect *se;
	knh_Func_t *mouse_press_func;
	knh_Func_t *mouse_move_func;
	knh_Func_t *mouse_release_func;
#ifdef K_USING_BOX2D
	b2Body *body;
#endif

	KRect(int x, int y, int width, int height);
#ifdef K_USING_BOX2D
	void addToWorld(KWorld *w);
#endif
	void mousePressEvent(QGraphicsSceneMouseEvent *event);
	void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
	void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
	void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
	void dragEnterEvent(QGraphicsSceneDragDropEvent *event);
	void wheelEvent(QGraphicsSceneWheelEvent *event);
	~KRect(void);
};

class KEllipse : public QObject, public GObject, public QGraphicsEllipseItem, public KRigidBody {
	Q_OBJECT;
public:
	bool isDrag;
	int x;
	int y;
	int width;
	int height;
#ifdef K_USING_BOX2D
	b2Body *body;
#endif
	
	KEllipse();
	void setRectShape(KRect *r);
#ifdef K_USING_BOX2D
	void addToWorld(KWorld *w);
#endif
};

typedef QList<QList<KPoint*>*> ObjPointList;

class KTexture : public QObject, public GObject, public QGraphicsPixmapItem, public KRigidBody {
	Q_OBJECT;
public:
	QPixmap *p;
	bool isDrag;
	int x;
	int y;
	int width;
	int height;
	QGraphicsColorizeEffect *ce;
	knh_Func_t *mouse_press_func;
	knh_Func_t *mouse_move_func;
	knh_Func_t *mouse_release_func;
#ifdef K_USING_BOX2D
	b2Body *body;
#endif
#ifdef K_USING_OPENCV
	IplImage *ipl;
#endif

	KTexture(const char *filepath);
	KTexture(QImage *image);
	KTexture(QPixmap *image);
	void setTrackData(const char *filepath);
	void setConnect(void);
	QList<KTexture*> *split(CTX ctx, int row, int col);
	void setRectShape(KRect *r);
	void setColor(QColor *c);
	~KTexture(void);
#ifdef K_USING_BOX2D
	void addToWorld(KWorld *w);
#endif
public slots:
	void mousePressEvent(QGraphicsSceneMouseEvent *event);
	void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
	void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
	void dragEnterEvent(QGraphicsSceneDragDropEvent *event);
};

class KComplexItem : public QObject, public GObject, public QGraphicsItemGroup, public KRigidBody {
	Q_OBJECT;
public:
	QList<QGraphicsPolygonItem*> *gp_list;
	bool isDrag;
	int x;
	int y;
	int width;
	int height;
#ifdef K_USING_BOX2D
	b2Body *body;
#endif

	KComplexItem(knh_Array_t *a);
	void setPosition(int x, int y);
	void setColor(QColor *c);
	~KComplexItem(void);
#ifdef K_USING_BOX2D
	void addToWorld(KWorld *w);
#endif
};

class KLine : public QObject, public GObject, public QGraphicsLineItem, public KRigidBody {
	Q_OBJECT;
public:
	QLine *l;
	QPen *_pen;
	bool isDrag;
	int x1;
	int y1;
	int x2;
	int y2;
	int width;
	int height;
	QGraphicsDropShadowEffect *se;
	knh_Func_t *mouse_press_func;
	knh_Func_t *mouse_move_func;
	knh_Func_t *mouse_release_func;

#ifdef K_USING_BOX2D
	b2Body *body;
#endif

	KLine(int x1, int y1, int x2, int y2);
#ifdef K_USING_BOX2D
	void addToWorld(KWorld *w);
#endif
	void mousePressEvent(QGraphicsSceneMouseEvent *event);
	void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
	void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
	void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
	void dragEnterEvent(QGraphicsSceneDragDropEvent *event);
};

class KText : public QGraphicsTextItem, public GObject, public KRigidBody {
	Q_OBJECT;
public:
	bool isDrag;
	int x;
	int y;
	int width;
	int height;
#ifdef K_USING_BOX2D
	b2Body *body;
#endif
	
	KText(QString text);
	void setPosition(int x, int y);
#ifdef K_USING_BOX2D
	void addToWorld(KWorld *w);
#endif
};

static inline int match(const char *base, const char *target)
{
	int ret = 0;
	if (strlen(base) == strlen(target) &&
		!strncmp(base, target, strlen(target))) {
		ret = 1;
	}
	return ret;
}

class KTimer : public QObject, public GObject {
public:
	int interval;
	int timer_id;
	knh_Func_t *fo;
	
	KTimer(int interval_, knh_Func_t *fo_);
	int start(void);
	void timerEvent(QTimerEvent *event);
};

class KGroup : public QObject, public QGraphicsItemGroup {
public:
	KGroup();
};

class Vec2f {
public:
	float x;
	float y;
	Vec2f() {
		this->x = 0;
		this->y = 0;
	};
	Vec2f(float x, float y) {
		this->x = x;
		this->y = y;
	}
};

typedef struct {
	Vec2f a;
	Vec2f b;
	Vec2f c;
} Triangle;

extern "C" std::vector<Triangle> triangulate(const std::vector<Vec2f> & points, float resolution);

#define KMETHOD  void  CC_FASTCALL_
#define NO_WARNING() (void)ctx; (void)sfp; (void)_rix;
#define NO_WARNING2() (void)ctx; (void)cid;
#define GObject_to_(T, q) dynamic_cast<GObject *>((T)q)

static GObject *GObject_to(knh_sfp_t &sfp)
{
	QObject *q = (QObject *)sfp.p->rawptr;
	QString name = q->objectName();
	if (name == "KRect") return GObject_to_(KRect *, q);
	else if (name == "KEllipse") return GObject_to_(KEllipse *, q);
	else if (name == "KText") return GObject_to_(KText *, q);
	else if (name == "KTexture") return GObject_to_(KTexture *, q);
	else if (name == "KLine") return GObject_to_(KLine *, q);
	else if (name == "KComplexItem") return GObject_to_(KComplexItem *, q);
	else if (name == "KGroup") return GObject_to_(KGroup *, q);
	return (GObject *)q;
}

#define QGraphicsItem_to_(T, q) dynamic_cast<QGraphicsItem *>((T)q)
static QGraphicsItem *QGraphicsItem_to(knh_sfp_t &sfp)
{
	QObject *q = (QObject *)sfp.p->rawptr;
	QString name = q->objectName();
	if (name == "KRect") return QGraphicsItem_to_(KRect *, q);
	else if (name == "KEllipse") return QGraphicsItem_to_(KEllipse *, q);
	else if (name == "KText") return QGraphicsItem_to_(KText *, q);
	else if (name == "KTexture") return QGraphicsItem_to_(KTexture *, q);
	else if (name == "KLine") return QGraphicsItem_to_(KLine *, q);
	else if (name == "KComplexItem") return QGraphicsItem_to_(KComplexItem *, q);
	else if (name == "KGroup") return QGraphicsItem_to_(KGroup *, q);
	return (QGraphicsItem *)q;
}

#include <konoha1/inlinelibs.h>
#define getClassTBL(CLASS) lctx->share->ClassTBL[knh_getcid(lctx, STEXT(#CLASS))]
#define new_RawPtrFromClass(CLASS, o) new_RawPtr(lctx, getClassTBL(CLASS), o)
//#define new_RawPtrFromClass_(CLASS) new_Object_init2(lctx, getClassTBL(lctx, CLASS))

