#ifndef QNETWORKSESSION
#define QNETWORKSESSION
class DummyQNetworkSession : public DummyQObject {
	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *closed_func;
	knh_Func_t *error_func;
	knh_Func_t *new_configuration_activated_func;
	knh_Func_t *opened_func;
	knh_Func_t *preferred_configuration_changed_func;
	knh_Func_t *state_changed_func;
	DummyQNetworkSession();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	knh_Object_t** reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
public slots:
	bool closedSlot();
	bool errorSlot(QNetworkSession::SessionError error);
	bool newConfigurationActivatedSlot();
	bool openedSlot();
	bool preferredConfigurationChangedSlot(const QNetworkConfiguration config, bool isSeamless);
	bool stateChangedSlot(QNetworkSession::State state);
};

class KQNetworkSession : public QNetworkSession {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQNetworkSession *dummy;
	KQNetworkSession(const QNetworkConfiguration connectionConfig, QObject* parent);
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QNETWORKSESSION


