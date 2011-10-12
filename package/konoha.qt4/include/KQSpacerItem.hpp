#ifndef QSPACERITEM
#define QSPACERITEM
class DummyQSpacerItem : public DummyQLayoutItem {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQSpacerItem();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQSpacerItem : public QSpacerItem, public DummyQSpacerItem {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQSpacerItem(int w, int h, QSizePolicy::Policy hPolicy, QSizePolicy::Policy vPolicy);
};

#endif //QSPACERITEM


