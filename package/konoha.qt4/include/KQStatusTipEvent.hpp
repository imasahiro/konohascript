#ifndef QSTATUSTIPEVENT
#define QSTATUSTIPEVENT
class DummyQStatusTipEvent : public DummyQEvent {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQStatusTipEvent();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void connection(QObject *o);
};

class KQStatusTipEvent : public QStatusTipEvent {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQStatusTipEvent *dummy;
	KQStatusTipEvent(const QString tip);
	void setSelf(knh_RawPtr_t *ptr);
};

#endif //QSTATUSTIPEVENT


