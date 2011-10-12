#ifndef QCOLUMNVIEW
#define QCOLUMNVIEW
class DummyQColumnView : public DummyQAbstractItemView {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQColumnView();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQColumnView : public QColumnView, public DummyQColumnView {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQColumnView(QWidget* parent);
	bool event(QEvent *event);
};

#endif //QCOLUMNVIEW


