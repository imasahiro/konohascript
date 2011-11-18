#ifndef QSTYLEHINTRETURN
#define QSTYLEHINTRETURN
class DummyQStyleHintReturn {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQStyleHintReturn();
	virtual ~DummyQStyleHintReturn();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	knh_Object_t** reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
};

class KQStyleHintReturn : public QStyleHintReturn {
//	Q_OBJECT;
public:
	int magic_num;
	knh_RawPtr_t *self;
	DummyQStyleHintReturn *dummy;
	KQStyleHintReturn(int version, int type);
	~KQStyleHintReturn();
	void setSelf(knh_RawPtr_t *ptr);
};

#endif //QSTYLEHINTRETURN


