#ifndef QTIMELINE
#define QTIMELINE
class DummyQTimeLine : public DummyQObject {
	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *finished_func;
	knh_Func_t *frame_changed_func;
	knh_Func_t *state_changed_func;
	knh_Func_t *value_changed_func;
	DummyQTimeLine();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	knh_Object_t** reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
public slots:
	bool finishedSlot();
	bool frameChangedSlot(int frame);
	bool stateChangedSlot(QTimeLine::State new_State);
	bool valueChangedSlot(qreal value);
};

class KQTimeLine : public QTimeLine {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQTimeLine *dummy;
	KQTimeLine(int duration, QObject* parent);
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QTIMELINE


