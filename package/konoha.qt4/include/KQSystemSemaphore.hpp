#ifndef QSYSTEMSEMAPHORE
#define QSYSTEMSEMAPHORE
class DummyQSystemSemaphore {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQSystemSemaphore();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQSystemSemaphore : public QSystemSemaphore, public DummyQSystemSemaphore {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQSystemSemaphore(const QString key, int initialValue, QSystemSemaphore::AccessMode mode);
};

#endif //QSYSTEMSEMAPHORE


