#ifndef QSOCKETNOTIFIER
#define QSOCKETNOTIFIER
class DummyQSocketNotifier : public DummyQObject {
	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *activated_func;
	DummyQSocketNotifier();
	virtual ~DummyQSocketNotifier();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	knh_Object_t** reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
public slots:
	bool activatedSlot(int socket);
};

class KQSocketNotifier : public QSocketNotifier {
//	Q_OBJECT;
public:
	int magic_num;
	knh_RawPtr_t *self;
	DummyQSocketNotifier *dummy;
	KQSocketNotifier(int socket, QSocketNotifier::Type type, QObject* parent);
	~KQSocketNotifier();
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QSOCKETNOTIFIER


