#ifndef QLCDNUMBER
#define QLCDNUMBER
class DummyQLCDNumber : public DummyQFrame {
	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *overflow_func;
	DummyQLCDNumber();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
public slots:
	bool overflowSlot();
};

class KQLCDNumber : public QLCDNumber {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQLCDNumber *dummy;
	KQLCDNumber(QWidget* parent);
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QLCDNUMBER


