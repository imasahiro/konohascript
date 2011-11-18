#ifndef QABSTRACTSCROLLAREA
#define QABSTRACTSCROLLAREA
class DummyQAbstractScrollArea : public DummyQFrame {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *viewport_event_func;
	knh_RawPtr_t *viewportEventPtr;
	DummyQAbstractScrollArea();
	virtual ~DummyQAbstractScrollArea();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	knh_Object_t** reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
	bool viewportEventDummy(QEvent* event);
};

class KQAbstractScrollArea : public QAbstractScrollArea {
//	Q_OBJECT;
public:
	int magic_num;
	knh_RawPtr_t *self;
	DummyQAbstractScrollArea *dummy;
	KQAbstractScrollArea(QWidget* parent);
	~KQAbstractScrollArea();
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QABSTRACTSCROLLAREA


