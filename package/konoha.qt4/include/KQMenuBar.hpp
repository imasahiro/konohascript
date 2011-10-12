#ifndef QMENUBAR
#define QMENUBAR
class DummyQMenuBar : public DummyQWidget {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQMenuBar();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQMenuBar : public QMenuBar, public DummyQMenuBar {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQMenuBar(QWidget* parent);
	bool event(QEvent *event);
};

#endif //QMENUBAR


