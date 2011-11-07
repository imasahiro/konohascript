#ifndef QDRAGMOVEEVENT
#define QDRAGMOVEEVENT
class DummyQDragMoveEvent : public DummyQDropEvent {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQDragMoveEvent();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
};

class KQDragMoveEvent : public QDragMoveEvent {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQDragMoveEvent *dummy;
	KQDragMoveEvent(const QPoint pos, Qt::DropActions actions, const QMimeData* data, Qt::MouseButtons buttons, Qt::KeyboardModifiers modifiers, QDragMoveEvent::Type type);
	void setSelf(knh_RawPtr_t *ptr);
};

#endif //QDRAGMOVEEVENT


