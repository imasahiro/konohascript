#ifndef QVALIDATOR
#define QVALIDATOR
class DummyQValidator : public DummyQObject {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQValidator();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQValidator : public QValidator, public DummyQValidator {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQValidator(QObject* parent);
	bool event(QEvent *event);
};

#endif //QVALIDATOR


