#ifndef QMESSAGEBOX
#define QMESSAGEBOX
class DummyQMessageBox : public DummyQDialog {
	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *button_clicked_func;
	DummyQMessageBox();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void connection(QObject *o);
public slots:
	bool buttonClickedSlot(QAbstractButton* button);
};

class KQMessageBox : public QMessageBox {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQMessageBox *dummy;
	KQMessageBox(QWidget* parent);
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QMESSAGEBOX


