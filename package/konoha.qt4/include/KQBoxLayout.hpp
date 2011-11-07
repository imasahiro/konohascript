#ifndef QBOXLAYOUT
#define QBOXLAYOUT
class DummyQBoxLayout : public DummyQLayout {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQBoxLayout();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
};

class KQBoxLayout : public QBoxLayout {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQBoxLayout *dummy;
	KQBoxLayout(QBoxLayout::Direction dir, QWidget* parent);
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QBOXLAYOUT


