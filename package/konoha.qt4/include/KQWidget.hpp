#ifndef QWIDGET
#define QWIDGET
class DummyQWidget : public DummyQObject, public DummyQPaintDevice {
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
	DummyQWidget();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool actionEvent(QActionEvent* event);
	bool changeEvent(QEvent* event);
	bool closeEvent(QCloseEvent* event);
	bool contextMenuEvent(QContextMenuEvent* event);
	bool dragEnterEvent(QDragEnterEvent* event);
	bool dragLeaveEvent(QDragLeaveEvent* event);
	bool dragMoveEvent(QDragMoveEvent* event);
	bool dropEvent(QDropEvent* event);
	bool enterEvent(QEvent* event);
	bool focusInEvent(QFocusEvent* event);
	bool focusOutEvent(QFocusEvent* event);
	bool hideEvent(QHideEvent* event);
	bool inputMethodEvent(QInputMethodEvent* event);
	bool keyPressEvent(QKeyEvent* event);
	bool keyReleaseEvent(QKeyEvent* event);
	bool leaveEvent(QEvent* event);
	bool mouseDoubleClickEvent(QMouseEvent* event);
	bool mouseMoveEvent(QMouseEvent* event);
	bool mousePressEvent(QMouseEvent* event);
	bool mouseReleaseEvent(QMouseEvent* event);
	bool moveEvent(QMoveEvent* event);
	bool paintEvent(QPaintEvent* event);
	bool resizeEvent(QResizeEvent* event);
	bool showEvent(QShowEvent* event);
	bool tabletEvent(QTabletEvent* event);
	bool wheelEvent(QWheelEvent* event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQWidget : public QWidget, public DummyQWidget {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQWidget(QWidget* parent, Qt::WindowFlags f);
	bool event(QEvent *event);
};

#endif //QWIDGET


