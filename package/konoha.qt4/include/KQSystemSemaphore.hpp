#ifndef QSYSTEMSEMAPHORE
#define QSYSTEMSEMAPHORE
class DummyQSystemSemaphore {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQSystemSemaphore();
	virtual ~DummyQSystemSemaphore();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	knh_Object_t** reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
};

class KQSystemSemaphore : public QSystemSemaphore {
//	Q_OBJECT;
public:
	int magic_num;
	knh_RawPtr_t *self;
	DummyQSystemSemaphore *dummy;
	KQSystemSemaphore(const QString key, int initialValue, QSystemSemaphore::AccessMode mode);
	~KQSystemSemaphore();
	void setSelf(knh_RawPtr_t *ptr);
};

#endif //QSYSTEMSEMAPHORE


