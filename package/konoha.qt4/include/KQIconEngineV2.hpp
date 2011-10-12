#ifndef QICONENGINEV2
#define QICONENGINEV2
class DummyQIconEngineV2 : public DummyQIconEngine {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQIconEngineV2();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQIconEngineV2 : public QIconEngineV2, public DummyQIconEngineV2 {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQIconEngineV2();
};

#endif //QICONENGINEV2


