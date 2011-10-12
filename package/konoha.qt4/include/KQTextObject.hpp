#ifndef QTEXTOBJECT
#define QTEXTOBJECT
class DummyQTextObject : public DummyQObject {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQTextObject();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQTextObject : public QTextObject, public DummyQTextObject {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQTextObject(QTextDocument* document);
	bool event(QEvent *event);
};

#endif //QTEXTOBJECT


