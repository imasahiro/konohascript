#ifndef QDRAGENTEREVENT
#define QDRAGENTEREVENT
class DummyQDragEnterEvent : public DummyQDragMoveEvent {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQDragEnterEvent();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQDragEnterEvent : public QDragEnterEvent, public DummyQDragEnterEvent {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQDragEnterEvent(const QPoint point, Qt::DropActions actions, const QMimeData* data, Qt::MouseButtons buttons, Qt::KeyboardModifiers modifiers);
};

#endif //QDRAGENTEREVENT


