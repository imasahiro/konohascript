#ifndef QPINCHGESTURE
#define QPINCHGESTURE
class DummyQPinchGesture : public DummyQGesture {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQPinchGesture();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQPinchGesture : public QPinchGesture, public DummyQPinchGesture {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQPinchGesture();
	bool event(QEvent *event);
};

#endif //QPINCHGESTURE


