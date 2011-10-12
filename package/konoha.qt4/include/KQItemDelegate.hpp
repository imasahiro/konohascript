#ifndef QITEMDELEGATE
#define QITEMDELEGATE
class DummyQItemDelegate : public DummyQAbstractItemDelegate {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQItemDelegate();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQItemDelegate : public QItemDelegate, public DummyQItemDelegate {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQItemDelegate(QObject* parent);
	bool event(QEvent *event);
};

#endif //QITEMDELEGATE


