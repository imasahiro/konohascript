#ifndef QGRAPHICSSCENEDRAGDROPEVENT
#define QGRAPHICSSCENEDRAGDROPEVENT
class DummyQGraphicsSceneDragDropEvent : public DummyQGraphicsSceneEvent {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQGraphicsSceneDragDropEvent();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQGraphicsSceneDragDropEvent : public QGraphicsSceneDragDropEvent, public DummyQGraphicsSceneDragDropEvent {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQGraphicsSceneDragDropEvent();
};

#endif //QGRAPHICSSCENEDRAGDROPEVENT


