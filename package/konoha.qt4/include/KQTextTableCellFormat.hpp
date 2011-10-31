#ifndef QTEXTTABLECELLFORMAT
#define QTEXTTABLECELLFORMAT
class DummyQTextTableCellFormat : public DummyQTextCharFormat {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQTextTableCellFormat();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void connection(QObject *o);
};

class KQTextTableCellFormat : public QTextTableCellFormat {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQTextTableCellFormat *dummy;
	KQTextTableCellFormat();
	void setSelf(knh_RawPtr_t *ptr);
};

#endif //QTEXTTABLECELLFORMAT

