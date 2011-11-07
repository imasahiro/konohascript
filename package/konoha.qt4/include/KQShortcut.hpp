#ifndef QSHORTCUT
#define QSHORTCUT
class DummyQShortcut : public DummyQObject {
	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *activated_func;
	knh_Func_t *activated_ambiguously_func;
	DummyQShortcut();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
public slots:
	bool activatedSlot();
	bool activatedAmbiguouslySlot();
};

class KQShortcut : public QShortcut {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQShortcut *dummy;
	KQShortcut(QWidget* parent);
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QSHORTCUT


