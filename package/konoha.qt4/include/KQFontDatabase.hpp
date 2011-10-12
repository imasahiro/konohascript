#ifndef QFONTDATABASE
#define QFONTDATABASE
class DummyQFontDatabase {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQFontDatabase();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQFontDatabase : public QFontDatabase, public DummyQFontDatabase {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQFontDatabase();
};

#endif //QFONTDATABASE


