#ifndef QINPUTDIALOG
#define QINPUTDIALOG
class DummyQInputDialog : public DummyQDialog {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQInputDialog();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQInputDialog : public QInputDialog, public DummyQInputDialog {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQInputDialog(QWidget* parent, Qt::WindowFlags flags);
	bool event(QEvent *event);
};

#endif //QINPUTDIALOG


