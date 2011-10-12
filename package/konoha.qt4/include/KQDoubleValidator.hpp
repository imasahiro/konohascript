#ifndef QDOUBLEVALIDATOR
#define QDOUBLEVALIDATOR
class DummyQDoubleValidator : public DummyQValidator {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQDoubleValidator();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQDoubleValidator : public QDoubleValidator, public DummyQDoubleValidator {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQDoubleValidator(QObject* parent);
	bool event(QEvent *event);
};

#endif //QDOUBLEVALIDATOR


