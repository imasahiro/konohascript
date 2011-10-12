#ifndef QBASICTIMER
#define QBASICTIMER
class DummyQBasicTimer {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQBasicTimer();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQBasicTimer : public QBasicTimer, public DummyQBasicTimer {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQBasicTimer();
};

#endif //QBASICTIMER


