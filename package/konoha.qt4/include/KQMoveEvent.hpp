#ifndef QMOVEEVENT
#define QMOVEEVENT
class DummyQMoveEvent : public DummyQEvent {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQMoveEvent();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void connection(QObject *o);
};

class KQMoveEvent : public QMoveEvent {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQMoveEvent *dummy;
	KQMoveEvent(const QPoint pos, const QPoint oldPos);
	void setSelf(knh_RawPtr_t *ptr);
};

#endif //QMOVEEVENT

