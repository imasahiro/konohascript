#ifndef QDOCKWIDGET
#define QDOCKWIDGET
class DummyQDockWidget : public DummyQWidget {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQDockWidget();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQDockWidget : public QDockWidget, public DummyQDockWidget {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQDockWidget(const QString title, QWidget* parent, Qt::WindowFlags flags);
	bool event(QEvent *event);
};

#endif //QDOCKWIDGET


