#ifndef QGRAPHICSROTATION
#define QGRAPHICSROTATION
class DummyQGraphicsRotation : public DummyQGraphicsTransform {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQGraphicsRotation();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQGraphicsRotation : public QGraphicsRotation, public DummyQGraphicsRotation {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQGraphicsRotation(QObject* parent);
	bool event(QEvent *event);
};

#endif //QGRAPHICSROTATION


