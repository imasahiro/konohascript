#ifndef QTOOLTIP
#define QTOOLTIP
class DummyQToolTip {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQToolTip();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQToolTip : public QToolTip, public DummyQToolTip {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;

};

#endif //QTOOLTIP


