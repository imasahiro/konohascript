#ifndef QWIDGET
#define QWIDGET
class DummyQWidget : public DummyQObject, public DummyQPaintDevice {
	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *action_event_func;
	knh_Func_t *change_event_func;
	knh_Func_t *close_event_func;
	knh_Func_t *context_menu_event_func;
	knh_Func_t *drag_enter_event_func;
	knh_Func_t *drag_leave_event_func;
	knh_Func_t *drag_move_event_func;
	knh_Func_t *drop_event_func;
	knh_Func_t *enter_event_func;
	knh_Func_t *focus_in_event_func;
	knh_Func_t *focus_out_event_func;
	knh_Func_t *hide_event_func;
	knh_Func_t *input_method_event_func;
	knh_Func_t *key_press_event_func;
	knh_Func_t *key_release_event_func;
	knh_Func_t *leave_event_func;
	knh_Func_t *mouse_double_click_event_func;
	knh_Func_t *mouse_move_event_func;
	knh_Func_t *mouse_press_event_func;
	knh_Func_t *mouse_release_event_func;
	knh_Func_t *move_event_func;
	knh_Func_t *paint_event_func;
	knh_Func_t *resize_event_func;
	knh_Func_t *show_event_func;
	knh_Func_t *tablet_event_func;
	knh_Func_t *wheel_event_func;
	knh_Func_t *custom_context_menu_requested_func;
	DummyQWidget();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	knh_Object_t** reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
	bool actionEventDummy(QActionEvent* event);
	bool changeEventDummy(QEvent* event);
	bool closeEventDummy(QCloseEvent* event);
	bool contextMenuEventDummy(QContextMenuEvent* event);
	bool dragEnterEventDummy(QDragEnterEvent* event);
	bool dragLeaveEventDummy(QDragLeaveEvent* event);
	bool dragMoveEventDummy(QDragMoveEvent* event);
	bool dropEventDummy(QDropEvent* event);
	bool enterEventDummy(QEvent* event);
	bool focusInEventDummy(QFocusEvent* event);
	bool focusOutEventDummy(QFocusEvent* event);
	bool hideEventDummy(QHideEvent* event);
	bool inputMethodEventDummy(QInputMethodEvent* event);
	bool keyPressEventDummy(QKeyEvent* event);
	bool keyReleaseEventDummy(QKeyEvent* event);
	bool leaveEventDummy(QEvent* event);
	bool mouseDoubleClickEventDummy(QMouseEvent* event);
	bool mouseMoveEventDummy(QMouseEvent* event);
	bool mousePressEventDummy(QMouseEvent* event);
	bool mouseReleaseEventDummy(QMouseEvent* event);
	bool moveEventDummy(QMoveEvent* event);
	bool paintEventDummy(QPaintEvent* event);
	bool resizeEventDummy(QResizeEvent* event);
	bool showEventDummy(QShowEvent* event);
	bool tabletEventDummy(QTabletEvent* event);
	bool wheelEventDummy(QWheelEvent* event);
public slots:
	bool customContextMenuRequestedSlot(const QPoint pos);
};

class KQWidget : public QWidget {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQWidget *dummy;
	KQWidget(QWidget* parent, Qt::WindowFlags f);
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QWIDGET


