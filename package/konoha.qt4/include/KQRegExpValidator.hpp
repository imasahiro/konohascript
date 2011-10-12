#ifndef QREGEXPVALIDATOR
#define QREGEXPVALIDATOR
class DummyQRegExpValidator : public DummyQValidator {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQRegExpValidator();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQRegExpValidator : public QRegExpValidator, public DummyQRegExpValidator {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQRegExpValidator(QObject* parent);
	bool event(QEvent *event);
};

#endif //QREGEXPVALIDATOR


