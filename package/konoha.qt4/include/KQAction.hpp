#ifndef QACTION
#define QACTION
class DummyQAction : public DummyQObject {
	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *changed_func;
	knh_Func_t *hovered_func;
	knh_Func_t *toggled_func;
	knh_Func_t *triggered_func;
	DummyQAction();
	virtual ~DummyQAction();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	knh_Object_t** reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
public slots:
	bool changedSlot();
	bool hoveredSlot();
	bool toggledSlot(bool checked);
	bool triggeredSlot(bool checked);
};

class KQAction : public QAction {
//	Q_OBJECT;
public:
	int magic_num;
	knh_RawPtr_t *self;
	DummyQAction *dummy;
	KQAction(QObject* parent);
	~KQAction();
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QACTION


