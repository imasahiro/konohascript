#ifndef QWIZARDPAGE
#define QWIZARDPAGE
class DummyQWizardPage : public DummyQWidget {
	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *complete_changed_func;
	DummyQWizardPage();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void connection(QObject *o);
public slots:
	bool completeChangedSlot();
};

class KQWizardPage : public QWizardPage {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQWizardPage *dummy;
	KQWizardPage(QWidget* parent);
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QWIZARDPAGE


