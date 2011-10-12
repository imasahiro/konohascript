#ifndef QDIR
#define QDIR
class DummyQDir {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQDir();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQDir : public QDir, public DummyQDir {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQDir(const QDir dir);
};

#endif //QDIR


