#ifndef QEASINGCURVE
#define QEASINGCURVE
class DummyQEasingCurve {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQEasingCurve();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
};

class KQEasingCurve : public QEasingCurve {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQEasingCurve *dummy;
	KQEasingCurve(QEasingCurve::Type type);
	void setSelf(knh_RawPtr_t *ptr);
};

#endif //QEASINGCURVE


