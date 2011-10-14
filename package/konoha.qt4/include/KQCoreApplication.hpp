#ifndef QCOREAPPLICATION
#define QCOREAPPLICATION
class DummyQCoreApplication : public DummyQObject {
	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *about_to_quit_func;
	DummyQCoreApplication();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void connection(QObject *o);
public slots:
	bool aboutToQuitSlot();
};

class KQCoreApplication : public QCoreApplication {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQCoreApplication *dummy;
	KQCoreApplication(int argc, char** argv);
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QCOREAPPLICATION


