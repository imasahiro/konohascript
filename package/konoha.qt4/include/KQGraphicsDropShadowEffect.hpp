#ifndef QGRAPHICSDROPSHADOWEFFECT
#define QGRAPHICSDROPSHADOWEFFECT
class DummyQGraphicsDropShadowEffect : public DummyQGraphicsEffect {
	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *blur_radius_changed_func;
	knh_Func_t *color_changed_func;
	knh_Func_t *offset_changed_func;
	DummyQGraphicsDropShadowEffect();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
public slots:
	bool blurRadiusChangedSlot(qreal blurRadius);
	bool colorChangedSlot(const QColor color);
	bool offsetChangedSlot(const QPointF offset);
};

class KQGraphicsDropShadowEffect : public QGraphicsDropShadowEffect {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQGraphicsDropShadowEffect *dummy;
	KQGraphicsDropShadowEffect(QObject* parent);
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QGRAPHICSDROPSHADOWEFFECT


