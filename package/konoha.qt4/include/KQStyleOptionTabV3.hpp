#ifndef QSTYLEOPTIONTABV3
#define QSTYLEOPTIONTABV3
class DummyQStyleOptionTabV3 : public DummyQStyleOptionTabV2 {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQStyleOptionTabV3();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQStyleOptionTabV3 : public QStyleOptionTabV3, public DummyQStyleOptionTabV3 {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQStyleOptionTabV3();
};

#endif //QSTYLEOPTIONTABV3


