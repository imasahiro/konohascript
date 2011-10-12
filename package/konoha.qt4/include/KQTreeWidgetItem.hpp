#ifndef QTREEWIDGETITEM
#define QTREEWIDGETITEM
class DummyQTreeWidgetItem {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQTreeWidgetItem();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQTreeWidgetItem : public QTreeWidgetItem, public DummyQTreeWidgetItem {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQTreeWidgetItem(int type);
};

#endif //QTREEWIDGETITEM


