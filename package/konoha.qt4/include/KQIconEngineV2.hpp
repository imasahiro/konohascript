#ifndef QICONENGINEV2
#define QICONENGINEV2
class DummyQIconEngineV2 : public DummyQIconEngine {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQIconEngineV2();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void connection(QObject *o);
};

class KQIconEngineV2 : public QIconEngineV2 {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQIconEngineV2 *dummy;
	KQIconEngineV2();
	void setSelf(knh_RawPtr_t *ptr);
};

#endif //QICONENGINEV2


