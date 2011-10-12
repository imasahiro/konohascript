#ifndef QTOOLBAR
#define QTOOLBAR
class DummyQToolBar : public DummyQWidget {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQToolBar();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQToolBar : public QToolBar, public DummyQToolBar {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQToolBar(const QString title, QWidget* parent);
	bool event(QEvent *event);
};

#endif //QTOOLBAR


