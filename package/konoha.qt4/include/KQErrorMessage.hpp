#ifndef QERRORMESSAGE
#define QERRORMESSAGE
class DummyQErrorMessage : public DummyQDialog {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQErrorMessage();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQErrorMessage : public QErrorMessage, public DummyQErrorMessage {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQErrorMessage(QWidget* parent);
	bool event(QEvent *event);
};

#endif //QERRORMESSAGE


