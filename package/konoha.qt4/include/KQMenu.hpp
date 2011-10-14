#ifndef QMENU
#define QMENU
class DummyQMenu : public DummyQWidget {
	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *about_to_hide_func;
	knh_Func_t *about_to_show_func;
	knh_Func_t *hovered_func;
	knh_Func_t *triggered_func;
	DummyQMenu();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void connection(QObject *o);
public slots:
	bool aboutToHideSlot();
	bool aboutToShowSlot();
	bool hoveredSlot(QAction* action);
	bool triggeredSlot(QAction* action);
};

class KQMenu : public QMenu {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQMenu *dummy;
	KQMenu(QWidget* parent);
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QMENU


