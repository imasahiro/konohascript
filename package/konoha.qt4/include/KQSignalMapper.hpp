#ifndef QSIGNALMAPPER
#define QSIGNALMAPPER
class DummyQSignalMapper : public DummyQObject {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQSignalMapper();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQSignalMapper : public QSignalMapper, public DummyQSignalMapper {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQSignalMapper(QObject* parent);
	bool event(QEvent *event);
};

#endif //QSIGNALMAPPER


