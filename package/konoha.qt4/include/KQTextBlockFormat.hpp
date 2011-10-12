#ifndef QTEXTBLOCKFORMAT
#define QTEXTBLOCKFORMAT
class DummyQTextBlockFormat : public DummyQTextFormat {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQTextBlockFormat();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQTextBlockFormat : public QTextBlockFormat, public DummyQTextBlockFormat {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQTextBlockFormat();
};

#endif //QTEXTBLOCKFORMAT


