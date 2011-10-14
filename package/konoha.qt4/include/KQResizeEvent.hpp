#ifndef QRESIZEEVENT
#define QRESIZEEVENT
class DummyQResizeEvent : public DummyQEvent {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQResizeEvent();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void connection(QObject *o);
};

class KQResizeEvent : public QResizeEvent {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQResizeEvent *dummy;
	KQResizeEvent(const QSize size, const QSize oldSize);
	void setSelf(knh_RawPtr_t *ptr);
};

#endif //QRESIZEEVENT


