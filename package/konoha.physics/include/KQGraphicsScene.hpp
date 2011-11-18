#ifndef QGRAPHICSSCENE
#define QGRAPHICSSCENE
class DummyQGraphicsScene : public DummyQObject {
	//Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *context_menu_event_func;
	knh_Func_t *drag_enter_event_func;
	knh_Func_t *drag_leave_event_func;
	knh_Func_t *drag_move_event_func;
	knh_Func_t *drop_event_func;
	knh_Func_t *focus_in_event_func;
	knh_Func_t *focus_out_event_func;
	knh_Func_t *help_event_func;
	knh_Func_t *input_method_event_func;
	knh_Func_t *key_press_event_func;
	knh_Func_t *key_release_event_func;
	knh_Func_t *mouse_double_click_event_func;
	knh_Func_t *mouse_move_event_func;
	knh_Func_t *mouse_press_event_func;
	knh_Func_t *mouse_release_event_func;
	knh_Func_t *wheel_event_func;
	knh_Func_t *changed_func;
	knh_Func_t *scene_rect_changed_func;
	knh_Func_t *selection_changed_func;
	/*
	DummyQGraphicsScene();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
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
	knh_RawPtr_t *self;
	DummyQGraphicsScene *dummy;
	KQGraphicsScene(QObject* parent);
	///void setSelf(knh_RawPtr_t *ptr);
	//bool event(QEvent *event);
};

#endif //QGRAPHICSSCENE
