#ifndef QABSTRACTSCROLLAREA
#define QABSTRACTSCROLLAREA
class DummyQAbstractScrollArea : public DummyQFrame {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *viewport_event_func;
	DummyQAbstractScrollArea();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool viewportEvent(QEvent* event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQAbstractScrollArea : public QAbstractScrollArea, public DummyQAbstractScrollArea {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQAbstractScrollArea(QWidget* parent);
	bool event(QEvent *event);
};

#endif //QABSTRACTSCROLLAREA


