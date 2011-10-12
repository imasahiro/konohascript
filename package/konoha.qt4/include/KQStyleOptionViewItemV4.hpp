#ifndef QSTYLEOPTIONVIEWITEMV4
#define QSTYLEOPTIONVIEWITEMV4
class DummyQStyleOptionViewItemV4 : public DummyQStyleOptionViewItemV3 {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQStyleOptionViewItemV4();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQStyleOptionViewItemV4 : public QStyleOptionViewItemV4, public DummyQStyleOptionViewItemV4 {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQStyleOptionViewItemV4();
};

#endif //QSTYLEOPTIONVIEWITEMV4


