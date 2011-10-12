#ifndef QSCROLLAREA
#define QSCROLLAREA
class DummyQScrollArea : public DummyQAbstractScrollArea {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQScrollArea();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQScrollArea : public QScrollArea, public DummyQScrollArea {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQScrollArea(QWidget* parent);
	bool event(QEvent *event);
};

#endif //QSCROLLAREA


