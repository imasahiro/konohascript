#ifndef QTABLEVIEW
#define QTABLEVIEW
class DummyQTableView : public DummyQAbstractItemView {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQTableView();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQTableView : public QTableView, public DummyQTableView {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQTableView(QWidget* parent);
	bool event(QEvent *event);
};

#endif //QTABLEVIEW


