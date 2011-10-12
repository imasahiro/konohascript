#ifndef QDESKTOPWIDGET
#define QDESKTOPWIDGET
class DummyQDesktopWidget : public DummyQWidget {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQDesktopWidget();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQDesktopWidget : public QDesktopWidget, public DummyQDesktopWidget {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQDesktopWidget();
	bool event(QEvent *event);
};

#endif //QDESKTOPWIDGET


