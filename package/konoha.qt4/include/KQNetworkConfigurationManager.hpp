#ifndef QNETWORKCONFIGURATIONMANAGER
#define QNETWORKCONFIGURATIONMANAGER
class DummyQNetworkConfigurationManager : public DummyQObject {
	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *configuration_added_func;
	knh_Func_t *configuration_changed_func;
	knh_Func_t *configuration_removed_func;
	knh_Func_t *online_state_changed_func;
	knh_Func_t *update_completed_func;
	DummyQNetworkConfigurationManager();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
public slots:
	bool configurationAddedSlot(const QNetworkConfiguration config);
	bool configurationChangedSlot(const QNetworkConfiguration config);
	bool configurationRemovedSlot(const QNetworkConfiguration configuration);
	bool onlineStateChangedSlot(bool isOnline);
	bool updateCompletedSlot();
};

class KQNetworkConfigurationManager : public QNetworkConfigurationManager {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQNetworkConfigurationManager *dummy;
	KQNetworkConfigurationManager(QObject* parent);
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QNETWORKCONFIGURATIONMANAGER


