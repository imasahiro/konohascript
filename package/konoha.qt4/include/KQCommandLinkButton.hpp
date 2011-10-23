#ifndef QCOMMANDLINKBUTTON
#define QCOMMANDLINKBUTTON
class DummyQCommandLinkButton : public DummyQPushButton {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQCommandLinkButton();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void connection(QObject *o);
};

class KQCommandLinkButton : public QCommandLinkButton {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQCommandLinkButton *dummy;
	KQCommandLinkButton(QWidget* parent);
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QCOMMANDLINKBUTTON

