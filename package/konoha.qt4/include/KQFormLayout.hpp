#ifndef QFORMLAYOUT
#define QFORMLAYOUT
class DummyQFormLayout : public DummyQLayout {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQFormLayout();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	knh_Object_t** reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
};

class KQFormLayout : public QFormLayout {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQFormLayout *dummy;
	KQFormLayout(QWidget* parent);
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QFORMLAYOUT


