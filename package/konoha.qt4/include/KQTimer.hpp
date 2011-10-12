#ifndef QTIMER
#define QTIMER
class DummyQTimer : public DummyQObject {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQTimer();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQTimer : public QTimer, public DummyQTimer {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQTimer(QObject* parent);
	bool event(QEvent *event);
};

#endif //QTIMER


