#ifndef QLOCALE
#define QLOCALE
class DummyQLocale {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQLocale();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
};

class KQLocale : public QLocale {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQLocale *dummy;
	KQLocale();
	void setSelf(knh_RawPtr_t *ptr);
};

#endif //QLOCALE


