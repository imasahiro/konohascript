#ifndef QGRAPHICSOPACITYEFFECT
#define QGRAPHICSOPACITYEFFECT
class DummyQGraphicsOpacityEffect : public DummyQGraphicsEffect {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQGraphicsOpacityEffect();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQGraphicsOpacityEffect : public QGraphicsOpacityEffect, public DummyQGraphicsOpacityEffect {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQGraphicsOpacityEffect(QObject* parent);
	bool event(QEvent *event);
};

#endif //QGRAPHICSOPACITYEFFECT


