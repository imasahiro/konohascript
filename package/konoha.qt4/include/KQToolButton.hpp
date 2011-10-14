#ifndef QTOOLBUTTON
#define QTOOLBUTTON
class DummyQToolButton : public DummyQAbstractButton {
	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *triggered_func;
	DummyQToolButton();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void connection(QObject *o);
public slots:
	bool triggeredSlot(QAction* action);
};

class KQToolButton : public QToolButton {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQToolButton *dummy;
	KQToolButton(QWidget* parent);
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QTOOLBUTTON


