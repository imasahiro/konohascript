#ifndef QWEBDATABASE
#define QWEBDATABASE
class DummyQWebDatabase {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQWebDatabase();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
};

class KQWebDatabase : public QWebDatabase {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQWebDatabase *dummy;
	KQWebDatabase(const QWebDatabase other);
	void setSelf(knh_RawPtr_t *ptr);
};

#endif //QWEBDATABASE


