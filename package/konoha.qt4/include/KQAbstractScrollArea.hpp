#ifndef QABSTRACTSCROLLAREA
#define QABSTRACTSCROLLAREA
class DummyQAbstractScrollArea : public DummyQFrame {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *viewport_event_func;
	DummyQAbstractScrollArea();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
	bool viewportEventDummy(QEvent* event);
};

class KQAbstractScrollArea : public QAbstractScrollArea {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQAbstractScrollArea *dummy;
	KQAbstractScrollArea(QWidget* parent);
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QABSTRACTSCROLLAREA


