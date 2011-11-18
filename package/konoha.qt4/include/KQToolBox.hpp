#ifndef QTOOLBOX
#define QTOOLBOX
class DummyQToolBox : public DummyQFrame {
	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *current_changed_func;
	DummyQToolBox();
	virtual ~DummyQToolBox();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	knh_Object_t** reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
public slots:
	bool currentChangedSlot(int index);
};

class KQToolBox : public QToolBox {
//	Q_OBJECT;
public:
	int magic_num;
	knh_RawPtr_t *self;
	DummyQToolBox *dummy;
	KQToolBox(QWidget* parent, Qt::WindowFlags f);
	~KQToolBox();
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QTOOLBOX


