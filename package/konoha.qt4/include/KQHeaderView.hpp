#ifndef QHEADERVIEW
#define QHEADERVIEW
class DummyQHeaderView : public DummyQAbstractItemView {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQHeaderView();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQHeaderView : public QHeaderView, public DummyQHeaderView {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQHeaderView(Qt::Orientation orientation, QWidget* parent);
	bool event(QEvent *event);
};

#endif //QHEADERVIEW


