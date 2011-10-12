#ifndef QWIZARD
#define QWIZARD
class DummyQWizard : public DummyQDialog {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQWizard();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQWizard : public QWizard, public DummyQWizard {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQWizard(QWidget* parent, Qt::WindowFlags flags);
	bool event(QEvent *event);
};

#endif //QWIZARD


