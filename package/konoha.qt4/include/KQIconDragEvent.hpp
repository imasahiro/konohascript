#ifndef QICONDRAGEVENT
#define QICONDRAGEVENT
class DummyQIconDragEvent : public DummyQEvent {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQIconDragEvent();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQIconDragEvent : public QIconDragEvent, public DummyQIconDragEvent {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQIconDragEvent();
};

#endif //QICONDRAGEVENT


