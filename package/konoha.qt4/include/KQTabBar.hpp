#ifndef QTABBAR
#define QTABBAR
class DummyQTabBar : public DummyQWidget {
	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *current_changed_func;
	knh_Func_t *tab_close_requested_func;
	knh_Func_t *tab_moved_func;
	DummyQTabBar();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
public slots:
	bool currentChangedSlot(int index);
	bool tabCloseRequestedSlot(int index);
	bool tabMovedSlot(int from, int to);
};

class KQTabBar : public QTabBar {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQTabBar *dummy;
	KQTabBar(QWidget* parent);
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QTABBAR


