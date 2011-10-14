#ifndef QDESKTOPWIDGET
#define QDESKTOPWIDGET
class DummyQDesktopWidget : public DummyQWidget {
	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *resized_func;
	knh_Func_t *screen_count_changed_func;
	knh_Func_t *work_area_resized_func;
	DummyQDesktopWidget();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void connection(QObject *o);
public slots:
	bool resizedSlot(int screen);
	bool screenCountChangedSlot(int new_Count);
	bool workAreaResizedSlot(int screen);
};

class KQDesktopWidget : public QDesktopWidget {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQDesktopWidget *dummy;
	KQDesktopWidget();
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QDESKTOPWIDGET


