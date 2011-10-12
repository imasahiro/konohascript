#ifndef QPOINTF
#define QPOINTF
class DummyQPointF {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQPointF();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQPointF : public QPointF, public DummyQPointF {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQPointF();
};

#endif //QPOINTF


