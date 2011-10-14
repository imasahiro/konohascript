#ifndef QGRAPHICSITEM
#define QGRAPHICSITEM
class DummyQGraphicsItem {
//	Q_OBJECT;
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
	DummyQGraphicsItem();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
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
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQGraphicsItem *dummy;
	KQGraphicsItem(QGraphicsItem* parent);
	void setSelf(knh_RawPtr_t *ptr);
};

#endif //QGRAPHICSITEM


