#ifndef QWIDGETITEM
#define QWIDGETITEM
class DummyQWidgetItem : public DummyQLayoutItem {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQWidgetItem();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void connection(QObject *o);
};

class KQWidgetItem : public QWidgetItem {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQWidgetItem *dummy;
	KQWidgetItem(QWidget* widget);
	void setSelf(knh_RawPtr_t *ptr);
};

#endif //QWIDGETITEM

