#ifndef QCOMPLETER
#define QCOMPLETER
class DummyQCompleter : public DummyQObject {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQCompleter();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQCompleter : public QCompleter, public DummyQCompleter {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQCompleter(QObject* parent);
	bool event(QEvent *event);
};

#endif //QCOMPLETER


