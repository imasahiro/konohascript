#ifndef QMDISUBWINDOW
#define QMDISUBWINDOW
class DummyQMdiSubWindow : public DummyQWidget {
	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *about_to_activate_func;
	knh_Func_t *window_state_changed_func;
	DummyQMdiSubWindow();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	knh_Object_t** reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
public slots:
	bool aboutToActivateSlot();
	bool windowStateChangedSlot(Qt::WindowStates oldState, Qt::WindowStates new_State);
};

class KQMdiSubWindow : public QMdiSubWindow {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQMdiSubWindow *dummy;
	KQMdiSubWindow(QWidget* parent, Qt::WindowFlags flags);
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QMDISUBWINDOW


