#ifndef QMOVIE
#define QMOVIE
class DummyQMovie : public DummyQObject {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQMovie();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQMovie : public QMovie, public DummyQMovie {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQMovie(QObject* parent);
	bool event(QEvent *event);
};

#endif //QMOVIE


