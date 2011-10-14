#ifndef QDATAWIDGETMAPPER
#define QDATAWIDGETMAPPER
class DummyQDataWidgetMapper : public DummyQObject {
	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *current_index_changed_func;
	DummyQDataWidgetMapper();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void connection(QObject *o);
public slots:
	bool currentIndexChangedSlot(int index);
};

class KQDataWidgetMapper : public QDataWidgetMapper {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQDataWidgetMapper *dummy;
	KQDataWidgetMapper(QObject* parent);
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QDATAWIDGETMAPPER


