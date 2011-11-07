#ifndef QPRINTER
#define QPRINTER
class DummyQPrinter : public DummyQPaintDevice {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQPrinter();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
};

class KQPrinter : public QPrinter {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQPrinter *dummy;
	KQPrinter(QPrinter::PrinterMode mode);
	void setSelf(knh_RawPtr_t *ptr);
};

#endif //QPRINTER


