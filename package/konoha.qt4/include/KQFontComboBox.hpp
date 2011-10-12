#ifndef QFONTCOMBOBOX
#define QFONTCOMBOBOX
class DummyQFontComboBox : public DummyQComboBox {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQFontComboBox();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQFontComboBox : public QFontComboBox, public DummyQFontComboBox {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQFontComboBox(QWidget* parent);
	bool event(QEvent *event);
};

#endif //QFONTCOMBOBOX


