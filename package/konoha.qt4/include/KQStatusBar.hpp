#ifndef QSTATUSBAR
#define QSTATUSBAR
class DummyQStatusBar : public DummyQWidget {
	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *message_changed_func;
	DummyQStatusBar();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void connection(QObject *o);
public slots:
	bool messageChangedSlot(const QString message);
};

class KQStatusBar : public QStatusBar {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQStatusBar *dummy;
	KQStatusBar(QWidget* parent);
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QSTATUSBAR


