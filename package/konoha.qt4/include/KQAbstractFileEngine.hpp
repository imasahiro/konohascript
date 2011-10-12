#ifndef QABSTRACTFILEENGINE
#define QABSTRACTFILEENGINE
class DummyQAbstractFileEngine {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQAbstractFileEngine();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQAbstractFileEngine : public QAbstractFileEngine, public DummyQAbstractFileEngine {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQAbstractFileEngine();
};

#endif //QABSTRACTFILEENGINE


