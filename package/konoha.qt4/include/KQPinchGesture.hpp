#ifndef QPINCHGESTURE
#define QPINCHGESTURE
class DummyQPinchGesture : public DummyQGesture {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQPinchGesture();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void connection(QObject *o);
};

class KQPinchGesture : public QPinchGesture {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQPinchGesture *dummy;
	KQPinchGesture();
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QPINCHGESTURE


