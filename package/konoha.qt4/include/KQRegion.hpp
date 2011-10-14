#ifndef QREGION
#define QREGION
class DummyQRegion {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQRegion();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void connection(QObject *o);
};

class KQRegion : public QRegion {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQRegion *dummy;
	KQRegion();
	void setSelf(knh_RawPtr_t *ptr);
};

#endif //QREGION


