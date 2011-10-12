#ifndef QSTYLEDITEMDELEGATE
#define QSTYLEDITEMDELEGATE
class DummyQStyledItemDelegate : public DummyQAbstractItemDelegate {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQStyledItemDelegate();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQStyledItemDelegate : public QStyledItemDelegate, public DummyQStyledItemDelegate {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQStyledItemDelegate(QObject* parent);
	bool event(QEvent *event);
};

#endif //QSTYLEDITEMDELEGATE


