#ifndef QREGEXP
#define QREGEXP
class DummyQRegExp {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQRegExp();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQRegExp : public QRegExp, public DummyQRegExp {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQRegExp();
};

#endif //QREGEXP


