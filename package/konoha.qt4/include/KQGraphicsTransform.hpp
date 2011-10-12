#ifndef QGRAPHICSTRANSFORM
#define QGRAPHICSTRANSFORM
class DummyQGraphicsTransform : public DummyQObject {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQGraphicsTransform();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQGraphicsTransform : public QGraphicsTransform, public DummyQGraphicsTransform {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQGraphicsTransform(QObject* parent);
	bool event(QEvent *event);
};

#endif //QGRAPHICSTRANSFORM


