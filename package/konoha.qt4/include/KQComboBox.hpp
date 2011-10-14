#ifndef QCOMBOBOX
#define QCOMBOBOX
class DummyQComboBox : public DummyQWidget {
	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *edit_text_changed_func;
	DummyQComboBox();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void connection(QObject *o);
public slots:
	bool editTextChangedSlot(const QString text);
};

class KQComboBox : public QComboBox {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQComboBox *dummy;
	KQComboBox(QWidget* parent);
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QCOMBOBOX


