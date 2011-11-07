#ifndef QMENUBAR
#define QMENUBAR
class DummyQMenuBar : public DummyQWidget {
	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *hovered_func;
	knh_Func_t *triggered_func;
	DummyQMenuBar();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
public slots:
	bool hoveredSlot(QAction* action);
	bool triggeredSlot(QAction* action);
};

class KQMenuBar : public QMenuBar {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQMenuBar *dummy;
	KQMenuBar(QWidget* parent);
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QMENUBAR


