#ifndef QPROGRESSBAR
#define QPROGRESSBAR
class DummyQProgressBar : public DummyQWidget {
	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *value_changed_func;
	DummyQProgressBar();
	virtual ~DummyQProgressBar();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	knh_Object_t** reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
public slots:
	bool valueChangedSlot(int value);
};

class KQProgressBar : public QProgressBar {
//	Q_OBJECT;
public:
	int magic_num;
	knh_RawPtr_t *self;
	DummyQProgressBar *dummy;
	KQProgressBar(QWidget* parent);
	~KQProgressBar();
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QPROGRESSBAR


