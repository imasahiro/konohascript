#ifndef QLATIN1CHAR
#define QLATIN1CHAR
class DummyQLatin1Char {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQLatin1Char();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
};

class KQLatin1Char : public QLatin1Char {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQLatin1Char *dummy;
	KQLatin1Char(char c);
	void setSelf(knh_RawPtr_t *ptr);
};

#endif //QLATIN1CHAR


