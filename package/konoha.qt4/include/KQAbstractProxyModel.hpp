#ifndef QABSTRACTPROXYMODEL
#define QABSTRACTPROXYMODEL
class DummyQAbstractProxyModel : public DummyQAbstractItemModel {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQAbstractProxyModel();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQAbstractProxyModel : public QAbstractProxyModel, public DummyQAbstractProxyModel {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQAbstractProxyModel(QObject* parent);
	bool event(QEvent *event);
};

#endif //QABSTRACTPROXYMODEL


