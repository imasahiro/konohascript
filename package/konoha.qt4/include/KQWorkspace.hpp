#ifndef QWORKSPACE
#define QWORKSPACE
class DummyQWorkspace : public DummyQWidget {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQWorkspace();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQWorkspace : public QWorkspace, public DummyQWorkspace {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQWorkspace(QWidget* parent);
	bool event(QEvent *event);
};

#endif //QWORKSPACE


