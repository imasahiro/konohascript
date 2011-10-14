#ifndef QCOLUMNVIEW
#define QCOLUMNVIEW
class DummyQColumnView : public DummyQAbstractItemView {
	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *update_preview_widget_func;
	DummyQColumnView();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void connection(QObject *o);
public slots:
	bool updatePreviewWidgetSlot(const QModelIndex index);
};

class KQColumnView : public QColumnView {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQColumnView *dummy;
	KQColumnView(QWidget* parent);
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QCOLUMNVIEW


