#ifndef QTEXTTABLE
#define QTEXTTABLE
class DummyQTextTable : public DummyQTextFrame {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQTextTable();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQTextTable : public QTextTable, public DummyQTextTable {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;

	bool event(QEvent *event);
};

#endif //QTEXTTABLE


