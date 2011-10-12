#ifndef QDATAWIDGETMAPPER
#define QDATAWIDGETMAPPER
class DummyQDataWidgetMapper : public DummyQObject {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQDataWidgetMapper();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQDataWidgetMapper : public QDataWidgetMapper, public DummyQDataWidgetMapper {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQDataWidgetMapper(QObject* parent);
	bool event(QEvent *event);
};

#endif //QDATAWIDGETMAPPER


