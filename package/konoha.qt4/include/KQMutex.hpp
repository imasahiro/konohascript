#ifndef QMUTEX
#define QMUTEX
class DummyQMutex {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQMutex();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQMutex : public QMutex, public DummyQMutex {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQMutex(QMutex::RecursionMode mode);
};

#endif //QMUTEX


