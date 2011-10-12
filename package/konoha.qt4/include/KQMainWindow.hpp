#ifndef QMAINWINDOW
#define QMAINWINDOW
class DummyQMainWindow : public DummyQWidget {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQMainWindow();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQMainWindow : public QMainWindow, public DummyQMainWindow {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQMainWindow(QWidget* parent, Qt::WindowFlags flags);
	bool event(QEvent *event);
};

#endif //QMAINWINDOW


