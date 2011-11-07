#ifndef QGRAPHICSCOLORIZEEFFECT
#define QGRAPHICSCOLORIZEEFFECT
class DummyQGraphicsColorizeEffect : public DummyQGraphicsEffect {
	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *color_changed_func;
	knh_Func_t *strength_changed_func;
	DummyQGraphicsColorizeEffect();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
public slots:
	bool colorChangedSlot(const QColor color);
	bool strengthChangedSlot(qreal strength);
};

class KQGraphicsColorizeEffect : public QGraphicsColorizeEffect {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQGraphicsColorizeEffect *dummy;
	KQGraphicsColorizeEffect(QObject* parent);
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QGRAPHICSCOLORIZEEFFECT


