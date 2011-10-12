#ifndef QSTYLEOPTIONTABV2
#define QSTYLEOPTIONTABV2
class DummyQStyleOptionTabV2 : public DummyQStyleOptionTab {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQStyleOptionTabV2();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQStyleOptionTabV2 : public QStyleOptionTabV2, public DummyQStyleOptionTabV2 {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQStyleOptionTabV2();
};

#endif //QSTYLEOPTIONTABV2


