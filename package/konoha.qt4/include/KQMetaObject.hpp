#ifndef QMETAOBJECT
#define QMETAOBJECT
class DummyQMetaObject {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQMetaObject();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	knh_Object_t** reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
};

class KQMetaObject : public QMetaObject {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQMetaObject *dummy;

	void setSelf(knh_RawPtr_t *ptr);
};

#endif //QMETAOBJECT


