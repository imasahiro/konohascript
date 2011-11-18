#ifndef QLOCALSOCKET
#define QLOCALSOCKET
class DummyQLocalSocket : public DummyQIODevice {
	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *connected_func;
	knh_Func_t *disconnected_func;
	knh_Func_t *error_func;
	knh_Func_t *state_changed_func;
	DummyQLocalSocket();
	virtual ~DummyQLocalSocket();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	knh_Object_t** reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
public slots:
	bool connectedSlot();
	bool disconnectedSlot();
	bool errorSlot(QLocalSocket::LocalSocketError socketError);
	bool stateChangedSlot(QLocalSocket::LocalSocketState socketState);
};

class KQLocalSocket : public QLocalSocket {
//	Q_OBJECT;
public:
	int magic_num;
	knh_RawPtr_t *self;
	DummyQLocalSocket *dummy;
	KQLocalSocket(QObject* parent);
	~KQLocalSocket();
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QLOCALSOCKET


