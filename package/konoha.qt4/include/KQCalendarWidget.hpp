#ifndef QCALENDARWIDGET
#define QCALENDARWIDGET
class DummyQCalendarWidget : public DummyQWidget {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQCalendarWidget();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQCalendarWidget : public QCalendarWidget, public DummyQCalendarWidget {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQCalendarWidget(QWidget* parent);
	bool event(QEvent *event);
};

#endif //QCALENDARWIDGET


