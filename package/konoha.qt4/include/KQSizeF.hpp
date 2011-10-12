#ifndef QSIZEF
#define QSIZEF
class DummyQSizeF {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQSizeF();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQSizeF : public QSizeF, public DummyQSizeF {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQSizeF();
};

#endif //QSIZEF


