#ifndef QFOCUSFRAME
#define QFOCUSFRAME
class DummyQFocusFrame : public DummyQWidget {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQFocusFrame();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQFocusFrame : public QFocusFrame, public DummyQFocusFrame {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQFocusFrame(QWidget* parent);
	bool event(QEvent *event);
};

#endif //QFOCUSFRAME


