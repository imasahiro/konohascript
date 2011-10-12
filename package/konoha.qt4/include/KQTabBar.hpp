#ifndef QTABBAR
#define QTABBAR
class DummyQTabBar : public DummyQWidget {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQTabBar();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQTabBar : public QTabBar, public DummyQTabBar {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQTabBar(QWidget* parent);
	bool event(QEvent *event);
};

#endif //QTABBAR


