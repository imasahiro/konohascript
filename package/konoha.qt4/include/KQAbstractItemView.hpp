#ifndef QABSTRACTITEMVIEW
#define QABSTRACTITEMVIEW
class DummyQAbstractItemView : public DummyQAbstractScrollArea {
	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *activated_func;
	knh_Func_t *clicked_func;
	knh_Func_t *double_clicked_func;
	knh_Func_t *entered_func;
	knh_Func_t *pressed_func;
	knh_Func_t *viewport_entered_func;
	DummyQAbstractItemView();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void connection(QObject *o);
public slots:
	bool activatedSlot(const QModelIndex index);
	bool clickedSlot(const QModelIndex index);
	bool doubleClickedSlot(const QModelIndex index);
	bool enteredSlot(const QModelIndex index);
	bool pressedSlot(const QModelIndex index);
	bool viewportEnteredSlot();
};

class KQAbstractItemView : public QAbstractItemView {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQAbstractItemView *dummy;
	KQAbstractItemView(QWidget* parent);
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QABSTRACTITEMVIEW


