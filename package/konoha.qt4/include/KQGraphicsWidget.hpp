#ifndef QGRAPHICSWIDGET
#define QGRAPHICSWIDGET
class DummyQGraphicsWidget : public DummyQGraphicsObject, public DummyQGraphicsLayoutItem {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *change_event_func;
	knh_Func_t *close_event_func;
	knh_Func_t *grab_keyboard_event_func;
	knh_Func_t *grab_mouse_event_func;
	knh_Func_t *hide_event_func;
	knh_Func_t *move_event_func;
	knh_Func_t *polish_event_func;
	knh_Func_t *resize_event_func;
	knh_Func_t *show_event_func;
	knh_Func_t *ungrab_keyboard_event_func;
	knh_Func_t *ungrab_mouse_event_func;
	knh_Func_t *window_frame_event_func;
	DummyQGraphicsWidget();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool changeEvent(QEvent* event);
	bool closeEvent(QCloseEvent* event);
	bool grabKeyboardEvent(QEvent* event);
	bool grabMouseEvent(QEvent* event);
	bool hideEvent(QHideEvent* event);
	bool moveEvent(QGraphicsSceneMoveEvent* event);
	bool polishEvent();
	bool resizeEvent(QGraphicsSceneResizeEvent* event);
	bool showEvent(QShowEvent* event);
	bool ungrabKeyboardEvent(QEvent* event);
	bool ungrabMouseEvent(QEvent* event);
	bool windowFrameEvent(QEvent* event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQGraphicsWidget : public QGraphicsWidget, public DummyQGraphicsWidget {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQGraphicsWidget(QGraphicsItem* parent, Qt::WindowFlags wFlags);
	bool event(QEvent *event);
};

#endif //QGRAPHICSWIDGET


