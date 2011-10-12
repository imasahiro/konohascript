#ifndef QACTION
#define QACTION
class DummyQAction : public DummyQObject {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQAction();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQAction : public QAction, public DummyQAction {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQAction(QObject* parent);
	bool event(QEvent *event);
};

#endif //QACTION


