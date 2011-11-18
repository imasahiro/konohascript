#ifndef QGRAPHICSSCENE
#define QGRAPHICSSCENE
class DummyQGraphicsScene : public DummyQObject {
	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	QList<knh_RawPtr_t *> *added_list;
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
	knh_RawPtr_t *contextMenuEventPtr;
	knh_RawPtr_t *dragEnterEventPtr;
	knh_RawPtr_t *dragLeaveEventPtr;
	knh_RawPtr_t *dragMoveEventPtr;
	knh_RawPtr_t *dropEventPtr;
	knh_RawPtr_t *focusInEventPtr;
	knh_RawPtr_t *focusOutEventPtr;
	knh_RawPtr_t *helpEventPtr;
	knh_RawPtr_t *inputMethodEventPtr;
	knh_RawPtr_t *keyPressEventPtr;
	knh_RawPtr_t *keyReleaseEventPtr;
	knh_RawPtr_t *mouseDoubleClickEventPtr;
	knh_RawPtr_t *mouseMoveEventPtr;
	knh_RawPtr_t *mousePressEventPtr;
	knh_RawPtr_t *mouseReleaseEventPtr;
	knh_RawPtr_t *wheelEventPtr;
	DummyQGraphicsScene();
	virtual ~DummyQGraphicsScene();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	knh_Object_t** reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
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
};

class KQGraphicsScene : public QGraphicsScene {
//	Q_OBJECT;
public:
	int magic_num;
	knh_RawPtr_t *self;
	DummyQGraphicsScene *dummy;
	KQGraphicsScene(QObject* parent);
	~KQGraphicsScene();
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QGRAPHICSSCENE


