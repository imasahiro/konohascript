#ifndef QDOCKWIDGET
#define QDOCKWIDGET
class DummyQDockWidget : public DummyQWidget {
	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *allowed_areas_changed_func;
	knh_Func_t *dock_location_changed_func;
	knh_Func_t *features_changed_func;
	knh_Func_t *top_level_changed_func;
	knh_Func_t *visibility_changed_func;
	DummyQDockWidget();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void connection(QObject *o);
public slots:
	bool allowedAreasChangedSlot(Qt::DockWidgetAreas allowedAreas);
	bool dockLocationChangedSlot(Qt::DockWidgetArea area);
	bool featuresChangedSlot(QDockWidget::DockWidgetFeatures features);
	bool topLevelChangedSlot(bool topLevel);
	bool visibilityChangedSlot(bool visible);
};

class KQDockWidget : public QDockWidget {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQDockWidget *dummy;
	KQDockWidget(const QString title, QWidget* parent, Qt::WindowFlags flags);
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QDOCKWIDGET


