#ifndef QTIMER
#define QTIMER
class DummyQTimer : public DummyQObject {
	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *timeout_func;
	DummyQTimer();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void connection(QObject *o);
public slots:
	bool timeoutSlot();
};

class KQTimer : public QTimer {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQTimer *dummy;
	KQTimer(QObject* parent);
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QTIMER


