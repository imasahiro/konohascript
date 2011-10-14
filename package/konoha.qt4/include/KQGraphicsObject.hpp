#ifndef QGRAPHICSOBJECT
#define QGRAPHICSOBJECT
class DummyQGraphicsObject : public DummyQObject, public DummyQGraphicsItem {
	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *enabled_changed_func;
	knh_Func_t *opacity_changed_func;
	knh_Func_t *parent_changed_func;
	knh_Func_t *rotation_changed_func;
	knh_Func_t *scale_changed_func;
	knh_Func_t *visible_changed_func;
	knh_Func_t *x_changed_func;
	knh_Func_t *y_changed_func;
	knh_Func_t *z_changed_func;
	DummyQGraphicsObject();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void connection(QObject *o);
public slots:
	bool enabledChangedSlot();
	bool opacityChangedSlot();
	bool parentChangedSlot();
	bool rotationChangedSlot();
	bool scaleChangedSlot();
	bool visibleChangedSlot();
	bool xChangedSlot();
	bool yChangedSlot();
	bool zChangedSlot();
};

class KQGraphicsObject : public QGraphicsObject {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQGraphicsObject *dummy;
	KQGraphicsObject(QGraphicsItem* parent);
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QGRAPHICSOBJECT


