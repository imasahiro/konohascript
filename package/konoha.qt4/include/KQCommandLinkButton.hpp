#ifndef QCOMMANDLINKBUTTON
#define QCOMMANDLINKBUTTON
class DummyQCommandLinkButton : public DummyQPushButton {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQCommandLinkButton();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQCommandLinkButton : public QCommandLinkButton, public DummyQCommandLinkButton {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQCommandLinkButton(QWidget* parent);
	bool event(QEvent *event);
};

#endif //QCOMMANDLINKBUTTON


