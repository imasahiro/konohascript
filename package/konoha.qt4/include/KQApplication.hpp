#ifndef QAPPLICATION
#define QAPPLICATION
class DummyQApplication : public DummyQCoreApplication {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQApplication();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQApplication : public QApplication, public DummyQApplication {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQApplication(int argc, char** argv);
	bool event(QEvent *event);
};

#endif //QAPPLICATION


