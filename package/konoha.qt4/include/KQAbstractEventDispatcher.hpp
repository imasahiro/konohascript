#ifndef QABSTRACTEVENTDISPATCHER
#define QABSTRACTEVENTDISPATCHER
class DummyQAbstractEventDispatcher : public DummyQObject {
	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *about_to_block_func;
	knh_Func_t *awake_func;
	DummyQAbstractEventDispatcher();
	virtual ~DummyQAbstractEventDispatcher();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	knh_Object_t** reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
public slots:
	bool aboutToBlockSlot();
	bool awakeSlot();
};

class KQAbstractEventDispatcher : public QAbstractEventDispatcher {
//	Q_OBJECT;
public:
	int magic_num;
	knh_RawPtr_t *self;
	DummyQAbstractEventDispatcher *dummy;
	KQAbstractEventDispatcher(QObject* parent);
	~KQAbstractEventDispatcher();
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QABSTRACTEVENTDISPATCHER


