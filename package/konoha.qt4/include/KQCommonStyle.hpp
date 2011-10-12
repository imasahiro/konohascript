#ifndef QCOMMONSTYLE
#define QCOMMONSTYLE
class DummyQCommonStyle : public DummyQStyle {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQCommonStyle();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQCommonStyle : public QCommonStyle, public DummyQCommonStyle {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQCommonStyle();
	bool event(QEvent *event);
};

#endif //QCOMMONSTYLE


