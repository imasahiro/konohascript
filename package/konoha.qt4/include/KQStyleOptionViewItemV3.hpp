#ifndef QSTYLEOPTIONVIEWITEMV3
#define QSTYLEOPTIONVIEWITEMV3
class DummyQStyleOptionViewItemV3 : public DummyQStyleOptionViewItemV2 {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQStyleOptionViewItemV3();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQStyleOptionViewItemV3 : public QStyleOptionViewItemV3, public DummyQStyleOptionViewItemV3 {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQStyleOptionViewItemV3();
};

#endif //QSTYLEOPTIONVIEWITEMV3


