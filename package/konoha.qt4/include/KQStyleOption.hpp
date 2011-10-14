#ifndef QSTYLEOPTION
#define QSTYLEOPTION
class DummyQStyleOption {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQStyleOption();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void connection(QObject *o);
};

class KQStyleOption : public QStyleOption {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQStyleOption *dummy;
	KQStyleOption(int version, int type);
	void setSelf(knh_RawPtr_t *ptr);
};

#endif //QSTYLEOPTION


