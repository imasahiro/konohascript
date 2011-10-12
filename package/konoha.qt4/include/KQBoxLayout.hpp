#ifndef QBOXLAYOUT
#define QBOXLAYOUT
class DummyQBoxLayout : public DummyQLayout {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQBoxLayout();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQBoxLayout : public QBoxLayout, public DummyQBoxLayout {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQBoxLayout(QBoxLayout::Direction dir, QWidget* parent);
	bool event(QEvent *event);
};

#endif //QBOXLAYOUT


