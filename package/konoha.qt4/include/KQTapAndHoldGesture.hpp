#ifndef QTAPANDHOLDGESTURE
#define QTAPANDHOLDGESTURE
class DummyQTapAndHoldGesture : public DummyQGesture {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQTapAndHoldGesture();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQTapAndHoldGesture : public QTapAndHoldGesture, public DummyQTapAndHoldGesture {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQTapAndHoldGesture();
	bool event(QEvent *event);
};

#endif //QTAPANDHOLDGESTURE


