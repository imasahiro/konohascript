#ifndef QPLAINTEXTEDIT
#define QPLAINTEXTEDIT
class DummyQPlainTextEdit : public DummyQAbstractScrollArea {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQPlainTextEdit();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQPlainTextEdit : public QPlainTextEdit, public DummyQPlainTextEdit {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQPlainTextEdit(QWidget* parent);
	bool event(QEvent *event);
};

#endif //QPLAINTEXTEDIT


