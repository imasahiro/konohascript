#ifndef QDRAG
#define QDRAG
class DummyQDrag : public DummyQObject {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQDrag();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQDrag : public QDrag, public DummyQDrag {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQDrag(QWidget* dragSource);
	bool event(QEvent *event);
};

#endif //QDRAG


