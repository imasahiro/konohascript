#ifndef QBITARRAY
#define QBITARRAY
class DummyQBitArray {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQBitArray();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
};

class KQBitArray : public QBitArray {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQBitArray *dummy;
	KQBitArray();
	void setSelf(knh_RawPtr_t *ptr);
};

#endif //QBITARRAY


