#ifndef QTREEVIEW
#define QTREEVIEW
class DummyQTreeView : public DummyQAbstractItemView {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQTreeView();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQTreeView : public QTreeView, public DummyQTreeView {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQTreeView(QWidget* parent);
	bool event(QEvent *event);
};

#endif //QTREEVIEW


