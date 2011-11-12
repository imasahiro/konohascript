#ifndef QGRAPHICSOPACITYEFFECT
#define QGRAPHICSOPACITYEFFECT
class DummyQGraphicsOpacityEffect : public DummyQGraphicsEffect {
	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *opacity_changed_func;
	knh_Func_t *opacity_mask_changed_func;
	DummyQGraphicsOpacityEffect();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	knh_Object_t** reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
public slots:
	bool opacityChangedSlot(qreal opacity);
	bool opacityMaskChangedSlot(const QBrush mask);
};

class KQGraphicsOpacityEffect : public QGraphicsOpacityEffect {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQGraphicsOpacityEffect *dummy;
	KQGraphicsOpacityEffect(QObject* parent);
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QGRAPHICSOPACITYEFFECT


