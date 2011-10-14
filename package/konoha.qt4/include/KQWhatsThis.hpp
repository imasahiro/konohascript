#ifndef QWHATSTHIS
#define QWHATSTHIS
class DummyQWhatsThis {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQWhatsThis();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void connection(QObject *o);
};

class KQWhatsThis : public QWhatsThis {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQWhatsThis *dummy;

	void setSelf(knh_RawPtr_t *ptr);
};

#endif //QWHATSTHIS


