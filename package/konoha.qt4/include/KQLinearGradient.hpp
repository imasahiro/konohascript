#ifndef QLINEARGRADIENT
#define QLINEARGRADIENT
class DummyQLinearGradient : public DummyQGradient {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQLinearGradient();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQLinearGradient : public QLinearGradient, public DummyQLinearGradient {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQLinearGradient();
};

#endif //QLINEARGRADIENT


