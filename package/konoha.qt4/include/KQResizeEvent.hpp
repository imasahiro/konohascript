#ifndef QRESIZEEVENT
#define QRESIZEEVENT
class DummyQResizeEvent : public DummyQEvent {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQResizeEvent();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQResizeEvent : public QResizeEvent, public DummyQResizeEvent {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQResizeEvent(const QSize size, const QSize oldSize);
};

#endif //QRESIZEEVENT


