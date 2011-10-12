#ifndef QDROPEVENT
#define QDROPEVENT
class DummyQDropEvent : public DummyQEvent {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQDropEvent();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQDropEvent : public QDropEvent, public DummyQDropEvent {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQDropEvent(const QPoint pos, Qt::DropActions actions, const QMimeData* data, Qt::MouseButtons buttons, Qt::KeyboardModifiers modifiers, QDropEvent::Type type);
};

#endif //QDROPEVENT


