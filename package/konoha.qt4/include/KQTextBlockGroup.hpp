#ifndef QTEXTBLOCKGROUP
#define QTEXTBLOCKGROUP
class DummyQTextBlockGroup : public DummyQTextObject {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQTextBlockGroup();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void connection(QObject *o);
};

class KQTextBlockGroup : public QTextBlockGroup {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQTextBlockGroup *dummy;
	KQTextBlockGroup(QTextDocument* document);
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QTEXTBLOCKGROUP

