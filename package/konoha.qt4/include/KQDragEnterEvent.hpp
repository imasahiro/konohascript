#ifndef QDRAGENTEREVENT
#define QDRAGENTEREVENT
class DummyQDragEnterEvent : public DummyQDragMoveEvent {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQDragEnterEvent();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	knh_Object_t** reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
};

class KQDragEnterEvent : public QDragEnterEvent {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQDragEnterEvent *dummy;
	KQDragEnterEvent(const QPoint point, Qt::DropActions actions, const QMimeData* data, Qt::MouseButtons buttons, Qt::KeyboardModifiers modifiers);
	void setSelf(knh_RawPtr_t *ptr);
};

#endif //QDRAGENTEREVENT


