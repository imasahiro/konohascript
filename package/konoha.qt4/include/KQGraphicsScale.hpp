#ifndef QGRAPHICSSCALE
#define QGRAPHICSSCALE
class DummyQGraphicsScale : public DummyQGraphicsTransform {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQGraphicsScale();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQGraphicsScale : public QGraphicsScale, public DummyQGraphicsScale {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQGraphicsScale(QObject* parent);
	bool event(QEvent *event);
};

#endif //QGRAPHICSSCALE


