#ifndef QLOCALSERVER
#define QLOCALSERVER
class DummyQLocalServer : public DummyQObject {
	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *new_connection_func;
	DummyQLocalServer();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
public slots:
	bool newConnectionSlot();
};

class KQLocalServer : public QLocalServer {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQLocalServer *dummy;
	KQLocalServer(QObject* parent);
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QLOCALSERVER


