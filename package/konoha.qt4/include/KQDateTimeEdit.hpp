#ifndef QDATETIMEEDIT
#define QDATETIMEEDIT
class DummyQDateTimeEdit : public DummyQAbstractSpinBox {
	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *date_changed_func;
	knh_Func_t *date_time_changed_func;
	knh_Func_t *time_changed_func;
	DummyQDateTimeEdit();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void connection(QObject *o);
public slots:
	bool dateChangedSlot(const QDate date);
	bool dateTimeChangedSlot(const QDateTime datetime);
	bool timeChangedSlot(const QTime time);
};

class KQDateTimeEdit : public QDateTimeEdit {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQDateTimeEdit *dummy;
	KQDateTimeEdit(QWidget* parent);
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QDATETIMEEDIT


