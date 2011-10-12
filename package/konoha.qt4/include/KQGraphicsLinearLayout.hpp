#ifndef QGRAPHICSLINEARLAYOUT
#define QGRAPHICSLINEARLAYOUT
class DummyQGraphicsLinearLayout : public DummyQGraphicsLayout {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQGraphicsLinearLayout();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQGraphicsLinearLayout : public QGraphicsLinearLayout, public DummyQGraphicsLinearLayout {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQGraphicsLinearLayout(QGraphicsLayoutItem* parent);
};

#endif //QGRAPHICSLINEARLAYOUT


