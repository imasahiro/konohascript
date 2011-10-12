#ifndef QDYNAMICPROPERTYCHANGEEVENT
#define QDYNAMICPROPERTYCHANGEEVENT
class DummyQDynamicPropertyChangeEvent : public DummyQEvent {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQDynamicPropertyChangeEvent();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQDynamicPropertyChangeEvent : public QDynamicPropertyChangeEvent, public DummyQDynamicPropertyChangeEvent {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQDynamicPropertyChangeEvent(const QByteArray name);
};

#endif //QDYNAMICPROPERTYCHANGEEVENT


