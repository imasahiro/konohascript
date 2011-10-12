#ifndef QEASINGCURVE
#define QEASINGCURVE
class DummyQEasingCurve {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQEasingCurve();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQEasingCurve : public QEasingCurve, public DummyQEasingCurve {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQEasingCurve(QEasingCurve::Type type);
};

#endif //QEASINGCURVE


