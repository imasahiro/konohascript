#ifndef QVBOXLAYOUT
#define QVBOXLAYOUT
class DummyQVBoxLayout : public DummyQBoxLayout {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQVBoxLayout();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQVBoxLayout : public QVBoxLayout, public DummyQVBoxLayout {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQVBoxLayout();
	bool event(QEvent *event);
};

#endif //QVBOXLAYOUT


