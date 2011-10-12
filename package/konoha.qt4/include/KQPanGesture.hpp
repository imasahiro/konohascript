#ifndef QPANGESTURE
#define QPANGESTURE
class DummyQPanGesture : public DummyQGesture {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQPanGesture();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQPanGesture : public QPanGesture, public DummyQPanGesture {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQPanGesture();
	bool event(QEvent *event);
};

#endif //QPANGESTURE


