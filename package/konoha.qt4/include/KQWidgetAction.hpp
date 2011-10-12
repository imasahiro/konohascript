#ifndef QWIDGETACTION
#define QWIDGETACTION
class DummyQWidgetAction : public DummyQAction {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQWidgetAction();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQWidgetAction : public QWidgetAction, public DummyQWidgetAction {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQWidgetAction(QObject* parent);
	bool event(QEvent *event);
};

#endif //QWIDGETACTION


