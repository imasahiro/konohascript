#ifndef QGRAPHICSEFFECT
#define QGRAPHICSEFFECT
class DummyQGraphicsEffect : public DummyQObject {
	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *enabled_changed_func;
	DummyQGraphicsEffect();
	virtual ~DummyQGraphicsEffect();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	knh_Object_t** reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
public slots:
	bool enabledChangedSlot(bool enabled);
};

class KQGraphicsEffect : public QGraphicsEffect {
//	Q_OBJECT;
public:
	int magic_num;
	knh_RawPtr_t *self;
	DummyQGraphicsEffect *dummy;
	KQGraphicsEffect(QObject* parent);
	~KQGraphicsEffect();
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QGRAPHICSEFFECT


