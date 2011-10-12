#ifndef QACCESSIBLEINTERFACE
#define QACCESSIBLEINTERFACE
class DummyQAccessibleInterface : public DummyQAccessible {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQAccessibleInterface();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQAccessibleInterface : public QAccessibleInterface, public DummyQAccessibleInterface {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQAccessibleInterface();
};

#endif //QACCESSIBLEINTERFACE


