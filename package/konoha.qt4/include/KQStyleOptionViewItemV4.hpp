#ifndef QSTYLEOPTIONVIEWITEMV4
#define QSTYLEOPTIONVIEWITEMV4
class DummyQStyleOptionViewItemV4 : public DummyQStyleOptionViewItemV3 {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQStyleOptionViewItemV4();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	knh_Object_t** reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
};

class KQStyleOptionViewItemV4 : public QStyleOptionViewItemV4 {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQStyleOptionViewItemV4 *dummy;
	KQStyleOptionViewItemV4();
	void setSelf(knh_RawPtr_t *ptr);
};

#endif //QSTYLEOPTIONVIEWITEMV4


