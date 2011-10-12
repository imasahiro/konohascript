#ifndef QGRAPHICSCOLORIZEEFFECT
#define QGRAPHICSCOLORIZEEFFECT
class DummyQGraphicsColorizeEffect : public DummyQGraphicsEffect {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQGraphicsColorizeEffect();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQGraphicsColorizeEffect : public QGraphicsColorizeEffect, public DummyQGraphicsColorizeEffect {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQGraphicsColorizeEffect(QObject* parent);
	bool event(QEvent *event);
};

#endif //QGRAPHICSCOLORIZEEFFECT


