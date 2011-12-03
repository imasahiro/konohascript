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

