#ifndef QMAINWINDOW
#define QMAINWINDOW
class DummyQMainWindow : public DummyQWidget {
	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *icon_size_changed_func;
	knh_Func_t *tool_button_style_changed_func;
	DummyQMainWindow();
	virtual ~DummyQMainWindow();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	knh_Object_t** reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
public slots:
	bool iconSizeChangedSlot(const QSize iconSize);
	bool toolButtonStyleChangedSlot(Qt::ToolButtonStyle toolButtonStyle);
};

class KQMainWindow : public QMainWindow {
//	Q_OBJECT;
public:
	int magic_num;
	knh_RawPtr_t *self;
	DummyQMainWindow *dummy;
	KQMainWindow(QWidget* parent, Qt::WindowFlags flags);
	~KQMainWindow();
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QMAINWINDOW


