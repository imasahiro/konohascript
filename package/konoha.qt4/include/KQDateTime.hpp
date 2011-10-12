#ifndef QDATETIME
#define QDATETIME
class DummyQDateTime {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQDateTime();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQDateTime : public QDateTime, public DummyQDateTime {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQDateTime();
};

#endif //QDATETIME


