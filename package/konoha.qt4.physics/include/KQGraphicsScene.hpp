#ifndef QGRAPHICSSCENE
#define QGRAPHICSSCENE
class DummyQGraphicsScene : public DummyQObject {
	//Q_OBJECT;
public:
	kRawPtr *self;
	std::map<std::string, kFunc *> *event_map;
	std::map<std::string, kFunc *> *slot_map;
	kFunc *context_menu_event_func;
	kFunc *drag_enter_event_func;
	kFunc *drag_leave_event_func;
	kFunc *drag_move_event_func;
	kFunc *drop_event_func;
	kFunc *focus_in_event_func;
	kFunc *focus_out_event_func;
	kFunc *help_event_func;
	kFunc *input_method_event_func;
	kFunc *key_press_event_func;
	kFunc *key_release_event_func;
	kFunc *mouse_double_click_event_func;
	kFunc *mouse_move_event_func;
	kFunc *mouse_press_event_func;
	kFunc *mouse_release_event_func;
	kFunc *wheel_event_func;
	kFunc *changed_func;
	kFunc *scene_rect_changed_func;
	kFunc *selection_changed_func;
	/*
	DummyQGraphicsScene();
	void setSelf(kRawPtr *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(kFunc *callback_func, std::string str);
	bool signalConnect(kFunc *callback_func, std::string str);
	void connection(QObject *o);
	bool contextMenuEventDummy(QGraphicsSceneContextMenuEvent* contextMenuEvent);
	bool dragEnterEventDummy(QGraphicsSceneDragDropEvent* event);
	bool dragLeaveEventDummy(QGraphicsSceneDragDropEvent* event);
	bool dragMoveEventDummy(QGraphicsSceneDragDropEvent* event);
	bool dropEventDummy(QGraphicsSceneDragDropEvent* event);
	bool focusInEventDummy(QFocusEvent* focusEvent);
	bool focusOutEventDummy(QFocusEvent* focusEvent);
	bool helpEventDummy(QGraphicsSceneHelpEvent* helpEvent);
	bool inputMethodEventDummy(QInputMethodEvent* event);
	bool keyPressEventDummy(QKeyEvent* keyEvent);
	bool keyReleaseEventDummy(QKeyEvent* keyEvent);
	bool mouseDoubleClickEventDummy(QGraphicsSceneMouseEvent* mouseEvent);
	bool mouseMoveEventDummy(QGraphicsSceneMouseEvent* mouseEvent);
	bool mousePressEventDummy(QGraphicsSceneMouseEvent* mouseEvent);
	bool mouseReleaseEventDummy(QGraphicsSceneMouseEvent* mouseEvent);
	bool wheelEventDummy(QGraphicsSceneWheelEvent* wheelEvent);
public slots:
	bool changedSlot(const QList<QRectF> region);
	bool sceneRectChangedSlot(const QRectF rect);
	bool selectionChangedSlot();
	*/
};

class KQGraphicsScene : public QGraphicsScene {
//	Q_OBJECT;
public:
	kRawPtr *self;
	DummyQGraphicsScene *dummy;
	KQGraphicsScene(QObject* parent);
	///void setSelf(kRawPtr *ptr);
	//bool event(QEvent *event);
};

#endif //QGRAPHICSSCENE
