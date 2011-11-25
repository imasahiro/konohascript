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
	knh_RawPtr_t *self;
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
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *context_menu_event_func;
	knh_Func_t *drag_enter_event_func;
	knh_Func_t *drag_leave_event_func;
	knh_Func_t *drag_move_event_func;
	knh_Func_t *drop_event_func;
	knh_Func_t *focus_in_event_func;
	knh_Func_t *focus_out_event_func;
	knh_Func_t *hover_enter_event_func;
	knh_Func_t *hover_leave_event_func;
	knh_Func_t *hover_move_event_func;
	knh_Func_t *input_method_event_func;
	knh_Func_t *key_press_event_func;
	knh_Func_t *key_release_event_func;
	knh_Func_t *mouse_double_click_event_func;
	knh_Func_t *mouse_move_event_func;
	knh_Func_t *mouse_press_event_func;
	knh_Func_t *mouse_release_event_func;
	knh_Func_t *scene_event_func;
	knh_Func_t *wheel_event_func;
	knh_Func_t *paint_func;
	knh_RawPtr_t *contextMenuEventPtr;
	knh_RawPtr_t *dragEnterEventPtr;
	knh_RawPtr_t *dragLeaveEventPtr;
	knh_RawPtr_t *dragMoveEventPtr;
	knh_RawPtr_t *dropEventPtr;
	knh_RawPtr_t *focusInEventPtr;
	knh_RawPtr_t *focusOutEventPtr;
	knh_RawPtr_t *hoverEnterEventPtr;
	knh_RawPtr_t *hoverLeaveEventPtr;
	knh_RawPtr_t *hoverMoveEventPtr;
	knh_RawPtr_t *inputMethodEventPtr;
	knh_RawPtr_t *keyPressEventPtr;
	knh_RawPtr_t *keyReleaseEventPtr;
	knh_RawPtr_t *mouseDoubleClickEventPtr;
	knh_RawPtr_t *mouseMoveEventPtr;
	knh_RawPtr_t *mousePressEventPtr;
	knh_RawPtr_t *mouseReleaseEventPtr;
	knh_RawPtr_t *sceneEventPtr;
	knh_RawPtr_t *wheelEventPtr;
	DummyQGraphicsItem();
	virtual ~DummyQGraphicsItem();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	knh_Object_t** reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
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
	knh_RawPtr_t *self;
	DummyQGraphicsItem *dummy;
	KQGraphicsItem(QGraphicsItem* parent);
	~KQGraphicsItem();
	void setSelf(knh_RawPtr_t *ptr);
	bool sceneEvent(QEvent *event);
	void paint(QPainter *painter, const QStyleOptionGraphicsItem * option, QWidget * widget);
};

