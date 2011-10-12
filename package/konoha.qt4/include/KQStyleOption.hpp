#ifndef QSTYLEOPTION
#define QSTYLEOPTION
class DummyQStyleOption {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQStyleOption();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQStyleOption : public QStyleOption, public DummyQStyleOption {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQStyleOption(int version, int type);
};

#endif //QSTYLEOPTION


