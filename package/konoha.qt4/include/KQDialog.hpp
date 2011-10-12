#ifndef QDIALOG
#define QDIALOG
class DummyQDialog : public DummyQWidget {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQDialog();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQDialog : public QDialog, public DummyQDialog {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQDialog(QWidget* parent, Qt::WindowFlags f);
	bool event(QEvent *event);
};

#endif //QDIALOG


