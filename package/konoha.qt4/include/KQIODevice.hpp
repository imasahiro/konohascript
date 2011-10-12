#ifndef QIODEVICE
#define QIODEVICE
class DummyQIODevice : public DummyQObject {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQIODevice();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQIODevice : public QIODevice, public DummyQIODevice {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQIODevice();
	bool event(QEvent *event);
};

#endif //QIODEVICE


