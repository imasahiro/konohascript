#ifndef QSTYLEOPTIONTABBARBASE
#define QSTYLEOPTIONTABBARBASE
class DummyQStyleOptionTabBarBase : public DummyQStyleOption {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQStyleOptionTabBarBase();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
};

class KQStyleOptionTabBarBase : public QStyleOptionTabBarBase {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQStyleOptionTabBarBase *dummy;
	KQStyleOptionTabBarBase();
	void setSelf(knh_RawPtr_t *ptr);
};

#endif //QSTYLEOPTIONTABBARBASE


