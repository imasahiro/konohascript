#ifndef QLATIN1STRING
#define QLATIN1STRING
class DummyQLatin1String {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQLatin1String();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void connection(QObject *o);
};

class KQLatin1String : public QLatin1String {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQLatin1String *dummy;
	KQLatin1String(const char* str);
	void setSelf(knh_RawPtr_t *ptr);
};

#endif //QLATIN1STRING


