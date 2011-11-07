#ifndef QCALENDARWIDGET
#define QCALENDARWIDGET
class DummyQCalendarWidget : public DummyQWidget {
	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *activated_func;
	knh_Func_t *clicked_func;
	knh_Func_t *current_page_changed_func;
	knh_Func_t *selection_changed_func;
	DummyQCalendarWidget();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
public slots:
	bool activatedSlot(const QDate date);
	bool clickedSlot(const QDate date);
	bool currentPageChangedSlot(int year, int month);
	bool selectionChangedSlot();
};

class KQCalendarWidget : public QCalendarWidget {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQCalendarWidget *dummy;
	KQCalendarWidget(QWidget* parent);
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QCALENDARWIDGET


