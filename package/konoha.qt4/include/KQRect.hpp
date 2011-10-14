#ifndef QRECT
#define QRECT
class DummyQRect {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQRect();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void connection(QObject *o);
};

class KQRect : public QRect {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQRect *dummy;
	KQRect();
	void setSelf(knh_RawPtr_t *ptr);
};

#endif //QRECT


