#ifndef QCOMMONSTYLE
#define QCOMMONSTYLE
class DummyQCommonStyle : public DummyQStyle {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQCommonStyle();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void connection(QObject *o);
};

class KQCommonStyle : public QCommonStyle {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQCommonStyle *dummy;
	KQCommonStyle();
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QCOMMONSTYLE


