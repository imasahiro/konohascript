#ifndef QTIMELINE
#define QTIMELINE
class DummyQTimeLine : public DummyQObject {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQTimeLine();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQTimeLine : public QTimeLine, public DummyQTimeLine {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQTimeLine(int duration, QObject* parent);
	bool event(QEvent *event);
};

#endif //QTIMELINE


