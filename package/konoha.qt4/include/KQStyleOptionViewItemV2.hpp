#ifndef QSTYLEOPTIONVIEWITEMV2
#define QSTYLEOPTIONVIEWITEMV2
class DummyQStyleOptionViewItemV2 : public DummyQStyleOptionViewItem {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQStyleOptionViewItemV2();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
};

class KQStyleOptionViewItemV2 : public QStyleOptionViewItemV2 {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQStyleOptionViewItemV2 *dummy;
	KQStyleOptionViewItemV2();
	void setSelf(knh_RawPtr_t *ptr);
};

#endif //QSTYLEOPTIONVIEWITEMV2


