#ifndef QDIALOG
#define QDIALOG
class DummyQDialog : public DummyQWidget {
	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *accepted_func;
	knh_Func_t *finished_func;
	knh_Func_t *rejected_func;
	DummyQDialog();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void connection(QObject *o);
public slots:
	bool acceptedSlot();
	bool finishedSlot(int result);
	bool rejectedSlot();
};

class KQDialog : public QDialog {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQDialog *dummy;
	KQDialog(QWidget* parent, Qt::WindowFlags f);
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QDIALOG

