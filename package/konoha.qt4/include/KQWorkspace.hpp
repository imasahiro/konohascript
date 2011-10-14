#ifndef QWORKSPACE
#define QWORKSPACE
class DummyQWorkspace : public DummyQWidget {
	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *window_activated_func;
	DummyQWorkspace();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void connection(QObject *o);
public slots:
	bool windowActivatedSlot(QWidget* w);
};

class KQWorkspace : public QWorkspace {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQWorkspace *dummy;
	KQWorkspace(QWidget* parent);
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QWORKSPACE


