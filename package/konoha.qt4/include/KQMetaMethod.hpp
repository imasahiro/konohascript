#ifndef QMETAMETHOD
#define QMETAMETHOD
class DummyQMetaMethod {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQMetaMethod();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQMetaMethod : public QMetaMethod, public DummyQMetaMethod {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQMetaMethod();
};

#endif //QMETAMETHOD


