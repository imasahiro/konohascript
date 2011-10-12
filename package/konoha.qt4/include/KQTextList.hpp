#ifndef QTEXTLIST
#define QTEXTLIST
class DummyQTextList : public DummyQTextBlockGroup {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQTextList();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQTextList : public QTextList, public DummyQTextList {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;

	bool event(QEvent *event);
};

#endif //QTEXTLIST


