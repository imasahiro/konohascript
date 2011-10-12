#ifndef QACCESSIBLEWIDGET
#define QACCESSIBLEWIDGET
class DummyQAccessibleWidget : public DummyQAccessibleObject {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQAccessibleWidget();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQAccessibleWidget : public QAccessibleWidget, public DummyQAccessibleWidget {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQAccessibleWidget(QWidget* w, QAccessibleWidget::Role role, const QString name);
};

#endif //QACCESSIBLEWIDGET


