#ifndef QTEXTBLOCKUSERDATA
#define QTEXTBLOCKUSERDATA
class DummyQTextBlockUserData {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQTextBlockUserData();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQTextBlockUserData : public QTextBlockUserData, public DummyQTextBlockUserData {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQTextBlockUserData();
};

#endif //QTEXTBLOCKUSERDATA


