#ifndef QACTIONGROUP
#define QACTIONGROUP
class DummyQActionGroup : public DummyQObject {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQActionGroup();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQActionGroup : public QActionGroup, public DummyQActionGroup {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQActionGroup(QObject* parent);
	bool event(QEvent *event);
};

#endif //QACTIONGROUP


