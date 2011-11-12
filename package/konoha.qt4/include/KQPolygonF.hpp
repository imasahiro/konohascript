#ifndef QPOLYGONF
#define QPOLYGONF
class DummyQPolygonF {//: public DummyQVector {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQPolygonF();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void connection(QObject *o);
};

class KQPolygonF : public QPolygonF {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQPolygonF *dummy;
	KQPolygonF();
	void setSelf(knh_RawPtr_t *ptr);
};

#endif //QPOLYGONF


