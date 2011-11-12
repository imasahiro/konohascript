#ifndef QGRAPHICSROTATION
#define QGRAPHICSROTATION
class DummyQGraphicsRotation : public DummyQGraphicsTransform {
	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *angle_changed_func;
	knh_Func_t *axis_changed_func;
	knh_Func_t *origin_changed_func;
	DummyQGraphicsRotation();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	knh_Object_t** reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
public slots:
	bool angleChangedSlot();
	bool axisChangedSlot();
	bool originChangedSlot();
};

class KQGraphicsRotation : public QGraphicsRotation {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQGraphicsRotation *dummy;
	KQGraphicsRotation(QObject* parent);
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QGRAPHICSROTATION


