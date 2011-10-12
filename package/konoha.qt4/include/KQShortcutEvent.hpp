#ifndef QSHORTCUTEVENT
#define QSHORTCUTEVENT
class DummyQShortcutEvent : public DummyQEvent {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQShortcutEvent();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQShortcutEvent : public QShortcutEvent, public DummyQShortcutEvent {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQShortcutEvent(const QKeySequence key, int id, bool ambiguous);
};

#endif //QSHORTCUTEVENT


