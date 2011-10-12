#ifndef QBUTTONGROUP
#define QBUTTONGROUP
class DummyQButtonGroup : public DummyQObject {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQButtonGroup();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQButtonGroup : public QButtonGroup, public DummyQButtonGroup {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQButtonGroup(QObject* parent);
	bool event(QEvent *event);
};

#endif //QBUTTONGROUP


