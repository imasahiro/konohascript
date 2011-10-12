#ifndef QGRAPHICSEFFECT
#define QGRAPHICSEFFECT
class DummyQGraphicsEffect : public DummyQObject {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQGraphicsEffect();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQGraphicsEffect : public QGraphicsEffect, public DummyQGraphicsEffect {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQGraphicsEffect(QObject* parent);
	bool event(QEvent *event);
};

#endif //QGRAPHICSEFFECT


