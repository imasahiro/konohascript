#ifndef QHOSTINFO
#define QHOSTINFO
class DummyQHostInfo {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQHostInfo();
	virtual ~DummyQHostInfo();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	knh_Object_t** reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
};

class KQHostInfo : public QHostInfo {
//	Q_OBJECT;
public:
	int magic_num;
	knh_RawPtr_t *self;
	DummyQHostInfo *dummy;
	KQHostInfo(int id);
	~KQHostInfo();
	void setSelf(knh_RawPtr_t *ptr);
};

#endif //QHOSTINFO


