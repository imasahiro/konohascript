#ifndef QPROXYMODEL
#define QPROXYMODEL
class DummyQProxyModel : public DummyQAbstractItemModel {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQProxyModel();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQProxyModel : public QProxyModel, public DummyQProxyModel {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQProxyModel(QObject* parent);
	bool event(QEvent *event);
};

#endif //QPROXYMODEL


