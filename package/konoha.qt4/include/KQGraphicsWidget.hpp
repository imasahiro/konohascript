#ifndef QGRAPHICSWIDGET
#define QGRAPHICSWIDGET
class DummyQGraphicsWidget : public DummyQGraphicsObject, public DummyQGraphicsLayoutItem {
	Q_OBJECT;
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
	knh_Func_t *geometry_changed_func;
	DummyQGraphicsWidget();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
	bool changeEventDummy(QEvent* event);
	bool closeEventDummy(QCloseEvent* event);
	bool grabKeyboardEventDummy(QEvent* event);
	bool grabMouseEventDummy(QEvent* event);
	bool hideEventDummy(QHideEvent* event);
	bool moveEventDummy(QGraphicsSceneMoveEvent* event);
	bool polishEventDummy();
	bool resizeEventDummy(QGraphicsSceneResizeEvent* event);
	bool showEventDummy(QShowEvent* event);
	bool ungrabKeyboardEventDummy(QEvent* event);
	bool ungrabMouseEventDummy(QEvent* event);
	bool windowFrameEventDummy(QEvent* event);
public slots:
	bool geometryChangedSlot();
};

class KQGraphicsWidget : public QGraphicsWidget {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQGraphicsWidget *dummy;
	KQGraphicsWidget(QGraphicsItem* parent, Qt::WindowFlags wFlags);
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QGRAPHICSWIDGET


