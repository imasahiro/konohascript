#ifndef QTREEWIDGET
#define QTREEWIDGET
class DummyQTreeWidget : public DummyQTreeView {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQTreeWidget();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQTreeWidget : public QTreeWidget, public DummyQTreeWidget {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQTreeWidget(QWidget* parent);
	bool event(QEvent *event);
};

#endif //QTREEWIDGET


