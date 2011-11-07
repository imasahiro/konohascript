#ifndef QREGEXP
#define QREGEXP
class DummyQRegExp {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQRegExp();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
};

class KQRegExp : public QRegExp {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQRegExp *dummy;
	KQRegExp();
	void setSelf(knh_RawPtr_t *ptr);
};

#endif //QREGEXP


