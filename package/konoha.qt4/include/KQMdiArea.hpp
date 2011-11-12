#ifndef QMDIAREA
#define QMDIAREA
class DummyQMdiArea : public DummyQAbstractScrollArea {
	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *sub_window_activated_func;
	DummyQMdiArea();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	knh_Object_t** reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
public slots:
	bool subWindowActivatedSlot(QMdiSubWindow* window);
};

class KQMdiArea : public QMdiArea {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQMdiArea *dummy;
	KQMdiArea(QWidget* parent);
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QMDIAREA


