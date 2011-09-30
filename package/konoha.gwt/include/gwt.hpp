#include <gam.hpp>
#define K_INTERNAL
#include <konoha1.h>
#include <konoha1/inlinelibs.h>

using namespace std;

#define getClassTBL(CLASS) lctx->share->ClassTBL[knh_getcid(lctx, STEXT(#CLASS))]
#define new_RawPtrFromClass(CLASS, o) new_RawPtr(lctx, getClassTBL(CLASS), o)
#define GamObject_to_(T, q) dynamic_cast<GamObject *>((T)q)

static GamObject *GamObject_to(knh_sfp_t &sfp)
{
	QObject *q = (QObject *)sfp.p->rawptr;
	QString name = q->objectName();
	if (name == "GamRect") return GamObject_to_(GamRect *, q);
	else if (name == "GamEllipse") return GamObject_to_(GamEllipse *, q);
	else if (name == "GamText") return GamObject_to_(GamText *, q);
	else if (name == "GamTexture") return GamObject_to_(GamTexture *, q);
	else if (name == "GamLine") return GamObject_to_(GamLine *, q);
	else if (name == "GamComplexItem") return GamObject_to_(GamComplexItem *, q);
	else if (name == "GamGroup") return GamObject_to_(GamGroup *, q);
	return (GamObject *)q;
}

#define QGraphicsItem_to_(T, q) dynamic_cast<QGraphicsItem *>((T)q)
static QGraphicsItem *QGraphicsItem_to(knh_sfp_t &sfp)
{
	QObject *q = (QObject *)sfp.p->rawptr;
	QString name = q->objectName();
	if (name == "GamRect") return QGraphicsItem_to_(GamRect *, q);
	else if (name == "GamEllipse") return QGraphicsItem_to_(GamEllipse *, q);
	else if (name == "GamText") return QGraphicsItem_to_(GamText *, q);
	else if (name == "GamTexture") return QGraphicsItem_to_(GamTexture *, q);
	else if (name == "GamLine") return QGraphicsItem_to_(GamLine *, q);
	else if (name == "GamComplexItem") return QGraphicsItem_to_(GamComplexItem *, q);
	else if (name == "GamGroup") return QGraphicsItem_to_(GamGroup *, q);
	return (QGraphicsItem *)q;
}

#define NO_WARNING() (void)ctx; (void)sfp; (void)_rix;
#define NO_WARNING2() (void)ctx; (void)cid;

class KContact : public GamContact {
public:
	knh_Func_t *begin;
	knh_Func_t *end;

	KContact();
	void BeginContact(b2Contact *contact);
	void EndContact(b2Contact *contact);
	void PreSolve(b2Contact *contact, const b2Manifold *oldManifold);
	void PostSolve(b2Contact *contact, const b2ContactImpulse *impulse);
};

class KScene;
class KWorld : public GamWorld {
public:
	KContact *contact;
	KWorld(KScene *scene);
};

class KRect : public GamRect {
	Q_OBJECT;
public:
	knh_Func_t *mouse_press_func;
	knh_Func_t *mouse_move_func;
	knh_Func_t *mouse_release_func;
	knh_RawPtr_t *self;

	KRect(int x, int y, int width, int height);
	void mousePressEvent(QGraphicsSceneMouseEvent *event);
	void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
	void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
	void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
	void dragEnterEvent(QGraphicsSceneDragDropEvent *event);
	void wheelEvent(QGraphicsSceneWheelEvent *event);
};

class KEllipse : public GamEllipse {
};

class KTexture : public GamTexture {
	Q_OBJECT;
public:
	knh_Func_t *mouse_press_func;
	knh_Func_t *mouse_move_func;
	knh_Func_t *mouse_release_func;

	KTexture(const char *filepath);
	void mousePressEvent(QGraphicsSceneMouseEvent *event);
	void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
	void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
	void dragEnterEvent(QGraphicsSceneDragDropEvent *event);
};

class KComplexItem : public GamComplexItem {
};

class KLine : public GamLine {
	Q_OBJECT;
public:
	knh_Func_t *mouse_press_func;
	knh_Func_t *mouse_move_func;
	knh_Func_t *mouse_release_func;

	KLine(int x1, int y1, int x2, int y2);
	void mousePressEvent(QGraphicsSceneMouseEvent *event);
	void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
	void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
	void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
	void dragEnterEvent(QGraphicsSceneDragDropEvent *event);
};

class KText : public GamText {
};

class KScene : public GamScene {
	Q_OBJECT;
public:
	knh_Func_t *mouse_press_func;
	knh_Func_t *mouse_move_func;
	knh_Func_t *mouse_release_func;
	knh_Func_t *drag_move_func;
	knh_RawPtr_t *self;
	QList<knh_RawPtr_t *> *added_list;

	KScene();
	void mousePressEvent(QGraphicsSceneMouseEvent *event);
	void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
	void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
	void dragMoveEvent(QGraphicsSceneDragDropEvent *event);
};

class KTimeLine : public QTimeLine {
	Q_OBJECT;
public:
	knh_Func_t *finished_event_func;
public slots:
	void finishedSlotFunc();
};

class KTimer : public GamTimer {
public:
	int interval;
	int timer_id;
	knh_Func_t *fo;

	KTimer(int interval_, knh_Func_t *fo_);
	int start(void);
	void timerEvent(QTimerEvent *event);
};
