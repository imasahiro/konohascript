#ifndef QACCESSIBLEWIDGET
#define QACCESSIBLEWIDGET
class DummyQAccessibleWidget : public DummyQAccessibleObject {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQAccessibleWidget();
	virtual ~DummyQAccessibleWidget();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	knh_Object_t** reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
};

class KQAccessibleWidget : public QAccessibleWidget {
//	Q_OBJECT;
public:
	int magic_num;
	knh_RawPtr_t *self;
	DummyQAccessibleWidget *dummy;
	KQAccessibleWidget(QWidget* w, QAccessibleWidget::Role role, const QString name);
	~KQAccessibleWidget();
	void setSelf(knh_RawPtr_t *ptr);
};

#endif //QACCESSIBLEWIDGET


