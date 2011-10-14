#ifndef QSYSTEMTRAYICON
#define QSYSTEMTRAYICON
class DummyQSystemTrayIcon : public DummyQObject {
	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *activated_func;
	knh_Func_t *message_clicked_func;
	DummyQSystemTrayIcon();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void connection(QObject *o);
public slots:
	bool activatedSlot(QSystemTrayIcon::ActivationReason reason);
	bool messageClickedSlot();
};

class KQSystemTrayIcon : public QSystemTrayIcon {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQSystemTrayIcon *dummy;
	KQSystemTrayIcon(QObject* parent);
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QSYSTEMTRAYICON


