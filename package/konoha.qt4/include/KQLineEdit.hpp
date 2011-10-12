#ifndef QLINEEDIT
#define QLINEEDIT
class DummyQLineEdit : public DummyQWidget {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQLineEdit();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQLineEdit : public QLineEdit, public DummyQLineEdit {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQLineEdit(QWidget* parent);
	bool event(QEvent *event);
};

#endif //QLINEEDIT


