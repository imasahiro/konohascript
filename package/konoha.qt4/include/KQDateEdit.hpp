#ifndef QDATEEDIT
#define QDATEEDIT
class DummyQDateEdit : public DummyQDateTimeEdit {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQDateEdit();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQDateEdit : public QDateEdit, public DummyQDateEdit {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQDateEdit(QWidget* parent);
	bool event(QEvent *event);
};

#endif //QDATEEDIT


