#ifndef QPROXYMODEL
#define QPROXYMODEL
class DummyQProxyModel : public DummyQAbstractItemModel {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQProxyModel();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
};

class KQProxyModel : public QProxyModel {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQProxyModel *dummy;
	KQProxyModel(QObject* parent);
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QPROXYMODEL


