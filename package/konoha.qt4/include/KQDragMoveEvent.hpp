#ifndef QDRAGMOVEEVENT
#define QDRAGMOVEEVENT
class DummyQDragMoveEvent : public DummyQDropEvent {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQDragMoveEvent();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQDragMoveEvent : public QDragMoveEvent, public DummyQDragMoveEvent {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQDragMoveEvent(const QPoint pos, Qt::DropActions actions, const QMimeData* data, Qt::MouseButtons buttons, Qt::KeyboardModifiers modifiers, QDragMoveEvent::Type type);
};

#endif //QDRAGMOVEEVENT


