#ifndef QTHREAD
#define QTHREAD
class DummyQThread : public DummyQObject {
	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *finished_func;
	knh_Func_t *started_func;
	knh_Func_t *terminated_func;
	DummyQThread();
	virtual ~DummyQThread();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	knh_Object_t** reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
public slots:
	bool finishedSlot();
	bool startedSlot();
	bool terminatedSlot();
};

class KQThread : public QThread {
//	Q_OBJECT;
public:
	int magic_num;
	knh_RawPtr_t *self;
	DummyQThread *dummy;
	KQThread(QObject* parent);
	~KQThread();
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QTHREAD


