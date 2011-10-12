#ifndef QSYSTEMLOCALE
#define QSYSTEMLOCALE
class DummyQSystemLocale {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQSystemLocale();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQSystemLocale : public QSystemLocale, public DummyQSystemLocale {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQSystemLocale();
};

#endif //QSYSTEMLOCALE


