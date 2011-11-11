#ifndef QWEBELEMENT
#define QWEBELEMENT
class DummyQWebElement {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQWebElement();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
};

class KQWebElement : public QWebElement {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQWebElement *dummy;
	KQWebElement();
	void setSelf(knh_RawPtr_t *ptr);
};

#endif //QWEBELEMENT

