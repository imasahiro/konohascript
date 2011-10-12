#ifndef QGROUPBOX
#define QGROUPBOX
class DummyQGroupBox : public DummyQWidget {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQGroupBox();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQGroupBox : public QGroupBox, public DummyQGroupBox {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQGroupBox(QWidget* parent);
	bool event(QEvent *event);
};

#endif //QGROUPBOX


