#ifndef QSHORTCUT
#define QSHORTCUT
class DummyQShortcut : public DummyQObject {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQShortcut();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQShortcut : public QShortcut, public DummyQShortcut {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQShortcut(QWidget* parent);
	bool event(QEvent *event);
};

#endif //QSHORTCUT


