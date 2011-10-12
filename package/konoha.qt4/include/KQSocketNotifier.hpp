#ifndef QSOCKETNOTIFIER
#define QSOCKETNOTIFIER
class DummyQSocketNotifier : public DummyQObject {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQSocketNotifier();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQSocketNotifier : public QSocketNotifier, public DummyQSocketNotifier {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQSocketNotifier(int socket, QSocketNotifier::Type type, QObject* parent);
	bool event(QEvent *event);
};

#endif //QSOCKETNOTIFIER


