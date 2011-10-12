#ifndef QTEXTBLOCKGROUP
#define QTEXTBLOCKGROUP
class DummyQTextBlockGroup : public DummyQTextObject {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQTextBlockGroup();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQTextBlockGroup : public QTextBlockGroup, public DummyQTextBlockGroup {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQTextBlockGroup(QTextDocument* document);
	bool event(QEvent *event);
};

#endif //QTEXTBLOCKGROUP


