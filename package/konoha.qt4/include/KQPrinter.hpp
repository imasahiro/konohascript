#ifndef QPRINTER
#define QPRINTER
class DummyQPrinter : public DummyQPaintDevice {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQPrinter();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQPrinter : public QPrinter, public DummyQPrinter {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQPrinter(QPrinter::PrinterMode mode);
};

#endif //QPRINTER


