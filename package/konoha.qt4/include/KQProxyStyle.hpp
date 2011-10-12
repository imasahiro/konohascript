#ifndef QPROXYSTYLE
#define QPROXYSTYLE
class DummyQProxyStyle : public DummyQCommonStyle {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQProxyStyle();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQProxyStyle : public QProxyStyle, public DummyQProxyStyle {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQProxyStyle(QStyle* style);
	bool event(QEvent *event);
};

#endif //QPROXYSTYLE


