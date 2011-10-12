#ifndef QHBOXLAYOUT
#define QHBOXLAYOUT
class DummyQHBoxLayout : public DummyQBoxLayout {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQHBoxLayout();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQHBoxLayout : public QHBoxLayout, public DummyQHBoxLayout {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQHBoxLayout();
	bool event(QEvent *event);
};

#endif //QHBOXLAYOUT


