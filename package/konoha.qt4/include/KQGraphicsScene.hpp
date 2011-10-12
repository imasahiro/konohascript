#ifndef QGRAPHICSSCENE
#define QGRAPHICSSCENE
class DummyQGraphicsScene : public DummyQObject {
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
	DummyQGraphicsScene();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool contextMenuEvent(QGraphicsSceneContextMenuEvent* contextMenuEvent);
	bool dragEnterEvent(QGraphicsSceneDragDropEvent* event);
	bool dragLeaveEvent(QGraphicsSceneDragDropEvent* event);
	bool dragMoveEvent(QGraphicsSceneDragDropEvent* event);
	bool dropEvent(QGraphicsSceneDragDropEvent* event);
	bool focusInEvent(QFocusEvent* focusEvent);
	bool focusOutEvent(QFocusEvent* focusEvent);
	bool helpEvent(QGraphicsSceneHelpEvent* helpEvent);
	bool inputMethodEvent(QInputMethodEvent* event);
	bool keyPressEvent(QKeyEvent* keyEvent);
	bool keyReleaseEvent(QKeyEvent* keyEvent);
	bool mouseDoubleClickEvent(QGraphicsSceneMouseEvent* mouseEvent);
	bool mouseMoveEvent(QGraphicsSceneMouseEvent* mouseEvent);
	bool mousePressEvent(QGraphicsSceneMouseEvent* mouseEvent);
	bool mouseReleaseEvent(QGraphicsSceneMouseEvent* mouseEvent);
	bool wheelEvent(QGraphicsSceneWheelEvent* wheelEvent);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQGraphicsScene : public QGraphicsScene, public DummyQGraphicsScene {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQGraphicsScene(QObject* parent);
	bool event(QEvent *event);
};

#endif //QGRAPHICSSCENE


