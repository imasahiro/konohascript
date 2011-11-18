#ifndef QBOXLAYOUT
#define QBOXLAYOUT
class DummyQBoxLayout : public DummyQLayout {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQBoxLayout();
	virtual ~DummyQBoxLayout();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	knh_Object_t** reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
};

class KQBoxLayout : public QBoxLayout {
//	Q_OBJECT;
public:
	int magic_num;
	knh_RawPtr_t *self;
	DummyQBoxLayout *dummy;
	KQBoxLayout(QBoxLayout::Direction dir, QWidget* parent);
	~KQBoxLayout();
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QBOXLAYOUT


