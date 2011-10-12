#ifndef QGRIDLAYOUT
#define QGRIDLAYOUT
class DummyQGridLayout : public DummyQLayout {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQGridLayout();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQGridLayout : public QGridLayout, public DummyQGridLayout {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQGridLayout(QWidget* parent);
	bool event(QEvent *event);
};

#endif //QGRIDLAYOUT


