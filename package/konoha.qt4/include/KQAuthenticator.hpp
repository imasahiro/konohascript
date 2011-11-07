#ifndef QAUTHENTICATOR
#define QAUTHENTICATOR
class DummyQAuthenticator {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQAuthenticator();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
};

class KQAuthenticator : public QAuthenticator {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQAuthenticator *dummy;
	KQAuthenticator();
	void setSelf(knh_RawPtr_t *ptr);
};

#endif //QAUTHENTICATOR


