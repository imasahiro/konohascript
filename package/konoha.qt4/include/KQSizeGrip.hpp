#ifndef QSIZEGRIP
#define QSIZEGRIP
class DummyQSizeGrip : public DummyQWidget {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQSizeGrip();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQSizeGrip : public QSizeGrip, public DummyQSizeGrip {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQSizeGrip(QWidget* parent);
	bool event(QEvent *event);
};

#endif //QSIZEGRIP


