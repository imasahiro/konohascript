#ifndef QMDISUBWINDOW
#define QMDISUBWINDOW
class DummyQMdiSubWindow : public DummyQWidget {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQMdiSubWindow();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQMdiSubWindow : public QMdiSubWindow, public DummyQMdiSubWindow {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQMdiSubWindow(QWidget* parent, Qt::WindowFlags flags);
	bool event(QEvent *event);
};

#endif //QMDISUBWINDOW


