#ifndef QSTANDARDITEMMODEL
#define QSTANDARDITEMMODEL
class DummyQStandardItemModel : public DummyQAbstractItemModel {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQStandardItemModel();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQStandardItemModel : public QStandardItemModel, public DummyQStandardItemModel {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQStandardItemModel(QObject* parent);
	bool event(QEvent *event);
};

#endif //QSTANDARDITEMMODEL


