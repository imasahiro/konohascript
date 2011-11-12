#ifndef QTOOLBAR
#define QTOOLBAR
class DummyQToolBar : public DummyQWidget {
	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *action_triggered_func;
	knh_Func_t *allowed_areas_changed_func;
	knh_Func_t *icon_size_changed_func;
	knh_Func_t *movable_changed_func;
	knh_Func_t *orientation_changed_func;
	knh_Func_t *tool_button_style_changed_func;
	knh_Func_t *top_level_changed_func;
	knh_Func_t *visibility_changed_func;
	DummyQToolBar();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	knh_Object_t** reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
public slots:
	bool actionTriggeredSlot(QAction* action);
	bool allowedAreasChangedSlot(Qt::ToolBarAreas allowedAreas);
	bool iconSizeChangedSlot(const QSize iconSize);
	bool movableChangedSlot(bool movable);
	bool orientationChangedSlot(Qt::Orientation orientation);
	bool toolButtonStyleChangedSlot(Qt::ToolButtonStyle toolButtonStyle);
	bool topLevelChangedSlot(bool topLevel);
	bool visibilityChangedSlot(bool visible);
};

class KQToolBar : public QToolBar {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQToolBar *dummy;
	KQToolBar(const QString title, QWidget* parent);
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QTOOLBAR


