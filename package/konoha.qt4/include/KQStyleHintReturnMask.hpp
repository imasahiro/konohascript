#ifndef QSTYLEHINTRETURNMASK
#define QSTYLEHINTRETURNMASK
class DummyQStyleHintReturnMask : public DummyQStyleHintReturn {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQStyleHintReturnMask();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void connection(QObject *o);
};

class KQStyleHintReturnMask : public QStyleHintReturnMask {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQStyleHintReturnMask *dummy;
	KQStyleHintReturnMask();
	void setSelf(knh_RawPtr_t *ptr);
};

#endif //QSTYLEHINTRETURNMASK


