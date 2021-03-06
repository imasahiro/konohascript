#ifndef QSTANDARDITEMMODEL
#define QSTANDARDITEMMODEL
class DummyQStandardItemModel : public DummyQAbstractItemModel {
	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *item_changed_func;
	DummyQStandardItemModel();
	virtual ~DummyQStandardItemModel();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	knh_Object_t** reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
public slots:
	bool itemChangedSlot(QStandardItem* item);
};

class KQStandardItemModel : public QStandardItemModel {
//	Q_OBJECT;
public:
	int magic_num;
	knh_RawPtr_t *self;
	DummyQStandardItemModel *dummy;
	KQStandardItemModel(QObject* parent);
	~KQStandardItemModel();
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QSTANDARDITEMMODEL


