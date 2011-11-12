#ifndef QSTYLEOPTIONDOCKWIDGET
#define QSTYLEOPTIONDOCKWIDGET
class DummyQStyleOptionDockWidget : public DummyQStyleOption {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQStyleOptionDockWidget();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	knh_Object_t** reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
};

class KQStyleOptionDockWidget : public QStyleOptionDockWidget {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQStyleOptionDockWidget *dummy;
	KQStyleOptionDockWidget();
	void setSelf(knh_RawPtr_t *ptr);
};

#endif //QSTYLEOPTIONDOCKWIDGET


