#ifndef QLAYOUT
#define QLAYOUT
class DummyQLayout : public DummyQLayoutItem, public DummyQObject {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQLayout();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQLayout : public QLayout, public DummyQLayout {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQLayout(QWidget* parent);
	bool event(QEvent *event);
};

#endif //QLAYOUT


