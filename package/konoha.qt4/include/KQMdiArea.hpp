#ifndef QMDIAREA
#define QMDIAREA
class DummyQMdiArea : public DummyQAbstractScrollArea {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQMdiArea();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQMdiArea : public QMdiArea, public DummyQMdiArea {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQMdiArea(QWidget* parent);
	bool event(QEvent *event);
};

#endif //QMDIAREA


