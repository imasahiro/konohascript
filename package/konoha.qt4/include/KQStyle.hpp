#ifndef QSTYLE
#define QSTYLE
class DummyQStyle : public DummyQObject {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQStyle();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQStyle : public QStyle, public DummyQStyle {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQStyle();
	bool event(QEvent *event);
};

#endif //QSTYLE


