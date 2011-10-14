#ifndef QACCESSIBLEBRIDGE
#define QACCESSIBLEBRIDGE
class DummyQAccessibleBridge {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQAccessibleBridge();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void connection(QObject *o);
};

class KQAccessibleBridge : public QAccessibleBridge {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQAccessibleBridge *dummy;
	KQAccessibleBridge();
	void setSelf(knh_RawPtr_t *ptr);
};

#endif //QACCESSIBLEBRIDGE


