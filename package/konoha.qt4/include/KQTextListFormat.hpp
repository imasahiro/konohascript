#ifndef QTEXTLISTFORMAT
#define QTEXTLISTFORMAT
class DummyQTextListFormat : public DummyQTextFormat {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQTextListFormat();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQTextListFormat : public QTextListFormat, public DummyQTextListFormat {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQTextListFormat();
};

#endif //QTEXTLISTFORMAT


