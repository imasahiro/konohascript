#ifndef QDEBUG
#define QDEBUG
class DummyQDebug {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQDebug();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQDebug : public QDebug, public DummyQDebug {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQDebug(QIODevice* device);
};

#endif //QDEBUG


