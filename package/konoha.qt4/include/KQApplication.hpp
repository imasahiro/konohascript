#ifndef QAPPLICATION
#define QAPPLICATION
class DummyQApplication : public DummyQCoreApplication {
	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *focus_changed_func;
	knh_Func_t *font_database_changed_func;
	knh_Func_t *last_window_closed_func;
	DummyQApplication();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
public slots:
	bool focusChangedSlot(QWidget* old, QWidget* now);
	bool fontDatabaseChangedSlot();
	bool lastWindowClosedSlot();
};

class KQApplication : public QApplication {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQApplication *dummy;
	KQApplication(int argc, char** argv);
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QAPPLICATION


