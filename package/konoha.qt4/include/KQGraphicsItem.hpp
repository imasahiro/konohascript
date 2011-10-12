#ifndef QGRAPHICSITEM
#define QGRAPHICSITEM
class DummyQGraphicsItem {
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
	bool contextMenuEvent(QGraphicsSceneContextMenuEvent* event);
	bool dragEnterEvent(QGraphicsSceneDragDropEvent* event);
	bool dragLeaveEvent(QGraphicsSceneDragDropEvent* event);
	bool dragMoveEvent(QGraphicsSceneDragDropEvent* event);
	bool dropEvent(QGraphicsSceneDragDropEvent* event);
	bool focusInEvent(QFocusEvent* event);
	bool focusOutEvent(QFocusEvent* event);
	bool hoverEnterEvent(QGraphicsSceneHoverEvent* event);
	bool hoverLeaveEvent(QGraphicsSceneHoverEvent* event);
	bool hoverMoveEvent(QGraphicsSceneHoverEvent* event);
	bool inputMethodEvent(QInputMethodEvent* event);
	bool keyPressEvent(QKeyEvent* event);
	bool keyReleaseEvent(QKeyEvent* event);
	bool mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event);
	bool mouseMoveEvent(QGraphicsSceneMouseEvent* event);
	bool mousePressEvent(QGraphicsSceneMouseEvent* event);
	bool mouseReleaseEvent(QGraphicsSceneMouseEvent* event);
	bool sceneEvent(QEvent* event);
	bool wheelEvent(QGraphicsSceneWheelEvent* event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQGraphicsItem : public QGraphicsItem, public DummyQGraphicsItem {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQGraphicsItem(QGraphicsItem* parent);
};

#endif //QGRAPHICSITEM


