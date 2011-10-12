#ifndef QLATIN1STRING
#define QLATIN1STRING
class DummyQLatin1String {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQLatin1String();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQLatin1String : public QLatin1String, public DummyQLatin1String {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQLatin1String(const char* str);
};

#endif //QLATIN1STRING


